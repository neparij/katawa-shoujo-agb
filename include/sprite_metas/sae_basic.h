#ifndef KS_SPRITEMETA_SAE_BASIC
#define KS_SPRITEMETA_SAE_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_sae_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta sae_basic(
                                           -4,
                                           -48,
                                           bn::sprite_items::sae_thumb_basic,
                                           0x44A8);
}

#endif  // KS_SPRITEMETA_SAE_BASIC
