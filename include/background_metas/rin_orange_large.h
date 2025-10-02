#ifndef KS_BGMETA_RIN_ORANGE_LARGE
#define KS_BGMETA_RIN_ORANGE_LARGE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_orange_large.h"
#include "bn_regular_bg_items_thumb_rin_orange_large.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_orange_large(
                     bn::regular_bg_items::rin_orange_large,
                     bn::regular_bg_items::thumb_rin_orange_large,
                     DISPLAYABLE_BITMASK_RIN_ORANGE_LARGE,
                     0x807EAB94);

}

#endif  // KS_BGMETA_RIN_ORANGE_LARGE
