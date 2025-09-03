#ifndef EMI_KNOCKEDDOWN_LARGEPULLOUT_CPP_H
#define EMI_KNOCKEDDOWN_LARGEPULLOUT_CPP_H

#include <bn_log.h>
#include <bn_regular_bg_actions.h>

#include "custom_event.h"

namespace ks {

    class EmiKnockeddownLargepulloutEvent final : public CustomEvent {
    public:
        EmiKnockeddownLargepulloutEvent() = default;
        ~EmiKnockeddownLargepulloutEvent() override {
            _move_action.reset();
            // _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
            return bn::make_unique<EmiKnockeddownLargepulloutEvent>();
        }

        void init() override {
            BN_LOG("EmiKnockeddownLargepulloutEvent::init");
            BN_ASSERT(background_visual.visible_bg_item.has_value(), "Event background is not set");
            _move_action = bn::regular_bg_move_to_action(
                background_visual.visible_bg_item->regular_ptr(),
                60,
                8,
                0
            );
            CustomEvent::init();
        }
        void update() override {
            // BN_LOG("EmiKnockeddownLargepulloutEvent::update");
            CustomEvent::update();
            if (_move_action.has_value() && !_move_action->done()) {
                _move_action->update();
            }
        }
        void destroy() override {
            BN_LOG("EmiKnockeddownLargepulloutEvent::destroy");
            _move_action.reset();
            // _background.reset();
            CustomEvent::destroy();
        }

    private:
        bn::optional<bn::regular_bg_move_to_action> _move_action;
    };
}
#endif // EMI_KNOCKEDDOWN_LARGEPULLOUT_CPP_H
