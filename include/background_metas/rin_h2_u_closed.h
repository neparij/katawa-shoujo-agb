#ifndef KS_BGMETA_RIN_H2_U_CLOSED
#define KS_BGMETA_RIN_H2_U_CLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_h2_u_closed.h"
#include "bn_regular_bg_items_thumb_rin_h2_u_closed.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_h2_u_closed(
                     bn::regular_bg_items::rin_h2_u_closed,
                     bn::regular_bg_items::thumb_rin_h2_u_closed,
                     DISPLAYABLE_BITMASK_NONE,
                     0x05D3D33D);

}

#endif  // KS_BGMETA_RIN_H2_U_CLOSED
