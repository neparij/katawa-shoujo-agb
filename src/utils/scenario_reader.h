#ifndef KS_SCENARIO_READER_H
#define KS_SCENARIO_READER_H

#include "bn_string.h"
#include "gba_types.h"
#include <BN_LOG.h>

namespace ks {
    namespace textdb {
        static const char CTL_TERMINATOR = '\0'; // NUL - the end of textdb chunk
        static const char CTL_FAST = '\1'; // SOH - sets cursor to render text by chars
        static const char CTL_BOLD_START = '\2'; // STX - starts bold text (switch spritefont)
        static const char CTL_BOLD_END = '\3'; // ETX - ends bold text (restore spritefont)
        static const char CTL_STRIKE_START = '\4'; // EOT - starts strikethrough text (switch spritefont?)
        static const char CTL_STRIKE_END = '\5'; // ENQ - ends strikethrough text (restore spritefont?)
        static const char CTL_WAIT = '\6'; // ACK - wait command (next byte is count of 1/10 seconds to wait)
        static const char CTL_NOWAIT = '\7'; // BEL - do not wait for user input to continue dialogue
        static const char CTL_COLOR_START = '\10';
        // BS - sets the color (switch spritepalette, next byte is palette index)
        static const char CTL_COLOR_END = '\11'; // HT - restore color (switch spritepalette)

        static u8 *ptr = nullptr;
        static u32 size = 0;
        static bool is_allocated = false;
        static const unsigned int* _index_ptr = nullptr;
        static const char* _chunk = nullptr;
        static const char* _locale = nullptr;

        inline void set(const char* chunk, const unsigned int* index, const char* locale) {
            _chunk = chunk;
            _index_ptr = index;
            _locale = locale;
        }

        inline void allocate() {
            BN_ASSERT(!is_allocated, "TextDB already allocated!");

            auto filename = bn::string<24>("tl");
            filename.append("_");
            filename.append(_chunk);
            filename.append(".");
            filename.append(_locale);

            BN_LOG("TextDB load from: ", filename);
            u32 src_len = 0;
            const u8 *compressed_data = (u8 *) gbfs_get_obj(globals::filesystem, filename.c_str(), &src_len);

            size = (compressed_data[1]) | (compressed_data[2] << 8) | (compressed_data[3] << 16);

            BN_LOG("EWRAM free: ", bn::memory::available_alloc_ewram());
            BN_LOG("Allocate ", size, " bytes for text database...");
            BN_ASSERT(!is_allocated, "Text database already allocated!");
            ptr = static_cast<u8 *>(bn::memory::ewram_alloc(static_cast<int>(size)));
            is_allocated = true;

            BN_LOG("Decompress TextDB file...");
            LZ77UnCompWRAM((u32) compressed_data, (u32) ptr);
            BN_LOG("EWRAM after allocation: ", bn::memory::available_alloc_ewram());
        }

        inline void free() {
            if (is_allocated) {
                BN_LOG("Freeing TextDB...");
                bn::memory::ewram_free(ptr);
                is_allocated = false;
            }
        }

        template<int MaxSize>
        // TODO: check should it be inline?
        inline void BN_CODE_IWRAM get_tl(const unsigned int key, bn::string<MaxSize> &out) {
            BN_ASSERT(is_allocated, "TextDB not allocated!");
            BN_ASSERT(_index_ptr != nullptr, "TextDB Index Table not set!");
            BN_ASSERT(_chunk != nullptr, "TextDB Chunk not set!");
            BN_ASSERT(_locale != nullptr, "TextDB Locale not set!");
            u32 cursor = _index_ptr[key];
            out.clear();
            for (u32 i = 0; i < size; i++) {
                char c = ptr[cursor];

                if (c == CTL_TERMINATOR) {
                    break;
                }

                out.push_back(c);
                cursor++;
            }
        }
    }
}

#endif // KS_SCENARIO_READER_H
