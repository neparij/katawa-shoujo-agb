#include "spriteitem.h"

namespace ks {

SpriteItem::SpriteItem(const bn::sprite_item& item)
    : _item(item) {}

SequenceType SpriteItem::type() const {
    return ks::SequenceType::Sprite;
}

SequenceItem* SpriteItem::clone() const {
    return new SpriteItem(*this);
}

const bn::sprite_item& SpriteItem::item() const {
    return _item;
}

bool SpriteItem::finished() const {
    return true;
}

} // namespace ks
