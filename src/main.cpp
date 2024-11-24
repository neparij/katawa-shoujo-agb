#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_bg_palettes.h"
#include "bn_music.h"

#include "bn_string.h"
#include "bn_sprite_text_generator.h"

#include "sequence/backgrounditem.h"
#include "sequence/menuitem.h"
#include "sequence/musicitem.h"
#include "sequence/runlabelitem.h"
// #include "sequence/runlabelfinishitem.h"
#include "variable_16x16_sprite_font.h"

#include "bn_bg_palettes.h"
#include "bn_regular_bg_builder.h"
#include "bn_music_items.h"
#include "scenemanager.h"
#include "constants.h"
#include "globals.h"

#include "scripts/script_a0_test.h"
#include "scripts/script_a1_monday.h"
#include "scripts/script_a1_tuesday.h"
#include "scripts/script_a1_wednesday.h"




#include "bn_regular_bg_items_school_dormhallway.h"
#include "bn_regular_bg_items_school_dormhisao_ss.h"



using size_type = int;
namespace
{

}

int main()
{
    // Core
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));


    // Debug menu stuff
    bn::string<32> title("Katawa Shouho v0.0.1+00098");
    bn::string<32> author("ported by: NeParij");
    bn::string<24> play_a0_test_scene("Test Scene");
    bn::string<24> play_a1_monday("Act 1. Monday");
    bn::string<24> play_a1_tuesday("Act 1. Tuesday");
    bn::string<24> play_a1_wednesday("Act 1. Wednesday");
    bn::string<24> play_all("Play all available");
    bn::string<24> debug_mem("Debug memory: ");
    bn::string<24> debug_dia("Debug dialogbox: ");
    bn::sprite_text_generator* _text_generator = new bn::sprite_text_generator(variable_16x16_sprite_font);
    bn::vector<bn::sprite_ptr, 64> _text_sprites;

    while(true)
    {
        int select = 0;
        bool selected = false;

        bn::music::play(bn::music_items::wiosna, 0.5);

        while (!selected) {
            while (!bn::keypad::a_pressed()) {
                if (bn::keypad::up_pressed()) {
                    select--;
                    if (select < 0) {
                        select = 6;
                    }
                } else if (bn::keypad::down_pressed()) {
                    select++;
                }
                select = select % 7;

                _text_sprites.clear();

                _text_generator->set_center_alignment();
                _text_generator->generate(0, -72, title, _text_sprites);
                _text_generator->generate(0, -72+12, author, _text_sprites);

                _text_generator->set_left_alignment();
                _text_generator->generate(-ks::device::screen_width_half + 4, -32 + (12 * 0), bn::string<24>(select == 0 ? "> " : "  ") + play_a0_test_scene, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, -32 + (12 * 1), bn::string<24>(select == 1 ? "> " : "  ") + play_a1_monday, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, -32 + (12 * 2), bn::string<24>(select == 2 ? "> " : "  ") + play_a1_tuesday, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, -32 + (12 * 3), bn::string<24>(select == 3 ? "> " : "  ") + play_a1_wednesday, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, 16 + 20, bn::string<24>(select == 4 ? "> " : "  ") + play_all, _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, 32 + 20, bn::string<24>(select == 5 ? "> " : "  ") + debug_mem + bn::to_string<8>(ks_globals::show_memory_debug), _text_sprites);
                _text_generator->generate(-ks::device::screen_width_half + 4, 48 + 20, bn::string<24>(select == 6 ? "> " : "  ") + debug_dia + bn::to_string<8>(ks_globals::show_dialog_debug), _text_sprites);

                bn::core::update();
            }

            if (select < 5) {
                selected = true;
            } else if (select == 5) {
                ks_globals::show_memory_debug = !ks_globals::show_memory_debug;
                bn::core::update();
            } else if (select == 6) {
                ks_globals::show_dialog_debug = !ks_globals::show_dialog_debug;
                bn::core::update();
            }
        }

        bn::music::stop();
        _text_sprites.clear();

        if (select == 0) {
            ks::scene__a0_actname();
            bn::core::update();
        } else if (select == 1) {
            ks::scene__a1_monday();
            bn::core::update();
        } else if (select == 2) {
            ks::scene__a1_tuesday();
            bn::core::update();
        } else if (select == 3) {
            ks::scene__a1_wednesday();
            bn::core::update();
        } else if (select == 4) {
            // Play all scenes
            ks::scene__a1_monday();
            bn::core::update();
            ks::scene__a1_tuesday();
            bn::core::update();
            ks::scene__a1_wednesday();
            bn::core::update();
        }
    }
}
