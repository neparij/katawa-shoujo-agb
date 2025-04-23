#ifndef KS_BGMETA_EMI_PARKBACK
#define KS_BGMETA_EMI_PARKBACK

#include "background_meta.h"
#include "bn_regular_bg_items_emi_parkback.h"
#include "bn_sprite_items_thumb_emi_parkback.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_parkback(
                     bn::regular_bg_items::emi_parkback,
                     bn::sprite_items::thumb_emi_parkback,
                     0x6A474550);

}

#endif  // KS_BGMETA_EMI_PARKBACK
