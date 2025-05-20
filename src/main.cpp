#include "bn_bg_palettes.h"
#include "bn_core.h"
#include "bn_memory.h"
#include "bn_regular_bg_items_video_end_4ls.h"
#include "bn_sprite_palettes.h"
#include "bn_sram.h"
#include "globals.h"
#include "ingametimer.h"
#include "scenemanager.h"
#include "sound_manager.h"
#include "translations/en.cpp"
#include "video_4ls_dxtv.h"
#include "menu/menu_extras.cpp.h"
#include "menu/menu_extras_cinema.cpp.h"
#include "menu/menu_main.cpp.h"
#include "menu/menu_options.cpp.h"
#include "menu/menu_saves.cpp.h"

#include "background_metas.h"

using size_type = int;

inline void game(const bool is_new_game) {
    ks::globals::state = GS_GAME;
    ks::in_game = true;
    ks::is_paused = false;
    ks::SceneManager::fade_reset();

    if (is_new_game) {
        ks::timer::start_ingame_timer();
    } else {
        ks::timer::start_ingame_timer(false);
    }

    ks::globals::i18n->script_a1_monday()();
    ks::globals::i18n->script_a1_tuesday()();
    ks::globals::i18n->script_a1_wednesday()();
    ks::globals::i18n->script_a1_thursday()();
    // ks::globals::i18n->script_a1_friday()();
    // ks::globals::i18n->script_a1_saturday()();
    // ks::globals::i18n->script_a1_sunday()();

    if (ks::progress.force_route == FR_EMI) {
        // video: tc_act2_emi
        // ks::globals::i18n->script_a2_emi()();
        // video: tc_act3_emi
        // ks::globals::i18n->script_a3_emi()();
        if (ks::progress.have_a_minute && ks::progress.talk_to_her_mom || ks::progress.let_misha_know) {
            // GOOD ENDING
            // video: tc_act4_emi
            // ks::globals::i18n->script_a4_emi()();
            // credits: credits_emi
        } else {
            // BAD ENDING
        }
    } else if (ks::progress.force_route == FR_HANAKO) {
        // video: tc_act2_hanako
        // ks::globals::i18n->script_a2_hanako()();
        // video: tc_act3_hanako
        // ks::globals::i18n->script_a3_hanako()();
        // video: tc_act4_hanako
        // ks::globals::i18n->script_a4_hanako()();
        if (ks::progress.go_to_the_city && ks::progress.agree_with_lilly) {
            // GOOD ENDING
            // credits: credits_hanako
        } else if (ks::progress.go_to_the_city) {
            // SAD ENDING
        } else {
            // RAGE ENDING
        }
    } else if (ks::progress.force_route == FR_LILLY) {
        // video: tc_act2_lilly
        // ks::globals::i18n->script_a2_lilly()();
        // video: tc_act3_lilly
        // ks::globals::i18n->script_a3_lilly()();
        // video: tc_act4_lilly
        // ks::globals::i18n->script_a4_lilly()();
        if (ks::progress.want_true && ks::progress.address_it && ks::progress.mention_the_letter) {
            // GOOD ENDING
            // credits: credits_lilly
        } else {
            // BAD ENDING
        }
    } else if (ks::progress.force_route == FR_RIN) {
        // video: tc_act2_rin
        // ks::globals::i18n->script_a2_rin()();
        // video: tc_act3_rin
        // ks::globals::i18n->script_a3_rin()();
        // video: tc_act4_rin
        if (!ks::progress.explain) {
            // video: tc_act4_rin
            // ks::globals::i18n->script_a4_rin()();
            if (ks::progress.is_true) {
                // TRUE ENDING
            } else {
                // GOOD ENDING
                // credits: credits_rin
            }
        } else {
            // BAD ENDING
        }
    } else if (ks::progress.force_route == FR_SHIZU) {
        // video: tc_act2_shizune
        // ks::globals::i18n->script_a2_shizune()();
        // video: tc_act3_shizune
        // ks::globals::i18n->script_a3_shizune()();
        // video: tc_act4_shizune
        // ks::globals::i18n->script_a4_shizune()();
        if (ks::progress.refuse_misha) {
            // GOOD ENDING
            // credits: credits_shizune
        } else {
            // BAD ENDING
        }
    } else {
        // ks::SceneManager::fade_out(ks::globals::colors::RED, 240);
        // Show blood red scene with Dissolve 4s
        // KENJI ENDING
    }

    ks::in_game = false;

    // credits
}

int main() {
    ks::sound_manager::init();
    ks::globals::init_engine(ks::globals::colors::WHITE);

    BN_LOG("");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣤⣤⣤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⢛⣩⣥⣶⣶⣶⣦⣭⣙⠛⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⢛⣋⣭⣴⣶⣶⣶⣬⣭⣛⢿⣷⣤⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⢋⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣍⠻⣿⣤⠀⠀⠀⠀⣠⣾⠿⣩⣶⣿⣿⣿⣿⣿⣿⢹⠾⣮⢿⣿⣿⣷⣝⠿⣶⡀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣩⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣝⢿⣶⣴⣿⢛⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⠀⡿⣼⠖⠛⠉⣀⣽⣌⢿⣦⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠟⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⢋⣾⠛⣶⡿⣛⣛⠿⣿⢋⡶⠛⠋⣉⠀⣴⢶⠀⣿⢱⣾⣿⣿⣷⢻⣿⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣭⣈⣆⠘⡟⣦⣤⡈⠛⣶⢩⣭⢹⠀⠘⠒⠿⢀⣿⣿⣛⣛⡿⣿⣷⢻⣷⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢋⡞⢳⠹⢿⣿⣿⢿⣛⣛⠿⣿⣿⣾⠀⣿⢹⠀⢻⠙⣿⢀⡟⣭⣿⣿⠷⣩⡿⠉⣠⠖⠶⢶⣤⣤⣽⣼⣿⡆⣿⡄[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⣿⠀⠉⣽⡶⠋⣀⣤⣤⠈⣦⡏⣿⢠⠏⣾⠛⢀⣿⠀⡿⣼⣿⣿⣇⣿⣤⠶⣫⣾⠿⢛⠻⣿⣿⣿⣿⣿⣿⣿⡇[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⢸⣾⠛⣦⡿⠟⢿⣿⣿⣿⣿⢱⠛⢀⡆⠀⠀⣴⣫⣶⣿⣹⠀⡿⢸⣮⣭⣿⠖⣭⠟⢀⣾⣴⣿⣿⣿⣿⣿⣿⣿⣛⣤⣾⣿⣿⡿⢦⣙⢿⣿⡏⣿⡇[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢀⣿⠀⠛⠉⣀⣿⣽⣭⣽⡻⣷⣭⣽⠀⠀⢹⡜⣿⣛⡾⠁⣴⢣⣿⣿⣿⢰⣉⣤⠞⣭⣿⣿⣿⣿⣿⣿⡿⣵⣿⠿⣿⣿⣿⣿⣶⣾⣿⣿⣦⢀⣿⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⣿⠉⣇⣰⠶⣦⣀⠀⠀⢣⢿⣤⠀⢹⣏⣉⣤⣤⠶⠶⣋⣿⢁⡇⢠⢿⠀⢻⣾⣀⣴⣛⣾⣿⣿⢟⣭⠻⣿⣿⣿⣿⣿⣿⣿⣿⡿⣵⣿⣫⢟⣾⣭⢾⣛⢿⣤⣿⣾⣹⡿⣾⡿⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⢀⣴⠛⠀⢉⠙⣿⣦⣀⠛⣦⠀⣿⣄⣷⠈⣧⠶⣭⣽⣭⠶⠛⢙⡆⣝⣫⣷⣻⠞⣵⡿⣿⣿⣿⣿⡿⠸⣾⣤⡶⣛⣶⠻⣿⣿⣿⣯⣿⣫⠿⣴⣿⣿⣿⣽⣿⣿⣷⣽⢿⣴⢰⣿⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠰⣏⣠⡿⠀⣿⢿⠀⣿⠈⢷⣴⠃⠈⣿⢻⠀⢿⢛⠶⢶⠶⢛⣯⣷⣿⣿⣿⡿⣵⣭⢛⣛⣩⠶⣶⢻⣼⢸⣻⠻⣇⡿⣼⢠⣿⣫⣿⢛⡿⣵⣿⣿⣿⣿⣿⣿⣿⣮⣿⣿⣿⢡⣿⠁⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⢻⠀⣿⢸⠀⣼⠀⠀⠀⠀⠀⠀⢷⠻⠾⣱⣿⣿⣿⣿⣿⣿⢛⡶⣛⣭⣿⡘⢃⡘⣷⣿⢂⣦⣡⢷⣶⣻⢻⢩⣶⡿⣾⡿⣾⣭⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⢟⡿⣴⣿⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⢸⡀⣿⠘⠿⠋⠀⠀⠀⠀⠀⠀⠀⠙⣿⠌⢩⣥⢛⣛⣿⢹⣨⣶⣶⣶⢂⣿⣸⢛⠾⣛⣩⣾⣿⣦⣙⣒⣛⣾⠟⣼⣿⣿⣮⢾⡛⣿⣿⣿⣿⣿⡿⣵⣿⣿⢋⣾⠟⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣶⣀⣰⢛⠻⣙⣿⢙⣿⣼⢸⢡⣘⣶⣝⣒⣛⣭⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣼⣿⣿⠿⡿⢿⣾⡻⣭⢿⣿⣿⣿⣿⢋⣾⡿⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⢀⣀⢀⡾⣶⡟⣭⢹⣄⣶⣻⢻⣰⢿⣦⣿⠛⠛⣬⣉⢶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠻⣿⡁⣀⢹⣿⣿⢻⣝⢿⢿⢉⣾⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⢻⠹⢛⣾⣡⢧⢋⣦⣿⠶⠞⠛⠉⠀⠀⠀⠀⠀⠀⠛⣿⣬⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠻⣿⣿⣿⣿⣿⠾⣩⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⣆⣿⠛⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣷⣝⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣙⠿⢛⣴⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣦⣙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣥⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⣿⣦⣙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣭⣾⠿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⣿⣦⣙⢿⣿⣿⣿⠿⣩⣾⠿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("[38;5;223m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⣿⣶⣭⣾⠿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀[33;0m");
    BN_LOG("");


    BN_ASSERT(fs != NULL, "GBFS file not found.\nUse the ROM that ends with .out.gba!");

    const bool isNewSave = ks::saves::initialize();
    if (isNewSave) {
        const bool isNewSaveAgain = ks::saves::initialize();
        BN_ASSERT(!isNewSaveAgain, "Failed to initialize saves.");
    }

    ks::globals::settings = ks::saves::readSettings();
    ks::timer::init();

    ks::SceneManager::fade_out(ks::globals::colors::BLACK, 30);
    if constexpr (KS_SHOW_4LS_INTRO) {
        // Show the 4LS intro video (p1 - video playback)
        ks::sound_manager::set_channel_loop<SOUND_CHANNEL_VIDEO>(false);
        ks::SceneManager::show_video(video_4ls_dxtv, video_4ls_dxtv_size, "video_4ls.gsm", ks::globals::colors::BLACK);

        // Show the 4LS intro video (p2 - native gfx playback)
        ks::primary_background = bn::regular_bg_items::video_end_4ls.create_bg(0, 0);

        // TODO: Should be calculated in msecs for readability instead of ticks
        bn::bg_palettes::set_fade_color(ks::globals::colors::WHITE);
        for (int i = 0; i < 120; i++) {
            if (i < 30) {
                bn::bg_palettes::set_fade_intensity(bn::fixed(30 - i) / 30);
            }
            if (i == 90) {
                bn::bg_palettes::set_fade_color(ks::globals::colors::BLACK);
            }
            if (i > 90) {
                bn::bg_palettes::set_fade_intensity(bn::fixed(i - 90) / 30);
            }
            ks::globals::main_update();
        }

        ks::primary_background.reset();
        bn::bg_palettes::set_fade_intensity(0);

        // Wait 1 second
        for (int i = 0; i < 60 * 1; i++) {
            ks::globals::main_update();
        }
    }
    ks::globals::sound_update();
    ks::sound_manager::set_channel_loop<SOUND_CHANNEL_MUSIC>(true);

    while (true) {
        switch (ks::globals::state) {
            case GS_INIT:
                ks::globals::state = GS_MENU_MAIN;

                bn::bg_palettes::set_fade(ks::globals::colors::BLACK, bn::fixed(1));
                bn::sprite_palettes::set_fade(ks::globals::colors::BLACK, bn::fixed(1));

                ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
                ks::sound_manager::play(MUSIC_MENUS);
                break;
            case GS_MENU_MAIN:
                ks::MenuMain().run();
                break;
            case GS_MENU_SAVES:
                ks::MenuSaves().run();
                break;
            case GS_MENU_EXTRAS:
                ks::MenuExtras().run();
                break;
            case GS_MENU_OPTIONS:
                ks::MenuOptions().run();
                break;
            case GS_MENU_EXTRAS_CINEMA:
                ks::MenuExtrasCinema().run();
                break;
            case GS_LOAD_GAME:
                ks::timer::reset();
                ks::SceneManager::free_resources();
                ks::globals::release_engine();
                ks::globals::init_engine(ks::globals::colors::BLACK);

                ks::globals::exit_scenario = false;
                ks::is_loading = true;
                ks::progress = ks::savedata_progress;
                ks::globals::state = GS_START_GAME;
                break;
            case GS_START_GAME:
                ks::static_text_sprites.clear();
                ks::progress_icon_sprites.clear();
                ks::primary_background.reset();
                ks::secondary_background.reset();
                ks::globals::main_update();

                game(!ks::is_loading);

                if (ks::globals::state == GS_LOAD_GAME) {
                    ks::globals::exit_scenario = false;
                } else {
                    ks::globals::state = GS_RESET;
                }
                break;
            case GS_RESET:
                ks::timer::reset();
                ks::SceneManager::free_resources();
                ks::globals::exit_scenario = false;
                ks::primary_background.reset();
                ks::secondary_background.reset();
                ks::progress_icon_sprites.clear();
                ks::dialog->reset();
                ks::globals::main_update();
                bn::bg_palettes::set_fade_intensity(0);
                bn::sprite_palettes::set_fade_intensity(0);

                ks::globals::release_engine();
                ks::globals::init_engine(ks::globals::colors::BLACK);

                ks::globals::state = GS_INIT;
                break;
            default:
                BN_ERROR("Wrong state: ", ks::globals::state);
        }
    }
}
