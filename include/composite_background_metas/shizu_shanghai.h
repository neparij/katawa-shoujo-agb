#ifndef KS_COMPOSITES_SHIZU_SHANGHAI_H
#define KS_COMPOSITES_SHIZU_SHANGHAI_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_shizu_shanghai.h"

namespace ks::composites {
extern const composite_bg_asset shizu_shanghai_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta shizu_shanghai_default = {
    ks::regular_composite_bg_item(ks::composites::shizu_shanghai_asset, 0),
    bn::regular_bg_items::thumb_shizu_shanghai,
    DISPLAYABLE_BITMASK_SHIZU_SHANGHAI,
    0x9425ac62,
};

constexpr inline composite_background_meta shizu_shanghai_boredlaugh = {
    ks::regular_composite_bg_item(ks::composites::shizu_shanghai_asset, 1),
    bn::regular_bg_items::thumb_shizu_shanghai,
    DISPLAYABLE_BITMASK_NONE,
    0x8e491684,
};

constexpr inline composite_background_meta shizu_shanghai_borednormal = {
    ks::regular_composite_bg_item(ks::composites::shizu_shanghai_asset, 2),
    bn::regular_bg_items::thumb_shizu_shanghai,
    DISPLAYABLE_BITMASK_SHIZU_SHANGHAI_BOREDNORMAL,
    0xa2abb1b8,
};

constexpr inline composite_background_meta shizu_shanghai_normallaugh = {
    ks::regular_composite_bg_item(ks::composites::shizu_shanghai_asset, 3),
    bn::regular_bg_items::thumb_shizu_shanghai,
    DISPLAYABLE_BITMASK_NONE,
    0xe24226ca,
};

constexpr inline composite_background_meta shizu_shanghai_smirklaugh = {
    ks::regular_composite_bg_item(ks::composites::shizu_shanghai_asset, 4),
    bn::regular_bg_items::thumb_shizu_shanghai,
    DISPLAYABLE_BITMASK_SHIZU_SHANGHAI_SMIRKLAUGH,
    0xe49e0b6c,
};

constexpr inline composite_background_meta shizu_shanghai_smirknormal = {
    ks::regular_composite_bg_item(ks::composites::shizu_shanghai_asset, 5),
    bn::regular_bg_items::thumb_shizu_shanghai,
    DISPLAYABLE_BITMASK_SHIZU_SHANGHAI_SMIRKNORMAL,
    0x0cfebe5e,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_SHIZU_SHANGHAI_H
