#ifndef KS_BGMETA_EMI_SHED_HISAO_CLOSED
#define KS_BGMETA_EMI_SHED_HISAO_CLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_shed_hisao_closed.h"
#include "bn_regular_bg_items_thumb_emi_shed_hisao_closed.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_shed_hisao_closed(
                     bn::regular_bg_items::emi_shed_hisao_closed,
                     bn::regular_bg_items::thumb_emi_shed_hisao_closed,
                     DISPLAYABLE_BITMASK_NONE,
                     0xDEDB651F);

}

#endif  // KS_BGMETA_EMI_SHED_HISAO_CLOSED
