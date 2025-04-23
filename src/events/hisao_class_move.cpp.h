#ifndef HISAO_CLASS_MOVE_CPP_H
#define HISAO_CLASS_MOVE_CPP_H

#include <BN_LOG.h>
#include <bn_regular_bg_actions.h>

#include "custom_event.h"
#include "hisao_class.h"

namespace ks {
    class HisaoClassMoveEvent final : public CustomEvent {
    public:
        HisaoClassMoveEvent() = default;
        ~HisaoClassMoveEvent() override {
            _move_action.reset();
            _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> clone() const override {
            return bn::make_unique<HisaoClassMoveEvent>(*this);
        }

        void init() override {
            BN_LOG("HisaoClassMoveEvent::init");
            BN_ASSERT(_background.has_value(), "Event background is not set");
            _move_action = bn::regular_bg_move_to_action(
                _background.value(),
                2000,
                -120,
                0
            );
            CustomEvent::init();
        }
        void update() override {
            CustomEvent::update();
            BN_LOG("HisaoClassMoveEvent::update");
            if (_move_action.has_value() && !_move_action->done()) {
                _move_action->update();
            }
        }
        void destroy() override {
            BN_LOG("HisaoClassMoveEvent::destroy");
            _move_action.reset();
            _background.reset();
            CustomEvent::destroy();
        }

    private:
        bn::optional<bn::regular_bg_move_to_action> _move_action;
    };
}
#endif // HISAO_CLASS_MOVE_CPP_H
