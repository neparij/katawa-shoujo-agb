#ifndef KS_BGMETA_SHIZUNE_HCG_TIED_SMILE_SMALL
#define KS_BGMETA_SHIZUNE_HCG_TIED_SMILE_SMALL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizune_hcg_tied_smile_small.h"
#include "bn_regular_bg_items_thumb_shizune_hcg_tied_smile_small.h"
namespace ks::background_metas {
    constexpr inline background_meta shizune_hcg_tied_smile_small(
                     bn::regular_bg_items::shizune_hcg_tied_smile_small,
                     bn::regular_bg_items::thumb_shizune_hcg_tied_smile_small,
                     DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_SMILE_SMALL,
                     0xEA7DA516);

}

#endif  // KS_BGMETA_SHIZUNE_HCG_TIED_SMILE_SMALL
