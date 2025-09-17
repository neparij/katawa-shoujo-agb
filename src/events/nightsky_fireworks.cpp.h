#ifndef NIGHTSKY_FIREWORKS_CPP_H
#define NIGHTSKY_FIREWORKS_CPP_H

#include <bn_log.h>
#include <bn_random.h>

#include "bn_bg_palette_ptr.h"
#include "bn_core.h"
#include "custom_event.h"

#include "bn_regular_bg_items_fireworks_a0.h"
#include "bn_regular_bg_items_fireworks_a1.h"
#include "bn_regular_bg_items_fireworks_a2.h"
#include "bn_regular_bg_items_fireworks_b0.h"
#include "bn_regular_bg_items_fireworks_b1.h"
#include "bn_regular_bg_items_fireworks_b2.h"
#include "bn_regular_bg_items_fireworks_b3.h"

namespace ks {

    class NightskyFireworksEvent final : public CustomEvent {
    public:
        NightskyFireworksEvent() = default;
        ~NightskyFireworksEvent() override {
            // _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
            return bn::make_unique<NightskyFireworksEvent>();
        }

        void init() override {
            BN_LOG("NightskyFireworksEvent::init");
            BN_ASSERT(background_visual.visible_bg_item.has_value(), "Event background is not set");
            _bg_priority = background_visual.visible_bg_item->priority();
            _bg_z_order = background_visual.visible_bg_item->z_order();
            layer_b_fw_timer = 17;
            CustomEvent::init();
        }

        bool is_blendable() override {
            return true;
        }

        void before_hide(void(*on_update)()) override {
            layer_a_fw.reset();
            layer_b_fw.reset();
        }

        void after_show(void(*on_update)()) override {
        }

        void update() override {
            if (is_paused) {
                return;
            }

            if (layer_a_fw_timer > 0) {
                layer_a_fw_timer--;
            } else {
                layer_a_fw_timer = 89;
                layer_a_fade = 0;
                main_layer_fade = 0.1;
                layer_a_fw.reset();
                layer_a_fw = layer_a_fireworks[layer_a_index].create_bg();
                layer_a_fw->set_priority(_bg_priority);
                layer_a_fw->set_z_order(_bg_z_order - 2);
                if (layer_b_fw.has_value()) {
                    layer_b_fw->set_z_order(_bg_z_order - 1);
                }
                if (++layer_a_index >= (int)layer_a_fireworks.size()) {
                    layer_a_index = 0;
                }
            }

            if (layer_b_fw_timer > 0) {
                layer_b_fw_timer--;
            } else {
                layer_b_fw_timer = 97;
                layer_b_fade = 0;
                main_layer_fade = 0.1;
                layer_b_fw.reset();
                layer_b_fw = layer_b_fireworks[layer_b_index].create_bg();
                layer_b_fw->set_priority(_bg_priority);
                layer_b_fw->set_z_order(_bg_z_order - 2);
                if (layer_a_fw.has_value()) {
                    layer_a_fw->set_z_order(_bg_z_order - 1);
                }
                if (++layer_b_index >= (int)layer_b_fireworks.size()) {
                    layer_b_index = 0;
                }
            }

            if (layer_a_fw.has_value() && layer_a_fade < bn::fixed(0.8)) {
                layer_a_fade += bn::fixed(0.01);
                auto palette = layer_a_fw->palette();
                palette.set_fade(bn::color(1, 1, 2), layer_a_fade);
            } else {
                layer_a_fw.reset();
            }

            if (layer_b_fw.has_value() && layer_b_fade < bn::fixed(0.8)) {
                layer_b_fade += bn::fixed(0.01);
                auto palette = layer_b_fw->palette();
                palette.set_fade(bn::color(1, 1, 2), layer_b_fade);
            } else {
                layer_b_fw.reset();
            }

            if (main_layer_fade > 0) {
                main_layer_fade -= bn::fixed(0.005);
                if (main_layer_fade < 0) {
                    main_layer_fade = 0;
                }
                auto palette = background_visual.visible_bg_item->regular_ptr().palette();
                palette.set_fade(bn::color(31, 31, 31), main_layer_fade);
            }

            CustomEvent::update();
        }
        void destroy() override {
            BN_LOG("NightskyFireworksEvent::destroy");
            layer_a_fw.reset();
            layer_b_fw.reset();
            CustomEvent::destroy();
        }

    private:
        bn::optional<bn::regular_bg_ptr> layer_a_fw;
        bn::optional<bn::regular_bg_ptr> layer_b_fw;
        int _bg_priority = 0;
        int _bg_z_order = 0;

        int layer_a_fw_timer = 0;
        int layer_b_fw_timer = 0;
        int layer_a_index = 0;
        int layer_b_index = 0;

        bn::fixed layer_a_fade = 0;
        bn::fixed layer_b_fade = 0;
        bn::fixed main_layer_fade = 0;

        const bn::span<const bn::regular_bg_item> layer_a_fireworks = bn::span(
            (const bn::regular_bg_item[]){
                bn::regular_bg_items::fireworks_a0,
                bn::regular_bg_items::fireworks_a1,
                bn::regular_bg_items::fireworks_a2
            }, 3
        );
        const bn::span<const bn::regular_bg_item> layer_b_fireworks = bn::span(
            (const bn::regular_bg_item[]){
                bn::regular_bg_items::fireworks_b0,
                bn::regular_bg_items::fireworks_b1,
                bn::regular_bg_items::fireworks_b2,
                bn::regular_bg_items::fireworks_b3
            }, 4
        );
    };
}
#endif // NIGHTSKY_FIREWORKS_CPP_H
