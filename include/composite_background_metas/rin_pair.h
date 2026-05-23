#ifndef KS_COMPOSITES_RIN_PAIR_H
#define KS_COMPOSITES_RIN_PAIR_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_rin_pair.h"

namespace ks::composites {
extern const composite_bg_asset rin_pair_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta rin_pair_c_hn_rn = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 0),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0x0a6b4e80,
};

constexpr inline composite_background_meta rin_pair_c_hf_rn = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 1),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0x45bd3726,
};

constexpr inline composite_background_meta rin_pair_c_hf_rt = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 2),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0xe0d94c23,
};

constexpr inline composite_background_meta rin_pair_c_hs_rt = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 3),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0x6fc9b0b2,
};

constexpr inline composite_background_meta rin_pair_c_hs_rs = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 4),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0xa7c033cc,
};

constexpr inline composite_background_meta rin_pair_c_hs_rf = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 5),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0x4f9d84eb,
};

constexpr inline composite_background_meta rin_pair_c_hn_rf = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 6),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0x6a0fc25f,
};

constexpr inline composite_background_meta rin_pair_n_hn_rn = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 7),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0x92c4c567,
};

constexpr inline composite_background_meta rin_pair_n_hn_rc = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 8),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0xa1aa2511,
};

constexpr inline composite_background_meta rin_pair_n_hf_rc = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 9),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0xcaeed655,
};

constexpr inline composite_background_meta rin_pair_n_hf_rt = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 10),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0xc2cbd9bb,
};

constexpr inline composite_background_meta rin_pair_n_hn_rt = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 11),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0x8b38939b,
};

constexpr inline composite_background_meta rin_pair_n_hn_rs = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 12),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0x956b789d,
};

constexpr inline composite_background_meta rin_pair_n_hf_rs = {
    ks::regular_composite_bg_item(ks::composites::rin_pair_asset, 13),
    bn::regular_bg_items::thumb_rin_pair,
    DISPLAYABLE_BITMASK_NONE,
    0x48b260d5,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_RIN_PAIR_H
