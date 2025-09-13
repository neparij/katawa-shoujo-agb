#ifndef KS_SPRITEMETA_EMICAS_BASIC
#define KS_SPRITEMETA_EMICAS_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_emicas_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta emicas_basic(
                                           8,
                                           -24,
                                           bn::sprite_items::emicas_thumb_basic,
                                           0x896C);
}

#endif  // KS_SPRITEMETA_EMICAS_BASIC
