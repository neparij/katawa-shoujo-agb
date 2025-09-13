#ifndef KS_SPRITEMETA_MEIKO_BASIC
#define KS_SPRITEMETA_MEIKO_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_meiko_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta meiko_basic(
                                           0,
                                           -48,
                                           bn::sprite_items::meiko_thumb_basic,
                                           0x4984);
}

#endif  // KS_SPRITEMETA_MEIKO_BASIC
