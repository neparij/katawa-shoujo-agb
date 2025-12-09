#ifndef TEXT_PARSER_TESTS_H
#define TEXT_PARSER_TESTS_H


#include "bn_sprite_text_generator.h"
#include "bn_string.h"
#include "suite.h"

#include "../src/text_parser.h"
#include "../../src/constants.h"
#include "../../src/scenemanager.h"

class text_parser_tests : public testing::test_suite {
public:
    text_parser_tests() : test_suite("text_parser") {
    }

    void run() {
        test_case("generate_lines, single line", [this] {
            ks::globals::init_text_generators(LANG_ENGLISH);
            text = "Single line";
            renderer_inst.generate_lines(max_width);
            TEST_ASSERT(renderer_inst.lines().size() == 1, "single line should have one line");
            TEST_ASSERT(renderer_inst.lines().at(0) == "Single line", "single line content should match");
        });

        test_case("generate_lines, multiple lines", [this] {
            ks::globals::init_text_generators(LANG_ENGLISH);
            text = "Multiple\nbeautiful lines";
            renderer_inst.generate_lines(max_width);
            TEST_ASSERT(renderer_inst.lines().size() == 2, "string with newline should have two lines");
            TEST_ASSERT(renderer_inst.lines().at(0) == "Multiple");
            TEST_ASSERT(renderer_inst.lines().at(1) == "beautiful lines");
        });

        test_case("generate_lines, newline character", [this] {
            ks::globals::init_text_generators(LANG_ENGLISH);
            text = "\nMiddle";
            renderer_inst.generate_lines(max_width);
            TEST_ASSERT(renderer_inst.lines().size() == 2, "string starting with newline should have two lines");
            TEST_ASSERT(renderer_inst.lines().at(0).empty(), "first line should be empty");
            TEST_ASSERT(renderer_inst.lines().at(1) == "Middle", "second line content should match");
        });

        test_case("generate_lines, word wrapping", [this] {
            ks::globals::init_text_generators(LANG_RUSSIAN);
            text = "Лёгкий ветерок колышет голые ветви над головой, заставляя их шуметь, словно деревянные колокольчики.";
            renderer_inst.generate_lines(max_width);
            TEST_ASSERT(renderer_inst.lines().size() == 3, "long text should be broken into several lines");
            TEST_ASSERT(renderer_inst.lines().at(0) == "Лёгкий ветерок колышет голые ветви");
            TEST_ASSERT(renderer_inst.lines().at(1) == "над головой, заставляя их шуметь,");
            TEST_ASSERT(renderer_inst.lines().at(2) == "словно деревянные колокольчики.");
        });

        test_case("generate_lines, word chopping", [this] {
            ks::globals::init_text_generators(LANG_ENGLISH);
            text = "Aaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhhhhhggggggggggghhhhhhhh……";
            renderer_inst.generate_lines(max_width);
            TEST_ASSERT(renderer_inst.lines().size() == 2, "long unbroken text should be split");
            TEST_ASSERT(renderer_inst.lines().at(0) == "Aaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhh");
            TEST_ASSERT(renderer_inst.lines().at(1) == "hhhggggggggggghhhhhhhh……");
        });

        test_case("generate_lines, control characters", [this] {
            ks::globals::init_text_generators(LANG_ENGLISH);
            text = "Text with ""\x02""bold""\x03"".""\x06""\x05""Wait 0.5 sec";
            renderer_inst.generate_lines(max_width);
            TEST_ASSERT(renderer_inst.lines().size() == 1, "break_to_lines size");
            TEST_ASSERT(renderer_inst.lines().at(0) == "Text with ""\x02""bold""\x03"".""\x06""\x05""Wait 0.5 sec", "break_to_lines line 1");
        });

        // TODO: rewrite it. Bad test design.
        test_case("generate_commands", [this] {
            ks::globals::init_text_generators(LANG_ENGLISH);
            text = "Text with ""\x02""bold""\x03"".""\x06""\x05""Wait 0.5 sec";
            renderer_inst.generate_lines(max_width);
            renderer_inst.generate_commands();
            TEST_ASSERT(renderer_inst.commands().size() == 8, "parse_to_commands size");
            TEST_ASSERT(renderer_inst.commands().at(0).command == RC_START_LINE, "parse_to_commands cmd 0");
            TEST_ASSERT(renderer_inst.commands().at(1).command == RC_TEXT_OUT, "parse_to_commands cmd 1");
            TEST_ASSERT(renderer_inst.commands().at(1).view == "Text with ", "parse_to_commands cmd 1 view");
            TEST_ASSERT(renderer_inst.commands().at(2).command == RC_SET_FONT, "parse_to_commands cmd 2");
            TEST_ASSERT(renderer_inst.commands().at(2).param == 1, "parse_to_commands cmd 2 param");
            TEST_ASSERT(renderer_inst.commands().at(3).command == RC_TEXT_OUT, "parse_to_commands cmd 3");
            TEST_ASSERT(renderer_inst.commands().at(3).view == "bold", "parse_to_commands cmd 3 view");
            TEST_ASSERT(renderer_inst.commands().at(4).command == RC_SET_FONT, "parse_to_commands cmd 4");
            TEST_ASSERT(renderer_inst.commands().at(4).param == 0, "parse_to_commands cmd 4 param");
            TEST_ASSERT(renderer_inst.commands().at(5).command == RC_TEXT_OUT, "parse_to_commands cmd 5");
            TEST_ASSERT(renderer_inst.commands().at(5).view == ".", "parse_to_commands cmd 5 view");
            TEST_ASSERT(renderer_inst.commands().at(6).command == RC_WAIT, "parse_to_commands cmd 6");
            TEST_ASSERT(renderer_inst.commands().at(6).param == 5, "parse_to_commands cmd 6 param");
            TEST_ASSERT(renderer_inst.commands().at(7).command == RC_TEXT_OUT, "parse_to_commands cmd 7");
            TEST_ASSERT(renderer_inst.commands().at(7).view == "Wait 0.5 sec", "parse_to_commands cmd 7 view");

            text = "It's nice to meet you, too!""\x06""\x05"" But~!";
            renderer_inst.generate_lines(max_width);
            renderer_inst.generate_commands();
            TEST_ASSERT(renderer_inst.commands().size() == 4, "parse_to_commands size");
            TEST_ASSERT(renderer_inst.commands().at(0).command == RC_START_LINE, "parse_to_commands cmd 0");
            TEST_ASSERT(renderer_inst.commands().at(1).command == RC_TEXT_OUT, "parse_to_commands cmd 1");
            TEST_ASSERT(renderer_inst.commands().at(1).view == "It's nice to meet you, too!", "parse_to_commands cmd 1 view");
            TEST_ASSERT(renderer_inst.commands().at(2).command == RC_WAIT, "parse_to_commands cmd 2");
            TEST_ASSERT(renderer_inst.commands().at(2).param == 5, "parse_to_commands cmd 2 param");
            TEST_ASSERT(renderer_inst.commands().at(3).command == RC_TEXT_OUT, "parse_to_commands cmd 3");
            TEST_ASSERT(renderer_inst.commands().at(3).view == " But~!", "parse_to_commands cmd 3 view");

            text = "It's nice to meet you, too! But~!""\x01"", I'm not Hakamichi, I'm Misha! This is Hakamichi. Shicchan~!";
            renderer_inst.generate_lines(max_width);
            renderer_inst.generate_commands();
            TEST_ASSERT(renderer_inst.is_fast() == true, "fast flag set to true");
            TEST_ASSERT(renderer_inst.commands().size() == 8, "parse_to_commands size");
            TEST_ASSERT(renderer_inst.commands().at(0).command == RC_START_LINE, "parse_to_commands cmd 0");
            TEST_ASSERT(renderer_inst.commands().at(0).param == 0, "parse_to_commands cmd 0 param");
            TEST_ASSERT(renderer_inst.commands().at(1).command == RC_TEXT_OUT, "parse_to_commands cmd 1");
            TEST_ASSERT(renderer_inst.commands().at(1).view == "It's nice to meet you, too! But~!", "parse_to_commands cmd 1 view");
            TEST_ASSERT(renderer_inst.commands().at(2).command == RC_FAST, "parse_to_commands cmd 2");
            TEST_ASSERT(renderer_inst.commands().at(3).command == RC_TEXT_OUT, "parse_to_commands cmd 3");
            TEST_ASSERT(renderer_inst.commands().at(3).view == ", I'm not", "parse_to_commands cmd 3 view");
            TEST_ASSERT(renderer_inst.commands().at(4).command == RC_START_LINE, "parse_to_commands cmd 4");
            TEST_ASSERT(renderer_inst.commands().at(4).param == 1, "parse_to_commands cmd 4 param");
            TEST_ASSERT(renderer_inst.commands().at(5).command == RC_TEXT_OUT, "parse_to_commands cmd 5");
            TEST_ASSERT(renderer_inst.commands().at(5).view == "Hakamichi, I'm Misha! This is Hakamichi.", "parse_to_commands cmd 5 view");
            TEST_ASSERT(renderer_inst.commands().at(6).command == RC_START_LINE, "parse_to_commands cmd 6");
            TEST_ASSERT(renderer_inst.commands().at(6).param == 2, "parse_to_commands cmd 6 param");
            TEST_ASSERT(renderer_inst.commands().at(7).command == RC_TEXT_OUT, "parse_to_commands cmd 7");
            TEST_ASSERT(renderer_inst.commands().at(7).view == "Shicchan~!", "parse_to_commands cmd 7 view");

        });
    }

private:
    bn::istring& text = ks::message;
    ks::text::parser<32> renderer_inst{&text, ks::text_generator};
    const int max_width = ks::device::screen_width - 20;
};

#endif //TEXT_PARSER_TESTS_H
