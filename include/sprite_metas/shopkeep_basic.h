#ifndef KS_SPRITEMETA_SHOPKEEP_BASIC
#define KS_SPRITEMETA_SHOPKEEP_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_shopkeep_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta shopkeep_basic(
                                           -8,
                                           -48,
                                           bn::sprite_items::shopkeep_thumb_basic,
                                           0x92AF);
}

#endif  // KS_SPRITEMETA_SHOPKEEP_BASIC
