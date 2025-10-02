#ifndef KS_BGMETA_LILLY_TRAINRIDE_NI
#define KS_BGMETA_LILLY_TRAINRIDE_NI

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_trainride_ni.h"
#include "bn_regular_bg_items_thumb_lilly_trainride_ni.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_trainride_ni(
                     bn::regular_bg_items::lilly_trainride_ni,
                     bn::regular_bg_items::thumb_lilly_trainride_ni,
                     DISPLAYABLE_BITMASK_LILLY_TRAINRIDE_NI,
                     0x26BAA666);

}

#endif  // KS_BGMETA_LILLY_TRAINRIDE_NI
