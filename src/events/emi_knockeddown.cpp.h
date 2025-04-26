#ifndef EMI_KNOCKEDDOWN_CPP_H
#define EMI_KNOCKEDDOWN_CPP_H

#include <BN_LOG.h>
#include "bn_regular_bg_items_emi_knockeddown_largepullout.h"
#include "bn_regular_bg_items_thumb_emi_knockeddown.h"

#include "custom_event.h"

namespace ks {

    namespace background_metas {
        constexpr inline background_meta emi_knockeddown(
            bn::regular_bg_items::emi_knockeddown_largepullout,
            bn::regular_bg_items::thumb_emi_knockeddown,
            0xFFFF0001);
    }

    class EmiKnockeddownEvent final : public CustomEvent {
    public:
        EmiKnockeddownEvent() = default;
        ~EmiKnockeddownEvent() override {
            _background.reset();
        };

        [[nodiscard]] bn::unique_ptr<CustomEvent> clone() const override {
            return bn::make_unique<EmiKnockeddownEvent>(*this);
        }

        void init() override {
            BN_LOG("EmiKnockeddownEvent::init");
            BN_ASSERT(_background.has_value(), "Event background is not set");
            _background->set_position(8, 0);
            SceneManager::set_background_position(8, 0);
            CustomEvent::init();
        }
        void update() override {
            CustomEvent::update();
        }
        void destroy() override {
            BN_LOG("EmiKnockeddownEvent::destroy");
            _background.reset();
            CustomEvent::destroy();
        }
    };
}
#endif // EMI_KNOCKEDDOWN_CPP_H
