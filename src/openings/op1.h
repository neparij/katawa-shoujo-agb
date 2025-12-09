#ifndef OP1_H
#define OP1_H
#include "bn_blending_actions.h"
#include "bn_regular_bg_item.h"
#include "bn_sprite_palette_item.h"
#include "bn_string_view.h"
#include "bn_fixed.h"
#include "bn_vector.h"
#include "bn_optional.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"

namespace ks {

    constexpr short op_heartbeat = 136;

    class GameOpening final {
    public:
        GameOpening() = default;

        void run();

    private:
        void update();
        void on_heartbeat();
        void switch_bg_stage(const bn::regular_bg_item &transition_bg_item,
                             bool persist = false,
                             int in_duration = 60,
                             int out_duration = 60);
        void create_credits_block(bn::fixed x,
                                  bn::fixed y,
                                  const bn::sprite_palette_item &header_palette_item,
                                  const bn::sprite_palette_item &caption_palette_item,
                                  const bn::string_view &header,
                                  const bn::string_view &caption_0,
                                  const bn::string_view &caption_1 = "",
                                  const bn::string_view &caption_2 = "",
                                  const bn::string_view &caption_3 = "",
                                  const bn::string_view &caption_4 = "");
        void fadein_text();
        void fadeout_text();
        void replace_or_create_main_bg_item(const bn::regular_bg_item& bg_item, bn::fixed x, bn::fixed y);
        void create_stage_cardiogram();
        void create_stage_ivdrip();
        void create_stage_table();
        void create_stage_clock();
        void create_stage_end();

        int frame_counter = 0;
        short heartbeat_frame_counter = -16;
        short heartbeat_index = 0;
        short bg_stage = 0;
        short opening_fade_duration = 260;
        bool outro = false;
        bool is_finished = false;
        bn::fixed scene_offset_x = 0;
        bn::optional<bn::blending_transparency_alpha_to_action> blending_action{};
        bn::vector<bn::sprite_move_to_action, 16> text_move_actions;

        bn::optional<bn::regular_bg_ptr> cardiogram_peak_bg{};
        bn::optional<bn::sprite_ptr> cardio_sprite{};
        short cardio_peak_index = -1;

        bn::optional<bn::regular_bg_ptr> ivdrip_additional_bg{};
        bn::optional<bn::sprite_ptr> ivdrip_sprite{};

        bn::optional<bn::regular_bg_ptr> clock_additional_bg{};
        short clock_second_index = -2;
    };
}

#endif //OP1_H
