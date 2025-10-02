#ifndef KS_BGMETA_SCHOOL_CLASSROOMART
#define KS_BGMETA_SCHOOL_CLASSROOMART

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_classroomart.h"
#include "bn_regular_bg_items_thumb_school_classroomart.h"
namespace ks::background_metas {
    constexpr inline background_meta school_classroomart(
                     bn::regular_bg_items::school_classroomart,
                     bn::regular_bg_items::thumb_school_classroomart,
                     DISPLAYABLE_BITMASK_NONE,
                     0x96987A2A);

}

#endif  // KS_BGMETA_SCHOOL_CLASSROOMART
