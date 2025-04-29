#ifndef LILLY_SHIZU_SHOWDOWN_SLICES_CPP_H
#define LILLY_SHIZU_SHOWDOWN_SLICES_CPP_H

#include <BN_LOG.h>
#include <bn_regular_bg_actions.h>

#include "custom_event.h"

namespace ks {

    class LillyShizuShowdownSlicesEvent final : public CustomEvent {
    public:
        LillyShizuShowdownSlicesEvent() = default;
        ~LillyShizuShowdownSlicesEvent() override {
            // _background.reset();
            secondary_background.reset();
            _lilly_move_action.reset();
            _shizu_move_action.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> clone() const override {
            return bn::make_unique<LillyShizuShowdownSlicesEvent>(*this);
        }

        void init() override {
            BN_LOG("LillyShizuShowdownSlicesEvent::init");
            CustomEvent::init();
            primary_background->set_position(-240, 0);
            SceneManager::set_background_position(-240, 0);

            _lilly_move_action = bn::regular_bg_move_to_action(
                primary_background.value(),
                15,
                0,
                0
            );
            SceneManager::sfx_play("sfx_draw.8ad", SOUND_CHANNEL_SOUND);
            SceneManager::pause(30);

            secondary_background.reset();
            secondary_background = bn::regular_bg_items::lilly_shizu_showdown_slices_shizu.create_bg(240, 0);

            _shizu_move_action = bn::regular_bg_move_to_action(
                secondary_background.value(),
                15,
                0,
                0
            );
            SceneManager::sfx_play("sfx_draw.8ad", SOUND_CHANNEL_SOUND);
            SceneManager::pause(30);
        }

        void update() override {
            CustomEvent::update();

            if (_lilly_move_action.has_value() && !_lilly_move_action->done()) {
                _lilly_move_action->update();
            }
            if (_shizu_move_action.has_value() && !_shizu_move_action->done()) {
                _shizu_move_action->update();
            }
        }

        void destroy() override {
            BN_LOG("LillyShizuShowdownSlicesEvent::destroy");
            // _background.reset();
            // secondary_background.reset();
            _lilly_move_action.reset();
            _shizu_move_action.reset();
            CustomEvent::destroy();
        }

    private:
        bn::optional<bn::regular_bg_move_to_action> _lilly_move_action;
        bn::optional<bn::regular_bg_move_to_action> _shizu_move_action;
    };
}
#endif // LILLY_SHIZU_SHOWDOWN_SLICES_CPP_H
