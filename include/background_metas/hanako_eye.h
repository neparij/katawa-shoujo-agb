#ifndef KS_BGMETA_HANAKO_EYE
#define KS_BGMETA_HANAKO_EYE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_eye.h"
#include "bn_regular_bg_items_thumb_hanako_eye.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_eye(
                     bn::regular_bg_items::hanako_eye,
                     bn::regular_bg_items::thumb_hanako_eye,
                     DISPLAYABLE_BITMASK_NONE,
                     0xD043743F);

}

#endif  // KS_BGMETA_HANAKO_EYE
