#ifndef KS_SPRITEMETA_MIKI_BASIC
#define KS_SPRITEMETA_MIKI_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_miki_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta miki_basic(
                                           -4,
                                           -40,
                                           bn::sprite_items::miki_thumb_basic,
                                           0xD9BF);
}

#endif  // KS_SPRITEMETA_MIKI_BASIC
