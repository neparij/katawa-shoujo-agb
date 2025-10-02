#ifndef KS_BGMETA_SHIZU_UNDRESSING_CLOTHED_KISS
#define KS_BGMETA_SHIZU_UNDRESSING_CLOTHED_KISS

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_undressing_clothed_kiss.h"
#include "bn_regular_bg_items_thumb_shizu_undressing_clothed_kiss.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_undressing_clothed_kiss(
                     bn::regular_bg_items::shizu_undressing_clothed_kiss,
                     bn::regular_bg_items::thumb_shizu_undressing_clothed_kiss,
                     DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_KISS,
                     0xC4C2CC63);

}

#endif  // KS_BGMETA_SHIZU_UNDRESSING_CLOTHED_KISS
