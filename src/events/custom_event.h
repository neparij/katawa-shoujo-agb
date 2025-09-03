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

        virtual bool is_blendable() {
            return false;
        }

        /// Perform show blend effect. Returns true if blend effect is performed, false otherwise.
        virtual bool show_blend() {
            return true;
        }

        /// Perform hide blend effect. Returns true if blend effect is performed, false otherwise.
        virtual bool hide_blend() {
            return true;
        }

        bool is_initialized() const {
            return _initialized;
        }

    protected:
        bool _initialized = false;
    };
}

#endif //CUSTOM_EVENT_H
