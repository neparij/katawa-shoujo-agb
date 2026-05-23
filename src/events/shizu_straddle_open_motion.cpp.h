#ifndef SHIZU_STRADDLE_OPEN_MOTION_CPP_H
#define SHIZU_STRADDLE_OPEN_MOTION_CPP_H

#include "bn_fixed.h"
#include "huge_bg_coords.h"

namespace ks::shizu_straddle_open_motion {

// composite_huge shizu_straddle_open: 477×512 content pasted at x=17 in 512×512 map.
// Ren'Py (1920×1080): height-fit display ≈1005×1080, xalign pans across (display_w − viewport_w).
constexpr int CONTENT_W = 477;
constexpr int CONTENT_H = 512;
constexpr int PASTE_X = 17;
constexpr int VIEWPORT_W = 240;
constexpr int VIEWPORT_H = 160;
constexpr int PAN_DURATION = 960;  // Ren'Py easein 16.0 s at 60 Hz

// Map scroll x = PASTE_X + xalign * (CONTENT_W − VIEWPORT_W); top-left is negated (see rin_h2).
inline int top_left_xalign(bn::fixed align) {
    return -(PASTE_X + (align * (CONTENT_W - VIEWPORT_W)).integer());
}

inline int top_left_yalign(bn::fixed align) {
    return -((align * (CONTENT_H - VIEWPORT_H)).integer());
}

inline bn::fixed_point position(bn::fixed xalign, bn::fixed yalign) {
    return huge_bg_coords::top_left_to_position(
        top_left_xalign(xalign), top_left_yalign(yalign));
}

}  // namespace ks::shizu_straddle_open_motion

#endif  // SHIZU_STRADDLE_OPEN_MOTION_CPP_H
