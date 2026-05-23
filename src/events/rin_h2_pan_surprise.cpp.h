#ifndef RIN_H2_PAN_SURPRISE_CPP_H
#define RIN_H2_PAN_SURPRISE_CPP_H

#include <bn_regular_bg_actions.h>

#include "custom_event.h"
#include "rin_h2_motion.cpp.h"

namespace ks {

class RinH2PanSurpriseEvent final : public CustomEvent {
public:
    RinH2PanSurpriseEvent() : CustomEvent(DISPLAYABLE_BITMASK_NONE) {}

    [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
        return bn::make_unique<RinH2PanSurpriseEvent>();
    }

    void init() override {
        BN_ASSERT(background_visual.visible_bg_item.has_value(), "Event background is not set");
        const bn::fixed_point start = rin_h2_motion::position(
            rin_h2_motion::RIN_H2_TOP_LEFT_X, 0);
        const bn::fixed_point end = rin_h2_motion::position_for_yalign(0.15);
        background_visual.visible_bg_item->set_position(start.x(), start.y());
        SceneManager::set_background_position(start.x().integer(), start.y().integer());
        _move_action = bn::regular_bg_move_to_action(
            background_visual.visible_bg_item->regular_ptr(),
            300,
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

#endif  // RIN_H2_PAN_SURPRISE_CPP_H
