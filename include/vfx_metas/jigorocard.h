#ifndef KS_VFXMETA_JIGOROCARD
#define KS_VFXMETA_JIGOROCARD

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_jigorocard.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta jigorocard(
                     bn::regular_bg_items::jigorocard,
                     DISPLAYABLE_BITMASK_JIGOROCARD);

}

#endif  // KS_VFXMETA_JIGOROCARD
