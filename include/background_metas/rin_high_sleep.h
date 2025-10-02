#ifndef KS_BGMETA_RIN_HIGH_SLEEP
#define KS_BGMETA_RIN_HIGH_SLEEP

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_high_sleep.h"
#include "bn_regular_bg_items_thumb_rin_high_sleep.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_high_sleep(
                     bn::regular_bg_items::rin_high_sleep,
                     bn::regular_bg_items::thumb_rin_high_sleep,
                     DISPLAYABLE_BITMASK_RIN_HIGH_SLEEP,
                     0x4E6BB0F8);

}

#endif  // KS_BGMETA_RIN_HIGH_SLEEP
