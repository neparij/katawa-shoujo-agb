#ifndef KS_BGMETA_RIN_NAP_CLOSE_HAND
#define KS_BGMETA_RIN_NAP_CLOSE_HAND

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_nap_close_hand.h"
#include "bn_regular_bg_items_thumb_rin_nap_close_hand.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_nap_close_hand(
                     bn::regular_bg_items::rin_nap_close_hand,
                     bn::regular_bg_items::thumb_rin_nap_close_hand,
                     DISPLAYABLE_BITMASK_NONE,
                     0x7FDEA9A2);

}

#endif  // KS_BGMETA_RIN_NAP_CLOSE_HAND
