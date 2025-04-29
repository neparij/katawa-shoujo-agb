#ifndef MENU_BASE_H
#define MENU_BASE_H

#include "../globals.h"

namespace ks {

    namespace menu {
        static int _initial_selection = 0;
        static void set_initial_selection(const int selection) {
            _initial_selection = selection;
        }
        static int get_and_reset_initial_selection() {
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
            text_generator->set_bg_priority(1);
        }
        virtual ~MenuBase() {
            text_generator->set_bg_priority(3);
        }

        virtual void run() {
            while (globals::state == initial_state) {
                on_update();
                if (bn::keypad::b_pressed()) {
                    on_back();
                }
                else if (bn::keypad::a_pressed()) {
                    on_select(selection);
                }
                else if (bn::keypad::up_pressed() || bn::keypad::down_pressed() || bn::keypad::left_pressed() || bn::keypad::right_pressed()) {
                    on_navigate(bn::keypad::up_pressed(), bn::keypad::down_pressed(), bn::keypad::left_pressed(), bn::keypad::right_pressed());
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

        void add_text_entry(const bn::fixed x, const bn::fixed y, const bn::string_view& text) {
            add_text_entry(x, y, text, -1);
        }

        void add_menu_entry(const bn::fixed x, const bn::fixed y, const bn::string_view& text, const int index) {
            if (selection_indexes.empty() || index != selection_indexes.back()) {
                items_count++;
            }
            add_text_entry(x, y, text, index);
        }

        void fade_out() {
            ks::sound_manager::set_fadeout_action<SOUND_CHANNEL_MUSIC>(30);
            ks::SceneManager::fade_out(ks::globals::colors::BLACK);
        }

    protected:
        bn::vector<signed char, 64> selection_indexes;
        bn::sprite_palette_item text_item_palette = globals::text_palettes::beige_selected;
        int selection = 0;
        int items_count = 0;
        bool need_repalette = true;
        bool need_fadein = false;
        gameState_t initial_state;

    };
}

#endif //MENU_BASE_H
