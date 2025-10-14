#ifndef KS_BGMETA_RIN_WET_FACE_UP
#define KS_BGMETA_RIN_WET_FACE_UP

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_rin_wet_face_up.h"
#include "bn_regular_bg_items_thumb_rin_wet_face_up.h"
namespace ks::background_metas {
    constexpr inline background_meta rin_wet_face_up(
                     bn::regular_bg_items::rin_wet_face_up,
                     bn::regular_bg_items::thumb_rin_wet_face_up,
                     DISPLAYABLE_BITMASK_RIN_WET_FACE_UP,
                     0x820FC466);

}

#endif  // KS_BGMETA_RIN_WET_FACE_UP
