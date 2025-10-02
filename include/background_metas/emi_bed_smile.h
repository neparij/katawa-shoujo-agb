#ifndef KS_BGMETA_EMI_BED_SMILE
#define KS_BGMETA_EMI_BED_SMILE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_bed_smile.h"
#include "bn_regular_bg_items_thumb_emi_bed_smile.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_bed_smile(
                     bn::regular_bg_items::emi_bed_smile,
                     bn::regular_bg_items::thumb_emi_bed_smile,
                     DISPLAYABLE_BITMASK_EMI_BED_SMILE,
                     0x0D3575CD);

}

#endif  // KS_BGMETA_EMI_BED_SMILE
