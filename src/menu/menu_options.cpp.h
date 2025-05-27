#ifndef MENU_OPTIONS_CPP_H
#define MENU_OPTIONS_CPP_H

#include <bn_format.h>
#include <bn_regular_bg_items_ui_bg_menu.h>
#include <bn_sprite_items_ui_button_check_0.h>
#include <bn_sprite_items_ui_button_check_1.h>

#include "menu_base.h"

namespace ks {
    class MenuOptions final : public MenuBase {
    public:
        explicit MenuOptions() {
            primary_background = bn::regular_bg_items::ui_bg_menu.create_bg(0, 0);

            create();
            update_checkboxes();
        }

        ~MenuOptions() override {
        }

        void on_back() override {
            writeSettings(globals::settings);
            globals::state = GS_MENU_MAIN;
            menu::set_initial_selection(3);
        }

        void on_select(const int option) override {
            switch (option) {
                case 0:
                    globals::settings.high_contrast = !globals::settings.high_contrast;
                    globals::accessibility_apply();
                    update_checkboxes();
                    break;
                case 1:
                    globals::settings.hdisabled = !globals::settings.hdisabled;
                    update_checkboxes();
                    break;
                case 2:
                    globals::settings.disable_disturbing_content = !globals::settings.
                            disable_disturbing_content;
                    update_checkboxes();
                    break;
                case 3:
                    if (globals::i18n->type() == LANG_ENGLISH) {
                        globals::set_language(LANG_RUSSIAN);
                    } else if (globals::i18n->type() == LANG_RUSSIAN) {
                        globals::set_language(LANG_ENGLISH);
                    } else {
                        BN_ERROR("Unkown language was selected");
                    }
                    create();
                    repalette();
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
            selection_indexes.clear();
            checkboxes_ptrs.clear();

            static_text_sprites.clear();
            progress_icon_sprites.clear();
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_left_alignment();

            unsigned char yy = 0;
            constexpr unsigned char y_spacing = 16;
            static_text_sprites.push_back(
                bn::sprite_items::ui_button_check_0.create_sprite(-device::screen_width_half + 30, -48 + yy));
            checkboxes_ptrs.push_back(static_text_sprites.back());
            add_menu_entry(-device::screen_width_half + 22 + 16, -48 + yy, globals::i18n->menu_options_high_contrast(),
                           0);
            yy += y_spacing;

            static_text_sprites.push_back(
                bn::sprite_items::ui_button_check_0.create_sprite(-device::screen_width_half + 30, -48 + yy));
            checkboxes_ptrs.push_back(static_text_sprites.back());
            add_menu_entry(-device::screen_width_half + 22 + 16, -48 + yy, globals::i18n->menu_options_hdisabled(), 1);
            yy += y_spacing;

            static_text_sprites.push_back(
                bn::sprite_items::ui_button_check_0.create_sprite(-device::screen_width_half + 30, -48 + yy));
            checkboxes_ptrs.push_back(static_text_sprites.back());
            auto disturbing_option_arr = globals::i18n->menu_options_disable_disturbing_content();
            BN_LOG("SZ: ", disturbing_option_arr.size());
            for (const char *line: disturbing_option_arr) {
                if (line != nullptr) {
                    add_menu_entry(-device::screen_width_half + 22 + 16, -48 + yy, line, 2);
                    yy += 10;
                } else {
                    yy += y_spacing - 10;
                    break;
                }
            }

            add_menu_entry(-device::screen_width_half + 22, -48 + yy,
                           bn::format<64>("{}: {}", globals::i18n->menu_options_language(),
                                          globals::i18n->language()),
                           3);
            yy += y_spacing;

            add_menu_entry(-device::screen_width_half + 22, device::screen_height_half - 22,
                           globals::i18n->menu_back(), 4);
        }

        void update_checkboxes() {
            checkboxes_ptrs.at(0).set_tiles(globals::settings.high_contrast
                                                ? bn::sprite_items::ui_button_check_1.tiles_item()
                                                : bn::sprite_items::ui_button_check_0.tiles_item());
            checkboxes_ptrs.at(1).set_tiles(globals::settings.hdisabled
                                                ? bn::sprite_items::ui_button_check_1.tiles_item()
                                                : bn::sprite_items::ui_button_check_0.tiles_item());
            checkboxes_ptrs.at(2).set_tiles(globals::settings.disable_disturbing_content
                                                ? bn::sprite_items::ui_button_check_1.tiles_item()
                                                : bn::sprite_items::ui_button_check_0.tiles_item());
        }

    private:
        bn::vector<bn::sprite_ptr, 8> checkboxes_ptrs;
    };
}

#endif //MENU_OPTIONS_CPP_H
