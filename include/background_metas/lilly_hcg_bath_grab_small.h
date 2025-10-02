#ifndef KS_BGMETA_LILLY_HCG_BATH_GRAB_SMALL
#define KS_BGMETA_LILLY_HCG_BATH_GRAB_SMALL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_hcg_bath_grab_small.h"
#include "bn_regular_bg_items_thumb_lilly_hcg_bath_grab_small.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_hcg_bath_grab_small(
                     bn::regular_bg_items::lilly_hcg_bath_grab_small,
                     bn::regular_bg_items::thumb_lilly_hcg_bath_grab_small,
                     DISPLAYABLE_BITMASK_LILLY_BATH_GRAB_SMALL,
                     0x3B0501C6);

}

#endif  // KS_BGMETA_LILLY_HCG_BATH_GRAB_SMALL
