#ifndef KS_SCENARIO_READER_H
#define KS_SCENARIO_READER_H

#include "bn_string.h"
#include "../globals.h"

namespace ks {
    namespace scenario {
        namespace gbfs_reader {

            using u32 = unsigned long;
            using u8 = unsigned char;


            static u32 src_len = 0;
            inline bn::string<512> parse_string(u8* source, u32* cursor, u32 max_length) {
                bn::string<512> result;

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

            inline bn::string<512> get_tl(const char* script, const char* locale, unsigned int offset) {
                // u32 cursor = 0x0A2F;
                u32 cursor = offset;
                auto filename = bn::string<32>(script).append(".").append(locale).c_str();
                auto data = (u8*)gbfs_get_obj(fs, filename, &src_len);
                // const char* text = (const char*)&data[offset];

                auto fff = parse_string(data, &cursor, src_len);
                return fff;
                // auto outf = bn::string_view(fff);
            }

            inline bn::string<128> get_short_tl(const char* script, const char* locale, unsigned int offset) {
                // u32 cursor = 0x0A2F;
                u32 cursor = offset;
                auto filename = bn::string<32>(script).append(".").append(locale).c_str();
                auto data = (u8*)gbfs_get_obj(fs, filename, &src_len);
                // const char* text = (const char*)&data[offset];

                auto fff = parse_string(data, &cursor, src_len);
                return fff;
                // auto outf = bn::string_view(fff);
            }
        }
    }
}

#endif // KS_SCENARIO_READER_H
