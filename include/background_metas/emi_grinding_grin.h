#ifndef KS_BGMETA_EMI_GRINDING_GRIN
#define KS_BGMETA_EMI_GRINDING_GRIN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_grinding_grin.h"
#include "bn_regular_bg_items_thumb_emi_grinding_grin.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_grinding_grin(
                     bn::regular_bg_items::emi_grinding_grin,
                     bn::regular_bg_items::thumb_emi_grinding_grin,
                     DISPLAYABLE_BITMASK_EMI_GRINDING_GRIN,
                     0x457C3082);

}

#endif  // KS_BGMETA_EMI_GRINDING_GRIN
