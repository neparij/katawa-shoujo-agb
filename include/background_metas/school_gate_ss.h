#ifndef KS_BGMETA_SCHOOL_GATE_SS
#define KS_BGMETA_SCHOOL_GATE_SS

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_school_gate_ss.h"
#include "bn_regular_bg_items_thumb_school_gate_ss.h"
namespace ks::background_metas {
    constexpr inline background_meta school_gate_ss(
                     bn::regular_bg_items::school_gate_ss,
                     bn::regular_bg_items::thumb_school_gate_ss,
                     DISPLAYABLE_BITMASK_NONE,
                     0x6AA5A24F);

}

#endif  // KS_BGMETA_SCHOOL_GATE_SS
