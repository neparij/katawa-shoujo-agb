#ifndef KS_BGMETA_EVENT_MISSING
#define KS_BGMETA_EVENT_MISSING

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_event_missing.h"
#include "bn_regular_bg_items_thumb_event_missing.h"
namespace ks::background_metas {
    constexpr inline background_meta event_missing(
                     bn::regular_bg_items::event_missing,
                     bn::regular_bg_items::thumb_event_missing,
                     DISPLAYABLE_BITMASK_NONE,
                     0xBE6EDDE7);

}

#endif  // KS_BGMETA_EVENT_MISSING
