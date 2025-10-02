#ifndef KS_BGMETA_RIN_PAIR_HISAO_SMILE
#define KS_BGMETA_RIN_PAIR_HISAO_SMILE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_pair_hisao_smile.h"
#include "bn_regular_bg_items_thumb_rin_pair_hisao_smile.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_pair_hisao_smile(
                     bn::regular_bg_items::rin_pair_hisao_smile,
                     bn::regular_bg_items::thumb_rin_pair_hisao_smile,
                     DISPLAYABLE_BITMASK_NONE,
                     0x7C4AF34D);

}

#endif  // KS_BGMETA_RIN_PAIR_HISAO_SMILE
