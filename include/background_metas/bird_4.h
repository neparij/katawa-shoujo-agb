#ifndef KS_BGMETA_BIRD_4
#define KS_BGMETA_BIRD_4

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_bird_4.h"
#include "bn_regular_bg_items_thumb_bird_4.h"
namespace ks::background_metas {
    constexpr inline background_meta bird_4(
                     bn::regular_bg_items::bird_4,
                     bn::regular_bg_items::thumb_bird_4,
                     DISPLAYABLE_BITMASK_NONE,
                     0xB52CDED8);

}

#endif  // KS_BGMETA_BIRD_4
