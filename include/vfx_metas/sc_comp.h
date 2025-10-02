#ifndef KS_VFXMETA_SC_COMP
#define KS_VFXMETA_SC_COMP

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_sc_comp.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta sc_comp(
                     bn::regular_bg_items::sc_comp,
                     DISPLAYABLE_BITMASK_SC_COMP);

}

#endif  // KS_VFXMETA_SC_COMP
