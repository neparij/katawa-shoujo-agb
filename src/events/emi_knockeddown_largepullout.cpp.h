#ifndef EMI_KNOCKEDDOWN_LARGEPULLOUT_CPP_H
#define EMI_KNOCKEDDOWN_LARGEPULLOUT_CPP_H

#include <BN_LOG.h>
#include <bn_regular_bg_actions.h>
#include "bn_regular_bg_items_emi_knockeddown_largepullout.h"
#include "bn_sprite_items_thumb_emi_knockeddown.h"

#include "custom_event.h"

namespace ks {

    namespace background_metas {
        constexpr inline background_meta emi_knockeddown_largepullout(
            bn::regular_bg_items::emi_knockeddown_largepullout,
            bn::sprite_items::thumb_emi_knockeddown,
            0xFFFF0003);
    }

    class EmiKnockeddownLargepulloutEvent final : public CustomEvent {
    public:
        EmiKnockeddownLargepulloutEvent() = default;
        ~EmiKnockeddownLargepulloutEvent() override {
            _move_action.reset();
            _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> clone() const override {
            return bn::make_unique<EmiKnockeddownLargepulloutEvent>(*this);
        }

        void init() override {
            BN_LOG("EmiKnockeddownLargepulloutEvent::init");
            BN_ASSERT(_background.has_value(), "Event background is not set");
            _move_action = bn::regular_bg_move_to_action(
                _background.value(),
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
            _background.reset();
            CustomEvent::destroy();
        }

    private:
        bn::optional<bn::regular_bg_move_to_action> _move_action;
    };
}
#endif // EMI_KNOCKEDDOWN_LARGEPULLOUT_CPP_H
