#include "scenemanager.h"

#include <bn_regular_bg_items_kslogo_heart.h>
#include <bn_regular_bg_items_kslogo_words.h>
#include <bn_affine_bg_actions.h>
#include <bn_affine_bg_items_test_delayblinds.h>
#include <bn_affine_bg_items_test_eyes.h>
#include <bn_affine_bg_items_test_flashback.h>
#include <bn_affine_bg_items_test_handsdissolve.h>
#include <bn_affine_bg_items_test_dots_col.h>
#include <bn_affine_bg_items_test_clockwipe.h>
#include <bn_affine_bg_tiles_ptr.h>
#include <bn_bg_palette_ptr.h>
#include <BN_LOG.h>

#include "bn_bg_palettes.h"
#include "bn_blending_actions.h"
#include "bn_blending_transparency_attributes.h"
#include "bn_blending_transparency_attributes_hbe_ptr.h"
#include "bn_core.h"
#include "bn_format.h"
#include "bn_memory.h"
#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_item.h"
#include "bn_regular_bg_items_ui_backdrop_dots.h"
#include "bn_regular_bg_items_scene_black.h"
#include "bn_sprite_actions.h"
// #include "bn_sprite_items_ui_ingame_menu_ne.h"
// #include "bn_sprite_items_ui_ingame_menu_nw.h"
// #include "bn_sprite_items_ui_ingame_menu_se.h"
// #include "bn_sprite_items_ui_ingame_menu_sw.h"
#include "bn_sprite_palettes.h"
#include "globals.h"
#include "ingametimer.h"
#include "sound_manager.h"
#include "translations/translation.h"
#include <video_4ls_dxtv.h>
#include <video_op_1_dxtv.h>
#include "../../butano/butano/src/bn_bgs_manager.h"
#include "savefile/save_file.h"
#include "shaders/vram_dma_shader.h"
#include "utils/lz77.h"
#include "utils/scenario_reader.h"
#include "videoplayer/video_player.h"

#include "menu/menu_ingame_pause.cpp.h"
#include "menu/menu_saves.cpp.h"
#include "sound/sound_mixer.h"

namespace ks {

u8* text_db;
u32 text_db_size;
bool text_db_allocated;
EWRAM_BSS bn::string<1024> message;
EWRAM_BSS bn::vector<bn::string<128>, 5> answers_messages;

bn::optional<ks::SceneManager> scene;
bn::optional<bn::sprite_text_generator> text_generator;
bn::optional<bn::sprite_text_generator> text_generator_bold;
bn::optional<bn::sprite_text_generator> text_generator_small;
ks::DialogBox* dialog;
bn::optional<bn::regular_bg_ptr> primary_background;
bn::optional<bn::regular_bg_ptr> secondary_background;
bn::optional<bn::affine_bg_ptr> transition_bg;
bn::optional<bn::color> fill_color;

bn::optional<bn::unique_ptr<CustomEvent>> custom_event;
bn::vector<character_visuals_ptr, 4> character_visuals;
bn::vector<character_restoration_data, 4> character_restoration;
background_visuals_ptr background_visual;

bn::rect_window left_window = bn::rect_window::external();
bn::rect_window right_window = bn::rect_window::internal();

bn::vector<unsigned char, 5> answers_index_map;
ks::saves::SaveSlotProgressData progress;
ks::saves::SaveSlotProgressData savedata_progress;
bool in_game = false;
bool in_replay = false;
bool is_loading = false;
bool is_paused = false;
unsigned char savedata_answer_index = 0;

EWRAM_BSS bn::vector<bn::sprite_ptr, 18> progress_icon_sprites;
EWRAM_BSS bn::vector<bn::sprite_ptr, 64> static_text_sprites;
EWRAM_BSS bn::vector<bn::sprite_ptr, 128> animated_text_sprites;

void SceneManager::free_resources() {
    BN_LOG("Free resources...");
    background_visual.bg_item.reset();
    primary_background.reset();
    secondary_background.reset();
    custom_event.reset();

    for (auto &visual : character_visuals) {
        visual.background.reset();
        visual.sprite.reset();
        visual.bg_item.reset();
        visual.sprite_item.reset();
        visual.visible_bg_item.reset();
        visual.visible_sprite_item.reset();
    }
    character_visuals.clear();

    if (text_db_allocated) {
        BN_LOG("Free text database...");
        bn::memory::ewram_free(text_db);
        text_db_allocated = false;
    }
}

void SceneManager::set(const ks::SceneManager instance) {
    free_resources();
    while (character_visuals.size() < character_visuals.max_size()) {
        character_visuals.push_back(character_visuals_ptr());
    }

    BN_LOG("RESET SCENE");
    scene.reset();
    BN_LOG("Set SM Instance");
    scene = instance;
    u32 src_len = 0;

    BN_LOG("Read Scene File...");
    const auto filename = bn::string<32>(scene->scenario()).append(".").append(scene->locale()).c_str();
    const u8 *compressed_data = (u8 *) gbfs_get_obj(fs, filename, &src_len);

    text_db_size = (compressed_data[1]) | (compressed_data[2] << 8) | (compressed_data[3] << 16);

    BN_LOG("EWRAM free: ", bn::memory::available_alloc_ewram());
    BN_LOG("Allocate ", text_db_size, " bytes for text database...");
    BN_ASSERT(!text_db_allocated, "Text database already allocated!");
    text_db = static_cast<u8 *>(bn::memory::ewram_alloc(static_cast<int>(text_db_size)));
    text_db_allocated = true;

    BN_LOG("Decompress Scene file...");
    LZ77UnCompWRAM((u32)compressed_data, (u32)text_db);
    BN_LOG("EWRAM after allocation: ", bn::memory::available_alloc_ewram());

    BN_LOG("Set Window boundaries");
    left_window.set_boundaries(-80,-120,80,0);
    right_window.set_boundaries(-80,0,80,120);
    BN_LOG("SceneManager init done!");
}

void SceneManager::init_savedata(ks::saves::SaveSlotProgressData &value) {
    if (!is_loading) {
        value.reproduction.answer_indices.fill(0);
        value.reproduction.line_hash = 0;
    }
    savedata_progress = value;
    savedata_answer_index = 0;
}

void SceneManager::set_script(const script_t script) {
    progress.metadata.script = script;
}

void SceneManager::set_label(const label_t label) {
    progress.metadata.label = label;
}

void SceneManager::set_line_hash(const unsigned int line_hash) {
    if (is_loading) {
        if (savedata_progress.reproduction.line_hash == line_hash || savedata_progress.reproduction.line_hash == 0) {
            is_loading = false;
            ks::sound_manager::restore_after_loading();
            sound_manager::update();
            sound_mixer::unmute();
            update_visuals();
        }
    }
    BN_LOG("Set line hash: ", line_hash);
    progress.reproduction.line_hash = line_hash;
}

void SceneManager::autosave() {
    if (is_loading) {
        return;
    }
    prepare_save_metadata();
    savedata_progress.metadata = progress.metadata;
    savedata_progress.reproduction = progress.reproduction;
    BN_LOG("Savedata progress linehash: ", savedata_progress.reproduction.line_hash);
    BN_LOG("Savedata progress answers count: ", savedata_progress.reproduction.answer_indices.size());
    ks::saves::writeAutosave(savedata_progress);
}

void SceneManager::save(unsigned short slot_index) {
    prepare_save_metadata();
    savedata_progress.metadata = progress.metadata;
    savedata_progress.reproduction = progress.reproduction;
    BN_LOG("Savedata progress linehash: ", savedata_progress.reproduction.line_hash);
    BN_LOG("Savedata progress answers count: ", savedata_progress.reproduction.answer_indices.size());
    ks::saves::writeSaveSlot(slot_index, savedata_progress);
}

void SceneManager::prepare_save_metadata() {
    // BN_LOG("Prepare save metadata");
    // for (auto & thumbnail_character : progress.metadata.thumbnail_characters) {
    //     thumbnail_character.thumbnail_hash = 0;
    //     thumbnail_character.offset_x = 0;
    // }
    //
    // int char_counter = 0;
    // for (auto& visual : character_visuals) {
    //     BN_LOG("Check visual");
    //     BN_LOG("Has sprite_meta: ", visual.sprite_meta.has_value());
    //     BN_LOG("Has background: ", visual.background.has_value());
    //     BN_LOG("Background is visible: ", visual.background.has_value() && visual.background.value().visible());
    //     if (char_counter >= 4) {
    //         break;
    //     }
    //     char_counter++;
    //     if (visual.sprite_meta.has_value() && visual.background.has_value() && visual.background.value().visible()) {
    //         BN_LOG("Add character thumbnail hash: ", visual.sprite_meta->hash);
    //         progress.metadata.thumbnail_characters[visual.index].thumbnail_hash = visual.sprite_meta->hash;
    //         progress.metadata.thumbnail_characters[visual.index].offset_x = visual.offset_x;
    //     }
    // }
}


void SceneManager::set_background(const background_meta& bg, const int position_x, const int position_y, const scene_transition_t transition, const int dissolve_time) {
    custom_event.reset();
    disable_fill();
    progress.metadata.thumbnail_hash = bg.hash;
    background_visual.bg_item = bg.bg;
    background_visual.position_x = position_x;
    background_visual.position_y = position_y;
    background_visual.dissolve_time = dissolve_time;
    set_background_transition(transition);


    if (dissolve_time != 0 || transition != SCENE_TRANSITION_NONE) {
        // TODO: Check that we need to hide characters only on dissolves!
        for (const auto& visual : character_visuals) {
            if (visual.character != CHARACTER_NONE) {
                hide_character(visual.character, false, true);
            }
        }
    }
}

void SceneManager::hide_background(const scene_transition_t transition, const int dissolve_time) {
    background_visual.bg_item.reset();
    background_visual.transition = transition;
    background_visual.dissolve_time = dissolve_time;
}

void SceneManager::set_background_position(const int position_x, const int position_y) {
    background_visual.position_x = position_x;
    background_visual.position_y = position_y;
}

void SceneManager::set_background_transition(const scene_transition_t transition) {
    if (is_loading) {
        return;
    }
    if (transition == SCENE_TRANSITION_PASSOUTOP1) {
        hide_background(transition, 0);
        return;
    }
    if (transition == SCENE_TRANSITION_LOCATIONCHANGE) {
        background_visual.transition = SCENE_TRANSITION_NONE;
        background_visual.dissolve_time = 60;
        return;
    }
    if (transition == SCENE_TRANSITION_LOCATIONSKIP) {
        background_visual.dissolve_time = 30;
        background_visual.transition = SCENE_TRANSITION_NONE;
        return;
    }
    BN_LOG("SET BG TRANSITION [", transition, "]");
    background_visual.transition = transition;
}

void SceneManager::enable_fill(const bn::color color) {
    background_visual.fill_color = color;
}

void SceneManager::disable_fill() {
    background_visual.fill_color.reset();
}


void SceneManager::set_event(const background_meta& bg, const CustomEvent& event, const scene_transition_t transition, const int dissolve_time) {
    set_background(bg, 0, 0, transition, dissolve_time);
    for (const auto& visual : character_visuals) {
        if (visual.character != CHARACTER_NONE) {
            hide_character(visual.character, false, true);
        }
    }
    custom_event = event.clone();
}

void SceneManager::show_dialog(const character_definition& actor, int tl_key) {
    if (is_loading) {
        return;
    }

    while (!ks::globals::exit_scenario) {
        switch (globals::state) {
            case GS_GAME:
                BN_LOG("TextDB pointer in global scope:", (u32)text_db);
                ks::scenario::gbfs_reader::get_tl<1024>(text_db, text_db_size, scene->_script_tl_index[tl_key], message);
                ks::globals::sound_update();

                dialog->show(actor, message);
                while (!dialog->is_finished() && !bn::keypad::start_pressed()) {
                    dialog->update();
                    ks::globals::main_update();
                }
                if (bn::keypad::start_pressed()) {
                    globals::state = GS_GAME_MENU;
                    is_paused = true;
                    update_visuals();
                }
                break;
            case GS_GAME_MENU:
                // SceneManager::open_ingame_menu();
                ks::MenuIngamePause().run();
                break;
            case GS_GAME_MENU_SAVES:
                ks::MenuSaves().run();
                break;
            default:
                BN_ERROR("Wrong state: ", ks::globals::state);
        }
        if (dialog->is_finished())
            break;
    }
}

void SceneManager::show_dialog(const char* actor_name, int tl_key) {
    if (is_loading) {
        return;
    }
    const ks::character_definition current = ks::definitions::base.with_name(actor_name);
    return show_dialog(current, tl_key);
}

void BN_CODE_EWRAM SceneManager::show_dialog_question(bn::vector<ks::answer_ptr, 5> answers) {
    if (is_loading) {
        return;
    }

    bool redisplay_dialog = false;  // Prevents re-showing dialog unnecessarily

    while (!ks::globals::exit_scenario) {
        switch (globals::state) {
            case GS_GAME:
                if (redisplay_dialog) {
                    dialog->restore_from_pause();
                    while (!dialog->is_finished() && !bn::keypad::start_pressed()) {
                        dialog->update();
                        globals::main_update();
                    }
                }
                // Phase 2: Display the question dialog
                answers_index_map.clear();
                answers_messages.clear();

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
                    dialog->reset_question();
                    redisplay_dialog = true;
                    globals::state = GS_GAME_MENU;
                    is_paused = true;
                    update_visuals();
                }
                break;
            case GS_GAME_MENU:
                ks::MenuIngamePause().run();
            break;
            case GS_GAME_MENU_SAVES:
                ks::MenuSaves().run();
            break;
            default:
                BN_ERROR("Wrong state: ", ks::globals::state);
        }
        if (dialog->is_finished())
            break;
    }
}

int SceneManager::get_dialog_question_answer() {
    if (is_loading) {
        return savedata_progress.reproduction.answer_indices.at(savedata_answer_index++);
    }
    const unsigned char answer = answers_index_map.at(dialog->get_answer_index());
    progress.reproduction.answer_indices[savedata_answer_index++] = answer;
    return answer;
}

void SceneManager::show_character(const character_t character,
                                  const ks::character_sprite_meta& sprite_meta,
                                  const bn::regular_bg_item& bg,
                                  const bn::sprite_item& sprite,
                                  const int position_x,
                                  const int position_y,
                                  const bool position_change) {
    BN_LOG("Show character: ", character, " X: ", position_x, " Y: ", position_y);;
    const auto character_index = get_character_visual_index(character, true);

    character_visuals.at(character_index).index = character_index;
    character_visuals.at(character_index).character = character;
    character_visuals.at(character_index).bg_item = bg;
    character_visuals.at(character_index).sprite_item = sprite;
    character_visuals.at(character_index).sprite_meta = sprite_meta;
    if (position_change) {
        character_visuals.at(character_index).position_x = position_x;
        character_visuals.at(character_index).position_y = position_y;
    }

    progress.metadata.thumbnail_characters[character_index].thumbnail_hash = sprite_meta.hash;
    progress.metadata.thumbnail_characters[character_index].offset_x = static_cast<short>(character_visuals.at(character_index).position_x / 5);
}

void SceneManager::show_character(const character_t character,
                                  const ks::character_sprite_meta& sprite_meta,
                                  const bn::regular_bg_item& bg,
                                  const bn::sprite_item& sprite,
                                  const int position_x,
                                  const int position_y) {
    show_character(character, sprite_meta, bg, sprite, position_x, position_y, true);
}

void SceneManager::show_character(const character_t character,
                                  const ks::character_sprite_meta& sprite_meta,
                                  const bn::regular_bg_item& bg,
                                  const bn::sprite_item& sprite) {
    show_character(character, sprite_meta, bg, sprite, 0, 0, false);
}

void SceneManager::set_character_position(const character_t character,
                                          const int position_x,
                                          const int position_y) {
    BN_LOG("Set character position: ", character, " X: ", position_x, " Y: ", position_y);
    const auto character_index = get_character_visual_index(character, false);

    character_visuals.at(character_index).position_x = position_x;
    character_visuals.at(character_index).position_y = position_y;

    progress.metadata.thumbnail_characters[character_index].offset_x = static_cast<short>(character_visuals.at(character_index).position_x / 5);
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

    // Too offscreen
    if (x_pos < -ks::device::screen_width_half - 64 || x_pos > ks::device::screen_width_half + 64) {
        is_left = false;
        is_right = false;
    }

    bg.set_visible_in_window(is_left, left_window);
    bg.set_visible_in_window(is_right, right_window);
}

void SceneManager::hide_character(const character_t character, const bool need_update, const bool remove) {
    BN_LOG("Hide character : ", character);
    const auto character_index = get_character_visual_index(character, false);

    if (remove) {
        progress.metadata.thumbnail_characters[character_index].thumbnail_hash = 0;
        progress.metadata.thumbnail_characters[character_index].offset_x = 0;
    }

    character_visuals.at(character_index).character = CHARACTER_NONE;
    character_visuals.at(character_index).bg_item.reset();
    character_visuals.at(character_index).sprite_item.reset();
    character_visuals.at(character_index).sprite_meta.reset();
    if (need_update && !is_loading) {
        ks::globals::main_update();
    }
}

void SceneManager::hide_character(const character_t character) {
    hide_character(character, true, true);
}

void SceneManager::perform_transition(const scene_transition_t transition, const bn::optional<bn::regular_bg_item>& to) {
    globals::sound_update();
    bn::blending::set_transparency_alpha(1.0);
    // while (!bn::keypad::start_pressed()) {
    //     bn::core::update();
    // }
    if (transition == SCENE_TRANSITION_PASSOUTOP1) {
        transition_fadeout(bn::affine_bg_items::test_flashback, 1,  false);
        return;
    }
    if (transition == SCENE_TRANSITION_SHUTEYE) {
        transition_fadeout(bn::affine_bg_items::test_eyes, 2,  false);
        // background_visual.bg_item.reset();
        primary_background.reset();
        return;
    }
    if (transition == SCENE_TRANSITION_OPENEYE) {
        if (to.has_value()) {
            BN_LOG("TO: HAS VALUE");
            primary_background.reset();
            ks::globals::main_update();
            primary_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            primary_background->set_priority(3);
            primary_background->set_z_order(10);
            if (custom_event.has_value()) {
                (*custom_event)->init();
            }
            ks::globals::sound_update();
        }
        transition_fadein(bn::affine_bg_items::test_eyes, 2,  false);
        return;
    }
    if (transition == SCENE_TRANSITION_HANDS_IN) {
        transition_fadeout(bn::affine_bg_items::test_handsdissolve, 16,  false);
        // background_visual.bg_item.reset();
        primary_background.reset();
        return;
    }
    if (transition == SCENE_TRANSITION_HANDS_OUT) {
        if (to.has_value()) {
            BN_LOG("TO: HAS VALUE");
            primary_background.reset();
            ks::globals::main_update();
            primary_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            primary_background->set_priority(3);
            primary_background->set_z_order(10);
            if (custom_event.has_value()) {
                (*custom_event)->init();
            }
            ks::globals::sound_update();
        }
        transition_fadein(bn::affine_bg_items::test_handsdissolve, 8,  false);
        return;
    }
    if (transition == SCENE_TRANSITION_SHORTTIMESKIP || transition == SCENE_TRANSITION_SHORTTIMESKIPSILENT) {
        // TODO: Check how the original works
        // if (transition == SCENE_TRANSITION_SHORTTIMESKIP) {
        //     sfx_play("sfx_time.8ad", SOUND_CHANNEL_SOUND);
        // }
        transition_fadeout(bn::affine_bg_items::test_delayblinds, 4, true);
        if (to.has_value()) {
            BN_LOG("TO: HAS VALUE");
            primary_background.reset();
            ks::globals::main_update();
            primary_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            primary_background->set_priority(3);
            primary_background->set_z_order(10);
            if (custom_event.has_value()) {
                (*custom_event)->init();
            }
            ks::globals::sound_update();
        }
        transition_fadein(bn::affine_bg_items::test_delayblinds, 4, false);
        return;
    }
    if (transition == SCENE_TRANSITION_FLASH || transition == SCENE_TRANSITION_SILENTFLASH) {
        // TODO: Check how the original works (KS:RE doesn't play any sound here)
        // if (transition == SCENE_TRANSITION_FLASH) {
        //     sfx_play("sfx_flash.8ad", SOUND_CHANNEL_SOUND);
        // }
        fade_out(ks::globals::colors::WHITE, 15);
        if (to.has_value()) {
            primary_background.reset();
            ks::globals::main_update();
            primary_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            primary_background->set_priority(3);
            primary_background->set_z_order(10);
            if (custom_event.has_value()) {
                (*custom_event)->init();
            }
            ks::globals::sound_update();
        }
        fade_in(ks::globals::colors::WHITE, 45);
        fade_reset();
        return;
    }
    if (transition == SCENE_TRANSITION_SHOWDOWN_THUNDER_LONG || transition == SCENE_TRANSITION_SHOWDOWN_THUNDER_SHORT) {
        fade_out(ks::globals::colors::WHITE, 15);
        if (to.has_value()) {
            primary_background.reset();
            ks::globals::main_update();
            primary_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            primary_background->set_priority(3);
            primary_background->set_z_order(10);
            if (custom_event.has_value()) {
                (*custom_event)->init();
            }
            ks::globals::sound_update();
        }
        fade_in(ks::globals::colors::WHITE, transition == SCENE_TRANSITION_SHOWDOWN_THUNDER_LONG ? 180 : 90);
        fade_reset();
        return;
    }
    if (transition == SCENE_TRANSITION_CLOCKWIPE_IN) {
        BN_ASSERT(!to.has_value(), "Clockwipe transition MUST have a value");
        primary_background.reset();
        ks::globals::main_update();
        primary_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
        primary_background->set_priority(3);
        primary_background->set_z_order(10);
        ks::globals::sound_update();
        transition_fadein(bn::affine_bg_items::test_clockwipe, 2, false);
        return;
    }
    if (transition == SCENE_TRANSITION_CLOCKWIPE_OUT) {
        transition_fadeout(bn::affine_bg_items::test_clockwipe, 2, true);
        primary_background.reset();
        return;

    }
    BN_ERROR("Transition not implemented: ", transition);
}

void SceneManager::perform_transition(const scene_transition_t transition) {
    perform_transition(transition, bn::nullopt);
}

void SceneManager::update() {
    if (custom_event.has_value() && (*custom_event)->is_initialized()) {
        (*custom_event)->update();
    }
}

void SceneManager::update_transitions() {
    if (custom_event.has_value()) {
        (*custom_event)->update();
    }
    ks::globals::main_update();
}


void SceneManager::update_visuals() {
    if (is_loading) {
        return;
    }

    BN_LOG("Update visuals process started");

    if (background_visual.fill_color.has_value()) {
        fill_color = background_visual.fill_color;
    } else {
        fill_color.reset();
    }


    // TODO: Example of palette changes!!!!
    // // auto palette = primary_background->palette()
    // if (primary_background.has_value()) {
    //     auto new_pal = bn::bg_palette_ptr::create(background_visual.visible_bg_item->palette_item());
    //     new_pal.set_fade(globals::colors::RED, 0.5);
    //     primary_background->set_palette(new_pal);
    // }

    bn::vector<bn::regular_bg_move_to_action, 5> bg_moves;
    bn::vector<bn::sprite_move_to_action, 4> spr_moves;
    bn::optional<bn::blending_transparency_alpha_to_action> blend_action;
    bool in_progress = false;

    /// COLLECT INFO
    if (!primary_background.has_value()) {
        background_visual.visible_bg_item.reset();
    }

    bool is_scene_visible = !fill_color.has_value();
    BN_LOG("Is scene visible: ", is_scene_visible);
    BN_LOG("Is paused: ", is_paused);

    bool background_want_change = background_visual.visible_bg_item.has_value() && background_visual.bg_item.has_value() &&
                                  background_visual.visible_bg_item != background_visual.bg_item && is_scene_visible;
    bool background_want_hide = background_visual.visible_bg_item.has_value() && (!background_visual.bg_item.has_value() || !is_scene_visible);
    bool background_want_show = !background_visual.visible_bg_item.has_value() && background_visual.bg_item.has_value() && is_scene_visible;
    bool background_want_transition = background_visual.transition != SCENE_TRANSITION_NONE;
    bool background_want_dissolve = background_visual.dissolve_time != 0 && (background_want_change || background_want_hide || background_want_show) && !background_want_transition;
    bool background_want_move = !background_want_change && !background_want_hide && !background_want_show && !custom_event.has_value() &&
                                background_visual.visible_bg_item.has_value() &&
                                (background_visual.position_x != primary_background->position().x() ||
                                background_visual.position_y != primary_background->position().y());
    bool custom_event_want_init = custom_event.has_value() && !(*custom_event)->is_initialized();
    BN_LOG("CUSTOM EVENT WANT INIT: ", custom_event_want_init);

    bool characters_want_show = false;
    bool characters_want_hide = false;
    for (auto &visual : character_visuals) {
        bool character_want_show = !visual.visible_bg_item.has_value() && (visual.bg_item.has_value() && is_scene_visible && !is_paused);
        bool character_want_hide = visual.visible_bg_item.has_value() && (!visual.bg_item.has_value() || !is_scene_visible || is_paused || background_want_transition);

        visual.will_show = character_want_show;
        visual.will_hide = character_want_hide;

        // if (visual.background.has_value() && (background_want_change || background_want_hide || background_want_show)) {
        //     visual.will_hide = true;
        //     BN_LOG("Will hide character ", visual.character, ". Reason: ", "visual.background.has_value() && background_want_transition");
        // }
        //
        // if (visual.background.has_value() && background_want_transition) {
        //     visual.will_hide = true;
        //     BN_LOG("Will hide character ", visual.character, ". Reason: ", "visual.background.has_value() && background_want_transition");
        //     visual.will_show = visual.visible_bg_item.has_value() && (should_enable_scene || (!should_disable_scene && is_scene_visible));
        //     if (visual.will_show) {
        //         BN_LOG("Will show character ", visual.character, ". Reason: ", "visual.visible_bg_item.has_value() && (should_enable_scene || (!should_disable_scene && is_scene_visible))");
        //     }
        // }
        //
        // if (!visual.background.has_value() && visual.bg_item.has_value() && should_enable_scene) {
        //     visual.will_show = true;
        //     BN_LOG("Will show character ", visual.character, ". Reason: ", "!visual.background.has_value() && visual.bg_item.has_value() && should_enable_scene");
        // }

        characters_want_show = characters_want_show || visual.will_show;
        characters_want_hide = characters_want_hide || visual.will_hide;
    }

    /// HIDE DIALOGS (WITH DISSOLVE)
    if (background_want_dissolve || background_want_transition || characters_want_show || characters_want_hide || is_paused) {
        if (!dialog->is_hidden()) {
            BN_LOG("Update visuals: Hide dialogbox");
            dialog->hide_blend();
        }
    }

    /// CHANGE CHARACTER POSES
    for (auto &visual : character_visuals) {
        if (!visual.bg_item.has_value() || !visual.sprite_item.has_value()) {
            // visual.visible_bg_item.reset();
            // visual.visible_sprite_item.reset();
            continue;
        }
        if (!visual.will_show && !visual.will_hide && is_scene_visible && !is_paused) {
            bn::fixed x = visual.background->position().x();
            bn::fixed y = visual.background->position().y();

            if (visual.bg_item != visual.visible_bg_item) {
                BN_LOG("Update visuals: Character ", visual.character, " background change");
                visual.background.reset();
                visual.background = visual.bg_item->create_bg(x, y);
                visual.background->set_priority(2);
                visual.background->set_z_order(10);
                visual.visible_bg_item = visual.bg_item;

                set_character_window_visibility(visual.background.value());
                ks::globals::sound_update();
            }

            if (visual.sprite_item != visual.visible_sprite_item) {
                BN_LOG("Update visuals: Character ", visual.character, " sprite change");
                visual.sprite.reset();
                visual.sprite = visual.sprite_item->create_sprite(
                    x + visual.offset_x + visual.sprite_meta->offset_x,
                    y + visual.sprite_meta->offset_y);
                visual.sprite->set_bg_priority(2);
                visual.sprite->set_z_order(10);
                visual.visible_sprite_item = visual.sprite_item;

                ks::globals::sound_update();
            }
        }
    }

    /// HIDE CHARACTERS (WITH DISSOLVE)
    /// TODO: investigate if we need to move characters when hiding
    if (characters_want_hide) {
        for (auto &visual : character_visuals) {
            if (!visual.background.has_value() || !visual.sprite.has_value()) {
                continue;
            }
            if (visual.will_hide && visual.sprite.has_value()) {
                BN_LOG("Update visuals: Hide character ", visual.character);
                visual.background->set_visible(true);
                visual.sprite->set_visible(true);
                visual.background->set_blending_enabled(true);
                visual.sprite->set_blending_enabled(true);
                bn::blending::set_transparency_alpha(bn::fixed(1));
                blend_action = bn::blending_transparency_alpha_to_action(20, 0.0);
            }
        }
        while (!blend_action->done()) {
            blend_action->update();
            globals::main_update();
        }
        blend_action.reset();

        for (auto &visual : character_visuals) {
            if (visual.will_hide) {
                visual.background.reset();
                visual.sprite.reset();
                visual.visible_bg_item.reset();
                visual.visible_sprite_item.reset();
            }
        }
    }

    /// HIDE BACKGROUNDS (WITH DISSOLVE)
    if (background_want_hide) {
        if (background_want_dissolve) {
            BN_LOG("Update visuals: Hide background with dissolve");
            primary_background->set_blending_enabled(true);
            bn::blending::set_transparency_alpha(bn::fixed(1));
            blend_action = bn::blending_transparency_alpha_to_action(background_visual.dissolve_time, 0.0);
            while (!blend_action->done()) {
                blend_action->update();
                globals::main_update();
            }
        }

        if (background_want_transition) {
            BN_LOG("Update visuals: Hide background with transition ", background_visual.transition);
            perform_transition(background_visual.transition);
            background_visual.transition = SCENE_TRANSITION_NONE;
        }

        primary_background.reset();
        background_visual.visible_bg_item.reset();
        blend_action.reset();
    }

    ks::globals::main_update();

    /// CHANGE BACKGROUNDS (WITH DISSOLVE)
    if (background_want_change) {
        bool background_change_fallback = false;
        if (background_want_dissolve) {
            BN_LOG("Update visuals: Change background with dissolve");
            secondary_background.reset();
            secondary_background = background_visual.bg_item->create_bg_optional(background_visual.position_x, background_visual.position_y);
            if (secondary_background.has_value()) {
                ks::globals::sound_update();
                secondary_background->set_priority(3);
                secondary_background->set_z_order(9);
                secondary_background->set_blending_enabled(true);
                bn::blending::set_transparency_alpha(bn::fixed(0));
                blend_action = bn::blending_transparency_alpha_to_action(background_visual.dissolve_time, 1.0);
                while (!blend_action->done()) {
                    blend_action->update();
                    globals::main_update();
                }

                primary_background.reset();
                secondary_background.reset();

                primary_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
                primary_background->set_priority(3);
                primary_background->set_z_order(10);
                if (custom_event.has_value()) {
                    (*custom_event)->init();
                }
                blend_action.reset();

                ks::globals::sound_update();
            } else {
                BN_LOG("   <<< Unable to create secondary background! Fallback to change without dissolve");
                background_change_fallback = true;
            }
        }

        if (background_want_transition) {
            BN_LOG("Update visuals: Change background with transition ", background_visual.transition);
            perform_transition(background_visual.transition, background_visual.bg_item);
            background_visual.transition = SCENE_TRANSITION_NONE;
        } else if (!background_want_dissolve || background_change_fallback) {
            BN_LOG("Update visuals: Change background instantly");
            primary_background.reset();
            primary_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
            primary_background->set_priority(3);
            primary_background->set_z_order(10);
            if (custom_event.has_value()) {
                (*custom_event)->init();
            }

            ks::globals::sound_update();
        }

        background_visual.visible_bg_item = background_visual.bg_item;
    }

    /// SHOW BACKGROUNDS (WITH DISSOLVE)
    if (background_want_show) {
        BN_LOG("Update visuals: Show background");
        primary_background.reset();
        primary_background = background_visual.bg_item->create_bg(background_visual.position_x, background_visual.position_y);
        primary_background->set_priority(3);
        primary_background->set_z_order(10);
        if (custom_event_want_init) {
            (*custom_event)->init();
        }
        ks::globals::sound_update();

        if (background_want_transition) {
            BN_LOG("                with transition ", background_visual.transition);
            perform_transition(background_visual.transition);
            background_visual.transition = SCENE_TRANSITION_NONE;
        }

        if (background_want_dissolve) {
            BN_LOG("                with dissolve");
            primary_background->set_blending_enabled(true);
            bn::blending::set_transparency_alpha(bn::fixed(0));
            blend_action = bn::blending_transparency_alpha_to_action(background_visual.dissolve_time, 1.0);
            while (!blend_action->done()) {
                blend_action->update();
                globals::main_update();
            }
            primary_background->set_blending_enabled(false);
            blend_action.reset();
        }

        background_visual.visible_bg_item = background_visual.bg_item;
    }

    /// STILL HAVE TRANSITIONS? PERFORM IT ANYWAY (example: PASSOUTP1)
    if (background_want_transition && background_visual.transition != SCENE_TRANSITION_NONE) {
        BN_LOG("Update visuals: Still have transition ", background_visual.transition);
        perform_transition(background_visual.transition);
        background_visual.transition = SCENE_TRANSITION_NONE;
    }

    /// If we have actually same background but different event - we should initialize it anyway!
    if (custom_event_want_init && !(*custom_event)->is_initialized()) {
        BN_LOG("Update visuals: Custom event still want init");
        (*custom_event)->init();
    }

    ks::globals::main_update();

    /// SHOW AND MOVE CHARACTERS (WITH DISSOLVE), MOVE BACKGROUND
    if (characters_want_show) {
        bool will_blend = false;
        for (auto &visual : character_visuals) {
            if (!visual.bg_item.has_value()) {
                continue;
            }
            if (visual.will_show) {
                BN_LOG("Update visuals: Show character ", visual.character);
                visual.background = visual.bg_item->create_bg(visual.position_x, visual.position_y);
                visual.background->set_priority(2);
                visual.background->set_z_order(10);
                visual.background->set_blending_enabled(true);
                ks::globals::sound_update();

                visual.sprite = visual.sprite_item->create_sprite(
                    visual.position_x + visual.offset_x + visual.sprite_meta->offset_x,
                    visual.position_y + visual.offset_y + visual.sprite_meta->offset_y);
                visual.sprite->set_bg_priority(2);
                visual.sprite->set_z_order(10);
                visual.sprite->set_blending_enabled(true);
                ks::globals::sound_update();

                visual.visible_bg_item = visual.bg_item;
                visual.visible_sprite_item = visual.sprite_item;

                set_character_window_visibility(visual.background.value());
                will_blend = true;
            }
        }
        if (will_blend) {
            bn::blending::set_transparency_alpha(bn::fixed(0));
            blend_action = bn::blending_transparency_alpha_to_action(20, 1.0);
        }
    }

    ks::globals::main_update();
    if (background_want_move) {
        BN_LOG("Update visuals: Move background");
        bg_moves.push_back(bn::regular_bg_move_to_action(*primary_background,
                                                         20,
                                                         background_visual.position_x,
                                                         background_visual.position_y));
    }
    for (auto &visual : character_visuals) {
        bool character_want_move = visual.background.has_value() &&
                                   (visual.position_x != visual.background->position().x() ||
                                   visual.position_y != visual.background->position().y());
        if (character_want_move) {
            BN_LOG("Update visuals: Move character ", visual.character,
                " from ", visual.background->position().x(), ", ", visual.background->position().y(),
                " to ", visual.position_x, ", ", visual.position_y);
            bg_moves.push_back(bn::regular_bg_move_to_action(*visual.background, 20, visual.position_x, visual.position_y));
            spr_moves.push_back(bn::sprite_move_to_action(*visual.sprite, 20,
                visual.position_x + visual.offset_x + visual.sprite_meta->offset_x,
                visual.position_y + visual.offset_y + visual.sprite_meta->offset_y));
        }
    }

    in_progress = true;
    while (in_progress && (blend_action.has_value() || !bg_moves.empty() || !spr_moves.empty())) {
        in_progress = false;
        if (blend_action.has_value() && !blend_action->done()) {
            blend_action->update();
            in_progress = true;
        }
        for (auto& action : bg_moves) {
            if (!action.done()) {
                action.update();
                in_progress = true;
                for (auto &visual : character_visuals) {
                    if (!visual.background.has_value()) {
                        continue;
                    }
                    set_character_window_visibility(visual.background.value());
                }
            }
        }
        for (auto& action : spr_moves) {
            if (!action.done()) {
                action.update();
                in_progress = true;
            }
        }
        globals::main_update();
    }
    for (auto &visual : character_visuals) {
        if (!visual.bg_item.has_value()) {
            continue;
        }
        if (visual.will_show) {
            visual.background->set_blending_enabled(false);
            visual.sprite->set_blending_enabled(false);
        }
    }
    blend_action.reset();

    /// discard: SHOW DIALOGS (WITH DISSOLVE)
}

void SceneManager::music_play(const music_t music) {
    music_play(music, 0);
}

void SceneManager::music_play(const music_t music, const int fade) {
    BN_LOG("Play Music ", ks::sound_manager::get_music_filename(music), " with fade ", fade);
    ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
    ks::sound_manager::play(music);
    if (fade > 0 && !is_loading) {
        ks::sound_manager::set_fadein_action<SOUND_CHANNEL_MUSIC>(fade);
    }

    if (!is_loading) {
        ks::globals::main_update();
    }
}

void SceneManager::music_stop() {
    music_stop(0);
}

void SceneManager::music_stop(const int fade) {
    BN_LOG("Stop GSM with fade ", fade);
    if (fade > 0 && !is_loading) {
        ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_MUSIC>(fade);
    } else {
        ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
    }
}

void SceneManager::sfx_play(const char* filename, const sound_channel_t channel) {
    sfx_play(filename, channel, 0);
}

void SceneManager::sfx_play(const char* filename, const sound_channel_t channel, const int fade) {
    BN_LOG("Play SFX ", filename, " on channel ", channel, " with fade ", fade);
    if (channel == SOUND_CHANNEL_SOUND) {
        ks::sound_manager::stop<SOUND_CHANNEL_SOUND>();
        ks::sound_manager::play<SOUND_CHANNEL_SOUND>(filename);
        if (fade > 0 && !is_loading) {
            ks::sound_manager::set_fadein_action<SOUND_CHANNEL_SOUND>(fade);
        }
    } else if (channel == SOUND_CHANNEL_AMBIENT) {
        ks::sound_manager::stop<SOUND_CHANNEL_AMBIENT>();
        ks::sound_manager::play<SOUND_CHANNEL_AMBIENT>(filename);
        if (fade > 0 && !is_loading) {
            ks::sound_manager::set_fadein_action<SOUND_CHANNEL_AMBIENT>(fade);
        }
    } else {
        BN_ERROR("Attempt to play SFX on invalid channel ", channel);
    }
}

void SceneManager::sfx_stop(const sound_channel_t channel) {
    sfx_stop(channel, 0);
}

void SceneManager::sfx_stop(const sound_channel_t channel, const int fade) {
    BN_LOG("Stop SFX on channel ", channel, " with fade ", fade);
    if (channel == SOUND_CHANNEL_SOUND) {
        if (fade > 0 && !is_loading) {
            ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_SOUND>(fade);
        } else {
            ks::sound_manager::stop<SOUND_CHANNEL_SOUND>();
        }
    } else if (channel == SOUND_CHANNEL_AMBIENT) {
        if (fade > 0 && !is_loading) {
            ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_AMBIENT>(fade);
        } else {
            ks::sound_manager::stop<SOUND_CHANNEL_AMBIENT>();
        }
    } else {
        BN_ERROR("Attempt to stop SFX on invalid channel ", channel);
    }
}

void SceneManager::show_video(const uint8_t* dxtv_file, size_t dxtv_size, const char* audio_file, bn::color clear) {
    if (is_loading) {
        return;
    }

    ks::timer::pause_ingame_timer();

    bool is_act_video = true;

    bn::color clear_color;
    if (dxtv_file == video_4ls_dxtv) {
        clear_color = globals::colors::BLACK;
        is_act_video = false;
    } else if (is_act_video && dxtv_file != video_op_1_dxtv) {
        clear_color = globals::colors::WHITE;
        ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_MUSIC>(120);
        ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_SOUND>(120);
        ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_AMBIENT>(120);
        fade_out(clear_color, 120);
    } else {
        clear_color = clear;
    }

    // Free last sound chunks
    ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
    ks::sound_manager::stop<SOUND_CHANNEL_SOUND>();
    ks::sound_manager::stop<SOUND_CHANNEL_AMBIENT>();
    ks::globals::sound_update();
    sound_mixer::mute();

    free_resources();
    ks::globals::release_engine();
    // ks::globals::init_engine(clear_color);

    bn::core::init(clear_color, bn::string_view(), ks::globals::ISR_VBlank);
    REG_TM0CNT_H |= TIMER_START;
    REG_TM1CNT_H |= TIMER_START;

    videoplayer_init(dxtv_file, dxtv_size, audio_file, clear_color.red(), clear_color.green(), clear_color.blue());
    if (is_act_video) {
        pause(60);
    }
    videoplayer_play();

    // Re-init Butano Core
    // ks::globals::release_engine();
    ks::globals::init_engine();
    BN_LOG("Init engine done!");

    // TODO: Check the ingame timer after engine restoration.
    ks::timer::resume_ingame_timer();
}

void SceneManager::show_video(const uint8_t* dxtv_file, size_t dxtv_size, const char* audio_file) {
    show_video(dxtv_file, dxtv_size, audio_file, ks::globals::colors::BLACK);
}

void SceneManager::exit_scenario_from_ingame_menu() {
    if (!in_replay) {
        autosave();
    }

    static_text_sprites.clear();
    animated_text_sprites.clear();
    secondary_background.reset();

    for(int alpha = 16; alpha <= 32; ++alpha) {
        bn::bg_palettes::set_fade(globals::colors::BLACK, bn::fixed(alpha) / 32);
        bn::sprite_palettes::set_fade(globals::colors::BLACK, bn::fixed(alpha) / 32);
        ks::globals::main_update();
    }

    free_resources();
}

void SceneManager::pause(const int ticks) {
    if (is_loading) {
        return;
    }
    if (is_paused) {
        return;
    }
    for(int tick = 0; tick <= ticks; ++tick) {
        ks::globals::main_update();
    }
}

void SceneManager::timeskip() {
    if (is_loading) {
        return;
    }

    music_stop(120);
    sfx_stop(SOUND_CHANNEL_SOUND, 120);
    sfx_stop(SOUND_CHANNEL_AMBIENT, 120);
    pause(120);

    music_play(MUSIC_TIMESKIP);

    set_background(background_metas::kslogo_heart, 0, 0, SCENE_TRANSITION_CLOCKWIPE_IN, 0);
    // set_background_transition(SCENE_TRANSITION_CLOCKWIPE);
    update_visuals();

    set_background(background_metas::kslogo_words, 0, 0, SCENE_TRANSITION_NONE, 108);
    // set_background_transition(SCENE_TRANSITION_CLOCKWIPE);
    update_visuals();

    pause(120);

    music_stop(120);

    hide_background(SCENE_TRANSITION_CLOCKWIPE_OUT, 0);
    update_visuals();

    pause(112);
}

void SceneManager::fade_in(const bn::color &color, const int steps) {
    bn::bg_palettes::set_fade(color, bn::fixed(1));
    bn::sprite_palettes::set_fade(color, bn::fixed(1));
    for(int alpha = steps; alpha >= 0; --alpha) {

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

inline shader_data SceneManager::init_transition_shader(const bn::affine_bg_item &transition_item, const bool use_buffer) {
    shader_data data{};

    const bool allow_offset = bn::bg_blocks_manager::allow_tiles_offset();
    bn::bg_blocks_manager::set_allow_tiles_offset(false);
    ks::transition_bg = transition_item.create_bg(0, 0);
    bn::bg_blocks_manager::set_allow_tiles_offset(allow_offset);


    ks::transition_bg->set_priority(1);
    ks::transition_bg->set_wrapping_enabled(false);
    ks::transition_bg->set_scale(2.0, 2.0);
    ks::transition_bg->set_blending_enabled(true);
    bn::blending::set_fade_color(bn::blending::fade_color_type::BLACK);
    bn::blending::set_fade_alpha(1.0);

    auto tiles_cbb = ks::transition_bg->tiles().cbb();
    auto tiles_handle = ks::transition_bg->tiles().handle();
    auto tiles_count = ks::transition_bg->tiles().tiles_count();
    BN_LOG("Tiles count: ", tiles_count);
    BN_LOG("Tiles Handle: ", tiles_handle);
    BN_LOG("Tiles CBB: ", tiles_cbb);
    // BN_LOG("Tiles HWID: ", ks::transition_bg->hw_id().value());

    auto cbb_addr = CHAR_BASE_BLOCK(tiles_cbb);
    BN_LOG("Tiles CBB ADDR: ", cbb_addr);

    data.vram_ptr = static_cast<uint32_t *>(cbb_addr);
    data.dwords = tiles_count * 8;

    if (use_buffer) {
        BN_LOG("EWRAM BEFORE ", bn::memory::available_alloc_ewram());
        data.tiles_buffer = static_cast<uint32_t*>(bn::memory::ewram_alloc(data.dwords * 4));  // EWRAM allocation
        BN_LOG("EWRAM AFTER ", bn::memory::available_alloc_ewram());
        BN_LOG("Start DMA copy");
        dmaCopy(cbb_addr, data.tiles_buffer, data.dwords * 4); // TODO: check
        BN_LOG("DMA copy finished");
    }

    return data;
}

void SceneManager::transition_fadein(const bn::affine_bg_item &transition_item, const int speed, const bool reverse) {
    const auto shader = init_transition_shader(transition_item, false);
    VBlankIntrWait();

    BN_LOG("Start Transition Fadein");

    if (reverse) {
        for (int dissolve_i = 0; dissolve_i < 128; dissolve_i += speed) {
            shader_dissolve_in_inverted(shader.dwords, dissolve_i, shader.vram_ptr, update_transitions);
            ks::globals::main_update();
        }
    } else {
        for (int dissolve_i = 128; dissolve_i > 0; dissolve_i -= speed) {
            shader_dissolve_in(shader.dwords, dissolve_i, shader.vram_ptr, update_transitions);
            ks::globals::main_update();
        }
    }

    bn::blending::set_fade_alpha(0.0);
    ks::transition_bg.reset();
}

void SceneManager::transition_fadeout(const bn::affine_bg_item &transition_item, const int speed, const bool reverse) {
    const auto shader = init_transition_shader(transition_item, true);
    VBlankIntrWait();

    BN_LOG("Start Transition Fadeout");

    if (reverse) {
        for (int dissolve_i = 128; dissolve_i >= 0; dissolve_i -= speed) {
            shader_dissolve_out_inverted(shader.dwords, dissolve_i, shader.tiles_buffer, shader.vram_ptr, update_transitions);
            ks::globals::main_update();
        }
    } else {
        for (int dissolve_i = 0; dissolve_i <= 128; dissolve_i += speed) {
            shader_dissolve_out(shader.dwords, dissolve_i, shader.tiles_buffer, shader.vram_ptr, update_transitions);
            ks::globals::main_update();
        }
    }

    bn::memory::ewram_free(shader.tiles_buffer);
    BN_LOG("EWRAM AFTER FREE: ", bn::memory::available_alloc_ewram());


    bn::blending::set_fade_alpha(0.0);
    ks::transition_bg.reset();
}

int SceneManager::get_character_visual_index(const character_t character, const bool create_if_not_found) {
    BN_LOG("get_character_visual_index: ", character, " create_if_not_found: ", create_if_not_found);
    for (int i = 0; i < 4; i++) {
        BN_LOG("Character at index ", i, ":");
        BN_LOG("                      character: ", character_visuals.at(i).character);
        BN_LOG("                      index: ", character_visuals.at(i).index, " (deprecated)");
        if (character_visuals.at(i).character == character) {
            return i;
        }
    }
    if (create_if_not_found) {
        for (int i = 0; i < 4; i++) {
            if (character_visuals.at(i).character == CHARACTER_NONE) {
                return i;
            }
        }
        BN_ERROR("Maximum displayable characters exceeded");
        return -1;
    }
    BN_ERROR("Character not found: ", character);
    return -1;
}
} // namespace ks
