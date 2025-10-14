#ifndef KS_BGMETA_EMI_SLEEP_NORMAL
#define KS_BGMETA_EMI_SLEEP_NORMAL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_sleep_normal.h"
#include "bn_regular_bg_items_thumb_emi_sleep_normal.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_sleep_normal(
                     bn::regular_bg_items::emi_sleep_normal,
                     bn::regular_bg_items::thumb_emi_sleep_normal,
                     DISPLAYABLE_BITMASK_EMI_SLEEP_NORMAL,
                     0x4D12722B);

}

#endif  // KS_BGMETA_EMI_SLEEP_NORMAL
