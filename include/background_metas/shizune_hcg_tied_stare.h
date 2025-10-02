#ifndef KS_BGMETA_SHIZUNE_HCG_TIED_STARE
#define KS_BGMETA_SHIZUNE_HCG_TIED_STARE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizune_hcg_tied_stare.h"
#include "bn_regular_bg_items_thumb_shizune_hcg_tied_stare.h"
namespace ks::background_metas {
    constexpr inline background_meta shizune_hcg_tied_stare(
                     bn::regular_bg_items::shizune_hcg_tied_stare,
                     bn::regular_bg_items::thumb_shizune_hcg_tied_stare,
                     DISPLAYABLE_BITMASK_NONE,
                     0xEF3CB195);

}

#endif  // KS_BGMETA_SHIZUNE_HCG_TIED_STARE
