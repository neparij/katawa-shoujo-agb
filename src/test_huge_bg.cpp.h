#ifndef TEST_HUGE_BG_CPP_H
#define TEST_HUGE_BG_CPP_H
#include <cstring>

#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "huge/event_hanako_scars_huge.h"

#define WIDTH_BLOCKS 30 // 240 pixels / 8 pixels per tile
#define HEIGHT_BLOCKS 20 // 160 pixels / 8 pixels per tile

#define TILES_COUNT ((WIDTH_BLOCKS * HEIGHT_BLOCKS) + (WIDTH_BLOCKS + HEIGHT_BLOCKS) + 1)
#define TILES_COUNT_BPP8 (TILES_COUNT * 2)

void test_huge_bg_cpp()
{

    // ks::sound_manager::play(MUSIC_CREDITS);

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

    // Кэшируем указатели на данные для избежания повторных обращений
    const auto* map_data = (const bn::regular_bg_map_cell*)event_hanako_scars_hugeMap;
    const uint8_t* tiles_data = (const uint8_t*)event_hanako_scars_hugeTiles;

    int previous_x_offset = -1;
    int previous_y_offset = -1;
    int x_offset = 0;
    int y_offset = 0;

    int bg_x = 0;
    int bg_y = 0;

    bool initialized = false;

    while (true)
    {
        if (bn::keypad::left_held() || bn::keypad::right_held()) {
            bg_x += (bn::keypad::left_held() ? -1 : 1);
        }
        if (bn::keypad::up_held() || bn::keypad::down_held()) {
            bg_y += (bn::keypad::up_held() ? -1 : 1);
        }

        // x_offset = ((bg_x / 8) % 64 + 64) % 64;
        // y_offset = ((bg_y / 8) % 64 + 64) % 64;
        x_offset = ((bg_x >> 3) % (64 * (WIDTH_BLOCKS + 1)) + 64) % (64 * (WIDTH_BLOCKS + 1));
        y_offset = ((bg_y >> 3) % (64 * (HEIGHT_BLOCKS + 1)) + 64) % (64 * (HEIGHT_BLOCKS + 1));

        if (x_offset != previous_x_offset || y_offset != previous_y_offset)
        {
            previous_x_offset = x_offset;
            previous_y_offset = y_offset;

            BN_LOG("X Offset: ", x_offset, " Y Offset: ", y_offset);

            for (int yy = 0; yy < HEIGHT_BLOCKS + 1; yy++)
            {
                for (int xx = 0; xx < WIDTH_BLOCKS + 1; xx++)
                {
                    int raw_x = (xx + x_offset) & 63;
                    int raw_y = (yy + y_offset) & 63;
                    int map_index = (raw_y << 6) + raw_x;

                    auto map_cell = map_data[map_index];
                    int tile_index = map_cell & 0b0000111111111111; // -mB16:p4i12 --- Using 4bits for palette, 12bits for tile index


                    const uint8_t* tile_ptr = tiles_data + (tile_index << 6); // * 64 заменено на битовый сдвиг

                    int vram_tile_x = (xx + x_offset) % (WIDTH_BLOCKS + 1);
                    int vram_tile_y = (yy + y_offset) % (HEIGHT_BLOCKS + 1);
                    int vram_tile_index = (vram_tile_y * (WIDTH_BLOCKS + 1) + vram_tile_x) % TILES_COUNT;
                    if (!initialized || yy == HEIGHT_BLOCKS || xx == WIDTH_BLOCKS || yy == 0 || xx == 0) {
                        // memcpy(&tiles_vram->begin()[vram_tile_index * 2], tile_ptr, 64); // 8bpp
                        dmaCopy(tile_ptr, &tiles_vram->begin()[vram_tile_index * 2], 64); // 8bpp
                    }

                    uint16_t new_map_cell = (map_cell & 0b1111000000000000) | vram_tile_index;
                    // In the VRAM we draw the corner quadrants, as the BG have offset to half of it size
                    // and is wrapped.
                    int vram_map_x = (xx + 16) & 31;
                    int vram_map_y = (yy + 16) & 31;
                    int vram_map_index = (vram_map_y << 5) + vram_map_x;

                    map_vram->begin()[vram_map_index] = new_map_cell;
                }
            }
            initialized = true;
        }

        // bg->set_top_left_position(0, 0);
        // bg->set_top_left_position(-bg_x % 8 + 128, -bg_y % 8 + 128);
        bg->set_top_left_position(-(bg_x & 7) + 128, -(bg_y & 7) + 128);
        ks::globals::main_update();
        auto cpu = bn::core::last_cpu_usage();
        if (cpu > bn::fixed(0.1)) {
            BN_LOG("Last CPU Usage: ", bn::core::last_cpu_usage() * 100, "%");
        }
        // ((bg_x / 8) % 64 + 64) % 64;
    }
}

#endif //TEST_HUGE_BG_CPP_H
