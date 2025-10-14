#ifndef KS_BGMETA_LILLY_TRAINRIDE_NI_NORM
#define KS_BGMETA_LILLY_TRAINRIDE_NI_NORM

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_trainride_ni_norm.h"
#include "bn_regular_bg_items_thumb_lilly_trainride_ni_norm.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_trainride_ni_norm(
                     bn::regular_bg_items::lilly_trainride_ni_norm,
                     bn::regular_bg_items::thumb_lilly_trainride_ni_norm,
                     DISPLAYABLE_BITMASK_NONE,
                     0x41EDCF16);

}

#endif  // KS_BGMETA_LILLY_TRAINRIDE_NI_NORM
