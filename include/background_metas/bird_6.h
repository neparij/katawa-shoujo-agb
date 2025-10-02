#ifndef KS_BGMETA_BIRD_6
#define KS_BGMETA_BIRD_6

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_bird_6.h"
#include "bn_regular_bg_items_thumb_bird_6.h"
namespace ks::background_metas {
    constexpr inline background_meta bird_6(
                     bn::regular_bg_items::bird_6,
                     bn::regular_bg_items::thumb_bird_6,
                     DISPLAYABLE_BITMASK_NONE,
                     0x5531A579);

}

#endif  // KS_BGMETA_BIRD_6
