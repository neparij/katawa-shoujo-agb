#ifndef KS_TEXT_PARSER_H
#define KS_TEXT_PARSER_H

#include "bn_string.h"
#include "bn_string_view.h"
#include "bn_vector.h"
#include "bn_sprite_text_generator.h"

typedef unsigned char render_cmd_t;
#define RC_START_LINE ((render_cmd_t) 0)
#define RC_TEXT_OUT ((render_cmd_t) 1)
#define RC_SET_FONT ((render_cmd_t) 2)
#define RC_SET_PALETTE ((render_cmd_t) 3)
#define RC_IMMEDIATE_START ((render_cmd_t) 4)
#define RC_IMMEDIATE_END ((render_cmd_t) 5)
#define RC_WAIT ((render_cmd_t) 6)
#define RC_NO_WAIT ((render_cmd_t) 7)


namespace ks::text {
    /// SOH - sets cursor to render text by chars
    static constexpr char CTL_FAST = 0x01;
    /// STX - starts bold text (switch spritefont)
    static constexpr char CTL_BOLD_START = 0x02;
    /// ETX - ends bold text (restore spritefont)
    static constexpr char CTL_BOLD_END = 0x03;
    /// EOT - starts strikethrough text (switch spritefont?)
    static constexpr char CTL_STRIKE_START = 0x04;
    /// ENQ - ends strikethrough text (restore spritefont?)
    static constexpr char CTL_STRIKE_END = 0x05;
    /// ACK - wait command (next byte is count of 1/10 seconds to wait)
    static constexpr char CTL_WAIT = 0x06;
    /// BEL - do not wait for user input to continue dialogue
    static constexpr char CTL_NOWAIT = 0x07;
    /// BS - sets the color (switch spritepalette, next byte is palette index)
    static constexpr char CTL_COLOR_START = 0x08;
    /// HT - restore color (switch spritepalette)
    static constexpr char CTL_COLOR_END = 0x09;

    static constexpr char MAX_CTL_CHAR = CTL_COLOR_END;

    constexpr bn::string_view SV_NULL = "";

    constexpr int BUFFER_SIZE = 128;

    struct render_cmd {
        render_cmd_t command{};
        unsigned int param{};
        bn::string_view view;
    };


    template<int MaxLines>
    class parser {
    public:
        explicit parser(bn::istring& text_ref, bn::sprite_text_generator &text_generator)
            : _text(text_ref),
              _text_generator(text_generator) {
        }

        void generate_lines();

        void generate_commands();

        static unsigned char get_char_size(unsigned char c);

        [[nodiscard]] bn::vector<bn::string_view, MaxLines> &lines() {
            return _lines;
        }

        [[nodiscard]] const bn::vector<bn::string_view, MaxLines> &lines() const {
            return _lines;
        }

        [[nodiscard]] bn::vector<render_cmd, MaxLines * 4> &commands() {
            return _commands;
        }

        [[nodiscard]] const bn::vector<render_cmd, MaxLines * 4> &commands() const {
            return _commands;
        }

        [[nodiscard]] bn::vector<render_cmd, MaxLines * 4> commands(int line_index) const {
            bn::vector<render_cmd, MaxLines * 4> line_commands;
            for (const auto& cmd : _commands) {
                if (cmd.command == RC_START_LINE && cmd.param == line_index) {
                    line_commands.push_back(cmd);
                } else if (!line_commands.empty()) {
                    if (cmd.command == RC_START_LINE) {
                        break;
                    }
                    line_commands.push_back(cmd);
                }
            }
            return line_commands;
        }

    private:
        bn::istring &_text;
        bn::sprite_text_generator &_text_generator;
        bn::vector<bn::string_view, MaxLines> _lines;
        bn::vector<render_cmd, MaxLines * 4> _commands;
        bn::string<BUFFER_SIZE> buffer;
    };
}


#endif //KS_TEXT_PARSER_H
