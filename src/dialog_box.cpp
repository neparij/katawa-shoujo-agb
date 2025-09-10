#include "dialog_box.h"

#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"

#include "constants.h"
#include "../../butano/butano/src/bn_display_manager.h"
#include "../../butano/butano/src/bn_sprites_manager.h"
#include "../../butano/butano/src/bn_sprite_tiles_manager.h"

namespace ks {
    template<int LinesPerPage>
    void dialog_box<LinesPerPage>::update(const bool force_render) {
        if (finished) {
            return;
        }

        const bool user_skip = bn::keypad::b_held();
        const bool user_advance = bn::keypad::a_pressed();
        constexpr int render_speed = 1;

        if (waiting_for_input) {
            if (user_advance || user_skip || force_render) {
                BN_LOG("current_line_index: ", current_line_index);
                if (current_line_index >= lines_count()) {
                    finished = true;
                    waiting_for_input = false;
                    // if (_infinite_render) {
                    //     render_offset += 12 * lines_count();
                    // }
                    return;
                }

                waiting_for_input = false;
                current_page_index++;
                current_char_index = 0;
                text_chunk_sprites.clear();
            }
            return;
        }

        if (user_skip || user_advance || force_render) {
            if (_infinite_render) {
                // Cancel previously added render_offset (because we are re-rendering all lines)
                render_offset -= 12 * (current_line_index);
                if (text_single_sprites.size() > 0) {
                    render_offset -= 12;
                }
            }

            text_chunk_sprites.clear();
            text_single_sprites.clear();
            // if (_infinite_render) {
                // globals::main_update(); // Force update to avoid tiles overusage.
            // }
            current_char_index = 0;

            const int page_start = (current_page_index * LinesPerPage);
            const int page_end = _infinite_render
                                     ? lines_count()
                                     : bn::min(page_start + LinesPerPage, lines_count());

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

            if (!_infinite_render && current_line_index % LinesPerPage == 0) {
                text_chunk_sprites.clear();
            } else if (_infinite_render && current_line_index == 0) {
                text_chunk_sprites.clear();
            } else {
                if (_infinite_render) {
                    // Remove offset added by single chars rendering, because we are re-rendering previous line
                    render_offset -= 12;
                }
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
                text_single_sprites.clear();
                if (_infinite_render) {
                    // Remove offset added by single chars rendering, because we are re-rendering the last line
                    render_offset -= 12;
                }
                draw_line(current_line_index - 1, false);
                return;
            }

            if (!_infinite_render && current_line_index % LinesPerPage == 0) {
                text_single_sprites.clear();
                draw_line(current_line_index - 1, false);
                waiting_for_input = true;
            }
        }
    }

    template<int LinesPerPage>
    void dialog_box<LinesPerPage>::draw_line(const int line_index, const bool one_sprite_per_character) {
        bn::sprite_text_generator *tg = &_default_text_generator.value();
        int x_offset = 0;
        bool line_found = false;

        for (const auto &cmd: _text_parser.commands()) {
            if (cmd.command == RC_START_LINE && cmd.param == line_index) {
                line_found = true;
                tg = &_default_text_generator.value();
            } else if (line_found) {
                if (cmd.command == RC_START_LINE) {
                    break;
                }
                if (cmd.command == RC_SET_FONT) {
                    if (cmd.param == 0) {
                        BN_LOG("Set font: default");
                        tg = &_default_text_generator.value();
                    } else if (cmd.param == 1) {
                        BN_LOG("Set font: BOLD");
                        tg = &_bold_text_generator.value();
                    }
                }
                if (cmd.command == RC_TEXT_OUT) {
                    BN_LOG("X offset: ", x_offset);
                    tg->set_left_alignment();
                    tg->set_one_sprite_per_character(one_sprite_per_character);
                    tg->set_palette_item(globals::text_palettes::original);
                    if (one_sprite_per_character) {
                        if (_infinite_render) {
                            tg->generate(
                                _text_start_position.x() + x_offset,
                                _text_start_position.y() + render_offset,
                                cmd.view,
                                text_single_sprites);
                        } else {
                            tg->generate(
                                _text_start_position.x() + x_offset,
                                _text_start_position.y() + (line_index % LinesPerPage) * 12,
                                cmd.view,
                                text_single_sprites);
                        }
                        for (auto &sprite: text_single_sprites) {
                            sprite.set_visible(false);
                        }
                    } else {
                        if (_infinite_render) {
                            tg->generate(
                                _text_start_position.x() + x_offset,
                                _text_start_position.y() + render_offset,
                                cmd.view,
                                text_chunk_sprites);
                        } else {
                            tg->generate(
                                _text_start_position.x() + x_offset,
                                _text_start_position.y() + (line_index % LinesPerPage) * 12,
                                cmd.view,
                                text_chunk_sprites);
                        }
                    }
                    x_offset += tg->width(cmd.view);
                    BN_LOG("Draw chunk: ", line_index, " '", cmd.view, "'");
                }
            }
        }

        if (_infinite_render) {
            render_offset += 12;
        }

        if (!line_found) {
            BN_ERROR("Line not found: ", line_index);
        }
    }
}
