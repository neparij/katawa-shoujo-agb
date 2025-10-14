#ifndef KS_BGMETA_HANAKO_AFTER_SMILE
#define KS_BGMETA_HANAKO_AFTER_SMILE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_after_smile.h"
#include "bn_regular_bg_items_thumb_hanako_after_smile.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_after_smile(
                     bn::regular_bg_items::hanako_after_smile,
                     bn::regular_bg_items::thumb_hanako_after_smile,
                     DISPLAYABLE_BITMASK_HANAKO_AFTER_SMILE,
                     0x3F2F9C97);

}

#endif  // KS_BGMETA_HANAKO_AFTER_SMILE
