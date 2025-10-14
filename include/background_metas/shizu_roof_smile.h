#ifndef KS_BGMETA_SHIZU_ROOF_SMILE
#define KS_BGMETA_SHIZU_ROOF_SMILE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_roof_smile.h"
#include "bn_regular_bg_items_thumb_shizu_roof_smile.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_roof_smile(
                     bn::regular_bg_items::shizu_roof_smile,
                     bn::regular_bg_items::thumb_shizu_roof_smile,
                     DISPLAYABLE_BITMASK_SHIZU_ROOF_SMILE,
                     0x196CDBD5);

}

#endif  // KS_BGMETA_SHIZU_ROOF_SMILE
