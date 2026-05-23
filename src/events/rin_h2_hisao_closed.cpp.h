#ifndef RIN_H2_HISAO_CLOSED_CPP_H
#define RIN_H2_HISAO_CLOSED_CPP_H

#include <bn_regular_bg_actions.h>

#include "custom_event.h"
#include "rin_h2_motion.cpp.h"

namespace ks {

class RinH2HisaoClosedEvent final : public CustomEvent {
public:
    RinH2HisaoClosedEvent() : CustomEvent(DISPLAYABLE_BITMASK_NONE) {}

    [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
        return bn::make_unique<RinH2HisaoClosedEvent>();
    }

    void init() override {
        BN_ASSERT(background_visual.visible_bg_item.has_value(), "Event background is not set");
        const bn::fixed_point end = rin_h2_motion::position_for_yalign(0.15);
        _move_action = bn::regular_bg_move_to_action(
            background_visual.visible_bg_item->regular_ptr(),
            480,
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

#endif  // RIN_H2_HISAO_CLOSED_CPP_H
