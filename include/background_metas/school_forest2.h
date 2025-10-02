#ifndef KS_BGMETA_SCHOOL_FOREST2
#define KS_BGMETA_SCHOOL_FOREST2

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_forest2.h"
#include "bn_regular_bg_items_thumb_school_forest2.h"
namespace ks::background_metas {
    constexpr inline background_meta school_forest2(
                     bn::regular_bg_items::school_forest2,
                     bn::regular_bg_items::thumb_school_forest2,
                     DISPLAYABLE_BITMASK_NONE,
                     0x41B60CD3);

}

#endif  // KS_BGMETA_SCHOOL_FOREST2
