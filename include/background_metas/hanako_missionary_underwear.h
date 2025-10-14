#ifndef KS_BGMETA_HANAKO_MISSIONARY_UNDERWEAR
#define KS_BGMETA_HANAKO_MISSIONARY_UNDERWEAR

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_missionary_underwear.h"
#include "bn_regular_bg_items_thumb_hanako_missionary_underwear.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_missionary_underwear(
                     bn::regular_bg_items::hanako_missionary_underwear,
                     bn::regular_bg_items::thumb_hanako_missionary_underwear,
                     DISPLAYABLE_BITMASK_HANAKO_MISSIONARY_UNDERWEAR,
                     0xF70B4944);

}

#endif  // KS_BGMETA_HANAKO_MISSIONARY_UNDERWEAR
