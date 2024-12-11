#include "bn_core.h"
#include "bn_sram.h"
#include "bn_keypad.h"
#include "bn_bg_palettes.h"

#include "bn_string.h"
#include "bn_sprite_text_generator.h"
#include "variable_16x16_sprite_font.h"


#include "bn_bg_palettes.h"
#include "scenemanager.h"
#include "constants.h"
#include "globals.h"


#include "vidtest.cpp.h"


#include "scripts/script_a0_test_en.cpp"
#include "scripts/script_a1_monday_en.cpp"
#include "scripts/script_a1_monday_ru.cpp"
#include "scripts/script_a1_tuesday_en.cpp"
#include "scripts/script_a1_tuesday_ru.cpp"
#include "scripts/script_a1_wednesday_en.cpp"
#include "scripts/script_a1_wednesday_ru.cpp"
#include "gsmplayer/player.h"

#include "bn_sprite_items_hanako.h"
#include <BN_LOG.h>

#define SFX_TEST "vinyl.pcm"
using size_type = int;
namespace
{
    struct sram_data
    {
        bn::array<char, 32> format_tag;
        bool video_shown = false;
    };
}

// void sram_init() {
//     sram_data cart_sram_data;
//     bn::sram::read(cart_sram_data);
//     if (!cart_sram_data.initialized) {
//         cart_sram_data.initialized = true;
//         bn::sram::write(cart_sram_data);
//     }
//     bn::sram::read(cart_sram_data);
//     if (!cart_sram_data.initialized) {
//         BN_ERROR("SRAM is not working.\n\nCheck your emulator settings if you play\nKatawa Shoujo on emulator.");
//     }
// }

// bool sram_video_shown() {
//     sram_data cart_sram_data;
//     bn::sram::read(cart_sram_data);
//     return false;//cart_sram_data.video_shown;
// }

void BN_CODE_IWRAM show_video() {
    auto vid_test = new ks::VidTest(fs);

    // player_init();
    // player_playGSM("music_happiness.gsm");
    while (!vid_test->is_finished()) {
        // bn::core::update();
        // player_update(0, [](unsigned current) {});
        vid_test->update();
        // ks::globals::main_update();
        // player_onVBlank();
    }

}



int main()
{
    bn::core::init(ks::globals::ISR_VBlank);
    BN_ASSERT(fs != NULL,
              "GBFS file not found.\nUse the ROM that ends with .out.gba!");


    bn::array<char, 32> expected_format_tag;
    bn::istring_base expected_format_tag_istring(expected_format_tag._data);
    bn::ostringstream expected_format_tag_stream(expected_format_tag_istring);
    expected_format_tag_stream.append("KSGBA.SRAM");

    sram_data cart_sram_data;
    bn::sram::read(cart_sram_data);
    if (cart_sram_data.format_tag != expected_format_tag) {
        cart_sram_data.format_tag = expected_format_tag;
        cart_sram_data.video_shown = true;
        bn::sram::clear(bn::sram::size());
        bn::sram::write(cart_sram_data);
    }

    bn::sram::read(cart_sram_data);
    if (cart_sram_data.format_tag != expected_format_tag) {
        BN_ERROR("SRAM is not working.\n\nCheck your emulator settings if you play\nKatawa Shoujo on emulator.");
    }

    if (!cart_sram_data.video_shown) {
        show_video();
        bn::sram::read(cart_sram_data);
        cart_sram_data.video_shown = true;
        bn::sram::write(cart_sram_data);
        bn::core::reset();
    } else {
        // BN_ERROR("played");

    }
    // BN_BARRIER;

    // while (true) {
    //     ks::globals::main_update();
    //     if (bn::keypad::start_pressed()) {
    //         sram_data cart_sram_data;
    //         bn::sram::read(cart_sram_data);
    //         cart_sram_data.video_shown = false;
    //         cart_sram_data.num_plays = 0;
    //         bn::sram::write(cart_sram_data);
    //         bn::core::reset();
    //     }
    // }

    // bn::core::reset();
    // BN_ERROR("Finished");

    bn::core::init(ks::globals::ISR_VBlank);
    player_init();

    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));
    bn::sprite_text_generator* _text_generator = new bn::sprite_text_generator(variable_16x16_sprite_font);
    ks::dialog = new ks::DialogBox(_text_generator, variable_16x16_sprite_font);

    bn::vector<bn::sprite_ptr, 64> _text_sprites;
    bn::optional<bn::sprite_ptr> _bottom_icon;
    while(true)
    {
        int select = 1;
        bool alt_lang = ks::globals::use_alt_lang;
        bool scene_selected = false;
        bool need_update = true;

        player_playGSM("music_menus.gsm");
        player_setLoop(true);

        _bottom_icon.reset();
        _bottom_icon = bn::sprite_items::hanako.create_sprite(ks::device::screen_width_half - 32, ks::device::screen_height_half - 32);
        ks::globals::main_update();

        while (!scene_selected) {
            if (bn::keypad::up_pressed()) {
                need_update = true;
                select--;
                if (select < 0) {
                    select = 6;
                }
            }
            if (bn::keypad::down_pressed()) {
                need_update = true;
                select = ++select % 7;
            }
            if (bn::keypad::a_pressed()) {
                need_update = true;
                if (select == 5) {
                    alt_lang = !alt_lang;
                    ks::globals::use_alt_lang = alt_lang;
                } else if (select == 6) {
                    sram_data cart_sram_data;
                    bn::sram::read(cart_sram_data);
                    cart_sram_data.video_shown = false;
                    bn::sram::write(cart_sram_data);
                    bn::core::reset();
                } else {
                    scene_selected = true;
                }
            }

            if (need_update) {
                need_update = false;

                // Debug menu stuff
                bn::string<64> title("Katawa Shoujo v0.1.5+00972");
                bn::string<64> author(alt_lang ? "порт от NeParij" : "ported by: NeParij");
                bn::string<64> play_a0_test_scene(alt_lang ? "Тестовая сцена" : "Test Scene");
                bn::string<64> play_a1_monday(alt_lang ? "Акт 1. Понедельник" : "Act 1. Monday");
                bn::string<64> play_a1_tuesday(alt_lang ? "Акт 1. Вторник" : "Act 1. Tuesday");
                bn::string<64> play_a1_wednesday(alt_lang ? "Акт 1. Среда" : "Act 1. Wednesday");
                bn::string<64> play_all(alt_lang ? "Играть все доступные" : "Play all available");
                bn::string<64> language(alt_lang ? "Язык: " : "Language: ");
                bn::string<64> play_video(alt_lang ? "Воспроизвести видео" : "Play video");

                _text_sprites.clear();
                _text_generator->set_one_sprite_per_character(false);
                _text_generator->set_center_alignment();
                _text_generator->generate(0, -72, title, _text_sprites);
                _text_generator->generate(0, -72+12, author, _text_sprites);

                _text_generator->set_left_alignment();
                _text_generator->generate(-ks::device::screen_width_half + 4, -40 + (12 * 0), bn::string<64>(select == 0 ? "> " : "  ") + play_a0_test_scene, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, -40 + (12 * 1), bn::string<64>(select == 1 ? "> " : "  ") + play_a1_monday, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, -40 + (12 * 2), bn::string<64>(select == 2 ? "> " : "  ") + play_a1_tuesday, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, -40 + (12 * 3), bn::string<64>(select == 3 ? "> " : "  ") + play_a1_wednesday, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, -40 + (12 * 4), bn::string<64>(select == 4 ? "> " : "  ") + play_all, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, 44 + (12 * 0), bn::string<64>(select == 5 ? "> " : "  ") + language + (alt_lang ? "Русский" : "English"), _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, 44 + (12 * 1), bn::string<64>(select == 6 ? "> " : "  ") + play_video, _text_sprites);
            }
            ks::globals::main_update();
        }

        _text_sprites.clear();
        _bottom_icon.reset();
        player_stop();


        if (select == 0) {
            ks::ScriptA0TestEn::a0_actname();
            // ks::globals::main_update();
        } else if (select == 1) {
            !alt_lang ? ks::ScriptA1MondayEn::a1_monday() : ks::ScriptA1MondayRu::a1_monday();
            // ks::globals::main_update();
        } else if (select == 2) {
            !alt_lang ? ks::ScriptA1TuesdayEn::a1_tuesday() : ks::ScriptA1TuesdayRu::a1_tuesday();
            // ks::globals::main_update();
        }
        else if (select == 3) {
            !alt_lang ? ks::ScriptA1WednesdayEn::a1_wednesday() :ks::ScriptA1WednesdayRu::a1_wednesday();
            // ks::globals::main_update();
        } else if (select == 4) {
            // Play all scenes
            !alt_lang ? ks::ScriptA1MondayEn::a1_monday() : ks::ScriptA1MondayRu::a1_monday();
            // ks::globals::main_update();

            !alt_lang ? ks::ScriptA1TuesdayEn::a1_tuesday() : ks::ScriptA1TuesdayRu::a1_tuesday();
            // ks::globals::main_update();

            !alt_lang ? ks::ScriptA1WednesdayEn::a1_wednesday() :ks::ScriptA1WednesdayRu::a1_wednesday();
            // ks::globals::main_update();
        }

        ks::SceneManager::free_resources();
        ks::main_background.reset();
        ks::secondary_background.reset();
        ks::dialog->reset();
    }
}

