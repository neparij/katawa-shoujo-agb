#ifndef KS_BGMETA_SCHOOL_ROOF
#define KS_BGMETA_SCHOOL_ROOF

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_roof.h"
#include "bn_regular_bg_items_thumb_school_roof.h"
namespace ks::background_metas {
    constexpr inline background_meta school_roof(
                     bn::regular_bg_items::school_roof,
                     bn::regular_bg_items::thumb_school_roof,
                     DISPLAYABLE_BITMASK_NONE,
                     0xA71A283E);

}

#endif  // KS_BGMETA_SCHOOL_ROOF
