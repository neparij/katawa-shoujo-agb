#ifndef KS_BGMETA_KENJI_GLASSES_FROWN
#define KS_BGMETA_KENJI_GLASSES_FROWN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_kenji_glasses_frown.h"
#include "bn_regular_bg_items_thumb_kenji_glasses_frown.h"
namespace ks::background_metas {
    constexpr inline background_meta kenji_glasses_frown(
                     bn::regular_bg_items::kenji_glasses_frown,
                     bn::regular_bg_items::thumb_kenji_glasses_frown,
                     DISPLAYABLE_BITMASK_KENJI_GLASSES_FROWN,
                     0x6EA51E11);

}

#endif  // KS_BGMETA_KENJI_GLASSES_FROWN
