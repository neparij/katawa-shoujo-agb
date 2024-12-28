#include "bn_core.h"
#include "bn_sprite_palettes.h"
#include "bn_sram.h"
#include "bn_keypad.h"
#include "bn_bg_palettes.h"


#include "bn_string.h"
#include "bn_format.h"
#include "bn_sprite_text_generator.h"
#include "variable_16x16_sprite_font.h"


#include "bn_bg_palettes.h"
#include "scenemanager.h"
#include "constants.h"
#include "globals.h"


#include "vidtest.cpp.h"


#include "scripts/script_a0_test_en.cpp"
#include "gsmplayer/player.h"
#include "gsmplayer/player_sfx.h"

#include "bn_regular_bg_items_video_end_4ls.h"
#include "bn_regular_bg_items_ui_bg_main.h"
#include "translation_en.cpp"
#include "translation_ru.cpp"

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

void BN_CODE_IWRAM show_video() {
    auto vid_test = new ks::VidTest(fs);
    while (!vid_test->is_finished()) {
        vid_test->update();
    }
}



int main()
{
    const constexpr bool SHOW_INTRO = true;

    // Init Butano Core.
    bn::core::init();
    // Check that ROM with GBFS is running.
    BN_ASSERT(fs != NULL, "GBFS file not found.\nUse the ROM that ends with .out.gba!");

    if (SHOW_INTRO) {
        // Show the 4LS intro video (p1 - video playback)
        show_video();
    }

    // Re-init Butano Core and GSM Audio Engine
    bn::core::init(ks::globals::ISR_VBlank);
    player_init();
    player_sfx_init();

    if (SHOW_INTRO) {
        // Show the 4LS intro video (p2 - native gfx playback)
        ks::main_background = bn::regular_bg_items::video_end_4ls.create_bg(0, 0);
        player_playGSM("video_a_4ls_end.gsm");
        constexpr bn::color WHITE = bn::color(31, 31, 31);
        constexpr bn::color BLACK = bn::color(0, 0, 0);

        // TODO: Should be calculated in msecs for readability instead of ticks
        bn::bg_palettes::set_fade_color(WHITE);
        for (int i = 0; i < 120; i++) {
            if (i < 30) {
                bn::bg_palettes::set_fade_intensity(bn::fixed(30 - i) / 30);
            }
            if (i == 90) {
                bn::bg_palettes::set_fade_color(BLACK);
            }
            if (i > 90) {
                bn::bg_palettes::set_fade_intensity(bn::fixed(i - 90) / 30);
            }
            ks::globals::main_update();
        }

        ks::main_background.reset();
        bn::bg_palettes::set_fade_intensity(0);

        // Wait 1 second
        for (int i = 0; i < 60 * 1; i++) {
            ks::globals::main_update();
        }
        // END OF INTRO
    }


    // Initialiaze common data and classes.
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));
    ks::static_text_sprites = new bn::vector<bn::sprite_ptr, 64>();
    ks::animated_text_sprites = new bn::vector<bn::sprite_ptr, 128>();
    ks::static_text_sprites->clear();
    ks::animated_text_sprites->clear();
    ks::text_generator = new bn::sprite_text_generator(variable_16x16_sprite_font);
    ks::dialog = new ks::DialogBox(ks::text_generator, ks::static_text_sprites, ks::animated_text_sprites);
    ks::globals::i18n = new ks::TranslationEn();

    // Main loop starts.
    bn::optional<bn::sprite_ptr> _bottom_icon;
    while(true)
    {
        int select = 1;
        bool scene_selected = false;
        bool need_update = true;


        ks::main_background = bn::regular_bg_items::ui_bg_main.create_bg(0, 0);
        player_playGSM("music_menus.gsm");
        player_setLoop(true);

        _bottom_icon.reset();
        _bottom_icon = bn::sprite_items::hanako.create_sprite(ks::device::screen_width_half - 32, ks::device::screen_height_half - 32);

        bn::sprite_palette_item original_palette_item = ks::text_generator->palette_item();
        bn::sprite_palette_item beige_palette_item = bn::sprite_items::variable_16x16_font_beige.palette_item();
        bn::sprite_palette_item beige_selected_palette_item = bn::sprite_items::variable_16x16_font_beige_selected.palette_item();

        ks::globals::main_update();

        while (!scene_selected) {
            if (bn::keypad::select_pressed()) {
                // TODO: Remove, test only
                player_sfx_play("sfx_alarmclock.pcm");
                player_sfx_setLoop(false);
            }
            if (bn::keypad::up_pressed()) {
                need_update = true;
                select--;
                if (select < 0) {
                    select = 5;
                }
            }
            if (bn::keypad::down_pressed()) {
                need_update = true;
                select = ++select % 6;
            }
            if (bn::keypad::a_pressed()) {
                need_update = true;
                if (select == 5) {
                    if (ks::globals::i18n->type() == ks::Translation::Type::EN) {
                        delete ks::globals::i18n;
                        ks::globals::i18n = new ks::TranslationRu();
                    } else if (ks::globals::i18n->type() == ks::Translation::Type::RU) {
                        delete ks::globals::i18n;
                        ks::globals::i18n = new ks::TranslationEn();
                    } else {
                        BN_ERROR("Unkown language was selected");
                    }
                } else {
                    scene_selected = true;
                }
            }

            if (need_update) {
                need_update = false;

                // Debug menu stuff
                bn::string<64> title("Katawa Shoujo v0.2.0+01339");

                // _text_sprites.clear();
                ks::static_text_sprites->clear();
                ks::text_generator->set_one_sprite_per_character(false);
                ks::text_generator->set_center_alignment();
                ks::text_generator->set_palette_item(beige_palette_item);
                ks::text_generator->generate(0, -60, title, *ks::static_text_sprites);
                ks::text_generator->generate(0, -60+12, ks::globals::i18n->menu_author(), *ks::static_text_sprites);

                ks::text_generator->set_left_alignment();

                ks::text_generator->set_palette_item(select == 0 ? beige_selected_palette_item : beige_palette_item);
                ks::text_generator->generate(-ks::device::screen_width_half + 24, -20 + (12 * 0), ks::globals::i18n->menu_play_a0_test_scene(), *ks::static_text_sprites);

                ks::text_generator->set_palette_item(select == 1 ? beige_selected_palette_item : beige_palette_item);
                ks::text_generator->generate(-ks::device::screen_width_half + 24, -20 + (12 * 1), ks::globals::i18n->menu_play_a1_monday(), *ks::static_text_sprites);

                ks::text_generator->set_palette_item(select == 2 ? beige_selected_palette_item : beige_palette_item);
                ks::text_generator->generate(-ks::device::screen_width_half + 24, -20 + (12 * 2), ks::globals::i18n->menu_play_a1_tuesday(), *ks::static_text_sprites);

                ks::text_generator->set_palette_item(select == 3 ? beige_selected_palette_item : beige_palette_item);
                ks::text_generator->generate(-ks::device::screen_width_half + 24, -20 + (12 * 3), ks::globals::i18n->menu_play_a1_wednesday(), *ks::static_text_sprites);

                ks::text_generator->set_palette_item(select == 4 ? beige_selected_palette_item : beige_palette_item);
                ks::text_generator->generate(-ks::device::screen_width_half + 24, -20 + (12 * 4), ks::globals::i18n->menu_play_all(), *ks::static_text_sprites);

                ks::text_generator->set_palette_item(select == 5 ? beige_selected_palette_item : beige_palette_item);
                ks::text_generator->generate(-ks::device::screen_width_half + 24, 56 + (12 * 0), bn::format<64>("{}: {}", ks::globals::i18n->menu_language(), ks::globals::i18n->language()), *ks::static_text_sprites);
            }
            ks::globals::main_update();
        }

        // _text_sprites.clear();
        ks::static_text_sprites->clear();
        _bottom_icon.reset();
        player_stop();

        if (select == 0) {
            ks::ScriptA0TestEn::a0_actname();
        } else if (select == 1) {
            ks::globals::i18n->script_a1_monday()();
        } else if (select == 2) {
            ks::globals::i18n->script_a1_tuesday()();
        } else if (select == 3) {
            ks::globals::i18n->script_a1_wednesday()();
        } else if (select == 4) {
            // Play all scenes
            ks::globals::i18n->script_a1_monday()();
            ks::globals::i18n->script_a1_tuesday()();
            ks::globals::i18n->script_a1_wednesday()();
        }

        ks::SceneManager::free_resources();
        ks::globals::exit_scenario = false;
        ks::main_background.reset();
        ks::dialog->reset();
        bn::bg_palettes::set_fade_intensity(0);
        bn::sprite_palettes::set_fade_intensity(0);
    }
}

