#ifndef KS_BGMETA_RIN_ROOF_DISGUST
#define KS_BGMETA_RIN_ROOF_DISGUST

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_roof_disgust.h"
#include "bn_regular_bg_items_thumb_rin_roof_disgust.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_roof_disgust(
                     bn::regular_bg_items::rin_roof_disgust,
                     bn::regular_bg_items::thumb_rin_roof_disgust,
                     DISPLAYABLE_BITMASK_NONE,
                     0x0D7EB224);

}

#endif  // KS_BGMETA_RIN_ROOF_DISGUST
