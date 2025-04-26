#ifndef KS_SPRITEMETA_SHIZU_ADJUST
#define KS_SPRITEMETA_SHIZU_ADJUST

#include "character_sprite_meta.h"

#include "bn_sprite_items_shizu_thumb_adjust.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta shizu_adjust(
                                           -8,
                                           -32,
                                           bn::sprite_items::shizu_thumb_adjust,
                                           0x6CA1);
}

#endif  // KS_SPRITEMETA_SHIZU_ADJUST
