#ifndef HANAKO_FIREWORKS_CPP_H
#define HANAKO_FIREWORKS_CPP_H

#include <bn_log.h>
#include <bn_random.h>

#include "bn_bg_palette_ptr.h"
#include "custom_event.h"

#include "bn_regular_bg_items_hanako_fw_base.h"
#include "bn_regular_bg_items_hanako_fw_flash0.h"
#include "bn_regular_bg_items_hanako_fw_flash1.h"
#include "bn_regular_bg_items_hanako_fw_flash2.h"
#include "gba_math.h"

namespace ks {

    namespace event_data::hanako_fireworks {
        constexpr bn::color fw_colors_array[] = {
            bn::color(31, 31, 31),
            bn::color(31, 0, 0),
            bn::color(0, 31, 0),
            bn::color(0, 0, 31),
            bn::color(31, 31, 0),
            bn::color(0, 31, 31),
            bn::color(31, 0, 31)
        };
        constexpr bn::span fw_colors(fw_colors_array);
    }

    class HanakoFireworksEvent final : public CustomEvent {
    public:
        HanakoFireworksEvent() : CustomEvent(DISPLAYABLE_BITMASK_HANAKO_SHANGHAIWINDOW) {};
        ~HanakoFireworksEvent() override {
            // _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
            return bn::make_unique<HanakoFireworksEvent>();
        }

        void init() override {
            BN_LOG("HanakoFireworksEvent::init");
            BN_ASSERT(background_visual.visible_bg_item.has_value(), "Event background is not set");
            _bg_priority = background_visual.visible_bg_item->priority();
            _bg_z_order = background_visual.visible_bg_item->z_order();
            random = bn::random();
            CustomEvent::init();
        }
        void update() override {
            if (is_paused || !_allow_updates) {
                return;
            }

            if (fw_timer > 0) {
                fw_timer--;
            } else if (_state != 2) {
                switch (fw_blend_state) {
                    case 0:
                        background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_flash0);
                        if (fw_color_index < event_data::hanako_fireworks::fw_colors.size() - 1) {
                            fw_color_index++;
                        } else {
                            fw_color_index = 0;
                        }
                        fw_colorize_value = bn::fixed(0.15);
                        break;
                    case 1:
                        break;
                    case 2:
                        background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_flash1);
                        break;
                    case 3:
                        background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_flash2);
                        break;
                    default:
                        background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_base);
                        break;
                }
                background_visual.visible_bg_item->set_priority(_bg_priority);
                background_visual.visible_bg_item->set_z_order(_bg_z_order);

                switch (fw_blend_state) {
                    case 0:
                        fw_blend_state++;
                        fw_timer = 3;
                        break;
                    case 1:
                    case 2:
                    case 3:
                        fw_blend_state++;
                        fw_timer = 6;
                        break;
                    default:
                        if (_state == 0) {
                            fw_blend_state = 0;
                            fw_timer = random.get_int(20, 65);
                        } else {
                            _state = 2;
                        }
                        break;
                }
            }

            auto palette = background_visual.visible_bg_item->regular_ptr().palette();
            fw_colorize_value -= bn::fixed(0.0015);
            if (fw_colorize_value < 0) {
                fw_colorize_value = 0;
            }

            if (fw_blend_state == 1) {
                auto color = event_data::hanako_fireworks::fw_colors[fw_color_index];
                color.set_components(
                    CLAMP(color.red() + fw_timer * 31, 0, 31),
                    CLAMP(color.green() + fw_timer * 31, 0, 31),
                    CLAMP(color.blue() + fw_timer * 31, 0, 31)
                );
                palette.set_fade(color, bn::fixed(fw_timer).division(6) + fw_colorize_value);
            } else {
                palette.set_fade(event_data::hanako_fireworks::fw_colors[fw_color_index], fw_colorize_value);
            }

            CustomEvent::update();
        }

        bool is_blendable() override {
            return true;
        }

        void before_hide(void(*on_update)()) override {
            if (!is_paused) {
                background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_base);
                background_visual.visible_bg_item->set_priority(_bg_priority);
                background_visual.visible_bg_item->set_z_order(_bg_z_order);
            }
            on_update();
        }

        void after_show(void(*on_update)()) override {
            _allow_updates = true;
            on_update();
        }

        void destroy() override {
            BN_LOG("HanakoFireworksEvent::destroy");
            CustomEvent::destroy();
        }

    private:
        bn::random random;
        int fw_timer = 0;
        bn::fixed fw_colorize_value = 0;
        int fw_blend_state = 0;
        int fw_color_index = 0;
        int _bg_priority = 0;
        int _bg_z_order = 0;
        bool _allow_updates = false;
    };
}
#endif // HANAKO_FIREWORKS_CPP_H
