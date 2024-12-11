#ifndef KS_SCENARIO_READER_H
#define KS_SCENARIO_READER_H

#include "bn_string.h"
#include "../globals.h"

#include <BN_LOG.h>

namespace ks {
    namespace scenario {
        namespace gbfs_reader {

            using u32 = unsigned long;
            using u8 = unsigned char;


            static u32 src_len = 0;

            template <int MaxSize>
            inline bn::string<MaxSize> parse_string(u8* source, u32* cursor, u32 max_length) {
                bn::string<MaxSize> result;
                for (u32 i = 0; i < max_length; i++) {
                    char c = source[*cursor];
                    (*cursor)++;
                    if (c == '\0') {  // Null-terminated string
                        break;
                    }
                    result.push_back(c);  // Append character to result
                }
                return result;
            }

            template <int MaxSize>
            inline bn::string<MaxSize> get_tl(const char* script, const char* locale, unsigned int offset) {
                u32 cursor = offset;
                auto filename = bn::string<32>(script).append(".").append(locale).c_str();
                auto data = (u8*)gbfs_get_obj(fs, filename, &src_len);
                return parse_string<MaxSize>(data, &cursor, src_len);
            }
        }
    }
}

#endif // KS_SCENARIO_READER_H
