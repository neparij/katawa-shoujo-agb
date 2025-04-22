#ifndef MENU_OPTIONS_CPP_H
#define MENU_OPTIONS_CPP_H

#include "menu_base.h"

namespace ks {
    class MenuOptions final : public MenuBase {
    public:
        MenuOptions() = default;
        ~MenuOptions() override {
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

#endif //MENU_OPTIONS_CPP_H
