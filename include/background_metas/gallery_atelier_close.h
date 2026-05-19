#ifndef KS_BGMETA_GALLERY_ATELIER_CLOSE
#define KS_BGMETA_GALLERY_ATELIER_CLOSE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_gallery_atelier_close.h"
#include "bn_regular_bg_items_thumb_gallery_atelier_close.h"
namespace ks::background_metas {
    constexpr inline background_meta gallery_atelier_close(
                     bn::regular_bg_items::gallery_atelier_close,
                     bn::regular_bg_items::thumb_gallery_atelier_close,
                     DISPLAYABLE_BITMASK_NONE,
                     0x60272054);

}

#endif  // KS_BGMETA_GALLERY_ATELIER_CLOSE
