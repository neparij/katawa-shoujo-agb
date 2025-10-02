#ifndef KS_BGMETA_RIN_HIGH_ONEEYE
#define KS_BGMETA_RIN_HIGH_ONEEYE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_high_oneeye.h"
#include "bn_regular_bg_items_thumb_rin_high_oneeye.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_high_oneeye(
                     bn::regular_bg_items::rin_high_oneeye,
                     bn::regular_bg_items::thumb_rin_high_oneeye,
                     DISPLAYABLE_BITMASK_RIN_HIGH_ONEEYE,
                     0xA8091838);

}

#endif  // KS_BGMETA_RIN_HIGH_ONEEYE
