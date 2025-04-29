#ifndef LILLY_SHIZU_SHOWDOWN_LILLY_CPP_H
#define LILLY_SHIZU_SHOWDOWN_LILLY_CPP_H

#include <BN_LOG.h>
#include <bn_regular_bg_actions.h>

#include "custom_event.h"

namespace ks {

    class LillyShizuShowdownLillyEvent final : public CustomEvent {
    public:
        LillyShizuShowdownLillyEvent() = default;
        ~LillyShizuShowdownLillyEvent() override {
            // _background.reset();
            _move_action.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> clone() const override {
            return bn::make_unique<LillyShizuShowdownLillyEvent>(*this);
        }

        void init() override {
            BN_LOG("LillyShizuShowdownLillyEvent::init");
            // _background->set_position(-120, -80);
            // SceneManager::set_background_position(-120, -80);

            _move_action = bn::regular_bg_move_to_action(
                primary_background.value(),
                15,
                64,
                0
            );

            CustomEvent::init();

            SceneManager::pause(15);
        }

        void update() override {
            CustomEvent::update();

            if (_move_action.has_value() && !_move_action->done()) {
                _move_action->update();
            }
        }

        void destroy() override {
            BN_LOG("LillyShizuShowdownLillyEvent::destroy");
            // _background.reset();
            _move_action.reset();
            CustomEvent::destroy();
        }

    private:
        bn::optional<bn::regular_bg_move_to_action> _move_action;
    };
}
#endif // LILLY_SHIZU_SHOWDOWN_LILLY_CPP_H
