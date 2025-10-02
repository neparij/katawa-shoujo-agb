#ifndef CUSTOM_EVENT_H
#define CUSTOM_EVENT_H

#include "custom_background_metas.h"

namespace ks
{
    class CustomEvent
    {
    public:
        explicit CustomEvent(const displayable_bitmask_t displayable_bitmask)
            : _displayable_bitmask(displayable_bitmask),
              _initialized(false),
              _state(0) {
        }
        virtual ~CustomEvent() = default;

        // virtual CustomEvent clone();

        virtual bn::unique_ptr<CustomEvent> create() const = 0;

        virtual void init() {
            _initialized = true;
            if (_displayable_bitmask != DISPLAYABLE_BITMASK_NONE && globals::in_game) {
                globals::states.set_seen_displayable(_displayable_bitmask, true);
            }
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

        virtual void before_hide([[maybe_unused]] void (*on_update)()) {
        }

        virtual void after_show([[maybe_unused]] void (*on_update)()) {
        }

        virtual void set_state(const int state) {
            _state = state;
        }

        int get_state() const {
            return _state;
        }

        bool is_initialized() const {
            return _initialized;
        }

        [[nodiscard]] displayable_bitmask_t get_displayable_bitmask() const {
            return _displayable_bitmask;
        }

    private:
        displayable_bitmask_t _displayable_bitmask;

    protected:
        bool _initialized = false;
        int _state = 0;
    };
}

#endif //CUSTOM_EVENT_H
