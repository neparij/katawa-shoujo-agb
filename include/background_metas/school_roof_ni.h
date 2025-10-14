#ifndef KS_BGMETA_SCHOOL_ROOF_NI
#define KS_BGMETA_SCHOOL_ROOF_NI

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_roof_ni.h"
#include "bn_regular_bg_items_thumb_school_roof_ni.h"
namespace ks::background_metas {
    constexpr inline background_meta school_roof_ni(
                     bn::regular_bg_items::school_roof_ni,
                     bn::regular_bg_items::thumb_school_roof_ni,
                     DISPLAYABLE_BITMASK_NONE,
                     0x3BF14FE2);

}

#endif  // KS_BGMETA_SCHOOL_ROOF_NI
