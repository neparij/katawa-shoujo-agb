#ifndef KS_BGMETA_SHIZU_CHESS_BASE
#define KS_BGMETA_SHIZU_CHESS_BASE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_chess_base.h"
#include "bn_regular_bg_items_thumb_shizu_chess_base.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_chess_base(
                     bn::regular_bg_items::shizu_chess_base,
                     bn::regular_bg_items::thumb_shizu_chess_base,
                     DISPLAYABLE_BITMASK_SHIZU_CHESS_BASE,
                     0x6A6B70F4);

}

#endif  // KS_BGMETA_SHIZU_CHESS_BASE
