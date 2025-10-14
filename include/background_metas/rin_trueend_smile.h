#ifndef KS_BGMETA_RIN_TRUEEND_SMILE
#define KS_BGMETA_RIN_TRUEEND_SMILE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_trueend_smile.h"
#include "bn_regular_bg_items_thumb_rin_trueend_smile.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_trueend_smile(
                     bn::regular_bg_items::rin_trueend_smile,
                     bn::regular_bg_items::thumb_rin_trueend_smile,
                     DISPLAYABLE_BITMASK_RIN_TRUEEND_SMILE,
                     0x478B5C07);

}

#endif  // KS_BGMETA_RIN_TRUEEND_SMILE
