#ifndef KS_VFXMETA_BRAILLER
#define KS_VFXMETA_BRAILLER

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_brailler.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta brailler(
                     bn::regular_bg_items::brailler,
                     DISPLAYABLE_BITMASK_BRAILLER);

}

#endif  // KS_VFXMETA_BRAILLER
