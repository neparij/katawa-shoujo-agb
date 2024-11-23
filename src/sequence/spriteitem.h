#ifndef KS_SPRITEITEM_H
#define KS_SPRITEITEM_H

#include "sequenceitem.h"
#include <bn_sprite_item.h>

namespace ks {

enum class SpriteEventType {
    Show = 0,
};

class SpriteItem : public ks::SequenceItem {
public:
    explicit SpriteItem(const bn::sprite_item& item);

    SequenceType type() const override;
    SequenceItem* clone() const override;

    const bn::sprite_item& item() const;
    bool finished() const override;

private:
    bn::sprite_item _item;
};

} // namespace ks

#endif // KS_SPRITEITEM_H
