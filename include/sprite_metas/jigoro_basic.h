#ifndef KS_SPRITEMETA_JIGORO_BASIC
#define KS_SPRITEMETA_JIGORO_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_jigoro_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta jigoro_basic(
                                           -16,
                                           -56,
                                           bn::sprite_items::jigoro_thumb_basic,
                                           0xEE30);
}

#endif  // KS_SPRITEMETA_JIGORO_BASIC
