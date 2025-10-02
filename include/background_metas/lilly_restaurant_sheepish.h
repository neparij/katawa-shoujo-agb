#ifndef KS_BGMETA_LILLY_RESTAURANT_SHEEPISH
#define KS_BGMETA_LILLY_RESTAURANT_SHEEPISH

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_restaurant_sheepish.h"
#include "bn_regular_bg_items_thumb_lilly_restaurant_sheepish.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_restaurant_sheepish(
                     bn::regular_bg_items::lilly_restaurant_sheepish,
                     bn::regular_bg_items::thumb_lilly_restaurant_sheepish,
                     DISPLAYABLE_BITMASK_LILLY_RESTAURANT_SHEEPISH,
                     0x64E71B29);

}

#endif  // KS_BGMETA_LILLY_RESTAURANT_SHEEPISH
