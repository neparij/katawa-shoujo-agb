#ifndef KS_SPRITEMETA_EMIWHEEL_BASIC
#define KS_SPRITEMETA_EMIWHEEL_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_emiwheel_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta emiwheel_basic(
                                           8,
                                           0,
                                           bn::sprite_items::emiwheel_thumb_basic,
                                           0xBB83);
}

#endif  // KS_SPRITEMETA_EMIWHEEL_BASIC
