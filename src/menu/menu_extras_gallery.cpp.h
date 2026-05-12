#ifndef MENU_EXTRAS_GALLERY_CPP_H
#define MENU_EXTRAS_GALLERY_CPP_H

#include "bn_format.h"
// #include <bn_regular_bg_items_ui_bg_menu_extras_gallery.h>
#include <bn_regular_bg_items_ui_bg_menu_inner.h>
#include "bn_sprite_items_ui_cg_corners.h"
#include "bn_sprite_items_ui_cg_gallery_locked.h"
#include "menu_base.h"
#include "menu_extras_gallery_images.h"

#define MENU_EXTRAS_GALLERY_MAX_PAGE_INDEX 8

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
            cg_corners_sprites.clear();
            cg_locked_sprites.clear();
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
            thumbnail_bg.reset();
            selection = 0;
            globals::main_update();

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
            show_selected();
        }

        void on_select(const int option) override {
            if (selection < gallery_items_count()) {
                primary_background.reset();
                secondary_background.reset();
                thumbnail_bg.reset();
                cg_locked_sprites.clear();
                cg_corners_sprites.clear();
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
                show_selected();
            } else {
                on_back();
            }
        }

        void create(const int page) {
            text_item_palette = globals::text_palettes::beige;
            current_page = page;
            selection_indexes.clear();
            cg_corners_sprites.clear();
            cg_locked_sprites.clear();
            items_count = 0;
            blend_action.reset();
            primary_background = bn::regular_bg_items::ui_bg_menu_inner.create_bg(0, 0);
            secondary_background.reset();
            static_text_sprites.clear();
            progress_icon_sprites.clear();
            globals::main_update();

            const auto page_contents = menu::get_gallery_page(page);
            items = page_contents.images;
            secondary_background = page_contents.bg_item->create_bg(0, 0);
            secondary_background->set_priority(primary_background->priority() - 1);

            text_generator->set_one_sprite_per_character(false);
            text_generator->set_left_alignment();

            add_text_entry_bold(-device::screen_width_half + 10, -device::screen_height_half + 14,
                    bn::format<64>("{} > {}", tl::menu_extras(), tl::menu_extras_gallery()), -1);

            int idx = 0;
            for (const auto &item : items) {
                cg_locked_sprites.push_back(bn::sprite_items::ui_cg_gallery_locked.create_sprite(
                    -84 + (idx % 4) * 56,
                    -39 + (idx / 4) * 38
                ));
                if (item.is_unlocked()) {
                    cg_locked_sprites.back().set_bg_priority(secondary_background->priority() + 1);
                } else {
                    cg_locked_sprites.back().set_bg_priority(secondary_background->priority());
                }
                idx++;
            }

            add_text_entry(-device::screen_width_half + 10, device::screen_height_half - 14,
                    bn::format<64>("(L/R) {}: {}/{}", tl::menu_page(), page + 1, MENU_EXTRAS_GALLERY_MAX_PAGE_INDEX + 1), -1);

            text_generator->set_right_alignment();
            add_menu_entry(device::screen_width_half - 10,
                           device::screen_height_half - 14, tl::menu_back(), idx);

            items_count = idx + 1;
            need_repalette = true;
            repalette();
        }

        void show_selected() {
            thumbnail_bg.reset();
            cg_corners_sprites.clear();
            globals::main_update(); // Update to prevent VRAM fragmentation
            if (selection < gallery_items_count()) {
                const auto& image = items.at(selection);
                if (image.is_unlocked()) {
                    thumbnail_bg = image.thumbnail->thumbnail.create_bg(
                        -84 + (selection % 4) * 56,
                        -39 + (selection / 4) * 38
                    );
                    thumbnail_bg->set_priority(secondary_background->priority() - 1);
                }

                for (int corner = 0; corner < 4; corner++) {
                    cg_corners_sprites.push_back(bn::sprite_items::ui_cg_corners.create_sprite(
                        -108 + (selection % 4) * 56 + (corner % 2) * 48,
                        -55 + (selection / 4) * 38 + (corner / 2) * 32,
                        corner
                    ));
                    cg_corners_sprites.back().set_bg_priority(secondary_background->priority() - 1);
                }
                if (!image.is_unlocked()) {
                // if (true) {
                    cg_corners_sprites.push_back(bn::sprite_items::ui_cg_corners.create_sprite(
                        -84 + (selection % 4) * 56,
                        -39 + (selection / 4) * 38,
                        5
                    ));
                    cg_corners_sprites.back().set_bg_priority(secondary_background->priority() - 1);
                }
            }
        }
    private:
        bn::optional<bn::blending_transparency_alpha_to_action> blend_action;
        bn::optional<bn::regular_bg_ptr> thumbnail_bg;
        bn::vector<bn::sprite_ptr, 12> cg_locked_sprites;
        bn::vector<bn::sprite_ptr, 5> cg_corners_sprites;
        bn::span<const menu::gallery_image> items;
        int current_page;

        [[nodiscard]] int gallery_items_count() const {
            return items.size();
        }
    };
}

#endif //MENU_EXTRAS_GALLERY_CPP_H
