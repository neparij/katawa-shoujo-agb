#include "bn_blending_actions.h"
#include "bn_math.h"
#include "dialog_box.h"
#include "constants.h"

#include "bn_sprite_double_size_mode.h"
#include "bn_sprite_items_ui_answerbox1.h"
#include "bn_sprite_items_ui_answerbox2.h"
#include "bn_sprite_items_ui_answerbox3.h"
#include "bn_sprite_items_ui_talkbox1.h"
#include "bn_sprite_items_ui_talkbox2.h"
#include "bn_sprite_items_ui_talkbox4.h"
#include "bn_sprite_items_ui_talkbox_actor.h"
#include "bn_sprite_items_ui_talkbox_actor_end.h"
#include "bn_sprite_items_ui_talkbox_actor_start.h"
#include "scenemanager.h"

namespace ks {
    void dialog_box_default::update() {
        if (is_question) {
            if (answers_camera.has_value() && answers_camera_action.has_value()) {
                if (answer_pause_cycle_counter < defaults::answer_camera_bounds_pause_count) {
                    answer_pause_cycle_counter++;
                } else {
                    if (answer_loop_cycle_counter < answers_camera_loop_duration) {
                        answer_loop_cycle_counter++;
                        answers_camera_action->update();
                        set_answer_sprites_visibility(answer_selected);
                    } else {
                        answer_pause_cycle_counter = 0;
                        answer_loop_cycle_counter = 0;
                    }
                }
            }

            if (bn::keypad::down_pressed() || bn::keypad::up_pressed()) {
                if (answers_camera.has_value()) {
                    answers_camera->set_x(0);
                }
                set_answer_sprites_visibility(answer_selected);
                if (bn::keypad::down_pressed()) {
                    answer_selected++;
                } else if (bn::keypad::up_pressed()) {
                    answer_selected += answers_widths.size() - 1;
                }
                answer_selected = answer_selected % answers_widths.size();
                setup_answer_camera();
                set_answer_box_blending();
                set_answers_palette();
            } else if (bn::keypad::a_pressed()) {
                finished = true;
            }
        } else {
            dialog_box::update();
        }
    }

    void dialog_box_default::show(const bool blending) {
        is_question = false;
        dialog_box::show(blending);
        if (text_boxes.empty()) {
            auto box_left = bn::sprite_items::ui_talkbox1.create_sprite(
                -ks::device::screen_width_half + 32,
                ks::device::screen_height_half - 32);
            auto box_center = bn::sprite_items::ui_talkbox2.create_sprite(
                -ks::device::screen_width_half + 128,
                ks::device::screen_height_half - 32);
            auto box_right = bn::sprite_items::ui_talkbox4.create_sprite(
                -ks::device::screen_width_half + 224,
                ks::device::screen_height_half - 32);

            box_left.set_bg_priority(1);
            box_center.set_bg_priority(1);
            box_right.set_bg_priority(1);

            box_center.set_horizontal_scale(bn::fixed(2.0));
            box_center.set_double_size_mode(bn::sprite_double_size_mode::ENABLED);

            text_boxes.push_back(bn::move(box_left));
            text_boxes.push_back(bn::move(box_center));
            text_boxes.push_back(bn::move(box_right));
        }

        actor_boxes.clear();
        title_sprites.clear();
        if (*_actor != definitions::no_char) {
            const int title_ends_x = -device::screen_width_half + 8 + _bold_text_generator->width(_actor->name());
            actor_boxes.push_back(
                bn::sprite_items::ui_talkbox_actor_start.create_sprite(-ks::device::screen_width_half + 16,
                                                                       ks::device::screen_height_half - 44));
            while (title_ends_x > -device::screen_width_half + (actor_boxes.size() * 32)) {
                actor_boxes.push_back(bn::sprite_items::ui_talkbox_actor.create_sprite(
                    -ks::device::screen_width_half + 16 + actor_boxes.size() * 32,
                    ks::device::screen_height_half - 44));
            }
            actor_boxes.push_back(bn::sprite_items::ui_talkbox_actor_end.create_sprite(
                -ks::device::screen_width_half + 16 + actor_boxes.size() * 32, ks::device::screen_height_half - 44));
            for (auto &box: actor_boxes) {
                box.set_bg_priority(1);
            }

            _bold_text_generator->set_left_alignment();
            _bold_text_generator->set_palette_item(_actor->who_color);
            _bold_text_generator->generate(-ks::device::screen_width_half + 8, ks::device::screen_height_half - 52,
                                          _actor->name(), title_sprites);
        }

        if (blending && hidden) {
            bn::blending::set_transparency_alpha(0);
            auto alpha_action = bn::blending_transparency_alpha_to_action(10, globals::transparency_alpha());
            while (!alpha_action.done()) {
                update();
                alpha_action.update();
                set_blending(true, true);
                globals::main_update();
            }
            alpha_action.reset();
            bn::blending::set_transparency_alpha(globals::transparency_alpha());
        }

        bn::blending::set_transparency_alpha(globals::transparency_alpha());
        set_blending(true, false);
        hidden = false;
    }

    void dialog_box_default::show_answers(bn::ivector<bn::string<128> > &answers) {
        BN_ASSERT(_default_text_generator != nullptr, "Default text generator is null");
        BN_ASSERT(_bold_text_generator != nullptr, "Bold text generator is null");

        is_question = true;
        finished = false;
        answer_selected = 0;

        answer_boxes.clear();
        answers_widths.clear();
        answer_sprites.clear();
        answer_sprite_indexes.clear();

        answers_camera.reset();
        answers_camera_action.reset();

        for (int i = 0; i < answers.size(); i++) {
            BN_LOG("Answer: ", answers.at(i));
            auto box_l = bn::sprite_items::ui_answerbox1.create_sprite(-64, -56 + i * 20);
            auto box_c = bn::sprite_items::ui_answerbox2.create_sprite(0, -56 + i * 20);
            auto box_r = bn::sprite_items::ui_answerbox3.create_sprite(64, -56 + i * 20);
            box_l.set_z_order(-49);
            box_c.set_z_order(-49);
            box_r.set_z_order(-49);

            box_l.set_bg_priority(1);
            box_c.set_bg_priority(1);
            box_r.set_bg_priority(1);

            answer_boxes.push_back(box_l);
            answer_boxes.push_back(box_c);
            answer_boxes.push_back(box_r);

            const int z_priority = _default_text_generator->z_order();
            _default_text_generator->set_left_alignment();
            _default_text_generator->set_z_order(-50);
            const int answer_width = _default_text_generator->width(answers.at(i));
            answers_widths.push_back(answer_width);
            if (answer_width <= answers_width_max) {
                _default_text_generator->set_one_sprite_per_character(false);
                _default_text_generator->generate(-answer_width / 2, -56 + i * 20, answers.at(i), answer_sprites);
            } else {
                _default_text_generator->set_one_sprite_per_character(true);
                _default_text_generator->generate(-answers_width_max / 2, -56 + i * 20, answers.at(i), answer_sprites);
            }
            _default_text_generator->set_z_order(z_priority);

            for (int answer_sprite_index = answer_sprite_indexes.size(); answer_sprite_index < answer_sprites.size();
                 answer_sprite_index++) {
                answer_sprite_indexes.push_back(i);
            }
        }

        setup_answer_camera();
        set_answer_box_blending();
        set_answers_palette();
        for (int i = 0; i < answers.size(); i++) {
            set_answer_sprites_visibility(i);
        }
    }

    void dialog_box_default::hide(const bool blending) {
        if (blending && !hidden) {
            bn::blending::set_transparency_alpha(globals::transparency_alpha());
            auto alpha_action = bn::blending_transparency_alpha_to_action(10, 0.0);
            while (!alpha_action.done()) {
                update();
                alpha_action.update();
                set_blending(true, true);
                globals::main_update();
            }
            alpha_action.reset();
        }

        text_boxes.clear();
        actor_boxes.clear();
        title_sprites.clear();
        text_chunk_sprites.clear();
        text_single_sprites.clear();
        hidden = true;
    }

    void dialog_box_default::set_blending(const bool boxes_blending_enabled, const bool text_blending_enabled) {
        for (auto &box: text_boxes) {
            box.set_blending_enabled(boxes_blending_enabled);
        }
        for (auto &box: actor_boxes) {
            box.set_blending_enabled(boxes_blending_enabled);
        }
        for (auto &sprite: title_sprites) {
            sprite.set_blending_enabled(text_blending_enabled);
        }
        for (auto &sprite: text_chunk_sprites) {
            sprite.set_blending_enabled(text_blending_enabled);
        }
        for (auto &sprite: text_single_sprites) {
            sprite.set_blending_enabled(text_blending_enabled);
        }
    }

    void dialog_box_default::setup_answer_camera() {
        const int answer_width = answers_widths.at(answer_selected);
        if (answer_width <= answers_width_max) {
            answers_camera.reset();
            answers_camera_action.reset();
            return;
        }

        const int camera_amplitude = answer_width - answers_width_max;
        const int camera_duration = defaults::answer_camera_duration_multiplier.multiplication(camera_amplitude).
                ceil_integer();
        answers_camera = bn::camera_ptr::create(0, 0);
        answers_camera_action = bn::camera_move_loop_action(answers_camera.value(), camera_duration, camera_amplitude,
                                                            0);
        answers_camera->set_x(0);
        answers_camera_loop_duration = camera_duration;

        for (int i = 0; i < answer_sprites.size(); i++) {
            if (answer_sprite_indexes.at(i) == answer_selected) {
                answer_sprites.at(i).set_camera(answers_camera);
            } else {
                answer_sprites.at(i).remove_camera();
            }
        }

        answer_loop_cycle_counter = 0;
        answer_pause_cycle_counter = 0;
    }

    void dialog_box_default::set_answer_box_blending() {
        for (int i = 0; i < answer_boxes.size(); i++) {
            const bool is_selected = i / 3 == answer_selected;
            answer_boxes.at(i).set_blending_enabled(!is_selected);
        }
    }

    void dialog_box_default::set_answers_palette() {
        for (int i = 0; i < answer_sprites.size(); i++) {
            const bool is_selected = answer_sprite_indexes.at(i) == answer_selected;
            answer_sprites.at(i).set_palette(is_selected
                                                 ? globals::text_palettes::beige_selected
                                                 : globals::text_palettes::beige);
        }
    }

    void dialog_box_default::set_answer_sprites_visibility(const unsigned short answer_index) {
        for (int i = 0; i < answer_sprites.size(); i++) {
            if (answer_sprite_indexes.at(i) == answer_index) {
                auto *char_sprite = &answer_sprites.at(i);
                bn::fixed_t<12> cam_pos_x = 0;
                if (answers_camera.has_value() && answer_selected == answer_index) {
                    cam_pos_x = answers_camera->position().x();
                }
                const auto relative_position = bn::abs(char_sprite->position().x() - 4 - cam_pos_x);
                if (relative_position > answers_width_max / 2) {
                    char_sprite->set_visible(false);
                } else {
                    char_sprite->set_visible(true);
                }
            }
        }
    }

    void dialog_box_default::reset_answers() {
        answer_boxes.clear();
        answer_sprites.clear();
        answer_sprite_indexes.clear();
    }
}
