#ifndef KS_BGMETA_RIN_PAIR_RIN_TALK
#define KS_BGMETA_RIN_PAIR_RIN_TALK

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_pair_rin_talk.h"
#include "bn_regular_bg_items_thumb_rin_pair_rin_talk.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_pair_rin_talk(
                     bn::regular_bg_items::rin_pair_rin_talk,
                     bn::regular_bg_items::thumb_rin_pair_rin_talk,
                     DISPLAYABLE_BITMASK_NONE,
                     0x57B2B5E6);

}

#endif  // KS_BGMETA_RIN_PAIR_RIN_TALK
