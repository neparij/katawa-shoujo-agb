#ifndef KS_BGMETA_RIN_ROOF_SURPRISED
#define KS_BGMETA_RIN_ROOF_SURPRISED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_roof_surprised.h"
#include "bn_regular_bg_items_thumb_rin_roof_surprised.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_roof_surprised(
                     bn::regular_bg_items::rin_roof_surprised,
                     bn::regular_bg_items::thumb_rin_roof_surprised,
                     DISPLAYABLE_BITMASK_NONE,
                     0xD09A263D);

}

#endif  // KS_BGMETA_RIN_ROOF_SURPRISED
