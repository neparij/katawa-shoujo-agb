#ifndef KS_BGMETA_HANAKO_GOODEND
#define KS_BGMETA_HANAKO_GOODEND

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_goodend.h"
#include "bn_regular_bg_items_thumb_hanako_goodend.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_goodend(
                     bn::regular_bg_items::hanako_goodend,
                     bn::regular_bg_items::thumb_hanako_goodend,
                     DISPLAYABLE_BITMASK_HANAKO_GOODEND,
                     0x21A2B6B3);

}

#endif  // KS_BGMETA_HANAKO_GOODEND
