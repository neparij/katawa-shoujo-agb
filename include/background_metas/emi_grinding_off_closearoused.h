#ifndef KS_BGMETA_EMI_GRINDING_OFF_CLOSEAROUSED
#define KS_BGMETA_EMI_GRINDING_OFF_CLOSEAROUSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_grinding_off_closearoused.h"
#include "bn_regular_bg_items_thumb_emi_grinding_off_closearoused.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_grinding_off_closearoused(
                     bn::regular_bg_items::emi_grinding_off_closearoused,
                     bn::regular_bg_items::thumb_emi_grinding_off_closearoused,
                     DISPLAYABLE_BITMASK_EMI_GRINDING_OFF_CLOSEAROUSED,
                     0x8C6D0D83);

}

#endif  // KS_BGMETA_EMI_GRINDING_OFF_CLOSEAROUSED
