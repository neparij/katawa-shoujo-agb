#ifndef KS_BGMETA_GALLERY_EXT
#define KS_BGMETA_GALLERY_EXT

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_gallery_ext.h"
#include "bn_regular_bg_items_thumb_gallery_ext.h"
namespace ks::background_metas {
    constexpr inline background_meta gallery_ext(
                     bn::regular_bg_items::gallery_ext,
                     bn::regular_bg_items::thumb_gallery_ext,
                     DISPLAYABLE_BITMASK_NONE,
                     0x3ED27C41);

}

#endif  // KS_BGMETA_GALLERY_EXT
