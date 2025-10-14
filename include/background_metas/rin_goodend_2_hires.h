#ifndef KS_BGMETA_RIN_GOODEND_2_HIRES
#define KS_BGMETA_RIN_GOODEND_2_HIRES

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_goodend_2_hires.h"
#include "bn_regular_bg_items_thumb_rin_goodend_2_hires.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_goodend_2_hires(
                     bn::regular_bg_items::rin_goodend_2_hires,
                     bn::regular_bg_items::thumb_rin_goodend_2_hires,
                     DISPLAYABLE_BITMASK_NONE,
                     0xE65AAFD6);

}

#endif  // KS_BGMETA_RIN_GOODEND_2_HIRES
