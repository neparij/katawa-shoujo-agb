#ifndef KS_VFXMETA_CHESSBOARD
#define KS_VFXMETA_CHESSBOARD

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_chessboard.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta chessboard(
                     bn::regular_bg_items::chessboard,
                     DISPLAYABLE_BITMASK_CHESSBOARD);

}

#endif  // KS_VFXMETA_CHESSBOARD
