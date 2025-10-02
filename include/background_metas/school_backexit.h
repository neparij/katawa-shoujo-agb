#ifndef KS_BGMETA_SCHOOL_BACKEXIT
#define KS_BGMETA_SCHOOL_BACKEXIT

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_backexit.h"
#include "bn_regular_bg_items_thumb_school_backexit.h"
namespace ks::background_metas {
    constexpr inline background_meta school_backexit(
                     bn::regular_bg_items::school_backexit,
                     bn::regular_bg_items::thumb_school_backexit,
                     DISPLAYABLE_BITMASK_NONE,
                     0xA7C5C0B7);

}

#endif  // KS_BGMETA_SCHOOL_BACKEXIT
