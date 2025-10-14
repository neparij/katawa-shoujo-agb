#ifndef KS_BGMETA_EMI_SHED_BASE2
#define KS_BGMETA_EMI_SHED_BASE2

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_shed_base2.h"
#include "bn_regular_bg_items_thumb_emi_shed_base2.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_shed_base2(
                     bn::regular_bg_items::emi_shed_base2,
                     bn::regular_bg_items::thumb_emi_shed_base2,
                     DISPLAYABLE_BITMASK_NONE,
                     0xC494075B);

}

#endif  // KS_BGMETA_EMI_SHED_BASE2
