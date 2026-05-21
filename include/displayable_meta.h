#ifndef KS_DISPLAYABLE_META_H
#define KS_DISPLAYABLE_META_H

#include "seen_bitmask.h"
#include "bn_regular_bg_item.h"

namespace ks {

struct displayable_asset;

/// Scene-layer VFX (crowd, …). Use ``asset`` for per-frame VRAM tile streaming;
/// legacy ``item`` loads the full grit tileset at once.
struct displayable_meta
{
    const bn::regular_bg_item*        item;
    const displayable_asset*          asset;
    int                               frame_count;
    int                               ticks_per_frame;
    int                               render_w_px;
    int                               render_h_px;
    displayable_bitmask_t             seen_bitmask;
};

}  // namespace ks

#endif  // KS_DISPLAYABLE_META_H
