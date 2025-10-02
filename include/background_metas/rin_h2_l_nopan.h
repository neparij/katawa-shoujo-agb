#ifndef KS_BGMETA_RIN_H2_L_NOPAN
#define KS_BGMETA_RIN_H2_L_NOPAN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_h2_l_nopan.h"
#include "bn_regular_bg_items_thumb_rin_h2_l_nopan.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_h2_l_nopan(
                     bn::regular_bg_items::rin_h2_l_nopan,
                     bn::regular_bg_items::thumb_rin_h2_l_nopan,
                     DISPLAYABLE_BITMASK_NONE,
                     0x5CD67806);

}

#endif  // KS_BGMETA_RIN_H2_L_NOPAN
