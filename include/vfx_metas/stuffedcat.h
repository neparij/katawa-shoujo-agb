#ifndef KS_VFXMETA_STUFFEDCAT
#define KS_VFXMETA_STUFFEDCAT

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_stuffedcat.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta stuffedcat(
                     bn::regular_bg_items::stuffedcat,
                     DISPLAYABLE_BITMASK_STUFFEDCAT);

}

#endif  // KS_VFXMETA_STUFFEDCAT
