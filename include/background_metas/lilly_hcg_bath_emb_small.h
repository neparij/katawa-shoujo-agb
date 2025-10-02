#ifndef KS_BGMETA_LILLY_HCG_BATH_EMB_SMALL
#define KS_BGMETA_LILLY_HCG_BATH_EMB_SMALL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_hcg_bath_emb_small.h"
#include "bn_regular_bg_items_thumb_lilly_hcg_bath_emb_small.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_hcg_bath_emb_small(
                     bn::regular_bg_items::lilly_hcg_bath_emb_small,
                     bn::regular_bg_items::thumb_lilly_hcg_bath_emb_small,
                     DISPLAYABLE_BITMASK_LILLY_BATH_EMB_SMALL,
                     0xA3967782);

}

#endif  // KS_BGMETA_LILLY_HCG_BATH_EMB_SMALL
