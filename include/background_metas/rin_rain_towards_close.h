#ifndef KS_BGMETA_RIN_RAIN_TOWARDS_CLOSE
#define KS_BGMETA_RIN_RAIN_TOWARDS_CLOSE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_rain_towards_close.h"
#include "bn_regular_bg_items_thumb_rin_rain_towards_close.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_rain_towards_close(
                     bn::regular_bg_items::rin_rain_towards_close,
                     bn::regular_bg_items::thumb_rin_rain_towards_close,
                     DISPLAYABLE_BITMASK_NONE,
                     0xE9512F30);

}

#endif  // KS_BGMETA_RIN_RAIN_TOWARDS_CLOSE
