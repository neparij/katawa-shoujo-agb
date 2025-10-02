#ifndef KS_BGMETA_RIN_H_NORMAL
#define KS_BGMETA_RIN_H_NORMAL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_h_normal.h"
#include "bn_regular_bg_items_thumb_rin_h_normal.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_h_normal(
                     bn::regular_bg_items::rin_h_normal,
                     bn::regular_bg_items::thumb_rin_h_normal,
                     DISPLAYABLE_BITMASK_RIN_H_NORMAL,
                     0xB783FCC3);

}

#endif  // KS_BGMETA_RIN_H_NORMAL
