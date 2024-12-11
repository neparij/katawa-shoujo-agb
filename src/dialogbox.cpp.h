#ifndef KS_DIALOGBOX_H
#define KS_DIALOGBOX_H

#include "bn_blending.h"
#include "bn_blending_actions.h"
#include "bn_camera_actions.h"
#include "bn_camera_ptr.h"
#include "bn_core.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_sprite_palette_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_string.h"
#include "bn_rect_window.h"
#include "bn_timer.h"

#include "bn_memory.h"

#include "constants.h"
#include "globals.h"
#include "gsmplayer/player.h"
#include "sequence/dialogitem.h"

#include "bn_sprite_items_ui_answerbox1.h"
#include "bn_sprite_items_ui_answerbox2.h"
#include "bn_sprite_items_ui_answerbox3.h"
#include "bn_sprite_items_ui_talkbox1.h"
#include "bn_sprite_items_ui_talkbox1_e.h"
#include "bn_sprite_items_ui_talkbox2.h"
#include "bn_sprite_items_ui_talkbox2_e.h"
#include "bn_sprite_items_ui_talkbox3.h"
#include "bn_sprite_items_ui_talkbox4.h"

#include <BN_LOG.h>
#include <bn_size.h>
#include <bn_sprite_actions.h>

#include "bn_sprite_items_variable_16x16_font_beige.h"
#include "bn_sprite_items_variable_16x16_font_beige_selected.h"

namespace ks
{
    enum class DialogState {
        Idle,
        Writing,
        WaitingForInput,
        QuestionActive,
    };

    class DialogBox
    {
    public:
        DialogBox(bn::sprite_text_generator* text_generator, const bn::sprite_font& font)
            : _text_generator(text_generator),
            _font(font),
            original_palette_item(_text_generator->palette_item()),
            beige_palette_item(bn::sprite_items::variable_16x16_font_beige.palette_item()),
            beige_selected_palette_item(bn::sprite_items::variable_16x16_font_beige_selected.palette_item())
        {
            reset_title();
            reset_message();
        }



        bool is_finished() {
            return _is_finished;
        }

        void reset_title() {
            _title_sprites.clear();
        }

        void reset_message() {
            _is_finished = false;
            _is_question = false;
            _text_render_timer.restart();
            _text_render_char_xpos = 0;
            _text_render_line = 0;
            _is_writing = false;
            _is_immediately = false;
            _word_buffer.clear();

            _animated_text_sprites.clear();
            _finalized_text_sprites.clear();
            _answers_sprites.clear();
        }

        void reset_question() {
            _is_finished = false;
            _is_question = true;
            for (auto answerbox : answerboxes_l) {
                answerbox.reset();
            }
            for (auto answerbox : answerboxes_c) {
                answerbox.reset();
            }
            for (auto answerbox : answerboxes_r) {
                answerbox.reset();
            }
            answerboxes_l.clear();
            answerboxes_c.clear();
            answerboxes_r.clear();
            _answers_sprites.clear();
            _answers_sprites_answer_index.clear();
            _answers_widths.clear();
            _answer_selected = 0;
        }

        void reset() {
            reset_title();
            reset_message();
            reset_question();
            talkbox1.reset();
            talkbox2.reset();
            talkbox3.reset();
            talkbox4.reset();
        }

        void set_blending(bool enabled) {
            talkbox1->set_blending_enabled(enabled);
            talkbox2->set_blending_enabled(enabled);
            talkbox3->set_blending_enabled(enabled);
            talkbox4->set_blending_enabled(enabled);

            for (auto s : _title_sprites) {
                s.set_blending_enabled(true);
            }
            for (auto s : _finalized_text_sprites) {
                s.set_blending_enabled(true);
            }
            for (auto s : _animated_text_sprites) {
                s.set_blending_enabled(true);
            }
        }

        void set_show_talkboxes(bool visible) {
            talkbox1->set_visible(visible);
            talkbox2->set_visible(visible);
            talkbox3->set_visible(visible);
            talkbox4->set_visible(visible);
        }

        void hide_blend() {
            bn::blending::set_transparency_alpha(0.7);
            auto alpha_action = bn::blending_transparency_alpha_to_action(10, 0.0);
            set_blending(true);
            while (!alpha_action.done()) {
                alpha_action.update();
                ks::globals::main_update();
            }

            set_blending(false);
            alpha_action.reset();
            set_show_talkboxes(false);
            reset_title();
            reset_message();
            _hidden = true;
        }

        void show_blend() {
            bn::blending::set_transparency_alpha(0);
            auto alpha_action = bn::blending_transparency_alpha_to_action(10, 0.7);
            set_blending(true);
            set_show_talkboxes(true);
            while (!alpha_action.done()) {
                alpha_action.update();
                ks::globals::main_update();
            }
            alpha_action.reset();
            bn::blending::set_transparency_alpha(0.7);
            _hidden = false;
        }

        void show(bn::string<16> actor, bn::string_view message)
        {
            reset_title();
            reset_message();
            reset_question();

            if (actor.size() == 0) {
                talkbox1 = bn::sprite_items::ui_talkbox1_e.create_sprite(-ks::device::screen_width_half + 32, ks::device::screen_height_half - 32);
                talkbox2 = bn::sprite_items::ui_talkbox2_e.create_sprite(-ks::device::screen_width_half + 32 + 64, ks::device::screen_height_half - 32);
            } else {
                talkbox1 = bn::sprite_items::ui_talkbox1.create_sprite(-ks::device::screen_width_half + 32, ks::device::screen_height_half - 32);
                talkbox2 = bn::sprite_items::ui_talkbox2.create_sprite(-ks::device::screen_width_half + 32 + 64, ks::device::screen_height_half - 32);
            }
            talkbox3 = bn::sprite_items::ui_talkbox3.create_sprite(-ks::device::screen_width_half + 32 + 128, ks::device::screen_height_half - 32);
            talkbox4 = bn::sprite_items::ui_talkbox4.create_sprite(-ks::device::screen_width_half + 32 + 192, ks::device::screen_height_half - 32);

            set_blending(true);
            _actor = actor;
            _remaining_message = message;
            BN_LOG("_remaining_message: ", _remaining_message.substr(0, 64));

            _text_generator->set_one_sprite_per_character(false);
            _text_generator->set_left_alignment();
            _text_generator->set_palette_item(original_palette_item);
            _text_generator->generate(-ks::device::screen_width_half + 8, ks::device::screen_height_half - 52, _actor, _title_sprites);

            if (_hidden) {
                show_blend();
            } else {
                bn::blending::set_transparency_alpha(0.7);
            }

            BN_LOG("BEFORE RENDER FIRST LINE");
            render_message_line(0);
            BN_LOG("AFTER RENDER FIRST LINE");
        }

        void show_question(bn::vector<bn::string<128>, 5>& answers) {
            reset_question();
            _text_generator->set_one_sprite_per_character(true);
            _text_generator->set_z_order(-50);
            // _text_generator->set_center_alignment();
            _text_generator->set_left_alignment();
            // _text_generator->set_palette_item(beige_palette_item);

            unsigned short last_answer_sprite_index = 0;
            for (int i = 0; i < answers.size(); i++) {
                auto box_l = bn::sprite_items::ui_answerbox1.create_sprite(-64, -56 + i * 20);
                auto box_c = bn::sprite_items::ui_answerbox2.create_sprite(0, -56 + i * 20);
                auto box_r = bn::sprite_items::ui_answerbox3.create_sprite(64, -56 + i * 20);
                box_l.set_z_order(-49);
                box_c.set_z_order(-49);
                box_r.set_z_order(-49);
                answerboxes_l.push_back(box_l);
                answerboxes_c.push_back(box_c);
                answerboxes_r.push_back(box_r);
                // // TODO: Use stringview?
                // _text_generator->generate(0, -56 + i * 20, answers.at(i), _answers_sprites);
                // _answers_widths.push_back(_text_generator->width(answers.at(i)));
                int answer_width = _text_generator->width(answers.at(i));
                _answers_widths.push_back(_text_generator->width(answers.at(i)));
                if (answer_width <= _answers_half_width * 2) {
                    _text_generator->generate(-answer_width / 2, -56 + i * 20, answers.at(i), _answers_sprites);
                } else {
                    _text_generator->generate(-_answers_half_width, -56 + i * 20, answers.at(i), _answers_sprites);
                }
                for (int spr_num = last_answer_sprite_index; spr_num < _answers_sprites.size(); spr_num++) {
                    _answers_sprites_answer_index.push_back(i);
                    last_answer_sprite_index = spr_num + 1;
                }
            }

            setup_answer_camera();
            set_answer_box_blending();
            set_answers_palette();
            for (int i = 0; i < answers.size(); i++) {
                set_answer_sprites_visibility(i);
            }
        }

        void move_answer_camera_to_start() {
            if (_answers_camera.has_value()) {
                _answers_camera->set_x(0);
                // ks::globals::main_update();
            }
        }

        void setup_answer_camera() {
            int answer_width = _answers_widths.at(_answer_selected);
            if (answer_width <= _answers_half_width * 2) {
                _answers_camera.reset();
                _answers_camera_action.reset();
                return;
            }

            int camera_amplitude = answer_width - _answers_half_width * 2;
            int camera_duration = camera_amplitude * ks::defaults::answer_camera_duration_multiplier;
            _answers_camera = bn::camera_ptr::create(0,0);
            _answers_camera_action = bn::camera_move_loop_action(_answers_camera.value(), camera_duration, camera_amplitude, 0);
            _answers_camera->set_x(0);
            _answers_camera_loop_duration = camera_duration;

            for (int i = 0; i < _answers_sprites.size(); i++) {
                if (_answers_sprites_answer_index.at(i) == _answer_selected) {
                    _answers_sprites.at(i).set_camera(_answers_camera);
                } else {
                    _answers_sprites.at(i).remove_camera();
                }
            }

            _answer_loop_cycle_counter = 0;
            _answer_pause_cycle_counter = 0;
        }

        void set_answer_box_blending() {
            for (int i = 0; i < answerboxes_l.size(); i++) {
                bool is_selected = i == _answer_selected;
                answerboxes_l.at(i)->set_blending_enabled(!is_selected);
                answerboxes_c.at(i)->set_blending_enabled(!is_selected);
                answerboxes_r.at(i)->set_blending_enabled(!is_selected);
            }
        }

        void set_answers_palette() {
            for (int i = 0; i < _answers_sprites.size(); i++) {
                bool is_selected = _answers_sprites_answer_index.at(i) == _answer_selected;
                _answers_sprites.at(i).set_palette(is_selected ? beige_selected_palette_item : beige_palette_item);
            }
        }

        void set_answer_sprites_visibility(unsigned short answer_index) {
            for (int i = 0; i < _answers_sprites.size(); i++) {
                if (_answers_sprites_answer_index.at(i) == answer_index) {
                    auto* char_sprite = &_answers_sprites.at(i);
                    bn::fixed_t<12> cam_pos_x = 0;
                    if (_answers_camera.has_value() && _answer_selected == answer_index) {
                        cam_pos_x = _answers_camera->position().x();
                    }
                    auto relative_position = bn::abs(char_sprite->position().x() - 4 - cam_pos_x);
                    if (relative_position > _answers_half_width) {
                        char_sprite->set_visible(false);
                    } else {
                        char_sprite->set_visible(true);
                    }
                }
            }
        }

        int get_answer_index() {
            return _answer_selected;
        }


        void BN_CODE_IWRAM render_message_line(int cursor) {
            const int max_width = ks::device::screen_width - 20;
            const unsigned char space_width = _text_generator->width(" ");

            if (_text_render_line == 0) {
                // Delete all text sprites on the first line of each page.
                reset_message();
            } else {
                _text_render_timer.restart();
                // auto finalized_line = bn::string<256>((_actor.size() != 0 && _text_render_prev_line_index == 0) ? "\"" : "");
                // auto finalized_index = _finalized_text_sprites.size();
                // finalized_line.append(_remaining_message.substr(_text_render_prev_line_index, _text_render_prev_line_length));
                bn::string_view finalized_line(_remaining_message.substr(_text_render_prev_line_index, _text_render_prev_line_length));
                bool quoted_start = _actor.size() != 0 && _text_render_prev_line_index == 0;

                BN_LOG("finalized_line: ", finalized_line.substr(0, 64));
                if (quoted_start) {
                    render_finalized_by_chunks_with_updates((_text_render_line - 1) * 12, finalized_line, bn::string_view("\""));
                } else {
                    render_finalized_by_chunks_with_updates((_text_render_line - 1) * 12, finalized_line);
                }
                _animated_text_sprites.clear();
                ks::globals::main_update();
            }

            unsigned int cursor_i = cursor;
            unsigned char cursor_x = 0;
            unsigned char word_width = 0;
            bool line_end = false;
            bool is_eol = false;
            bool is_space = false;
            bool is_newline = false;
            bool quoted_start = false;
            bool quoted_end = false;

            if (_actor.size() != 0 && cursor == 0) {
                _word_buffer.append("\"");
                quoted_start = true;
            }

            while (!line_end) {
                unsigned char first_byte = static_cast<unsigned char>(_remaining_message.at(cursor_i));
                int char_length = get_char_size(first_byte);

                bn::string<4> part = _remaining_message.substr(cursor_i, char_length);
                BN_LOG("part: [", part, "]");

                // Move the index to the next character
                cursor_i += char_length;

                is_eol = (cursor_i == _remaining_message.size());
                is_space = part.starts_with(32);
                is_newline = part.starts_with(10);

                if (is_eol) {
                    _word_buffer.append(part);
                    if (_actor.size() != 0) {
                        _word_buffer.append("\"");
                        quoted_end = true;
                    }
                }

                if (is_eol || is_space || is_newline) {
                    word_width = _text_generator->width(_word_buffer);

                    if (cursor_x + word_width < max_width) {
                        bn::string_view buffer(_word_buffer);
                        BN_LOG("Word buffer: [", buffer, "]");
                        // render_animated_by_chunks_with_updates(cursor_x, _text_render_line * 12, buffer);
                        _word_buffer.clear();

                        ks::globals::main_update();
                        cursor_x += word_width + (is_space ? space_width : 0);
                        _text_render_next_line_index = cursor_i;
                        if (is_eol || is_newline) {
                            line_end = true;
                        }
                    } else {
                        if (is_eol) {
                            _text_render_next_line_index = cursor_i - _word_buffer.size() + (quoted_end ? 1 : 0);
                        } else {
                            _text_render_next_line_index = cursor_i - _word_buffer.size() - 1;
                        }
                        _word_buffer.clear();
                        line_end = true;
                    }
                } else {
                    _word_buffer.append(part);
                }
            }

            _text_render_prev_line_index = cursor;
            _text_render_prev_line_length = _text_render_next_line_index - _text_render_prev_line_index;

            if (is_newline) {
                // Do not try to render newline character (it invalid UTF-8 char)
                _text_render_prev_line_length--;
            }

            write_animation();
        }

        void render_animated_by_chunks_with_updates(int x, int y, bn::string_view buffer, unsigned char chunk_size = 4) {
            _text_generator->set_one_sprite_per_character(true);

            unsigned char current_x = x;

            size_t index = 0;
            while (index < buffer.size()) {
                bn::string<16> chunk; // Temporary string for a single chunk (size limited to chunk_size)
                chunk.clear();
                int chunk_length = 0;  // Number of valid UTF-8 characters added to the chunk

                // BN_LOG("index: ", index, " of ", buffer.size());
                // Extract a valid UTF-8 chunk
                while (index < buffer.size() && chunk_length < chunk_size) {
                    unsigned char c = static_cast<unsigned char>(buffer.at(index));
                    unsigned char char_size = get_char_size(c);

                    BN_LOG("Buffer size: ", buffer.size(), ", Index: ", index, ", Chunk: ", chunk);

                    // Ensure there are enough bytes left in the finalized_line for this character
                    if (index + char_size <= buffer.size()) {
                        for (int i = 0; i < char_size; ++i) {
                            chunk.push_back(buffer.at(index + i));
                        }
                        index += char_size; // Move the index past the character
                        ++chunk_length; // Count this as one character
                    } else {
                        break; // Incomplete character at the end of the line
                    }
                }

                // BN_LOG("Buffer size: ", buffer.size(), ", Index: ", index, ", Chunk: ", chunk);

                // Generate sprites for the chunk
                _text_generator->generate(
                    -ks::device::screen_width_half + 10 + current_x,
                    ks::device::screen_height_half - 36 + y,
                    chunk,
                    _animated_text_sprites
                    );

                // Update horizontal position for the next chunk
                current_x += _text_generator->width(chunk);

                // Update the screen
                ks::globals::main_update();
            }
        }

        void render_finalized_by_chunks_with_updates(int y, bn::string_view finalized_line, bn::string_view prefix = nullptr, unsigned char chunk_size = 4) {
            _text_generator->set_one_sprite_per_character(false);
            unsigned char current_x = 0;
            if (prefix != nullptr) {
                _text_generator->generate(-ks::device::screen_width_half + 10, ks::device::screen_height_half - 36 + y, prefix, _finalized_text_sprites);
                current_x += _text_generator->width(prefix);
            }
            // _text_generator->generate(-ks::device::screen_width_half + 10 + current_x, ks::device::screen_height_half - 36 + y, finalized_line, _finalized_text_sprites);

            size_t index = 0;
            while (index < finalized_line.size()) {
                bn::string<16> chunk; // Temporary string for a single chunk (size limited to chunk_size)
                int chunk_length = 0;  // Number of valid UTF-8 characters added to the chunk

                // Extract a valid UTF-8 chunk
                while (index < finalized_line.size() && chunk_length < chunk_size) {
                    unsigned char c = static_cast<unsigned char>(finalized_line[index]);
                    unsigned char char_size = get_char_size(c);

                    // Ensure there are enough bytes left in the finalized_line for this character
                    if (index + char_size <= finalized_line.size()) {
                        for (int i = 0; i < char_size; ++i) {
                            chunk.push_back(finalized_line[index + i]);
                        }
                        index += char_size; // Move the index past the character
                        ++chunk_length; // Count this as one character
                    } else {
                        break; // Incomplete character at the end of the line
                    }
                }

                // Generate sprites for the chunk
                _text_generator->generate(
                    -ks::device::screen_width_half + 10 + current_x,
                    ks::device::screen_height_half - 36 + y,
                    chunk,
                    _finalized_text_sprites
                    );

                // Update horizontal position for the next chunk
                current_x += _text_generator->width(chunk);

                // Update the screen
                ks::globals::main_update();
            }
        }

        void hide_animated_sprites() {
            for (auto& sprite : _animated_text_sprites) {
                sprite.set_visible(false);
            }
        }

        void show_message_sprites() {
            for (auto& sprite : _animated_text_sprites) {
                sprite.set_visible(true);
            }
        }

        void write_animation() {
            _text_render_timer.restart();
            _is_immediately = false;
            _is_writing = true;
        }

        void BN_CODE_IWRAM write_immediately() {
            _text_render_timer.restart();
            // Increases the audio player rate
            // player_setRate(3);
            while (_text_render_next_line_index != _remaining_message.size() && _text_render_line < ks::defaults::text_render_max_lines_count - 1) {
                _text_render_line++;
                render_message_line(_text_render_next_line_index);
                ks::globals::main_update();
            }
            show_message_sprites();
            // player_setRate(0);
            _is_immediately = true;
            _is_writing = false;
        }

        unsigned char BN_CODE_IWRAM get_char_size(unsigned char c) {
            if ((c & 0x80) == 0) {
                return 1;
            } else if ((c & 0xE0) == 0xC0) {
                return 2;
            } else if ((c & 0xF0) == 0xE0) {
                return 3;
            } else if ((c & 0xF8) == 0xF0) {
                return 4;
            }
        }

        void update()
        {
            bool SKIP = bn::keypad::b_held();

            if (_is_question) {
                // int pause_cycle_counter = 50;
                if (_answers_camera.has_value() && _answers_camera_action.has_value()) {
                    if (_answer_pause_cycle_counter < ks::defaults::answer_camera_bounds_pause_count) {
                        _answer_pause_cycle_counter++;
                    } else {
                        if (_answer_loop_cycle_counter < _answers_camera_loop_duration) {
                            _answer_loop_cycle_counter++;
                            _answers_camera_action->update();
                            set_answer_sprites_visibility(_answer_selected);
                        } else {
                            _answer_pause_cycle_counter = 0;
                            _answer_loop_cycle_counter = 0;
                        }
                    }
                }

                if (bn::keypad::down_pressed() || bn::keypad::up_pressed()) {
                    move_answer_camera_to_start();
                    set_answer_sprites_visibility(_answer_selected);
                    if (bn::keypad::down_pressed()) {
                        _answer_selected++;
                    } else if (bn::keypad::up_pressed()) {
                        _answer_selected += _answers_widths.size() - 1;
                    }
                    _answer_selected = _answer_selected % _answers_widths.size();
                    setup_answer_camera();
                    set_answer_box_blending();
                    set_answers_palette();
                } else if (bn::keypad::a_pressed()) {
                    BN_LOG("BEFORE FINISH");
                    _is_finished = true;
                    BN_LOG("AFTER FINISH");
                }
                return;
            }

            if (_is_writing) {
                BN_LOG("WRITING");
                if (bn::keypad::a_pressed() || SKIP) {
                    write_immediately();
                } else {
                    if (_animated_text_sprites.size() > 0 && _text_render_timer.elapsed_ticks() < _animated_text_sprites.size() * ks::defaults::text_render_char_ticks) {
                        // Animating
                        int i = 0;
                        for (auto sprite : _animated_text_sprites) {
                            if (_text_render_timer.elapsed_ticks() >= i * ks::defaults::text_render_char_ticks) {
                                sprite.set_visible(true);
                            }
                            i++;
                        }
                    } else if (_text_render_next_line_index != _remaining_message.size() && _text_render_line < ks::defaults::text_render_max_lines_count - 1) {
                        _text_render_line++;
                        render_message_line(_text_render_next_line_index);
                    } else {
                        _is_writing = false;
                    }
                }
            } else {
                if (_text_render_next_line_index == _remaining_message.size()) {
                    if (bn::keypad::a_pressed() || SKIP) {
                        _is_finished = true;
                    }
                } else {
                    // There is more pages to display
                    if (bn::keypad::a_pressed() || SKIP) {
                        _text_render_line = (_text_render_line + 1) % ks::defaults::text_render_max_lines_count;
                        render_message_line(_text_render_next_line_index);
                    }
                }
            }
        }

private:
        const unsigned short _answers_half_width = 92;

        bool _is_finished = false;
        bool _is_question = false;
        bool _is_writing;
        bool _is_immediately;
        int _text_render_char_xpos;

        int _text_render_line = 0; // The line to render animated text (0..2) one sprite per character. Previous line is rendered as static.
        int _text_render_prev_line_index = 0;
        int _text_render_prev_line_length = 0;
        int _text_render_next_line_index = 0;


        bool _hidden = true;

        bn::sprite_text_generator* _text_generator;
        const bn::sprite_font& _font;

        // Answers related stuff
        bn::vector<bn::optional<bn::sprite_ptr>, 5> answerboxes_l;
        bn::vector<bn::optional<bn::sprite_ptr>, 5> answerboxes_c;
        bn::vector<bn::optional<bn::sprite_ptr>, 5> answerboxes_r;
        bn::vector<bn::sprite_ptr, 128> _answers_sprites;
        bn::vector<unsigned short, 128> _answers_sprites_answer_index;
        bn::vector<unsigned short, 5> _answers_widths;
        bn::optional<bn::camera_ptr> _answers_camera;
        bn::optional<bn::camera_move_loop_action> _answers_camera_action;
        unsigned short _answers_camera_loop_duration;
        int _answer_selected;
        unsigned short _answer_loop_cycle_counter;
        unsigned short _answer_pause_cycle_counter;

        // Talkbox related stuff
        bn::optional<bn::sprite_ptr> talkbox1;
        bn::optional<bn::sprite_ptr> talkbox2;
        bn::optional<bn::sprite_ptr> talkbox3;
        bn::optional<bn::sprite_ptr> talkbox4;
        bn::vector<bn::sprite_ptr, 32> _title_sprites;
        bn::vector<bn::sprite_ptr, 128> _animated_text_sprites;
        bn::vector<bn::sprite_ptr, 512> _finalized_text_sprites;
        // bn::vector<bn::sprite_ptr, 256> _debug_sprites;
        bn::timer _text_render_timer;
        bn::string<32> _actor;
        bn::string_view _remaining_message;
        bn::string<256> _word_buffer; // May be resize form verylongphraseswithoutspaces

        // Palettes
        bn::sprite_palette_item original_palette_item;
        bn::sprite_palette_item beige_palette_item;
        bn::sprite_palette_item beige_selected_palette_item;
    };

}

#endif
