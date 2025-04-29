#ifndef GLOBALS_H
#define GLOBALS_H

#include <bn_color.h>
#include <bn_optional.h>
#include <bn_sprite_items_variable_16x16_font.h>
#include <bn_sprite_items_variable_16x16_font_hi_pal.h>
#include <bn_sprite_palette_item.h>
#include <bn_unique_ptr.h>

#include "definitions.h"
#include "translation.h"
#include "savefile/save_file.h"
#include "utils/gbfs/gbfs.h"

#define KS_AGB_VERSION "0.3.1+00"
#define KS_SHOW_4LS_INTRO true

static const GBFS_FILE* fs = find_first_gbfs_file(nullptr);

namespace ks {
    // Forward declaration
    // class Translation;

    namespace globals {
        extern gameState_t state;
        extern bool exit_scenario;
        extern bn::unique_ptr<Translation> i18n;
        extern saves::SaveSettingsData settings;

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
