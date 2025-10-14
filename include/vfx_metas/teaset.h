#ifndef KS_VFXMETA_TEASET
#define KS_VFXMETA_TEASET

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_teaset.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta teaset(
                     bn::regular_bg_items::teaset,
                     DISPLAYABLE_BITMASK_TEASET);

}

#endif  // KS_VFXMETA_TEASET
