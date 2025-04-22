#ifndef MENU_DEBUG_ACTS_CPP_H
#define MENU_DEBUG_ACTS_CPP_H

#include "menu_base.h"

namespace ks {
    class MenuDebugActs final : public MenuBase {
    public:
        MenuDebugActs() = default;
        ~MenuDebugActs() override {
        }

        void init() override {
            MenuBase::init();
        }

        void update() override {
            MenuBase::update();
        }

        void destroy() override {
            MenuBase::destroy();
        }
    };
}

#endif //MENU_DEBUG_ACTS_CPP_H
