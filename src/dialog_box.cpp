#include "dialog_box.h"

#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"

namespace ks {
    template<int LinesPerPage>
    void dialog_box<LinesPerPage>::update(const bool force_render) {
        if (finished) {
            return;
        }

        const bool user_skip = bn::keypad::b_held();
        const bool user_advance = bn::keypad::a_pressed();
        const int render_speed = (0xFF - globals::settings.text_speed) / 34;

        if (waiting_for_input) {
            if (text_wait_map.contains(current_char_index)) {
                // Wait for N ticks or user input.
                if (text_wait_ticks > 0 && !(user_skip || user_advance || force_render)) {
                    // Do not decrement timer if it set to 0xFFFF - wait only for user input instead.
                    if (text_wait_ticks != 0xFFFF) {
                        text_wait_ticks--;
                    }
                } else {
                    text_wait_ticks = 0;
                    waiting_for_input = false;
                    next_render_cooldown = 0;
                    text_wait_map.erase(current_char_index);

                    if (current_char_index == 0) {
                        // Workaround for wait at the beginning of line (prevent wait-loop)
                        current_char_index++;
                    }
                }
                return;
            }
            if (user_advance || user_skip || force_render || nowait) {
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

        if (fast) {
            if (_infinite_render) {
                BN_ERROR("{fast} tag isn't supported for infinite renderer.");
            }

            text_chunk_sprites.clear();
            text_single_sprites.clear();
            current_char_index = 0;

            const int chunked_lines_from = (_text_parser.fast_ends_on_line() / LinesPerPage) * LinesPerPage;
            const int chunked_lines_to = _text_parser.fast_ends_on_line();
            for (int i = chunked_lines_from; i < chunked_lines_to; i++) {
                draw_line(i, false);
            }
            draw_line(chunked_lines_to, true);

            current_line_index = chunked_lines_to;
            BN_LOG("fast done");
        } else {
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
        }

        if (text_wait_map.contains(current_char_index)) {
            // Set wait for N ticks or user input.
            text_wait_ticks = text_wait_map.at(current_char_index);
            waiting_for_input = true;
            return;
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
        // TODO: remove pointer to back-reference and use generator directly
        bn::sprite_text_generator *tg = &_default_text_generator.value();
        int x_offset = 0;
        bool line_found = false;
        text_wait_map.clear();

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
                        tg->set_palette_item(globals::text_palettes::original);
                    } else if (cmd.param == 1) {
                        tg->set_palette_item(globals::text_palettes::bold(globals::text_palettes::original));
                    }
                }
                if (cmd.command == RC_FAST) {
                    fast = false;
                    BN_LOG("Unset fast flag");
                }
                if (cmd.command == RC_WAIT && one_sprite_per_character) {
                    if (cmd.param != 0xFF) {
                        text_wait_map.insert(text_single_sprites.size(), cmd.param * 6);
                        BN_LOG("Added waiting at char num ", text_single_sprites.size(), " to ", cmd.param * 6, " ticks.");
                    } else {
                        text_wait_map.insert(text_single_sprites.size(), 0xFFFF);
                        BN_LOG("Added waiting at char num ", text_single_sprites.size(), " to user input.");
                    }
                }
                if (cmd.command == RC_TEXT_OUT) {
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
                            sprite.set_visible(false || fast);
                        }
                        if (fast) {
                            current_char_index = text_single_sprites.size() - 1;
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
