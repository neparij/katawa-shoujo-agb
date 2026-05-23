#ifndef KS_COMPOSITE_HUGE_RIN_WET_ARMS_H
#define KS_COMPOSITE_HUGE_RIN_WET_ARMS_H

#include "background_meta.h"
#include "composite_huge_bg_item.h"
#include "bn_regular_bg_items_thumb_rin_wet.h"

namespace ks::composites {
extern const composite_bg_asset rin_wet_arms_asset;
}

namespace ks::composite_huge_background_metas {

constexpr inline composite_huge_background_meta rin_wet_arms = {
    ks::composite_huge_bg_item(ks::composites::rin_wet_arms_asset, 0),
    bn::regular_bg_items::thumb_rin_wet,
    DISPLAYABLE_BITMASK_NONE,
    0x7fbd8c8c,
};

}  // namespace ks::composite_huge_background_metas

#endif  // KS_COMPOSITE_HUGE_RIN_WET_ARMS_H
