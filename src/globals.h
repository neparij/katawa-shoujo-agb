#ifndef GLOBALS_H
#define GLOBALS_H

#include <bn_color.h>
#include <bn_optional.h>
#include <bn_sprite_items_fontpalette_main.h>
#include <bn_sprite_items_fontpalette_main_bold.h>
#include <bn_sprite_items_fontpalette_beige.h>
#include <bn_sprite_items_fontpalette_beige_bold.h>
#include <bn_sprite_items_fontpalette_beige_selected.h>
#include <bn_sprite_items_fontpalette_beige_selected_bold.h>
#include <bn_sprite_items_fontpalette_beige_disabled.h>
#include <bn_sprite_items_fontpalette_beige_disabled_bold.h>
#include <bn_sprite_items_fontpalette_alive.h>
#include <bn_sprite_items_fontpalette_alive_bold.h>
#include <bn_sprite_items_fontpalette_red.h>
#include <bn_sprite_items_fontpalette_red_bold.h>
#include <bn_sprite_items_fontpalette_mi.h>
#include <bn_sprite_items_fontpalette_mi_bold.h>
#include <bn_sprite_palette_item.h>
#include <bn_unique_ptr.h>

#include "konami_code.h"
#include "definitions.h"
#include "translation.h"
#include "savefile/save_file.h"
#include "utils/gbfs/gbfs.h"

#define KS_SHOW_4LS_INTRO true

namespace ks::globals {
    struct system_stats_t {
        char magic[16] = { 'K', 'S', 'G', 'B', 'A', 'S', 'Y', 'S', 'S', 'T', 'A', 'T', 'S', 0, 0, 0 };
        uint32_t last_used_cpu;
        uint32_t ewram_used;
        uint16_t bg_tiles_used;
        uint16_t bg_maps_used;
        uint16_t bg_palettes_used;
        uint16_t sprite_tiles_used;
        uint16_t sprite_palettes_used;

        system_stats_t() :
            last_used_cpu(0),
            ewram_used(0),
            bg_tiles_used(0),
            bg_maps_used(0),
            bg_palettes_used(0),
            sprite_tiles_used(0),
            sprite_palettes_used(0)
        {}
    };

    inline auto system_stats = system_stats_t();

    extern void update_system_stats();

    inline gameState_t state = GS_INIT;
    inline bool exit_scenario = false;
    inline bool in_game = false;
    inline auto settings = saves::SaveSettingsData();
    inline auto states = saves::SaveStatesData();
    inline const GBFS_FILE *filesystem = nullptr;

    extern void init_filesystem();

    extern void init_engine(const bn::optional<bn::color> &clear_color);

    extern void init_engine();

    extern void release_resources();

    extern void release_engine();

    extern void set_language(language_t tl);

    extern void init_text_generators(language_t tl);

    extern void init_text_generators();

    extern void main_update();

    extern void ISR_VBlank();

    extern void accessibility_apply();

    extern bn::fixed transparency_alpha();

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
        const bn::sprite_palette_item beige_disabled = bn::sprite_items::fontpalette_beige_disabled.palette_item();

        [[nodiscard]] inline bn::sprite_palette_item bold(const bn::sprite_palette_item& text_item_palette) {
            if (text_item_palette == original) {
                return bn::sprite_items::fontpalette_main_bold.palette_item();
            }
            if (text_item_palette == beige) {
                return bn::sprite_items::fontpalette_beige_bold.palette_item();
            }
            if (text_item_palette == beige_selected) {
                return bn::sprite_items::fontpalette_beige_selected_bold.palette_item();
            }
            if (text_item_palette == beige_disabled) {
                return bn::sprite_items::fontpalette_beige_disabled_bold.palette_item();
            }
            if (text_item_palette == bn::sprite_items::fontpalette_alive.palette_item()) {
                return bn::sprite_items::fontpalette_alive_bold.palette_item();
            }
            if (text_item_palette == bn::sprite_items::fontpalette_red.palette_item()) {
                return bn::sprite_items::fontpalette_red_bold.palette_item();
            }
            if (text_item_palette == bn::sprite_items::fontpalette_mi.palette_item()) {
                return bn::sprite_items::fontpalette_mi_bold.palette_item();
            }

            BN_ERROR("Unknown palette type for bold variant");
            return bn::sprite_items::fontpalette_main_bold.palette_item();
        }

        // Ren'Py {color=#...} indices from tools/converter/src/utils.py RENPY_COLOR_TO_PALETTE_INDEX.
        [[nodiscard]] inline bn::sprite_palette_item colored(const unsigned char index) {
            switch(index) {
                case 0:
                    // TODO: verify #fff / default palette on every background
                    return original;
                case 1:
                    return bn::sprite_items::fontpalette_alive.palette_item();
                case 2:
                    return bn::sprite_items::fontpalette_red.palette_item();
                case 3:
                    return bn::sprite_items::fontpalette_mi.palette_item();
                default:
                    return original;
            }
        }
    }
}

#endif // GLOBALS_H
