#ifndef KS_BGMETA_SHIZU_UNDRESSING_UNCLOTHED_KISS
#define KS_BGMETA_SHIZU_UNDRESSING_UNCLOTHED_KISS

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_undressing_unclothed_kiss.h"
#include "bn_regular_bg_items_thumb_shizu_undressing_unclothed_kiss.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_undressing_unclothed_kiss(
                     bn::regular_bg_items::shizu_undressing_unclothed_kiss,
                     bn::regular_bg_items::thumb_shizu_undressing_unclothed_kiss,
                     DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_KISS,
                     0x1F3F9121);

}

#endif  // KS_BGMETA_SHIZU_UNDRESSING_UNCLOTHED_KISS
