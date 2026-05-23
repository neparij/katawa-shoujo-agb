#ifndef KS_HUGE_BG_COORDS_H
#define KS_HUGE_BG_COORDS_H

#include "bn_display.h"
#include "bn_fixed_point.h"

namespace ks::huge_bg_coords {

// Huge / composite-huge backgrounds use a 256×256 px VRAM map (32×32 cells).
// Script scroll coordinates are top-left of that window; Butano set_position /
// regular_bg_move_to_action use screen-centre-relative position.
constexpr int MAP_W = 256;
constexpr int MAP_H = 256;

inline bn::fixed_point top_left_to_position(bn::fixed top_left_x, bn::fixed top_left_y)
{
    const int dx = (int(bn::display::width()) - MAP_W) / 2;
    const int dy = (int(bn::display::height()) - MAP_H) / 2;
    return bn::fixed_point(top_left_x - dx, top_left_y - dy);
}

inline bn::fixed_point top_left_to_position(int top_left_x, int top_left_y)
{
    return top_left_to_position(bn::fixed(top_left_x), bn::fixed(top_left_y));
}

}  // namespace ks::huge_bg_coords

#endif  // KS_HUGE_BG_COORDS_H
