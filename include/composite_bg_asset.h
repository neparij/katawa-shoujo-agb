#ifndef KS_COMPOSITE_BG_ASSET_H
#define KS_COMPOSITE_BG_ASSET_H

/**
 * ROM layout for composite / multi-variant backgrounds.
 *
 * All variants share one qualetize palette and one deduplicated tileset in
 * ROM. At runtime only the current variant's `used_tiles[]` are streamed
 * into a VRAM pool sized to `max_vram_tiles`.
 *
 * Map dimensions are independent of 240×160 — must be at least 256×256 px
 * (32×32 cells, Butano regular_bg minimum) and at most 256×256.
 */

#include <cstdint>

#include "bn_bg_palette_item.h"
#include "bn_regular_bg_tiles_item.h"

namespace ks {

struct composite_tileset
{
    const bn::regular_bg_tiles_item* const* slabs;
    int                                     slab_count;
};

struct composite_variant
{
    /// Global ROM tile indices (`slab << 10 | local`). Slot 0 = transparent.
    const uint16_t*       used_tiles;
    int                   used_count;
    /// BIOS RLE of 16-bit regular_bg_map_cell values (palette bank included).
    const unsigned char*  map_compressed;
};

struct composite_bg_asset
{
    const composite_tileset*   tileset;
    const bn::bg_palette_item* palette;
    const composite_variant*   variants;
    int                        variant_count;
    /// Max `used_count` across variants — VRAM pool allocation size.
    int                        max_vram_tiles;
    /// Logical map size in pixels (multiple of 8, ≤ 256 regular / ≤ 512 huge).
    int                        map_w_px;
    int                        map_h_px;
    /// When true, use composite huge scrolling path (512×512 map).
    bool                       huge;
};

}  // namespace ks

#endif  // KS_COMPOSITE_BG_ASSET_H
