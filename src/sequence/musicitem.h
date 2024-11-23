#ifndef KS_MUSICITEM_H
#define KS_MUSICITEM_H

#include "sequenceitem.h"
#include <bn_music_item.h>
#include <bn_string.h>

namespace ks {

class MusicItem : public ks::SequenceItem {
public:
    explicit MusicItem(const bn::music_item& item);
    explicit MusicItem(const bn::music_item& item, float fade);

    SequenceType type() const override;
    SequenceItem* clone() const override;
    const bn::music_item& item() const;
    bool finished() const override;

private:
    bn::music_item _item;
};

class MusicStopItem : public ks::SequenceItem {
public:
    MusicStopItem(const bn::string<8>& name, float value);

    SequenceType type() const override;
    SequenceItem* clone() const override;
    bool finished() const override;

private:
    bn::string<8> _name;
    float _value;
};

} // namespace ks

#endif // KS_MUSICITEM_H
