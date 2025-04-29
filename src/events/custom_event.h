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

        virtual bn::unique_ptr<CustomEvent> clone() const = 0;

        virtual void init() {
            _initialized = true;
        }
        virtual void update() {
            BN_ASSERT(is_initialized(), "Custom event is not initialized!");
        }
        virtual void destroy() {
            _initialized = false;
        }

        bool is_initialized() const {
            return _initialized;
        }

    protected:
        bool _initialized = false;
    };
}

#endif //CUSTOM_EVENT_H
