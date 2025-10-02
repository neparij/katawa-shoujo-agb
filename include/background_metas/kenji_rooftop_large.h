#ifndef KS_BGMETA_KENJI_ROOFTOP_LARGE
#define KS_BGMETA_KENJI_ROOFTOP_LARGE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_kenji_rooftop_large.h"
#include "bn_regular_bg_items_thumb_kenji_rooftop_large.h"
namespace ks::background_metas {
    constexpr inline background_meta kenji_rooftop_large(
                     bn::regular_bg_items::kenji_rooftop_large,
                     bn::regular_bg_items::thumb_kenji_rooftop_large,
                     DISPLAYABLE_BITMASK_NONE,
                     0x24E43576);

}

#endif  // KS_BGMETA_KENJI_ROOFTOP_LARGE
