#ifndef KS_SCENARIO_READER_H
#define KS_SCENARIO_READER_H

#include "bn_string.h"
#include "gba_types.h"

namespace ks {
    namespace textdb {
        static constexpr char CTL_TERMINATOR = 0x00;
        static constexpr char CMD_START = 0xFF;

        extern u8 *ptr;
        extern bool is_allocated;
        extern const u8 *_chunk;

        [[nodiscard]] const u8 *get_chunk();

        void set(const u8 *chunk);

        void allocate();

        void free();

        void get_tl(const unsigned short key, bn::istring &out);
    }
}

#endif // KS_SCENARIO_READER_H
