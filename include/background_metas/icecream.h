#ifndef KS_BGMETA_ICECREAM
#define KS_BGMETA_ICECREAM

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_icecream.h"
#include "bn_regular_bg_items_thumb_icecream.h"
namespace ks::background_metas {
    constexpr inline background_meta icecream(
                     bn::regular_bg_items::icecream,
                     bn::regular_bg_items::thumb_icecream,
                     DISPLAYABLE_BITMASK_NONE,
                     0xC969B336);

}

#endif  // KS_BGMETA_ICECREAM
