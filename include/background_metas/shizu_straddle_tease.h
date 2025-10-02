#ifndef KS_BGMETA_SHIZU_STRADDLE_TEASE
#define KS_BGMETA_SHIZU_STRADDLE_TEASE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_straddle_tease.h"
#include "bn_regular_bg_items_thumb_shizu_straddle_tease.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_straddle_tease(
                     bn::regular_bg_items::shizu_straddle_tease,
                     bn::regular_bg_items::thumb_shizu_straddle_tease,
                     DISPLAYABLE_BITMASK_SHIZU_STRADDLE_TEASE,
                     0x9666EA8A);

}

#endif  // KS_BGMETA_SHIZU_STRADDLE_TEASE
