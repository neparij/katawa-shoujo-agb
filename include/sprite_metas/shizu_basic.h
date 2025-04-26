#ifndef KS_SPRITEMETA_SHIZU_BASIC
#define KS_SPRITEMETA_SHIZU_BASIC

#include "character_sprite_meta.h"

#include "bn_sprite_items_shizu_thumb_basic.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta shizu_basic(
                                           16,
                                           -32,
                                           bn::sprite_items::shizu_thumb_basic,
                                           0x37DE);
}

#endif  // KS_SPRITEMETA_SHIZU_BASIC
