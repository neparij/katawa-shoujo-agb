#ifndef KS_BGMETA_EMI_SLEEP_CRY
#define KS_BGMETA_EMI_SLEEP_CRY

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_sleep_cry.h"
#include "bn_regular_bg_items_thumb_emi_sleep_cry.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_sleep_cry(
                     bn::regular_bg_items::emi_sleep_cry,
                     bn::regular_bg_items::thumb_emi_sleep_cry,
                     DISPLAYABLE_BITMASK_EMI_SLEEP_CRY,
                     0x515384F8);

}

#endif  // KS_BGMETA_EMI_SLEEP_CRY
