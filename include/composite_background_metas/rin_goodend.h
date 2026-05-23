#ifndef KS_COMPOSITES_RIN_GOODEND_H
#define KS_COMPOSITES_RIN_GOODEND_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_rin_goodend.h"

namespace ks::composites {
extern const composite_bg_asset rin_goodend_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta rin_goodend_1 = {
    ks::regular_composite_bg_item(ks::composites::rin_goodend_asset, 0),
    bn::regular_bg_items::thumb_rin_goodend,
    DISPLAYABLE_BITMASK_NONE,
    0x8ab58058,
};

constexpr inline composite_background_meta rin_goodend_1b = {
    ks::regular_composite_bg_item(ks::composites::rin_goodend_asset, 1),
    bn::regular_bg_items::thumb_rin_goodend,
    DISPLAYABLE_BITMASK_NONE,
    0x6dfb6768,
};

constexpr inline composite_background_meta rin_goodend_2 = {
    ks::regular_composite_bg_item(ks::composites::rin_goodend_asset, 2),
    bn::regular_bg_items::thumb_rin_goodend,
    DISPLAYABLE_BITMASK_NONE,
    0x222fa88a,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_RIN_GOODEND_H
