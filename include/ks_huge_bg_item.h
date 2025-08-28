/**
* -----------------------------------------------------------------------------
 *  File: ks_huge_bg_item.h
 *  Description: Header file for the huge background item
 *  Author: neparij (Nikolai Laptev)
 *  Project: Katawa Shoujo - Game Boy Advance
 *  License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International
 *  Creation Date: 2025-05-29
 * -----------------------------------------------------------------------------
 */

#ifndef KS_HUGE_BG_ITEM_H
#define KS_HUGE_BG_ITEM_H
#include <cstdint>

#include "bn_bg_palette_item.h"
#include "bn_bpp_mode.h"
#include "bn_color.h"
#include "bn_fixed.h"
#include "bn_size.h"
#include "bn_span.h"
#include "ks_huge_bg.h"

namespace ks {
    class huge_bg_item {
    public:
        constexpr huge_bg_item(const uint8_t* tiles_ptr,
                               const uint16_t* map_cells_ptr,
                               const bn::bg_palette_item& palette_item,
                               const bn::size &map_dimensions) : _tiles_ptr(tiles_ptr),
                                                   _map_cells_ptr(map_cells_ptr),
                                                   _palette_item(palette_item),
                                                   _map_dimensions(map_dimensions) {
        }

        [[nodiscard]] huge_bg create_bg() const;

        [[nodiscard]] huge_bg create_bg(bn::fixed x, bn::fixed y) const;

        [[nodiscard]] const uint8_t* tiles_ref() const
        {
            return _tiles_ptr;
        }

        [[nodiscard]] const uint16_t* cells_ref() const
        {
            return _map_cells_ptr;
        }

        [[nodiscard]] constexpr const bn::bg_palette_item& palette_item() const
        {
            return _palette_item;
        }

        [[nodiscard]] constexpr const bn::size& map_dimensions() const
        {
            return _map_dimensions;
        }

        bool operator==(const huge_bg_item& other) const {
            return _tiles_ptr == other._tiles_ptr &&
                   _map_cells_ptr == other._map_cells_ptr &&
                   _palette_item == other._palette_item &&
                   _map_dimensions == other._map_dimensions;
        }

        bool operator!=(const huge_bg_item& other) const {
            return !(*this == other);
    }

    private:
        const uint8_t* _tiles_ptr;
        const uint16_t* _map_cells_ptr;
        bn::bg_palette_item _palette_item;
        bn::size _map_dimensions;
    };

}

#endif //KS_HUGE_BG_ITEM_H
