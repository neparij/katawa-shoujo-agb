#ifndef KS_BGMETA_TEAROOM_CHESS
#define KS_BGMETA_TEAROOM_CHESS

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_tearoom_chess.h"
#include "bn_regular_bg_items_thumb_tearoom_chess.h"
namespace ks::background_metas {
    constexpr inline background_meta tearoom_chess(
                     bn::regular_bg_items::tearoom_chess,
                     bn::regular_bg_items::thumb_tearoom_chess,
                     DISPLAYABLE_BITMASK_NONE,
                     0x7C53E11E);

}

#endif  // KS_BGMETA_TEAROOM_CHESS
