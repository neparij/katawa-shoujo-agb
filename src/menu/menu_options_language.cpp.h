#ifndef MENU_OPTIONS_LANGUAGE_CPP_H
#define MENU_OPTIONS_LANGUAGE_CPP_H

#include <bn_format.h>
#include <bn_regular_bg_items_ui_bg_menu_language.h>
#include <bn_sprite_items_ui_button_check_0.h>
#include <bn_sprite_items_ui_button_check_1.h>
#include <bn_sprite_items_ui_thumbbar_l.h>
#include <bn_sprite_items_ui_thumbbar_r.h>
#include <bn_sprite_items_ui_bar_horizontal_thumb.h>

#include "menu_base.h"
#include "definitions.h"
#include "../utils/scenario_reader.h"

namespace ks {
    class MenuOptionsLanguage final : public MenuBase {
    public:
        explicit MenuOptionsLanguage() {
            static_text_sprites.clear();
            primary_background.reset();
            primary_background = bn::regular_bg_items::ui_bg_menu_language.create_bg(0, 0);

            text_item_palette = globals::text_palettes::beige;
            create();
        }

        ~MenuOptionsLanguage() override {
        }

        void on_back() override {
            if (globals::state == GS_GAME_MENU_OPTIONS_LANGUAGE) {
                globals::state = GS_GAME_MENU_OPTIONS;
                menu::set_initial_selection(1);
                BN_LOG("Reload SceneManager TextDB with locale: ", globals::i18n->locale());
                SceneManager::reload_textdb();
            } else {
                globals::state = GS_MENU_OPTIONS;
                menu::set_initial_selection(1);
            }
        }

        void on_select(const int option) override {
            switch (option) {
                case 0:
                    globals::set_language(LANG_ENGLISH);
                    break;
                case 1:
                    globals::set_language(LANG_RUSSIAN);
                    break;
                case 2:
                    globals::set_language(LANG_SPANISH);
                    break;
                case 3:
                    globals::set_language(LANG_JAPAN);
                    break;
                default:
                    BN_ERROR("Language is not implemented");
            }
            // create();
            // repalette();
            on_back();
        }

        void create() {
            constexpr short draw_x_from = 50;
            selection_indexes.clear();
            items_count = 0;
            static_text_sprites.clear();
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_left_alignment();

            unsigned char yy = 23;
            constexpr unsigned char y_spacing = 14;

            add_text_entry_bold(-device::screen_width_half + draw_x_from, -device::screen_height_half + yy,
                    bn::format<64>("{} > {}", globals::i18n->menu_options(), globals::i18n->menu_language()), MENU_TEXT_NOT_AN_OPTION);
            yy += y_spacing;

            add_menu_entry(-device::screen_width_half + draw_x_from + 4, -device::screen_height_half + yy,
                globals::i18n->language_en(), 0);
            yy += y_spacing;

            add_menu_entry(-device::screen_width_half + draw_x_from + 4, -device::screen_height_half + yy,
                globals::i18n->language_ru(), 1);
            yy += y_spacing;

            add_text_entry(-device::screen_width_half + draw_x_from + 4, -device::screen_height_half + yy,
                globals::i18n->language_fr(), MENU_TEXT_DISABLED);
            yy += y_spacing;

            add_text_entry(-device::screen_width_half + draw_x_from + 4, -device::screen_height_half + yy,
                globals::i18n->language_it(), MENU_TEXT_DISABLED);
            yy += y_spacing;

            add_menu_entry(-device::screen_width_half + draw_x_from + 4, -device::screen_height_half + yy,
                globals::i18n->language_es(), 2);
            yy += y_spacing;

            add_text_entry(-device::screen_width_half + draw_x_from + 4, -device::screen_height_half + yy,
                globals::i18n->language_de(), MENU_TEXT_DISABLED);
            yy += y_spacing;

            add_menu_entry(-device::screen_width_half + draw_x_from + 4, -device::screen_height_half + yy,
                globals::i18n->language_jp(), 3);
            yy += y_spacing;

            add_text_entry(-device::screen_width_half + draw_x_from + 4, -device::screen_height_half + yy,
                globals::i18n->language_zh_hans(), MENU_TEXT_DISABLED);
            yy += y_spacing;

            need_repalette = true;
            switch (globals::settings.language) {
                case LANG_ENGLISH:
                    set_selection(0);
                    break;
                case LANG_RUSSIAN:
                    set_selection(1);
                    break;
                case LANG_FRENCH:
                    set_selection(0);
                    break;
                case LANG_ITALIAN:
                    set_selection(0);
                    break;
                case LANG_SPANISH:
                    set_selection(2);
                    break;
                case LANG_GERMAN:
                    set_selection(0);
                    break;
                case LANG_JAPAN:
                    set_selection(3);
                    break;
                case LANG_CHINESE_SIMPLIFIED:
                    set_selection(0);
                    break;
                default:
                    BN_LOG("Unknown language is set");
                    set_selection(0);
            }
        }
    };
}

#endif //MENU_OPTIONS_LANGUAGE_CPP_H
