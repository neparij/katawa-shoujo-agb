#ifndef MENU_SAVES_CPP_H
#define MENU_SAVES_CPP_H

#include <bn_format.h>
#include <bn_regular_bg_items_ui_bg_menu_inner.h>
#include <bn_sprite_items_ui_button_b.h>
#include <bn_sprite_items_thumb_hosp_room.h>

#include "background_metas.h"
#include "menu_base.h"
#include "../ingametimer.h"


namespace ks {
    class MenuSaves final : public MenuBase {
    public:
        explicit MenuSaves(gameState_t &state): MenuBase(state) {
            main_background = bn::regular_bg_items::ui_bg_menu_inner.create_bg(0, 0);

            total_saves = saves::getUsedSaveSlots();
            saves_from_cursor = total_saves;
            if (saves::readAutosaveMetadata().has_data) {
                saves_from_cursor++;
            }

            draw_slots(saves_from_cursor);
        }

        ~MenuSaves() override {
        }

        void on_back() override {
            state = GS_MENU_MAIN;
            menu::set_initial_selection(1);
        }

        void on_select(const int option) override {
            if (option == 3) {
                on_back();
            } else {
                timer::start_ingame_timer();

                const short i = saveslot_index.at(selection);
                BN_LOG("Slot: ", i);
                if (i == -1) {
                    progress = saves::readAutosave();
                } else {
                    progress = saves::readSaveSlot(i);
                }
                BN_ASSERT(saves::isValid(&progress, i), "Invalid save slot");

                state = GS_LOAD_GAME;
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

        void draw_slots(const unsigned short from) {
            constexpr short draw_x_from = 10;
            constexpr short draw_y_from = -48;
            constexpr short draw_y_offset = 40;

            selection_indexes.clear();
            saveslot_index.clear();
            items_count = 0;

            static_text_sprites->clear();
            progress_icon_sprites->clear();
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_left_alignment();

            signed char selection_index = 0;
            unsigned char tile_index = 0;

            const unsigned short to = bn::max(0, from - 3);

            for (unsigned short i = from; i > to; i--, tile_index++, selection_index += 1) {
                const bool is_autosave = i == total_saves + 1;
                saves::SaveSlotMetadata slot;
                if (is_autosave) {
                    slot = saves::readAutosaveMetadata();
                } else {
                    slot = saves::readSlotMetadata(i - 1);
                }


                add_menu_entry(-device::screen_width_half + draw_x_from + 52, draw_y_from + draw_y_offset * tile_index,
                               globals::i18n->label(slot.label),
                               selection_index);

                add_text_entry(-device::screen_width_half + draw_x_from + 52, draw_y_from + (draw_y_offset * tile_index + 12),
                               bn::format<64>(
                                   "{}: {}:{}:{} {}",
                                   globals::i18n->screens_playtime(),
                                   slot.hours_played,
                                   bn::format<2>(slot.minutes_played < 10 ? "0{}" : "{}", slot.minutes_played),
                                   bn::format<2>(slot.seconds_played < 10 ? "0{}" : "{}", slot.seconds_played),
                                   is_autosave ? globals::i18n->definitions_autosave() : ""),
                               selection_index);

                const auto thumbnail = background_metas::get_by_hash(slot.thumbnail_hash);
                if (thumbnail != nullptr) {
                    progress_icon_sprites->push_back(thumbnail->thumbnail.create_sprite(
                        -device::screen_width_half + draw_x_from + 24, draw_y_from + 10 + draw_y_offset * tile_index));
                }

                saveslot_index.push_back(is_autosave ? -1 : i - 1);
                globals::sound_update();
            }

            text_generator->set_right_alignment();
            add_menu_entry(device::screen_width_half - draw_x_from, device::screen_height_half - 14,
                           globals::i18n->menu_back(), 3);
            need_repalette = true;
        }

    private:
        bn::vector<short, 3> saveslot_index;
        unsigned short total_saves, saves_from_cursor;
    };
}

#endif //MENU_SAVES_CPP_H
