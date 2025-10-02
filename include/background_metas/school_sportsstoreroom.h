#ifndef KS_BGMETA_SCHOOL_SPORTSSTOREROOM
#define KS_BGMETA_SCHOOL_SPORTSSTOREROOM

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_sportsstoreroom.h"
#include "bn_regular_bg_items_thumb_school_sportsstoreroom.h"
namespace ks::background_metas {
    constexpr inline background_meta school_sportsstoreroom(
                     bn::regular_bg_items::school_sportsstoreroom,
                     bn::regular_bg_items::thumb_school_sportsstoreroom,
                     DISPLAYABLE_BITMASK_NONE,
                     0xF3E01172);

}

#endif  // KS_BGMETA_SCHOOL_SPORTSSTOREROOM
