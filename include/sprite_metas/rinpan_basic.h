#ifndef KS_SPRITEMETA_RINPAN_BASIC
#define KS_SPRITEMETA_RINPAN_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_rinpan_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta rinpan_basic(
                                           -4,
                                           -44,
                                           bn::sprite_items::rinpan_thumb_basic,
                                           0xE908);
}

#endif  // KS_SPRITEMETA_RINPAN_BASIC
