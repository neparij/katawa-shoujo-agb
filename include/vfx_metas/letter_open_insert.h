#ifndef KS_VFXMETA_LETTER_OPEN_INSERT
#define KS_VFXMETA_LETTER_OPEN_INSERT

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_letter_open_insert.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta letter_open_insert(
                     bn::regular_bg_items::letter_open_insert,
                     DISPLAYABLE_BITMASK_LETTER_OPEN_INSERT);

}

#endif  // KS_VFXMETA_LETTER_OPEN_INSERT
