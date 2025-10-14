#ifndef KS_VFXMETA_SHANGPAI
#define KS_VFXMETA_SHANGPAI

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shangpai.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta shangpai(
                     bn::regular_bg_items::shangpai,
                     DISPLAYABLE_BITMASK_SHANGPAI);

}

#endif  // KS_VFXMETA_SHANGPAI
