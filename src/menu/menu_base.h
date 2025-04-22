#ifndef MENU_BASE_H
#define MENU_BASE_H

namespace ks {
    class MenuBase
    {
    public:
        MenuBase() = default;
        virtual ~MenuBase() = default;

        virtual void init() {
        }
        virtual void update() {
        }
        virtual void destroy() {
        }
    };
}

#endif //MENU_BASE_H
