#ifndef KS_SPRITEMETA_MUTO_BASIC
#define KS_SPRITEMETA_MUTO_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_muto_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta muto_basic(
                                           -4,
                                           -60,
                                           bn::sprite_items::muto_thumb_basic,
                                           0xB1B3);
}

#endif  // KS_SPRITEMETA_MUTO_BASIC
