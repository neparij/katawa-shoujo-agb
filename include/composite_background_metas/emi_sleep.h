#ifndef KS_COMPOSITES_EMI_SLEEP_H
#define KS_COMPOSITES_EMI_SLEEP_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_emi_sleep.h"

namespace ks::composites {
extern const composite_bg_asset emi_sleep_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta emi_sleep_normal = {
    ks::regular_composite_bg_item(ks::composites::emi_sleep_asset, 0),
    bn::regular_bg_items::thumb_emi_sleep,
    DISPLAYABLE_BITMASK_EMI_SLEEP_NORMAL,
    0x4d12722b,
};

constexpr inline composite_background_meta emi_sleep_unsure = {
    ks::regular_composite_bg_item(ks::composites::emi_sleep_asset, 1),
    bn::regular_bg_items::thumb_emi_sleep,
    DISPLAYABLE_BITMASK_EMI_SLEEP_UNSURE,
    0x09b2ddb8,
};

constexpr inline composite_background_meta emi_sleep_weep = {
    ks::regular_composite_bg_item(ks::composites::emi_sleep_asset, 2),
    bn::regular_bg_items::thumb_emi_sleep,
    DISPLAYABLE_BITMASK_EMI_SLEEP_WEEP,
    0xd9bd6ef2,
};

constexpr inline composite_background_meta emi_sleep_cry = {
    ks::regular_composite_bg_item(ks::composites::emi_sleep_asset, 3),
    bn::regular_bg_items::thumb_emi_sleep,
    DISPLAYABLE_BITMASK_EMI_SLEEP_CRY,
    0x515384f8,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_EMI_SLEEP_H
