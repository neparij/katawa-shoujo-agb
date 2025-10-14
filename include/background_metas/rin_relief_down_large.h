#ifndef KS_BGMETA_RIN_RELIEF_DOWN_LARGE
#define KS_BGMETA_RIN_RELIEF_DOWN_LARGE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_relief_down_large.h"
#include "bn_regular_bg_items_thumb_rin_relief_down_large.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_relief_down_large(
                     bn::regular_bg_items::rin_relief_down_large,
                     bn::regular_bg_items::thumb_rin_relief_down_large,
                     DISPLAYABLE_BITMASK_NONE,
                     0xE20A7B72);

}

#endif  // KS_BGMETA_RIN_RELIEF_DOWN_LARGE
