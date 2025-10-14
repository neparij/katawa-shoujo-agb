#ifndef KS_BGMETA_SUBURB_ROADCENTER_NI
#define KS_BGMETA_SUBURB_ROADCENTER_NI

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_suburb_roadcenter_ni.h"
#include "bn_regular_bg_items_thumb_suburb_roadcenter_ni.h"
namespace ks::background_metas {
    constexpr inline background_meta suburb_roadcenter_ni(
                     bn::regular_bg_items::suburb_roadcenter_ni,
                     bn::regular_bg_items::thumb_suburb_roadcenter_ni,
                     DISPLAYABLE_BITMASK_NONE,
                     0x1CA723BD);

}

#endif  // KS_BGMETA_SUBURB_ROADCENTER_NI
