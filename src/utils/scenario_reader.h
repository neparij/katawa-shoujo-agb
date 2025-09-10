#ifndef KS_SCENARIO_READER_H
#define KS_SCENARIO_READER_H

#define KS_TEXTDB_INDEX_SIZE 512
#define KS_TEXTDB_MAX_OFFSET 0xFFFF


#include "bn_string.h"
#include "gba_types.h"

namespace ks {
    namespace textdb {
        static constexpr char CTL_TERMINATOR = '\0';

        extern u8 *ptr;
        extern u32 size;
        extern bool is_allocated;
        extern u16 _index[KS_TEXTDB_INDEX_SIZE];
        extern const char *_chunk;
        extern const char *_locale;

        void set(const char *chunk, const char *locale);

        void allocate();

        void free();

        template<int MaxSize>
        void get_tl(const unsigned short key, bn::string<MaxSize> &out);

        char *get_tl_cstr(const unsigned short key);
    }
}

#endif // KS_SCENARIO_READER_H
