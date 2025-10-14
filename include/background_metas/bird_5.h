#ifndef KS_BGMETA_BIRD_5
#define KS_BGMETA_BIRD_5

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_bird_5.h"
#include "bn_regular_bg_items_thumb_bird_5.h"
namespace ks::background_metas {
    constexpr inline background_meta bird_5(
                     bn::regular_bg_items::bird_5,
                     bn::regular_bg_items::thumb_bird_5,
                     DISPLAYABLE_BITMASK_NONE,
                     0xB2EFF370);

}

#endif  // KS_BGMETA_BIRD_5
