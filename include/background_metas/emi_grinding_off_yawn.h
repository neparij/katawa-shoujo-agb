#ifndef KS_BGMETA_EMI_GRINDING_OFF_YAWN
#define KS_BGMETA_EMI_GRINDING_OFF_YAWN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_grinding_off_yawn.h"
#include "bn_regular_bg_items_thumb_emi_grinding_off_yawn.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_grinding_off_yawn(
                     bn::regular_bg_items::emi_grinding_off_yawn,
                     bn::regular_bg_items::thumb_emi_grinding_off_yawn,
                     DISPLAYABLE_BITMASK_EMI_GRINDING_OFF_YAWN,
                     0x9D9ABED8);

}

#endif  // KS_BGMETA_EMI_GRINDING_OFF_YAWN
