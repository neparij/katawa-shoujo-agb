#ifndef KS_COMPOSITE_HUGE_RIN_H2_H
#define KS_COMPOSITE_HUGE_RIN_H2_H

#include "background_meta.h"
#include "composite_huge_bg_item.h"
#include "bn_regular_bg_items_thumb_rin_h2.h"

namespace ks::composites {
extern const composite_bg_asset rin_h2_asset;
}

namespace ks::composite_huge_background_metas {

constexpr inline composite_huge_background_meta rin_h2_pan_surprise = {
    ks::composite_huge_bg_item(ks::composites::rin_h2_asset, 0),
    bn::regular_bg_items::thumb_rin_h2,
    DISPLAYABLE_BITMASK_NONE,
    0x6c60bf4a,
};

constexpr inline composite_huge_background_meta rin_h2_pan_away = {
    ks::composite_huge_bg_item(ks::composites::rin_h2_asset, 1),
    bn::regular_bg_items::thumb_rin_h2,
    DISPLAYABLE_BITMASK_NONE,
    0xcd24bd8f,
};

constexpr inline composite_huge_background_meta rin_h2_pan_closed = {
    ks::composite_huge_bg_item(ks::composites::rin_h2_asset, 2),
    bn::regular_bg_items::thumb_rin_h2,
    DISPLAYABLE_BITMASK_NONE,
    0xd9351e8a,
};

constexpr inline composite_huge_background_meta rin_h2_nopan_closed = {
    ks::composite_huge_bg_item(ks::composites::rin_h2_asset, 3),
    bn::regular_bg_items::thumb_rin_h2,
    DISPLAYABLE_BITMASK_NONE,
    0xf16a04ee,
};

constexpr inline composite_huge_background_meta rin_h2_hisao_surprise = {
    ks::composite_huge_bg_item(ks::composites::rin_h2_asset, 4),
    bn::regular_bg_items::thumb_rin_h2,
    DISPLAYABLE_BITMASK_NONE,
    0x0575de92,
};

constexpr inline composite_huge_background_meta rin_h2_hisao_away = {
    ks::composite_huge_bg_item(ks::composites::rin_h2_asset, 5),
    bn::regular_bg_items::thumb_rin_h2,
    DISPLAYABLE_BITMASK_NONE,
    0xa0104552,
};

constexpr inline composite_huge_background_meta rin_h2_hisao_closed = {
    ks::composite_huge_bg_item(ks::composites::rin_h2_asset, 6),
    bn::regular_bg_items::thumb_rin_h2,
    DISPLAYABLE_BITMASK_NONE,
    0x65d832d6,
};

}  // namespace ks::composite_huge_background_metas

#endif  // KS_COMPOSITE_HUGE_RIN_H2_H
