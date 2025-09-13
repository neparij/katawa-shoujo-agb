#ifndef KS_SPRITEMETA_AKIRA_BASIC
#define KS_SPRITEMETA_AKIRA_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_akira_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta akira_basic(
                                           0,
                                           -48,
                                           bn::sprite_items::akira_thumb_basic,
                                           0x02D6);
}

#endif  // KS_SPRITEMETA_AKIRA_BASIC
