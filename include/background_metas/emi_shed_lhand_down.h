#ifndef KS_BGMETA_EMI_SHED_LHAND_DOWN
#define KS_BGMETA_EMI_SHED_LHAND_DOWN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_shed_lhand_down.h"
#include "bn_regular_bg_items_thumb_emi_shed_lhand_down.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_shed_lhand_down(
                     bn::regular_bg_items::emi_shed_lhand_down,
                     bn::regular_bg_items::thumb_emi_shed_lhand_down,
                     DISPLAYABLE_BITMASK_NONE,
                     0xED86234E);

}

#endif  // KS_BGMETA_EMI_SHED_LHAND_DOWN
