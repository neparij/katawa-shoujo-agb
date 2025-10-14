#ifndef KS_VFXMETA_HANAPHONE
#define KS_VFXMETA_HANAPHONE

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanaphone.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta hanaphone(
                     bn::regular_bg_items::hanaphone,
                     DISPLAYABLE_BITMASK_HANAPHONE);

}

#endif  // KS_VFXMETA_HANAPHONE
