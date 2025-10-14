#ifndef KS_BGMETA_SCHOOL_ROOM32
#define KS_BGMETA_SCHOOL_ROOM32

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_room32.h"
#include "bn_regular_bg_items_thumb_school_room32.h"
namespace ks::background_metas {
    constexpr inline background_meta school_room32(
                     bn::regular_bg_items::school_room32,
                     bn::regular_bg_items::thumb_school_room32,
                     DISPLAYABLE_BITMASK_NONE,
                     0x2442302D);

}

#endif  // KS_BGMETA_SCHOOL_ROOM32
