#ifndef EMI_KNOCKEDDOWN_CPP_H
#define EMI_KNOCKEDDOWN_CPP_H

#include <BN_LOG.h>
#include "custom_event.h"

namespace ks {

    class EmiKnockeddownEvent final : public CustomEvent {
    public:
        EmiKnockeddownEvent() = default;
        ~EmiKnockeddownEvent() override {
            // _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> clone() const override {
            return bn::make_unique<EmiKnockeddownEvent>(*this);
        }

        void init() override {
            BN_LOG("EmiKnockeddownEvent::init");
            BN_ASSERT(primary_background.has_value(), "Event background is not set");
            primary_background->set_position(8, 0);
            SceneManager::set_background_position(8, 0);
            CustomEvent::init();
        }
        void update() override {
            CustomEvent::update();
        }
        void destroy() override {
            BN_LOG("EmiKnockeddownEvent::destroy");
            // primary_background.reset();
            CustomEvent::destroy();
        }
    };
}
#endif // EMI_KNOCKEDDOWN_CPP_H
