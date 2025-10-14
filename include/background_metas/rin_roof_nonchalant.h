#ifndef KS_BGMETA_RIN_ROOF_NONCHALANT
#define KS_BGMETA_RIN_ROOF_NONCHALANT

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_roof_nonchalant.h"
#include "bn_regular_bg_items_thumb_rin_roof_nonchalant.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_roof_nonchalant(
                     bn::regular_bg_items::rin_roof_nonchalant,
                     bn::regular_bg_items::thumb_rin_roof_nonchalant,
                     DISPLAYABLE_BITMASK_NONE,
                     0xD192FE62);

}

#endif  // KS_BGMETA_RIN_ROOF_NONCHALANT
