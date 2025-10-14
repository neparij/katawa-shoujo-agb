#ifndef KS_BGMETA_BIRD_8
#define KS_BGMETA_BIRD_8

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_bird_8.h"
#include "bn_regular_bg_items_thumb_bird_8.h"
namespace ks::background_metas {
    constexpr inline background_meta bird_8(
                     bn::regular_bg_items::bird_8,
                     bn::regular_bg_items::thumb_bird_8,
                     DISPLAYABLE_BITMASK_NONE,
                     0x2A454BF6);

}

#endif  // KS_BGMETA_BIRD_8
