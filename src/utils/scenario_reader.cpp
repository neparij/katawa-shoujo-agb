#include "scenario_reader.h"

#include "bn_memory.h"
#include "lz77.h"
#include "huff.h"
#include <bn_log.h>
#include <cstring>

#include "utf8.h"
#include "../globals.h"


namespace ks::textdb {
    u8 *spm_table = nullptr;
    u8 *ptr = nullptr;
    bool is_allocated = false;
    const char *_chunk = nullptr;
    const char *_locale = nullptr;

    void init_spm_table(const char *locale) {
        auto filename = bn::string < 24 > ("spm_vocab_");
        filename.append(locale);
        filename.append(".bin");

        BN_LOG("Init SPM Table: ", filename);
        u32 src_len = 0;
        spm_table = (u8 *) gbfs_get_obj(globals::filesystem, filename.c_str(), &src_len);
        BN_ASSERT(spm_table != nullptr, "SPM vocabulary table not found in filesystem!");
    }

    const char *get_chunk() {
        return _chunk;
    }

    void set(const char *chunk, const char *locale) {
        _chunk = chunk;
        _locale = locale;
    }

    void allocate() {
        BN_ASSERT(!is_allocated, "TextDB already allocated!");

        auto filename = bn::string < 24 > (_chunk);
        filename.append(".");
        filename.append(_locale);

        BN_LOG("TextDB load from: ", filename);
        u32 src_len = 0;
        const u8 *compressed_data = (u8 *) gbfs_get_obj(ks::globals::filesystem, filename.c_str(), &src_len);
        const u32 header = *(reinterpret_cast<const u32*>(compressed_data));
        const u32 type = (header >> 4) & 0x0F;
        const u32 size = (header >> 8) & 0x00FFFFFF;
        BN_ASSERT(type == 1 || type == 2, "Unsupported TextDB compression type!");

        BN_LOG("EWRAM free: ", bn::memory::available_alloc_ewram());
        BN_LOG("Allocate ", size, " bytes for text database...");
        BN_ASSERT(!is_allocated, "Text database already allocated!");
        BN_ASSERT(bn::memory::available_alloc_ewram() >= size, "Not enough EWRAM for TextDB allocation!");
        ptr = static_cast<u8 *>(bn::memory::ewram_alloc(static_cast<int>(size)));
        is_allocated = true;

        BN_LOG("Decompress TextDB file...");
        if (type == 1) {
            LZ77UnCompWRAM((u32) compressed_data, (u32) ptr);
        } else {
            HuffUnComp((u32) compressed_data, (u32) ptr);
        }
        BN_LOG("EWRAM after allocation: ", bn::memory::available_alloc_ewram());
    }

    void free() {
        if (is_allocated) {
            BN_LOG("Freeing TextDB...");
            bn::memory::ewram_free(ptr);
            ptr = nullptr;
            is_allocated = false;
        }
    }

    void get_tl(const unsigned short key, bn::istring &out) {
        BN_ASSERT(is_allocated && ptr != nullptr, "TextDB not allocated!");
        BN_ASSERT(_chunk != nullptr, "TextDB Chunk not set!");
        BN_ASSERT(_locale != nullptr, "TextDB Locale not set!");

        out.clear();
        const int index_elements = ptr[0] | ptr[1] << 8;
        constexpr int index_from = 2;
        const int tl_index_size = index_elements * 3;
        // Little-endian 0x000000 to 0xFFFFFF
        const int offset = ptr[index_from + key * 3] |
                           ptr[index_from + key * 3 + 1] << 8 |
                           ptr[index_from + key * 3 + 2] << 16;

        int i = 0;

        do {
            const u8 c0 = ptr[index_from + tl_index_size + offset + i];
            if (c0 == CTL_TERMINATOR) {
                break;
            }

            if (c0 == CMD_START) {
                // Add command
                BN_LOG("Add command from SPM-stream");
                i += 1;  // skip 0xFF
                const char cmd = ptr[index_from + tl_index_size + offset + i];
                const auto cmd_size = utf8::get_char_size(cmd);
                if (cmd == text::CTL_NEWLINE) {
                    BN_LOG("Add newline");
                    out.append("\n");
                } else {
                    for (int j = 0; j < cmd_size; j++) {
                        out.push_back(ptr[index_from + tl_index_size + offset + i + j]);
                    }
                }
                i += cmd_size;
            } else {
                // Process spm GET.
                constexpr int spm_index_size = 2046 * 2;
                int token_id;
                if (c0 < 0xC0) {
                    token_id = c0;
                    i += 1;
                } else {
                    const u8 c1 = ptr[index_from + tl_index_size + offset + i + 1];
                    BN_ASSERT((c1 & 0xC0) == 0x80, "Invalid token continuation byte!");
                    token_id = ((int(c0) & 0x1F) << 6) | (int(c1) & 0x3F);
                    i += 2;
                }

                BN_ASSERT(token_id > 0 && token_id <= 2047, "token_id out of range!");
                const int spm_token_index = token_id - 1;
                BN_LOG("Token index: ", spm_token_index);

                // Where is the token starts?
                const int spm_token_offset = (spm_table[spm_token_index * 2]) | (spm_table[spm_token_index * 2 + 1] << 8); // Little-endian 0x0000 to 0xFFFF

                // Start of token
                const char* token_ptr = reinterpret_cast<char *>(spm_table + spm_index_size + spm_token_offset);
                BN_LOG("Add SPM token", " <<", token_ptr, ">>");

                for (int j = 0; ; j++) {
                    const char tc = token_ptr[j];
                    if (tc == CTL_TERMINATOR) {
                        break;
                    }
                    out.push_back(tc);
                }
            }
        } while (true);
    }
}
