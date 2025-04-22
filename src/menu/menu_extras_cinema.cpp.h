#ifndef MENU_EXTRAS_CINEMA_CPP_H
#define MENU_EXTRAS_CINEMA_CPP_H

#include <bn_bgs_mosaic_actions.h>
#include <bn_bg_palette_actions.h>
#include <bn_bg_palette_ptr.h>
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
#include <video_op_1_agmv.h>
#include <video_tc_act2_emi_agmv.h>
#include <video_tc_act2_hanako_agmv.h>
#include <video_tc_act2_lilly_agmv.h>
#include <video_tc_act2_rin_agmv.h>
#include <video_tc_act2_shizune_agmv.h>

#include "menu_base.h"

namespace ks {
    class MenuExtrasCinema final : public MenuBase {
    public:
        explicit MenuExtrasCinema(gameState_t &state): MenuBase(state) {
            draw();
            show_selected();
            items_count = 7;
        }

        ~MenuExtrasCinema() override {
        }

        void on_back() override {
            state = GS_MENU_EXTRAS;
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
                ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
                ks::sound_manager::stop<SOUND_CHANNEL_SOUND>();
                ks::sound_manager::stop<SOUND_CHANNEL_AMBIENT>();

                if (option == 0) {
                    SceneManager::show_video(video_op_1_agmv, video_op_1_agmv_size, "video_op_1.gsm",
                                             globals::colors::BLACK);
                } else if (option == 1) {
                    SceneManager::show_video(video_tc_act2_emi_agmv, video_tc_act2_emi_agmv_size,
                                             "video_tc_act2_emi.gsm", globals::colors::WHITE);
                } else if (option == 2) {
                    SceneManager::show_video(video_tc_act2_hanako_agmv, video_tc_act2_hanako_agmv_size,
                                             "video_tc_act2_hanako.gsm", globals::colors::WHITE);
                } else if (option == 3) {
                    SceneManager::show_video(video_tc_act2_lilly_agmv, video_tc_act2_lilly_agmv_size,
                                             "video_tc_act2_lilly.gsm", globals::colors::WHITE);
                } else if (option == 4) {
                    SceneManager::show_video(video_tc_act2_rin_agmv, video_tc_act2_rin_agmv_size,
                                             "video_tc_act2_rin.gsm", globals::colors::WHITE);
                } else if (option == 5) {
                    SceneManager::show_video(video_tc_act2_shizune_agmv, video_tc_act2_shizune_agmv_size,
                                             "video_tc_act2_shizune.gsm", globals::colors::WHITE);
                }

                // TODO: see src/temp/test_videopal_draw.cpp.h

                sound_manager::play(MUSIC_MENUS);
                draw();
                need_repalette = true;
                show_selected();
            }
        }

        void draw() {
            main_background = bn::regular_bg_items::ui_bg_menu_extras_cinema.create_bg(0, 0);

            static_text_sprites->clear();
            progress_icon_sprites->clear();
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_center_alignment();
            add_menu_entry(globals::i18n->menu_extras_return_xoffset() + 90,
                           device::screen_height_half - 14, globals::i18n->menu_back(), 6);

            progress_icon_sprites->push_back(
                bn::sprite_items::ui_tn_op_1_bw.create_sprite(-76 + (0 * 76), -35));
            progress_icon_sprites->push_back(
                bn::sprite_items::ui_tn_tc_act2_emi_bw.create_sprite(-76 + (1 * 76), -35));
            progress_icon_sprites->push_back(
                bn::sprite_items::ui_tn_tc_act2_hanako_bw.create_sprite(-76 + (2 * 76), -35));
            progress_icon_sprites->push_back(
                bn::sprite_items::ui_tn_tc_act2_lilly_bw.create_sprite(-76 + (0 * 76), -35 + 64));
            progress_icon_sprites->push_back(
                bn::sprite_items::ui_tn_tc_act2_rin_bw.create_sprite(-76 + (1 * 76), -35 + 64));
            progress_icon_sprites->push_back(
                bn::sprite_items::ui_tn_tc_act2_shizu_bw.create_sprite(-76 + (2 * 76), -35 + 64));
        }

        void show_selected() const {
            if (progress_icon_sprites->size() > 6) {
                progress_icon_sprites->pop_back();
            }

            if (selection < 6) {
                const int x = -76 + (selection % 3) * 76;
                const int y = (selection < 3) ? -35 : -35 + 64;
                switch (selection) {
                    case 0:
                        progress_icon_sprites->push_back(
                            bn::sprite_items::ui_tn_op_1.create_sprite(x, y));
                        break;
                    case 1:
                        progress_icon_sprites->push_back(
                            bn::sprite_items::ui_tn_tc_act2_emi.create_sprite(x, y));
                        break;
                    case 2:
                        progress_icon_sprites->push_back(
                            bn::sprite_items::ui_tn_tc_act2_hanako.create_sprite(x, y));
                        break;
                    case 3:
                        progress_icon_sprites->push_back(
                            bn::sprite_items::ui_tn_tc_act2_lilly.create_sprite(x, y));
                        break;
                    case 4:
                        progress_icon_sprites->push_back(
                            bn::sprite_items::ui_tn_tc_act2_rin.create_sprite(x, y));
                        break;
                    case 5:
                        progress_icon_sprites->push_back(
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
