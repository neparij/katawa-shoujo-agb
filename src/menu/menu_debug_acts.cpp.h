#ifndef MENU_DEBUG_ACTS_CPP_H
#define MENU_DEBUG_ACTS_CPP_H

#include "menu_base.h"

namespace ks {
    class MenuDebugActs final : public MenuBase {
    public:
        explicit MenuDebugActs(gameState_t &state): MenuBase(state) {}
        ~MenuDebugActs() override {
        }
    };
}

#endif //MENU_DEBUG_ACTS_CPP_H
