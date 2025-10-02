#ifndef KS_BGMETA_SHIZU_UNDRESSING_CLOTHED_BLUSH
#define KS_BGMETA_SHIZU_UNDRESSING_CLOTHED_BLUSH

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_undressing_clothed_blush.h"
#include "bn_regular_bg_items_thumb_shizu_undressing_clothed_blush.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_undressing_clothed_blush(
                     bn::regular_bg_items::shizu_undressing_clothed_blush,
                     bn::regular_bg_items::thumb_shizu_undressing_clothed_blush,
                     DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_BLUSH,
                     0x3A073DCC);

}

#endif  // KS_BGMETA_SHIZU_UNDRESSING_CLOTHED_BLUSH
