#ifndef KS_BGMETA_SHIZUCONFESS_CLOSED
#define KS_BGMETA_SHIZUCONFESS_CLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizuconfess_closed.h"
#include "bn_regular_bg_items_thumb_shizuconfess_closed.h"
namespace ks::background_metas {
    constexpr inline background_meta shizuconfess_closed(
                     bn::regular_bg_items::shizuconfess_closed,
                     bn::regular_bg_items::thumb_shizuconfess_closed,
                     DISPLAYABLE_BITMASK_SHIZUCONFESS_CLOSED,
                     0x4898D882);

}

#endif  // KS_BGMETA_SHIZUCONFESS_CLOSED
