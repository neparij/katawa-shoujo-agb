#ifndef KS_BGMETA_SCHOOL_TRACK
#define KS_BGMETA_SCHOOL_TRACK

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_track.h"
#include "bn_regular_bg_items_thumb_school_track.h"
namespace ks::background_metas {
    constexpr inline background_meta school_track(
                     bn::regular_bg_items::school_track,
                     bn::regular_bg_items::thumb_school_track,
                     DISPLAYABLE_BITMASK_NONE,
                     0x92662917);

}

#endif  // KS_BGMETA_SCHOOL_TRACK
