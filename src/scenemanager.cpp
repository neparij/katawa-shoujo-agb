#include "scenemanager.h"
#include "bn_music.h"
#include "bn_regular_bg_actions.h"
#include "bn_sprite_actions.h"
#include "bn_blending_actions.h"
#include "sequence/backgrounditem.h"
#include "sequence/istartitem.h"
#include "sequence/musicitem.h"
#include "sequence/runlabelitem.h"
#include "sequence/runlabelfinishitem.h"

#include "utils/scenario_reader.h"
#include "variable_16x16_sprite_font.h"

#include "globals.h"

#include <BN_LOG.h>
// #include "bn_music_items.h"


namespace ks {

bn::optional<bn::regular_bg_ptr> main_background;
bn::optional<bn::regular_bg_ptr> secondary_background;
bn::vector<character_visuals_ptr, 4> character_visuals;
bn::vector<bn::optional<bn::sprite_palette_ptr>, 2> character_palettes;

ks::DialogBox* dialog;

void SceneManager::reset() {
    while (character_visuals.size() < character_visuals.max_size()) {
        character_visuals.push_back(character_visuals_ptr());
    }
    while (character_palettes.size() < character_palettes.max_size()) {
        character_palettes.push_back(bn::optional<bn::sprite_palette_ptr>());
    }
    for (auto visual : character_visuals) {
        visual.background.reset();
        visual.sprite.reset();
        // visual.sprite_palette.reset();
    }

    // character_visuals.clear();
}

void SceneManager::set_background(const bn::regular_bg_item& bg) {
    // TODO: rewrite to support "scene" token
    // temporaly hide chars
    // for (auto visual : character_visuals) {
    //     visual.background.reset();
    //     visual.sprite.reset();
    // }
    for (int i = 0; i < character_visuals.size(); i++) {
        hide_character(i, false);
    }

    main_background.reset();
    main_background = bg.create_bg(0, 0);
    main_background->set_z_order(10);

    ks::globals::main_update();
}

void SceneManager::show_dialog(const ks::SceneManager* scene, bn::string<16> actor, int tl_key) {
    auto message = ks::scenario::gbfs_reader::get_tl(scene->scenario(), scene->locale(), scene->_script_tl_index[tl_key]);
    dialog->show(actor, message);
    while (!dialog->is_finished()) {
        dialog->update();
        ks::globals::main_update();
    }
}

void SceneManager::show_character(const int character_index,
                                  const bn::regular_bg_item& bg,
                                  const bn::sprite_item& sprite,
                                  const ks::character_sprite_meta& sprite_meta,
                                  const int position_x,
                                  const int position_y,
                                  const bool position_change) {
    bool was_shown_before = character_visuals.at(character_index).background.has_value();
    if (position_change && !was_shown_before) {
        character_visuals.at(character_index).position_x = position_x;
        character_visuals.at(character_index).position_y = position_y;
    }
    if (!was_shown_before) {
        dialog->hide_blend();
    }

    character_visuals.at(character_index).background.reset();
    character_visuals.at(character_index).background = bg.create_bg(character_visuals.at(character_index).position_x,
                                                                    character_visuals.at(character_index).position_y);
    character_visuals.at(character_index).background->set_z_order(0);

    character_visuals.at(character_index).sprite.reset();
    character_visuals.at(character_index).sprite = sprite.create_sprite(character_visuals.at(character_index).position_x + sprite_meta.offset_x,
                                                                        character_visuals.at(character_index).position_y + sprite_meta.offset_y);
    character_visuals.at(character_index).offset_x = sprite_meta.offset_x;
    character_visuals.at(character_index).offset_y = sprite_meta.offset_y;
    character_visuals.at(character_index).sprite->set_z_order(-5);

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
        spr_alpha_action.reset();
    }

    ks::globals::main_update();

    if (position_change && was_shown_before) {
        set_character_position(character_index, position_x, position_y);
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

    character_visuals.at(character_index).bg_move_action = bn::regular_bg_move_to_action(character_visuals.at(character_index).background.value(),
                                                                                      20,
                                                                                      position_x,
                                                                                      position_y);
    character_visuals.at(character_index).spr_move_action = bn::sprite_move_to_action(character_visuals.at(character_index).sprite.value(),
                                                                                      20,
                                                                                      position_x + character_visuals.at(character_index).offset_x,
                                                                                      position_y + character_visuals.at(character_index).offset_y);

    while (!character_visuals.at(character_index).bg_move_action->done() &&
           !character_visuals.at(character_index).spr_move_action->done()) {
        character_visuals.at(character_index).bg_move_action->update();
        character_visuals.at(character_index).spr_move_action->update();
        ks::globals::main_update();
    }
    character_visuals.at(character_index).bg_move_action.reset();
    character_visuals.at(character_index).spr_move_action.reset();
}

void SceneManager::hide_character(const int character_index, const bool need_update) {
    // delete character_visuals.at(character_index).sprite_item_ptr;
    character_visuals.at(character_index).background.reset();
    character_visuals.at(character_index).sprite.reset();
    character_visuals.at(character_index).position_x = 0;
    character_visuals.at(character_index).position_y = 0;
    // delete &character_visuals.at(character_index).background_item_ptr;
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

} // namespace ks
