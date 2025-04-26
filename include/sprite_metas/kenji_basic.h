#ifndef KS_SPRITEMETA_KENJI_BASIC
#define KS_SPRITEMETA_KENJI_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_kenji_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta kenji_basic(
                                           6,
                                           -46,
                                           bn::sprite_items::kenji_thumb_basic,
                                           0x0012);
}

#endif  // KS_SPRITEMETA_KENJI_BASIC
