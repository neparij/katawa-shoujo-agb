#ifndef KS_BGMETA_HANAKO_SCARS_LARGE
#define KS_BGMETA_HANAKO_SCARS_LARGE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_scars_large.h"
#include "bn_regular_bg_items_thumb_hanako_scars_large.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_scars_large(
                     bn::regular_bg_items::hanako_scars_large,
                     bn::regular_bg_items::thumb_hanako_scars_large,
                     DISPLAYABLE_BITMASK_NONE,
                     0x227FCED9);

}

#endif  // KS_BGMETA_HANAKO_SCARS_LARGE
