#ifndef TEXT_RENDER_TESTS_H
#define TEXT_RENDER_TESTS_H


#include "asserts.h"
#include "tests.h"

#include "../src/text_render.h"
#include "fonts_info.h"

class text_render_tests : public tests {
public:
    text_render_tests() : tests("text_render"),
                          renderer_inst(ks::text::renderer<512, 32>(font_playtime_sprite_font)) {
        // Check UTF-8 character size detection
        const auto s1 = reinterpret_cast<const unsigned char *>("A");
        KS_ASSERT(renderer_inst.get_char_size(s1[0]) == 1, "get_char_size: 1 byte character 'A'");

        const auto s2 = reinterpret_cast<const unsigned char *>("ñ"); // UTF-8: 0xC3 0xB1
        KS_ASSERT(renderer_inst.get_char_size(s2[0]) == 2, "get_char_size: 2 bytes character 'ñ'");

        const auto s3 = reinterpret_cast<const unsigned char *>("あ"); // UTF-8: 0xE3 0x81 0x82
        KS_ASSERT(renderer_inst.get_char_size(s3[0]) == 3, "get_char_size: 3 bytes character 'あ'");

        const auto s4 = reinterpret_cast<const unsigned char *>("𐍈"); // UTF-8: 0xF0 0x90 0x8D 0x88
        KS_ASSERT(renderer_inst.get_char_size(s4[0]) == 4, "get_char_size: 4 bytes character '𐍈'");

        renderer_inst.set_text("Single line");
        renderer_inst.generate_lines();
        KS_ASSERT(renderer_inst.lines().size() == 1, "break_to_lines size");
        KS_ASSERT(renderer_inst.lines().at(0) == "Single line", "break_to_lines line 1");
        renderer_inst.generate_commands();

        renderer_inst.set_text("Multiple\nbeautiful lines");
        renderer_inst.generate_lines();
        KS_ASSERT(renderer_inst.lines().size() == 2, "break_to_lines size");
        KS_ASSERT(renderer_inst.lines().at(0) == "Multiple", "break_to_lines line 1");
        KS_ASSERT(renderer_inst.lines().at(1) == "beautiful lines", "break_to_lines line 2");

        renderer_inst.set_text("\nMiddle");
        renderer_inst.generate_lines();
        KS_ASSERT(renderer_inst.lines().size() == 2, "break_to_lines size");
        KS_ASSERT(renderer_inst.lines().at(0).empty(), "break_to_lines line 1");
        KS_ASSERT(renderer_inst.lines().at(1) == "Middle", "break_to_lines line 2");

        renderer_inst.set_text("Лёгкий ветерок колышет голые ветви над головой, заставляя их шуметь, словно деревянные колокольчики.");
        renderer_inst.generate_lines();
        KS_ASSERT(renderer_inst.lines().size() == 3, "break_to_lines size");
        KS_ASSERT(renderer_inst.lines().at(0) == "Лёгкий ветерок колышет голые ветви", "break_to_lines line 1");
        KS_ASSERT(renderer_inst.lines().at(1) == "над головой, заставляя их шуметь,", "break_to_lines line 2");
        KS_ASSERT(renderer_inst.lines().at(2) == "словно деревянные колокольчики.", "break_to_lines line 3");

        renderer_inst.set_text("Aaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhhhhhggggggggggghhhhhhhh……");
        renderer_inst.generate_lines();
        KS_ASSERT(renderer_inst.lines().size() == 2, "break_to_lines size");
        KS_ASSERT(renderer_inst.lines().at(0) == "Aaaaaaaaaaaaaaahhhhhhhhhhhhhhhhhhhhh", "break_to_lines line 1");
        KS_ASSERT(renderer_inst.lines().at(1) == "hhhggggggggggghhhhhhhh……", "break_to_lines line 2");


        renderer_inst.set_text("Text with ""\x02""bold""\x03"".""\x06""\x05""Wait 0.5 sec");
        renderer_inst.generate_lines();
        KS_ASSERT(renderer_inst.lines().size() == 1, "break_to_lines size");
        KS_ASSERT(renderer_inst.lines().at(0) == "Text with ""\x02""bold""\x03"".""\x06""\x05""Wait 0.5 sec", "break_to_lines line 1");
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

        renderer_inst.set_text("It's nice to meet you, too!""\x06""\x05"" But~!");
        renderer_inst.generate_lines();
        renderer_inst.generate_commands();
        KS_ASSERT(renderer_inst.commands().size() == 4, "parse_to_commands size");
        KS_ASSERT(renderer_inst.commands().at(0).command == RC_START_LINE, "parse_to_commands cmd 0");
        KS_ASSERT(renderer_inst.commands().at(1).command == RC_TEXT_OUT, "parse_to_commands cmd 1");
        KS_ASSERT(renderer_inst.commands().at(1).view == "It's nice to meet you, too!", "parse_to_commands cmd 1 view");
        KS_ASSERT(renderer_inst.commands().at(2).command == RC_WAIT, "parse_to_commands cmd 2");
        KS_ASSERT(renderer_inst.commands().at(2).param == 5, "parse_to_commands cmd 2 param");
        KS_ASSERT(renderer_inst.commands().at(3).command == RC_TEXT_OUT, "parse_to_commands cmd 3");
        KS_ASSERT(renderer_inst.commands().at(3).view == " But~!", "parse_to_commands cmd 3 view");

        renderer_inst.set_text("It's nice to meet you, too! But~!""\x01"", I'm not Hakamichi, I'm Misha! This is Hakamichi. Shicchan~!");
        renderer_inst.generate_lines();
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

    }

private:
    ks::text::renderer<512, 32> renderer_inst;
};

#endif //TEXT_RENDER_TESTS_H
