#ifndef MENU_SAVES_CPP_H
#define MENU_SAVES_CPP_H

#include "menu_base.h"

namespace ks {
    class MenuSaves final : public MenuBase {
    public:
        MenuSaves() = default;
        ~MenuSaves() override {
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

#endif //MENU_SAVES_CPP_H
