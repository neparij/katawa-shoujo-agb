#ifndef KS_BGMETA_SCHOOL_ROOF_BLURRED
#define KS_BGMETA_SCHOOL_ROOF_BLURRED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_roof_blurred.h"
#include "bn_regular_bg_items_thumb_school_roof_blurred.h"
namespace ks::background_metas {
    constexpr inline background_meta school_roof_blurred(
                     bn::regular_bg_items::school_roof_blurred,
                     bn::regular_bg_items::thumb_school_roof_blurred,
                     DISPLAYABLE_BITMASK_NONE,
                     0x8C5BC60E);

}

#endif  // KS_BGMETA_SCHOOL_ROOF_BLURRED
