#ifndef MENU_EXTRAS_CPP_H
#define MENU_EXTRAS_CPP_H

#include "menu_base.h"

namespace ks {
    class MenuExtras final : public MenuBase {
    public:
        MenuExtras() = default;
        ~MenuExtras() override {
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

#endif //MENU_EXTRAS_CPP_H
