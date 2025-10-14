#ifndef KS_BGMETA_LILLY_HOSPITAL
#define KS_BGMETA_LILLY_HOSPITAL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_hospital.h"
#include "bn_regular_bg_items_thumb_lilly_hospital.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_hospital(
                     bn::regular_bg_items::lilly_hospital,
                     bn::regular_bg_items::thumb_lilly_hospital,
                     DISPLAYABLE_BITMASK_LILLY_HOSPITAL,
                     0xE02C5A39);

}

#endif  // KS_BGMETA_LILLY_HOSPITAL
