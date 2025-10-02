#ifndef KS_BGMETA_RIN_PAIR_RIN_CLOSED
#define KS_BGMETA_RIN_PAIR_RIN_CLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_pair_rin_closed.h"
#include "bn_regular_bg_items_thumb_rin_pair_rin_closed.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_pair_rin_closed(
                     bn::regular_bg_items::rin_pair_rin_closed,
                     bn::regular_bg_items::thumb_rin_pair_rin_closed,
                     DISPLAYABLE_BITMASK_NONE,
                     0xBA673F7F);

}

#endif  // KS_BGMETA_RIN_PAIR_RIN_CLOSED
