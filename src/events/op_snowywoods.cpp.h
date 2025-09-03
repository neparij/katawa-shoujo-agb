#ifndef OP_SNOWYWOODS_CPP_H
#define OP_SNOWYWOODS_CPP_H

#include <bn_log.h>

#include "bn_core.h"
#include "custom_event.h"
#include "bn_regular_bg_items_snow_layer_0.h"
#include "bn_regular_bg_items_snow_layer_1.h"

namespace ks {
    class OpSnowywoodsEvent final : public CustomEvent {
    public:
        OpSnowywoodsEvent() = default;
        ~OpSnowywoodsEvent() override {
            // _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
            return bn::make_unique<OpSnowywoodsEvent>();
        }

        void init() override {
            BN_LOG("OpSnowywoodsEvent::init");
            _vfx_snow_layer_0 = bn::regular_bg_items::snow_layer_0.create_bg(0, 0);
            _vfx_snow_layer_1 = bn::regular_bg_items::snow_layer_1.create_bg(0, 0);

            _vfx_snow_layer_0->set_priority(background_visual.visible_bg_item->priority() - 1);
            _vfx_snow_layer_1->set_priority(background_visual.visible_bg_item->priority() - 1);
            _vfx_snow_layer_0->set_visible(false);
            _vfx_snow_layer_1->set_visible(false);
            CustomEvent::init();
        }

        bool is_blendable() override {
            return true;
        }

        void before_hide(void(*on_update)()) override {
            _blend_action = bn::blending_transparency_alpha_to_action(15, 0);

            _vfx_snow_layer_0->set_visible(true);
            _vfx_snow_layer_1->set_visible(true);
            _vfx_snow_layer_0->set_blending_enabled(true);
            _vfx_snow_layer_1->set_blending_enabled(true);

            while (!_blend_action->done()) {
                _blend_action->update();
                on_update();
            }
            _blend_action.reset();

            _vfx_snow_layer_0.reset();
            _vfx_snow_layer_1.reset();
            bn::blending::restore();
        }

        void after_show(void(*on_update)()) override {
            bn::blending::set_transparency_alpha(0);
            _blend_action = bn::blending_transparency_alpha_to_action(30, 1);

            _vfx_snow_layer_0->set_visible(true);
            _vfx_snow_layer_1->set_visible(true);
            _vfx_snow_layer_0->set_blending_enabled(true);
            _vfx_snow_layer_1->set_blending_enabled(true);

            while (!_blend_action->done()) {
                _blend_action->update();
                on_update();
            }
            _blend_action.reset();

            _vfx_snow_layer_0->set_blending_enabled(false);
            _vfx_snow_layer_1->set_blending_enabled(false);
            bn::blending::restore();
        }

        void update() override {
            _animation_sine += bn::fixed(0.001);
            if (_animation_sine > 1) {
                _animation_sine -= 1;
            }

            const bn::fixed sine_value_a = bn::sin(_animation_sine + 0.125);
            const bn::fixed sine_value_b = bn::sin(_animation_sine);

            if (_vfx_snow_layer_0.has_value()) {
                _vfx_snow_layer_0->set_position(
                    _vfx_snow_layer_0->position().x() + bn::fixed(0.25) * sine_value_a,
                    _vfx_snow_layer_0->position().y() + bn::fixed(0.25)
                );
            }
            if (_vfx_snow_layer_1.has_value()) {
                _vfx_snow_layer_1->set_position(
                    _vfx_snow_layer_1->position().x() + bn::fixed(0.125) * sine_value_b,
                    _vfx_snow_layer_1->position().y() + bn::fixed(0.22)
                );
            }

            CustomEvent::update();
        }

        void destroy() override {
            BN_LOG("OpSnowywoodsEvent::destroy");
            CustomEvent::destroy();
            _vfx_snow_layer_0.reset();
            _vfx_snow_layer_1.reset();
        }

    private:
        bn::fixed _animation_sine = 0;
        bn::optional<bn::regular_bg_ptr> _vfx_snow_layer_0;
        bn::optional<bn::regular_bg_ptr> _vfx_snow_layer_1;
        bn::optional<bn::blending_transparency_alpha_to_action> _blend_action;
    };
}
#endif // OP_SNOWYWOODS_CPP_H
