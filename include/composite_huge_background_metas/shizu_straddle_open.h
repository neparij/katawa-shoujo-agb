#ifndef KS_COMPOSITE_HUGE_SHIZU_STRADDLE_OPEN_H
#define KS_COMPOSITE_HUGE_SHIZU_STRADDLE_OPEN_H

#include "background_meta.h"
#include "composite_huge_bg_item.h"
#include "bn_regular_bg_items_thumb_shizu_straddle.h"

namespace ks::composites {
extern const composite_bg_asset shizu_straddle_open_asset;
}

namespace ks::composite_huge_background_metas {

constexpr inline composite_huge_background_meta shizu_straddle_open = {
    ks::composite_huge_bg_item(ks::composites::shizu_straddle_open_asset, 0),
    bn::regular_bg_items::thumb_shizu_straddle,
    DISPLAYABLE_BITMASK_SHIZU_STRADDLE_OPEN,
    0x609e25bc,
};

}  // namespace ks::composite_huge_background_metas

#endif  // KS_COMPOSITE_HUGE_SHIZU_STRADDLE_OPEN_H
