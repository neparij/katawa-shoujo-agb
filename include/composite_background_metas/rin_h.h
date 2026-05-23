#ifndef KS_COMPOSITES_RIN_H_H
#define KS_COMPOSITES_RIN_H_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_rin_h.h"

namespace ks::composites {
extern const composite_bg_asset rin_h_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta rin_h_closed = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 0),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0xd0fe448d,
};

constexpr inline composite_background_meta rin_h_left = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 1),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0xb2a237fa,
};

constexpr inline composite_background_meta rin_h_normal = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 2),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0xb783fcc3,
};

constexpr inline composite_background_meta rin_h_right = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 3),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0x823e033f,
};

constexpr inline composite_background_meta rin_h_closed_close = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 4),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0x6d8c5931,
};

constexpr inline composite_background_meta rin_h_strain_close = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 5),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0x21aacb6f,
};

constexpr inline composite_background_meta rin_h_strain = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 6),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0x9dfc70b0,
};

constexpr inline composite_background_meta rin_h_normal_close = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 7),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0x6bf21be8,
};

constexpr inline composite_background_meta rin_h_right_close = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 8),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0x2713a330,
};

constexpr inline composite_background_meta rin_h_left_close = {
    ks::regular_composite_bg_item(ks::composites::rin_h_asset, 9),
    bn::regular_bg_items::thumb_rin_h,
    DISPLAYABLE_BITMASK_NONE,
    0xbe664bfd,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_RIN_H_H
