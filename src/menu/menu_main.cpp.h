#ifndef MENU_MAIN_CPP_H
#define MENU_MAIN_CPP_H

#include <bn_regular_bg_items_ui_bg_menu_main.h>

#include "bn_sprite_items_ui_icon_00_tc1_hisao.h"
#include "bn_sprite_items_ui_icon_01_tc2_hanako.h"
#include "bn_sprite_items_ui_icon_02_tc3_hanako.h"
#include "bn_sprite_items_ui_icon_03_tc2_emi.h"
#include "bn_sprite_items_ui_icon_04_tc3_emi.h"
#include "bn_sprite_items_ui_icon_05_tc4_emi_1.h"
#include "bn_sprite_items_ui_icon_05_tc4_emi_2.h"
#include "bn_sprite_items_ui_icon_06_tc4_hanako.h"
#include "bn_sprite_items_ui_icon_07_tc2_lilly.h"
#include "bn_sprite_items_ui_icon_08_tc3_lilly.h"
#include "bn_sprite_items_ui_icon_09_tc4_lilly.h"
#include "bn_sprite_items_ui_icon_10_tc2_rin.h"
#include "bn_sprite_items_ui_icon_11_tc3_rin_hisao.h"
#include "bn_sprite_items_ui_icon_12_tc3_rin_rin.h"
#include "bn_sprite_items_ui_icon_13_tc4_rin.h"
#include "bn_sprite_items_ui_icon_14_tc2_shizune.h"
#include "bn_sprite_items_ui_icon_15_tc3_shizune.h"
#include "bn_sprite_items_ui_icon_16_tc4_shizune.h"


#include "menu_base.h"

namespace ks {
    class MenuMain final : public MenuBase {
    public:
        explicit MenuMain() {
            const bn::string<64> version(KS_AGB_VERSION);
            secondary_background.reset();
            primary_background = bn::regular_bg_items::ui_bg_menu_main.create_bg(0, 0);

            static_text_sprites.clear();
            progress_icon_sprites.clear();
            globals::main_update();

            draw_progress_icons();
            globals::main_update();

            add_text_entry_small(-device::screen_width_half + 4, device::screen_height_half - 6, version);

            add_menu_entry(-device::screen_width_half + 22, device::screen_height_half - 22 - (16 * 3),
                           globals::i18n->menu_start(), 0);
            add_menu_entry(-device::screen_width_half + 22, device::screen_height_half - 22 - (16 * 2),
                           globals::i18n->menu_saves(), 1);
            globals::sound_update();


            add_menu_entry(-device::screen_width_half + 22, device::screen_height_half - 22 - (16 * 1),
                           globals::i18n->menu_extras(), 2);
            add_menu_entry(-device::screen_width_half + 22, device::screen_height_half - 22 - (16 * 0),
                           globals::i18n->menu_options(), 3);
            globals::sound_update();
        }

        ~MenuMain() override {
        }

        void on_update() override {
            animate_progress_icons();
        }

        void on_back() override {
        }

        void on_select(const int option) override {
            switch (option) {
                case 0:
                    fade_out();
                    globals::state = GS_START_GAME;
                    break;
                case 1:
                    globals::state = GS_MENU_SAVES;
                    break;
                case 2:
                    globals::state = GS_MENU_EXTRAS;
                    break;
                case 3:
                    globals::state = GS_MENU_OPTIONS;
                    break;
                default:
                    BN_ERROR("Menu option is not implemented");
            }
        }

    private:
        bool icons_appearing = false;
        char icons_appeared = 0;
        bn::optional<bn::blending_transparency_alpha_to_action> transparency_action;
        bn::vector<bn::sprite_move_to_action, 2> move_to_actions;
        bn::vector<bn::sprite_ptr, 2> progress_icon_sprites_partial; // Used for combined sprites for progress icons

        void draw_progress_icons() {
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_16_tc4_shizune.create_sprite(111, 17));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_15_tc3_shizune.create_sprite(113, 42));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_14_tc2_shizune.create_sprite(93, 71));
            globals::sound_update();

            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_13_tc4_rin.create_sprite(62, -22));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_12_tc3_rin_rin.create_sprite(67, -8));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_11_tc3_rin_hisao.create_sprite(82, 13));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_10_tc2_rin.create_sprite(96, 48));
            globals::sound_update();

            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_09_tc4_lilly.create_sprite(29, -17));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_08_tc3_lilly.create_sprite(63, 8));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_07_tc2_lilly.create_sprite(65, 39));

            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_06_tc4_hanako.create_sprite(16, 8));
            globals::sound_update();

            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_05_tc4_emi_1.create_sprite(14, 37));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_05_tc4_emi_2.create_sprite(50, 42));
            progress_icon_sprites_partial.push_back(progress_icon_sprites.back());

            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_04_tc3_emi.create_sprite(32, 63));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_03_tc2_emi.create_sprite(37, 64));
            globals::sound_update();

            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_02_tc3_hanako.create_sprite(29, 19));
            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_01_tc2_hanako.create_sprite(52, 41));

            progress_icon_sprites.push_back(bn::sprite_items::ui_icon_00_tc1_hisao.create_sprite(71, 71));


            if (selection == 0) {
                for (auto &sprite: progress_icon_sprites) {
                    sprite.set_visible(false);
                }
                icons_appearing = true;
            }
        }

        void animate_progress_icons() {
            if (icons_appearing && icons_appeared < progress_icon_sprites.size()) {
                const int icon_index = progress_icon_sprites.size() - 1 - icons_appeared;
                auto &icon = progress_icon_sprites.at(icon_index);
                if (transparency_action.has_value() && move_to_actions.size() > 0) {
                    if (!transparency_action->done()) {
                        transparency_action->update();
                        for (auto &move_to_action: move_to_actions) {
                            if (!move_to_action.done()) {
                                move_to_action.update();
                            }
                        }
                    } else {
                        transparency_action.reset();
                        move_to_actions.clear();
                        icons_appeared++;
                        // for (unsigned char i = progress_icon_sprites.size() - 1; i >= icon_index; --i) {
                        //     progress_icon_sprites.at(i).set_blending_enabled(false);
                        // }
                        for (auto &sprite: progress_icon_sprites) {
                            sprite.set_blending_enabled(false);
                        }
                    }
                } else {
                    if (progress_icon_sprites_partial.size() != 0 && icon == progress_icon_sprites_partial.back()) {
                        icons_appeared++;
                        progress_icon_sprites_partial.pop_back();
                        animate_progress_icons();
                    } else {
                        bn::blending::set_transparency_alpha(0.0);
                        transparency_action = bn::blending_transparency_alpha_to_action(30, 1.0);

                        icon.set_y(icon.y() + 8);
                        move_to_actions.push_back(bn::sprite_move_to_action(icon,
                                                                             30,
                                                                             icon.position().x(),
                                                                             icon.position().y() - 8));
                    }

                    icon.set_blending_enabled(true);
                    icon.set_visible(true);
                }
            }
        }
    };
}

#endif //MENU_MAIN_CPP_H
