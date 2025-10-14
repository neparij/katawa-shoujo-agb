#ifndef KS_BGMETA_HANAKO_PARK_LOOK
#define KS_BGMETA_HANAKO_PARK_LOOK

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_park_look.h"
#include "bn_regular_bg_items_thumb_hanako_park_look.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_park_look(
                     bn::regular_bg_items::hanako_park_look,
                     bn::regular_bg_items::thumb_hanako_park_look,
                     DISPLAYABLE_BITMASK_HANAKO_PARK_LOOK,
                     0xFFA32A75);

}

#endif  // KS_BGMETA_HANAKO_PARK_LOOK
