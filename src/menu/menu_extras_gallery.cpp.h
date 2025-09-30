#ifndef MENU_EXTRAS_GALLERY_CPP_H
#define MENU_EXTRAS_GALLERY_CPP_H

#include "bn_format.h"
#include "bn_keypad.h"
#include <bn_regular_bg_items_ui_bg_menu_extras_gallery.h>
#include <bn_regular_bg_items_ui_bg_menu_extras_gallery_page_0.h>
#include <bn_regular_bg_items_ui_bg_menu_extras_gallery_page_1.h>
#include <bn_regular_bg_items_ui_bg_menu_extras_gallery_page_2.h>
#include "menu_base.h"
#include "menu_extras_gallery_images.h"

#define MENU_EXTRAS_GALLERY_MAX_PAGE_INDEX 2

namespace ks {
    class MenuExtrasGallery final : public MenuBase {
    public:
        explicit MenuExtrasGallery() {
            create(0);
            show_selected();
        }

        ~MenuExtrasGallery() override {
        }

        void on_back() override {
            thumbnail_bg.reset();
            secondary_background.reset();
            globals::state = GS_MENU_EXTRAS;
            menu::set_initial_selection(1);
        }

        void on_navigate(const bool up, const bool down, const bool left, const bool right) override {
            if (selection < gallery_items_count()) {
                if (left && selection > 0) {
                    selection--;
                }
                if (right && selection < gallery_items_count() - 1) {
                    selection++;
                }
                if (up && selection > 3) {
                    selection -= 4;
                }
                if (down) {
                    if (selection < gallery_items_count() - 4) {
                        selection += 4;
                    } else if (selection != items_count - 2 && selection / 4 != 2) {
                        selection = items_count - 2;
                    } else {
                        selection = items_count - 1;
                    }
                }
            } else {
                if (up) {
                    selection--;
                }
            }

            need_repalette = true;
            show_selected();
        }

        void on_tab_change(bool is_next) override {
            if (is_next) {
                if (current_page < MENU_EXTRAS_GALLERY_MAX_PAGE_INDEX) {
                    current_page++;
                } else {
                    current_page = 0;
                }
            } else {
                if (current_page > 0) {
                    current_page--;
                } else {
                    current_page = MENU_EXTRAS_GALLERY_MAX_PAGE_INDEX;
                }
            }

            create(current_page);
            selection = 0;
            need_repalette = true;
            show_selected();
        }

        void on_select(const int option) override {
            if (selection < gallery_items_count()) {
                primary_background.reset();
                secondary_background.reset();
                thumbnail_bg.reset();
                static_text_sprites.clear();
                progress_icon_sprites.clear();
                bn::bg_palettes::set_transparent_color(globals::colors::BLACK);
                globals::main_update();

                items.at(selection).script();
                SceneManager::free_resources();

                primary_background.reset();
                secondary_background.reset();
                create(current_page);
                need_repalette = true;
            } else {
                on_back();
            }
            show_selected();
        }

        void create(const int page) {
            text_item_palette = globals::text_palettes::beige;
            current_page = page;
            selection_indexes.clear();
            items_count = 0;
            items = menu::get_gallery_images(page);
            blend_action.reset();
            primary_background = bn::regular_bg_items::ui_bg_menu_extras_gallery.create_bg(0, 0);
            if (page == 0) {
                secondary_background = bn::regular_bg_items::ui_bg_menu_extras_gallery_page_0.create_bg(0, 0);
            } else if (page == 1) {
                secondary_background = bn::regular_bg_items::ui_bg_menu_extras_gallery_page_1.create_bg(0, 0);
            } else if (page == 2) {
                secondary_background = bn::regular_bg_items::ui_bg_menu_extras_gallery_page_2.create_bg(0, 0);
            } else {
                BN_ERROR("Invalid gallery page: ", page);
            }

            static_text_sprites.clear();
            progress_icon_sprites.clear();
            globals::main_update();

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_left_alignment();

            text_generator_bold->set_one_sprite_per_character(false);
            text_generator_bold->set_left_alignment();

            add_text_entry_bold(-device::screen_width_half + 10, -device::screen_height_half + 14,
                    bn::format<64>("{} > {}", globals::i18n->menu_extras(), globals::i18n->menu_extras_gallery()), -1);

            int idx = 0;
            for (auto &item : items) {
                if (item.thumbnail != nullptr) {
                    idx++;
                }
            }

            add_text_entry(-device::screen_width_half + 10, device::screen_height_half - 14,
                    bn::format<64>("(L/R) {}: {}/{}", globals::i18n->menu_page(), page + 1, MENU_EXTRAS_GALLERY_MAX_PAGE_INDEX + 1), -1);

            text_generator->set_right_alignment();
            add_menu_entry(device::screen_width_half - 10,
                           device::screen_height_half - 14, globals::i18n->menu_back(), idx);

            items_count = idx + 1;
        }

        void show_selected() {
            thumbnail_bg.reset();
            if (selection < gallery_items_count()) {
                thumbnail_bg = items.at(selection).thumbnail->thumbnail.create_bg(
                    -84 + (selection % 4) * 56,
                    -39 + (selection / 4) * 38
                );
                thumbnail_bg->set_priority(secondary_background->priority() - 1);
            }
        }
    private:
        bn::optional<bn::blending_transparency_alpha_to_action> blend_action;
        bn::optional<bn::regular_bg_ptr> thumbnail_bg;
        bn::array<menu::gallery_image, 12> items;
        int current_page;

        int gallery_items_count() {
            int count = 0;
            for (const auto &item : items) {
                if (item.thumbnail != nullptr) {
                    count++;
                }
            }
            return count;
        }
    };
}

#endif //MENU_EXTRAS_GALLERY_CPP_H
