#ifndef KS_BGMETA_RIN_KISS
#define KS_BGMETA_RIN_KISS

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_kiss.h"
#include "bn_regular_bg_items_thumb_rin_kiss.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_kiss(
                     bn::regular_bg_items::rin_kiss,
                     bn::regular_bg_items::thumb_rin_kiss,
                     DISPLAYABLE_BITMASK_RIN_KISS,
                     0xB38F977E);

}

#endif  // KS_BGMETA_RIN_KISS
