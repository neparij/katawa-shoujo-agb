#ifndef RIN_H2_MOTION_CPP_H
#define RIN_H2_MOTION_CPP_H

#include "bn_fixed.h"
#include "huge_bg_coords.h"

namespace ks::rin_h2_motion {

// Content is pasted at x=136 in the 512×512 map; top-left scroll to show it at screen x=0.
constexpr int RIN_H2_TOP_LEFT_X = -136;

inline int top_left_yalign(bn::fixed align) {
    return -((align * (270 - 160)).integer());
}

inline bn::fixed_point position(bn::fixed top_left_x, bn::fixed top_left_y) {
    return huge_bg_coords::top_left_to_position(top_left_x, top_left_y);
}

inline bn::fixed_point position_for_yalign(bn::fixed align) {
    return position(RIN_H2_TOP_LEFT_X, top_left_yalign(align));
}

}  // namespace ks::rin_h2_motion

#endif  // RIN_H2_MOTION_CPP_H
