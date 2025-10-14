#ifndef KS_BGMETA_HANAKO_BREAKDOWN_DOWN
#define KS_BGMETA_HANAKO_BREAKDOWN_DOWN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_breakdown_down.h"
#include "bn_regular_bg_items_thumb_hanako_breakdown_down.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_breakdown_down(
                     bn::regular_bg_items::hanako_breakdown_down,
                     bn::regular_bg_items::thumb_hanako_breakdown_down,
                     DISPLAYABLE_BITMASK_NONE,
                     0xABF77E72);

}

#endif  // KS_BGMETA_HANAKO_BREAKDOWN_DOWN
