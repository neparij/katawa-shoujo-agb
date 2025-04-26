#ifndef KS_SPRITEMETA_SHIZU_BEHIND_NAK
#define KS_SPRITEMETA_SHIZU_BEHIND_NAK

#include "character_sprite_meta.h"

#include "bn_sprite_items_shizu_thumb_behind_nak.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta shizu_behind_nak(
                                           -8,
                                           -32,
                                           bn::sprite_items::shizu_thumb_behind_nak,
                                           0xD33B);
}

#endif  // KS_SPRITEMETA_SHIZU_BEHIND_NAK
