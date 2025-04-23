#ifndef KS_BGMETA_HANA_LIBRARY
#define KS_BGMETA_HANA_LIBRARY

#include "background_meta.h"
#include "bn_regular_bg_items_hana_library.h"
#include "bn_sprite_items_thumb_hana_library.h"
namespace ks::background_metas {
    constexpr inline background_meta hana_library(
                     bn::regular_bg_items::hana_library,
                     bn::sprite_items::thumb_hana_library,
                     0x092915A0);

}

#endif  // KS_BGMETA_HANA_LIBRARY
