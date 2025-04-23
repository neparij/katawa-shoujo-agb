#ifndef EMI_KNOCKEDDOWN_FACEPULLOUT_CPP_H
#define EMI_KNOCKEDDOWN_FACEPULLOUT_CPP_H

#include <BN_LOG.h>
#include <bn_regular_bg_actions.h>
#include "bn_regular_bg_items_emi_knockeddown_facepullout.h"
#include "bn_sprite_items_thumb_emi_knockeddown.h"

#include "custom_event.h"

namespace ks {

    namespace background_metas {
        constexpr inline background_meta emi_knockeddown_facepullout(
            bn::regular_bg_items::emi_knockeddown_facepullout,
            bn::sprite_items::thumb_emi_knockeddown,
            0xFFFF0002);
    }

    class EmiKnockeddownFacepulloutEvent final : public CustomEvent {
    public:
        EmiKnockeddownFacepulloutEvent() = default;
        ~EmiKnockeddownFacepulloutEvent() override {
            _move_action.reset();
            _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> clone() const override {
            return bn::make_unique<EmiKnockeddownFacepulloutEvent>(*this);
        }

        void init() override {
            BN_LOG("EmiKnockeddownFacepulloutEvent::init");
            BN_ASSERT(_background.has_value(), "Event background is not set");
            _move_action = bn::regular_bg_move_to_action(
                _background.value(),
                180,
                0,
                16
            );
            CustomEvent::init();
        }
        void update() override {
            CustomEvent::update();
            if (_move_action.has_value() && !_move_action->done()) {
                _move_action->update();
            }
        }
        void destroy() override {
            BN_LOG("EmiKnockeddownFacepulloutEvent::destroy");
            _move_action.reset();
            _background.reset();
            CustomEvent::destroy();
        }

    private:
        bn::optional<bn::regular_bg_move_to_action> _move_action;
    };
}
#endif // EMI_KNOCKEDDOWN_FACEPULLOUT_CPP_H
