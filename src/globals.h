#ifndef GLOBALS_H
#define GLOBALS_H

#include "utils/gbfs/gbfs.h"

#include <bn_color.h>
#include <bn_optional.h>
#include <bn_sprite_items_variable_16x16_font.h>
#include <bn_sprite_items_variable_16x16_font_hi_pal.h>
#include <bn_sprite_palette_item.h>
#include <bn_vector.h>

#include "definitions.h"
#include "savefile/save_file.h"

static const GBFS_FILE* fs = find_first_gbfs_file(0);
alignas(4) static u8 translation_buffer[4];

namespace ks {
    // Forward declaration
    class Translation;

    namespace globals {
        extern bool exit_scenario;
        extern ks::Translation* i18n;
        extern ks::saves::SaveSettingsData settings;

        extern void init_engine(const bn::optional<bn::color> &clear_color);
        extern void init_engine();
        extern void release_engine();
        extern void set_language(language_t tl);

        extern void main_update();
        extern void ISR_VBlank();
        extern void sound_update();

        extern void accessibility_apply();

        namespace colors {
            extern const bn::color BLACK;
            extern const bn::color WHITE;
            extern const bn::color RED;
        }

        namespace text_palettes {
            const bn::sprite_palette_item original = bn::sprite_items::variable_16x16_font.palette_item();
            extern const bn::sprite_palette_item beige;
            extern const bn::sprite_palette_item beige_selected;
        }
    }
}

#endif // GLOBALS_H
