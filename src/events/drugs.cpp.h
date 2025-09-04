#ifndef EV_DRUGS_CPP_H
#define EV_DRUGS_CPP_H

#include <bn_log.h>

#include "bn_bg_palettes.h"
#include "bn_bg_palette_ptr.h"
#include "bn_regular_bg_actions.h"
#include "custom_event.h"

namespace ks {

    class DrugsEvent final : public CustomEvent {
    public:
        DrugsEvent() = default;
        ~DrugsEvent() override {
            // _background.reset();
        };
        //
        // CustomEvent clone() override {
        //     return DrugsEvent();
        // }

        [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
            return bn::make_unique<DrugsEvent>();
        }

        void init() override {
            BN_LOG("DrugsEvent::init");
            _palette_color_idx = 0;
            _palette_color_timer = 0;

            BN_ASSERT(background_visual.visible_bg_item.has_value(), "Event background is not set");

            BN_LOG("DrugsEvent::init - setpos");
            background_visual.visible_bg_item->set_position(-48, -176);

            BN_LOG("DrugsEvent::init - SM setpos");
            SceneManager::set_background_position(-48, -176);

            BN_LOG("DrugsEvent::init - moveact create");
            _move_action = bn::regular_bg_top_left_move_to_action(
                background_visual.visible_bg_item->regular_ptr(),
                _updates,
                -240,
                -176
            );

            BN_LOG("DrugsEvent::init - palette get");
            _palette = background_visual.visible_bg_item->regular_ptr().palette();
            for (int i = 0; i < 64; i++) {
                _palette->set_color(i, bn::color(31, 31, 31));
            }


            BN_LOG("DrugsEvent::init - DONE");
            CustomEvent::init();
            BN_LOG("CustomEvent::init - DONE");
        }
        void update() override {
            CustomEvent::update();

            bn::bg_palettes::set_transparent_color(ks::globals::colors::WHITE);
            if (_palette_color_idx < 64) {
                if (_palette_color_timer < _updates_per_color) {
                    _palette_color_timer++;

                    const int color_value = 31 - (_palette_color_timer * 31 / _updates_per_color);
                    _palette->set_color(_palette_color_idx, bn::color(color_value, color_value, color_value));
                    background_visual.visible_bg_item->set_palette(_palette.value());
                } else {
                    _palette_color_idx++;
                    _palette_color_timer = 0;
                }
            }

            if (_move_action.has_value()) {
                if (!_move_action->done()) {
                    _move_action->update();
                }
            }
        }
        void destroy() override {
            BN_LOG("DrugsEvent::destroy");
            _move_action.reset();
            // _palette.reset();
            CustomEvent::destroy();
        }

    private:
        const int _updates = 2100;
        const int _updates_per_color = 31;
        int _palette_color_idx;
        int _palette_color_timer;
        bn::optional<bn::regular_bg_top_left_move_to_action> _move_action;
        bn::optional<bn::bg_palette_ptr> _palette;
    };
}
#endif // EV_DRUGS_CPP_H
