#ifndef HISAO_CLASS_END_CPP_H
#define HISAO_CLASS_END_CPP_H

#include <bn_log.h>

#include "custom_event.h"

namespace ks {
    class HisaoClassEndEvent final : public CustomEvent {
    public:
        HisaoClassEndEvent() = default;
        ~HisaoClassEndEvent() override {
            // _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> create() const override {
            return bn::make_unique<HisaoClassEndEvent>();
        }

        void init() override {
            BN_LOG("HisaoClassEndEvent::init");
            background_visual.visible_bg_item->set_position(-120, 0);
            SceneManager::set_background_position(-120, 0);
            CustomEvent::init();
        }

        void update() override {
            CustomEvent::update();
        }

        void destroy() override {
            BN_LOG("HisaoClassEndEvent::destroy");
            // _background.reset();
            CustomEvent::destroy();
        }
    };
}
#endif // HISAO_CLASS_END_CPP_H
