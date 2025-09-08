#include "dialog_box.h"
#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"

#include "constants.h"

namespace ks {
    void dialog_box::update() {
        if (finished) {
            return;
        }

        const bool user_skip = bn::keypad::b_held();
        const bool user_advance = bn::keypad::a_pressed();
        constexpr int lines_per_page = 3;
        constexpr int render_speed = 3;

        if (waiting_for_input) {
            if (user_advance || user_skip) {
                BN_LOG("current_line_index: ", current_line_index);
                if (current_line_index >= lines_count()) {
                    finished = true;
                    waiting_for_input = false;
                    return;
                }

                waiting_for_input = false;
                current_page_index++;
                current_char_index = 0;
                text_chunk_sprites.clear();
            }
            return;
        }

        if (user_skip || user_advance) {
            text_chunk_sprites.clear();
            text_single_sprites.clear();
            current_char_index = 0;

            const int page_start = (current_page_index * lines_per_page);
            const int page_end = bn::min(page_start + lines_per_page, lines_count());
            for (int i = page_start; i < page_end; i++) {
                draw_line(i, false);
            }
            current_line_index = page_end;
            waiting_for_input = true;
            return;
        }

        if (next_render_cooldown > 0) {
            next_render_cooldown--;
            return;
        }

        if (current_char_index == 0) {
            text_single_sprites.clear();

            if (current_line_index % lines_per_page == 0) {
                text_chunk_sprites.clear();
            } else {
                draw_line(current_line_index - 1, false);
            }
            draw_line(current_line_index, true);
        }

        if (current_char_index < text_single_sprites.size()) {
            current_char_index++;
            for (int i = 0; i < current_char_index; i++) {
                text_single_sprites.at(i).set_visible(true);
            }
            next_render_cooldown = render_speed;
        } else {
            current_line_index++;
            current_char_index = 0;

            if (current_line_index >= lines_count()) {
                waiting_for_input = true;
                return;
            }

            if (current_line_index % lines_per_page == 0) {
                waiting_for_input = true;
            }
        }
    }

    void dialog_box::draw_line(const int line_index, const bool one_sprite_per_character) {
        bn::sprite_text_generator *tg = &_default_text_generator;
        int x_offset = 0;
        bool line_found = false;

        for (const auto &cmd: _text_parser.commands()) {
            if (cmd.command == RC_START_LINE && cmd.param == line_index) {
                line_found = true;
                tg = &_default_text_generator;
            } else if (line_found) {
                if (cmd.command == RC_START_LINE) {
                    break;
                }
                if (cmd.command == RC_SET_FONT) {
                    if (cmd.param == 0) {
                        BN_LOG("Set font: default");
                        tg = &_default_text_generator;
                    } else if (cmd.param == 1) {
                        BN_LOG("Set font: BOLD");
                        tg = &_bold_text_generator;
                    }
                }
                if (cmd.command == RC_TEXT_OUT) {
                    BN_LOG("X offset: ", x_offset);
                    tg->set_left_alignment();
                    tg->set_one_sprite_per_character(one_sprite_per_character);
                    tg->set_palette_item(globals::text_palettes::original);
                    if (one_sprite_per_character) {
                        tg->generate(
                            _text_start_position.x() + x_offset,
                            _text_start_position.y() + (line_index % 3) * 12,
                            cmd.view,
                            text_single_sprites);
                        for (auto &sprite: text_single_sprites) {
                            sprite.set_visible(false);
                        }
                    } else {
                        BN_LOG("Start position: ", _text_start_position.x() + x_offset, ", ", _text_start_position.y() + (line_index % 3) * 12);
                        tg->generate(
                            _text_start_position.x() + x_offset,
                            _text_start_position.y() + (line_index % 3) * 12,
                            cmd.view,
                            text_chunk_sprites);
                    }
                    x_offset += tg->width(cmd.view);
                    BN_LOG("Draw chunk: ", line_index, " '", cmd.view, "'");
                }
            }
        }

        if (!line_found) {
            BN_ERROR("Line not found: ", line_index);
        }
    }
}
