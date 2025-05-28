#ifndef TEST_HUGE_BG_CPP_H
#define TEST_HUGE_BG_CPP_H
#include <cstring>

#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "huge/event_hanako_scars_huge.h"

#define WIDTH_BLOCKS 30 // 240 pixels / 8 pixels per tile
#define HEIGHT_BLOCKS 20 // 160 pixels / 8 pixels per tile

#define TILES_COUNT_BPP4 ((WIDTH_BLOCKS * HEIGHT_BLOCKS) + (WIDTH_BLOCKS + HEIGHT_BLOCKS) + 1)
#define TILES_COUNT_BPP8 (TILES_COUNT_BPP4 * 2)

void test_huge_bg_cpp()
{
    ks::SceneManager::fade_reset();
    bn::optional<bn::regular_bg_ptr> bg;
    bn::optional bg_palette = bn::bg_palette_item(bn::span<const bn::color>((bn::color*)event_hanako_scars_hugePal, 192), bn::bpp_mode::BPP_8, bn::compression_type::NONE).create_palette();
    bn::optional bg_tiles = bn::regular_bg_tiles_ptr::allocate(TILES_COUNT_BPP8, bn::bpp_mode::BPP_8);
    bn::optional bg_map = bn::regular_bg_map_ptr::allocate(bn::size(32, 32), bg_tiles.value(), bg_palette.value());
    // bn::regular_bg_map_ptr::create()
    // bn::regular_bg_ptr::create()

    bg = bn::regular_bg_ptr::create(bg_map.value());

    auto map_vram = bg_map.value().vram();
    BN_LOG("BG_MAP VRAM: ", map_vram->begin());

    auto tiles_vram = bg_tiles.value().vram();
    BN_LOG("BG_TILES VRAM: ", tiles_vram->begin());

    int previous_x_offset = -1;
    int previous_y_offset = -1;
    int x_offset = 0;
    int y_offset = 0;

    int bg_x = 0;
    int bg_y = 0;

    while (true)
    {
        // x_offset = (bg_x / 8) % 64;
        // y_offset = (bg_y / 8) % 64;
        x_offset = ((bg_x / 8) % 64 + 64) % 64;
        y_offset = ((bg_y / 8) % 64 + 64) % 64;

        if (x_offset != previous_x_offset || y_offset != previous_y_offset)
        {
            previous_x_offset = x_offset;
            previous_y_offset = y_offset;

            for (int yy = 0; yy < HEIGHT_BLOCKS + 1; yy++)
            {
                for (int xx = 0; xx < WIDTH_BLOCKS + 1; xx++)
                {
                    // Bits:  0-9   = tile index (0–1023)
                    //        10    = horizontal flip
                    //        11    = vertical flip
                    //        12-15 = palette (for 4bpp mode)
                    // int map_index = (yy + y_offset) * 64 + xx + x_offset;

                    int raw_x = (xx + x_offset) % 64;
                    int raw_y = (yy + y_offset) % 64;
                    int map_index = raw_y * 64 + raw_x;

                    auto map_cell = ((bn::regular_bg_map_cell*)event_hanako_scars_hugeMap)[map_index];
                    int tile_index = map_cell & 0b0000111111111111; // -mB16:p4i12 --- Using 4bits for palette, 12bits for tile index


                    uint8_t* tiles_data = (uint8_t*)event_hanako_scars_hugeTiles;
                    uint8_t* tile_ptr = tiles_data + tile_index * 64; // 8bpp
                    int vram_tile_index = (yy * (WIDTH_BLOCKS + 1) + xx);
                    memcpy(&tiles_vram->begin()[vram_tile_index * 2], tile_ptr, 64); // 8bpp

                    uint16_t new_map_cell = (map_cell & 0b1111000000000000) | vram_tile_index;
                    map_vram->begin()[yy * 32 + xx] = new_map_cell;
                }
            }
        }

        if (bn::keypad::left_held() || bn::keypad::right_held()) {
            bg_x += (bn::keypad::left_held() ? -1 : 1);
        }
        if (bn::keypad::up_held() || bn::keypad::down_held()) {
            bg_y += (bn::keypad::up_held() ? -1 : 1);
        }
        bg->set_top_left_position(0, 0);
        // bg->set_position(bg_x, bg_y);
        ks::globals::main_update();
    }
}

#endif //TEST_HUGE_BG_CPP_H
