#ifndef KS_VFXMETA_PILLS
#define KS_VFXMETA_PILLS

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_pills.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta pills(
                     bn::regular_bg_items::pills,
                     DISPLAYABLE_BITMASK_PILLS);

}

#endif  // KS_VFXMETA_PILLS
