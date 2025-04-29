#ifndef MENU_EXTRAS_CPP_H
#define MENU_EXTRAS_CPP_H

#include <bn_regular_bg_items_ui_bg_menu_extras.h>
#include <bn_regular_bg_items_ui_bg_menu_extras_emi.h>
#include <bn_regular_bg_items_ui_bg_menu_extras_hanako.h>
#include <bn_regular_bg_items_ui_bg_menu_extras_lilly.h>
#include <bn_regular_bg_items_ui_bg_menu_extras_rin.h>
#include <bn_regular_bg_items_ui_bg_menu_extras_shizu.h>

#include "menu_base.h"

namespace ks {
    class MenuExtras final : public MenuBase {
    public:
        explicit MenuExtras() {
            primary_background = bn::regular_bg_items::ui_bg_menu_extras.create_bg(0, 0);

            secondary_background.reset();
            static_text_sprites.clear();
            progress_icon_sprites.clear();
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_center_alignment();
            add_menu_entry(globals::i18n->menu_extras_jukebox_xoffset() - 90, 0,
                           globals::i18n->menu_extras_jukebox(), 0);

            add_menu_entry(globals::i18n->menu_extras_gallery_xoffset() - 30, 0,
                           globals::i18n->menu_extras_gallery(), 1);

            add_menu_entry(globals::i18n->menu_extras_library_xoffset() + 30, 0,
                           globals::i18n->menu_extras_library(), 2);

            add_menu_entry(globals::i18n->menu_extras_cinema_xoffset() + 90, 0,
                           globals::i18n->menu_extras_cinema(), 3);

            add_menu_entry(globals::i18n->menu_extras_return_xoffset() + 90,
                           device::screen_height_half - 14,
                           globals::i18n->menu_back(), 4);

            show_selected();
        }

        ~MenuExtras() override {
            secondary_background.reset();
        }

        void on_back() override {
            globals::state = GS_MENU_MAIN;
            menu::set_initial_selection(2);
        }

        void on_select(const int option) override {
            switch (option) {
                case 3:
                    globals::state = GS_MENU_EXTRAS_CINEMA;
                    break;
                case 4:
                    on_back();
                    break;
                default:
                    BN_ERROR("Menu option is not implemented.");
            }
        }

        void on_navigate(const bool up, const bool down, const bool left, const bool right) override {
            if (selection != 4 && down) {
                selection = 4;
                show_selected();
            } else if (selection == 4 && up) {
                selection = 3;
                show_selected();
            } else {
                if (selection != 4) {
                    selection += right ? 1 : -1;
                    selection = bn::min(3, selection);
                    selection = bn::max(0, selection);
                    show_selected();
                }
            }

            need_repalette = true;
        }

        void show_selected() const {
            secondary_background.reset();

            if (selection == 0) {
                secondary_background = bn::regular_bg_items::ui_bg_menu_extras_lilly.create_bg(0, 0);
            } else if (selection == 1) {
                secondary_background = bn::regular_bg_items::ui_bg_menu_extras_rin.create_bg(0, 0);
            } else if (selection == 2) {
                secondary_background = bn::regular_bg_items::ui_bg_menu_extras_shizu.create_bg(0, 0);
            } else if (selection == 3) {
                secondary_background = bn::regular_bg_items::ui_bg_menu_extras_emi.create_bg(0, 0);
            } else if (selection == 4) {
                secondary_background = bn::regular_bg_items::ui_bg_menu_extras_hanako.create_bg(0, 0);
            }

            secondary_background->set_priority(2);
        }
    };
}

#endif //MENU_EXTRAS_CPP_H
