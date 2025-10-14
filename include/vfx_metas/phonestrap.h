#ifndef KS_VFXMETA_PHONESTRAP
#define KS_VFXMETA_PHONESTRAP

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_phonestrap.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta phonestrap(
                     bn::regular_bg_items::phonestrap,
                     DISPLAYABLE_BITMASK_PHONESTRAP);

}

#endif  // KS_VFXMETA_PHONESTRAP
