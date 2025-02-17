#include "scenemanager.h"
#include "bn_bg_palettes.h"
#include "bn_format.h"
#include "bn_regular_bg_items_ui_ingame_menu_background_0.h"
#include "bn_sprite_palettes.h"
#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_item.h"
#include "bn_sprite_actions.h"
#include "bn_blending_actions.h"
#include "globals.h"
#include "gsmplayer/player.h"
#include "gsmplayer/player_sfx.h"
#include "translation.h"
#include "utils/scenario_reader.h"
#include "utils/lz77.h"
#include "utils/gbfs/gbfs.h"
#include <BN_LOG.h>

#include "bn_memory.h"

#include "bn_core.h"
// #include "bn_blending_fade_alpha.h"
// #include "bn_blending_fade_alpha_hbe_ptr.h"
// #include "bn_bg_palette_color_hbe_ptr.h"
#include "bn_blending_transparency_attributes.h"
#include "bn_blending_transparency_attributes_hbe_ptr.h"
#include "bn_regular_bg_items_ui_backdrop_dots.h"
#include "videoplayer/video_player.h"
// #include "bn_sprite_items_ui_backdrop_dots_top.h"
// #include "bn_sprite_items_ui_backdrop_dots_bottom.h"

// #include "bn_regular_bg_position_hbe_ptr.h"
// #include "bn_regular_bg_attributes_hbe_ptr.h"

#include "video_4ls_agmv.h"
#include "video_op_1_agmv.h"

namespace ks {

// alignas(4) u8* EWRAM_DATA text_db;
u8 EWRAM_DATA text_db[131072];
// alignas(4) u8 EWRAM_DATA text_db[65536];
u32 text_db_size;

bn::optional<ks::SceneManager> scene;
bn::sprite_text_generator* text_generator;
ks::DialogBox* dialog;
bn::optional<bn::regular_bg_ptr> main_background;
bn::optional<bn::regular_bg_ptr> secondary_background;
bn::optional<bn::regular_bg_ptr> tertiary_background;
bn::vector<character_visuals_ptr, 8> character_visuals;
background_visuals_ptr background_visual;

bn::rect_window left_window = bn::rect_window::external();
bn::rect_window right_window = bn::rect_window::internal();
bn::array<bn::blending_transparency_attributes, 160> transparency_attributes;
bn::optional<bn::blending_transparency_attributes_hbe_ptr> transparency_attributes_hbe;

bn::vector<unsigned char, 5> answers_index_map;
ks::saves::SaveSlotProgressData progress;
bool in_replay = false;

bn::vector<bn::sprite_ptr, 18>* progress_icon_sprites;
bn::vector<bn::sprite_ptr, 64>* static_text_sprites;
bn::vector<bn::sprite_ptr, 128>* animated_text_sprites;

ks::character_definition SceneManager::_cached_actor;
int SceneManager::_cached_tl_key = -1;

void SceneManager::free_resources() {
    delete &background_visual.background;
    background_visual.bg_item.reset();
    while (character_visuals.size() < character_visuals.max_size()) {
        character_visuals.push_back(character_visuals_ptr());
    }
    for (auto &visual : character_visuals) {
        visual.background.reset();
        visual.sprite.reset();
    }
}

void SceneManager::set(const ks::SceneManager instance) {
    BN_LOG("RESET SCENE");
    scene.reset();
    BN_LOG("Set SM Instance");
    scene = instance;

    // ks::scenario::gbfs_reader::read_scenario_text_db(scene->scenario(), scene->locale(), text_db);

    u32 src_len = 0;
    u8* compressed_data;

    BN_LOG("Read Scene File...");
    auto filename = bn::string<32>(scene->scenario()).append(".").append(scene->locale()).c_str();
    compressed_data = (u8*)gbfs_get_obj(fs, filename, &src_len);

    text_db_size = (compressed_data[1]) | (compressed_data[2] << 8) | (compressed_data[3] << 16);
    // BN_LOG("Uncompressed size:", text_db_size);
    // BN_LOG("Compressed data header: ",
    //        "Byte 0: ", compressed_data[0],
    //        ", Byte 1: ", compressed_data[1],
    //        ", Byte 2: ", compressed_data[2],
    //        ", Byte 3: ", compressed_data[3]);

    // if (text_db) {
    //     free(text_db);
    // //     // bn::memory::ewram_free(text_db);
    // }


    BN_LOG("EWRAM BEFORE ", bn::memory::available_alloc_ewram());
    BN_LOG("Allocate memory...");
    BN_LOG("Size: ", text_db_size);
    // bn::memory::ewram_free(text_db);
    // text_db = (u8*)bn::memory::ewram_alloc(text_db_size);
    // text_db = (u8*)aligned_alloc(8, text_db_size);
    // text_db = (u8*)malloc(text_db_size);
    // BN_LOG("OK!");
    // if (!text_db) {
    //     BN_ERROR("Error: Failed to allocate memory for text_db.");
    //     return;
    // }
    BN_LOG("Decompress Scene file...");
    LZ77UnCompWRAM((u32)compressed_data, (u32)text_db);
    BN_LOG("EWRAM AFTER ", bn::memory::available_alloc_ewram());
    BN_LOG("Decoded TextDB:", text_db);
    for (u32 i = 0; i < 16; i++) {
        BN_LOG("TextDB byte [", i, "]: ", text_db[i], " Char: ", (char)text_db[i]);
    }

    BN_LOG("Set Window boundaries");
    left_window.set_boundaries(-80,-120,80,0);
    right_window.set_boundaries(-80,0,80,120);
    BN_LOG("SceneManager init done!");
}

void SceneManager::set_background(const bn::regular_bg_item& bg, const int position_x, const int position_y, const int dissolve_time) {
    // TODO: rewrite to support "scene" token
    // temporaly hide chars
    for (int i = 0; i < character_visuals.size(); i++) {
        hide_character(i, false);
    }

    ks::globals::sound_update();
    if (background_visual.bg_item != bg) {
        bool with_dissolve = dissolve_time > 0;
        bool have_background = main_background.has_value();
        bool have_characters = false;
        for (auto& v : character_visuals) {
            if (v.sprite.has_value()) {
                have_characters = true;
            }
        }

        BN_LOG("WITH DISSOLVE: ", with_dissolve);
        BN_LOG("HAVE BG: ", have_background);
        BN_LOG("HAVE CHARS: ", have_characters);

        background_visual.bg_item = bg;
        background_visual.position_x = position_x;
        background_visual.position_y = position_y;
        background_visual.dissolve_on_top = false;

        if (with_dissolve && have_background && !have_characters) {
            // with_dissolve = false;
            // main_background.reset();
            // main_background = bg.create_bg(position_x, position_y);
            // main_background->set_z_order(10);

            // background_visual.background = &main_background.value();


            // // main_background->set_tiles()
            // background_visual.dissolve_on_top = true;
            // secondary_background.reset();
            // secondary_background = bg.create_bg(position_x, position_y);
            // secondary_background->set_z_order(9);

            // background_visual.background = &secondary_background.value();

            // First — Attempt to create dissolve BG:
            secondary_background.reset();
            secondary_background = bg.create_bg_optional(position_x, position_y);
            if (secondary_background.has_value()) {
                secondary_background->set_priority(3);
                secondary_background->set_z_order(9);
                background_visual.dissolve_on_top = true;
                background_visual.background = &secondary_background.value();
            } else {
                for (int i = 0; i < 10; i++) {
                    BN_LOG("!!! Unable to create DISSOLVE BG !!!");
                }
                with_dissolve = false;
                main_background.reset();
                main_background = bg.create_bg(position_x, position_y);
                main_background->set_priority(3);
                main_background->set_z_order(10);

                background_visual.background = &main_background.value();
            }
        } else {
            // delete &background_visual.background;
            main_background.reset();
            main_background = bg.create_bg(position_x, position_y);
            main_background->set_priority(3);
            main_background->set_z_order(10);

            background_visual.background = &main_background.value();
        }

        if (with_dissolve && !(have_background && have_characters)) {
            background_visual.will_show = true;
            background_visual.dissolve_time = dissolve_time;
        } else {
            background_visual.will_show = false;
            background_visual.dissolve_time = 0;
        }
    } else {
        BN_LOG("Set position of BG!!!!");
        BN_LOG("X: ", position_x, "; Y: ", position_y);
        background_visual.position_x = position_x;
        background_visual.position_y = position_y;
    }

    ks::globals::sound_update();
}

// void SceneManager::set_background(const bn::regular_bg_item& bg) {
//     set_background(bg, 0, 0);
// }

void SceneManager::set_background_position(const int position_x, const int position_y) {
    background_visual.position_x = position_x;
    background_visual.position_y = position_y;
}

void SceneManager::show_dialog(const ks::character_definition& actor, int tl_key) {
    BN_LOG("SH1");
    _cached_actor = actor;
    _cached_tl_key = tl_key;

    BN_LOG("SH2");
    while (!ks::globals::exit_scenario) {
        bn::string<1024> message;
        // ks::scenario::gbfs_reader::get_tl<1024>(scene->scenario(), scene->locale(), scene->_script_tl_index[tl_key], message);
        BN_LOG("TextDB pointer in global scope:", (u32)text_db);
        ks::scenario::gbfs_reader::get_tl<1024>(text_db, text_db_size, scene->_script_tl_index[tl_key], message);
        ks::globals::sound_update();
        // ks::globals::main_update();
        dialog->show(actor.name(), message);
        while (!dialog->is_finished() && !bn::keypad::start_pressed()) {
            dialog->update();
            ks::globals::main_update();
        }
        if (bn::keypad::start_pressed()) {
            dialog->hide_blend();
            SceneManager::open_ingame_menu();
            continue;
        }
        break;
    }
}

void SceneManager::show_dialog(const char* actor_name, int tl_key) {
    const ks::character_definition current = ks::definitions::base.with_name(actor_name);
    return show_dialog(current, tl_key);
}

void BN_CODE_EWRAM SceneManager::show_dialog_question(bn::vector<ks::answer_ptr, 5> answers) {
    bool redisplay_dialog = false;  // Prevents re-showing dialog unnecessarily

    // TODO: IDEAAA!!!! TO USE 1024 SIZED MESSAGE I CAN USE TWO METHOD CALLS INSIDE WHILE CYCLE.
    // - FIRST: REDISPLAY
    // - SECOND: PERFORM QUESTION
    // Looks like this way compiler shouldn't create bn::string<1024> and bn::vector<bn::string<128>, 5> at the same scope
    // and should release resources on each method pop from stack
    // WAAAAAAAAHAA!~

    while (!ks::globals::exit_scenario) {
        if (redisplay_dialog) {
            bn::string<1024> message;
            // ks::scenario::gbfs_reader::get_tl<1024>(scene->scenario(), scene->locale(), scene->_script_tl_index[_cached_tl_key], message);
            ks::scenario::gbfs_reader::get_tl<1024>(text_db, text_db_size, scene->_script_tl_index[_cached_tl_key], message);
            ks::globals::sound_update();
            dialog->show(_cached_actor.name(), message);

            while (!dialog->is_finished() && !bn::keypad::start_pressed()) {
                dialog->update();
                ks::globals::main_update();
            }
        }

        // Phase 2: Display the question dialog
        answers_index_map.clear();
        bn::vector<bn::string<128>, 5> answers_messages;

        for (int i = 0; i < answers.size(); i++) {
            bn::string<128> answer;
            // ks::scenario::gbfs_reader::get_tl<128>(
            //     scene->scenario(), scene->locale(), scene->_script_tl_index[answers.at(i).tl_key], answer);
            ks::scenario::gbfs_reader::get_tl<128>(text_db, text_db_size, scene->_script_tl_index[answers.at(i).tl_key], answer);
            ks::globals::sound_update();
            answers_messages.push_back(answer);
            answers_index_map.push_back(answers.at(i).index);
        }

        dialog->show_question(answers_messages);

        while (!dialog->is_finished() && !bn::keypad::start_pressed()) {
            dialog->update();
            ks::globals::main_update();
        }

        if (bn::keypad::start_pressed()) {
            // Pause and re-open menu logic
            dialog->reset_question();
            dialog->hide_blend();
            SceneManager::open_ingame_menu();
            redisplay_dialog = true;
            continue;
        }
        break;
    }
}

int SceneManager::get_dialog_question_answer() {
    return answers_index_map.at(dialog->get_answer_index());
}

void SceneManager::show_character(const int character_index,
                                  const bn::regular_bg_item& bg,
                                  const bn::sprite_item& sprite,
                                  const ks::character_sprite_meta& sprite_meta,
                                  const int position_x,
                                  const int position_y,
                                  const bool position_change,
                                  const bool restoring = false) {
    bool was_shown_before = character_visuals.at(character_index).background.has_value();

    // TODO: make restoring as separate method
    if (!restoring) {
        character_visuals.at(character_index).index = character_index;
        character_visuals.at(character_index).bg_item = bg;
        character_visuals.at(character_index).sprite_item = sprite;
        character_visuals.at(character_index).sprite_meta = sprite_meta;

        if (position_change && !was_shown_before) {
            character_visuals.at(character_index).position_x = position_x;
            character_visuals.at(character_index).position_y = position_y;
        }
        // if (!was_shown_before) {
        //     dialog->hide_blend();
        // }
    }

    // DISABLE DISSOLVING BG IF ANY!!!!
    // TODO: Refactor to displayable queue
    if (background_visual.dissolve_on_top) {
        BN_LOG("!!! CANCEL DISSOLVE ON TOP !!!");

        background_visual.dissolve_on_top = false;
        background_visual.will_show = false;
        background_visual.dissolve_time = 0;
        BN_LOG(" - main BG reset");
        main_background.reset();
        BN_LOG(" - secondary BG reset");
        secondary_background.reset();

        BN_LOG(" - create new main BG");
        main_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
        main_background->set_priority(3);
        main_background->set_z_order(10);

        BN_LOG(" - update BG pointer");
        background_visual.background = &main_background.value();

        ks::globals::main_update();
        BN_LOG("!!! CANCEL DISSOLVE ON TOP - DONE !!!");
    }

    BN_LOG("SHOW CHARACTER ", character_index);

    ks::globals::sound_update();
    character_visuals.at(character_index).background.reset();
    character_visuals.at(character_index).background = character_visuals.at(character_index).bg_item->create_bg(character_visuals.at(character_index).position_x,
                                                                    character_visuals.at(character_index).position_y);
    character_visuals.at(character_index).background->set_priority(2);
    character_visuals.at(character_index).background->set_z_order(10);
    ks::globals::sound_update();

    character_visuals.at(character_index).sprite.reset();
    character_visuals.at(character_index).sprite = character_visuals.at(character_index).sprite_item->create_sprite(character_visuals.at(character_index).position_x + sprite_meta.offset_x,
                                                                        character_visuals.at(character_index).position_y + sprite_meta.offset_y);
    character_visuals.at(character_index).offset_x = sprite_meta.offset_x;
    character_visuals.at(character_index).offset_y = sprite_meta.offset_y;
    character_visuals.at(character_index).sprite->set_bg_priority(2);
    character_visuals.at(character_index).sprite->set_z_order(10);

    // set_character_window_visibility(character_visuals.at(character_index).background.value(), position_x, position_y);
    set_character_window_visibility(character_visuals.at(character_index).background.value());

    if (!restoring) {
        if (!was_shown_before) {
            character_visuals.at(character_index).will_show = true;
            // character_visuals.at(character_index).alpha = 1.0;


            // bn::blending::set_transparency_alpha(0);
            // auto spr_alpha_action = bn::blending_transparency_alpha_to_action(20, 1);
            // character_visuals.at(character_index).sprite->set_blending_enabled(true);
            // character_visuals.at(character_index).background->set_blending_enabled(true);
            // while (!spr_alpha_action.done()) {
            //     spr_alpha_action.update();

            //     ks::globals::main_update();
            // }
            // character_visuals.at(character_index).sprite->set_blending_enabled(false);
            // character_visuals.at(character_index).background->set_blending_enabled(false);
        }

        // ks::globals::main_update();

        if (position_change && was_shown_before) {
            set_character_position(character_index, position_x, position_y);
        }
    }
}

void SceneManager::show_character(const int character_index,
                                  const bn::regular_bg_item& bg,
                                  const bn::sprite_item& sprite,
                                  const ks::character_sprite_meta& sprite_meta,
                                  const int position_x,
                                  const int position_y) {
    show_character(character_index, bg, sprite, sprite_meta, position_x, position_y, true);
}

void SceneManager::show_character(const int character_index,
                                  const bn::regular_bg_item& bg,
                                  const bn::sprite_item& sprite,
                                  const ks::character_sprite_meta& sprite_meta) {
    show_character(character_index, bg, sprite, sprite_meta, 0, 0, false);
}

void SceneManager::set_character_position(const int character_index,
                                          const int position_x,
                                          const int position_y) {
    character_visuals.at(character_index).position_x = position_x;
    character_visuals.at(character_index).position_y = position_y;
}

// void SceneManager::set_character_window_visibility(bn::regular_bg_ptr bg, bn::fixed target_x, bn::fixed target_y)
void SceneManager::set_character_window_visibility(bn::regular_bg_ptr bg)
{
    bool is_right = true;
    bool is_left = true;
    bn::fixed x_pos = bg.position().x();

    BN_LOG("CHARA X: ", x_pos);

    if (x_pos > ks::device::screen_width_half - 64) {
        // This is a right side of screen
        // [ | | |x]
        // if (target_x > 0) {
            is_left = false;
        // }
    } else if (x_pos < -ks::device::screen_width_half + 64) {
        // This is a left side of screen
        // [x| | | ]
        // if (target_x < 0) {
            is_right = false;
        // }
    }

    bg.set_visible_in_window(is_left, left_window);
    bg.set_visible_in_window(is_right, right_window);
}

void SceneManager::hide_character(const int character_index, const bool need_update) {
    character_visuals.at(character_index).bg_item.reset();
    character_visuals.at(character_index).sprite_item.reset();
    character_visuals.at(character_index).sprite_meta.reset();
    character_visuals.at(character_index).background.reset();
    character_visuals.at(character_index).sprite.reset();
    character_visuals.at(character_index).position_x = 0;
    character_visuals.at(character_index).position_y = 0;
    if (need_update) {
        ks::globals::main_update();
    }
}

void SceneManager::hide_character(const int character_index) {
    hide_character(character_index, true);
}

void SceneManager::update_visuals() {
    bool incomplete = true;
    bool show_blend = false;
    // bool hide_blend = false;
    bool bg_show_blend = false;
    bn::vector<bn::regular_bg_move_to_action, 9> bg_moves;
    bn::vector<bn::sprite_move_to_action, 8> spr_moves;
    bn::vector<bn::regular_bg_ptr, 4> bg_blend_ptrs;
    bn::vector<bn::sprite_ptr, 4> spr_blend_ptrs;
    bn::optional<bn::blending_transparency_alpha_to_action> blend_action;
    bn::optional<bn::blending_transparency_alpha_to_action> bg_blend_action;

    bg_moves.clear();
    spr_moves.clear();
    bg_blend_ptrs.clear();
    spr_blend_ptrs.clear();


    if (background_visual.position_x != background_visual.background->position().x() ||
        background_visual.position_y != background_visual.background->position().y()) {
        bg_moves.push_back(bn::regular_bg_move_to_action(*background_visual.background,
                                                         20,
                                                         background_visual.position_x,
                                                         background_visual.position_y));
    }
    if (background_visual.will_show) {
        bg_show_blend = true;
    }

    for (auto &visual : character_visuals) {
        if (!visual.background.has_value()) {
            continue;
        }

        if (visual.will_show) {
            show_blend = true;
            bg_blend_ptrs.push_back(visual.background.value());
            spr_blend_ptrs.push_back(visual.sprite.value());
        }

        if (visual.position_x != visual.background->position().x() ||
            visual.position_y != visual.background->position().y()) {



            bg_moves.push_back(bn::regular_bg_move_to_action(visual.background.value(),
                                                             20,
                                                             visual.position_x,
                                                             visual.position_y));
            spr_moves.push_back(bn::sprite_move_to_action(visual.sprite.value(),
                                                          20,
                                                          visual.position_x + visual.offset_x,
                                                          visual.position_y + visual.offset_y));
        }
    }

    if (bg_show_blend) {
        background_visual.background->set_visible(false);
        if (!dialog->is_hidden()) {
            dialog->hide_blend();
        }
    }

    if (show_blend) {
        for (auto blending_bg : bg_blend_ptrs) {
            blending_bg.set_visible(false);
        }
        for (auto blending_spr : spr_blend_ptrs) {
            blending_spr.set_visible(false);
        }
        if (!dialog->is_hidden()) {
            dialog->hide_blend();
        }
    }

    if (bg_show_blend) {
        bn::blending::set_transparency_alpha(0.0);
        background_visual.background->set_visible(true);
        background_visual.background->set_blending_enabled(true);
        bg_blend_action = bn::blending_transparency_alpha_to_action(background_visual.dissolve_time, 1.0);
    }

    // BLEND BG
    while (bg_blend_action.has_value() && !bg_blend_action->done()) {
        bg_blend_action->update();
        ks::globals::main_update();
    }
    if (background_visual.background) {
        background_visual.background->set_blending_enabled(false);
        if (background_visual.dissolve_on_top) {
            background_visual.dissolve_on_top = false;
            BN_LOG("REPLACE BG!");
            main_background.reset();
            // main_background = secondary_background.value();
            secondary_background.reset();
            main_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            main_background->set_priority(3);
            main_background->set_z_order(10);
            background_visual.background = &main_background.value();
            bn::core::update();
        }
    }

    if (show_blend) {
        for (auto blending_bg : bg_blend_ptrs) {
            blending_bg.set_blending_enabled(true);
            blending_bg.set_visible(true);
        }
        for (auto blending_spr : spr_blend_ptrs) {
            blending_spr.set_blending_enabled(true);
            blending_spr.set_visible(true);
        }

        bn::blending::set_transparency_alpha(0.0);
        blend_action = bn::blending_transparency_alpha_to_action(20, 1.0);
    }

    // BLEND and MOVES chars
    while (incomplete) {
        incomplete = false;

        for (auto &action : bg_moves) {
            BN_LOG("MOVE CHARACTER");
            if (!action.done()) {
                incomplete = true;

                action.update();
                // set_character_window_visibility(action.bg(), action.final_position().x(), action.final_position().y());
                set_character_window_visibility(action.bg());
            }
        }

        for (auto &action : spr_moves) {
            if (!action.done()) {
                incomplete = true;

                action.update();
            }
        }

        if (show_blend) {
            if (!blend_action->done()) {
                incomplete = true;

                blend_action->update();
            }
        }

        ks::globals::main_update();
    }
    if (background_visual.will_show) {
        background_visual.will_show = false;
    }
    for (auto &visual : character_visuals) {
        if (visual.will_show) {
            visual.will_show = false;
        }
    }
    for (auto blending_bg : bg_blend_ptrs) {
        blending_bg.set_blending_enabled(false);
    }
    for (auto blending_spr : spr_blend_ptrs) {
        blending_spr.set_blending_enabled(false);
    }
}

void SceneManager::music_play(const char* filename) {
    music_play(filename, 0);
}

void SceneManager::music_play(const char* filename, bn::fixed fade) {
    BN_LOG("Play GSM ", filename, " with fade ", fade);
    if (player_isPlaying()) {
        player_stop();
    }
    player_playGSM(filename);
    player_setLoop(true);
    ks::globals::main_update();
}

void SceneManager::music_stop() {
    if (player_isPlaying()) {
        player_stop();
    }
}

void SceneManager::sfx_play(const char* filename) {
    sfx_play(filename, 0);
}

void SceneManager::sfx_play(const char* filename, bn::fixed fade) {
    BN_LOG("Play SFX ", filename, " with fade ", fade);
    if (player_sfx_isPlaying()) {
        player_sfx_stop();
    }
    player_sfx_play(filename);
    player_sfx_setLoop(false);
}

void SceneManager::sfx_stop() {
    if (player_sfx_isPlaying()) {
        player_sfx_stop();
    }
}

void SceneManager::show_video(const uint8_t* agmv_file, size_t agmv_size, const char* audio_file, bn::color clear) {
    // Free last sound chunks
    player_stop();
    player_sfx_stop();
    ks::globals::sound_update();

    bool is_act_video = true;

    bn::color clear_color;
    if (agmv_file == video_4ls_agmv) {
        clear_color = globals::colors::BLACK;
        is_act_video = false;
    }

    if (is_act_video && agmv_file != video_op_1_agmv) {
        clear_color = globals::colors::WHITE;
        fade_out(clear_color, 120);
    }

    ks::globals::release_engine();
    ks::globals::init_engine(clear_color);

    if (is_act_video) {
        pause(60);
    }

    // fade_reset();
    videoplayer_init(agmv_file, agmv_size, audio_file, clear_color.red(), clear_color.green(), clear_color.blue());
    videoplayer_play();
    videoplayer_clean();

    // Re-init Butano Core
    ks::globals::release_engine();
    ks::globals::init_engine();
}

void SceneManager::show_video(const uint8_t* agmv_file, size_t agmv_size, const char* audio_file) {
    show_video(agmv_file, agmv_size, audio_file, ks::globals::colors::BLACK);
}


void SceneManager::open_ingame_menu() {
    const int TRANSITION_STEPS = 16;

    // bn::bg_palettes::set_fade_color(BLACK);
    // bn::sprite_palettes::set_fade_color(BLACK);

    // Enable blending for characters
    for (auto& char_visual : character_visuals) {
        if (char_visual.background.has_value() && char_visual.sprite.has_value()) {
            char_visual.background->set_blending_enabled(true);
            char_visual.sprite->set_blending_enabled(true);
        }
    }
    // First of all — blend palettes to half-BLACK
    for(int alpha = 0; alpha <= TRANSITION_STEPS; ++alpha) {

        bn::blending::set_transparency_alpha(bn::fixed(TRANSITION_STEPS - alpha) / TRANSITION_STEPS);
        ks::globals::main_update();
    }

    // Hide all characters
    for (auto& char_visual : character_visuals) {
        char_visual.background.reset();
        char_visual.sprite.reset();
    }

    bn::fixed dots_offset = 0;
    secondary_background = bn::regular_bg_items::ui_backdrop_dots.create_bg(0, 0);
    secondary_background->set_blending_enabled(true);

    // bn::array<bn::blending_transparency_attributes, 160> dots_tattr;
    // bn::optional<bn::blending_transparency_attributes_hbe_ptr> transparency_attributes_hbe;

    unsigned char frame_skip = 0;
    unsigned char frame = 0;

    while (dots_offset < 160 + 96) {
        if (frame > frame_skip) {
            frame = 0;
        }

        if (frame == 0) {
            dots_offset += 16;
            secondary_background->set_position(0, -80 + 128 + dots_offset);
            for(int index = 0, amplitude = 160; index < amplitude; ++index)
            {
                // bn::fixed
                bn::fixed clamped_alpha = bn::min(bn::max((index + 32 - dots_offset) / (32), bn::fixed(0)), bn::fixed(1));
                bn::fixed transparency_alpha = (bn::fixed(1) - clamped_alpha) * bn::fixed(0.5);
                transparency_attributes[index].set_transparency_alpha(transparency_alpha);
            }
        }

        transparency_attributes_hbe = bn::blending_transparency_attributes_hbe_ptr::create(transparency_attributes);
        // transparency_attributes_hbe = bn::blending_transparency_attributes_hbe_ptr::create(dots_tattr);
        ks::globals::main_update();
        frame++;
    }

    // delete &dots_tattr;
    transparency_attributes_hbe.reset();

    secondary_background.reset();

    // Disable the transparency BLENDING!
    bn::blending::set_transparency_alpha(1);

    // Enable the fade BLENDING!
    bn::blending::set_fade_alpha(0.5);
    main_background->set_blending_enabled(true);
    ks::globals::main_update();


    // TEMP
    tertiary_background = bn::regular_bg_items::ui_ingame_menu_background_0.create_bg(0, 0);

    // TEMP
    unsigned char selected = 0;
    bn::vector<signed char, 64> selection_index;
    bn::sprite_palette_item original_palette_item = ks::text_generator->palette_item();
    bn::sprite_palette_item beige_palette_item = bn::sprite_items::variable_16x16_font_beige.palette_item();
    bn::sprite_palette_item beige_selected_palette_item = bn::sprite_items::variable_16x16_font_beige_selected.palette_item();
    static_text_sprites->clear();
    ks::text_generator->set_center_alignment();
    ks::text_generator->set_one_sprite_per_character(false);
    ks::text_generator->generate(0, -ks::device::screen_height_half + 8, bn::format<64>("{}: {}", ks::globals::i18n->screens_playtime(), "0:00:00"), *static_text_sprites);
    ks::globals::sound_update();
    selection_index.resize(static_text_sprites->size(), -1);

    ks::text_generator->generate(0, -48, ks::globals::i18n->screens_return(), *static_text_sprites);
    ks::globals::sound_update();
    selection_index.resize(static_text_sprites->size(), 0);

    ks::text_generator->generate(0, -32, ks::globals::i18n->screens_history(), *static_text_sprites);
    ks::globals::sound_update();
    selection_index.resize(static_text_sprites->size(), 1);

    ks::text_generator->generate(0, -16, ks::globals::i18n->screens_options(), *static_text_sprites);
    ks::globals::sound_update();
    selection_index.resize(static_text_sprites->size(), 2);

    ks::text_generator->generate(0, 0, ks::globals::i18n->screens_save_game(), *static_text_sprites);
    ks::globals::sound_update();
    selection_index.resize(static_text_sprites->size(), 3);

    ks::text_generator->generate(0, 16, ks::globals::i18n->screens_load_game(), *static_text_sprites);
    ks::globals::sound_update();
    selection_index.resize(static_text_sprites->size(), 4);

    ks::text_generator->generate(0, 32, ks::globals::i18n->screens_main_menu(), *static_text_sprites);
    ks::globals::sound_update();
    selection_index.resize(static_text_sprites->size(), 5);

    ks::text_generator->set_palette_item(original_palette_item);
    ks::text_generator->generate(0, ks::device::screen_height_half - 8 - 12, bn::format<64>("{}: {}", ks::globals::i18n->screens_current_scene(), ks::globals::i18n->definitions_no_scene()), *static_text_sprites);
    ks::text_generator->generate(0, ks::device::screen_height_half - 8, bn::format<64>("{}: {}", ks::globals::i18n->screens_current_track(), ks::globals::i18n->definitions_nothing()), *static_text_sprites);
    ks::globals::sound_update();
    selection_index.resize(static_text_sprites->size(), -1);

    bool action_performed = false;
    while (!action_performed) {
        BN_LOG("Calc palettes");
        for (int i = 0; i < static_text_sprites->size(); i++) {
            bool is_selected = selection_index.at(i) == selected;
            bool is_action = selection_index.at(i) != -1;
            if (!is_action) {
                static_text_sprites->at(i).set_palette(original_palette_item);
            } else {
                static_text_sprites->at(i).set_palette(is_selected ? beige_selected_palette_item : beige_palette_item);
            }
        }

        while (true) {
            ks::globals::main_update();
            if (bn::keypad::up_pressed() || bn::keypad::down_pressed()) {
                selected += bn::keypad::down_pressed() ? 1 : -1;
                selected += 6;
                selected = selected % 6;
                break;
            }
            if (bn::keypad::start_pressed() || bn::keypad::b_pressed()) {
                action_performed = true;
                break;
            }
            if (bn::keypad::a_pressed()) {
                if (selected == 0) {
                    action_performed = true;
                }
                if (selected == 5) {
                    action_performed = true;
                    ks::globals::exit_scenario = true;
                    BN_LOG("EXIT_SCENARIO");
                }
                break;
            }
        }
    }

    // backwards processing.
    bn::blending::set_fade_alpha(0);
    main_background->set_blending_enabled(false);
    ks::text_generator->set_left_alignment();

    if (!ks::globals::exit_scenario) {
        SceneManager::close_ingame_menu();
    } else {
        SceneManager::exit_scenario_from_ingame_menu();
    }
}

void SceneManager::close_ingame_menu() {
    static_text_sprites->clear();
    animated_text_sprites->clear();
    tertiary_background.reset();

    bn::fixed dots_offset = 160 + 96;
    secondary_background = bn::regular_bg_items::ui_backdrop_dots.create_bg(0, 0);
    secondary_background->set_blending_enabled(true);

    // bn::array<bn::blending_transparency_attributes, 160> dots_tattr;
    // bn::optional<bn::blending_transparency_attributes_hbe_ptr> transparency_attributes_hbe;

    unsigned char frame_skip = 0;
    unsigned char frame = 0;
    while (dots_offset > 0) {
        if (frame > frame_skip) {
            frame = 0;
        }

        if (frame == 0) {
            dots_offset -= 16;
            secondary_background->set_position(0, -80 + 128 + dots_offset);
            for(int index = 0, amplitude = 160; index < amplitude; ++index)
            {
                // bn::fixed
                bn::fixed clamped_alpha = bn::min(bn::max((index + 32 - dots_offset) / (32), bn::fixed(0)), bn::fixed(1));
                bn::fixed transparency_alpha = (bn::fixed(1) - clamped_alpha) * bn::fixed(0.5);
                transparency_attributes[index].set_transparency_alpha(transparency_alpha);
            }
        }


        transparency_attributes_hbe = bn::blending_transparency_attributes_hbe_ptr::create_optional(transparency_attributes);
        // bn::blending_transparency_attributes_hbe_ptr::create(dots_tattr);
        ks::globals::main_update();
        frame++;
    }
    transparency_attributes_hbe.reset();
    secondary_background.reset();


    for (auto& character_visual : character_visuals) {
        if (!character_visual.bg_item.has_value()) continue;
        if (!character_visual.sprite_item.has_value()) continue;
        if (!character_visual.sprite_meta.has_value()) continue;
        BN_LOG("Restoring char ", character_visual.index);

        SceneManager::show_character(
            character_visual.index,
            character_visual.bg_item.value(),
            character_visual.sprite_item.value(),
            character_visual.sprite_meta.value(),
            character_visual.position_x,
            character_visual.position_y,
            false,
            true);
    }

    // Enable blending for characters
    for (auto& char_visual : character_visuals) {
        if (char_visual.background.has_value() && char_visual.sprite.has_value()) {
            char_visual.will_show = true;
        //     char_visual.background->set_blending_enabled(true);
        //     char_visual.sprite->set_blending_enabled(true);
        }
    }

    update_visuals();
}

void SceneManager::exit_scenario_from_ingame_menu() {
    static_text_sprites->clear();
    animated_text_sprites->clear();
    secondary_background.reset();
    tertiary_background.reset();

    const bn::color BLACK = bn::color(0, 0, 0);
    for(int alpha = 16; alpha <= 32; ++alpha) {
        bn::bg_palettes::set_fade(BLACK, bn::fixed(alpha) / 32);
        bn::sprite_palettes::set_fade(BLACK, bn::fixed(alpha) / 32);
        ks::globals::main_update();
    }

    free_resources();
    if (text_db) {
        bn::memory::ewram_free(text_db);
    }
}

void SceneManager::pause(const int ticks) {
    for(int tick = 0; tick <= ticks; ++tick) {
        ks::globals::main_update();
    }
}

void SceneManager::fade_in(const bn::color &color, const int steps) {
    bn::bg_palettes::set_fade(color, bn::fixed(1));
    bn::sprite_palettes::set_fade(color, bn::fixed(1));
    for(int alpha = steps; alpha > 0; --alpha) {

        bn::bg_palettes::set_fade(color, bn::fixed(alpha) / steps);
        bn::sprite_palettes::set_fade(color, bn::fixed(alpha) / steps);
        ks::globals::main_update();
    }
}

void SceneManager::fade_out(const bn::color &color, const int steps) {
    for(int alpha = 0; alpha <= steps; ++alpha) {
        bn::bg_palettes::set_fade(color, bn::fixed(alpha) / steps);
        bn::sprite_palettes::set_fade(color, bn::fixed(alpha) / steps);
        ks::globals::main_update();
    }
}

void SceneManager::fade_in(const bn::color &color) {
    fade_in(color, 32);
}

void SceneManager::fade_out(const bn::color &color) {
    fade_out(color, 32);
}

void SceneManager::fade_reset() {
    bn::bg_palettes::set_fade_intensity(bn::fixed(0));
    bn::sprite_palettes::set_fade_intensity(bn::fixed(0));
}

} // namespace ks
