#ifndef KS_BGMETA_RIN_H_NORMAL_CLOSE
#define KS_BGMETA_RIN_H_NORMAL_CLOSE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_h_normal_close.h"
#include "bn_regular_bg_items_thumb_rin_h_normal_close.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_h_normal_close(
                     bn::regular_bg_items::rin_h_normal_close,
                     bn::regular_bg_items::thumb_rin_h_normal_close,
                     DISPLAYABLE_BITMASK_RIN_H_NORMAL_CLOSE,
                     0x6BF21BE8);

}

#endif  // KS_BGMETA_RIN_H_NORMAL_CLOSE
