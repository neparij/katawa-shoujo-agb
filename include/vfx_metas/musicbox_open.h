#ifndef KS_VFXMETA_MUSICBOX_OPEN
#define KS_VFXMETA_MUSICBOX_OPEN

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_musicbox_open.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta musicbox_open(
                     bn::regular_bg_items::musicbox_open,
                     DISPLAYABLE_BITMASK_MUSICBOX_OPEN);

}

#endif  // KS_VFXMETA_MUSICBOX_OPEN
