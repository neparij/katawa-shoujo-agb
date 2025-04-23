#ifndef KS_BGMETA_HOSP_EXT
#define KS_BGMETA_HOSP_EXT

#include "background_meta.h"
#include "bn_regular_bg_items_hosp_ext.h"
#include "bn_sprite_items_thumb_hosp_ext.h"
namespace ks::background_metas {
    constexpr inline background_meta hosp_ext(
                     bn::regular_bg_items::hosp_ext,
                     bn::sprite_items::thumb_hosp_ext,
                     0x1FB79AAE);

}

#endif  // KS_BGMETA_HOSP_EXT
