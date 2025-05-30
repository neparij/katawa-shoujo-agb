/**
* -----------------------------------------------------------------------------
 *  File: test_huge_bg.cpp.h
 *  Description: Testing the display of huge backgrounds in the Katawa Shoujo GBA project.
 *  Author: neparij (Nikolai Laptev)
 *  Project: Katawa Shoujo - Game Boy Advance
 *  License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International
 *  Creation Date: 2025-05-28
 * -----------------------------------------------------------------------------
 */

#ifndef TEST_HUGE_BG_CPP_H
#define TEST_HUGE_BG_CPP_H

#include "ks_huge_bg_item.h"
#include "ks_huge_bg.h"
#include "bn_regular_bg_map_ptr.h"

#include "ks_huge_bg_items_event_hanako_scars_4bpp.h"

#define WIDTH_BLOCKS 30 // 240 pixels / 8 pixels per tile
#define HEIGHT_BLOCKS 20 // 160 pixels / 8 pixels per tile

#define TILES_COUNT ((WIDTH_BLOCKS * HEIGHT_BLOCKS) + (WIDTH_BLOCKS + HEIGHT_BLOCKS) + 1)
#define TILES_COUNT_BPP8 (TILES_COUNT * 2)

#define USE_8BPP false

void test_huge_bg_cpp()
{
    ks::sound_manager::play(MUSIC_HANAKO);
    ks::SceneManager::fade_reset();

    bn::optional bg = ks::huge_bg_items::event_hanako_scars_4bpp.create_bg(-48, -352);
    bn::optional move_to_action = bn::regular_bg_top_left_move_to_action(bg->regular_bg_ptr(), 1800, -216, 0);

    while (true)
    {
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
            ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
            break;
        }

        ks::globals::main_update();
    }
}

#endif //TEST_HUGE_BG_CPP_H
