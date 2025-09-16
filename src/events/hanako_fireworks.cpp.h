#ifndef HANAKO_FIREWORKS_CPP_H
#define HANAKO_FIREWORKS_CPP_H

#include <bn_log.h>
#include <bn_random.h>
#include <gba_interrupt.h>

#include "bn_core.h"
#include "custom_event.h"

#include "bn_regular_bg_items_hanako_fw_base.h"
#include "bn_regular_bg_items_hanako_fw_flash_bright.h"
#include "bn_regular_bg_items_hanako_fw_flash0.h"
#include "bn_regular_bg_items_hanako_fw_flash1.h"
#include "bn_regular_bg_items_hanako_fw_flash2.h"
#include "bn_regular_bg_items_hanako_fw_flash3.h"
#include "../sound_manager.h"

namespace ks {

    class HanakoFireworksEvent final : public CustomEvent {
    public:
        HanakoFireworksEvent() = default;
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
            if (is_paused) {
                return;
            }

            if (fw_timer > 0) {
                fw_timer--;
            } else {
                switch (fw_blend_state) {
                    case 0:
                        background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_flash_bright);
                        fw_colorize_value = 0;
                        break;
                    case 1:
                        background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_flash0);
                        if (fw_color_index < fw_colors.size() - 1) {
                            fw_color_index++;
                        } else {
                            fw_color_index = 0;
                        }
                        fw_colorize_value = bn::fixed(0.15);
                        break;
                    case 2:
                        background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_flash1);
                        break;
                    case 3:
                        background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_flash2);
                        break;
                    case 4:
                        background_visual.visible_bg_item->force_create_regular_ptr(bn::regular_bg_items::hanako_fw_flash3);
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
                    case 4:
                        fw_blend_state++;
                        fw_timer = 6;
                        break;
                    default:
                        fw_blend_state = 0;
                        fw_timer = random.get_int(20, 65);
                        break;
                }
            }

            auto palette = background_visual.visible_bg_item->regular_ptr().palette();
            fw_colorize_value -= bn::fixed(0.0015);
            if (fw_colorize_value < 0) {
                fw_colorize_value = 0;
            }
            palette.set_fade(fw_colors[fw_color_index], fw_colorize_value);

            CustomEvent::update();
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
        const bn::span<bn::color> fw_colors = bn::span(
            (bn::color[]){
                bn::color(31, 31, 31),
                bn::color(31, 0, 0),
                bn::color(0, 31, 0),
                bn::color(0, 0, 31),
                bn::color(31, 31, 0),
                bn::color(0, 31, 31),
                bn::color(31, 0, 31)
            }, 7
        );
    };
}
#endif // HANAKO_FIREWORKS_CPP_H
