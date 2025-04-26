#ifndef KS_SPRITEMETA_SHIZU_BASIC_CAS
#define KS_SPRITEMETA_SHIZU_BASIC_CAS

#include "character_sprite_meta.h"

#include "bn_sprite_items_shizu_thumb_basic_cas.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta shizu_basic_cas(
                                           16,
                                           -32,
                                           bn::sprite_items::shizu_thumb_basic_cas,
                                           0x9409);
}

#endif  // KS_SPRITEMETA_SHIZU_BASIC_CAS
