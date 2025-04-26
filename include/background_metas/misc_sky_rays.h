#ifndef KS_BGMETA_MISC_SKY_RAYS
#define KS_BGMETA_MISC_SKY_RAYS

#include "background_meta.h"
#include "bn_regular_bg_items_misc_sky_rays.h"
#include "bn_regular_bg_items_thumb_misc_sky_rays.h"
namespace ks::background_metas {
    constexpr inline background_meta misc_sky_rays(
                     bn::regular_bg_items::misc_sky_rays,
                     bn::regular_bg_items::thumb_misc_sky_rays,
                     0x4C197DFC);

}

#endif  // KS_BGMETA_MISC_SKY_RAYS
