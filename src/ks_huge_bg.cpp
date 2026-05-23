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
        BN_LOG("huge_bg::create(bn::fixed x, bn::fixed y, const huge_bg_item &item)");
        BN_LOG("Create PAL");
        const auto bg_palette = bn::bg_palette_ptr::create(item.palette_item());
        BN_LOG("Create TILES");
        auto bg_tiles = bn::regular_bg_tiles_ptr::allocate(bg_palette.bpp() == bn::bpp_mode::BPP_4 ? TILES_COUNT : TILES_COUNT_BPP8, bg_palette.bpp());
        BN_LOG("Create MAP");
        auto bg_map = bn::regular_bg_map_ptr::allocate(bn::size(32, 32), bg_tiles, bg_palette);

        BN_LOG("Create PTR");
        auto bg = bn::regular_bg_ptr::create(bg_map);

        BN_LOG("Set Position");
        bg.set_position(x, y);

        BN_LOG("<<< return huge_bg >>>");
        return huge_bg(bg, item.map_dimensions(), item.cells_ref(), item.tiles_ref(), bg_map.vram()->begin(), bg_tiles.vram()->begin());
    }

    void huge_bg::update() {
        const bn::fixed_point top_left = regular_bg_ptr().top_left_position();
        const int bg_x = (-top_left.x()).right_shift_integer();
        const int bg_y = (-top_left.y()).right_shift_integer();
        const int map_width = map_dimensions().width();
        const int map_height = map_dimensions().height();
        const bn::bpp_mode bpp = regular_bg_ptr().palette().bpp();

        const int x_tile = huge_bg_tile_offset_for_axis(bg_x, previous_bg_x, initialized);
        const int y_tile = huge_bg_tile_offset_for_axis(bg_y, previous_bg_y, initialized);

        x_offset = (x_tile % (map_width * (WIDTH_BLOCKS + 1)) + map_width * (WIDTH_BLOCKS + 1))
                   % (map_width * (WIDTH_BLOCKS + 1));
        y_offset = (y_tile % (map_height * (HEIGHT_BLOCKS + 1)) + map_height * (HEIGHT_BLOCKS + 1))
                   % (map_height * (HEIGHT_BLOCKS + 1));

        previous_bg_x = bg_x;
        previous_bg_y = bg_y;

        if (x_offset != previous_x_offset || y_offset != previous_y_offset || !initialized)
        {
            unsigned short xdiff = bn::abs(x_offset - previous_x_offset);
            unsigned short ydiff = bn::abs(y_offset - previous_y_offset);
            previous_x_offset = x_offset;
            previous_y_offset = y_offset;

            for (int yy = 0; yy < HEIGHT_BLOCKS + 1; yy++)
            {
                for (int xx = 0; xx < WIDTH_BLOCKS + 1; xx++)
                {
                    const bool upload_tile = !initialized || xx < xdiff || yy < ydiff
                            || xx > WIDTH_BLOCKS - xdiff || yy > HEIGHT_BLOCKS - ydiff;

                    int raw_x = (xx + x_offset) % map_width;
                    int raw_y = (yy + y_offset) % map_height;
                    int map_index = raw_y * map_width + raw_x;

                    auto map_cell = _map_data[map_index];
                    int tile_index = map_cell & 0b0000111111111111;

                    int vram_tile_x = (xx + x_offset) % (WIDTH_BLOCKS + 1);
                    int vram_tile_y = (yy + y_offset) % (HEIGHT_BLOCKS + 1);
                    int vram_tile_index = (vram_tile_y * (WIDTH_BLOCKS + 1) + vram_tile_x) % TILES_COUNT;

                    uint16_t new_map_cell;
                    if (bpp == bn::bpp_mode::BPP_8) {
                        if (upload_tile) {
                            memcpy(&_tiles_vram[vram_tile_index * 2], _tiles_data + tile_index * 64, 64);
                        }
                        new_map_cell = (map_cell & 0b1111000000000000) | vram_tile_index;
                    } else {
                        if (upload_tile) {
                            memcpy(&_tiles_vram[vram_tile_index], _tiles_data + tile_index * 32, 32);
                        }
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

            initialized = true;
        }
    }

    huge_bg& huge_bg::operator=(const huge_bg& other) {
        BN_LOG("huge_bg::operator=(const huge_bg& other)");
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
        previous_bg_x = other.previous_bg_x;
        previous_bg_y = other.previous_bg_y;
        initialized = other.initialized;

        return *this;
    }

    bn::fixed_point huge_bg::position() const {
        return regular_bg_ptr().position();
    }

    huge_bg::~huge_bg() {
        huge_bgs_manager::pop(this);
    }
}
