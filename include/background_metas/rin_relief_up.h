#ifndef KS_BGMETA_RIN_RELIEF_UP
#define KS_BGMETA_RIN_RELIEF_UP

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_relief_up.h"
#include "bn_regular_bg_items_thumb_rin_relief_up.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_relief_up(
                     bn::regular_bg_items::rin_relief_up,
                     bn::regular_bg_items::thumb_rin_relief_up,
                     DISPLAYABLE_BITMASK_RIN_RELIEF_UP,
                     0x602E8E6D);

}

#endif  // KS_BGMETA_RIN_RELIEF_UP
