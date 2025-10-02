#ifndef KS_BGMETA_HOK_WHEAT
#define KS_BGMETA_HOK_WHEAT

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hok_wheat.h"
#include "bn_regular_bg_items_thumb_hok_wheat.h"
namespace ks::background_metas {
    constexpr inline background_meta hok_wheat(
                     bn::regular_bg_items::hok_wheat,
                     bn::regular_bg_items::thumb_hok_wheat,
                     DISPLAYABLE_BITMASK_NONE,
                     0x98B09660);

}

#endif  // KS_BGMETA_HOK_WHEAT
