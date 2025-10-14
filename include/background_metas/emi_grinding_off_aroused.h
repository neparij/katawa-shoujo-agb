#ifndef KS_BGMETA_EMI_GRINDING_OFF_AROUSED
#define KS_BGMETA_EMI_GRINDING_OFF_AROUSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_grinding_off_aroused.h"
#include "bn_regular_bg_items_thumb_emi_grinding_off_aroused.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_grinding_off_aroused(
                     bn::regular_bg_items::emi_grinding_off_aroused,
                     bn::regular_bg_items::thumb_emi_grinding_off_aroused,
                     DISPLAYABLE_BITMASK_EMI_GRINDING_OFF_AROUSED,
                     0x6BC4B340);

}

#endif  // KS_BGMETA_EMI_GRINDING_OFF_AROUSED
