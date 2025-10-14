#ifndef KS_BGMETA_EMI_BED_LEGS
#define KS_BGMETA_EMI_BED_LEGS

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_bed_legs.h"
#include "bn_regular_bg_items_thumb_emi_bed_legs.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_bed_legs(
                     bn::regular_bg_items::emi_bed_legs,
                     bn::regular_bg_items::thumb_emi_bed_legs,
                     DISPLAYABLE_BITMASK_NONE,
                     0xB21B7779);

}

#endif  // KS_BGMETA_EMI_BED_LEGS
