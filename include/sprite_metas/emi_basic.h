#ifndef KS_SPRITEMETA_EMI_BASIC
#define KS_SPRITEMETA_EMI_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_emi_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta emi_basic(
                                           -2,
                                           -24,
                                           bn::sprite_items::emi_thumb_basic,
                                           0x0C68);
}

#endif  // KS_SPRITEMETA_EMI_BASIC
