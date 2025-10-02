#ifndef KS_BGMETA_RIN_HIGH_GRIN
#define KS_BGMETA_RIN_HIGH_GRIN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_high_grin.h"
#include "bn_regular_bg_items_thumb_rin_high_grin.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_high_grin(
                     bn::regular_bg_items::rin_high_grin,
                     bn::regular_bg_items::thumb_rin_high_grin,
                     DISPLAYABLE_BITMASK_RIN_HIGH_GRIN,
                     0x80DAD74B);

}

#endif  // KS_BGMETA_RIN_HIGH_GRIN
