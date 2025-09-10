#include "dialog_box.h"

#include "bn_log.h"
#include "bn_blending.h"
#include "bn_sprite_items_ui_talkbox1.h"
#include "bn_sprite_items_ui_talkbox2.h"
#include "bn_sprite_items_ui_talkbox2_doublespeak.h"
#include "bn_sprite_items_ui_talkbox4.h"
#include "bn_sprite_items_ui_talkbox_actor.h"
#include "bn_sprite_items_ui_talkbox_actor_end.h"
#include "bn_sprite_items_ui_talkbox_actor_start.h"

namespace ks {
    void dialog_box_doublespeak::update() {
        _left_window.update();
        _right_window.update();
    }

    void dialog_box_doublespeak::show(const bool blending) {
        BN_ASSERT(_bold_text_generator.has_value(), "Bold text generator is null");

        BN_LOG("Left: ");
        _left_window.log();

        BN_LOG("Right: ");
        _right_window.log();

        _left_window.show(blending);
        _right_window.show(blending);

        if (text_boxes.empty()) {
            auto box_left = bn::sprite_items::ui_talkbox1.create_sprite(
                -ks::device::screen_width_half + 32,
                ks::device::screen_height_half - 32);
            auto box_left_end = bn::sprite_items::ui_talkbox2_doublespeak.create_sprite(
                -ks::device::screen_width_half + 96,
                ks::device::screen_height_half - 32);
            auto box_right = bn::sprite_items::ui_talkbox2.create_sprite(
                -ks::device::screen_width_half + 160,
                ks::device::screen_height_half - 32);
            auto box_right_end = bn::sprite_items::ui_talkbox4.create_sprite(
                -ks::device::screen_width_half + 224,
                ks::device::screen_height_half - 32);

            box_left.set_bg_priority(1);
            box_left_end.set_bg_priority(1);
            box_right.set_bg_priority(1);
            box_right_end.set_bg_priority(1);

            text_boxes.push_back(bn::move(box_left));
            text_boxes.push_back(bn::move(box_left_end));
            text_boxes.push_back(bn::move(box_right));
            text_boxes.push_back(bn::move(box_right_end));
        }

        actor_boxes.clear();
        title_sprites.clear();

        for (int actor_num = 0; actor_num < 2; actor_num++) {
            const character_definition* _actor = actor_num == 0 ? _left_window.get_actor() : _right_window.get_actor();
            const int offset_x = actor_num == 0 ? 0 : device::screen_width_half - 2;

            const int title_ends_x = -device::screen_width_half + 8 + _bold_text_generator->width(_actor->name()) + offset_x;
            actor_boxes.push_back(
                bn::sprite_items::ui_talkbox_actor_start.create_sprite(-ks::device::screen_width_half + 16 + offset_x,
                                                                       ks::device::screen_height_half - 44));

            int add = 0;
            while (title_ends_x > -device::screen_width_half + (++add * 32) + offset_x) {
                actor_boxes.push_back(bn::sprite_items::ui_talkbox_actor.create_sprite(
                    -ks::device::screen_width_half + 16 + add * 32 + offset_x,
                    ks::device::screen_height_half - 44));
            }
            actor_boxes.push_back(bn::sprite_items::ui_talkbox_actor_end.create_sprite(
                -ks::device::screen_width_half + 16 + add * 32 + offset_x, ks::device::screen_height_half - 44));
            for (auto &box: actor_boxes) {
                box.set_bg_priority(1);
            }

            _bold_text_generator->set_left_alignment();
            _bold_text_generator->set_palette_item(_actor->who_color);
            _bold_text_generator->generate(-ks::device::screen_width_half + 8 + offset_x, ks::device::screen_height_half - 52,
                                          _actor->name(), title_sprites);
        }

        bn::blending::set_transparency_alpha(globals::transparency_alpha());
        set_blending(true, false);
        _left_window.set_hidden(false);
        _right_window.set_hidden(false);
    }

    void dialog_box_doublespeak::hide(const bool blending) {
        text_boxes.clear();
        actor_boxes.clear();
        title_sprites.clear();
        _left_window.clear_sprites();
        _left_window.set_hidden(true);
        _right_window.clear_sprites();
        _right_window.set_hidden(true);
    }

    void dialog_box_doublespeak::set_blending(const bool boxes_blending_enabled, const bool text_blending_enabled) {
        for (auto &box: text_boxes) {
            box.set_blending_enabled(boxes_blending_enabled);
        }
        for (auto &box: actor_boxes) {
            box.set_blending_enabled(boxes_blending_enabled);
        }
        for (auto &sprite: title_sprites) {
            sprite.set_blending_enabled(text_blending_enabled);
        }
    }
}
