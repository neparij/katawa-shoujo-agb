#include "scenemanager.h"
#include "bn_bg_palettes.h"
#include "bn_format.h"
#include "bn_sprite_palettes.h"
#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_item.h"
#include "bn_sprite_actions.h"
#include "bn_blending_actions.h"
#include "globals.h"
#include "gsmplayer/player.h"
#include "translation.h"
#include "utils/scenario_reader.h"
#include <BN_LOG.h>


namespace ks {

bn::optional<ks::SceneManager> scene;
bn::sprite_text_generator* text_generator;
ks::DialogBox* dialog;
bn::optional<bn::regular_bg_ptr> main_background;
bn::optional<bn::regular_bg_ptr> secondary_background;
bn::vector<character_visuals_ptr, 8> character_visuals;
bn::vector<unsigned char, 5> answers_index_map;
ks::saves::SaveSlotProgressData progress;
bool in_replay = false;

bn::vector<bn::sprite_ptr, 64>* static_text_sprites;
bn::vector<bn::sprite_ptr, 128>* animated_text_sprites;

bn::string<16> SceneManager::_cached_actor;
int SceneManager::_cached_tl_key = -1;

void SceneManager::free_resources() {
    while (character_visuals.size() < character_visuals.max_size()) {
        character_visuals.push_back(character_visuals_ptr());
    }
    for (auto &visual : character_visuals) {
        visual.background.reset();
        visual.sprite.reset();
    }
}

void SceneManager::set(const ks::SceneManager instance) {
    scene.reset();
    scene = instance;
}

void SceneManager::set_background(const bn::regular_bg_item& bg) {
    // TODO: rewrite to support "scene" token
    // temporaly hide chars
    for (int i = 0; i < character_visuals.size(); i++) {
        hide_character(i, false);
    }

    main_background.reset();
    main_background = bg.create_bg(0, 0);
    main_background->set_z_order(10);

    ks::globals::main_update();
}

void SceneManager::show_dialog(bn::string<16> actor, int tl_key) {
    _cached_actor = actor;
    _cached_tl_key = tl_key;

    while (!ks::globals::exit_scenario) {
        // TODO: Use ref to message. All the way. Reduce the mem usage.
        bn::string<1024> message = ks::scenario::gbfs_reader::get_tl<1024>(scene->scenario(), scene->locale(), scene->_script_tl_index[tl_key]);
        ks::globals::main_update();
        dialog->show(actor, message);
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
            // ATTENTION! Used reduced-size message due to limits. Need to be tested as well.
            bn::string<512> message = ks::scenario::gbfs_reader::get_tl<512>(scene->scenario(), scene->locale(), scene->_script_tl_index[_cached_tl_key]);
            dialog->show(_cached_actor, message);

            while (!dialog->is_finished() && !bn::keypad::start_pressed()) {
                dialog->update();
                ks::globals::main_update();
            }
        }

        // Phase 2: Display the question dialog
        answers_index_map.clear();
        bn::vector<bn::string<128>, 5> answers_messages;

        for (int i = 0; i < answers.size(); i++) {
            auto message = ks::scenario::gbfs_reader::get_tl<128>(
                scene->scenario(), scene->locale(), scene->_script_tl_index[answers.at(i).tl_key]);
            answers_messages.push_back(message);
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
        if (!was_shown_before) {
            dialog->hide_blend();
        }
    }

    character_visuals.at(character_index).background.reset();
    character_visuals.at(character_index).background = character_visuals.at(character_index).bg_item->create_bg(character_visuals.at(character_index).position_x,
                                                                    character_visuals.at(character_index).position_y);
    character_visuals.at(character_index).background->set_z_order(0);

    character_visuals.at(character_index).sprite.reset();
    character_visuals.at(character_index).sprite = character_visuals.at(character_index).sprite_item->create_sprite(character_visuals.at(character_index).position_x + sprite_meta.offset_x,
                                                                        character_visuals.at(character_index).position_y + sprite_meta.offset_y);
    character_visuals.at(character_index).offset_x = sprite_meta.offset_x;
    character_visuals.at(character_index).offset_y = sprite_meta.offset_y;
    character_visuals.at(character_index).sprite->set_z_order(-5);

    if (!restoring) {
        if (!was_shown_before) {
            bn::blending::set_transparency_alpha(0);
            auto spr_alpha_action = bn::blending_transparency_alpha_to_action(20, 1);
            character_visuals.at(character_index).sprite->set_blending_enabled(true);
            character_visuals.at(character_index).background->set_blending_enabled(true);
            while (!spr_alpha_action.done()) {
                spr_alpha_action.update();

                ks::globals::main_update();
            }
            character_visuals.at(character_index).sprite->set_blending_enabled(false);
            character_visuals.at(character_index).background->set_blending_enabled(false);
        }

        ks::globals::main_update();

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

    auto bg_move_action = bn::regular_bg_move_to_action(character_visuals.at(character_index).background.value(),
                                                                                      20,
                                                                                      position_x,
                                                                                      position_y);
    auto spr_move_action = bn::sprite_move_to_action(character_visuals.at(character_index).sprite.value(),
                                                                                      20,
                                                                                      position_x + character_visuals.at(character_index).offset_x,
                                                                                      position_y + character_visuals.at(character_index).offset_y);

    while (!bg_move_action.done() &&
           !spr_move_action.done()) {
        bg_move_action.update();
        spr_move_action.update();
        ks::globals::main_update();
    }
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

void SceneManager::music_play(const char* filename) {
    music_play(filename, 0);
}

void SceneManager::music_play(const char* filename, bn::fixed fade) {
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

void SceneManager::open_ingame_menu() {
    const int TRANSITION_STEPS = 16;
    constexpr bn::color BLACK = bn::color(0, 0, 0);

    bn::bg_palettes::set_fade_color(BLACK);
    bn::sprite_palettes::set_fade_color(BLACK);

    // Enable blending for characters
    for (auto& char_visual : character_visuals) {
        if (char_visual.background.has_value() && char_visual.sprite.has_value()) {
            char_visual.background->set_blending_enabled(true);
            char_visual.sprite->set_blending_enabled(true);
        }
    }
    // First of all — blend palettes to half-BLACK
    for(int alpha = 0; alpha <= TRANSITION_STEPS; ++alpha) {
        bn::bg_palettes::set_fade_intensity(bn::fixed(alpha) / (TRANSITION_STEPS * 2));
        bn::sprite_palettes::set_fade_intensity(bn::fixed(alpha) / (TRANSITION_STEPS * 2));

        // Among with blending palettes dissolve characters via blending
        bn::blending::set_transparency_alpha(bn::fixed(TRANSITION_STEPS - alpha) / TRANSITION_STEPS);
        ks::globals::main_update();
    }

    // Hide all characters
    for (auto& char_visual : character_visuals) {
        char_visual.background.reset();
        char_visual.sprite.reset();
    }

    // Disable palette fading, as then we need to display other gfx as normal
    bn::bg_palettes::set_fade_intensity(0);
    bn::sprite_palettes::set_fade_intensity(0);

    // Disable the transparency BLENDING!
    bn::blending::set_transparency_alpha(1);

    // Enable the fade BLENDING!
    bn::blending::set_fade_alpha(0.5);
    main_background->set_blending_enabled(true);
    ks::globals::main_update();


    // TEMP
    secondary_background = bn::regular_bg_items::ui_ingame_menu_background_0.create_bg(0, 0);

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
    selection_index.resize(static_text_sprites->size(), -1);

    // ks::text_generator->set_palette_item(beige_selected_palette_item);
    ks::text_generator->generate(0, -48, ks::globals::i18n->screens_return(), *static_text_sprites);
    selection_index.resize(static_text_sprites->size(), 0);
    // ks::text_generator->set_palette_item(beige_palette_item);
    ks::text_generator->generate(0, -32, ks::globals::i18n->screens_history(), *static_text_sprites);
    selection_index.resize(static_text_sprites->size(), 1);
    ks::text_generator->generate(0, -16, ks::globals::i18n->screens_options(), *static_text_sprites);
    selection_index.resize(static_text_sprites->size(), 2);
    ks::text_generator->generate(0, 0, ks::globals::i18n->screens_save_game(), *static_text_sprites);
    selection_index.resize(static_text_sprites->size(), 3);
    ks::text_generator->generate(0, 16, ks::globals::i18n->screens_load_game(), *static_text_sprites);
    selection_index.resize(static_text_sprites->size(), 4);
    ks::text_generator->generate(0, 32, ks::globals::i18n->screens_main_menu(), *static_text_sprites);
    selection_index.resize(static_text_sprites->size(), 5);

    ks::text_generator->set_palette_item(original_palette_item);
    ks::text_generator->generate(0, ks::device::screen_height_half - 8 - 12, bn::format<64>("{}: {}", ks::globals::i18n->screens_current_scene(), ks::globals::i18n->definitions_no_scene()), *static_text_sprites);
    ks::text_generator->generate(0, ks::device::screen_height_half - 8, bn::format<64>("{}: {}", ks::globals::i18n->screens_current_track(), ks::globals::i18n->definitions_nothing()), *static_text_sprites);
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
                }
                break;
            }
        }
    }

    // TODO: backwards processing.
    bn::blending::set_fade_alpha(0);
    main_background->set_blending_enabled(false);

    if (!ks::globals::exit_scenario) {
        SceneManager::close_ingame_menu();
    } else {
        SceneManager::exit_scenario_from_ingame_menu();
    }
}

void SceneManager::close_ingame_menu() {
    static_text_sprites->clear();
    animated_text_sprites->clear();
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

    const bn::color BLACK = bn::color(0, 0, 0);
    for(int alpha = 16; alpha >= 0; --alpha) {
        bn::bg_palettes::set_fade(BLACK, bn::fixed(alpha) / 32);
        bn::sprite_palettes::set_fade(BLACK, bn::fixed(alpha) / 32);
        ks::globals::main_update();
    }
}

void SceneManager::exit_scenario_from_ingame_menu() {
    static_text_sprites->clear();
    animated_text_sprites->clear();
    secondary_background.reset();

    const bn::color BLACK = bn::color(0, 0, 0);
    for(int alpha = 16; alpha <= 32; ++alpha) {
        bn::bg_palettes::set_fade(BLACK, bn::fixed(alpha) / 32);
        bn::sprite_palettes::set_fade(BLACK, bn::fixed(alpha) / 32);
        ks::globals::main_update();
    }
}

} // namespace ks
