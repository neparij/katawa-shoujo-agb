#ifndef KS_BGMETA_EMI_CRY_DOWN
#define KS_BGMETA_EMI_CRY_DOWN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_cry_down.h"
#include "bn_regular_bg_items_thumb_emi_cry_down.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_cry_down(
                     bn::regular_bg_items::emi_cry_down,
                     bn::regular_bg_items::thumb_emi_cry_down,
                     DISPLAYABLE_BITMASK_EMI_CRY_DOWN,
                     0x604528B2);

}

#endif  // KS_BGMETA_EMI_CRY_DOWN
