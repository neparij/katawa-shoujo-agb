#ifndef KS_BGMETA_RIN_H_LEFT_CLOSE
#define KS_BGMETA_RIN_H_LEFT_CLOSE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_h_left_close.h"
#include "bn_regular_bg_items_thumb_rin_h_left_close.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_h_left_close(
                     bn::regular_bg_items::rin_h_left_close,
                     bn::regular_bg_items::thumb_rin_h_left_close,
                     DISPLAYABLE_BITMASK_RIN_H_LEFT_CLOSE,
                     0xBE664BFD);

}

#endif  // KS_BGMETA_RIN_H_LEFT_CLOSE
