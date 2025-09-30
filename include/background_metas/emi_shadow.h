#ifndef KS_BGMETA_EMI_SHADOW
#define KS_BGMETA_EMI_SHADOW

#include "background_meta.h"
#include "bn_regular_bg_items_emi_shadow.h"
#include "bn_regular_bg_items_thumb_emi_shadow.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_shadow(
                     bn::regular_bg_items::emi_shadow,
                     bn::regular_bg_items::thumb_emi_shadow,
                     0x99CAF325);

}

#endif  // KS_BGMETA_EMI_SHADOW
