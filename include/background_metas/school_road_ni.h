#ifndef KS_BGMETA_SCHOOL_ROAD_NI
#define KS_BGMETA_SCHOOL_ROAD_NI

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_road_ni.h"
#include "bn_regular_bg_items_thumb_school_road_ni.h"
namespace ks::background_metas {
    constexpr inline background_meta school_road_ni(
                     bn::regular_bg_items::school_road_ni,
                     bn::regular_bg_items::thumb_school_road_ni,
                     DISPLAYABLE_BITMASK_NONE,
                     0xC61219BC);

}

#endif  // KS_BGMETA_SCHOOL_ROAD_NI
