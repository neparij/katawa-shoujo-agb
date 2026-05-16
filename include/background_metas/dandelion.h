#ifndef KS_BGMETA_DANDELION
#define KS_BGMETA_DANDELION

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_dandelion.h"
#include "bn_regular_bg_items_thumb_dandelion.h"
namespace ks::background_metas {
    constexpr inline background_meta dandelion(
                     bn::regular_bg_items::dandelion,
                     bn::regular_bg_items::thumb_dandelion,
                     DISPLAYABLE_BITMASK_NONE,
                     0xC2F79D98);

}

#endif  // KS_BGMETA_DANDELION
