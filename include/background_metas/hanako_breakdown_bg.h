#ifndef KS_BGMETA_HANAKO_BREAKDOWN_BG
#define KS_BGMETA_HANAKO_BREAKDOWN_BG

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_breakdown_bg.h"
#include "bn_regular_bg_items_thumb_hanako_breakdown_bg.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_breakdown_bg(
                     bn::regular_bg_items::hanako_breakdown_bg,
                     bn::regular_bg_items::thumb_hanako_breakdown_bg,
                     DISPLAYABLE_BITMASK_NONE,
                     0xBDDDB5AB);

}

#endif  // KS_BGMETA_HANAKO_BREAKDOWN_BG
