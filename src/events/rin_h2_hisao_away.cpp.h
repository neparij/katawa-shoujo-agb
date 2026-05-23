#ifndef RIN_H2_HISAO_AWAY_CPP_H
#define RIN_H2_HISAO_AWAY_CPP_H

#include "custom_event.h"
#include "rin_h2_motion.cpp.h"

namespace ks {

class RinH2HisaoAwayEvent final : public CustomEvent {
public:
    RinH2HisaoAwayEvent() : CustomEvent(DISPLAYABLE_BITMASK_NONE) {}

    [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
        return bn::make_unique<RinH2HisaoAwayEvent>();
    }

    [[nodiscard]] bn::optional<bn::fixed_point> background_target_position() const override {
        return rin_h2_motion::position_for_yalign(0.15);
    }

    void init() override {
        BN_ASSERT(background_visual.visible_bg_item.has_value(), "Event background is not set");
        const bn::fixed_point pos = rin_h2_motion::position_for_yalign(0.15);
        background_visual.visible_bg_item->set_position(pos.x(), pos.y());
        SceneManager::set_background_position(pos.x().integer(), pos.y().integer());
        CustomEvent::init();
    }
};

}  // namespace ks

#endif  // RIN_H2_HISAO_AWAY_CPP_H
