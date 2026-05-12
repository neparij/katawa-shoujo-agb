#ifndef MENU_OPTIONS_CPP_H
#define MENU_OPTIONS_CPP_H

#include <bn_regular_bg_items_ui_bg_menu_inner.h>
#include <bn_sprite_items_ui_button_check_0.h>
#include <bn_sprite_items_ui_button_check_1.h>
#include <bn_sprite_items_ui_thumbbar_l.h>
#include <bn_sprite_items_ui_thumbbar_r.h>
#include <bn_sprite_items_ui_bar_horizontal_thumb.h>

#include "menu_base.h"

namespace ks {
    class MenuOptions final : public MenuBase {
    public:
        explicit MenuOptions() {
            static_text_sprites.clear();
            background_visual.visible_bg_item.reset();
            primary_background.reset();
            primary_background = bn::regular_bg_items::ui_bg_menu_inner.create_bg(0, 0);

            text_item_palette = globals::text_palettes::beige;
            create();
            update_checkboxes();
            update_thumbbars();
        }

        ~MenuOptions() override {
        }

        void on_back() override {
            writeSettings(globals::settings);
            if (globals::state == GS_GAME_MENU_OPTIONS) {
                globals::state = GS_GAME_MENU;
                menu::set_initial_selection(2);
            } else {
                globals::state = GS_MENU_MAIN;
                menu::set_initial_selection(3);
            }
        }

        void on_select(const int option) override {
            switch (option) {
                case 0:
                    globals::settings.hdisabled = !globals::settings.hdisabled;
                    update_checkboxes();
                    break;
                case 1:
                    if (globals::state == GS_GAME_MENU_OPTIONS) {
                        globals::state = GS_GAME_MENU_OPTIONS_ACCESSIBILITY;
                    } else {
                        globals::state = GS_MENU_OPTIONS_ACCESSIBILITY;
                    }
                    break;
                case 2:
                case 3:
                    break;
                case 4:
                    on_back();
                    break;
                default:
                    BN_ERROR("Menu option is not implemented");
            }
        }

        void create() {
            constexpr short draw_x_from = 10;

            selection_indexes.clear();
            checkboxes_ptrs.clear();
            thumbbars_ptrs.clear();
            thumbs_ptrs.clear();

            items_count = 0;
            static_text_sprites.clear();
            progress_icon_sprites.clear();
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_left_alignment();

            unsigned char yy = 14;
            constexpr unsigned char y_spacing = 16;

            add_text_entry_bold(-device::screen_width_half + draw_x_from, -device::screen_height_half + yy,
                    tl::menu_options(), -1);
            yy += y_spacing + 4;

            add_text_entry_bold(-device::screen_width_half + draw_x_from, -device::screen_height_half + yy,
                    tl::menu_options_general(), -1);
            yy += y_spacing;

            static_text_sprites.push_back(
                bn::sprite_items::ui_button_check_0.create_sprite(
                    -device::screen_width_half + draw_x_from + 8, -device::screen_height_half + yy));
            checkboxes_ptrs.push_back(static_text_sprites.back());
            add_menu_entry(-device::screen_width_half + draw_x_from + 16, -device::screen_height_half + yy,
                tl::menu_options_hdisabled(), 0);
            yy += y_spacing;

            add_menu_entry(-device::screen_width_half + draw_x_from + 16, -device::screen_height_half + yy,
                tl::menu_options_accessibility(), 1);
            yy += y_spacing;

            add_text_entry_bold(-device::screen_width_half + draw_x_from, -device::screen_height_half + yy,
                    tl::menu_options_sound(), -1);
            yy += y_spacing;

            static_text_sprites.push_back(
                bn::sprite_items::ui_thumbbar_l.create_sprite(
                    -device::screen_width_half + 32, -device::screen_height_half + yy));
            thumbbars_ptrs.push_back(static_text_sprites.back());
            static_text_sprites.push_back(
                bn::sprite_items::ui_thumbbar_r.create_sprite(
                    -device::screen_width_half + 96, -device::screen_height_half + yy));
            thumbbars_ptrs.push_back(static_text_sprites.back());
            static_text_sprites.push_back(
                bn::sprite_items::ui_bar_horizontal_thumb.create_sprite(
                    -device::screen_width_half + 16, -device::screen_height_half + yy));
            thumbs_ptrs.push_back(static_text_sprites.back());
            add_menu_entry(0, -device::screen_height_half + yy,
                tl::menu_options_music_volume(), 2);
            yy += y_spacing;

            static_text_sprites.push_back(
                bn::sprite_items::ui_thumbbar_l.create_sprite(
                    -device::screen_width_half + 32, -device::screen_height_half + yy));
            thumbbars_ptrs.push_back(static_text_sprites.back());
            static_text_sprites.push_back(
                bn::sprite_items::ui_thumbbar_r.create_sprite(
                    -device::screen_width_half + 96, -device::screen_height_half + yy));
            thumbbars_ptrs.push_back(static_text_sprites.back());
            static_text_sprites.push_back(
                bn::sprite_items::ui_bar_horizontal_thumb.create_sprite(
                    -device::screen_width_half + 16+96, -device::screen_height_half + yy));
            thumbs_ptrs.push_back(static_text_sprites.back());
            add_menu_entry(0, -device::screen_height_half + yy,
                tl::menu_options_sfx_volume(), 3);
            yy += y_spacing;

            text_generator->set_right_alignment();
            add_menu_entry(device::screen_width_half - draw_x_from, device::screen_height_half - 14,
                           tl::menu_back(), 4);
            need_repalette = true;
        }

        void on_repalette() override {
            if (selection == 2) {
                thumbbars_ptrs.at(0).set_palette(globals::text_palettes::beige_selected);
                thumbbars_ptrs.at(1).set_palette(globals::text_palettes::beige_selected);
                thumbs_ptrs.at(0).set_palette(globals::text_palettes::beige_selected);
            } else {
                thumbbars_ptrs.at(0).set_palette(globals::text_palettes::beige);
                thumbbars_ptrs.at(1).set_palette(globals::text_palettes::beige);
                thumbs_ptrs.at(0).set_palette(globals::text_palettes::beige);
            }

            if (selection == 3) {
                thumbbars_ptrs.at(2).set_palette(globals::text_palettes::beige_selected);
                thumbbars_ptrs.at(3).set_palette(globals::text_palettes::beige_selected);
                thumbs_ptrs.at(1).set_palette(globals::text_palettes::beige_selected);
            } else {
                thumbbars_ptrs.at(2).set_palette(globals::text_palettes::beige);
                thumbbars_ptrs.at(3).set_palette(globals::text_palettes::beige);
                thumbs_ptrs.at(1).set_palette(globals::text_palettes::beige);
            }
        }

        void on_navigate(const bool up, const bool down, const bool left, const bool right) override {
            MenuBase::on_navigate(up, down, left, right);
            if (selection == 2 && (left || right)) {
                if (right) {
                    globals::settings.music_volume = CLAMP(globals::settings.music_volume + 0x11, 0x00, 0xFF);
                } else {
                    globals::settings.music_volume = CLAMP(globals::settings.music_volume - 0x11, 0x00, 0xFF);
                }
                update_thumbbars();
            } else if (selection == 3 && (left || right)) {
                if (right) {
                    globals::settings.sfx_volume = CLAMP(globals::settings.sfx_volume + 0x11, 0x00, 0xFF);
                } else {
                    globals::settings.sfx_volume = CLAMP(globals::settings.sfx_volume - 0x11, 0x00, 0xFF);
                }
                ks::sound_manager::stop<SOUND_CHANNEL_SOUND>();
                ks::sound_manager::play<SOUND_CHANNEL_SOUND>("sfx_slide.8ad");
                update_thumbbars();
            }
        }

        void update_checkboxes() {
            checkboxes_ptrs.at(0).set_tiles(globals::settings.hdisabled
                                                ? bn::sprite_items::ui_button_check_1.tiles_item()
                                                : bn::sprite_items::ui_button_check_0.tiles_item());
        }

        void update_thumbbars() {
            thumbs_ptrs.at(0).set_position(
                -device::screen_width_half + 16 + bn::fixed(globals::settings.music_volume).multiplication(96).division(255),
                thumbs_ptrs.at(0).position().y()
            );
            thumbs_ptrs.at(1).set_position(
                -device::screen_width_half + 16 + bn::fixed(globals::settings.sfx_volume).multiplication(96).division(255),
                thumbs_ptrs.at(1).position().y()
            );
        }

    private:
        bn::vector<bn::sprite_ptr, 1> checkboxes_ptrs;
        bn::vector<bn::sprite_ptr, 4> thumbbars_ptrs;
        bn::vector<bn::sprite_ptr, 2> thumbs_ptrs;
    };
}

#endif //MENU_OPTIONS_CPP_H
