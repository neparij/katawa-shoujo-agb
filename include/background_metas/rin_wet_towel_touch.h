#ifndef KS_BGMETA_RIN_WET_TOWEL_TOUCH
#define KS_BGMETA_RIN_WET_TOWEL_TOUCH

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_wet_towel_touch.h"
#include "bn_regular_bg_items_thumb_rin_wet_towel_touch.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_wet_towel_touch(
                     bn::regular_bg_items::rin_wet_towel_touch,
                     bn::regular_bg_items::thumb_rin_wet_towel_touch,
                     DISPLAYABLE_BITMASK_RIN_WET_TOWEL_TOUCH,
                     0xC861606F);

}

#endif  // KS_BGMETA_RIN_WET_TOWEL_TOUCH
