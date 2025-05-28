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
#include <cstring>

#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "huge/event_hanako_scars_huge.h"
#include "huge/event_hanako_scars_4bpp_huge.h"

#define WIDTH_BLOCKS 30 // 240 pixels / 8 pixels per tile
#define HEIGHT_BLOCKS 20 // 160 pixels / 8 pixels per tile

#define TILES_COUNT ((WIDTH_BLOCKS * HEIGHT_BLOCKS) + (WIDTH_BLOCKS + HEIGHT_BLOCKS) + 1)
#define TILES_COUNT_BPP8 (TILES_COUNT * 2)

inline int floor_div(const int a, const int b) {
    return a >= 0 ? a / b : (a - b + 1) / b;
}

#define USE_8BPP true

void test_huge_bg_cpp()
{

    ks::sound_manager::play(MUSIC_HANAKO);

    ks::SceneManager::fade_reset();
    bn::optional<bn::regular_bg_ptr> bg;
#if USE_8BPP
    bn::optional bg_palette = bn::bg_palette_item(bn::span<const bn::color>((bn::color*)event_hanako_scars_hugePal, 192), bn::bpp_mode::BPP_8, bn::compression_type::RUN_LENGTH).create_palette();
    bn::optional bg_tiles = bn::regular_bg_tiles_ptr::allocate(TILES_COUNT_BPP8, bn::bpp_mode::BPP_8);
    bn::optional bg_map = bn::regular_bg_map_ptr::allocate(bn::size(32, 32), bg_tiles.value(), bg_palette.value());
#else
    bn::optional bg_palette = bn::bg_palette_item(bn::span<const bn::color>((bn::color*)event_hanako_scars_4bpp_hugePal, 192), bn::bpp_mode::BPP_4, bn::compression_type::RUN_LENGTH).create_palette();
    bn::optional bg_tiles = bn::regular_bg_tiles_ptr::allocate(TILES_COUNT, bn::bpp_mode::BPP_4);
    bn::optional bg_map = bn::regular_bg_map_ptr::allocate(bn::size(32, 32), bg_tiles.value(), bg_palette.value());
#endif

    bg = bn::regular_bg_ptr::create(bg_map.value());


#if USE_8BPP
    uint8_t* tiles_data = (uint8_t*)event_hanako_scars_hugeTiles;
    uint16_t* map_data = (uint16_t*)event_hanako_scars_hugeMap;
#else
    uint8_t* tiles_data = (uint8_t*)event_hanako_scars_4bpp_hugeTiles;
    uint16_t* map_data = (uint16_t*)event_hanako_scars_4bpp_hugeMap;
#endif

    auto map_vram = bg_map.value().vram();
    BN_LOG("BG_MAP VRAM: ", map_vram->begin());

    auto tiles_vram = bg_tiles.value().vram();
    BN_LOG("BG_TILES VRAM: ", tiles_vram->begin());

    int previous_x_offset = -1;
    int previous_y_offset = -1;
    int x_offset = 0;
    int y_offset = 0;

    int bg_x = 48;
    int bg_y = 352;
    bool initialized = false;

    while (true)
    {
        if (bn::keypad::left_held() || bn::keypad::right_held()) {
            bg_x += (bn::keypad::left_held() ? -1 : 1);
            BN_LOG("New BG X: ", bg_x);
        }
        if (bn::keypad::up_held() || bn::keypad::down_held()) {
            bg_y += (bn::keypad::up_held() ? -1 : 1);
            BN_LOG("New BG Y: ", bg_y);
        }

        bg->set_top_left_position(0 - bg_x, 0 - bg_y);

        if (initialized) {
            ks::globals::main_update();
        }


        x_offset = (floor_div(bg_x, 8) % (64 * (WIDTH_BLOCKS + 1)) + 64 * (WIDTH_BLOCKS + 1)) % (64 * (WIDTH_BLOCKS + 1));
        y_offset = (floor_div(bg_y, 8) % (64 * (HEIGHT_BLOCKS + 1)) + 64 * (HEIGHT_BLOCKS + 1)) % (64 * (HEIGHT_BLOCKS + 1));

        if (x_offset != previous_x_offset || y_offset != previous_y_offset || !initialized)
        {
            unsigned short xdiff = bn::abs(x_offset - previous_x_offset);
            unsigned short ydiff = bn::abs(y_offset - previous_y_offset);
            previous_x_offset = x_offset;
            previous_y_offset = y_offset;

            BN_LOG("X Offset: ", x_offset, " Y Offset: ", y_offset);
            BN_LOG("X Diff: ", xdiff, " Y Diff: ", ydiff);

            for (int yy = 0; yy < HEIGHT_BLOCKS + 1; yy++)
            {
                for (int xx = 0; xx < WIDTH_BLOCKS + 1; xx++)
                {
                    if (!initialized || xx < xdiff || yy < ydiff || xx > WIDTH_BLOCKS - xdiff || yy > HEIGHT_BLOCKS - ydiff) {
                        int raw_x = (xx + x_offset) % 64;
                        int raw_y = (yy + y_offset) % 64;
                        int map_index = raw_y * 64 + raw_x;

                        auto map_cell = map_data[map_index];
                        int tile_index = map_cell & 0b0000111111111111; // -mB16:p4i12 --- Using 4bits for palette, 12bits for tile index

                        int vram_tile_x = (xx + x_offset) % (WIDTH_BLOCKS + 1);
                        int vram_tile_y = (yy + y_offset) % (HEIGHT_BLOCKS + 1);
                        int vram_tile_index = (vram_tile_y * (WIDTH_BLOCKS + 1) + vram_tile_x) % TILES_COUNT;
#if USE_8BPP
                        memcpy(&tiles_vram->begin()[vram_tile_index * 2], tiles_data + tile_index * 64, 64); // 8bpp
                        uint16_t new_map_cell = (map_cell & 0b1111000000000000) | vram_tile_index;
#else
                        memcpy(&tiles_vram->begin()[vram_tile_index], tiles_data + tile_index * 32, 32); // 4bpp
                        uint16_t palette = (map_cell >> 12) & 0xF;
                        palette = (palette + bg_palette->id()) & 0xF;
                        uint16_t palette_bits = palette << 12;
                        uint16_t new_map_cell = palette_bits | vram_tile_index;
#endif

                        int vram_map_x = (xx + x_offset) % (32);
                        int vram_map_y = (yy + y_offset) % (32);
                        int vram_map_index = vram_map_y * 32 + vram_map_x;

                        map_vram->begin()[vram_map_index] = new_map_cell;
                        asm __volatile("nop");
                        asm __volatile("nop");
                    }
                }
            }

            initialized = true;
        }
    }
}

#endif //TEST_HUGE_BG_CPP_H
