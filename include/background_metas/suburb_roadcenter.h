#ifndef KS_BGMETA_SUBURB_ROADCENTER
#define KS_BGMETA_SUBURB_ROADCENTER

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_suburb_roadcenter.h"
#include "bn_regular_bg_items_thumb_suburb_roadcenter.h"
namespace ks::background_metas {
    constexpr inline background_meta suburb_roadcenter(
                     bn::regular_bg_items::suburb_roadcenter,
                     bn::regular_bg_items::thumb_suburb_roadcenter,
                     DISPLAYABLE_BITMASK_NONE,
                     0x0D8F76F9);

}

#endif  // KS_BGMETA_SUBURB_ROADCENTER
