#ifndef KS_BGMETA_MISC_CEILING
#define KS_BGMETA_MISC_CEILING

#include "background_meta.h"
#include "bn_regular_bg_items_misc_ceiling.h"
#include "bn_sprite_items_thumb_misc_ceiling.h"
namespace ks::background_metas {
    constexpr inline background_meta misc_ceiling(
                     bn::regular_bg_items::misc_ceiling,
                     bn::sprite_items::thumb_misc_ceiling,
                     0xE751D1CF);

}

#endif  // KS_BGMETA_MISC_CEILING
