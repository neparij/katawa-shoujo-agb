#ifndef GLOBALS_H
#define GLOBALS_H

#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_ptr.h"
#include "utils/gbfs/gbfs.h"

#include <bn_vector.h>

static const GBFS_FILE* fs = find_first_gbfs_file(0);

namespace ks {
    namespace globals {
        extern bool show_memory_debug;
        extern bool use_alt_lang;

        extern void main_update();
        extern void ISR_VBlank();
    }
}

#endif // GLOBALS_H
