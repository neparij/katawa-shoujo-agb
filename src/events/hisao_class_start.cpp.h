#ifndef HISAO_CLASS_START_CPP_H
#define HISAO_CLASS_START_CPP_H

#include <bn_log.h>
#include <bn_regular_bg_actions.h>

#include "custom_event.h"

namespace ks {
    class HisaoClassStartEvent final : public CustomEvent {
    public:
        HisaoClassStartEvent() = default;
        ~HisaoClassStartEvent() override {
            // _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
            return bn::make_unique<HisaoClassStartEvent>();
        }

        void init() override {
            BN_LOG("HisaoClassStartEvent::init");
            background_visual.visible_bg_item->set_position(0, 0);
            SceneManager::set_background_position(0, 0);
            CustomEvent::init();
        }

        void update() override {
            CustomEvent::update();
        }

        void destroy() override {
            BN_LOG("HisaoClassStartEvent::destroy");
            // _background.reset();
            CustomEvent::destroy();
        }
    };
}
#endif // HISAO_CLASS_START_CPP_H
