#ifndef KS_SCENARIO_READER_H
#define KS_SCENARIO_READER_H

#include "bn_string.h"
#include "gba_types.h"
#include <BN_LOG.h>

namespace ks {
    namespace scenario {
        static const char CTL_TERMINATOR = '\0'; // NUL - the end of textdb chunk
        static const char CTL_FAST = '\1'; // SOH - sets cursor to render text by chars
        static const char CTL_BOLD_START = '\2'; // STX - starts bold text (switch spritefont)
        static const char CTL_BOLD_END = '\3'; // ETX - ends bold text (restore spritefont)
        static const char CTL_STRIKE_START = '\4'; // EOT - starts strikethrough text (switch spritefont?)
        static const char CTL_STRIKE_END = '\5'; // ENQ - ends strikethrough text (restore spritefont?)
        static const char CTL_WAIT = '\6'; // ACK - wait command (next byte is count of 1/10 seconds to wait)
        static const char CTL_NOWAIT = '\7'; // BEL - do not wait for user input to continue dialogue
        static const char CTL_COLOR_START = '\10'; // BS - sets the color (switch spritepalette, next byte is palette index)
        static const char CTL_COLOR_END = '\11'; // HT - restore color (switch spritepalette)


        namespace gbfs_reader {

            template <int MaxSize>
            inline void BN_CODE_IWRAM get_tl(u8* text_db, u32 text_db_size, unsigned int offset, bn::string<MaxSize>& out) {
                BN_LOG("O1");
                u32 cursor = offset;
                out.clear();
                BN_LOG("O2");
                for (u32 i = 0; i < text_db_size; i++) {
                    char c = text_db[cursor];

                    if (c == CTL_TERMINATOR) {
                        break;
                    }

                    out.push_back(c);
                    cursor++;
                }
                BN_LOG("O3");
            }
        }
    }
}

#endif // KS_SCENARIO_READER_H
