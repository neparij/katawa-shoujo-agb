#ifndef KS_BGMETA_CITY_STREET1
#define KS_BGMETA_CITY_STREET1

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_city_street1.h"
#include "bn_regular_bg_items_thumb_city_street1.h"
namespace ks::background_metas {
    constexpr inline background_meta city_street1(
                     bn::regular_bg_items::city_street1,
                     bn::regular_bg_items::thumb_city_street1,
                     DISPLAYABLE_BITMASK_NONE,
                     0x79A595BC);

}

#endif  // KS_BGMETA_CITY_STREET1
