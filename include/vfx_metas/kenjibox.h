#ifndef KS_VFXMETA_KENJIBOX
#define KS_VFXMETA_KENJIBOX

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_kenjibox.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta kenjibox(
                     bn::regular_bg_items::kenjibox,
                     DISPLAYABLE_BITMASK_KENJIBOX);

}

#endif  // KS_VFXMETA_KENJIBOX
