#ifndef SHIZU_STRADDLE_OPEN_CPP_H
#define SHIZU_STRADDLE_OPEN_CPP_H

#include <bn_regular_bg_actions.h>

#include "custom_event.h"
#include "shizu_straddle_open_motion.cpp.h"

namespace ks {

class ShizuStraddleOpenEvent final : public CustomEvent {
public:
    ShizuStraddleOpenEvent() : CustomEvent(DISPLAYABLE_BITMASK_SHIZU_STRADDLE_OPEN) {}

    [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
        return bn::make_unique<ShizuStraddleOpenEvent>();
    }

    [[nodiscard]] bn::optional<bn::fixed_point> background_target_position() const override {
        return shizu_straddle_open_motion::position(0.7, 1.0);
    }

    void init() override {
        BN_ASSERT(background_visual.visible_bg_item.has_value(), "Event background is not set");
        const bn::fixed_point start = shizu_straddle_open_motion::position(0.7, 1.0);
        const bn::fixed_point end = shizu_straddle_open_motion::position(0, 0);
        background_visual.visible_bg_item->set_position(start.x(), start.y());
        SceneManager::set_background_position(start.x().integer(), start.y().integer());
        _move_action = bn::regular_bg_move_to_action(
            background_visual.visible_bg_item->regular_ptr(),
            shizu_straddle_open_motion::PAN_DURATION,
            end.x(),
            end.y());
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

#endif  // SHIZU_STRADDLE_OPEN_CPP_H
