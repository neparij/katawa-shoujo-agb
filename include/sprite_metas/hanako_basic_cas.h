#ifndef KS_SPRITEMETA_HANAKO_BASIC_CAS
#define KS_SPRITEMETA_HANAKO_BASIC_CAS

#include "character_sprite_meta.h"

#include "bn_sprite_items_hanako_thumb_basic_cas.h"
namespace ks::sprite_metas {
    constexpr inline character_sprite_meta hanako_basic_cas(
                                           4,
                                           -48,
                                           bn::sprite_items::hanako_thumb_basic_cas,
                                           0x7150);
}

#endif  // KS_SPRITEMETA_HANAKO_BASIC_CAS
