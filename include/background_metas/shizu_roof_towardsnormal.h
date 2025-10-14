#ifndef KS_BGMETA_SHIZU_ROOF_TOWARDSNORMAL
#define KS_BGMETA_SHIZU_ROOF_TOWARDSNORMAL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_roof_towardsnormal.h"
#include "bn_regular_bg_items_thumb_shizu_roof_towardsnormal.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_roof_towardsnormal(
                     bn::regular_bg_items::shizu_roof_towardsnormal,
                     bn::regular_bg_items::thumb_shizu_roof_towardsnormal,
                     DISPLAYABLE_BITMASK_SHIZU_ROOF_TOWARDSNORMAL,
                     0x5F87312D);

}

#endif  // KS_BGMETA_SHIZU_ROOF_TOWARDSNORMAL
