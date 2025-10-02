#ifndef MENU_EXTRAS_GALLERY_IMAGES_H
#define MENU_EXTRAS_GALLERY_IMAGES_H

#include "bn_log.h"
#include "bn_regular_bg_item.h"
#include "background_meta.h"
#include "background_metas.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_gallery_page_0.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_gallery_page_1.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_gallery_page_2.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_gallery_page_3.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_gallery_page_4.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_gallery_page_5.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_gallery_page_6.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_gallery_page_7.h"
#include "bn_regular_bg_items_ui_bg_menu_extras_gallery_page_8.h"
#include "custom_background_metas.h"
#include "../scenemanager.h"
#include "../events/hanako_fireworks.cpp.h"
#include "../events/hisao_class_end.cpp.h"
#include "../events/hisao_class_move.cpp.h"
#include "../events/hisao_class_start.cpp.h"
#include "../events/other_iwanako.cpp.h"

#define GALLERY_IMAGE_ELEMENTS 7
#define GALLERY_CUSTOM_EVENTS_ELEMENTS 3
#define GALLERY_DISSOLVE_TIME 30

namespace ks::menu {
    struct gallery_image {
        const displayable_bitmask_t displayable_bitmask;
        const background_meta *thumbnail;
        void (*script)();
        const bool is_cutin = false;

        constexpr gallery_image(const displayable_bitmask_t id,
                      const background_meta *thumb,
                      void (*script)(),
                      const bool is_cutin_flag = false)
            : displayable_bitmask(id),
              thumbnail(thumb),
              script(script),
              is_cutin(is_cutin_flag) {
        }

        [[nodiscard]] bool is_unlocked() const {
            if (!is_cutin) {
                return globals::states.is_seen_displayable(displayable_bitmask);
            }
            BN_LOG("Cutin check");
            return globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_PILLS) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_STUFFEDCAT) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_TEASET) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_SHANGPAI) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_WINE) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_MUSICBOX_CLOSED) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_MUSICBOX_OPEN) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_HANAPHONE) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_PHONESTRAP) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_HANAPHONESTRAP) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_INSERT_STARTPISTOL) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_INVITE) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_SC_COMP) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_BRAILLER) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_CHESSBOARD) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_KENJIBOX) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_JIGOROCARD) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_LETTER_INSERT) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_LETTER_OPEN_INSERT) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_LETTER_OPEN_INSERT_2) ||
                   globals::states.is_seen_displayable(DISPLAYABLE_BITMASK_STALLPHOTO_INSERT);
        }
    };

    struct gallery_page {
        bn::span<const gallery_image> images;
        const bn::regular_bg_item *bg_item;

        constexpr gallery_page(const bn::span<const gallery_image> _images, const bn::regular_bg_item *_bg_item)
            : images(_images), bg_item(_bg_item) {
        }
    };

    namespace gallery_script {
        static __attribute__((always_inline)) void prepare_scene_manager() {
            SceneManager::set(SceneManager("gallery"));
        }

        static __attribute__((always_inline)) void process() {
            SceneManager::update_visuals();
            while (!bn::keypad::a_pressed() && !bn::keypad::b_pressed()) {
                globals::main_update();
            }
        }

        static __attribute__((always_inline)) void show_bg(const background_meta &bg) {
            BN_ASSERT(bg.seen_bitmask != DISPLAYABLE_BITMASK_NONE, "Background seen_bitmask is NONE");
            if (globals::states.is_seen_displayable(bg.seen_bitmask)) {
                SceneManager::set_background(bg, 0, 0, SCENE_TRANSITION_NONE, GALLERY_DISSOLVE_TIME,
                                             PALETTE_VARIANT_DEFAULT);
                process();
            }
        }

        static __attribute__((always_inline)) void show_vfx(const vfx_meta &vfx) {
            BN_ASSERT(vfx.seen_bitmask != DISPLAYABLE_BITMASK_NONE, "Background seen_bitmask is NONE");
            if (globals::states.is_seen_displayable(vfx.seen_bitmask)) {
                SceneManager::set_foreground(vfx, 0, 0, GALLERY_DISSOLVE_TIME);
                process();
                SceneManager::hide_foreground(GALLERY_DISSOLVE_TIME / 2);
                SceneManager::update_visuals();
            }
        }

        static __attribute__((always_inline)) void show_bg(const background_meta &bg,
                                                           const displayable_bitmask_t &displayable_bitmask) {
            if (globals::states.is_seen_displayable(displayable_bitmask)) {
                SceneManager::set_background(bg, 0, 0, SCENE_TRANSITION_NONE, GALLERY_DISSOLVE_TIME,
                                             PALETTE_VARIANT_DEFAULT);
                process();
            }
        }

        static __attribute__((always_inline)) void show_event(const background_meta &bg, const CustomEvent &event,
                                                              const scene_transition_t transition,
                                                              const int dissolve_time) {
            if (globals::states.is_seen_displayable(bg.seen_bitmask) ||
                globals::states.is_seen_displayable(event.get_displayable_bitmask())) {
                SceneManager::set_event(bg, event, transition, dissolve_time);
                process();
            }
        }

        /** Placeholder for not implemented scripts
         *
         * TODO: Remove this method after all scripts are implemented
         */
        static void not_implemented() {
            BN_ERROR("Gallery script is not implemented yet.");
        }
    }

    extern const gallery_image images_0[12];
    extern const gallery_image images_1[12];
    extern const gallery_image images_2[12];
    extern const gallery_image images_3[12];
    extern const gallery_image images_4[12];
    extern const gallery_image images_5[12];
    extern const gallery_image images_6[12];
    extern const gallery_image images_7[12];
    extern const gallery_image images_8[10];
    extern const gallery_image images_null[1];

    inline gallery_page get_gallery_page(const int page) {
        if (page == 0) {
            return {bn::span(images_0, 12), &bn::regular_bg_items::ui_bg_menu_extras_gallery_page_0};
        }
        if (page == 1) {
            return {bn::span(images_1, 12), &bn::regular_bg_items::ui_bg_menu_extras_gallery_page_1};
        }
        if (page == 2) {
            return {bn::span(images_2, 12), &bn::regular_bg_items::ui_bg_menu_extras_gallery_page_2};
        }
        if (page == 3) {
            return {bn::span(images_3, 12), &bn::regular_bg_items::ui_bg_menu_extras_gallery_page_3};
        }
        if (page == 4) {
            return {bn::span(images_4, 12), &bn::regular_bg_items::ui_bg_menu_extras_gallery_page_4};
        }
        if (page == 5) {
            return {bn::span(images_5, 12), &bn::regular_bg_items::ui_bg_menu_extras_gallery_page_5};
        }
        if (page == 6) {
            return {bn::span(images_6, 12), &bn::regular_bg_items::ui_bg_menu_extras_gallery_page_6};
        }
        if (page == 7) {
            return {bn::span(images_7, 12), &bn::regular_bg_items::ui_bg_menu_extras_gallery_page_7};
        }
        if (page == 8) {
            return {bn::span(images_8, 10), &bn::regular_bg_items::ui_bg_menu_extras_gallery_page_8};
        }
        return {bn::span(images_null, 1), nullptr};
    }

}

#endif //MENU_EXTRAS_GALLERY_IMAGES_H
