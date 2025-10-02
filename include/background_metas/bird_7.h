#ifndef KS_BGMETA_BIRD_7
#define KS_BGMETA_BIRD_7

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_bird_7.h"
#include "bn_regular_bg_items_thumb_bird_7.h"
namespace ks::background_metas {
    constexpr inline background_meta bird_7(
                     bn::regular_bg_items::bird_7,
                     bn::regular_bg_items::thumb_bird_7,
                     DISPLAYABLE_BITMASK_NONE,
                     0x7FCDB335);

}

#endif  // KS_BGMETA_BIRD_7
