#ifndef KS_BGMETA_EMI_BED_NORMAL
#define KS_BGMETA_EMI_BED_NORMAL

#include "background_meta.h"
#include "bn_regular_bg_items_emi_bed_normal.h"
#include "bn_regular_bg_items_thumb_emi_bed_normal.h"
namespace ks::background_metas {
    constexpr inline background_meta emi_bed_normal(
                     bn::regular_bg_items::emi_bed_normal,
                     bn::regular_bg_items::thumb_emi_bed_normal,
                     0x460F927F);

}

#endif  // KS_BGMETA_EMI_BED_NORMAL
