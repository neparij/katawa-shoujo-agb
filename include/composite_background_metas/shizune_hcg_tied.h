#ifndef KS_COMPOSITES_SHIZUNE_HCG_TIED_H
#define KS_COMPOSITES_SHIZUNE_HCG_TIED_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_shizune_tied.h"

namespace ks::composites {
extern const composite_bg_asset shizune_hcg_tied_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta shizune_hcg_tied_smile = {
    ks::regular_composite_bg_item(ks::composites::shizune_hcg_tied_asset, 0),
    bn::regular_bg_items::thumb_shizune_tied,
    DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_SMILE,
    0xea7da516,
};

constexpr inline composite_background_meta shizune_hcg_tied_blush = {
    ks::regular_composite_bg_item(ks::composites::shizune_hcg_tied_asset, 1),
    bn::regular_bg_items::thumb_shizune_tied,
    DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_BLUSH,
    0xb5d68a89,
};

constexpr inline composite_background_meta shizune_hcg_tied_blush_hisao2 = {
    ks::regular_composite_bg_item(ks::composites::shizune_hcg_tied_asset, 2),
    bn::regular_bg_items::thumb_shizune_tied,
    DISPLAYABLE_BITMASK_NONE,
    0x79997e98,
};

constexpr inline composite_background_meta shizune_hcg_tied_stare = {
    ks::regular_composite_bg_item(ks::composites::shizune_hcg_tied_asset, 3),
    bn::regular_bg_items::thumb_shizune_tied,
    DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_STARE,
    0x9d02a3de,
};

constexpr inline composite_background_meta shizune_hcg_tied_close_hisao2 = {
    ks::regular_composite_bg_item(ks::composites::shizune_hcg_tied_asset, 4),
    bn::regular_bg_items::thumb_shizune_tied,
    DISPLAYABLE_BITMASK_NONE,
    0x2ee9aac0,
};

constexpr inline composite_background_meta shizune_hcg_tied_kinky3 = {
    ks::regular_composite_bg_item(ks::composites::shizune_hcg_tied_asset, 5),
    bn::regular_bg_items::thumb_shizune_tied,
    DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_KINKY3,
    0xcaaa6f67,
};

constexpr inline composite_background_meta shizune_hcg_tied_kinky2 = {
    ks::regular_composite_bg_item(ks::composites::shizune_hcg_tied_asset, 6),
    bn::regular_bg_items::thumb_shizune_tied,
    DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_KINKY2,
    0x0e394c83,
};

constexpr inline composite_background_meta shizune_hcg_tied_close = {
    ks::regular_composite_bg_item(ks::composites::shizune_hcg_tied_asset, 7),
    bn::regular_bg_items::thumb_shizune_tied,
    DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_CLOSE,
    0xb0780a17,
};

constexpr inline composite_background_meta shizune_hcg_tied_kinky1_hisao2 = {
    ks::regular_composite_bg_item(ks::composites::shizune_hcg_tied_asset, 8),
    bn::regular_bg_items::thumb_shizune_tied,
    DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_KINKY1,
    0xec815210,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_SHIZUNE_HCG_TIED_H
