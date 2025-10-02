#ifndef KS_BGMETA_TEAROOM_HISAOE_OUTSIDE
#define KS_BGMETA_TEAROOM_HISAOE_OUTSIDE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_tearoom_hisaoe_outside.h"
#include "bn_regular_bg_items_thumb_tearoom_hisaoe_outside.h"
namespace ks::background_metas {
    constexpr inline background_meta tearoom_hisaoe_outside(
                     bn::regular_bg_items::tearoom_hisaoe_outside,
                     bn::regular_bg_items::thumb_tearoom_hisaoe_outside,
                     DISPLAYABLE_BITMASK_NONE,
                     0xBB1C187A);

}

#endif  // KS_BGMETA_TEAROOM_HISAOE_OUTSIDE
