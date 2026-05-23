#ifndef KS_COMPOSITES_SHIZU_STRADDLE_H
#define KS_COMPOSITES_SHIZU_STRADDLE_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_shizu_straddle.h"

namespace ks::composites {
extern const composite_bg_asset shizu_straddle_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta shizu_straddle_tease = {
    ks::regular_composite_bg_item(ks::composites::shizu_straddle_asset, 0),
    bn::regular_bg_items::thumb_shizu_straddle,
    DISPLAYABLE_BITMASK_SHIZU_STRADDLE_TEASE,
    0x9666ea8a,
};

constexpr inline composite_background_meta shizu_straddle_closed = {
    ks::regular_composite_bg_item(ks::composites::shizu_straddle_asset, 1),
    bn::regular_bg_items::thumb_shizu_straddle,
    DISPLAYABLE_BITMASK_SHIZU_STRADDLE_CLOSED,
    0x50dfadcb,
};

constexpr inline composite_background_meta shizu_straddle_smile = {
    ks::regular_composite_bg_item(ks::composites::shizu_straddle_asset, 2),
    bn::regular_bg_items::thumb_shizu_straddle,
    DISPLAYABLE_BITMASK_SHIZU_STRADDLE_SMILE,
    0xb6bb09fc,
};

constexpr inline composite_background_meta shizu_straddle_come = {
    ks::regular_composite_bg_item(ks::composites::shizu_straddle_asset, 3),
    bn::regular_bg_items::thumb_shizu_straddle,
    DISPLAYABLE_BITMASK_SHIZU_STRADDLE_COME,
    0xec59d299,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_SHIZU_STRADDLE_H
