#ifndef KS_BGMETA_RIN_TRUEEND_HUG
#define KS_BGMETA_RIN_TRUEEND_HUG

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_trueend_hug.h"
#include "bn_regular_bg_items_thumb_rin_trueend_hug.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_trueend_hug(
                     bn::regular_bg_items::rin_trueend_hug,
                     bn::regular_bg_items::thumb_rin_trueend_hug,
                     DISPLAYABLE_BITMASK_RIN_TRUEEND_HUG,
                     0x86436BEC);

}

#endif  // KS_BGMETA_RIN_TRUEEND_HUG
