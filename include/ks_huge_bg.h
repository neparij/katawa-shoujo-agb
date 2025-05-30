/**
* -----------------------------------------------------------------------------
 *  File: ks_huge_bg.h
 *  Description: Header file for the huge background instance
 *  Author: neparij (Nikolai Laptev)
 *  Project: Katawa Shoujo - Game Boy Advance
 *  License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International
 *  Creation Date: 2025-05-29
 * -----------------------------------------------------------------------------
 */

#ifndef KS_HUGE_BG_H
#define KS_HUGE_BG_H

#include "bn_log.h"
#include "ks_huge_bgs_manager.h"
#include "bn_regular_bg_ptr.h"
#include "bn_size.h"
#include "bn_span.h"
#include "bn_tile.h"

#define WIDTH_BLOCKS 30 // 240 pixels / 8 pixels per tile
#define HEIGHT_BLOCKS 20 // 160 pixels / 8 pixels per tile
#define TILES_COUNT ((WIDTH_BLOCKS * HEIGHT_BLOCKS) + (WIDTH_BLOCKS + HEIGHT_BLOCKS) + 1)
#define TILES_COUNT_BPP8 (TILES_COUNT * 2)

namespace ks {
    class huge_bg_item;

    class huge_bg {
    public:
        ~huge_bg();

        [[nodiscard]] static huge_bg create(const huge_bg_item &item);

        [[nodiscard]] static huge_bg create(bn::fixed x, bn::fixed y, const huge_bg_item &item);

        [[nodiscard]] bn::regular_bg_ptr regular_bg_ptr() {
            return _wrapped_bg_ptr;
        }

        [[nodiscard]] bn::size map_dimensions() const {
            return _map_dimensions;
        }

        huge_bg(huge_bg &&other) noexcept : huge_bg(other._wrapped_bg_ptr,
                                                             other._map_dimensions,
                                                             other._map_data,
                                                             other._tiles_data,
                                                             other._map_vram,
                                                             other._tiles_vram) {
            *this = bn::move(other);
        }

        // // Copy constructor.
        // huge_bg(const huge_bg& other);
        //
        // // Copy assignment operator.
        huge_bg& operator=(const huge_bg& other);

        void update();

    private:
        bn::regular_bg_ptr _wrapped_bg_ptr;
        bn::size _map_dimensions;
        const uint16_t *_map_data;
        const uint8_t *_tiles_data;
        bn::span<unsigned short>::iterator _map_vram;
        bn::span<bn::tile>::iterator _tiles_vram;

        int x_offset, y_offset;
        int previous_x_offset, previous_y_offset;

        bool initialized;

        explicit huge_bg(const bn::regular_bg_ptr &handle,
                         const bn::size &map_dimensions,
                         const uint16_t *map_data,
                         const uint8_t *tiles_data,
                         const bn::span<unsigned short>::iterator map_vram,
                         const bn::span<bn::tile>::iterator tiles_vram) : _wrapped_bg_ptr(handle),
                                                                          _map_dimensions(map_dimensions),
                                                                          _map_data(map_data),
                                                                          _tiles_data(tiles_data),
                                                                          _map_vram(map_vram),
                                                                          _tiles_vram(tiles_vram) {
            x_offset = y_offset = 0;
            previous_x_offset = previous_y_offset = 0;
            initialized = false;
            huge_bgs_manager::push(this);
            update();
        }
    };
}

#endif //KS_HUGE_BG_H
