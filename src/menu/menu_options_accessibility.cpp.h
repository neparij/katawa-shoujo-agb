#ifndef MENU_OPTIONS_ACCESSIBILITY_CPP_H
#define MENU_OPTIONS_ACCESSIBILITY_CPP_H

#include <bn_format.h>
#include <bn_regular_bg_items_ui_bg_menu_inner.h>
#include <bn_sprite_items_ui_button_check_0.h>
#include <bn_sprite_items_ui_button_check_1.h>
#include <bn_sprite_items_ui_thumbbar_l.h>
#include <bn_sprite_items_ui_thumbbar_r.h>
#include <bn_sprite_items_ui_bar_horizontal_thumb.h>

#include "menu_base.h"
#include "definitions.h"

namespace ks {
    class MenuOptionsAccessibility final : public MenuBase {
    public:
        explicit MenuOptionsAccessibility() {
            static_text_sprites.clear();
            background_visual.visible_bg_item.reset();
            primary_background.reset();
            primary_background = bn::regular_bg_items::ui_bg_menu_inner.create_bg(0, 0);

            text_item_palette = globals::text_palettes::beige;
            create();
            update_checkboxes();
            update_thumbbars();
        }

        ~MenuOptionsAccessibility() override {
        }

        void on_back() override {
            if (globals::state == GS_GAME_MENU_OPTIONS_ACCESSIBILITY) {
                globals::state = GS_GAME_MENU_OPTIONS;
                menu::set_initial_selection(2);
            } else {
                globals::state = GS_MENU_OPTIONS;
                menu::set_initial_selection(2);
            }
        }

        void on_select(const int option) override {
            switch (option) {
                case 0:
                case 1:
                    break;
                case 2:
                    globals::settings.high_contrast = !globals::settings.high_contrast;
                    globals::accessibility_apply();
                    update_checkboxes();
                    break;
                case 3:
                    globals::settings.disable_disturbing_content = !globals::settings.disable_disturbing_content;
                    update_checkboxes();
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
                    bn::format<64>("{} > {}", globals::i18n->menu_options(), globals::i18n->menu_accessibility()), -1);
            yy += y_spacing + 4;

            add_text_entry_bold(-device::screen_width_half + draw_x_from, -device::screen_height_half + yy,
                    globals::i18n->menu_options_accessibility_display(), -1);
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
                globals::i18n->menu_options_accessibility_text_speed(), 0);
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
                globals::i18n->menu_options_accessibility_brightness(), 1);
            yy += y_spacing;

            static_text_sprites.push_back(
                bn::sprite_items::ui_button_check_0.create_sprite(
                    -device::screen_width_half + draw_x_from + 8, -device::screen_height_half + yy));
            checkboxes_ptrs.push_back(static_text_sprites.back());
            add_menu_entry(-device::screen_width_half + draw_x_from + 16, -device::screen_height_half + yy,
                globals::i18n->menu_options_accessibility_high_contrast(), 2);
            yy += y_spacing + 4;

            add_text_entry_bold(-device::screen_width_half + draw_x_from, -device::screen_height_half + yy,
                    globals::i18n->menu_options_accessibility_mental(), -1);
            yy += y_spacing;

            static_text_sprites.push_back(
                bn::sprite_items::ui_button_check_0.create_sprite(-device::screen_width_half + draw_x_from + 8,
                                                                  -device::screen_height_half + yy));
            checkboxes_ptrs.push_back(static_text_sprites.back());
            for (auto disturbing_option_arr = globals::i18n->menu_options_accessibility_disable_disturbing_content();
                 const char *line: disturbing_option_arr) {
                if (line != nullptr) {
                    add_menu_entry(-device::screen_width_half + draw_x_from + 16, -device::screen_height_half + yy,
                                   line, 3);
                    if (globals::settings.language == LANG_JAPAN) {
                        yy += 13;
                    } else {
                        yy += 10;
                    }

                } else {
                    yy += y_spacing - 10;
                    break;
                }
            }

            text_generator->set_right_alignment();
            add_menu_entry(device::screen_width_half - draw_x_from, device::screen_height_half - 14,
                           globals::i18n->menu_back(), 4);
            need_repalette = true;
        }

        void on_repalette() override {
            if (selection == 0) {
                thumbbars_ptrs.at(0).set_palette(globals::text_palettes::beige_selected);
                thumbbars_ptrs.at(1).set_palette(globals::text_palettes::beige_selected);
                thumbs_ptrs.at(0).set_palette(globals::text_palettes::beige_selected);
            } else {
                thumbbars_ptrs.at(0).set_palette(globals::text_palettes::beige);
                thumbbars_ptrs.at(1).set_palette(globals::text_palettes::beige);
                thumbs_ptrs.at(0).set_palette(globals::text_palettes::beige);
            }

            if (selection == 1) {
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
            if (selection == 0 && (left || right)) {
                if (right) {
                    globals::settings.text_speed = CLAMP(globals::settings.text_speed + 0x11, 0x00, 0xFF);
                } else {
                    globals::settings.text_speed = CLAMP(globals::settings.text_speed - 0x11, 0x00, 0xFF);
                }
                update_thumbbars();
            } else if (selection == 1 && (left || right)) {
                if (right) {
                    globals::settings.brightness = CLAMP(globals::settings.brightness + 0x11, 0x00, 0xFF);
                } else {
                    globals::settings.brightness = CLAMP(globals::settings.brightness - 0x11, 0x00, 0xFF);
                }
                globals::accessibility_apply();
                update_thumbbars();
            }
        }

        void update_checkboxes() {
            checkboxes_ptrs.at(0).set_tiles(globals::settings.high_contrast
                                                ? bn::sprite_items::ui_button_check_1.tiles_item()
                                                : bn::sprite_items::ui_button_check_0.tiles_item());
            checkboxes_ptrs.at(1).set_tiles(globals::settings.disable_disturbing_content
                                                ? bn::sprite_items::ui_button_check_1.tiles_item()
                                                : bn::sprite_items::ui_button_check_0.tiles_item());
        }

        void update_thumbbars() {
            thumbs_ptrs.at(0).set_position(
                -device::screen_width_half + 16 + bn::fixed(globals::settings.text_speed).multiplication(96).division(255),
                thumbs_ptrs.at(0).position().y()
            );
            thumbs_ptrs.at(1).set_position(
                -device::screen_width_half + 16 + bn::fixed(globals::settings.brightness).multiplication(96).division(255),
                thumbs_ptrs.at(1).position().y()
            );
        }

    private:
        bn::vector<bn::sprite_ptr, 2> checkboxes_ptrs;
        bn::vector<bn::sprite_ptr, 4> thumbbars_ptrs;
        bn::vector<bn::sprite_ptr, 2> thumbs_ptrs;
    };
}

#endif //MENU_OPTIONS_ACCESSIBILITY_CPP_H
