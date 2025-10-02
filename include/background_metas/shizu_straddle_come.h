#ifndef KS_BGMETA_SHIZU_STRADDLE_COME
#define KS_BGMETA_SHIZU_STRADDLE_COME

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_straddle_come.h"
#include "bn_regular_bg_items_thumb_shizu_straddle_come.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_straddle_come(
                     bn::regular_bg_items::shizu_straddle_come,
                     bn::regular_bg_items::thumb_shizu_straddle_come,
                     DISPLAYABLE_BITMASK_SHIZU_STRADDLE_COME,
                     0xEC59D299);

}

#endif  // KS_BGMETA_SHIZU_STRADDLE_COME
