#ifndef TEXT_PARSER_TESTS_H
#define TEXT_PARSER_TESTS_H


#include "bn_sprite_text_generator.h"
#include "bn_string.h"
#include "testing/suite.h"

#include "../src/text_parser.h"
#include "fonts_info.h"
#include "../../src/constants.h"

class text_parser_tests : public test_suite {
public:
    text_parser_tests() : test_suite("text_render") {
    }

    void run() {
        test_case("get_char_size", [this] {
            // Check UTF-8 character size detection
            const auto s1 = reinterpret_cast<const unsigned char *>("A");
            KS_ASSERT(renderer_inst.get_char_size(s1[0]) == 1, "A");

            const auto s2 = reinterpret_cast<const unsigned char *>("ñ"); // UTF-8: 0xC3 0xB1
            KS_ASSERT(renderer_inst.get_char_size(s2[0]) == 2, "ñ");

            const auto s3 = reinterpret_cast<const unsigned char *>("あ"); // UTF-8: 0xE3 0x81 0x82
            KS_ASSERT(renderer_inst.get_char_size(s3[0]) == 3, "あ");

            const auto s4 = reinterpret_cast<const unsigned char *>("𐍈"); // UTF-8: 0xF0 0x90 0x8D 0x88
            KS_ASSERT(renderer_inst.get_char_size(s4[0]) == 4, "𐍈");
        });

        test_case("generate_lines, single line", [this] {
            text = "Single line";
            renderer_inst.generate_lines(max_width);
            KS_ASSERT(renderer_inst.lines().size() == 1, "single line should have one line");
            KS_ASSERT(renderer_inst.lines().at(0) == "Single line", "single line content should match");
        });

        test_case("generate_lines, multiple lines", [this] {
            text = "Multiple\nbeautiful lines";
            renderer_inst.generate_lines(max_width);
            KS_ASSERT(renderer_inst.lines().size() == 2, "string with newline should have two lines");
            KS_ASSERT(renderer_inst.lines().at(0) == "Multiple");
            KS_ASSERT(renderer_inst.lines().at(1) == "beautiful lines");
        });

        test_case("generate_lines, newline character", [this] {
            text = "\nMiddle";
            renderer_inst.generate_lines(max_width);
            KS_ASSERT(renderer_inst.lines().size() == 2, "string starting with newline should have two lines");
            KS_ASSERT(renderer_inst.lines().at(0).empty(), "first line should be empty");
            KS_ASSERT(renderer_inst.lines().at(1) == "Middle", "second line content should match");
        });

        test_case("generate_lines, word wrapping", [this] {
            text = "Лёгкий ветерок колышет голые ветви над головой, заставляя их шуметь, словно деревянные колокольчики.";
            renderer_inst.generate_lines(max_width);
            KS_ASSERT(renderer_inst.lines().size() == 3, "long text should be broken into several lines");
            KS_ASSERT(renderer_inst.lines().at(0) == "Лёгкий ветерок колышет голые ветви");
            KS_ASSERT(renderer_inst.lines().at(1) == "над головой, заставляя их шуметь,");
            KS_ASSERT(renderer_inst.lines().at(2) == "словно деревянные колокольчики.");
        });

        test_case("generate_lines, word chopping", [this] {
            text = "Aaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhhhhhggggggggggghhhhhhhh……";
            renderer_inst.generate_lines(max_width);
            KS_ASSERT(renderer_inst.lines().size() == 2, "long unbroken text should be split");
            KS_ASSERT(renderer_inst.lines().at(0) == "Aaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhh");
            KS_ASSERT(renderer_inst.lines().at(1) == "hhhggggggggggghhhhhhhh……");
        });

        test_case("generate_lines, control characters", [this] {
            text = "Text with ""\x02""bold""\x03"".""\x06""\x05""Wait 0.5 sec";
            renderer_inst.generate_lines(max_width);
            KS_ASSERT(renderer_inst.lines().size() == 1, "break_to_lines size");
            KS_ASSERT(renderer_inst.lines().at(0) == "Text with ""\x02""bold""\x03"".""\x06""\x05""Wait 0.5 sec", "break_to_lines line 1");
        });

        // TODO: rewrite it. Bad test design.
        test_case("generate_commands", [this] {
            text = "Text with ""\x02""bold""\x03"".""\x06""\x05""Wait 0.5 sec";
            renderer_inst.generate_lines(max_width);
            renderer_inst.generate_commands();
            KS_ASSERT(renderer_inst.commands().size() == 8, "parse_to_commands size");
            KS_ASSERT(renderer_inst.commands().at(0).command == RC_START_LINE, "parse_to_commands cmd 0");
            KS_ASSERT(renderer_inst.commands().at(1).command == RC_TEXT_OUT, "parse_to_commands cmd 1");
            KS_ASSERT(renderer_inst.commands().at(1).view == "Text with ", "parse_to_commands cmd 1 view");
            KS_ASSERT(renderer_inst.commands().at(2).command == RC_SET_FONT, "parse_to_commands cmd 2");
            KS_ASSERT(renderer_inst.commands().at(2).param == 1, "parse_to_commands cmd 2 param");
            KS_ASSERT(renderer_inst.commands().at(3).command == RC_TEXT_OUT, "parse_to_commands cmd 3");
            KS_ASSERT(renderer_inst.commands().at(3).view == "bold", "parse_to_commands cmd 3 view");
            KS_ASSERT(renderer_inst.commands().at(4).command == RC_SET_FONT, "parse_to_commands cmd 4");
            KS_ASSERT(renderer_inst.commands().at(4).param == 0, "parse_to_commands cmd 4 param");
            KS_ASSERT(renderer_inst.commands().at(5).command == RC_TEXT_OUT, "parse_to_commands cmd 5");
            KS_ASSERT(renderer_inst.commands().at(5).view == ".", "parse_to_commands cmd 5 view");
            KS_ASSERT(renderer_inst.commands().at(6).command == RC_WAIT, "parse_to_commands cmd 6");
            KS_ASSERT(renderer_inst.commands().at(6).param == 5, "parse_to_commands cmd 6 param");
            KS_ASSERT(renderer_inst.commands().at(7).command == RC_TEXT_OUT, "parse_to_commands cmd 7");
            KS_ASSERT(renderer_inst.commands().at(7).view == "Wait 0.5 sec", "parse_to_commands cmd 7 view");

            text = "It's nice to meet you, too!""\x06""\x05"" But~!";
            renderer_inst.generate_lines(max_width);
            renderer_inst.generate_commands();
            KS_ASSERT(renderer_inst.commands().size() == 4, "parse_to_commands size");
            KS_ASSERT(renderer_inst.commands().at(0).command == RC_START_LINE, "parse_to_commands cmd 0");
            KS_ASSERT(renderer_inst.commands().at(1).command == RC_TEXT_OUT, "parse_to_commands cmd 1");
            KS_ASSERT(renderer_inst.commands().at(1).view == "It's nice to meet you, too!", "parse_to_commands cmd 1 view");
            KS_ASSERT(renderer_inst.commands().at(2).command == RC_WAIT, "parse_to_commands cmd 2");
            KS_ASSERT(renderer_inst.commands().at(2).param == 5, "parse_to_commands cmd 2 param");
            KS_ASSERT(renderer_inst.commands().at(3).command == RC_TEXT_OUT, "parse_to_commands cmd 3");
            KS_ASSERT(renderer_inst.commands().at(3).view == " But~!", "parse_to_commands cmd 3 view");

            text = "It's nice to meet you, too! But~!""\x01"", I'm not Hakamichi, I'm Misha! This is Hakamichi. Shicchan~!";
            renderer_inst.generate_lines(max_width);
            renderer_inst.generate_commands();
            KS_ASSERT(renderer_inst.commands().size() == 9, "parse_to_commands size");
            KS_ASSERT(renderer_inst.commands().at(0).command == RC_IMMEDIATE_START, "parse_to_commands cmd 0");
            KS_ASSERT(renderer_inst.commands().at(1).command == RC_START_LINE, "parse_to_commands cmd 1");
            KS_ASSERT(renderer_inst.commands().at(1).param == 0, "parse_to_commands cmd 1 param");
            KS_ASSERT(renderer_inst.commands().at(2).command == RC_TEXT_OUT, "parse_to_commands cmd 2");
            KS_ASSERT(renderer_inst.commands().at(2).view == "It's nice to meet you, too! But~!", "parse_to_commands cmd 2 view");
            KS_ASSERT(renderer_inst.commands().at(3).command == RC_IMMEDIATE_END, "parse_to_commands cmd 3");
            KS_ASSERT(renderer_inst.commands().at(4).command == RC_TEXT_OUT, "parse_to_commands cmd 4");
            KS_ASSERT(renderer_inst.commands().at(4).view == ", I'm not", "parse_to_commands cmd 4 view");
            KS_ASSERT(renderer_inst.commands().at(5).command == RC_START_LINE, "parse_to_commands cmd 5");
            KS_ASSERT(renderer_inst.commands().at(5).param == 1, "parse_to_commands cmd 5 param");
            KS_ASSERT(renderer_inst.commands().at(6).command == RC_TEXT_OUT, "parse_to_commands cmd 6");
            KS_ASSERT(renderer_inst.commands().at(6).view == "Hakamichi, I'm Misha! This is Hakamichi.", "parse_to_commands cmd 6 view");
            KS_ASSERT(renderer_inst.commands().at(7).command == RC_START_LINE, "parse_to_commands cmd 7");
            KS_ASSERT(renderer_inst.commands().at(7).param == 2, "parse_to_commands cmd 7 param");
            KS_ASSERT(renderer_inst.commands().at(8).command == RC_TEXT_OUT, "parse_to_commands cmd 8");
            KS_ASSERT(renderer_inst.commands().at(8).view == "Shicchan~!", "parse_to_commands cmd 8 view");

        });
    }

private:
    bn::string<512> text;
    bn::sprite_text_generator text_generator{font_playtime_sprite_font};
    ks::text::parser<32> renderer_inst{text, text_generator};
    const int max_width = ks::device::screen_width - 20;
};

#endif //TEXT_PARSER_TESTS_H
