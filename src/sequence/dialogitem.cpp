#include "dialogitem.h"

namespace ks {

DialogItem::DialogItem(const bn::string<16>& title, const bn::string<512>& message)
    : _title(title), _message(message) {}

SequenceType DialogItem::type() const {
    return ks::SequenceType::Dialog;
}

SequenceItem* DialogItem::clone() const {
    return new DialogItem(*this);
}

const bn::string<16>& DialogItem::title() const {
    return _title;
}

const bn::string<512>& DialogItem::message() const {
    return _message;
}

bool DialogItem::finished() const {
    return _finished;
}

void DialogItem::finished(bool flag) {
    _finished = flag;
}

} // namespace ks
