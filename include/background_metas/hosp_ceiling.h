#ifndef KS_BGMETA_HOSP_CEILING
#define KS_BGMETA_HOSP_CEILING

#include "background_meta.h"
#include "bn_regular_bg_items_hosp_ceiling.h"
#include "bn_sprite_items_thumb_hosp_ceiling.h"
namespace ks::background_metas {
    constexpr inline background_meta hosp_ceiling(
                     bn::regular_bg_items::hosp_ceiling,
                     bn::sprite_items::thumb_hosp_ceiling,
                     0x7D1FED55);

}

#endif  // KS_BGMETA_HOSP_CEILING
