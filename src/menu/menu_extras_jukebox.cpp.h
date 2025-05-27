#ifndef MENU_EXTRAS_JUKEBOX_CPP_H
#define MENU_EXTRAS_JUKEBOX_CPP_H

#include <bn_format.h>
#include <bn_regular_bg_items_ui_bg_menu_inner.h>
#include "menu_base.h"
#include "../scenemanager.h"
#include "../sound/sound_mixer.h"


namespace ks {
    class MenuExtrasJukebox final : public MenuBase {
    public:
        explicit MenuExtrasJukebox() {
            primary_background = bn::regular_bg_items::ui_bg_menu_inner.create_bg(0, 0);

            static_text_sprites.clear();
            animated_text_sprites.clear();
            progress_icon_sprites.clear();
            globals::main_update();

            text_item_palette = globals::text_palettes::beige;
            total_tracks = 38;
            tracks_from_cursor = 1;
            draw(tracks_from_cursor);

            // for (int i = 0; i < 39; i++) {
            //     const auto& track = globals::i18n->music(i);
            //     BN_LOG("Music entry [", i, "]: ", track);
            //     // add_menu_entry_small(-device::screen_width_half + 14, -device::screen_height_half + 14 + 16 + (i * 8),
            //                          // bn::format<64>("{}: {}", i + 1, track), i);
            // }
        }

        ~MenuExtrasJukebox() override {
        }

        void on_back() override {
            globals::state = GS_MENU_EXTRAS;
            menu::set_initial_selection(0);
        }

        void on_select(const int option) override {
            if (option == 6) {
                on_back();
            } else {
                const unsigned short track_id = tracks_from_cursor + option;
                sound_manager::play(static_cast<music_t>(track_id));
                draw(tracks_from_cursor);
            }
        }

        void draw(const unsigned short from) {
            static_text_sprites.clear();
            text_generator->set_one_sprite_per_character(false);
            text_generator->set_left_alignment();
            text_generator_small->set_one_sprite_per_character(false);
            text_generator_small->set_left_alignment();
            text_generator_bold->set_one_sprite_per_character(false);
            text_generator_bold->set_left_alignment();

            add_text_entry_bold(-device::screen_width_half + 14, -device::screen_height_half + 14,
                                bn::format<64>("{} > {}", globals::i18n->menu_extras(),
                                               globals::i18n->menu_extras_jukebox()), -1);

            add_text_entry_small(-device::screen_width_half + 14, -device::screen_height_half + 14 +16,
                    bn::format<64>("{}: {}", globals::i18n->screens_now_playing(), globals::i18n->music(sound_manager::current_music))
                );

            unsigned short idx = 0;
            for (int i = from; i < from + 6; i++, idx++) {
                if (i > total_tracks) {
                    break;
                }
                const auto &track = globals::i18n->music(i);
                add_menu_entry(-device::screen_width_half + 14,
                               -device::screen_height_half + 14 + 32 + (idx * 16),
                               track,
                               idx);
            }

            text_generator->set_right_alignment();
            add_menu_entry(device::screen_width_half - 10,
                           device::screen_height_half - 14, globals::i18n->menu_back(), 6);

            need_repalette = true;
        }

        void on_navigate(const bool up, const bool down, const bool left, const bool right) override {
            if (up) {
                if (selection > 0) {
                    selection--;
                } else {
                    if (tracks_from_cursor > 1) {
                        tracks_from_cursor--;
                        draw(tracks_from_cursor);
                    }
                }
            } else if (down) {
                if (selection < 5) {
                    selection++;
                } else {
                    if (tracks_from_cursor + 5 < total_tracks) {
                        tracks_from_cursor++;
                        draw(tracks_from_cursor);
                    } else if (selection == 5) {
                        selection = 6; // Back button
                    }
                }
            }
            need_repalette = true;
        }

    private:
        unsigned short total_tracks, tracks_from_cursor;
    };
}

#endif //MENU_EXTRAS_JUKEBOX_CPP_H
