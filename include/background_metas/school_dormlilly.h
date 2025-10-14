#ifndef KS_BGMETA_SCHOOL_DORMLILLY
#define KS_BGMETA_SCHOOL_DORMLILLY

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_dormlilly.h"
#include "bn_regular_bg_items_thumb_school_dormlilly.h"
namespace ks::background_metas {
    constexpr inline background_meta school_dormlilly(
                     bn::regular_bg_items::school_dormlilly,
                     bn::regular_bg_items::thumb_school_dormlilly,
                     DISPLAYABLE_BITMASK_NONE,
                     0x6D8BF5DD);

}

#endif  // KS_BGMETA_SCHOOL_DORMLILLY
