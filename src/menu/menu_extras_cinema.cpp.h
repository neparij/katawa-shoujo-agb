#ifndef MENU_EXTRAS_CINEMA_CPP_H
#define MENU_EXTRAS_CINEMA_CPP_H

#include <bn_bgs_mosaic_actions.h>
#include <bn_bg_palette_actions.h>
#include <bn_bg_palette_ptr.h>
#include <bn_format.h>
#include <bn_regular_bg_items_ui_bg_menu_extras_cinema.h>
#include <bn_regular_bg_items_ui_test_paldraw_b.h>
#include <bn_sprite_items_ui_tn_op_1.h>
#include <bn_sprite_items_ui_tn_op_1_bw.h>
#include <bn_sprite_items_ui_tn_tc_act2_emi.h>
#include <bn_sprite_items_ui_tn_tc_act2_emi_bw.h>
#include <bn_sprite_items_ui_tn_tc_act2_hanako.h>
#include <bn_sprite_items_ui_tn_tc_act2_hanako_bw.h>
#include <bn_sprite_items_ui_tn_tc_act2_lilly.h>
#include <bn_sprite_items_ui_tn_tc_act2_lilly_bw.h>
#include <bn_sprite_items_ui_tn_tc_act2_rin.h>
#include <bn_sprite_items_ui_tn_tc_act2_rin_bw.h>
#include <bn_sprite_items_ui_tn_tc_act2_shizu.h>
#include <bn_sprite_items_ui_tn_tc_act2_shizu_bw.h>
#include <video_op_1_dxtv.h>
#include <video_tc_act2_emi_dxtv.h>
#include <video_tc_act2_hanako_dxtv.h>
#include <video_tc_act2_lilly_dxtv.h>
#include <video_tc_act2_rin_dxtv.h>
#include <video_tc_act2_shizune_dxtv.h>

#include "menu_base.h"

namespace ks {
    class MenuExtrasCinema final : public MenuBase {
    public:
        explicit MenuExtrasCinema() {
            draw();
            show_selected();
            text_item_palette = globals::text_palettes::beige;
            items_count = 7;
        }

        ~MenuExtrasCinema() override {
        }

        void on_back() override {
            globals::state = GS_MENU_EXTRAS;
            menu::set_initial_selection(3);
        }

        void on_navigate(const bool up, const bool down, const bool left, const bool right) override {
            if (down) {
                selection += 3;
                selection = bn::min(selection, 6);
            }
            if (up) {
                if (selection == 6) {
                    selection = 5;
                } else if (selection >= 3) {
                    selection -= 3;
                }
            }
            if (left || right) {
                if (selection != 6) {
                    selection += right
                                     ? (selection % 3 != 2)
                                           ? 1
                                           : 0
                                     : (selection % 3 != 0)
                                           ? -1
                                           : 0;
                    selection = bn::min(5, selection);
                    selection = bn::max(0, selection);
                }
            }

            need_repalette = true;
            show_selected();
        }

        void on_select(const int option) override {
            if (option == 6) {
                on_back();
            } else {
                if (option == 0) {
                    SceneManager::show_video(video_op_1_dxtv, video_op_1_dxtv_size, "video_op_1.ulc",
                                             globals::colors::BLACK);
                } else if (option == 1) {
                    SceneManager::show_video(video_tc_act2_emi_dxtv, video_tc_act2_emi_dxtv_size,
                                             "video_tc_act2_emi.ulc", globals::colors::WHITE);
                } else if (option == 2) {
                    SceneManager::show_video(video_tc_act2_hanako_dxtv, video_tc_act2_hanako_dxtv_size,
                                             "video_tc_act2_hanako.ulc", globals::colors::WHITE);
                } else if (option == 3) {
                    SceneManager::show_video(video_tc_act2_lilly_dxtv, video_tc_act2_lilly_dxtv_size,
                                             "video_tc_act2_lilly.ulc", globals::colors::WHITE);
                } else if (option == 4) {
                    SceneManager::show_video(video_tc_act2_rin_dxtv, video_tc_act2_rin_dxtv_size,
                                             "video_tc_act2_rin.ulc", globals::colors::WHITE);
                } else if (option == 5) {
                    SceneManager::show_video(video_tc_act2_shizune_dxtv, video_tc_act2_shizune_dxtv_size,
                                             "video_tc_act2_shizune.ulc", globals::colors::WHITE);
                }

                // TODO: see src/temp/test_videopal_draw.cpp.h

                sound_manager::play(MUSIC_MENUS);
                draw();
                need_repalette = true;
                show_selected();
            }
        }

        void draw() {
            primary_background = bn::regular_bg_items::ui_bg_menu_extras_cinema.create_bg(0, 0);

            static_text_sprites.clear();
            progress_icon_sprites.clear();
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_center_alignment();

            text_generator_bold->set_one_sprite_per_character(false);
            text_generator_bold->set_left_alignment();

            add_text_entry_bold(-device::screen_width_half + 10, -device::screen_height_half + 14,
                    bn::format<64>("{} > {}", globals::i18n->menu_extras(), globals::i18n->menu_extras_cinema()), -1);

            add_menu_entry(globals::i18n->menu_extras_return_xoffset() + 90,
                           device::screen_height_half - 14, globals::i18n->menu_back(), 6);

            progress_icon_sprites.push_back(
                bn::sprite_items::ui_tn_op_1_bw.create_sprite(-76 + (0 * 76), -32));
            progress_icon_sprites.push_back(
                bn::sprite_items::ui_tn_tc_act2_emi_bw.create_sprite(-76 + (1 * 76), -32));
            progress_icon_sprites.push_back(
                bn::sprite_items::ui_tn_tc_act2_hanako_bw.create_sprite(-76 + (2 * 76), -32));
            progress_icon_sprites.push_back(
                bn::sprite_items::ui_tn_tc_act2_lilly_bw.create_sprite(-76 + (0 * 76), -32 + 64));
            progress_icon_sprites.push_back(
                bn::sprite_items::ui_tn_tc_act2_rin_bw.create_sprite(-76 + (1 * 76), -32 + 64));
            progress_icon_sprites.push_back(
                bn::sprite_items::ui_tn_tc_act2_shizu_bw.create_sprite(-76 + (2 * 76), -32 + 64));
        }

        void show_selected() const {
            if (progress_icon_sprites.size() > 6) {
                progress_icon_sprites.pop_back();
            }

            if (selection < 6) {
                const int x = -76 + (selection % 3) * 76;
                const int y = (selection < 3) ? -32 : -32 + 64;
                switch (selection) {
                    case 0:
                        progress_icon_sprites.push_back(
                            bn::sprite_items::ui_tn_op_1.create_sprite(x, y));
                        break;
                    case 1:
                        progress_icon_sprites.push_back(
                            bn::sprite_items::ui_tn_tc_act2_emi.create_sprite(x, y));
                        break;
                    case 2:
                        progress_icon_sprites.push_back(
                            bn::sprite_items::ui_tn_tc_act2_hanako.create_sprite(x, y));
                        break;
                    case 3:
                        progress_icon_sprites.push_back(
                            bn::sprite_items::ui_tn_tc_act2_lilly.create_sprite(x, y));
                        break;
                    case 4:
                        progress_icon_sprites.push_back(
                            bn::sprite_items::ui_tn_tc_act2_rin.create_sprite(x, y));
                        break;
                    case 5:
                        progress_icon_sprites.push_back(
                            bn::sprite_items::ui_tn_tc_act2_shizu.create_sprite(x, y));
                        break;
                    default:
                        break;
                }
            }
        }
    };
}

#endif //MENU_EXTRAS_CINEMA_CPP_H
