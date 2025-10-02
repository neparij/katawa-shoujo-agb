#ifndef KS_BGMETA_HANAKO_MISSIONARY_CLENCH
#define KS_BGMETA_HANAKO_MISSIONARY_CLENCH

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_missionary_clench.h"
#include "bn_regular_bg_items_thumb_hanako_missionary_clench.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_missionary_clench(
                     bn::regular_bg_items::hanako_missionary_clench,
                     bn::regular_bg_items::thumb_hanako_missionary_clench,
                     DISPLAYABLE_BITMASK_HANAKO_MISSIONARY_CLENCH,
                     0xFDC595C1);

}

#endif  // KS_BGMETA_HANAKO_MISSIONARY_CLENCH
