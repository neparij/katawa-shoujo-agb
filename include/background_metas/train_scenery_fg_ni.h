#ifndef KS_BGMETA_TRAIN_SCENERY_FG_NI
#define KS_BGMETA_TRAIN_SCENERY_FG_NI

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_train_scenery_fg_ni.h"
#include "bn_regular_bg_items_thumb_train_scenery_fg_ni.h"
namespace ks::background_metas {
    constexpr inline background_meta train_scenery_fg_ni(
                     bn::regular_bg_items::train_scenery_fg_ni,
                     bn::regular_bg_items::thumb_train_scenery_fg_ni,
                     DISPLAYABLE_BITMASK_NONE,
                     0x21A69878);

}

#endif  // KS_BGMETA_TRAIN_SCENERY_FG_NI
