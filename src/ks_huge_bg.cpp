#include "ks_huge_bg.h"

#include <cstring>

#include "bn_bg_palette_ptr.h"
#include "ks_huge_bg_item.h"
#include "bn_log.h"
#include "bn_math.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "gba_math.h"
#include "ks_huge_bgs_manager.h"

namespace ks {

    huge_bg huge_bg::create(const huge_bg_item &item) {
        return create(0, 0, item);
    }

    huge_bg huge_bg::create(bn::fixed x, bn::fixed y, const huge_bg_item &item) {
        const auto bg_palette = bn::bg_palette_ptr::create(item.palette_item());
        auto bg_tiles = bn::regular_bg_tiles_ptr::allocate(bg_palette.bpp() == bn::bpp_mode::BPP_4 ? TILES_COUNT : TILES_COUNT_BPP8, bg_palette.bpp());
        auto bg_map = bn::regular_bg_map_ptr::allocate(bn::size(32, 32), bg_tiles, bg_palette);

        auto bg = bn::regular_bg_ptr::create(bg_map);
        bg.set_top_left_position(x, y);

        return huge_bg(bg, item.map_dimensions(), item.cells_ref(), item.tiles_ref(), bg_map.vram()->begin(), bg_tiles.vram()->begin());
    }

    void huge_bg::update() {
        const int bg_x = -regular_bg_ptr().top_left_position().x().integer();
        const int bg_y = -regular_bg_ptr().top_left_position().y().integer();
        const int map_width = map_dimensions().width();
        const int map_height = map_dimensions().height();
        const bn::bpp_mode bpp = regular_bg_ptr().palette().bpp();

        x_offset = (floor_div(bg_x, 8) % (map_width * (WIDTH_BLOCKS + 1)) + map_width * (WIDTH_BLOCKS + 1)) % (map_width * (WIDTH_BLOCKS + 1));
        y_offset = (floor_div(bg_y, 8) % (map_height * (HEIGHT_BLOCKS + 1)) + map_height * (HEIGHT_BLOCKS + 1)) % (map_height * (HEIGHT_BLOCKS + 1));

        if (x_offset != previous_x_offset || y_offset != previous_y_offset || !initialized)
        {
            unsigned short xdiff = bn::abs(x_offset - previous_x_offset);
            unsigned short ydiff = bn::abs(y_offset - previous_y_offset);
            previous_x_offset = x_offset;
            previous_y_offset = y_offset;
            //
            // BN_LOG("X Offset: ", x_offset, " Y Offset: ", y_offset);
            // BN_LOG("X Diff: ", xdiff, " Y Diff: ", ydiff);

            for (int yy = 0; yy < HEIGHT_BLOCKS + 1; yy++)
            {
                for (int xx = 0; xx < WIDTH_BLOCKS + 1; xx++)
                {
                    if (!initialized || xx < xdiff || yy < ydiff || xx > WIDTH_BLOCKS - xdiff || yy > HEIGHT_BLOCKS - ydiff) {
                        int raw_x = (xx + x_offset) % 64;
                        int raw_y = (yy + y_offset) % 64;
                        int map_index = raw_y * 64 + raw_x;

                        auto map_cell = _map_data[map_index];
                        int tile_index = map_cell & 0b0000111111111111; // -mB16:p4i12 --- Using 4bits for palette, 12bits for tile index

                        int vram_tile_x = (xx + x_offset) % (WIDTH_BLOCKS + 1);
                        int vram_tile_y = (yy + y_offset) % (HEIGHT_BLOCKS + 1);
                        int vram_tile_index = (vram_tile_y * (WIDTH_BLOCKS + 1) + vram_tile_x) % TILES_COUNT;

                        uint16_t new_map_cell;
                        if (bpp == bn::bpp_mode::BPP_8) {
                            memcpy(&_tiles_vram[vram_tile_index * 2], _tiles_data + tile_index * 64, 64); // 8bpp
                            new_map_cell = (map_cell & 0b1111000000000000) | vram_tile_index;
                        } else {
                            memcpy(&_tiles_vram[vram_tile_index], _tiles_data + tile_index * 32, 32); // 4bpp
                            uint16_t palette = (map_cell >> 12) & 0xF;
                            palette = (palette + regular_bg_ptr().palette().id()) & 0xF;
                            uint16_t palette_bits = palette << 12;
                            new_map_cell = palette_bits | vram_tile_index;
                        }

                        int vram_map_x = (xx + x_offset) % (32);
                        int vram_map_y = (yy + y_offset) % (32);
                        int vram_map_index = vram_map_y * 32 + vram_map_x;

                        _map_vram[vram_map_index] = new_map_cell;
                        asm __volatile("nop");
                        asm __volatile("nop");
                    }
                }
            }

            initialized = true;
        }
    }

    huge_bg& huge_bg::operator=(const huge_bg& other) {
        if (this == &other) {
            return *this;
        }

        _wrapped_bg_ptr = other._wrapped_bg_ptr;
        _map_dimensions = other._map_dimensions;
        _map_data = other._map_data;
        _tiles_data = other._tiles_data;
        _map_vram = other._map_vram;
        _tiles_vram = other._tiles_vram;

        x_offset = other.x_offset;
        y_offset = other.y_offset;
        previous_x_offset = other.previous_x_offset;
        previous_y_offset = other.previous_y_offset;
        initialized = other.initialized;

        return *this;
    }

    huge_bg::~huge_bg() {
        huge_bgs_manager::pop(this);
    }
}
