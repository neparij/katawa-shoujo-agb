#ifndef KS_BGMETA_EMI_MISS_CLOSED
#define KS_BGMETA_EMI_MISS_CLOSED

#include "background_meta.h"
#include "bn_regular_bg_items_emi_miss_closed.h"
#include "bn_sprite_items_thumb_emi_miss_closed.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_miss_closed(
                     bn::regular_bg_items::emi_miss_closed,
                     bn::sprite_items::thumb_emi_miss_closed,
                     0x30481238);

}

#endif  // KS_BGMETA_EMI_MISS_CLOSED
