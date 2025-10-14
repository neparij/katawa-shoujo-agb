#ifndef KS_BGMETA_SHIZU_GOODEND
#define KS_BGMETA_SHIZU_GOODEND

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_goodend.h"
#include "bn_regular_bg_items_thumb_shizu_goodend.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_goodend(
                     bn::regular_bg_items::shizu_goodend,
                     bn::regular_bg_items::thumb_shizu_goodend,
                     DISPLAYABLE_BITMASK_SHIZU_GOODEND,
                     0x7D5E8FA4);

}

#endif  // KS_BGMETA_SHIZU_GOODEND
