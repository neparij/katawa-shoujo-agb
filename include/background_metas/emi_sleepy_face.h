#ifndef KS_BGMETA_EMI_SLEEPY_FACE
#define KS_BGMETA_EMI_SLEEPY_FACE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_emi_sleepy_face.h"
#include "bn_regular_bg_items_thumb_emi_sleepy_face.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_sleepy_face(
                     bn::regular_bg_items::emi_sleepy_face,
                     bn::regular_bg_items::thumb_emi_sleepy_face,
                     DISPLAYABLE_BITMASK_EMI_SLEEPY_FACE,
                     0x9B1DCAFC);

}

#endif  // KS_BGMETA_EMI_SLEEPY_FACE
