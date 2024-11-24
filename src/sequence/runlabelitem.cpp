#include "runlabelitem.h"

namespace ks {

RunLabelItem::RunLabelItem(void(*callback)(ks::SceneManager& scene))
    : _callback(callback) {}
// RunLabelItem::RunLabelItem(void(*callback)(ks::SceneManager&)) :
//     _callback(callback) {}

SequenceType RunLabelItem::type() const {
    return ks::SequenceType::RunLabel;
}

SequenceItem* RunLabelItem::clone() const {
    return new RunLabelItem(*this);
}
// SequenceItem* RunLabelItem::clone() const {
//     return new RunLabelItem(_callback); // Clone with the same callback
// }

void RunLabelItem::run(ks::SceneManager& scene) {
    if (_callback) {
        _callback(scene);
    }
}

bool RunLabelItem::finished() const {
    return true;
}

} // namespace ks
