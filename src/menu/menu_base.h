#ifndef MENU_BASE_H
#define MENU_BASE_H

#include "../globals.h"

namespace ks {

    namespace menu {
        constexpr unsigned char NAVIGATION_COOLDOWN = 15;
        constexpr unsigned char NAVIGATION_COOLDOWN_FIRST = 30;
        inline int _initial_selection = 0;
        inline int _navigation_timer = 0;
        static void set_initial_selection(const int selection) {
            BN_LOG("Set initial select to: ", selection);
            _initial_selection = selection;
        }
        static int get_and_reset_initial_selection() {
            BN_LOG("Get initial selection (", _initial_selection, ") and reset it");
            const int selection = _initial_selection;
            _initial_selection = 0;
            return selection;
        }
    }
    class MenuBase
    {
    public:
        explicit MenuBase() : initial_state(globals::state) {
            selection = menu::get_and_reset_initial_selection();
            selection_indexes.clear();
            need_fadein = bn::bg_palettes::fade_intensity() == 1;
            text_generator->set_one_sprite_per_character(false);
            text_generator->set_left_alignment();
            text_generator->set_bg_priority(1);
            text_generator_bold->set_one_sprite_per_character(false);
            text_generator_bold->set_left_alignment();
            text_generator_bold->set_bg_priority(1);
            text_generator_small->set_one_sprite_per_character(false);
            text_generator_small->set_left_alignment();
            text_generator_small->set_bg_priority(1);
        }
        virtual ~MenuBase() {
            // text_generator->set_bg_priority(3);
            // text_generator_bold->set_bg_priority(3);

            text_generator->set_bg_priority(1);
            text_generator_bold->set_bg_priority(1);
            text_generator_small->set_bg_priority(1);
        }

        virtual void run() {
            while (globals::state == initial_state && !break_run_loop) {
                update();
                if (bn::keypad::b_pressed()) {
                    on_back();
                }
                else if (bn::keypad::a_pressed()) {
                    on_select(selection);
                }
                else if (menu::_navigation_timer == 0 && (bn::keypad::up_held() || bn::keypad::down_held() || bn::keypad::left_held() || bn::keypad::right_held())) {
                    if (bn::keypad::any_pressed()) {
                        menu::_navigation_timer = menu::NAVIGATION_COOLDOWN_FIRST;
                    } else {
                        menu::_navigation_timer = menu::NAVIGATION_COOLDOWN;
                    }
                    on_navigate(bn::keypad::up_held(), bn::keypad::down_held(), bn::keypad::left_held(), bn::keypad::right_held());
                }
                if (bn::keypad::any_released()) {
                    menu::_navigation_timer = 0;
                }

                if (need_repalette) {
                    repalette();
                }
                if (need_fadein) {
                    fadein();
                }
                globals::main_update();
            }
        }

        void update() {
            if (menu::_navigation_timer > 0) {
                menu::_navigation_timer--;
            }
            on_update();
        }

        virtual void on_navigate(const bool up, const bool down, const bool left, const bool right) {
            if (up || down) {
                selection += up ? -1 : 1;
                selection += items_count;
                selection = selection % items_count;

                need_repalette = true;
            }
        }

        virtual void on_select(const int option) {

        }

        virtual void on_back() {

        }

        virtual void on_update() {

        }

        virtual void on_repalette() {

        }

        void restart() {
            break_run_loop = true;
        }

        void set_selection(const int select) {
            selection = select;
            need_repalette = true;
        }

        void repalette() {
            need_repalette = false;

            if (static_text_sprites.size() == 0) return;

            BN_LOG("Repalette menu");
            for (int i = 0; i < static_text_sprites.size(); i++) {
                const bool is_selected = selection_indexes.at(i) == selection;
                if (const bool is_action = selection_indexes.at(i) != -1; !is_action) {
                    static_text_sprites.at(i).set_palette(text_item_palette);
                } else {
                    static_text_sprites.at(i).set_palette(is_selected ? globals::text_palettes::beige_selected : globals::text_palettes::beige);
                }
            }

            on_repalette();
        }

        void fadein() {
            need_fadein = false;
            SceneManager::fade_in(globals::colors::BLACK);
        }


        void add_text_entry(const bn::fixed x, const bn::fixed y, const bn::string_view& text, const int index) {
            BN_LOG("Add entry: ", text);
            BN_LOG("at position: [", x, ", ", y, "] with index: ", index);
            text_generator->generate(x, y, text, static_text_sprites);
            selection_indexes.resize(static_text_sprites.size(), index);
        }

        void add_text_entry_bold(const bn::fixed x, const bn::fixed y, const bn::string_view& text, const int index) {
            BN_LOG("Add entry: ", text);
            BN_LOG("at position: [", x, ", ", y, "] with index: ", index);
            text_generator_bold->generate(x, y, text, static_text_sprites);
            selection_indexes.resize(static_text_sprites.size(), index);
        }

        void add_text_entry_small(const bn::fixed x, const bn::fixed y, const bn::string_view& text, const int index) {
            BN_LOG("Add entry: ", text);
            BN_LOG("at position: [", x, ", ", y, "] with index: ", index);
            text_generator_small->generate(x, y, text, static_text_sprites);
            selection_indexes.resize(static_text_sprites.size(), index);
        }

        void add_text_entry(const bn::fixed x, const bn::fixed y, const bn::string_view& text) {
            add_text_entry(x, y, text, -1);
        }

        void add_text_entry_bold(const bn::fixed x, const bn::fixed y, const bn::string_view& text) {
            add_text_entry_bold(x, y, text, -1);
        }

        void add_text_entry_small(const bn::fixed x, const bn::fixed y, const bn::string_view& text) {
            add_text_entry_small(x, y, text, -1);
        }

        void add_menu_entry(const bn::fixed x, const bn::fixed y, const bn::string_view& text, const int index) {
            if (selection_indexes.empty() || index != selection_indexes.back()) {
                items_count++;
            }
            add_text_entry(x, y, text, index);
        }

        void add_menu_entry_bold(const bn::fixed x, const bn::fixed y, const bn::string_view& text, const int index) {
            if (selection_indexes.empty() || index != selection_indexes.back()) {
                items_count++;
            }
            add_text_entry_bold(x, y, text, index);
        }

        void add_menu_entry_small(const bn::fixed x, const bn::fixed y, const bn::string_view& text, const int index) {
            if (selection_indexes.empty() || index != selection_indexes.back()) {
                items_count++;
            }
            add_text_entry_small(x, y, text, index);
        }

        void fade_out() {
            ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_MUSIC>(30);
            ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_SOUND>(30);
            ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_AMBIENT>(30);
            ks::SceneManager::fade_out(ks::globals::colors::BLACK, 30);
        }

    protected:
        bn::vector<signed char, 64> selection_indexes;
        bn::sprite_palette_item text_item_palette = globals::text_palettes::beige_selected;
        int selection = 0;
        int items_count = 0;
        bool need_repalette = true;
        bool need_fadein = false;
        bool break_run_loop = false;
        gameState_t initial_state;

    };
}

#endif //MENU_BASE_H
