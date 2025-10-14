#ifndef KS_BGMETA_RIN_GALLERYSKYLIGHT
#define KS_BGMETA_RIN_GALLERYSKYLIGHT

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_galleryskylight.h"
#include "bn_regular_bg_items_thumb_rin_galleryskylight.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_galleryskylight(
                     bn::regular_bg_items::rin_galleryskylight,
                     bn::regular_bg_items::thumb_rin_galleryskylight,
                     DISPLAYABLE_BITMASK_RIN_GALLERYSKYLIGHT,
                     0xC18B5048);

}

#endif  // KS_BGMETA_RIN_GALLERYSKYLIGHT
