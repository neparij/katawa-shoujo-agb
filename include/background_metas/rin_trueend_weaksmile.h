#ifndef KS_BGMETA_RIN_TRUEEND_WEAKSMILE
#define KS_BGMETA_RIN_TRUEEND_WEAKSMILE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_trueend_weaksmile.h"
#include "bn_regular_bg_items_thumb_rin_trueend_weaksmile.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_trueend_weaksmile(
                     bn::regular_bg_items::rin_trueend_weaksmile,
                     bn::regular_bg_items::thumb_rin_trueend_weaksmile,
                     DISPLAYABLE_BITMASK_RIN_TRUEEND_WEAKSMILE,
                     0x6819D3F3);

}

#endif  // KS_BGMETA_RIN_TRUEEND_WEAKSMILE
