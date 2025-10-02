#ifndef KS_BGMETA_EMI_SHED_HISAO_NEUTRAL
#define KS_BGMETA_EMI_SHED_HISAO_NEUTRAL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_shed_hisao_neutral.h"
#include "bn_regular_bg_items_thumb_emi_shed_hisao_neutral.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_shed_hisao_neutral(
                     bn::regular_bg_items::emi_shed_hisao_neutral,
                     bn::regular_bg_items::thumb_emi_shed_hisao_neutral,
                     DISPLAYABLE_BITMASK_NONE,
                     0x1F81304F);

}

#endif  // KS_BGMETA_EMI_SHED_HISAO_NEUTRAL
