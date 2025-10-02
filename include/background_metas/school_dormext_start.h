#ifndef KS_BGMETA_SCHOOL_DORMEXT_START
#define KS_BGMETA_SCHOOL_DORMEXT_START

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_dormext_start.h"
#include "bn_regular_bg_items_thumb_school_dormext_start.h"
namespace ks::background_metas {
    constexpr inline background_meta school_dormext_start(
                     bn::regular_bg_items::school_dormext_start,
                     bn::regular_bg_items::thumb_school_dormext_start,
                     DISPLAYABLE_BITMASK_NONE,
                     0x063B3D23);

}

#endif  // KS_BGMETA_SCHOOL_DORMEXT_START
