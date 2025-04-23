#ifndef KS_BGMETA_HANA_LIBRARY_READ
#define KS_BGMETA_HANA_LIBRARY_READ

#include "background_meta.h"
#include "bn_regular_bg_items_hana_library_read.h"
#include "bn_sprite_items_thumb_hana_library_read.h"
namespace ks::background_metas {
    constexpr inline background_meta hana_library_read(
                     bn::regular_bg_items::hana_library_read,
                     bn::sprite_items::thumb_hana_library_read,
                     0x3BADDF80);

}

#endif  // KS_BGMETA_HANA_LIBRARY_READ
