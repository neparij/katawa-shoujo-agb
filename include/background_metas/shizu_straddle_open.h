#ifndef KS_BGMETA_SHIZU_STRADDLE_OPEN
#define KS_BGMETA_SHIZU_STRADDLE_OPEN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_straddle_open.h"
#include "bn_regular_bg_items_thumb_shizu_straddle_open.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_straddle_open(
                     bn::regular_bg_items::shizu_straddle_open,
                     bn::regular_bg_items::thumb_shizu_straddle_open,
                     DISPLAYABLE_BITMASK_SHIZU_STRADDLE_OPEN,
                     0x609E25BC);

}

#endif  // KS_BGMETA_SHIZU_STRADDLE_OPEN
