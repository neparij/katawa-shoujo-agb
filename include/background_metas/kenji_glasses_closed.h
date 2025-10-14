#ifndef KS_BGMETA_KENJI_GLASSES_CLOSED
#define KS_BGMETA_KENJI_GLASSES_CLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_kenji_glasses_closed.h"
#include "bn_regular_bg_items_thumb_kenji_glasses_closed.h"
namespace ks::background_metas {
    constexpr inline background_meta kenji_glasses_closed(
                     bn::regular_bg_items::kenji_glasses_closed,
                     bn::regular_bg_items::thumb_kenji_glasses_closed,
                     DISPLAYABLE_BITMASK_KENJI_GLASSES_CLOSED,
                     0xFC5B75BE);

}

#endif  // KS_BGMETA_KENJI_GLASSES_CLOSED
