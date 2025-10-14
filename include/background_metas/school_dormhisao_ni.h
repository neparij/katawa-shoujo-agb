#ifndef KS_BGMETA_SCHOOL_DORMHISAO_NI
#define KS_BGMETA_SCHOOL_DORMHISAO_NI

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_dormhisao_ni.h"
#include "bn_regular_bg_items_thumb_school_dormhisao_ni.h"
namespace ks::background_metas {
    constexpr inline background_meta school_dormhisao_ni(
                     bn::regular_bg_items::school_dormhisao_ni,
                     bn::regular_bg_items::thumb_school_dormhisao_ni,
                     DISPLAYABLE_BITMASK_NONE,
                     0xF16BFFB8);

}

#endif  // KS_BGMETA_SCHOOL_DORMHISAO_NI
