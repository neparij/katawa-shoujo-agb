#include "text_parser.h"

#include "bn_assert.h"
#include "bn_log.h"
#include "bn_string_view.h"
#include "bn_string.h"
#include "constants.h"


namespace ks::text {
    /**
     * @brief Generates wrapped text lines from the internal `_text`.
     */
    template<int MaxLines>
    void parser<MaxLines>::generate_lines(const int max_width) {
        _lines.clear();
        BN_ASSERT(!_text.empty(), "Text should not be empty");

        buffer.clear();
        bn::istring_base istring(buffer);
        bn::ostringstream buffer_stream(istring);

        int cursor_i = 0;
        bool done = false;


        bn::string_view::pointer cursor = _text.data();
        bn::string_view::size_type cursor_end = 0;

        while (!done) {
            BN_ASSERT(_lines.size() != MaxLines, "Too many lines");

            const int ch_length = get_char_size(*(cursor + cursor_i));
            bn::string<4> part = bn::string_view(cursor + cursor_i, ch_length);
            cursor_i += ch_length;

            const bool is_eol = cursor + cursor_i == _text.end();
            const bool is_space = part.starts_with(32);
            const bool is_newline = part.starts_with(10);
            const bool is_control_char = part.starts_with(CTL_FAST) ||
                                         part.starts_with(CTL_BOLD_START) ||
                                         part.starts_with(CTL_BOLD_END) ||
                                         part.starts_with(CTL_STRIKE_START) ||
                                         part.starts_with(CTL_STRIKE_END) ||
                                         part.starts_with(CTL_WAIT) ||
                                         part.starts_with(CTL_NOWAIT) ||
                                         part.starts_with(CTL_COLOR_START) ||
                                         part.starts_with(CTL_COLOR_END);

            if (is_eol || is_space || is_newline) {
                const auto buffer_width = _text_generator.width(buffer_stream.view());

                if (buffer_width < max_width) {
                    // Save the possible line break
                    cursor_end = cursor_i;
                    if (is_eol || is_newline) {
                        const bool ends_with_space = *(cursor + cursor_end - 1) == ' ';
                        const bool ends_with_newline = *(cursor + cursor_end - 1) == '\n';
                        _lines.push_back(
                            bn::string_view(cursor, cursor_end + (ends_with_space || ends_with_newline ? -1 : 0)));
                        buffer.clear();
                        istring = bn::istring_base(buffer);
                        buffer_stream = bn::ostringstream(istring);
                        cursor += cursor_end;
                        cursor_end = 0;
                        cursor_i = 0;
                        if (is_eol) {
                            done = true;
                        }
                    }
                    if (is_space) {
                        buffer_stream.append(part);
                    }
                } else {
                    BN_ASSERT(!buffer_stream.empty(), "Buffer stream is empty when breaking line");
                    const bool ends_with_space = *(cursor + cursor_end - 1) == ' ';
                    const bool ends_with_newline = *(cursor + cursor_end - 1) == '\n';
                    _lines.push_back(
                        bn::string_view(cursor, cursor_end + (ends_with_space || ends_with_newline ? -1 : 0)));
                    buffer.clear();
                    istring = bn::istring_base(buffer);
                    buffer_stream = bn::ostringstream(istring);
                    cursor += cursor_end;
                    cursor_end = 0;
                    cursor_i = 0;
                }
            } else {
                if (!is_control_char) {
                    if (cursor_end == 0) {
                        const auto buffer_width = _text_generator.width(buffer_stream.view());
                        const auto part_width = _text_generator.width(part);
                        if (buffer_width + part_width < max_width) {
                            buffer_stream.append(part);
                        } else {
                            // If this is a single long word that exceeds the line width, we have no choice but to break it
                            _lines.push_back(bn::string_view(cursor, cursor_i - ch_length));
                            buffer.clear();
                            istring = bn::istring_base(buffer);
                            buffer_stream = bn::ostringstream(istring);
                            cursor += cursor_i - ch_length;
                            cursor_end = 0;
                            cursor_i = 0;
                        }
                    } else {
                        buffer_stream.append(part);
                    }
                }
            }
        }
    }

    /**
     * @brief Generates rendering commands from the internal `_lines`.
     */
    template<int MaxLines>
    void parser<MaxLines>::generate_commands() {
        _commands.clear();
        BN_ASSERT(!_text.empty(), "Text should not be empty");
        BN_ASSERT(!_lines.empty(), "Text-referenced lines should not be empty");

        bool bold_flag = false;
        bool strike_flag = false;
        unsigned char palette_index = 0;
        unsigned int line_index = 0;

        for (const auto line: _lines) {
            if (!line.empty()) {
                BN_ASSERT(_commands.size() != MaxLines * 4, "Too many commands");

                _commands.push_back({RC_START_LINE, line_index, SV_NULL});
                if (bold_flag) {
                    _commands.push_back({RC_SET_FONT, 1, SV_NULL});
                }
                if (palette_index != 0) {
                    _commands.push_back({RC_SET_PALETTE, palette_index, SV_NULL});
                }
                if (strike_flag) {
                    BN_ERROR("TODO: STRIKETHROUGH not implemented");
                }
                int offset = 0;
                for (int i = 0; i < line.size();) {
                    const auto first_byte = static_cast<unsigned char>(line.at(i));
                    const int char_size = get_char_size(first_byte);

                    if (first_byte <= MAX_CTL_CHAR) {
                        _commands.push_back({RC_TEXT_OUT, 0, bn::string_view(line.data() + offset, i - offset)});
                        offset += char_size;
                        if (first_byte == CTL_FAST) {
                            _commands.insert(_commands.cbegin(), {RC_IMMEDIATE_START, 0, SV_NULL});
                            _commands.push_back({RC_IMMEDIATE_END, 0, SV_NULL});
                        }
                        if (first_byte == CTL_BOLD_START) {
                            _commands.push_back({RC_SET_FONT, 1, SV_NULL});
                            bold_flag = true;
                        }
                        if (first_byte == CTL_BOLD_END) {
                            _commands.push_back({RC_SET_FONT, 0, SV_NULL});
                            bold_flag = false;
                        }
                        if (first_byte == CTL_STRIKE_START || first_byte == CTL_STRIKE_END) {
                            BN_ERROR("TODO: STRIKETHROUGH not implemented");
                        }
                        if (first_byte == CTL_WAIT) {
                            BN_ASSERT(char_size == 2, "CTL_WAIT must be followed by a byte parameter");
                            const auto wait_time = static_cast<unsigned char>(line.at(i + 1));
                            _commands.push_back({RC_WAIT, wait_time, SV_NULL});
                        }
                        if (first_byte == CTL_NOWAIT) {
                            _commands.push_back({RC_NO_WAIT, 0, SV_NULL});
                        }
                        if (first_byte == CTL_COLOR_START) {
                            BN_ASSERT(char_size == 2, "CTL_COLOR_START must be followed by a byte parameter");
                            palette_index = static_cast<unsigned char>(line.at(i + 1));
                            _commands.push_back({RC_SET_PALETTE, palette_index, SV_NULL});
                        }
                        if (first_byte == CTL_COLOR_END) {
                            palette_index = 0;
                            _commands.push_back({RC_SET_PALETTE, palette_index, SV_NULL});
                        }

                        offset = i + char_size;
                    }

                    i += char_size;
                }

                _commands.push_back({RC_TEXT_OUT, 0, bn::string_view(line.data() + offset, line.size() - offset)});
            }
            line_index++;
        }
    }

    /**
     * @brief Determines the byte length of a UTF-8 encoded character.
     *
     * This function inspects the leading byte of a UTF-8 character
     * and returns the number of bytes that character occupies.
     *
     * @param c The first byte of the UTF-8 character.
     * @return unsigned char The size of the character in bytes (1 to 4).
     *
     * @note If the byte does not match any valid UTF-8 leading byte pattern,
     *       an error is triggered via BN_ERROR and 1 is returned by default.
     */
    template<int MaxLines>
    unsigned char BN_CODE_IWRAM parser<MaxLines>::get_char_size(const unsigned char c) {
        if (c == CTL_WAIT || c == CTL_COLOR_START) {
            return 2;
        }
        if ((c & 0x80) == 0) {
            return 1;
        }
        if ((c & 0xE0) == 0xC0) {
            return 2;
        }
        if ((c & 0xF0) == 0xE0) {
            return 3;
        }
        if ((c & 0xF8) == 0xF0) {
            return 4;
        }
        BN_ERROR("Unknown char size");
        return 1;
    }

    template class parser<1>;
    template class parser<32>;
}
