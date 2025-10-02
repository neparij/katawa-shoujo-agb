#ifndef KS_BGMETA_SCHOOL_TRACK_ON
#define KS_BGMETA_SCHOOL_TRACK_ON

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_track_on.h"
#include "bn_regular_bg_items_thumb_school_track_on.h"
namespace ks::background_metas {
    constexpr inline background_meta school_track_on(
                     bn::regular_bg_items::school_track_on,
                     bn::regular_bg_items::thumb_school_track_on,
                     DISPLAYABLE_BITMASK_NONE,
                     0x7D93AD36);

}

#endif  // KS_BGMETA_SCHOOL_TRACK_ON
