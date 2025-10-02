#ifndef KS_VFXMETA_WINE
#define KS_VFXMETA_WINE

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_wine.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta wine(
                     bn::regular_bg_items::wine,
                     DISPLAYABLE_BITMASK_WINE);

}

#endif  // KS_VFXMETA_WINE
