#ifndef KS_BGMETA_TRAIN_SCENERY
#define KS_BGMETA_TRAIN_SCENERY

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_train_scenery.h"
#include "bn_regular_bg_items_thumb_train_scenery.h"
namespace ks::background_metas {
    constexpr inline background_meta train_scenery(
                     bn::regular_bg_items::train_scenery,
                     bn::regular_bg_items::thumb_train_scenery,
                     DISPLAYABLE_BITMASK_NONE,
                     0x0D463A0D);

}

#endif  // KS_BGMETA_TRAIN_SCENERY
