#ifndef KS_BGMETA_TEAROOM_HISAOE_THINKCLOSED
#define KS_BGMETA_TEAROOM_HISAOE_THINKCLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_tearoom_hisaoe_thinkclosed.h"
#include "bn_regular_bg_items_thumb_tearoom_hisaoe_thinkclosed.h"
namespace ks::background_metas {
    constexpr inline background_meta tearoom_hisaoe_thinkclosed(
                     bn::regular_bg_items::tearoom_hisaoe_thinkclosed,
                     bn::regular_bg_items::thumb_tearoom_hisaoe_thinkclosed,
                     DISPLAYABLE_BITMASK_NONE,
                     0xED8AD11D);

}

#endif  // KS_BGMETA_TEAROOM_HISAOE_THINKCLOSED
