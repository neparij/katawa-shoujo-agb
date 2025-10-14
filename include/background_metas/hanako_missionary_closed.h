#ifndef KS_BGMETA_HANAKO_MISSIONARY_CLOSED
#define KS_BGMETA_HANAKO_MISSIONARY_CLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_missionary_closed.h"
#include "bn_regular_bg_items_thumb_hanako_missionary_closed.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_missionary_closed(
                     bn::regular_bg_items::hanako_missionary_closed,
                     bn::regular_bg_items::thumb_hanako_missionary_closed,
                     DISPLAYABLE_BITMASK_HANAKO_MISSIONARY_CLOSED,
                     0x352CCD1E);

}

#endif  // KS_BGMETA_HANAKO_MISSIONARY_CLOSED
