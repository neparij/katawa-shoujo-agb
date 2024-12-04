#include "musicitem.h"

namespace ks {

// MusicItem implementation
MusicItem::MusicItem(const char* item)
    : _item(item) {}

MusicItem::MusicItem(const char* item, bn::fixed fade)
    : _item(item) {}

SequenceType MusicItem::type() const {
    return ks::SequenceType::Music;
}

SequenceItem* MusicItem::clone() const {
    return new MusicItem(*this);
}

const char* MusicItem::item() const {
    return _item;
}

bool MusicItem::finished() const {
    return true;
}

// MusicStopItem implementation
MusicStopItem::MusicStopItem(const bn::string<8>& name, bn::fixed value)
    : _name(name), _value(value) {}

MusicStopItem::MusicStopItem()
    : _name(""), _value(0) {}

SequenceType MusicStopItem::type() const {
    return ks::SequenceType::MusicStop;
}

SequenceItem* MusicStopItem::clone() const {
    return new MusicStopItem(*this);
}

bool MusicStopItem::finished() const {
    return true;
}

//MusicNotFoundItem implementation
MusicNotFoundItem::MusicNotFoundItem(){}

SequenceType MusicNotFoundItem::type() const {
    return ks::SequenceType::MusicNotFound;
}

SequenceItem* MusicNotFoundItem::clone() const {
    return new MusicNotFoundItem(*this);
}

bool MusicNotFoundItem::finished() const {
    return true;
}

} // namespace ks
