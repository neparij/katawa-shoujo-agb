#ifndef MENU_SAVES_CPP_H
#define MENU_SAVES_CPP_H

#include <bn_format.h>
#include <bn_regular_bg_items_ui_bg_menu_saves_front.h>
#include <bn_sprite_items_ui_bg_menu_saves_back_0.h>
#include <bn_sprite_items_ui_bg_menu_saves_back_1.h>
#include <bn_sprite_items_ui_bg_menu_saves_back_2.h>
#include <bn_sprite_items_ui_button_b.h>
#include <bn_sprite_items_ui_new_save.h>
#include <bn_sprite_items_ui_new_save_selected.h>

#include "background_metas.h"
#include "character_sprite_metas.h"
#include "menu_base.h"
#include "../ingametimer.h"
#include "../scenemanager.h"
#include "../sound/sound_mixer.h"


namespace ks {
    class MenuSaves final : public MenuBase {
    public:
        explicit MenuSaves() {
            primary_background.reset();
            progress_icon_sprites.clear();
            secondary_background = bn::regular_bg_items::ui_bg_menu_saves_front.create_bg(0, 0);
            secondary_background->set_priority(1);
            text_generator->set_bg_priority(1);

            text_item_palette = globals::text_palettes::beige;
            total_saves = saves::getUsedSaveSlots();
            saves_from_cursor = total_saves;
            if (saves::readAutosaveMetadata().has_data || in_game) {
                saves_from_cursor++;
            }

            draw_slots(saves_from_cursor);
        }

        ~MenuSaves() override {
        }

        void on_back() override {
            BN_LOG("on back, state = ", globals::state);
            if (globals::state == GS_MENU_SAVES) {
                globals::state = GS_MENU_MAIN;
                menu::set_initial_selection(1);
            } else if (globals::state == GS_GAME_MENU_SAVES) {
                globals::state = GS_GAME_MENU;
                menu::set_initial_selection(4);
            }
        }

        void on_select(const int option) override {
            if (option == 3) {
                on_back();
            } else {
                const short slot_index = saveslot_index.at(selection);
                if (slot_index == -1 && in_game) {
                    const unsigned short new_slot_index = saves::getUsedSaveSlots();
                    if (new_slot_index < saves::getTotalSaveSlots()) {
                        BN_LOG("Save game to slot ", new_slot_index);
                        SceneManager::save(new_slot_index);
                        restart();
                    } else {
                        BN_ERROR("No more slots available");
                    }
                } else {
                    if (slot_index == -1) {
                        savedata_progress = saves::readAutosave();
                    } else {
                        savedata_progress = saves::readSaveSlot(slot_index);
                    }
                    BN_ASSERT(saves::isValid(&savedata_progress, slot_index), "Invalid save slot");

                    fade_out();
                    sound_manager::stop<SOUND_CHANNEL_MUSIC>();
                    sound_manager::stop<SOUND_CHANNEL_SOUND>();
                    sound_manager::stop<SOUND_CHANNEL_AMBIENT>();
                    sound_mixer::mute();
                    if (globals::state == GS_GAME_MENU_SAVES) {
                        globals::exit_scenario = true;
                    }
                    globals::state = GS_LOAD_GAME;
                }
            }
        }

        void on_navigate(const bool up, const bool down, const bool left, const bool right) override {
            if (up) {
                const unsigned char additional_slot = saves::readAutosaveMetadata().has_data ? 1 : 0;
                if (selection == 0 && saves_from_cursor < total_saves + additional_slot) {
                    saves_from_cursor++;
                    draw_slots(saves_from_cursor);
                } else if (selection == 3) {
                    if (saveslot_index.empty()) {
                        selection = 3;
                    } else {
                        selection = saveslot_index.size() - 1;
                    }
                } else {
                    selection--;
                }
            } else if (down) {
                if (selection == 2 && saves_from_cursor > 3) {
                    saves_from_cursor--;
                    draw_slots(saves_from_cursor);
                } else {
                    if (saveslot_index.empty()) {
                        selection = 3;
                    } else if (selection == saveslot_index.size() - 1) {
                        selection = 3;
                    } else {
                        selection++;
                    }
                }
            }

            selection = bn::min(3, bn::max(0, selection));
            need_repalette = true;
        }

        void on_repalette() override {
            if (new_save_thumbnals.size() == 2) {
                if (selection == 0) {
                    new_save_thumbnals.at(0).set_visible(false);
                    new_save_thumbnals.at(1).set_visible(true);
                } else {
                    new_save_thumbnals.at(0).set_visible(true);
                    new_save_thumbnals.at(1).set_visible(false);
                }
            }
        }

        void draw_slots(const unsigned short from) {
            constexpr short draw_x_from = 10;
            constexpr short draw_y_from = -48;
            constexpr short draw_y_offset = 40;

            selection_indexes.clear();
            saveslot_index.clear();
            items_count = 0;

            static_text_sprites.clear();
            progress_icon_sprites.clear();
            saveslot_thumbnails.clear();
            new_save_thumbnals.clear();
            progress_icon_sprites.push_back(bn::sprite_items::ui_bg_menu_saves_back_0.create_sprite(
                -device::screen_width_half + 32, -device::screen_height_half + 32));
            progress_icon_sprites.back().set_bg_priority(3);
            progress_icon_sprites.push_back(bn::sprite_items::ui_bg_menu_saves_back_1.create_sprite(
                -device::screen_width_half + 32, -device::screen_height_half + 32 + 64));
            progress_icon_sprites.back().set_bg_priority(3);
            progress_icon_sprites.push_back(bn::sprite_items::ui_bg_menu_saves_back_2.create_sprite(
                -device::screen_width_half + 32, -device::screen_height_half + 32 + 128));
            progress_icon_sprites.back().set_bg_priority(3);
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_left_alignment();

            signed char selection_index = 0;
            unsigned char tile_index = 0;

            const unsigned short to = bn::max(0, from - 3);

            add_text_entry_bold(-device::screen_width_half + draw_x_from, -device::screen_height_half + 14,
                    globals::i18n->menu_saves(), -1);

            for (unsigned short i = from; i > to; i--, tile_index++, selection_index += 1) {
                const bool additional_slot = i == total_saves + 1;
                saves::SaveSlotMetadata slot;
                if (additional_slot && !in_game) {
                    slot = saves::readAutosaveMetadata();
                } else if (additional_slot && in_game) {
                    slot = progress.metadata;
                    slot.has_data = false;
                } else {
                    slot = saves::readSlotMetadata(i - 1);
                }

                if (slot.has_data) {
                    add_menu_entry_small(-device::screen_width_half + draw_x_from + 52, draw_y_from + draw_y_offset * tile_index,
                               globals::i18n->label(slot.label),
                               selection_index);

                    add_menu_entry_small(-device::screen_width_half + draw_x_from + 52, draw_y_from + (draw_y_offset * tile_index + 12),
                                   bn::format<64>(
                                       "{}: {}:{}:{} {}",
                                       globals::i18n->screens_playtime(),
                                       slot.hours_played,
                                       bn::format<2>(slot.minutes_played < 10 ? "0{}" : "{}", slot.minutes_played),
                                       bn::format<2>(slot.seconds_played < 10 ? "0{}" : "{}", slot.seconds_played),
                                       additional_slot ? globals::i18n->definitions_autosave() : ""),
                                   selection_index);
                } else {
                    add_menu_entry(-device::screen_width_half + draw_x_from + 52, draw_y_from + draw_y_offset * tile_index + 10,
                                                   globals::i18n->textbutton_save(),
                                                   selection_index);
                }

                const auto thumbnail = background_metas::get_by_hash(slot.thumbnail_hash);
                if (thumbnail != nullptr && slot.has_data) {
                    // This is a regular save/autosave
                    saveslot_thumbnails.push_back(thumbnail->thumbnail.create_bg(
                        -device::screen_width_half + draw_x_from + 24, draw_y_from + 10 + draw_y_offset * tile_index));
                    saveslot_thumbnails.back().set_priority(2);
                    for (const auto &[thumbnail_hash, offset_x] : slot.thumbnail_characters) {
                        if (thumbnail_hash != 0) {
                            if (const auto character_thumbnail = character_sprite_metas::get_by_hash(thumbnail_hash);
                                character_thumbnail != nullptr) {
                                progress_icon_sprites.push_back(
                                    character_thumbnail->thumbnail.create_sprite(
                                        -device::screen_width_half + draw_x_from + 24 + offset_x,
                                        draw_y_from + 10 + draw_y_offset * tile_index
                                    )
                                );
                                progress_icon_sprites.back().set_bg_priority(2);
                            }
                        }
                    }
                } else if (!slot.has_data && tile_index == 0) {
                    // This is a "new save" thumbnail placeholder
                    new_save_thumbnals.push_back(bn::sprite_items::ui_new_save.create_sprite(
                            -device::screen_width_half + draw_x_from + 24, draw_y_from + 10));
                    new_save_thumbnals.push_back(bn::sprite_items::ui_new_save_selected.create_sprite(
                            -device::screen_width_half + draw_x_from + 24, draw_y_from + 10));
                    for (auto& sprite : new_save_thumbnals) {
                        sprite.set_visible(false);
                    }
                }

                saveslot_index.push_back(additional_slot ? -1 : i - 1);
                globals::sound_update();
            }

            text_generator->set_right_alignment();
            add_menu_entry(device::screen_width_half - draw_x_from, device::screen_height_half - 14,
                           globals::i18n->menu_back(), 3);
            need_repalette = true;
        }

    private:
        bn::vector<short, 3> saveslot_index;
        bn::vector<bn::regular_bg_ptr, 3> saveslot_thumbnails;
        bn::vector<bn::sprite_ptr, 2> new_save_thumbnals;
        unsigned short total_saves, saves_from_cursor;
    };
}

#endif //MENU_SAVES_CPP_H
