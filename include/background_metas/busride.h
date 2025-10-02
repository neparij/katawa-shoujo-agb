#ifndef KS_BGMETA_BUSRIDE
#define KS_BGMETA_BUSRIDE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_busride.h"
#include "bn_regular_bg_items_thumb_busride.h"
namespace ks::background_metas {
    constexpr inline background_meta busride(
                     bn::regular_bg_items::busride,
                     bn::regular_bg_items::thumb_busride,
                     DISPLAYABLE_BITMASK_NONE,
                     0x8F2AB0B8);

}

#endif  // KS_BGMETA_BUSRIDE
