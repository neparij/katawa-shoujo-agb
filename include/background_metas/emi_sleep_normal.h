#ifndef KS_BGMETA_EMI_SLEEP_NORMAL
#define KS_BGMETA_EMI_SLEEP_NORMAL

#include "background_meta.h"
#include "bn_regular_bg_items_emi_sleep_normal.h"
#include "bn_sprite_items_thumb_emi_sleep_normal.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_sleep_normal(
                     bn::regular_bg_items::emi_sleep_normal,
                     bn::sprite_items::thumb_emi_sleep_normal,
                     0x4D12722B);

}

#endif  // KS_BGMETA_EMI_SLEEP_NORMAL
