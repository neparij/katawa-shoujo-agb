#ifndef HOSP_ROOM_CPP_H
#define HOSP_ROOM_CPP_H

#include <bn_log.h>

#include "bn_core.h"
#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "custom_event.h"
#include "bn_sprite_items_mask_hosp_room.h"
#include "bn_tiled_bg_animate_actions.h"

#include "bn_regular_bg_items_sakura_layer_0.h"
#include "bn_regular_bg_items_sakura_layer_1.h"

#include "bn_regular_bg_tiles_items_sakura_tiles_0.h"
#include "bn_regular_bg_tiles_items_sakura_tiles_1.h"

namespace ks {
    class HospRoomEvent final : public CustomEvent {
    public:
        HospRoomEvent() = default;
        ~HospRoomEvent() override {
            // _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
            return bn::make_unique<HospRoomEvent>();
        }

        void init() override {
            BN_LOG("HospRoomEvent::init");
            _mask = bn::sprite_items::mask_hosp_room.create_sprite(79, 1);
            _mask->set_window_enabled(true);
            _mask->set_visible(false);

            _vfx_sakura_layer_0 = bn::regular_bg_items::sakura_layer_0.create_bg(0, 0);
            _vfx_sakura_layer_1 = bn::regular_bg_items::sakura_layer_1.create_bg(0, 0);
            _vfx_sakura_layer_0->set_priority(background_visual.visible_bg_item->priority() - 1);
            _vfx_sakura_layer_1->set_priority(background_visual.visible_bg_item->priority() - 1);
            _vfx_sakura_layer_0->set_visible(false);
            _vfx_sakura_layer_1->set_visible(false);


            // TODO: Check for characters boundaries after.
            bn::window outside_window = bn::window::outside();
            left_window.restore_boundaries();
            right_window.restore_boundaries();
            outside_window.set_show_bg(_vfx_sakura_layer_0.value(), false);
            outside_window.set_show_bg(_vfx_sakura_layer_1.value(), false);

            _sakura_tiles_move_action_0 = bn::regular_bg_move_by_action(
                _vfx_sakura_layer_0.value(),
                bn::fixed(0.33),
                bn::fixed(0.21)
            );

            _sakura_tiles_move_action_1 = bn::regular_bg_move_by_action(
                _vfx_sakura_layer_1.value(),
                bn::fixed(0.33),
                bn::fixed(0.42)
            );

            _sakura_tiles_animate_action_0 = bn::create_tiled_bg_animate_action_forever(
                _vfx_sakura_layer_0.value(),
                7, // Use a primary number to avoid sync
                _vfx_sakura_tiles_items,
                0, 1
            );

            _sakura_tiles_animate_action_1 = bn::create_tiled_bg_animate_action_forever(
                _vfx_sakura_layer_1.value(),
                13, // Use a primary number to avoid sync
                _vfx_sakura_tiles_items,
                0, 1
            );

            CustomEvent::init();
        }

        bool is_blendable() override {
            return true;
        }
        
        void before_hide(void(*on_update)()) override {
            _blend_action = bn::blending_transparency_alpha_to_action(5, 0);
        
            _vfx_sakura_layer_0->set_visible(true);
            _vfx_sakura_layer_1->set_visible(true);
            _vfx_sakura_layer_0->set_blending_enabled(true);
            _vfx_sakura_layer_1->set_blending_enabled(true);
        
            while (!_blend_action->done()) {
                _blend_action->update();
                on_update();
            }
            _blend_action.reset();
        
            _vfx_sakura_layer_0.reset();
            _vfx_sakura_layer_1.reset();
            _mask.reset();
            bn::blending::restore();
        }
        
        void after_show(void(*on_update)()) override {
            bn::blending::set_transparency_alpha(0);
            _blend_action = bn::blending_transparency_alpha_to_action(15, 1);

            _mask->set_visible(true);
            _vfx_sakura_layer_0->set_visible(true);
            _vfx_sakura_layer_1->set_visible(true);
            _vfx_sakura_layer_0->set_blending_enabled(true);
            _vfx_sakura_layer_1->set_blending_enabled(true);
        
            while (!_blend_action->done()) {
                _blend_action->update();
                on_update();
            }
            _blend_action.reset();
        
            _vfx_sakura_layer_0->set_blending_enabled(false);
            _vfx_sakura_layer_1->set_blending_enabled(false);
            bn::blending::restore();
        }

        void update() override {
            if (_mask.has_value() && background_visual.visible_bg_item.has_value()) {
                _mask->set_position(
                    background_visual.visible_bg_item->position().x() + 79,
                    background_visual.visible_bg_item->position().y() + 1
                );
            }

            if (_sakura_tiles_animate_action_0.has_value()) {
                _sakura_tiles_animate_action_0->update();
            }
            if (_sakura_tiles_animate_action_1.has_value()) {
                _sakura_tiles_animate_action_1->update();
            }
            if (_sakura_tiles_move_action_0.has_value()) {
                _sakura_tiles_move_action_0->update();
            }
            if (_sakura_tiles_move_action_1.has_value()) {
                _sakura_tiles_move_action_1->update();
            }

            CustomEvent::update();
        }

        void destroy() override {
            BN_LOG("HospRoomEvent::destroy");
            CustomEvent::destroy();
            _sakura_tiles_animate_action_0.reset();
            _sakura_tiles_animate_action_1.reset();
            _sakura_tiles_move_action_0.reset();
            _sakura_tiles_move_action_1.reset();
            _vfx_sakura_layer_0.reset();
            _vfx_sakura_layer_1.reset();
            _mask.reset();
        }

    private:
        bn::optional<bn::sprite_ptr> _mask;

        bn::optional<bn::regular_bg_ptr> _vfx_sakura_layer_0;
        bn::optional<bn::regular_bg_ptr> _vfx_sakura_layer_1;
        bn::regular_bg_tiles_item _vfx_sakura_tiles_items[2] = {
            bn::regular_bg_tiles_items::sakura_tiles_0,
            bn::regular_bg_tiles_items::sakura_tiles_1
        };
        bn::optional<bn::tiled_bg_animate_action<2>> _sakura_tiles_animate_action_0;
        bn::optional<bn::tiled_bg_animate_action<2>> _sakura_tiles_animate_action_1;
        bn::optional<bn::regular_bg_move_by_action> _sakura_tiles_move_action_0;
        bn::optional<bn::regular_bg_move_by_action> _sakura_tiles_move_action_1;
        bn::optional<bn::blending_transparency_alpha_to_action> _blend_action;
    };
}
#endif // HOSP_ROOM_CPP_H
