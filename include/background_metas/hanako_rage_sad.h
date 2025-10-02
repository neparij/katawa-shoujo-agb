#ifndef KS_BGMETA_HANAKO_RAGE_SAD
#define KS_BGMETA_HANAKO_RAGE_SAD

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_rage_sad.h"
#include "bn_regular_bg_items_thumb_hanako_rage_sad.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_rage_sad(
                     bn::regular_bg_items::hanako_rage_sad,
                     bn::regular_bg_items::thumb_hanako_rage_sad,
                     DISPLAYABLE_BITMASK_HANAKO_RAGE_SAD,
                     0xC9613A6C);

}

#endif  // KS_BGMETA_HANAKO_RAGE_SAD
