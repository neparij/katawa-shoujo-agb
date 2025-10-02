#ifndef KS_BGMETA_EMI_SHED_RHAND_UP
#define KS_BGMETA_EMI_SHED_RHAND_UP

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_shed_rhand_up.h"
#include "bn_regular_bg_items_thumb_emi_shed_rhand_up.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_shed_rhand_up(
                     bn::regular_bg_items::emi_shed_rhand_up,
                     bn::regular_bg_items::thumb_emi_shed_rhand_up,
                     DISPLAYABLE_BITMASK_NONE,
                     0xC7644AC7);

}

#endif  // KS_BGMETA_EMI_SHED_RHAND_UP
