#ifndef KS_BGMETA_MISHA_ROOF_NORMAL
#define KS_BGMETA_MISHA_ROOF_NORMAL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_misha_roof_normal.h"
#include "bn_regular_bg_items_thumb_misha_roof_normal.h"
namespace ks::background_metas {
    constexpr inline background_meta misha_roof_normal(
                     bn::regular_bg_items::misha_roof_normal,
                     bn::regular_bg_items::thumb_misha_roof_normal,
                     DISPLAYABLE_BITMASK_MISHA_ROOF_NORMAL,
                     0x7D431D45);

}

#endif  // KS_BGMETA_MISHA_ROOF_NORMAL
