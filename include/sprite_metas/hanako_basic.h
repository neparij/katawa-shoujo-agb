#ifndef KS_SPRITEMETA_HANAKO_BASIC
#define KS_SPRITEMETA_HANAKO_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_hanako_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta hanako_basic(
                                           4,
                                           -48,
                                           bn::sprite_items::hanako_thumb_basic,
                                           0xAED6);
}

#endif  // KS_SPRITEMETA_HANAKO_BASIC
