#ifndef KS_BGMETA_RIN_PAIR_BASE
#define KS_BGMETA_RIN_PAIR_BASE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_pair_base.h"
#include "bn_regular_bg_items_thumb_rin_pair_base.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_pair_base(
                     bn::regular_bg_items::rin_pair_base,
                     bn::regular_bg_items::thumb_rin_pair_base,
                     DISPLAYABLE_BITMASK_RIN_PAIR_BASE,
                     0x79429E5D);

}

#endif  // KS_BGMETA_RIN_PAIR_BASE
