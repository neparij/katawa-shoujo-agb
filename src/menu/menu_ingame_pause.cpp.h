#ifndef MENU_INGAME_PAUSE_CPP_H
#define MENU_INGAME_PAUSE_CPP_H

#include "menu_base.h"
#include "bn_sprite_items_ui_ingame_menu_ne.h"
#include "bn_sprite_items_ui_ingame_menu_nw.h"
#include "bn_sprite_items_ui_ingame_menu_se.h"
#include "bn_sprite_items_ui_ingame_menu_sw.h"

namespace ks {
    class MenuIngamePause final : public MenuBase {
    public:
        explicit MenuIngamePause() {
            BN_LOG("Create MenuIngamePause");

            secondary_background.reset();
            static_text_sprites.clear();
            animated_text_sprites.clear();
            progress_icon_sprites.clear();
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_center_alignment();
            text_item_palette = globals::text_palettes::original;

            bn::blending::set_fade_alpha(0.0);
            bn::blending::set_transparency_alpha(1.0);
            if (selection == 0) {
                show_dots_animation(true);
            } else {
                if (background_visual.visible_bg_item.has_value()) {
                    primary_background = background_visual.bg_item->create_bg(
                        background_visual.position_x,
                        background_visual.position_y);
                    primary_background->set_priority(3);
                    primary_background->set_z_order(10);

                    if (custom_event.has_value()) {
                        (*custom_event)->init();
                    }
                }
            }

            if (primary_background.has_value()) {
                bn::blending::set_fade_alpha(ks::DialogBox::transparency_alpha());
                primary_background->set_blending_enabled(true);
            }

            menu_bg_sprites.push_back(bn::sprite_items::ui_ingame_menu_ne.create_sprite(32, -32));
            menu_bg_sprites.push_back(bn::sprite_items::ui_ingame_menu_nw.create_sprite(-32, -32));
            menu_bg_sprites.push_back(bn::sprite_items::ui_ingame_menu_se.create_sprite(32, 32));
            menu_bg_sprites.push_back(bn::sprite_items::ui_ingame_menu_sw.create_sprite(-32, 32));

            add_text_entry(0, -ks::device::screen_height_half + 8,
                           bn::format<64>(
                               "{}: {}:{}:{}",
                               ks::globals::i18n->screens_playtime(),
                               progress.metadata.hours_played,
                               bn::format<2>(progress.metadata.minutes_played < 10 ? "0{}" : "{}",
                                             progress.metadata.minutes_played),
                               bn::format<2>(progress.metadata.seconds_played < 10 ? "0{}" : "{}",
                                             progress.metadata.seconds_played)));

            add_menu_entry(0, -48, ks::globals::i18n->screens_return(), 0);
            add_menu_entry(0, -32, ks::globals::i18n->screens_history(), 1);
            add_menu_entry(0, -16, ks::globals::i18n->screens_options(), 2);
            add_menu_entry(0, 0, ks::globals::i18n->screens_save_game(), 3);
            add_menu_entry(0, 16, ks::globals::i18n->screens_load_game(), 4);
            add_menu_entry(0, 32, ks::globals::i18n->screens_main_menu(), 5);

            add_text_entry(0, ks::device::screen_height_half - 8 - 12,
                           bn::format<64>("{}: {}",
                                          ks::globals::i18n->screens_current_scene(),
                                          ks::globals::i18n->label(progress.metadata.label)));

            add_text_entry(0, ks::device::screen_height_half - 8,
                           bn::format<64>("{}: {}",
                                          ks::globals::i18n->screens_current_track(),
                                          ks::globals::i18n->music(ks::sound_manager::current_music)));
        }

        ~MenuIngamePause() override {
        }

        void on_back() override {
            menu_bg_sprites.clear();
            static_text_sprites.clear();

            if (primary_background.has_value()) {
                bn::blending::set_fade_alpha(0.0);
                primary_background->set_blending_enabled(false);
            }
            show_dots_animation(false);
            ks::globals::state = GS_GAME;
            is_paused = false;
            ks::SceneManager::update_visuals();
        }

        void on_update() override {
            if (bn::keypad::start_pressed()) {
                on_back();
            }
        }

        void on_select(const int option) override {
            switch (option) {
                case 0:
                    on_back();
                    break;
                case 3:
                    slot_idx = saves::getUsedSaveSlots();
                    if (slot_idx < saves::getTotalSaveSlots()) {
                        BN_LOG("Save game to slot ", slot_idx);
                        SceneManager::save(slot_idx);
                    } else {
                        BN_ERROR("No more slots available");
                        break;
                    }
                    break;
                case 4:
                    primary_background.reset();
                    secondary_background.reset();
                    static_text_sprites.clear();
                    animated_text_sprites.clear();
                    progress_icon_sprites.clear();
                    if (custom_event.has_value()) {
                        BN_LOG("Should dispose custom event");
                        (*custom_event)->destroy();
                    }
                    menu_bg_sprites.clear();
                    globals::state = GS_GAME_MENU_SAVES;
                    break;
                case 5:
                    globals::exit_scenario = true;
                    if (!in_replay) {
                        SceneManager::autosave();
                    }

                    for(int alpha = 16; alpha <= 32; ++alpha) {
                        bn::bg_palettes::set_fade(globals::colors::BLACK, bn::fixed(alpha) / 32);
                        bn::sprite_palettes::set_fade(globals::colors::BLACK, bn::fixed(alpha) / 32);
                        ks::globals::main_update();
                    }
                    globals::state = GS_RESET;
                    break;
                default:
                    BN_ERROR("Menu option is not implemented");
                    break;
            }
        }

        void show_dots_animation(bool forward) {
            secondary_background = bn::regular_bg_items::ui_backdrop_dots.create_bg(0, 0);
            secondary_background->set_blending_enabled(true);

            while (forward ? dots_offset < 160 + 96 : dots_offset > 0) {
                dots_offset += forward ? 16 : -16;
                secondary_background->set_position(0, -80 + 128 + dots_offset);
                for (int index = 0, amplitude = 160; index < amplitude; ++index) {
                    // bn::fixed
                    const bn::fixed clamped_alpha = bn::min(bn::max((index + 32 - dots_offset) / (32), bn::fixed(0)),
                                                            bn::fixed(1));
                    const bn::fixed transparency_alpha =
                            (bn::fixed(1) - clamped_alpha) * DialogBox::transparency_alpha();
                    transparency_attributes[index].set_transparency_alpha(transparency_alpha);
                }

                transparency_attributes_hbe = bn::blending_transparency_attributes_hbe_ptr::create(
                    transparency_attributes);
                globals::main_update();
            }

            transparency_attributes_hbe.reset();
            secondary_background.reset();
            bn::blending::set_transparency_alpha(1);
        }

    private:
        bn::fixed dots_offset = 0;
        bn::array<bn::blending_transparency_attributes, 160> transparency_attributes;
        bn::optional<bn::blending_transparency_attributes_hbe_ptr> transparency_attributes_hbe;
        bn::vector<bn::sprite_ptr, 4> menu_bg_sprites;

        // TODO: remove when save menu will be done:
        unsigned short slot_idx = -1;
    };
}
#endif //MENU_INGAME_PAUSE_CPP_H
