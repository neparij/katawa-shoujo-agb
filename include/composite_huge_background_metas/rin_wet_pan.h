#ifndef KS_COMPOSITE_HUGE_RIN_WET_PAN_H
#define KS_COMPOSITE_HUGE_RIN_WET_PAN_H

#include "background_meta.h"
#include "composite_huge_bg_item.h"
#include "bn_regular_bg_items_thumb_rin_wet.h"

namespace ks::composites {
extern const composite_bg_asset rin_wet_pan_asset;
}

namespace ks::composite_huge_background_metas {

constexpr inline composite_huge_background_meta rin_wet_pan_down = {
    ks::composite_huge_bg_item(ks::composites::rin_wet_pan_asset, 0),
    bn::regular_bg_items::thumb_rin_wet,
    DISPLAYABLE_BITMASK_NONE,
    0x101e4a44,
};

}  // namespace ks::composite_huge_background_metas

#endif  // KS_COMPOSITE_HUGE_RIN_WET_PAN_H
