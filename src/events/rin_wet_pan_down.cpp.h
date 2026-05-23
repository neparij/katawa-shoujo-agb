#ifndef RIN_WET_PAN_DOWN_CPP_H
#define RIN_WET_PAN_DOWN_CPP_H

#include <bn_regular_bg_actions.h>

#include "custom_event.h"

namespace ks {

class RinWetPanDownEvent final : public CustomEvent {
public:
    RinWetPanDownEvent() : CustomEvent(DISPLAYABLE_BITMASK_RIN_WET_PAN_DOWN) {}

    [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
        return bn::make_unique<RinWetPanDownEvent>();
    }

    [[nodiscard]] bn::optional<bn::fixed_point> background_target_position() const override {
        return bn::fixed_point(-128, -32);
    }

    void init() override {
        BN_ASSERT(background_visual.visible_bg_item.has_value(), "Event background is not set");
        background_visual.visible_bg_item->set_position(-128, -32);
        SceneManager::set_background_position(-128, -32);
        _move_action = bn::regular_bg_move_to_action(
            background_visual.visible_bg_item->regular_ptr(),
            600,
            -128,
            48);
        CustomEvent::init();
    }

    void update() override {
        CustomEvent::update();
        if(_move_action.has_value() && !_move_action->done()) {
            _move_action->update();
        }
    }

    void destroy() override {
        _move_action.reset();
        CustomEvent::destroy();
    }

private:
    bn::optional<bn::regular_bg_move_to_action> _move_action;
};

}  // namespace ks

#endif  // RIN_WET_PAN_DOWN_CPP_H
