#ifndef GLOBALS_H
#define GLOBALS_H

#include "utils/gbfs/gbfs.h"

#include <bn_vector.h>

static const GBFS_FILE* fs = find_first_gbfs_file(0);

namespace ks {
    // Forward declaration
    class Translation;

    namespace globals {
        extern bool exit_scenario;
        extern ks::Translation* i18n;

        extern void main_update();
        extern void ISR_VBlank();
    }
}

#endif // GLOBALS_H
