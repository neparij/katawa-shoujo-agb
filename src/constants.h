#ifndef KS_CONSTANTS_H
#define KS_CONSTANTS_H

namespace ks
{
    namespace device {
        const int screen_width = 240;
        const int screen_height = 160;
        const int screen_width_half = screen_width / 2;
        const int screen_height_half = screen_height / 2;
    } // namespace device


    namespace defaults {
        const int text_render_char_ticks = 13000;
        const int text_render_skip_ticks = 10000;
        const int text_render_max_lines_count = 3;
        const double answer_camera_duration_multiplier = 1.3;
        const int answer_camera_bounds_pause_count = 70;
    } // namespace defaults

    namespace system {
        const int allocate_iterators = 2;
        const int interator_size = 1024;
    }
}

#endif
