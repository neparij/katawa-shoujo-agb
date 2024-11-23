#include "menuitem.h"

namespace ks {

MenuItem::MenuItem(void(*callback)(ks::SceneManager& scene))
    : _callback(callback) {}

SequenceType MenuItem::type() const {
    return ks::SequenceType::Menu;
}

SequenceItem* MenuItem::clone() const {
    return new MenuItem(*this);
}

void MenuItem::run(ks::SceneManager& scene) {
    if (_callback) {
        _callback(scene);
    }
}

bool MenuItem::finished() const {
    return true;
}

} // namespace ks
