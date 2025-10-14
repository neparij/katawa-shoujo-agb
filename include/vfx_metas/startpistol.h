#ifndef KS_VFXMETA_STARTPISTOL
#define KS_VFXMETA_STARTPISTOL

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_startpistol.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta startpistol(
                     bn::regular_bg_items::startpistol,
                     DISPLAYABLE_BITMASK_INSERT_STARTPISTOL);

}

#endif  // KS_VFXMETA_STARTPISTOL
