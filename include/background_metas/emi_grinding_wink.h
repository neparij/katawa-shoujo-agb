#ifndef KS_BGMETA_EMI_GRINDING_WINK
#define KS_BGMETA_EMI_GRINDING_WINK

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_grinding_wink.h"
#include "bn_regular_bg_items_thumb_emi_grinding_wink.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_grinding_wink(
                     bn::regular_bg_items::emi_grinding_wink,
                     bn::regular_bg_items::thumb_emi_grinding_wink,
                     DISPLAYABLE_BITMASK_EMI_GRINDING_WINK,
                     0xC20E9287);

}

#endif  // KS_BGMETA_EMI_GRINDING_WINK
