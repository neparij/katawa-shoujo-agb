#ifndef KS_DIALOGBOX_H
#define KS_DIALOGBOX_H

#include "bn_blending.h"
#include "bn_blending_actions.h"
#include "bn_core.h"
#include "bn_keypad.h"
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

#include "bn_sprite_items_ui_talkbox1.h"
#include "bn_sprite_items_ui_talkbox1_e.h"
#include "bn_sprite_items_ui_talkbox2.h"
#include "bn_sprite_items_ui_talkbox2_e.h"
#include "bn_sprite_items_ui_talkbox3.h"
#include "bn_sprite_items_ui_talkbox4.h"

#include <BN_LOG.h>
#include <bn_size.h>

namespace ks
{
    class DialogBox
    {
    public:
        DialogBox(bn::sprite_text_generator* text_generator, const bn::sprite_font& font)
            : _text_generator(text_generator),
            _font(font)
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
            _text_render_timer.restart();
            _text_render_char_xpos = 0;
            _text_render_line = 0;
            _is_writing = false;
            _is_immediately = false;
            _word_buffer.clear();

            _animated_text_sprites.clear();
            _finalized_text_sprites.clear();
        }

        void reset() {
            reset_title();
            reset_message();
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

        void show(bn::string<16> actor, bn::string<512> message)
        {
            reset_title();
            reset_message();

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

            if (ks::globals::show_memory_debug) {
                _text_generator->set_one_sprite_per_character(false);
                _debug_sprites.clear();
                _text_generator->generate(-116, -72, bn::to_string<32>("IWRAM stack::") + bn::to_string<32>(bn::memory::used_stack_iwram()), _debug_sprites);
                _text_generator->generate(-116, -72+12, bn::to_string<32>("IWRAM static::") + bn::to_string<32>(bn::memory::used_static_iwram()), _debug_sprites);
                _text_generator->generate(-116, -72+24, bn::to_string<32>("EWRAM static::") + bn::to_string<32>(bn::memory::used_static_ewram()), _debug_sprites);
                _text_generator->generate(-116, -72+36, bn::to_string<32>("EWRAM alloc::") + bn::to_string<32>(bn::memory::used_alloc_ewram()), _debug_sprites);
                _text_generator->generate(-116, -72+48, bn::to_string<32>("EWRAM avail::") + bn::to_string<32>(bn::memory::available_alloc_ewram()), _debug_sprites);
            }

            _actor = actor;
            _remaining_message = message;

            _text_generator->set_one_sprite_per_character(false);
            _text_generator->generate(-ks::device::screen_width_half + 8, ks::device::screen_height_half - 52, _actor, _title_sprites);

            if (_hidden) {
                show_blend();
            } else {
                bn::blending::set_transparency_alpha(0.7);
            }

            render_message_line(0);
        }


        void BN_CODE_IWRAM render_message_line(int cursor) {
            auto message_view = bn::string_view(_remaining_message);
            const int max_width = ks::device::screen_width - 20;
            unsigned space_width = _text_generator->width(" ");

            if (_text_render_line == 0) {
                // Delete all text sprites on the first line of each page.
                reset_message();
            } else {
                _text_render_timer.restart();
                _animated_text_sprites.clear();

                auto finalized_line = bn::string<256>((_actor.size() != 0 && _text_render_prev_line_index == 0) ? "\"" : "");
                auto finalized_index = _finalized_text_sprites.size();

                finalized_line.append(message_view.substr(_text_render_prev_line_index, _text_render_prev_line_length));
                render_finalized((_text_render_line - 1) * 12, finalized_line);

                // auto offset = (max_width - _text_generator->width(finalized_line)) / 2;
                // for (int i = finalized_index; i < _finalized_text_sprites.size(); i++) {
                //     auto pos = _finalized_text_sprites[i].position();
                //     _finalized_text_sprites[i].set_position(pos.x() + offset, pos.y());
                // }
            }

            int cursor_i = cursor;
            unsigned cursor_x = 0;
            unsigned word_width = 0;
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
                unsigned char first_byte = static_cast<unsigned char>(message_view[cursor_i]);
                int char_length = 1;

                if ((first_byte & 0x80) == 0x00) {
                    // ASCII character (1 byte)
                    char_length = 1;
                } else if ((first_byte & 0xE0) == 0xC0) {
                    // Two-byte character
                    char_length = 2;
                } else if ((first_byte & 0xF0) == 0xE0) {
                    // Three-byte character
                    char_length = 3;
                } else if ((first_byte & 0xF8) == 0xF0) {
                    // Four-byte character
                    char_length = 4;
                }

                // Extract the UTF-8 character
                bn::string<4> part;
                for (int j = 0; j < char_length && (cursor_i + j) < message_view.size(); ++j) {
                    part.push_back(message_view[cursor_i + j]);
                }

                // Move the index to the next character
                cursor_i += char_length;

                is_eol = (cursor_i == message_view.size());
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
                        render_animated(cursor_x, _text_render_line * 12);
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

            // auto offset = (max_width - cursor_x) / 2;
            // for (auto char_sprite : _animated_text_sprites) {
            //     auto pos = char_sprite.position();
            //     char_sprite.set_position(pos.x() + offset, pos.y());
            // }

            _text_render_prev_line_index = cursor;
            _text_render_prev_line_length = _text_render_next_line_index - _text_render_prev_line_index;

            if (is_newline) {
                // Do not try to render newline character (it invalid UTF-8 char)
                _text_render_prev_line_length--;
            }

            hide_message_sprites();
            write_animation();
        }

        void render_animated(int x, int y) {
            _text_generator->set_one_sprite_per_character(true);
            _text_generator->generate(-ks::device::screen_width_half + 10 + x, ks::device::screen_height_half - 36 + y, _word_buffer, _animated_text_sprites);
            _word_buffer.clear();
        }

        void render_finalized(int y, bn::string<256> finalized_line) {
            _text_generator->set_one_sprite_per_character(false);
            _text_generator->generate(-ks::device::screen_width_half + 10, ks::device::screen_height_half - 36 + y, finalized_line, _finalized_text_sprites);
        }

        void hide_message_sprites() {
            for (auto sprite : _animated_text_sprites) {
                sprite.set_visible(false);
            }
        }

        void show_message_sprites() {
            for (auto sprite : _animated_text_sprites) {
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
            player_setRate(3);
            while (_text_render_next_line_index != _remaining_message.size() && _text_render_line < ks::defaults::text_render_max_lines_count - 1) {
                if (_text_render_timer.elapsed_ticks() > ks::defaults::text_render_skip_ticks) {
                    _text_render_line++;
                    render_message_line(_text_render_next_line_index);
                }
                ks::globals::main_update();
            }
            show_message_sprites();
            player_setRate(0);
            _is_immediately = true;
            _is_writing = false;
        }

        void update()
        {
            bool SKIP = bn::keypad::b_held();
            bool SKIP_WITH_TIMER = SKIP && _text_render_timer.elapsed_ticks() > ks::defaults::text_render_skip_ticks;



            if (_is_writing) {
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
                    if (bn::keypad::a_pressed() || SKIP_WITH_TIMER) {
                        _is_finished = true;
                    }
                } else {
                    // There is more pages to display
                    if (bn::keypad::a_pressed() || SKIP_WITH_TIMER) {
                        _text_render_line = (_text_render_line + 1) % ks::defaults::text_render_max_lines_count;
                        render_message_line(_text_render_next_line_index);
                    }
                }
            }
        }

    private:
        bool _is_finished = false;
        bool _is_writing;
        bool _is_immediately;
        int _text_render_char_xpos;

        int _text_render_line = 0; // The line to render animated text (0..2) one sprite per character. Previous line is rendered as static.
        int _text_render_prev_line_index = 0;
        int _text_render_prev_line_length = 0;
        int _text_render_next_line_index = 0;


        bool _hidden = true;
        bn::optional<bn::sprite_ptr> talkbox1;
        bn::optional<bn::sprite_ptr> talkbox2;
        bn::optional<bn::sprite_ptr> talkbox3;
        bn::optional<bn::sprite_ptr> talkbox4;

        bn::sprite_text_generator* _text_generator;
        const bn::sprite_font& _font;
        bn::vector<bn::sprite_ptr, 32> _title_sprites;
        bn::vector<bn::sprite_ptr, 512> _animated_text_sprites;
        bn::vector<bn::sprite_ptr, 512> _finalized_text_sprites;
        bn::vector<bn::sprite_ptr, 256> _debug_sprites;
        bn::timer _text_render_timer;
        bn::string<32> _actor;
        bn::string<512> _remaining_message;
        bn::string<256> _word_buffer; // May be resize form verylongphraseswithoutspaces

    };

}

#endif
