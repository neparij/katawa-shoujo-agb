#ifndef KS_BGMETA_HANAKO_BREAKDOWN_UP
#define KS_BGMETA_HANAKO_BREAKDOWN_UP

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_breakdown_up.h"
#include "bn_regular_bg_items_thumb_hanako_breakdown_up.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_breakdown_up(
                     bn::regular_bg_items::hanako_breakdown_up,
                     bn::regular_bg_items::thumb_hanako_breakdown_up,
                     DISPLAYABLE_BITMASK_HANAKO_BREAKDOWN_UP,
                     0xE9714B93);

}

#endif  // KS_BGMETA_HANAKO_BREAKDOWN_UP
