#ifndef KS_BGMETA_EMI_SHED_EMI_SHOCK
#define KS_BGMETA_EMI_SHED_EMI_SHOCK

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_shed_emi_shock.h"
#include "bn_regular_bg_items_thumb_emi_shed_emi_shock.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_shed_emi_shock(
                     bn::regular_bg_items::emi_shed_emi_shock,
                     bn::regular_bg_items::thumb_emi_shed_emi_shock,
                     DISPLAYABLE_BITMASK_NONE,
                     0x04A7F033);

}

#endif  // KS_BGMETA_EMI_SHED_EMI_SHOCK
