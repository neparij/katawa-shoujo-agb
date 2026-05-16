#ifndef KS_BGMETA_BRAILLE
#define KS_BGMETA_BRAILLE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_braille.h"
#include "bn_regular_bg_items_thumb_braille.h"
namespace ks::background_metas {
    constexpr inline background_meta braille(
                     bn::regular_bg_items::braille,
                     bn::regular_bg_items::thumb_braille,
                     DISPLAYABLE_BITMASK_NONE,
                     0x4B0327BF);

}

#endif  // KS_BGMETA_BRAILLE
