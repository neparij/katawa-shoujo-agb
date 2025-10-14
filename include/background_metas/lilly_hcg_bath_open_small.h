#ifndef KS_BGMETA_LILLY_HCG_BATH_OPEN_SMALL
#define KS_BGMETA_LILLY_HCG_BATH_OPEN_SMALL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_hcg_bath_open_small.h"
#include "bn_regular_bg_items_thumb_lilly_hcg_bath_open_small.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_hcg_bath_open_small(
                     bn::regular_bg_items::lilly_hcg_bath_open_small,
                     bn::regular_bg_items::thumb_lilly_hcg_bath_open_small,
                     DISPLAYABLE_BITMASK_LILLY_BATH_OPEN_SMALL,
                     0x8FCEC6A8);

}

#endif  // KS_BGMETA_LILLY_HCG_BATH_OPEN_SMALL
