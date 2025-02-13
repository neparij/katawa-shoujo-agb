#ifndef GLOBALS_H
#define GLOBALS_H

#include "utils/gbfs/gbfs.h"

#include <bn_color.h>
#include <bn_optional.h>
#include <bn_vector.h>

static const GBFS_FILE* fs = find_first_gbfs_file(0);
alignas(4) static u8 translation_buffer[4];

namespace ks {
    // Forward declaration
    class Translation;
    enum class TranslationType;

    namespace globals {
        extern bool exit_scenario;
        extern ks::Translation* i18n;
        extern ks::TranslationType language;

        extern void init_engine(const bn::optional<bn::color> &clear_color);
        extern void init_engine();
        extern void release_engine();
        extern void set_language(ks::TranslationType tl);

        extern void main_update();
        extern void ISR_VBlank();
        extern void sound_update();

        namespace colors {
            extern const bn::color BLACK;
            extern const bn::color WHITE;
            extern const bn::color RED;
        }
    }
}

#endif // GLOBALS_H
