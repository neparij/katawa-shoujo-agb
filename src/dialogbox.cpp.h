#ifndef KS_DIALOGBOX_H
#define KS_DIALOGBOX_H

#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_string.h"
#include "bn_timer.h"

#include "bn_memory.h"

#include "constants.h"
#include "globals.h"
#include "sequence/dialogitem.h"

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
            _text_render_timer.restart();
            _text_render_line = 0;
            _text_render_char = 0;
            _text_render_page = 0;
        }

        void show(ks::DialogItem* item)
        {
            _item = item;
            _title = _item->title();
            _text_render_timer.restart();
            _text_render_ticks = ks::defaults::text_render_char_ticks;
            _text_render_line = 0;
            _text_render_char = 0;
            _text_render_page = 0;

            _title_sprites.clear();
            _message_sprites.clear();

            _set_messages(_item->message());
        }

        void hide()
        {
            _title_sprites.clear();
            _message_sprites.clear();
        }

        void update()
        {
            if (ks_globals::show_memory_debug || ks_globals::show_dialog_debug) {
                _debug_sprites.clear();
            }
            if (ks_globals::show_memory_debug) {
                _text_generator->generate(-116, -72, bn::to_string<32>("IWRAM stack::") + bn::to_string<32>(bn::memory::used_stack_iwram()), _debug_sprites);
                _text_generator->generate(-116, -72+12, bn::to_string<32>("IWRAM static::") + bn::to_string<32>(bn::memory::used_static_iwram()), _debug_sprites);
                _text_generator->generate(-116, -72+24, bn::to_string<32>("EWRAM static::") + bn::to_string<32>(bn::memory::used_static_ewram()), _debug_sprites);
                _text_generator->generate(-116, -72+36, bn::to_string<32>("EWRAM alloc::") + bn::to_string<32>(bn::memory::used_alloc_ewram()), _debug_sprites);
                _text_generator->generate(-116, -72+48, bn::to_string<32>("EWRAM avail::") + bn::to_string<32>(bn::memory::available_alloc_ewram()), _debug_sprites);
            }

            if (_message_lines_count == 0) {
                return;
            }

            int page_min_line = _text_render_page * ks::defaults::text_render_max_lines_count;
            int page_max_line = bn::min(_message_lines_count, (_text_render_page + 1) * ks::defaults::text_render_max_lines_count);

            if (_text_render_char < _messages_lengths[_text_render_line]) {
                if (bn::keypad::b_held()) {
                    _text_render_line = _message_lines_count - 1;
                    _text_render_char = _messages_lengths[_text_render_line];
                    _text_render_timer.restart();
                    _text_render_ticks = ks::defaults::text_render_char_ticks;
                    _is_dirty = true;
                }
                if (bn::keypad::a_pressed()) {
                    _text_render_line = _message_lines_count - 1;
                    _text_render_char = _messages_lengths[_text_render_line] - 1;
                    _text_render_timer.restart();
                }

                if (_text_render_timer.elapsed_ticks() > _text_render_ticks) {
                    _text_render_char++;
                    _text_render_timer.restart();
                    _is_dirty = true;
                }
            } else {
                if (_text_render_line < _message_lines_count - 1) {
                    if (_text_render_line < page_max_line - 1) {
                        _text_render_timer.restart();
                        _text_render_line++;
                        _text_render_char = 0;
                        _text_render_page = _text_render_line / ks::defaults::text_render_max_lines_count;
                        _is_dirty = true;
                    } else if (_text_render_char == _messages_lengths[_text_render_line]) {
                        if (bn::keypad::a_pressed() || bn::keypad::b_held()) {
                            _text_render_page++;
                            _text_render_ticks = ks::defaults::text_render_char_ticks;
                        }
                    }
                }
            }

            if (_is_dirty) {
                _title_sprites.clear();
                _message_sprites.clear();

                _text_generator->set_left_alignment();
                _text_generator->generate(-ks::device::screen_width_half + 2, ks::device::screen_height_half - 48, _title, _title_sprites);

                int line_index = 0;
                for (auto line : _messages) {
                    if (line_index > _text_render_line) {
                        continue;
                    }

                    bn::string<128> message;
                    if (_text_render_line != line_index) {
                        message = line;
                    } else {
                        message = utf8_substring(line.c_str(), _text_render_char);
                    }

                    if (line_index < page_max_line &&
                        line_index >= page_min_line) {
                        _text_generator->generate(-ks::device::screen_width_half + 5, ks::device::screen_height_half - 36 + 12 * (line_index % ks::defaults::text_render_max_lines_count), message, _message_sprites);
                    }
                    line_index++;
                }
            }

            bool rendered = _text_render_line == _message_lines_count - 1 && _text_render_char == _messages_lengths[_text_render_line];
            bool rendered_and_a_pressed = rendered && bn::keypad::a_pressed();
            bool rendered_and_b_held_with_timer = rendered && bn::keypad::b_held() && _text_render_timer.elapsed_ticks() > _text_render_ticks;

            if (rendered_and_a_pressed || rendered_and_b_held_with_timer) {
                _item->finished(true);
            } else {
                _item->finished(false);
            }

            if (ks_globals::show_dialog_debug) {
                _text_generator->generate(-116, 0, bn::to_string<32>("P:") + bn::to_string<32>(_text_render_page) + "; L:" + bn::to_string<32>(_text_render_line) + "; C:" + bn::to_string<32>(_text_render_char) , _debug_sprites);
            }
        }

        // bool finished() {
        //     if (_message_lines_count == 0) {
        //         return true;
        //     }

        //     if (_text_render_line == _message_lines_count - 1 && _text_render_char == _messages_lengths[_text_render_line] && bn::keypad::a_pressed()) {
        //         return true;
        //     }

        //     return false;
        // }

    private:
        bn::sprite_text_generator* _text_generator;
        const bn::sprite_font& _font;
        bn::vector<bn::sprite_ptr, 16> _title_sprites;
        bn::vector<bn::sprite_ptr, 256> _message_sprites;
        bn::vector<bn::sprite_ptr, 256> _debug_sprites;
        bn::timer _text_render_timer;
        int _text_render_line;
        int _text_render_char;
        int _text_render_page;
        int _text_render_ticks;
        ks::DialogItem* _item;
        bn::string<16> _title;
        bn::string<128> _messages[32];
        int _messages_lengths[32];
        int _message_lines_count;
        bool _is_dirty = true;

        void _set_messages(const bn::string<512>& message)
        {
            for (auto& m : _messages)
            {
                m.clear();
            }

            // int line_width = 0;
            int line_index = 0;

            bn::string<128> line_buffer = "";
            bn::string<128> word_buffer = "";

            int line_buffer_w = 0;
            int word_buffer_w = 0;
            const int max_width = ks::device::screen_width - 10;

            auto utf8_message = string_to_utf8_characters(message);

            for (auto u8char : utf8_message) {
                if (u8char.data() == 10) {
                    if (!word_buffer.empty()) {
                        line_buffer.append(word_buffer); // Append pending word to the current line
                        word_buffer.clear();
                        word_buffer_w = 0;
                    }
                    _messages[line_index] = line_buffer; // Save current line
                    _messages_lengths[line_index] = utf8_length(line_buffer.c_str());
                    line_index++;
                    line_buffer.clear();
                    line_buffer_w = 0;
                    continue;
                }

                int char_width = get_character_width(u8char);
                if (u8char.data() == 32 && line_buffer_w + word_buffer_w >= max_width) {
                    // Too much for this line. Dispose the line buffer and keep word buffer for the next line.
                    _messages[line_index] = line_buffer;
                    _messages_lengths[line_index] = utf8_length(line_buffer.c_str());
                    line_index++;
                    line_buffer.clear();
                    line_buffer_w = 0;

                    word_buffer.append(utf8_character_to_string(u8char));
                    word_buffer_w += char_width;
                    if (word_buffer.length() > 0 && word_buffer.at(0) == 32) {
                        // Remove the first white-space.
                        word_buffer = word_buffer.substr(1, word_buffer.length() - 1);
                        word_buffer_w -= char_width;
                    }
                } else if (u8char.data() == 32) {
                    // This is a space. We need to transfer word buffer to line, and remain the space char in word buffer.
                    line_buffer.append(word_buffer);
                    line_buffer_w += word_buffer_w;
                    word_buffer.clear();
                    word_buffer.append(utf8_character_to_string(u8char));
                    word_buffer_w = char_width;
                } else {
                    // This is a printable character. Just append it.
                    word_buffer.append(utf8_character_to_string(u8char));
                    word_buffer_w += char_width;
                }
            }
            if (!word_buffer.empty()) {
                if (line_buffer_w + word_buffer_w >= max_width) {
                    _messages[line_index] = line_buffer;
                    _messages_lengths[line_index] = utf8_length(line_buffer.c_str());
                    line_index++;

                    if (word_buffer.length() > 0 && word_buffer.at(0) == 32) {
                        // Remove the first white-space.
                        word_buffer = word_buffer.substr(1, word_buffer.length() - 1);
                    }
                    _messages[line_index] = word_buffer;
                    _messages_lengths[line_index] = utf8_length(word_buffer.c_str());
                } else {
                    line_buffer.append(word_buffer);
                    _messages[line_index] = line_buffer;
                    _messages_lengths[line_index] = utf8_length(line_buffer.c_str());
                }
            }

            _message_lines_count = line_index + 1;
        };

        constexpr int get_character_width(const bn::utf8_character& c)
        {
            int index;
            if (c.data() < 127) {
                index = c.data() - 32;
            } else {
                index = _font.utf8_characters_ref().index(c);
            }

            return _font.character_widths_ref()[index];
        };

        bn::vector<bn::utf8_character, 512> string_to_utf8_characters(const bn::string<1024>& input_string)
        {
            bn::vector<bn::utf8_character, 512> utf8_characters;

            const char* str = input_string.c_str();
            while (*str)
            {
                bn::utf8_character utf8_char = bn::utf8_character(str);
                utf8_characters.push_back(utf8_char);
                str += utf8_char.size();
            }

            return utf8_characters;
        };

        bn::string<4> utf8_character_to_string(const bn::utf8_character& utf8_char)
        {
            bn::string<4> output_string;

            int32_t data = utf8_char.data(); // Get the UTF-8 code point data

            if (data < 0x80)
            {
                // 1-byte UTF-8 character
                output_string += static_cast<char>(data);
            }
            else if (data < 0x800)
            {
                // 2-byte UTF-8 character
                output_string += static_cast<char>(0xC0 | (data >> 6));
                output_string += static_cast<char>(0x80 | (data & 0x3F));
            }
            else if (data < 0x10000)
            {
                // 3-byte UTF-8 character
                output_string += static_cast<char>(0xE0 | (data >> 12));
                output_string += static_cast<char>(0x80 | ((data >> 6) & 0x3F));
                output_string += static_cast<char>(0x80 | (data & 0x3F));
            }
            else if (data < 0x110000)
            {
                // 4-byte UTF-8 character
                output_string += static_cast<char>(0xF0 | (data >> 18));
                output_string += static_cast<char>(0x80 | ((data >> 12) & 0x3F));
                output_string += static_cast<char>(0x80 | ((data >> 6) & 0x3F));
                output_string += static_cast<char>(0x80 | (data & 0x3F));
            }
            else
            {
                // Invalid UTF-8 character
                BN_ERROR("Invalid UTF-8 character data");
            }

            return output_string;
        };

        bn::string<128> utf8_substring(const char* str, int char_count) {
            bn::string<128> result;
            int current_count = 0;

            for (const char* ptr = str; *ptr != '\0'; ++ptr) {
                if ((*ptr & 0xC0) != 0x80) {  // Not a continuation byte
                    if (current_count == char_count) {
                        break;
                    }
                    current_count++;
                }
                result += *ptr;  // Append the byte to the result
            }

            return result;
        };

        int utf8_length(const char* str) {
            int length = 0;
            for (const char* ptr = str; *ptr; ++ptr) {
                if ((*ptr & 0xC0) != 0x80) {  // Not a continuation byte
                    ++length;
                }
            }
            return length;
        };

    };

}

#endif
