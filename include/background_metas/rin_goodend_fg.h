#ifndef KS_BGMETA_RIN_GOODEND_FG
#define KS_BGMETA_RIN_GOODEND_FG

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_goodend_fg.h"
#include "bn_regular_bg_items_thumb_rin_goodend_fg.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_goodend_fg(
                     bn::regular_bg_items::rin_goodend_fg,
                     bn::regular_bg_items::thumb_rin_goodend_fg,
                     DISPLAYABLE_BITMASK_NONE,
                     0xDFA80E3C);

}

#endif  // KS_BGMETA_RIN_GOODEND_FG
