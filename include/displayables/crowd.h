#ifndef KS_DISPLAYABLES_CROWD_H
#define KS_DISPLAYABLES_CROWD_H

#include "displayable_meta.h"
#include "displayable_asset.h"

namespace ks::displayables {

extern const displayable_asset crowd_asset;

constexpr inline displayable_meta crowd = {
    /* item            */ nullptr,
    /* asset           */ &crowd_asset,
    /* frame_count     */ 3,
    /* ticks_per_frame */ 18,
    /* render_w_px     */ 240,
    /* render_h_px     */ 160,
    /* seen_bitmask    */ DISPLAYABLE_BITMASK_NONE,
};

}  // namespace ks::displayables

#endif  // KS_DISPLAYABLES_CROWD_H
