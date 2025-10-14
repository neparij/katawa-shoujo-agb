#ifndef KS_BGMETA_SUBURB_ROADCENTER_SS
#define KS_BGMETA_SUBURB_ROADCENTER_SS

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_suburb_roadcenter_ss.h"
#include "bn_regular_bg_items_thumb_suburb_roadcenter_ss.h"
namespace ks::background_metas {
    constexpr inline background_meta suburb_roadcenter_ss(
                     bn::regular_bg_items::suburb_roadcenter_ss,
                     bn::regular_bg_items::thumb_suburb_roadcenter_ss,
                     DISPLAYABLE_BITMASK_NONE,
                     0xE7DFE96B);

}

#endif  // KS_BGMETA_SUBURB_ROADCENTER_SS
