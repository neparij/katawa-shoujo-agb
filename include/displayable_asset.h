#ifndef KS_DISPLAYABLE_ASSET_H
#define KS_DISPLAYABLE_ASSET_H

/**
 * Scene displayable ROM layout for per-frame VRAM tile streaming.
 *
 * The converter stores all unique 8×8 tiles in ROM (`regular_bg_tiles` slabs).
 * At runtime only the tiles referenced by the *current* animation frame are
 * copied into a VRAM pool sized to `max_vram_tiles` (the maximum per-frame
 * unique count across all frames).
 */

#include <cstdint>

#include "bn_regular_bg_tiles_item.h"

namespace ks {

struct displayable_tileset
{
    const bn::regular_bg_tiles_item* const* slabs;
    int                                     slab_count;
};

struct displayable_frame
{
    /// Global ROM tile indices (`slab << 10 | local`), slot 0 = transparent.
    const uint16_t*       used_tiles;
    int                   used_count;
    /// BIOS RLE map (32×32 cells, local tile ids 0..used_count-1).
    const unsigned char*  map_compressed;
};

struct displayable_asset
{
    const displayable_tileset*  tileset;
    const displayable_frame*    frames;
    int                         frame_count;
    /// Max `used_count` over all frames — VRAM pool allocation size.
    int                         max_vram_tiles;
    int                         render_w_px;
    int                         render_h_px;
};

}  // namespace ks

#endif  // KS_DISPLAYABLE_ASSET_H
