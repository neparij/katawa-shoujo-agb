#ifndef KS_VFXMETA_LETTER_INSERT
#define KS_VFXMETA_LETTER_INSERT

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_letter_insert.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta letter_insert(
                     bn::regular_bg_items::letter_insert,
                     DISPLAYABLE_BITMASK_LETTER_INSERT);

}

#endif  // KS_VFXMETA_LETTER_INSERT
