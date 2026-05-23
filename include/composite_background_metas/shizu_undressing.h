#ifndef KS_COMPOSITES_SHIZU_UNDRESSING_H
#define KS_COMPOSITES_SHIZU_UNDRESSING_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_shizu_undressing.h"

namespace ks::composites {
extern const composite_bg_asset shizu_undressing_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta shizu_undressing_clothed_stare = {
    ks::regular_composite_bg_item(ks::composites::shizu_undressing_asset, 0),
    bn::regular_bg_items::thumb_shizu_undressing,
    DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_STARE,
    0xc44fe6b4,
};

constexpr inline composite_background_meta shizu_undressing_clothed_kiss = {
    ks::regular_composite_bg_item(ks::composites::shizu_undressing_asset, 1),
    bn::regular_bg_items::thumb_shizu_undressing,
    DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_KISS,
    0xc4c2cc63,
};

constexpr inline composite_background_meta shizu_undressing_clothed_blush = {
    ks::regular_composite_bg_item(ks::composites::shizu_undressing_asset, 2),
    bn::regular_bg_items::thumb_shizu_undressing,
    DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_BLUSH,
    0x3a073dcc,
};

constexpr inline composite_background_meta shizu_undressing_unclothed_closed = {
    ks::regular_composite_bg_item(ks::composites::shizu_undressing_asset, 3),
    bn::regular_bg_items::thumb_shizu_undressing,
    DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_CLOSED,
    0x072e261d,
};

constexpr inline composite_background_meta shizu_undressing_unclothed_blush = {
    ks::regular_composite_bg_item(ks::composites::shizu_undressing_asset, 4),
    bn::regular_bg_items::thumb_shizu_undressing,
    DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_BLUSH,
    0x6ebb3cba,
};

constexpr inline composite_background_meta shizu_undressing_unclothed_kiss = {
    ks::regular_composite_bg_item(ks::composites::shizu_undressing_asset, 5),
    bn::regular_bg_items::thumb_shizu_undressing,
    DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_KISS,
    0x1f3f9121,
};

constexpr inline composite_background_meta shizu_undressing_unclothed_talk = {
    ks::regular_composite_bg_item(ks::composites::shizu_undressing_asset, 6),
    bn::regular_bg_items::thumb_shizu_undressing,
    DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_TALK,
    0x497161b3,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_SHIZU_UNDRESSING_H
