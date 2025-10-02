#ifndef KS_BGMETA_SHIZU_LIVING
#define KS_BGMETA_SHIZU_LIVING

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_living.h"
#include "bn_regular_bg_items_thumb_shizu_living.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_living(
                     bn::regular_bg_items::shizu_living,
                     bn::regular_bg_items::thumb_shizu_living,
                     DISPLAYABLE_BITMASK_NONE,
                     0xD99625B2);

}

#endif  // KS_BGMETA_SHIZU_LIVING
