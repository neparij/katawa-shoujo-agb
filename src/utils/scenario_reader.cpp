#include "scenario_reader.h"

#include "bn_memory.h"
#include "lz77.h"
#include "huff.h"
#include <bn_log.h>
#include <cstring>

#include "utf8.h"
#include "spm_vocab_tl.h"


namespace ks::textdb {
    u8 *ptr = nullptr;
    bool is_allocated = false;
    const u8 *_chunk = nullptr;
    bool restore_wanted = false;

    namespace {

        int decompressed_byte_size()
        {
            if(! _chunk) {
                return 0;
            }
            const u32 header = *(reinterpret_cast<const u32*>(_chunk));
            return int((header >> 8) & 0x00FFFFFFu);
        }

        void release_ewram()
        {
            if(! is_allocated) {
                return;
            }
            BN_LOG("Freeing TextDB...");
            bn::memory::ewram_free(ptr);
            ptr = nullptr;
            is_allocated = false;
        }

        bool try_allocate()
        {
            if(is_allocated || ! _chunk) {
                return false;
            }

            const u32 header = *(reinterpret_cast<const u32*>(_chunk));
            const u32 type = (header >> 4) & 0x0F;
            const u32 size = (header >> 8) & 0x00FFFFFF;
            if(type != 1 && type != 2) {
                return false;
            }
            if(bn::memory::available_alloc_ewram() < int(size)) {
                return false;
            }

            ptr = static_cast<u8 *>(bn::memory::ewram_alloc(static_cast<int>(size)));
            if(! ptr) {
                return false;
            }

            is_allocated = true;
            if(type == 1) {
                LZ77UnCompWRAM((u32) _chunk, (u32) ptr);
            } else {
                HuffUnComp((u32) _chunk, (u32) ptr);
            }
            return true;
        }

        void ensure_loaded()
        {
            if(is_allocated) {
                return;
            }
            if(! restore_wanted || ! _chunk) {
                return;
            }

            BN_LOG("TextDB load...");
            BN_LOG("EWRAM free: ", bn::memory::available_alloc_ewram());
            BN_LOG("Allocate ", decompressed_byte_size(), " bytes for text database...");
            BN_ASSERT(try_allocate(), "TextDB ensure_loaded failed");
            BN_LOG("EWRAM after allocation: ", bn::memory::available_alloc_ewram());
        }

    }  // namespace

    const u8 *get_chunk() {
        return _chunk;
    }

    void set(const u8 *chunk) {
        _chunk = chunk;
    }

    void allocate() {
        BN_ASSERT(!is_allocated, "TextDB already allocated!");
        restore_wanted = true;
        ensure_loaded();
    }

    void free() {
        release_ewram();
        restore_wanted = false;
    }

    void request_release() {
        if(! is_allocated) {
            return;
        }
        BN_LOG("textdb: request_release (ewram=", bn::memory::available_alloc_ewram(), ")");
        release_ewram();
        restore_wanted = true;
    }

    void get_tl(const unsigned short key, bn::istring &out) {
        ensure_loaded();
        BN_ASSERT(is_allocated && ptr != nullptr, "TextDB not allocated!");
        BN_ASSERT(_chunk != nullptr, "TextDB Chunk not set!");

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
                // BN_LOG("Add command from SPM-stream");
                i += 1;  // skip 0xFF
                const char cmd = ptr[index_from + tl_index_size + offset + i];
                const auto cmd_size = utf8::get_char_size(cmd);
                if (cmd == text::CTL_NEWLINE) {
                    // BN_LOG("Add newline");
                    out.append("\n");
                } else {
                    for (int j = 0; j < cmd_size; j++) {
                        out.push_back(ptr[index_from + tl_index_size + offset + i + j]);
                    }
                }
                i += cmd_size;
            } else {
                // Process spm GET.
                const int spm_token_count = spm_vocab_tl[0] | (spm_vocab_tl[1] << 8);   // little-endian uint16
                constexpr int spm_index_from = 2;
                const int spm_index_size = spm_token_count * 2;
                int token_id;
                if (c0 < 0xC0) {
                    token_id = c0;
                    i += 1;
                } else if ((c0 & 0xE0) == 0xC0) {
                    const u8 c1 = ptr[index_from + tl_index_size + offset + i + 1];
                    BN_ASSERT((c1 & 0xC0) == 0x80, "Invalid token continuation byte!");
                    token_id = ((int(c0) & 0x1F) << 6) | (int(c1) & 0x3F);
                    i += 2;
                } else if ((c0 & 0xF0) == 0xE0) {
                    const u8 c1 = ptr[index_from + tl_index_size + offset + i + 1];
                    const u8 c2 = ptr[index_from + tl_index_size + offset + i + 2];
                    BN_ASSERT((c1 & 0xC0) == 0x80, "Invalid token continuation byte (c1)!");
                    BN_ASSERT((c2 & 0xC0) == 0x80, "Invalid token continuation byte (c2)!");
                    token_id = ((int(c0) & 0x0F) << 12) | ((int(c1) & 0x3F) << 6) | (int(c2) & 0x3F);
                    i += 3;
                } else {
                    BN_ERROR("Invalid token lead byte in TextDB stream!");
                }

                BN_ASSERT(token_id > 0, "token_id out of range!");
                BN_ASSERT(token_id <= spm_token_count, "token_id exceeds loaded SPM vocabulary!");
                const int spm_token_index = token_id - 1;
                // BN_LOG("Token index: ", spm_token_index);

                // Where is the token starts?
                const int spm_token_offset = (spm_vocab_tl[spm_index_from + spm_token_index * 2]) |
                                             (spm_vocab_tl[spm_index_from + spm_token_index * 2 + 1] << 8); // Little-endian 0x0000 to 0xFFFF

                // Start of token
                const char* token_ptr = reinterpret_cast<const char *>(spm_vocab_tl + spm_index_from + spm_index_size + spm_token_offset);
                // BN_LOG("Add SPM token", " <<", token_ptr, ">>");

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
