#ifndef KS_BGMETA_HANAKO_BED_CROTCH_GLANCE
#define KS_BGMETA_HANAKO_BED_CROTCH_GLANCE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_bed_crotch_glance.h"
#include "bn_regular_bg_items_thumb_hanako_bed_crotch_glance.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_bed_crotch_glance(
                     bn::regular_bg_items::hanako_bed_crotch_glance,
                     bn::regular_bg_items::thumb_hanako_bed_crotch_glance,
                     DISPLAYABLE_BITMASK_HANAKO_BED_CROTCH_GLANCE,
                     0x37493D30);

}

#endif  // KS_BGMETA_HANAKO_BED_CROTCH_GLANCE
