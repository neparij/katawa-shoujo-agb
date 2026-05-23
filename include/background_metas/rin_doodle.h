#ifndef KS_BGMETA_RIN_DOODLE
#define KS_BGMETA_RIN_DOODLE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_doodle.h"
#include "bn_regular_bg_items_thumb_rin_doodle.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_doodle(
                     bn::regular_bg_items::rin_doodle,
                     bn::regular_bg_items::thumb_rin_doodle,
                     DISPLAYABLE_BITMASK_NONE,
                     0x48ACBAED);

}

#endif  // KS_BGMETA_RIN_DOODLE
