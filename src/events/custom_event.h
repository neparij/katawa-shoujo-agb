#ifndef CUSTOM_EVENT_H
#define CUSTOM_EVENT_H

#include "custom_background_metas.h"

namespace ks
{
    class CustomEvent
    {
    public:
        CustomEvent() = default;
        virtual ~CustomEvent() = default;

        // virtual CustomEvent clone();

        virtual bn::unique_ptr<CustomEvent> create() const = 0;

        virtual void init() {
            _initialized = true;
        }
        virtual void update() {
            BN_ASSERT(is_initialized(), "Custom event is not initialized!");
        }
        virtual void destroy() {
            _initialized = false;
        }

        virtual bool is_blendable() {
            return false;
        }

        virtual void before_hide(void (*on_update)()) {
        }

        virtual void after_show(void (*on_update)()) {
        }

        bool is_initialized() const {
            return _initialized;
        }

    protected:
        bool _initialized = false;
    };
}

#endif //CUSTOM_EVENT_H
