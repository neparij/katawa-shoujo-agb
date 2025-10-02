#ifndef KS_BGMETA_EMI_SHED_EMI_GRIN
#define KS_BGMETA_EMI_SHED_EMI_GRIN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_shed_emi_grin.h"
#include "bn_regular_bg_items_thumb_emi_shed_emi_grin.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_shed_emi_grin(
                     bn::regular_bg_items::emi_shed_emi_grin,
                     bn::regular_bg_items::thumb_emi_shed_emi_grin,
                     DISPLAYABLE_BITMASK_NONE,
                     0xB65EE4FF);

}

#endif  // KS_BGMETA_EMI_SHED_EMI_GRIN
