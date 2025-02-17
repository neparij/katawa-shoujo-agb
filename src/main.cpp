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


#include "videoplayer/video_player.h"
#include "video_4ls_agmv.h"
#include "video_op_1_agmv.h"
#include "video_tc_act2_emi_agmv.h"
#include <video_tc_act2_hanako_agmv.h>
#include <video_tc_act2_lilly_agmv.h>
#include <video_tc_act2_rin_agmv.h>
#include <video_tc_act2_shizune_agmv.h>



#include "scripts/script_a0_test_en.cpp"
#include "gsmplayer/player.h"
#include "gsmplayer/player_sfx.h"

#include "bn_regular_bg_items_video_end_4ls.h"
#include "bn_regular_bg_items_ui_bg_menu.h"
#include "bn_regular_bg_items_ui_bg_menu_main.h"
#include "bn_regular_bg_items_ui_bg_menu_extras.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_lilly.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_rin.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_shizu.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_emi.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_hanako.h"

#include "bn_regular_bg_items_ui_bg_menu_extras_cinema.h"
#include "bn_sprite_items_ui_tn_op_1_bw.h"
#include "bn_sprite_items_ui_tn_op_1.h"
#include "bn_sprite_items_ui_tn_tc_act2_emi_bw.h"
#include "bn_sprite_items_ui_tn_tc_act2_emi.h"
#include "bn_sprite_items_ui_tn_tc_act2_hanako_bw.h"
#include "bn_sprite_items_ui_tn_tc_act2_hanako.h"
#include "bn_sprite_items_ui_tn_tc_act2_lilly_bw.h"
#include "bn_sprite_items_ui_tn_tc_act2_lilly.h"
#include "bn_sprite_items_ui_tn_tc_act2_rin_bw.h"
#include "bn_sprite_items_ui_tn_tc_act2_rin.h"
#include "bn_sprite_items_ui_tn_tc_act2_shizu_bw.h"
#include "bn_sprite_items_ui_tn_tc_act2_shizu.h"


#include "translation_en.cpp"
#include "translation_ru.cpp"

#include "bn_sprite_items_ui_icon_00_tc1_hisao.h"
#include "bn_sprite_items_ui_icon_01_tc2_hanako.h"
#include "bn_sprite_items_ui_icon_02_tc3_hanako.h"
#include "bn_sprite_items_ui_icon_03_tc2_emi.h"
#include "bn_sprite_items_ui_icon_04_tc3_emi.h"
#include "bn_sprite_items_ui_icon_05_tc4_emi_1.h"
#include "bn_sprite_items_ui_icon_05_tc4_emi_2.h"
#include "bn_sprite_items_ui_icon_06_tc4_hanako.h"
#include "bn_sprite_items_ui_icon_07_tc2_lilly.h"
#include "bn_sprite_items_ui_icon_08_tc3_lilly.h"
#include "bn_sprite_items_ui_icon_09_tc4_lilly.h"
#include "bn_sprite_items_ui_icon_10_tc2_rin.h"
#include "bn_sprite_items_ui_icon_11_tc3_rin_hisao.h"
#include "bn_sprite_items_ui_icon_12_tc3_rin_rin.h"
#include "bn_sprite_items_ui_icon_13_tc4_rin.h"
#include "bn_sprite_items_ui_icon_14_tc2_shizune.h"
#include "bn_sprite_items_ui_icon_15_tc3_shizune.h"
#include "bn_sprite_items_ui_icon_16_tc4_shizune.h"



#include "bn_regular_bg_items_ui_test_paldraw.h"
#include "bn_regular_bg_items_ui_test_paldraw_b.h"
#include "bn_regular_bg_actions.h"
#include "bn_bg_palette_actions.h"
#include "bn_bg_palettes_actions.h"
#include "bn_bgs_mosaic_actions.h"
#include "bn_regular_bg_items_emi_bed_smile.h"
#include "bn_sprite_items_hanako.h"
#include <BN_LOG.h>

using size_type = int;
namespace
{
    struct sram_data
    {
        bn::array<char, 32> format_tag;
        bool video_shown = false;
    };
}

typedef enum menuEnum {
    MENU_MAIN    = 0,
    MENU_SAVES   = 1,
    MENU_EXTRAS  = 2,
    MENU_OPTIONS = 3,

    MENU_EXTRAS_CINEMA = 4,
} menuEnum;

void draw_progress_icons() {
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_16_tc4_shizune.create_sprite(111, 17));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_15_tc3_shizune.create_sprite(113, 42));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_14_tc2_shizune.create_sprite(93, 71));
    ks::globals::sound_update();

    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_13_tc4_rin.create_sprite(62, -22));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_12_tc3_rin_rin.create_sprite(67, -8));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_11_tc3_rin_hisao.create_sprite(82, 13));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_10_tc2_rin.create_sprite(96, 48));
    ks::globals::sound_update();

    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_09_tc4_lilly.create_sprite(29, -17));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_08_tc3_lilly.create_sprite(63,  8));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_07_tc2_lilly.create_sprite(65, 39));

    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_06_tc4_hanako.create_sprite(16, 8));
    ks::globals::sound_update();

    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_05_tc4_emi_1.create_sprite(14, 37));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_05_tc4_emi_2.create_sprite(50, 42));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_04_tc3_emi.create_sprite(32, 63));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_03_tc2_emi.create_sprite(37, 64));
    ks::globals::sound_update();

    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_02_tc3_hanako.create_sprite(29, 19));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_01_tc2_hanako.create_sprite(52, 41));

    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_icon_00_tc1_hisao.create_sprite(71, 71));
}

void open_main_menu(menuEnum &state, bn::vector<signed char, 64>* indexes) {
    state = MENU_MAIN;
    bn::string<64> version("v0.2.7+02769");
    ks::main_background = bn::regular_bg_items::ui_bg_menu_main.create_bg(0, 0);

    indexes->clear();
    ks::static_text_sprites->clear();
    ks::progress_icon_sprites->clear();
    draw_progress_icons();

    ks::globals::main_update();

    ks::text_generator->set_one_sprite_per_character(false);
    ks::text_generator->set_left_alignment();

    ks::text_generator->generate(-ks::device::screen_width_half + 4, ks::device::screen_height_half - 6, version, *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), -1);

    ks::text_generator->generate(-ks::device::screen_width_half + 22, ks::device::screen_height_half - 22 - (16 * 3), ks::globals::i18n->menu_start(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 0);
    ks::text_generator->generate(-ks::device::screen_width_half + 22, ks::device::screen_height_half - 22 - (16 * 2), ks::globals::i18n->menu_saves(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 1);
    ks::globals::sound_update();

    ks::text_generator->generate(-ks::device::screen_width_half + 22, ks::device::screen_height_half - 22 - (16 * 1), ks::globals::i18n->menu_extras(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 2);
    ks::text_generator->generate(-ks::device::screen_width_half + 22, ks::device::screen_height_half - 22 - (16 * 0), ks::globals::i18n->menu_options(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 3);
    ks::globals::sound_update();
}

void open_saves_menu(menuEnum &state, bn::vector<signed char, 64>* indexes) {
    state = MENU_SAVES;
    ks::main_background = bn::regular_bg_items::ui_bg_menu.create_bg(0, 0);

    indexes->clear();
    ks::static_text_sprites->clear();
    ks::progress_icon_sprites->clear();
    ks::globals::main_update();

    ks::text_generator->set_one_sprite_per_character(false);
    ks::text_generator->set_left_alignment();

    ks::text_generator->generate(-ks::device::screen_width_half + 22, -20 + (12 * 1), ks::globals::i18n->menu_play_a0_test_scene(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 0);
    ks::text_generator->generate(-ks::device::screen_width_half + 22, -20 + (12 * 2), ks::globals::i18n->menu_play_a1_monday(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 1);
    ks::globals::sound_update();

    ks::text_generator->generate(-ks::device::screen_width_half + 22, -20 + (12 * 3), ks::globals::i18n->menu_play_a1_tuesday(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 2);
    ks::text_generator->generate(-ks::device::screen_width_half + 22, -20 + (12 * 4), ks::globals::i18n->menu_play_a1_wednesday(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 3);
    ks::globals::sound_update();

    ks::text_generator->generate(-ks::device::screen_width_half + 22, -20 + (12 * 5), ks::globals::i18n->menu_play_a1_thursday(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 4);
    ks::globals::sound_update();

    ks::text_generator->generate(-ks::device::screen_width_half + 22, ks::device::screen_height_half - 22, ks::globals::i18n->menu_back(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 5);
    ks::globals::sound_update();
}

void open_extras_menu(menuEnum &state, bn::vector<signed char, 64>* indexes) {
    state = MENU_EXTRAS;
    ks::main_background = bn::regular_bg_items::ui_bg_menu_extras.create_bg(0, 0);

    indexes->clear();
    ks::static_text_sprites->clear();
    ks::progress_icon_sprites->clear();
    ks::globals::main_update();

    ks::text_generator->set_one_sprite_per_character(false);
    ks::text_generator->set_center_alignment();
    ks::text_generator->generate(ks::globals::i18n->menu_extras_jukebox_xoffset() - 90, 0, ks::globals::i18n->menu_extras_jukebox(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 0);
    ks::text_generator->generate(ks::globals::i18n->menu_extras_gallery_xoffset() - 30, 0, ks::globals::i18n->menu_extras_gallery(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 1);
    ks::text_generator->generate(ks::globals::i18n->menu_extras_library_xoffset() + 30, 0, ks::globals::i18n->menu_extras_library(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 2);
    ks::text_generator->generate(ks::globals::i18n->menu_extras_cinema_xoffset() + 90, 0, ks::globals::i18n->menu_extras_cinema(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 3);
    ks::text_generator->generate(ks::globals::i18n->menu_extras_return_xoffset() + 90, ks::device::screen_height_half - 14, ks::globals::i18n->menu_back(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 4);
}

void update_extras_menu(int select) {
    ks::secondary_background.reset();
    if (select == 0) {
        ks::secondary_background = bn::regular_bg_items::ui_bg_menu_extras_lilly.create_bg(0, 0);
    } else if (select == 1) {
        ks::secondary_background = bn::regular_bg_items::ui_bg_menu_extras_rin.create_bg(0, 0);
    } else if (select == 2) {
        ks::secondary_background = bn::regular_bg_items::ui_bg_menu_extras_shizu.create_bg(0, 0);
    } else if (select == 3) {
        ks::secondary_background = bn::regular_bg_items::ui_bg_menu_extras_emi.create_bg(0, 0);
    } else if (select == 4) {
        ks::secondary_background = bn::regular_bg_items::ui_bg_menu_extras_hanako.create_bg(0, 0);
    }
}

void open_extras_cinema_menu(menuEnum &state, bn::vector<signed char, 64>* indexes) {
    state = MENU_EXTRAS_CINEMA;
    ks::main_background = bn::regular_bg_items::ui_bg_menu_extras_cinema.create_bg(0, 0);

    indexes->clear();
    ks::static_text_sprites->clear();
    ks::progress_icon_sprites->clear();
    ks::globals::main_update();

    ks::text_generator->set_one_sprite_per_character(false);
    ks::text_generator->set_center_alignment();
    ks::text_generator->generate(ks::globals::i18n->menu_extras_return_xoffset() + 90, ks::device::screen_height_half - 14, ks::globals::i18n->menu_back(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 6);

    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_op_1_bw.create_sprite(-76 + (0 * 76), -35));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_emi_bw.create_sprite(-76 + (1 * 76), -35));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_hanako_bw.create_sprite(-76 + (2 * 76), -35));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_lilly_bw.create_sprite(-76 + (0 * 76), -35 + 64));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_rin_bw.create_sprite(-76 + (1 * 76), -35 + 64));
    ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_shizu_bw.create_sprite(-76 + (2 * 76), -35 + 64));
}

void update_extras_cinema_menu(int select) {
    if (ks::progress_icon_sprites->size() > 6) {
        ks::progress_icon_sprites->pop_back();
    }

    if (select < 6) {
        int x = -76 + (select % 3) * 76;
        int y = (select <3) ? -35 : -35 + 64;
        switch (select) {
        case 0:
            ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_op_1.create_sprite(x, y));
            break;
        case 1:
            ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_emi.create_sprite(x, y));
            break;
        case 2:
            ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_hanako.create_sprite(x, y));
            break;
        case 3:
            ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_lilly.create_sprite(x, y));
            break;
        case 4:
            ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_rin.create_sprite(x, y));
            break;
        case 5:
            ks::progress_icon_sprites->push_back(bn::sprite_items::ui_tn_tc_act2_shizu.create_sprite(x, y));
            break;
        default:
            break;
        }
    }
}

void open_options_menu(menuEnum &state, bn::vector<signed char, 64>* indexes) {
    state = MENU_OPTIONS;
    ks::main_background = bn::regular_bg_items::ui_bg_menu.create_bg(0, 0);

    indexes->clear();
    ks::static_text_sprites->clear();
    ks::progress_icon_sprites->clear();
    ks::globals::main_update();

    ks::text_generator->set_one_sprite_per_character(false);
    ks::text_generator->set_left_alignment();

    ks::text_generator->generate(-ks::device::screen_width_half + 22, -20 + (12 * 5), bn::format<64>("{}: {}", ks::globals::i18n->menu_language(), ks::globals::i18n->language()), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 0);
    ks::globals::sound_update();

    ks::text_generator->generate(-ks::device::screen_width_half + 22, ks::device::screen_height_half - 22, ks::globals::i18n->menu_back(), *ks::static_text_sprites);
    indexes->resize(ks::static_text_sprites->size(), 1);
    ks::globals::sound_update();
}

float bezier_f(float t)
{
    return t * t * (3.0f - 2.0f * t);
}


struct music_entry {
    const char* name;
    const char* gsm_file;
};

constexpr music_entry music_entries[] = {
    music_entry("Afternoon", "music_tranquil.gsm"),
    music_entry("Ah Eh I Oh You", "music_nurse.gsm"),
    music_entry("Air Guitar", "music_soothing.gsm"),
    music_entry("Aria de l'Etoile", "music_twinkle.gsm"),
    music_entry("Breathlessly", "music_moonlight.gsm"),
    music_entry("Caged Heart", "music_rain.gsm"),
    music_entry("Cold Iron", "music_tragic.gsm"),
    music_entry("Comfort", "music_comfort.gsm"),
    music_entry("Concord", "music_lilly.gsm"),
    music_entry("Daylight", "music_daily.gsm"),
    music_entry("Ease", "music_ease.gsm"),
    music_entry("Everyday Fantasy", "music_another.gsm"),
    music_entry("Friendship", "music_friendship.gsm") ,
    music_entry("Fripperies", "music_happiness.gsm"),
    music_entry("Generic Happy Music", "music_comedy.gsm"),
    music_entry("High Tension", "music_tension.gsm"),
    music_entry("Hokabi", "music_running.gsm"),
    music_entry("Innocence", "music_innocence.gsm"),
    music_entry("Letting my Heart Speak", "music_heart.gsm"),
    music_entry("Lullaby of Open Eyes", "music_serene.gsm"),
    music_entry("Moment of Decision", "music_drama.gsm"),
    music_entry("Nocturne", "music_night.gsm"),
    music_entry("Out of the Loop", "music_kenji.gsm"),
    music_entry("Painful History", "music_hanako.gsm"),
    music_entry("Parity", "music_rin.gsm"),
    music_entry("Passing of Time", "music_timeskip.gsm"),
    music_entry("Raindrops and Puddles", "music_dreamy.gsm"),
    music_entry("Red Velvet", "music_jazz.gsm"),
    music_entry("Romance in Andante II", "music_romance.gsm"),
    music_entry("Romance in Andante", "music_credits.gsm"),
    music_entry("Sarabande from BWV1010", "music_musicbox.gsm"),
    music_entry("School Days", "music_normal.gsm"),
    music_entry("Shadow of the Truth", "music_sadness.gsm"),
    music_entry("Standing Tall", "music_emi.gsm"),
    music_entry("Stride", "music_pearly.gsm"),
    music_entry("The Student Council", "music_shizune.gsm"),
    music_entry("To Become One", "music_one.gsm"),
    music_entry("Wiosna", "music_menus.gsm")
};

const constexpr bool SHOW_INTRO = true;
const constexpr bn::color COLOR_WHITE = bn::color(31,31,31);
const constexpr bn::color COLOR_BLACK = bn::color(0,0,0);
const constexpr bn::color COLOR_RED = bn::color(31,0,0);

int main()
{
    ks::globals::init_engine(COLOR_WHITE);
    BN_ASSERT(fs != NULL, "GBFS file not found.\nUse the ROM that ends with .out.gba!");

    ks::SceneManager::fade_in(COLOR_WHITE, 30);
    if (SHOW_INTRO) {
        // Show the 4LS intro video (p1 - video playback)
        ks::SceneManager::show_video(video_4ls_agmv, video_4ls_agmv_size, "video_4ls.gsm", COLOR_BLACK);

        // Show the 4LS intro video (p2 - native gfx playback)
        ks::main_background = bn::regular_bg_items::video_end_4ls.create_bg(0, 0);

        // TODO: Should be calculated in msecs for readability instead of ticks
        bn::bg_palettes::set_fade_color(COLOR_WHITE);
        for (int i = 0; i < 120; i++) {
            if (i < 30) {
                bn::bg_palettes::set_fade_intensity(bn::fixed(30 - i) / 30);
            }
            if (i == 90) {
                bn::bg_palettes::set_fade_color(COLOR_BLACK);
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
    }
    ks::globals::sound_update();

    menuEnum state;
    bn::vector<signed char, 64> selection_index;

    while(true)
    {
        int select = 0;
        bool scene_selected = false;
        bool need_fade_in = true;
        bool need_repalette = true;

        bn::bg_palettes::set_fade(COLOR_BLACK, bn::fixed(1));
        bn::sprite_palettes::set_fade(COLOR_BLACK, bn::fixed(1));

        open_main_menu(state, &selection_index);

        int temp_music_index = 37;
        BN_LOG("Music entries size: ", temp_music_index);
        player_playGSM("music_menus.gsm");
        player_setLoop(true);

        bn::sprite_palette_item original_palette_item = ks::text_generator->palette_item();
        bn::sprite_palette_item beige_palette_item = bn::sprite_items::variable_16x16_font_beige.palette_item();
        bn::sprite_palette_item beige_selected_palette_item = bn::sprite_items::variable_16x16_font_beige_selected.palette_item();

        // ks::globals::main_update();

        while (!scene_selected) {


            if (bn::keypad::r_pressed() || bn::keypad::l_pressed()) {
                if (bn::keypad::r_pressed()) {
                    temp_music_index++;
                }
                if (bn::keypad::l_pressed()) {
                    temp_music_index--;
                }
                temp_music_index = (temp_music_index + 38) % 38;
                BN_LOG("MUSIC.ID=", temp_music_index);
                BN_LOG("MUSIC.NAME=", music_entries[temp_music_index].name);
                player_playGSM(music_entries[temp_music_index].gsm_file);
                player_setLoop(true);
            }

            if (bn::keypad::up_pressed() || bn::keypad::down_pressed()) {
                need_repalette = true;
                if (state == MENU_EXTRAS) {
                    if (select != 4 && bn::keypad::down_pressed()) {
                        select = 4;
                        update_extras_menu(select);
                    } else if (select == 4 && bn::keypad::up_pressed()) {
                        select = 3;
                        update_extras_menu(select);
                    }
                } else if (state == MENU_EXTRAS_CINEMA) {
                    if (bn::keypad::down_pressed()) {
                        select += 3;
                        select = bn::min(select, 6);
                    }
                    if (bn::keypad::up_pressed()) {
                        if (select == 6) {
                            select = 5;
                        } else if (select >= 3) {
                            select -= 3;
                        }
                    }
                    update_extras_cinema_menu(select);
                } else {
                    char menuItemsCount = 0;
                    if (state == MENU_MAIN) {
                        menuItemsCount = 4;
                    } else if (state == MENU_SAVES) {
                        menuItemsCount = 6;
                    } else if (state == MENU_EXTRAS) {
                        menuItemsCount = 7;
                    } else if (state == MENU_OPTIONS) {
                        menuItemsCount = 2;
                    }

                    select += bn::keypad::down_pressed() ? 1 : -1;
                    select += menuItemsCount;
                    select = select % menuItemsCount;
                }
            }

            if (bn::keypad::left_pressed() || bn::keypad::right_pressed()) {
                need_repalette = true;
                if (state == MENU_EXTRAS) {
                    if (select != 4) {
                        select += bn::keypad::right_pressed() ? 1 : -1;
                        select = bn::min(3, select);
                        select = bn::max(0, select);
                        update_extras_menu(select);
                    }
                } else if (state == MENU_EXTRAS_CINEMA) {
                    if (select != 6) {
                        select += bn::keypad::right_pressed()
                                    ? (select % 3 != 2) ? 1 : 0
                                    : (select % 3 != 0) ? -1 : 0;
                        select = bn::min(5, select);
                        select = bn::max(0, select);
                        update_extras_cinema_menu(select);
                    }
                }
            }

            if (bn::keypad::b_pressed() && state != MENU_MAIN) {
                need_repalette = true;
                select = 0;
                if (state == MENU_SAVES) {
                    select = 1;
                    open_main_menu(state, &selection_index);
                } else if (state == MENU_EXTRAS) {
                    select = 2;
                    open_main_menu(state, &selection_index);
                } else if (state == MENU_EXTRAS_CINEMA) {
                    select = 3;
                    open_extras_menu(state, &selection_index);
                    update_extras_menu(select);
                } else if (state == MENU_OPTIONS) {
                    select = 3;
                    open_main_menu(state, &selection_index);
                } else {
                    select = 0;
                    open_main_menu(state, &selection_index);
                }
            }
            if (bn::keypad::a_pressed()) {
                need_repalette = true;
                if (state == MENU_MAIN) {
                    if (select == 0) {
                        scene_selected = true;
                    }
                    if (select == 1) {
                        select = 0;
                        open_saves_menu(state, &selection_index);
                    }
                    if (select == 2) {
                        select = 0;
                        open_extras_menu(state, &selection_index);
                        update_extras_menu(select);
                    }
                    if (select == 3) {
                        select = 0;
                        open_options_menu(state, &selection_index);
                    }
                } else if (state == MENU_SAVES) {
                    if (select == 5) {
                        select = 1;
                        open_main_menu(state, &selection_index);
                    } else {
                        scene_selected = true;
                    }
                } else if (state == MENU_EXTRAS) {
                    if (select == 4) {
                        select = 2;
                        open_main_menu(state, &selection_index);
                    } else {
                        if (select == 3) {
                            select = 0;
                            open_extras_cinema_menu(state, &selection_index);
                            update_extras_cinema_menu(select);
                        }
                    }
                } else if (state == MENU_EXTRAS_CINEMA) {
                    if (select == 6) {
                        select = 3;
                        open_extras_menu(state, &selection_index);
                        update_extras_menu(select);
                    } else {
                        player_stop();
                        player_sfx_stop();

                        if (select == 0) {
                            ks::SceneManager::show_video(video_op_1_agmv, video_op_1_agmv_size, "video_op_1.gsm", COLOR_BLACK);
                        } else if (select == 1) {
                            ks::SceneManager::show_video(video_tc_act2_emi_agmv, video_tc_act2_emi_agmv_size, "video_tc_act2_emi.gsm", COLOR_WHITE);
                        } else if (select == 2) {
                            ks::SceneManager::show_video(video_tc_act2_hanako_agmv, video_tc_act2_hanako_agmv_size, "video_tc_act2_hanako.gsm", COLOR_WHITE);
                        } else if (select == 3) {
                            ks::SceneManager::show_video(video_tc_act2_lilly_agmv, video_tc_act2_lilly_agmv_size, "video_tc_act2_lilly.gsm", COLOR_WHITE);
                        } else if (select == 4) {
                            ks::SceneManager::show_video(video_tc_act2_rin_agmv, video_tc_act2_rin_agmv_size, "video_tc_act2_rin.gsm", COLOR_WHITE);
                        } else if (select == 5) {
                            ks::SceneManager::show_video(video_tc_act2_shizune_agmv, video_tc_act2_shizune_agmv_size, "video_tc_act2_shizune.gsm", COLOR_WHITE);
                        }

                        ks::main_background = bn::regular_bg_items::ui_bg_menu.create_bg(0, 0);
                        ks::secondary_background = bn::regular_bg_items::ui_test_paldraw_b.create_bg_optional(0, 0);
                        bn::bg_palette_ptr minbg_palette = ks::main_background->palette();
                        bn::bg_palette_ptr secbg_palette = ks::secondary_background->palette();
                        minbg_palette.set_fade(COLOR_WHITE, bn::fixed(1));
                        secbg_palette.set_grayscale_intensity(bn::fixed(1));
                        secbg_palette.set_fade(COLOR_WHITE, bn::fixed(1));
                        bn::bg_palette_fade_to_action main_fade_action(minbg_palette, 128, bn::fixed(0));
                        bn::bg_palette_fade_to_action fade_action(secbg_palette, 96, bn::fixed(0));
                        bn::bg_palette_grayscale_to_action grayscale_action(secbg_palette, 64, bn::fixed(0));

                        ks::main_background->set_mosaic_enabled(true);
                        ks::secondary_background->set_mosaic_enabled(true);
                        bn::bgs_mosaic::set_stretch(0.5);
                        bn::bgs_mosaic_stretch_to_action main_mosaic_action(48, bn::fixed(0));

                        float move_f = 0.0f;
                        while (!fade_action.done() || !grayscale_action.done() || move_f < 1) {
                            if (!main_mosaic_action.done()) {
                                main_mosaic_action.update();
                            }

                            if (!main_fade_action.done()) {
                                main_fade_action.update();
                            }

                            if (!fade_action.done() && move_f > 0.6f) {
                                fade_action.update();
                            }

                            if (!grayscale_action.done() && fade_action.done()) {
                                grayscale_action.update();
                            }

                            ks::secondary_background->set_position(-72 * bezier_f(move_f), 0);
                            if (move_f < 1) {
                                move_f += 0.003f;
                            }
                            bn::core::update();
                        }

                        ks::SceneManager::fade_out(COLOR_BLACK);
                        need_fade_in = true;


                        player_playGSM("music_menus.gsm");
                        player_setLoop(true);
                        open_extras_cinema_menu(state, &selection_index);
                        update_extras_cinema_menu(select);

                        // bn::core::reset();
                    }
                } else if (state == MENU_OPTIONS) {
                    if (select == 1) {
                        select = 3;
                        open_main_menu(state, &selection_index);
                    } else {
                        if (select == 0) {
                            if (ks::globals::i18n->type() == ks::TranslationType::EN) {
                                ks::globals::set_language(ks::TranslationType::RU);
                            } else if (ks::globals::i18n->type() == ks::TranslationType::RU) {
                                ks::globals::set_language(ks::TranslationType::EN);
                            } else {
                                BN_ERROR("Unkown language was selected");
                            }
                            open_options_menu(state, &selection_index);
                        }
                    }
                }
            }


            if (need_repalette) {
                need_repalette = false;
                BN_LOG("Repalette menu");

                for (int i = 0; i < ks::static_text_sprites->size(); i++) {
                    bool is_selected = selection_index.at(i) == select;
                    bool is_action = selection_index.at(i) != -1;
                    if (!is_action) {
                        ks::static_text_sprites->at(i).set_palette(original_palette_item);
                    } else {
                        ks::static_text_sprites->at(i).set_palette(is_selected ? beige_selected_palette_item : beige_palette_item);
                    }
                }
            }

            if (need_fade_in) {
                need_fade_in = false;
                ks::SceneManager::fade_in(COLOR_BLACK);
            }

            ks::globals::main_update();
        }

        ks::SceneManager::fade_out(COLOR_BLACK);
        // _text_sprites.clear();
        ks::static_text_sprites->clear();
        ks::progress_icon_sprites->clear();
        ks::main_background.reset();
        ks::secondary_background.reset();
        ks::globals::main_update();
        // _bottom_icon.reset();
        player_stop();

        ks::SceneManager::fade_reset();
        if (state == MENU_MAIN) {
            // Play all scenes
            ks::globals::i18n->script_a1_monday()();
            ks::globals::i18n->script_a1_tuesday()();
            ks::globals::i18n->script_a1_wednesday()();
            ks::globals::i18n->script_a1_thursday()();
        } else if (state == MENU_SAVES) {
            if (select == 0) {
                ks::ScriptA0TestEn().a0_actname();
            } else if (select == 1) {
                ks::globals::i18n->script_a1_monday()();
            } else if (select == 2) {
                ks::globals::i18n->script_a1_tuesday()();
            } else if (select == 3) {
                ks::globals::i18n->script_a1_wednesday()();
            } else if (select == 4) {
                ks::globals::i18n->script_a1_thursday()();
            }
        }

        ks::SceneManager::free_resources();
        ks::globals::exit_scenario = false;
        ks::main_background.reset();
        ks::secondary_background.reset();
        ks::progress_icon_sprites->clear();
        ks::dialog->reset();
        ks::globals::main_update();
        bn::bg_palettes::set_fade_intensity(0);
        bn::sprite_palettes::set_fade_intensity(0);
    }
}

