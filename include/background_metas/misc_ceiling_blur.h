#ifndef KS_BGMETA_MISC_CEILING_BLUR
#define KS_BGMETA_MISC_CEILING_BLUR

#include "background_meta.h"
#include "bn_regular_bg_items_misc_ceiling_blur.h"
#include "bn_sprite_items_thumb_misc_ceiling_blur.h"
namespace ks::background_metas {
    constexpr inline background_meta misc_ceiling_blur(
                     bn::regular_bg_items::misc_ceiling_blur,
                     bn::sprite_items::thumb_misc_ceiling_blur,
                     0xAB466140);

}

#endif  // KS_BGMETA_MISC_CEILING_BLUR
