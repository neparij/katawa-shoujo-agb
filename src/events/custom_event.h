#ifndef CUSTOM_EVENT_H
#define CUSTOM_EVENT_H

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

        }

        void set_background(const bn::regular_bg_ptr &bg) {
            _background = bg;
        }

        bool is_initialized() const {
            return _initialized;
        }

    protected:
        bn::optional<bn::regular_bg_ptr> _background;
        bool _initialized = false;
    };
}

#endif //CUSTOM_EVENT_H
