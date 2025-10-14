#ifndef KS_VFXMETA_MUSICBOX_CLOSED
#define KS_VFXMETA_MUSICBOX_CLOSED

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_musicbox_closed.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta musicbox_closed(
                     bn::regular_bg_items::musicbox_closed,
                     DISPLAYABLE_BITMASK_MUSICBOX_CLOSED);

}

#endif  // KS_VFXMETA_MUSICBOX_CLOSED
