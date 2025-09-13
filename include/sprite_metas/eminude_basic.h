#ifndef KS_SPRITEMETA_EMINUDE_BASIC
#define KS_SPRITEMETA_EMINUDE_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_eminude_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta eminude_basic(
                                           8,
                                           -24,
                                           bn::sprite_items::eminude_thumb_basic,
                                           0xF25A);
}

#endif  // KS_SPRITEMETA_EMINUDE_BASIC
