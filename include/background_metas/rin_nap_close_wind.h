#ifndef KS_BGMETA_RIN_NAP_CLOSE_WIND
#define KS_BGMETA_RIN_NAP_CLOSE_WIND

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_nap_close_wind.h"
#include "bn_regular_bg_items_thumb_rin_nap_close_wind.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_nap_close_wind(
                     bn::regular_bg_items::rin_nap_close_wind,
                     bn::regular_bg_items::thumb_rin_nap_close_wind,
                     DISPLAYABLE_BITMASK_NONE,
                     0x1DCF09FD);

}

#endif  // KS_BGMETA_RIN_NAP_CLOSE_WIND
