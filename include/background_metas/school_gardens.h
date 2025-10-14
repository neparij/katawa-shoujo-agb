#ifndef KS_BGMETA_SCHOOL_GARDENS
#define KS_BGMETA_SCHOOL_GARDENS

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_gardens.h"
#include "bn_regular_bg_items_thumb_school_gardens.h"
namespace ks::background_metas {
    constexpr inline background_meta school_gardens(
                     bn::regular_bg_items::school_gardens,
                     bn::regular_bg_items::thumb_school_gardens,
                     DISPLAYABLE_BITMASK_NONE,
                     0x68C39FD3);

}

#endif  // KS_BGMETA_SCHOOL_GARDENS
