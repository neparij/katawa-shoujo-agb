#ifndef KS_SPRITEMETA_HANAGOWN_BASIC
#define KS_SPRITEMETA_HANAGOWN_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_hanagown_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta hanagown_basic(
                                           4,
                                           -48,
                                           bn::sprite_items::hanagown_thumb_basic,
                                           0xE84F);
}

#endif  // KS_SPRITEMETA_HANAGOWN_BASIC
