#include "backgrounditem.h"

namespace ks {

BackgroundItem::BackgroundItem(const bn::regular_bg_item& item)
    : _item(item) {}

SequenceType BackgroundItem::type() const {
    return ks::SequenceType::Background;
}

SequenceItem* BackgroundItem::clone() const {
    return new BackgroundItem(*this);
}

const bn::regular_bg_item& BackgroundItem::item() const {
    return _item;
}

bool BackgroundItem::finished() const {
    return true;
}

} // namespace ks
