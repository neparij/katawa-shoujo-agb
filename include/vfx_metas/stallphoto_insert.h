#ifndef KS_VFXMETA_STALLPHOTO_INSERT
#define KS_VFXMETA_STALLPHOTO_INSERT

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_stallphoto_insert.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta stallphoto_insert(
                     bn::regular_bg_items::stallphoto_insert,
                     DISPLAYABLE_BITMASK_STALLPHOTO_INSERT);

}

#endif  // KS_VFXMETA_STALLPHOTO_INSERT
