#ifndef MENU_MAIN_CPP_H
#define MENU_MAIN_CPP_H

#include "menu_base.h"

namespace ks {
    class MenuMain final : public MenuBase {
    public:
        MenuMain() = default;
        ~MenuMain() override {
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

#endif //MENU_MAIN_CPP_H
