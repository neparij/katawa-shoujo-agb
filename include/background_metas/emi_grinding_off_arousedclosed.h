#ifndef KS_BGMETA_EMI_GRINDING_OFF_AROUSEDCLOSED
#define KS_BGMETA_EMI_GRINDING_OFF_AROUSEDCLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_grinding_off_arousedclosed.h"
#include "bn_regular_bg_items_thumb_emi_grinding_off_arousedclosed.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_grinding_off_arousedclosed(
                     bn::regular_bg_items::emi_grinding_off_arousedclosed,
                     bn::regular_bg_items::thumb_emi_grinding_off_arousedclosed,
                     DISPLAYABLE_BITMASK_EMI_GRINDING_OFF_AROUSEDCLOSED,
                     0x7A573FB7);

}

#endif  // KS_BGMETA_EMI_GRINDING_OFF_AROUSEDCLOSED
