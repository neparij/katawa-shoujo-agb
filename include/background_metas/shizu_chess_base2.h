#ifndef KS_BGMETA_SHIZU_CHESS_BASE2
#define KS_BGMETA_SHIZU_CHESS_BASE2

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_chess_base2.h"
#include "bn_regular_bg_items_thumb_shizu_chess_base2.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_chess_base2(
                     bn::regular_bg_items::shizu_chess_base2,
                     bn::regular_bg_items::thumb_shizu_chess_base2,
                     DISPLAYABLE_BITMASK_SHIZU_CHESS_BASE2,
                     0x532DB4FC);

}

#endif  // KS_BGMETA_SHIZU_CHESS_BASE2
