#ifndef EMI_KNOCKEDDOWN_LEGS_CPP_H
#define EMI_KNOCKEDDOWN_LEGS_CPP_H

#include <BN_LOG.h>
#include <bn_regular_bg_actions.h>

#include "custom_event.h"

namespace ks {
    class EmiKnockeddownLegsEvent final : public CustomEvent {
    public:
        EmiKnockeddownLegsEvent() = default;
        ~EmiKnockeddownLegsEvent() override {
            _move_action.reset();
            _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> clone() const override {
            return bn::make_unique<EmiKnockeddownLegsEvent>(*this);
        }

        void init() override {
            BN_LOG("EmiKnockeddownLegsEvent::init");
            BN_ASSERT(_background.has_value(), "Event background is not set");
            _move_action = bn::regular_bg_move_to_action(
                _background.value(),
                480,
                -104,
                -32
            );
            CustomEvent::init();
        }
        void update() override {
            CustomEvent::update();
            // BN_LOG("EmiKnockeddownLegsEvent::update");
            if (_move_action.has_value() && !_move_action->done()) {
                _move_action->update();
            }
        }
        void destroy() override {
            BN_LOG("EmiKnockeddownLegsEvent::destroy");
            _move_action.reset();
            _background.reset();
            CustomEvent::destroy();
        }

    private:
        bn::optional<bn::regular_bg_move_to_action> _move_action;
    };
}
#endif // EMI_KNOCKEDDOWN_LEGS_CPP_H
