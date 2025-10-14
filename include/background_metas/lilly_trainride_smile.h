#ifndef KS_BGMETA_LILLY_TRAINRIDE_SMILE
#define KS_BGMETA_LILLY_TRAINRIDE_SMILE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_trainride_smile.h"
#include "bn_regular_bg_items_thumb_lilly_trainride_smile.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_trainride_smile(
                     bn::regular_bg_items::lilly_trainride_smile,
                     bn::regular_bg_items::thumb_lilly_trainride_smile,
                     DISPLAYABLE_BITMASK_NONE,
                     0xF66074CA);

}

#endif  // KS_BGMETA_LILLY_TRAINRIDE_SMILE
