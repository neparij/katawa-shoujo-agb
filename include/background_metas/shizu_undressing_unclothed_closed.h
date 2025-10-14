#ifndef KS_BGMETA_SHIZU_UNDRESSING_UNCLOTHED_CLOSED
#define KS_BGMETA_SHIZU_UNDRESSING_UNCLOTHED_CLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_undressing_unclothed_closed.h"
#include "bn_regular_bg_items_thumb_shizu_undressing_unclothed_closed.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_undressing_unclothed_closed(
                     bn::regular_bg_items::shizu_undressing_unclothed_closed,
                     bn::regular_bg_items::thumb_shizu_undressing_unclothed_closed,
                     DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_CLOSED,
                     0x072E261D);

}

#endif  // KS_BGMETA_SHIZU_UNDRESSING_UNCLOTHED_CLOSED
