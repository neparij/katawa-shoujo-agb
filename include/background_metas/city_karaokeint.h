#ifndef KS_BGMETA_CITY_KARAOKEINT
#define KS_BGMETA_CITY_KARAOKEINT

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_city_karaokeint.h"
#include "bn_regular_bg_items_thumb_city_karaokeint.h"
namespace ks::background_metas {
    constexpr inline background_meta city_karaokeint(
                     bn::regular_bg_items::city_karaokeint,
                     bn::regular_bg_items::thumb_city_karaokeint,
                     DISPLAYABLE_BITMASK_NONE,
                     0x5E43C6D1);

}

#endif  // KS_BGMETA_CITY_KARAOKEINT
