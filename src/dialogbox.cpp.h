#ifndef KS_DIALOGBOX_H
#define KS_DIALOGBOX_H

#include "bn_blending.h"
#include "bn_blending_actions.h"
#include "bn_camera_actions.h"
#include "bn_camera_ptr.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_sprite_palette_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_string.h"
#include "bn_rect_window.h"
#include "bn_timer.h"

#include "constants.h"
#include "globals.h"

#include "bn_sprite_items_ui_answerbox1.h"
#include "bn_sprite_items_ui_answerbox2.h"
#include "bn_sprite_items_ui_answerbox3.h"
#include "bn_sprite_items_ui_talkbox1.h"
#include "bn_sprite_items_ui_talkbox2.h"
#include "bn_sprite_items_ui_talkbox3.h"
#include "bn_sprite_items_ui_talkbox4.h"
#include "bn_sprite_items_ui_talkbox_actor_start.h"
#include "bn_sprite_items_ui_talkbox_actor.h"
#include "bn_sprite_items_ui_talkbox_actor_end.h"

#include <BN_LOG.h>
#include <bn_size.h>
#include <bn_sprite_actions.h>
#include <bn_sprite_tiles_ptr.h>
#include <gba_video.h>

#include "bn_sprite_items_variable_16x16_font_beige_pal.h"
#include "bn_sprite_items_variable_16x16_font_beige_selected_pal.h"
#include "../../butano/butano/hw/include/bn_hw_irq.h"

#include "bn_sprite_items_transition_block_0.h"
#include "bn_sprite_items_transition_block_1.h"
#include "bn_sprite_items_transition_block_2.h"
#include "bn_sprite_items_transition_block_3.h"
static u32* tile_addr_ptr[2];
static unsigned char gradients[120];
static u8* gradients_ptr;
static u8 gradient_iteration = 0;

// Предварительно вычисленные паттерны для каждой строки
static u32 pattern_buffer[128];   // Буфер для текущего шаблона (не в IWRAM)

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
        DialogBox(bn::sprite_text_generator* text_generator, bn::vector<bn::sprite_ptr, 64>* finalized_text_sprites, bn::vector<bn::sprite_ptr, 128>* animated_text_sprites)
            : _text_generator(text_generator),
            _finalized_text_sprites(finalized_text_sprites),
            _animated_text_sprites(animated_text_sprites),
            original_palette_item(_text_generator->palette_item()),
            beige_palette_item(bn::sprite_items::variable_16x16_font_beige_pal.palette_item()),
            beige_selected_palette_item(bn::sprite_items::variable_16x16_font_beige_selected_pal.palette_item())
        {
            reset_title();
            reset_message();

            // talkbox1 = bn::sprite_items::ui_talkbox1_e.create_sprite(-ks::device::screen_width_half + 32, ks::device::screen_height_half - 32);
            // talkbox2 = bn::sprite_items::ui_talkbox2_e.create_sprite(-ks::device::screen_width_half + 32 + 64, ks::device::screen_height_half - 32);
            // // } else {
            // // talkbox1 = bn::sprite_items::ui_talkbox1.create_sprite(-ks::device::screen_width_half + 32, ks::device::screen_height_half - 32);
            // // talkbox2 = bn::sprite_items::ui_talkbox2.create_sprite(-ks::device::screen_width_half + 32 + 64, ks::device::screen_height_half - 32);
            // // }
            // talkbox3 = bn::sprite_items::ui_talkbox3.create_sprite(-ks::device::screen_width_half + 32 + 128, ks::device::screen_height_half - 32);
            // talkbox4 = bn::sprite_items::ui_talkbox4.create_sprite(-ks::device::screen_width_half + 32 + 192, ks::device::screen_height_half - 32);
        }

        const constexpr static bool DRAW_PACKED_SPRITES_IN_ONE_CHUNK = true;

        bool is_finished() {
            return _is_finished;
        }

        bool is_skipping() {
            return bn::keypad::b_held() && !_is_question;
        }

        bool is_hidden() {
            return _hidden;
        }

        static bn::fixed transparency_alpha() {
            return bn::fixed(ks::globals::settings.high_contrast ? 1.0 : 0.85);
        }

        void reset_title() {
            _title_sprites.clear();
            talkbox_actor_sprites.clear();
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

            // _animated_text_sprites->clear();
            // _finalized_text_sprites->clear();
            for (auto& sprite : *_animated_text_sprites) {
                sprite.set_visible(false);
            }
            for (auto& sprite : *_finalized_text_sprites) {
                sprite.set_visible(false);
            }
            _animated_text_sprites->clear();
            _finalized_text_sprites->clear();
            _answers_sprites.clear();
        }

        void reset_question() {
            _is_finished = false;
            _is_question = true;
            for (auto& answerbox : answerboxes_l) {
                answerbox.reset();
            }
            for (auto& answerbox : answerboxes_c) {
                answerbox.reset();
            }
            for (auto& answerbox : answerboxes_r) {
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
            talkbox_actor_sprites.clear();
        }

        void set_blending(bool enabled) {
            talkbox1->set_blending_enabled(enabled);
            talkbox2->set_blending_enabled(enabled);
            talkbox3->set_blending_enabled(enabled);
            talkbox4->set_blending_enabled(enabled);
            for (auto& s : talkbox_actor_sprites) {
                s.set_blending_enabled(true);
            }

            for (auto& s : _title_sprites) {
                s.set_blending_enabled(true);
            }
            for (auto& s : *_finalized_text_sprites) {
                s.set_blending_enabled(true);
            }
            for (auto& s : *_animated_text_sprites) {
                s.set_blending_enabled(true);
            }
        }

        void finalize_blending() {
            for (auto& s : _title_sprites) {
                s.set_blending_enabled(false);
            }
            for (auto& s : *_finalized_text_sprites) {
                s.set_blending_enabled(false);
            }
            for (auto& s : *_animated_text_sprites) {
                s.set_blending_enabled(false);
            }
        }

        void set_show_talkboxes(bool visible) {
            talkbox1->set_visible(visible);
            talkbox2->set_visible(visible);
            talkbox3->set_visible(visible);
            talkbox4->set_visible(visible);
            for (auto& s : talkbox_actor_sprites) {
                s.set_visible(visible);
            }
        }

        void hide_blend() {
            bn::blending::set_transparency_alpha(transparency_alpha());
            auto alpha_action = bn::blending_transparency_alpha_to_action(10, 0.0);
            set_blending(true);
            while (!alpha_action.done()) {
                alpha_action.update();
                ks::globals::main_update();
            }

            alpha_action.reset();
            hide();
        }

        void show_blend() {
            bn::blending::set_transparency_alpha(0);
            auto alpha_action = bn::blending_transparency_alpha_to_action(10, transparency_alpha());
            set_blending(true);
            set_show_talkboxes(true);
            while (!alpha_action.done()) {
                alpha_action.update();
                ks::globals::main_update();
            }
            alpha_action.reset();
            bn::blending::set_transparency_alpha(transparency_alpha());
            finalize_blending();
            _hidden = false;
        }

        void show(const character_definition& actor, const bn::string<1024> &message) {
            reset_title();
            reset_message();
            reset_question();

            if (actor.name() && *actor.name() != '\0') {
                _actor = &actor;  // Store pointer to the character definition
            } else {
                _actor = nullptr;  // No character
            }
            if (message != _remaining_message) {
                _remaining_message = message;
            }

            talkbox1 = bn::sprite_items::ui_talkbox1.create_sprite(-ks::device::screen_width_half + 32, ks::device::screen_height_half - 32);
            talkbox2 = bn::sprite_items::ui_talkbox2.create_sprite(-ks::device::screen_width_half + 32 + 64, ks::device::screen_height_half - 32);
            talkbox3 = bn::sprite_items::ui_talkbox3.create_sprite(-ks::device::screen_width_half + 32 + 128, ks::device::screen_height_half - 32);
            talkbox4 = bn::sprite_items::ui_talkbox4.create_sprite(-ks::device::screen_width_half + 32 + 192, ks::device::screen_height_half - 32);

            // talkbox1 = bn::sprite_items::transition_block_0.create_sprite(-ks::device::screen_width_half + 32, -ks::device::screen_height_half + 32);
            // talkbox2 = bn::sprite_items::transition_block_1.create_sprite(-ks::device::screen_width_half + 32 + 64, -ks::device::screen_height_half + 32);
            // talkbox3 = bn::sprite_items::transition_block_2.create_sprite(-ks::device::screen_width_half + 32 + 128, -ks::device::screen_height_half + 32);
            // talkbox4 = bn::sprite_items::transition_block_3.create_sprite(-ks::device::screen_width_half + 32 + 192, -ks::device::screen_height_half + 32);
            //
            // // ЭТАП 1: Создание градиента
            // // Инициализируем градиент один раз здесь
            // for (int i = 0; i < 120; i++) {
            //     gradients[i] = i;
            // }
            // gradients_ptr = static_cast<uint8_t *>(gradients);
            //
            // // Функция обновления шаблонов на основе текущего значения градиента
            // auto update_patterns = [&]() {
            //     const u8 gi = gradient_iteration;
            //
            //     for (int y = 0; y < 80; y++) {
            //         for (int block = 0; block < 2; block++) {
            //             // Вычисляем шаблоны для всех 8 тайлов
            //             for (int tile = 0; tile < 8; tile++) {
            //                 u32 result = 0;
            //                 const int base = block * 64 + tile * 8;
            //
            //                 for (int pixel = 0; pixel < 8; pixel++) {
            //                     const int index = base + pixel;
            //                     if (index < 120 && gradients[index] <= gi) {
            //                         result |= (1 << (pixel * 4));
            //                     }
            //                 }
            //
            //                 pattern_buffer[block * 64 + tile * 8] = result;
            //             }
            //         }
            //     }
            // };
            //
            // globals::main_update();
            // tile_addr_ptr[0] = static_cast<uint32_t *>(SPR_VRAM(talkbox1->tiles().id()));
            // tile_addr_ptr[1] = static_cast<uint32_t *>(SPR_VRAM(talkbox2->tiles().id()));
            // // tile_addr_ptr[2] = static_cast<uint32_t *>(SPR_VRAM(talkbox3->tiles().id()));
            // // tile_addr_ptr[3] = static_cast<uint32_t *>(SPR_VRAM(talkbox4->tiles().id()));
            //
            // // Инициализируем начальное значение итерации градиента
            // gradient_iteration = 0;
            //
            // // ЭТАП 2: Обновление шаблонов для начального значения градиента
            // update_patterns();
            //
            // bn::hw::irq::enable(bn::hw::irq::id::HBLANK);
            // bn::hw::irq::set_isr(bn::hw::irq::id::HBLANK, []() BN_CODE_IWRAM {
            //     const u16 vcount = REG_VCOUNT;
            //     if (vcount < 160 && vcount % 2 == 0) {
            //         // Выполняем 4 раза - для каждого блока.
            //         for (int block = 0; block < 2; block++) {
            //             tile_addr_ptr[block][0] = pattern_buffer[block * 64 + 0];
            //             tile_addr_ptr[block][8] = pattern_buffer[block * 64 + 8];
            //             tile_addr_ptr[block][16] = pattern_buffer[block * 64 + 16];
            //             tile_addr_ptr[block][24] = pattern_buffer[block * 64 + 24];
            //             tile_addr_ptr[block][32] = pattern_buffer[block * 64 + 32];
            //             tile_addr_ptr[block][40] = pattern_buffer[block * 64 + 40];
            //             tile_addr_ptr[block][48] = pattern_buffer[block * 64 + 48];
            //             tile_addr_ptr[block][56] = pattern_buffer[block * 64 + 56];
            //         }
            //     }
            // });
            //
            // while (true) {
            //     if (gradient_iteration < 120) {
            //         gradient_iteration++;
            //         // ЭТАП 3: Обновление шаблонов при изменении итерации градиента
            //         update_patterns();
            //     } else {
            //         gradient_iteration = 0;
            //         update_patterns();
            //     }
            //     globals::main_update();
            // }

            talkbox1->set_bg_priority(1);
            talkbox2->set_bg_priority(1);
            talkbox3->set_bg_priority(1);
            talkbox4->set_bg_priority(1);

            _text_generator->set_one_sprite_per_character(false);
            _text_generator->set_left_alignment();
            _text_generator->set_palette_item(original_palette_item);

            _text_generator->set_bg_priority(1);
            _text_generator->set_z_order(-10);

            ks::globals::sound_update();

            if (_actor != nullptr) {
                // BN_LOG("Actor: ", _actor->name());
                BN_LOG("[38;5;", _actor->log_color, "m", "[1m", _actor->name(), "[0m");
                _text_generator->set_palette_item(_actor->who_color);
                _text_generator->generate(-ks::device::screen_width_half + 8, ks::device::screen_height_half - 52, _actor->name(), _title_sprites);
                _text_generator->set_palette_item(original_palette_item);  // Reset to default palette
                const int title_ends_x = -ks::device::screen_width_half + 8 + _text_generator->width(_actor->name());

                talkbox_actor_sprites.push_back(bn::sprite_items::ui_talkbox_actor_start.create_sprite(-ks::device::screen_width_half + 16, ks::device::screen_height_half - 44));
                talkbox_actor_sprites.back().set_bg_priority(1);
                unsigned char i = 1;

                while (title_ends_x > -ks::device::screen_width_half + (i * 32)) {
                    talkbox_actor_sprites.push_back(bn::sprite_items::ui_talkbox_actor.create_sprite(-ks::device::screen_width_half + 16 + i * 32, ks::device::screen_height_half - 44));
                    talkbox_actor_sprites.back().set_bg_priority(1);
                    i++;
                }

                talkbox_actor_sprites.push_back(bn::sprite_items::ui_talkbox_actor_end.create_sprite(-ks::device::screen_width_half + 16 + i * 32, ks::device::screen_height_half - 44));
                talkbox_actor_sprites.back().set_bg_priority(1);
            }

            set_blending(true);
            if (_hidden) {
                show_blend();
            } else {
                bn::blending::set_transparency_alpha(transparency_alpha());
                finalize_blending();
            }

            render_message_line(0, is_skipping());
        }

        void hide() {
            set_blending(false);
            set_show_talkboxes(false);
            reset_title();
            reset_message();
            _hidden = true;
        }

         void restore_from_pause() {
            if (!_remaining_message.empty()) {
                if (_actor != nullptr) {
                    show(*_actor, _remaining_message);
                } else {
                    show(definitions::no_char, _remaining_message);
                }
            }
        }

        void show_question(bn::vector<bn::string<128>, 5>& answers) {

            // BN_LOG("Pointer (S) address: ", ks::gfx::static_text_tiles);
            // BN_LOG("Pointer (A) address: ", ks::gfx::animated_text_tiles);

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

                box_l.set_bg_priority(1);
                box_c.set_bg_priority(1);
                box_r.set_bg_priority(1);


                answerboxes_l.push_back(box_l);
                answerboxes_c.push_back(box_c);
                answerboxes_r.push_back(box_r);
                // // TODO: Use stringview?
                // _text_generator->generate(0, -56 + i * 20, answers.at(i), _answers_sprites);
                // _answers_widths.push_back(_text_generator->width(answers.at(i)));
                const int answer_width = _text_generator->width(answers.at(i));
                _answers_widths.push_back(_text_generator->width(answers.at(i)));
                if (answer_width <= _answers_half_width * 2) {
                    _text_generator->generate(-answer_width / 2, -56 + i * 20, answers.at(i), _answers_sprites);
                } else {
                    _text_generator->generate(-_answers_half_width, -56 + i * 20, answers.at(i), _answers_sprites);
                }
                ks::globals::sound_update();
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

            // BN_LOG("Pointer (S) address: ", ks::gfx::static_text_tiles);
            // BN_LOG("Pointer (A) address: ", ks::gfx::animated_text_tiles);
        }

        void move_answer_camera_to_start() {
            if (_answers_camera.has_value()) {
                _answers_camera->set_x(0);
                // ks::globals::main_update();
            }
        }

        void setup_answer_camera() {
            const int answer_width = _answers_widths.at(_answer_selected);
            if (answer_width <= _answers_half_width * 2) {
                _answers_camera.reset();
                _answers_camera_action.reset();
                return;
            }

            const int camera_amplitude = answer_width - _answers_half_width * 2;
            const int camera_duration = camera_amplitude * ks::defaults::answer_camera_duration_multiplier;
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
                const bool is_selected = i == _answer_selected;
                answerboxes_l.at(i)->set_blending_enabled(!is_selected);
                answerboxes_c.at(i)->set_blending_enabled(!is_selected);
                answerboxes_r.at(i)->set_blending_enabled(!is_selected);
            }
        }

        void set_answers_palette() {
            for (int i = 0; i < _answers_sprites.size(); i++) {
                const bool is_selected = _answers_sprites_answer_index.at(i) == _answer_selected;
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
                    const auto relative_position = bn::abs(char_sprite->position().x() - 4 - cam_pos_x);
                    if (relative_position > _answers_half_width) {
                        char_sprite->set_visible(false);
                    } else {
                        char_sprite->set_visible(true);
                    }
                }
            }
        }

        int get_answer_index() const {
            return _answer_selected;
        }


        void render_message_line(const int cursor, const bool immediately = false) {
            constexpr int max_width = ks::device::screen_width - 20;
            const unsigned char space_width = _text_generator->width(" ");
            const bn::string_view message(_remaining_message);

            _text_generator->set_palette_item(original_palette_item);

            if (_text_render_line == 0) {
                // Delete all text sprites on the first line of each page.
                reset_message();
            } else {
                _text_render_timer.restart();
                const bool quoted_start = _actor != nullptr && _text_render_prev_line_index == 0;

                const bn::string_view finalized_line(message.substr(_text_render_prev_line_index, _text_render_prev_line_length));
                // BN_LOG("Render finalized line ", _text_render_line - 1, ": ", finalized_line);
                render_text_by_chunks_with_updates<64>(
                    0, (_text_render_line - 1) * 12,
                    finalized_line,
                    *_finalized_text_sprites,
                    quoted_start ? "\"" : "",
                    "",
                    false
                    );

                for (auto& sprite : *_finalized_text_sprites) {
                    if (!sprite.visible()) {
                        sprite.set_visible(true);
                    }
                }

                if (!_animated_text_sprites->empty()) {
                    _animated_text_sprites->clear();
                }
            }

            int cursor_i = cursor;
            unsigned char cursor_x = 0;
            unsigned char word_width = 0;
            bool line_end = false;
            bool is_eol = false;
            bool is_space = false;
            bool is_newline = false;
            bool quoted_start = false;
            bool quoted_end = false;

            if (_actor != nullptr && cursor == 0) {
                _word_buffer.append("\"");
                quoted_start = true;
            }

            while (!line_end) {
                unsigned char first_byte = static_cast<unsigned char>(message.at(cursor_i));
                int char_length = get_char_size(first_byte);

                bn::string<4> part = message.substr(cursor_i, char_length);
                cursor_i += char_length;

                BN_ASSERT(cursor_i <= message.size(), "Cursor index out of bounds in message");

                is_eol = (cursor_i == message.size());
                is_space = part.starts_with(32);
                is_newline = part.starts_with(10);

                if (is_eol) {
                    _word_buffer.append(part);
                    if (_actor != nullptr) {
                        _word_buffer.append("\"");
                        quoted_end = true;
                    }
                }

                if (is_eol || is_space || is_newline) {
                    word_width = _text_generator->width(_word_buffer);

                    if (cursor_x + word_width < max_width) {
                        _word_buffer.clear();
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
                    word_width = _text_generator->width(_word_buffer + part);
                    if (word_width >= max_width) {
                            // 🚨 FUCK YOU KENJI for your "Aaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhhhhhggggggggggghhhhhhhh……"
                            _text_render_next_line_index = cursor_i;
                            _word_buffer.clear();
                            line_end = true;
                    } else {
                        _word_buffer.append(part);
                    }
                }
            }

            ks::globals::sound_update();

            _text_render_prev_line_index = cursor;
            _text_render_prev_line_length = _text_render_next_line_index - _text_render_prev_line_index;

            if (is_newline) {
                // Do not try to render newline character (it invalid UTF-8 char)
                _text_render_prev_line_length--;
            }

            // BN_ASSERT(_text_render_prev_line_index + _text_render_prev_line_length <= message.size(), "Finalized line substring out of bounds");

            bn::string_view animated_line(message.substr(cursor, _text_render_prev_line_length));

            // BN_LOG("Animated: ", animated_line);
            BN_LOG("  ", animated_line);
            if (!_animated_text_sprites->empty()) {
                // BN_LOG("Animated sprites not empty. clear");
                _animated_text_sprites->clear();
            }
            render_text_by_chunks_with_updates<128>(
                0, _text_render_line * 12,
                animated_line,
                *_animated_text_sprites,
                quoted_start ? "\"" : "",
                (quoted_end && _text_render_next_line_index == message.size()) ? "\"" : "",
                true && !immediately
            );

            write_animation();
        }

        template <int SpritePtrSize>
        void render_text_by_chunks_with_updates(
            int x,
            int y,
            bn::string_view buffer,
            bn::vector<bn::sprite_ptr, SpritePtrSize>& sprite_vector,
            bn::string_view prefix,
            bn::string_view suffix,
            bool one_sprite_per_character = true,
            unsigned char chunk_size = 8
            ) {
            // Set text generator settings
            _text_generator->set_one_sprite_per_character(one_sprite_per_character);

            // Start rendering position
            unsigned char current_x = x;

            // Tilesprites to hide from position
            unsigned short sprite_vector_start = sprite_vector.size();

            // Render prefix if provided
            if (!prefix.empty()) {
                _text_generator->generate(
                    -ks::device::screen_width_half + 10 + current_x,
                    ks::device::screen_height_half - 36 + y,
                    prefix,
                    sprite_vector
                    );
                current_x += _text_generator->width(prefix);
            }

            // Render text in chunks
            if (DRAW_PACKED_SPRITES_IN_ONE_CHUNK && !one_sprite_per_character) {
                _text_generator->generate(
                    -ks::device::screen_width_half + 10 + current_x,
                    ks::device::screen_height_half - 36 + y,
                    buffer,
                    sprite_vector
                    );

                ks::globals::sound_update();

                // Update horizontal position
                current_x += _text_generator->width(buffer);
            } else {
                int index = 0;
                while (index < buffer.size()) {
                    bn::string<32> chunk; // Temporary string for a single chunk. SHOULD BE SIZE CHUNK * 4, ALSO SEE ASSERTS BELOW
                    chunk.clear();
                    int chunk_length = 0; // Number of valid UTF-8 characters added to the chunk

                    // Extract valid UTF-8 characters up to chunk_size
                    while (index < buffer.size() && chunk_length < chunk_size) {
                        unsigned char c = static_cast<unsigned char>(buffer[index]);
                        unsigned char char_size = get_char_size(c);
                        BN_ASSERT(char_size > 0 && char_size <= 4, "Invalid UTF-8 character size");
                        BN_ASSERT(index + char_size <= buffer.size(), "UTF-8 character exceeds buffer size");

                        // Ensure there are enough bytes left for this character
                        if (index + char_size <= buffer.size()) {
                            for (int i = 0; i < char_size; ++i) {
                                chunk.push_back(buffer[index + i]);
                            }
                            index += char_size; // Advance the index
                            ++chunk_length; // Count the character
                        } else {
                            // BN_ERROR("Incomplete character at the end of the buffer");
                            return;
                        }
                    }

                    // Generate sprites for the chunk
                    BN_ASSERT(buffer.size() <= SpritePtrSize, "Buffer size exceeds limit for rendering");
                    BN_ASSERT(chunk.size() <= 32, "Chunk size exceeds limit");
                    if (!chunk.empty()) {
                        // BN_LOG("Add chunk [", chunk, "]");
                        // BN_LOG("Spirtes used/available: ", bn::sprites_manager.);
                        // BN_LOG("Static size: ", _finalized_text_sprites->size());
                        // BN_LOG("Animated size: ", _animated_text_sprites->size());
                        _text_generator->generate(
                            -ks::device::screen_width_half + 10 + current_x,
                            ks::device::screen_height_half - 36 + y,
                            chunk,
                            sprite_vector
                            );

                        // Update horizontal position
                        current_x += _text_generator->width(chunk);
                    }

                    ks::globals::sound_update();
                }
            }

            for (unsigned short i = sprite_vector_start; i < sprite_vector.size(); i++) {
                sprite_vector.at(i).set_visible(false);
            }

            // Render suffix if provided
            if (!suffix.empty()) {
                _text_generator->generate(
                    -ks::device::screen_width_half + 10 + current_x,
                    ks::device::screen_height_half - 36 + y,
                    suffix,
                    sprite_vector
                    );
                current_x += _text_generator->width(prefix);
                sprite_vector.back().set_visible(false);
            }
        }

        void hide_animated_sprites() {
            for (auto& sprite : *_animated_text_sprites) {
                if (sprite.visible()) {
                    sprite.set_visible(false);
                }
            }
        }

        void show_message_sprites() {
            for (auto& sprite : *_animated_text_sprites) {
                if (!sprite.visible()) {
                    sprite.set_visible(true);
                }
            }
        }

        void write_animation() {
            _text_render_timer.restart();
            _is_immediately = false;
            _is_writing = true;
        }

        void write_immediately() {
            _text_render_timer.restart();
            // Increases the audio player rate
            // player_setRate(2);
            while (_text_render_next_line_index != _remaining_message.size() && _text_render_line < ks::defaults::text_render_max_lines_count - 1) {
                _text_render_line++;
                render_message_line(_text_render_next_line_index, true);
            }
            show_message_sprites();
            // player_setRate(0);
            _is_immediately = true;
            _is_writing = false;
        }

        inline unsigned char BN_CODE_IWRAM get_char_size(unsigned char c) {
            if ((c & 0x80) == 0) {
                return 1;
            } else if ((c & 0xE0) == 0xC0) {
                return 2;
            } else if ((c & 0xF0) == 0xE0) {
                return 3;
            } else if ((c & 0xF8) == 0xF0) {
                return 4;
            }
            BN_ERROR("Unknown char size");
            return 1;
        }

        void update()
        {
            if (_is_question) {
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
                    _is_finished = true;
                }
                return;
            }

            if (_is_writing) {
                if (bn::keypad::a_pressed() || is_skipping()) {
                    write_immediately();
                } else {
                    if (_animated_text_sprites->size() > 0 && _text_render_timer.elapsed_ticks() < _animated_text_sprites->size() * ks::defaults::text_render_char_ticks) {
                        // Animating
                        int i = 0;
                        for (auto& sprite : *_animated_text_sprites) {
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
                    if (bn::keypad::a_pressed() || is_skipping()) {
                        _is_finished = true;
                    }
                } else {
                    // There is more pages to display
                    if (bn::keypad::a_pressed() || is_skipping()) {
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
        bn::vector<bn::sprite_ptr, 64>* _finalized_text_sprites;
        bn::vector<bn::sprite_ptr, 128>* _animated_text_sprites;

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
        unsigned char _answer_selected;
        unsigned short _answer_loop_cycle_counter;
        unsigned short _answer_pause_cycle_counter;

        // Talkbox related stuff
        bn::optional<bn::sprite_ptr> talkbox1;
        bn::optional<bn::sprite_ptr> talkbox2;
        bn::optional<bn::sprite_ptr> talkbox3;
        bn::optional<bn::sprite_ptr> talkbox4;
        bn::vector<bn::sprite_ptr, 8> talkbox_actor_sprites;
        bn::vector<bn::sprite_ptr, 8> _title_sprites;

        bn::timer _text_render_timer;
        bn::string<1024> _remaining_message;
        bn::string<64> _word_buffer; // May be resize form verylongphraseswithoutspaces

        const character_definition* _actor = nullptr;  // Store pointer to character definition

        // Palettes
        bn::sprite_palette_item original_palette_item;
        bn::sprite_palette_item beige_palette_item;
        bn::sprite_palette_item beige_selected_palette_item;
    };

}

#endif
