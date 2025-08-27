#ifndef GLOBALS_H
#define GLOBALS_H

#include <bn_color.h>
#include <bn_optional.h>
#include <bn_sprite_items_fontpalette_main.h>
#include <bn_sprite_items_fontpalette_beige.h>
#include <bn_sprite_items_fontpalette_beige_selected.h>
#include <bn_sprite_palette_item.h>
#include <bn_unique_ptr.h>

#include "konami_code.h"
#include "definitions.h"
#include "translations/translation.h"
#include "savefile/save_file.h"
#include "utils/gbfs/gbfs.h"

#define KS_SHOW_4LS_INTRO true

namespace ks::globals {
    inline gameState_t state = GS_INIT;
    inline bool exit_scenario = false;
    inline bn::unique_ptr<Translation> i18n;
    inline auto settings = saves::SaveSettingsData();
    inline const GBFS_FILE *filesystem = nullptr;

    extern void init_filesystem();

    extern void init_engine(const bn::optional<bn::color> &clear_color);

    extern void init_engine();

    extern void release_engine();

    extern void set_language(language_t tl);

    extern void main_update();

    extern void ISR_VBlank();

    extern void accessibility_apply();

    namespace colors {
        // image black = "#000"
        inline constexpr auto BLACK = bn::color(0, 0, 0);
        // image white = "#FFF"
        inline constexpr auto WHITE = bn::color(31, 31, 31);
        // image bloodred = "#d00"
        inline constexpr auto BLOODRED = bn::color(27, 0 ,0);
        // image pink = "#FF7FD4"
        inline constexpr auto PINK = bn::color(31, 15, 26);
        // image darkgrey = "#0D0D0D"
        inline constexpr auto DARKGREY = bn::color(2, 2, 2); // Slightly lighter for GBA screen;
    }

    namespace text_palettes {
        const bn::sprite_palette_item original = bn::sprite_items::fontpalette_main.palette_item();
        const bn::sprite_palette_item beige = bn::sprite_items::fontpalette_beige.palette_item();
        const bn::sprite_palette_item beige_selected = bn::sprite_items::fontpalette_beige_selected.palette_item();
    }
}

#endif // GLOBALS_H
