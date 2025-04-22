#ifndef MENU_EXTRAS_CINEMA_CPP_H
#define MENU_EXTRAS_CINEMA_CPP_H

#include "menu_base.h"

namespace ks {
    class MenuExtrasCinema final : public MenuBase {
    public:
        MenuExtrasCinema() = default;
        ~MenuExtrasCinema() override {
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

#endif //MENU_EXTRAS_CINEMA_CPP_H
