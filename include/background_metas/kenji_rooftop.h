#ifndef KS_BGMETA_KENJI_ROOFTOP
#define KS_BGMETA_KENJI_ROOFTOP

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_kenji_rooftop.h"
#include "bn_regular_bg_items_thumb_kenji_rooftop.h"
namespace ks::background_metas {
    constexpr inline background_meta kenji_rooftop(
                     bn::regular_bg_items::kenji_rooftop,
                     bn::regular_bg_items::thumb_kenji_rooftop,
                     DISPLAYABLE_BITMASK_KENJI_ROOFTOP,
                     0x5DD2D87C);

}

#endif  // KS_BGMETA_KENJI_ROOFTOP
