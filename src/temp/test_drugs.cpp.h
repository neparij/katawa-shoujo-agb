/**
* -----------------------------------------------------------------------------
 *  File: test_drugs_bg.cpp.h
 *  Author: neparij (Nikolai Laptev)
 *  Project: Katawa Shoujo - Game Boy Advance
 *  License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International
 *  Creation Date: 2025-08-27
 * -----------------------------------------------------------------------------
 */

#ifndef TEST_DRUGS_BG_CPP_H
#define TEST_DRUGS_BG_CPP_H

#include "ks_huge_bg_item.h"
#include "ks_huge_bg.h"
#include "bn_regular_bg_map_ptr.h"

#include "ks_huge_bg_items_event_drugs_en.h"

void test_drugs()
{
    ks::sound_manager::play(MUSIC_RAIN);
    ks::SceneManager::fade_reset();

    constexpr int updates = 2100;
    constexpr int updates_per_color = 31;
    bn::bg_palettes::set_transparent_color(ks::globals::colors::WHITE);
    bn::optional bg = ks::huge_bg_items::event_drugs_en.create_bg(-48, -176);
    bn::optional move_to_action = bn::regular_bg_top_left_move_to_action(bg->regular_bg_ptr(), updates, -240, -176);

    bn::optional bg_palette = bg->regular_bg_ptr().palette();
    bn::bg_palette_ptr new_pal = bg_palette.value();

    for (int i = 0; i < 64; i++) {
        new_pal.set_color(i, bn::color(31, 31, 31));
    }

    int palette_color_idx = 0;
    int palette_color_timer = 0;
    while (true)
    {

        if (palette_color_idx < 64) {
            if (palette_color_timer < updates_per_color) {
                palette_color_timer++;

                const int color_value = 31 - (palette_color_timer * 31 / updates_per_color);
                new_pal.set_color(palette_color_idx, bn::color(color_value, color_value, color_value));
                bg->regular_bg_ptr().set_palette(new_pal);
            } else {
                palette_color_idx++;
                palette_color_timer = 0;
            }
        }

        if (move_to_action.has_value()) {
            if (!move_to_action->done()) {
                move_to_action->update();
            }
        }

        if (bn::keypad::a_pressed()) {
            move_to_action.value().reset();
        }

        if (bn::keypad::b_pressed()) {
            bg.reset();
            move_to_action.reset();
            bg_palette.reset();
            ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
            break;
        }

        ks::globals::main_update();
    }
}

#endif //TEST_DRUGS_BG_CPP_H
