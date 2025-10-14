#ifndef KS_BGMETA_CITY_ALLEY
#define KS_BGMETA_CITY_ALLEY

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_city_alley.h"
#include "bn_regular_bg_items_thumb_city_alley.h"
namespace ks::background_metas {
    constexpr inline background_meta city_alley(
                     bn::regular_bg_items::city_alley,
                     bn::regular_bg_items::thumb_city_alley,
                     DISPLAYABLE_BITMASK_NONE,
                     0xEF10B3D4);

}

#endif  // KS_BGMETA_CITY_ALLEY
