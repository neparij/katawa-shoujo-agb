#ifndef KS_BGMETA_SCHOOL_PARKINGLOT
#define KS_BGMETA_SCHOOL_PARKINGLOT

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_parkinglot.h"
#include "bn_regular_bg_items_thumb_school_parkinglot.h"
namespace ks::background_metas {
    constexpr inline background_meta school_parkinglot(
                     bn::regular_bg_items::school_parkinglot,
                     bn::regular_bg_items::thumb_school_parkinglot,
                     DISPLAYABLE_BITMASK_NONE,
                     0xA5181EDB);

}

#endif  // KS_BGMETA_SCHOOL_PARKINGLOT
