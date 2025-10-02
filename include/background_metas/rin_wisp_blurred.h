#ifndef KS_BGMETA_RIN_WISP_BLURRED
#define KS_BGMETA_RIN_WISP_BLURRED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_wisp_blurred.h"
#include "bn_regular_bg_items_thumb_rin_wisp_blurred.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_wisp_blurred(
                     bn::regular_bg_items::rin_wisp_blurred,
                     bn::regular_bg_items::thumb_rin_wisp_blurred,
                     DISPLAYABLE_BITMASK_NONE,
                     0x8FF6095C);

}

#endif  // KS_BGMETA_RIN_WISP_BLURRED
