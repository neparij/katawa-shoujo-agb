#ifndef KS_SPRITEMETA_SHIZU_ADJUST_CAS
#define KS_SPRITEMETA_SHIZU_ADJUST_CAS

#include "character_sprite_meta.h"

#include "bn_sprite_items_shizu_thumb_adjust_cas.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta shizu_adjust_cas(
                                           -8,
                                           -32,
                                           bn::sprite_items::shizu_thumb_adjust_cas,
                                           0x75CB);
}

#endif  // KS_SPRITEMETA_SHIZU_ADJUST_CAS
