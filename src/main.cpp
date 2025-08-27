#include "bn_bg_palettes.h"
#include "bn_core.h"
#include "bn_memory.h"
#include "bn_regular_bg_items_video_end_4ls.h"
#include "bn_sprite_palettes.h"
#include "bn_sram.h"
#include "gba_video.h"
#include "globals.h"
#include "ingametimer.h"
#include "scenemanager.h"
#include "sound_manager.h"
#include "translations/en.cpp"
#include "video_4ls_dxtv.h"
#include "menu/menu_extras.cpp.h"
#include "menu/menu_extras_cinema.cpp.h"
#include "menu/menu_extras_jukebox.cpp.h"
#include "menu/menu_main.cpp.h"
#include "menu/menu_options.cpp.h"
#include "menu/menu_saves.cpp.h"

#include "background_metas.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "temp/test_drugs.cpp.h"
#include "temp/test_huge_bg.cpp.h"

using size_type = int;

inline void game(const bool is_new_game) {
    ks::globals::state = GS_GAME;
    ks::globals::in_game = true;
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
    ks::globals::i18n->script_a1_friday()();
    ks::globals::i18n->script_a1_saturday()();
    ks::globals::i18n->script_a1_sunday()();

    if (ks::progress.force_route == FR_EMI) {
        // video: tc_act2_emi
        IF_NOT_EXIT(ks::SceneManager::show_video(video_tc_act2_emi_dxtv, video_tc_act2_emi_dxtv_size, "video_tc_act2_emi.ulc", ks::globals::colors::WHITE););
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
        IF_NOT_EXIT(ks::SceneManager::show_video(video_tc_act2_hanako_dxtv, video_tc_act2_hanako_dxtv_size, "video_tc_act2_hanako.ulc", ks::globals::colors::WHITE););
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
        IF_NOT_EXIT(ks::SceneManager::show_video(video_tc_act2_lilly_dxtv, video_tc_act2_lilly_dxtv_size, "video_tc_act2_lilly.ulc", ks::globals::colors::WHITE););
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
        IF_NOT_EXIT(ks::SceneManager::show_video(video_tc_act2_rin_dxtv, video_tc_act2_rin_dxtv_size, "video_tc_act2_rin.ulc", ks::globals::colors::WHITE););
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
        IF_NOT_EXIT(ks::SceneManager::show_video(video_tc_act2_shizune_dxtv, video_tc_act2_shizune_dxtv_size, "video_tc_act2_shizune.ulc", ks::globals::colors::WHITE););
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
        IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 120));
        IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLOODRED));
        IF_NOT_EXIT(ks::SceneManager::update_visuals());
        // Show blood red scene with Dissolve 4s
        // KENJI ENDING
    }

    if (ks::is_loading) {
        BN_ERROR("Unable to load savegame.");
    }

    ks::globals::in_game = false;

    // credits
}

inline float bezier_f(float t) {
    return t * t * (3.0f - 2.0f * t);
}

inline void print_save_debug() {
    const auto flashInfo = ks::saves::get_flash_info();
    constexpr auto lineHeight = 12;

    bn::bg_palettes::set_transparent_color(ks::globals::colors::BLACK);
    ks::primary_background.reset();
    ks::static_text_sprites.clear();
    ks::text_generator_small->generate_top_left(8, lineHeight * 0, "Flash Info:", ks::static_text_sprites);
    ks::text_generator_small->generate_top_left(8, lineHeight * 1, bn::format<64>("- ManufacturerId: {}", flashInfo.manufacturer), ks::static_text_sprites);
    ks::text_generator_small->generate_top_left(8, lineHeight * 2, bn::format<64>("- DeviceType: {}", flashInfo.device), ks::static_text_sprites);
    ks::text_generator_small->generate_top_left(8, lineHeight * 3, bn::format<64>("- SizeType: {}", flashInfo.size), ks::static_text_sprites);
    ks::text_generator_small->generate_top_left(8, lineHeight * 4, "Press START to continue...", ks::static_text_sprites);
    ks::text_generator_small->generate_top_left(8, lineHeight * 5, "Press SELECT to fake SRAM...", ks::static_text_sprites);
    while (!bn::keypad::start_pressed() && !bn::keypad::select_pressed()) {
        bn::core::update();
    }
    if (bn::keypad::select_pressed()) {
        ks::saves::set_flash_info_fake_sram();
        ks::saves::initialize();
    }
    ks::primary_background.reset();
    ks::static_text_sprites.clear();
    bn::bg_palettes::set_transparent_color(ks::globals::colors::WHITE);
}

int main() {
    while(REG_VCOUNT != 160)
    {
    }

    while(REG_VCOUNT != 161)
    {
    }

    BN_LOG("Katawa Shoujo GBA: ", KS_BUILD_STRING);
    BN_LOG("Build date: ", KS_BUILD_DATE);
    BN_LOG("Built on: ", KS_BUILD_HOST_OS, "/", KS_BUILD_HOST_ENV);
    BN_LOG("Compiler: ", KS_BUILD_COMPILER);
    BN_LOG("⠀");

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

    ks::globals::init_engine(ks::globals::colors::WHITE);
    sound_mixer::init();
    bn::core::update();
    sound_mixer::mute();
    ks::globals::init_filesystem();

    if (ks::saves::initialize()) {
        print_save_debug();

        const bool isNewSaveAgain = ks::saves::initialize();
        BN_ASSERT(!isNewSaveAgain, "Failed to initialize saves.");
    } else {
        print_save_debug();
    }

    ks::globals::settings = ks::saves::readSettings();
    ks::timer::init();

    ks::SceneManager::fade_out(ks::globals::colors::BLACK, 30);

    if constexpr (KS_SHOW_4LS_INTRO) {
        // Show the 4LS intro video (p1 - video playback)
        ks::sound_manager::set_channel_loop<SOUND_CHANNEL_VIDEO>(false);
        ks::SceneManager::show_video(video_4ls_dxtv, video_4ls_dxtv_size, "video_4ls.ulc", ks::globals::colors::BLACK);

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
    ks::sound_manager::set_channel_loop<SOUND_CHANNEL_MUSIC>(true);

    test_drugs();

    while (true) {
        switch (ks::globals::state) {
            case GS_INIT:
                ks::globals::state = GS_MENU_MAIN;
                ks::globals::in_game = false;

                bn::bg_palettes::set_fade(ks::globals::colors::BLACK, bn::fixed(1));
                bn::sprite_palettes::set_fade(ks::globals::colors::BLACK, bn::fixed(1));

                ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
                ks::sound_manager::play(MUSIC_MENUS);
                sound_mixer::unmute();
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
            case GS_MENU_EXTRAS_JUKEBOX:
                ks::MenuExtrasJukebox().run();
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
                ks::huge_background.reset();
                ks::primary_background.reset();
                ks::secondary_background.reset();
                // ks::globals::main_update();

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
                ks::globals::in_game = false;
                ks::huge_background.reset();
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
