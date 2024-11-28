#ifndef KS_MUSICITEM_H
#define KS_MUSICITEM_H

#include "sequenceitem.h"
#include <bn_music_item.h>
#include <bn_string.h>

namespace ks {

class MusicItem : public ks::SequenceItem {
public:
    explicit MusicItem(const char* item);
    explicit MusicItem(const char* item, bn::fixed fade);

    SequenceType type() const override;
    SequenceItem* clone() const override;
    const char* item() const;
    bool finished() const override;

private:
    const char* _item;
};

class MusicStopItem : public ks::SequenceItem {
public:
    MusicStopItem(const bn::string<8>& name, bn::fixed value);
    MusicStopItem();

    SequenceType type() const override;
    SequenceItem* clone() const override;
    bool finished() const override;

private:
    bn::string<8> _name;
    bn::fixed _value;
};

class MusicNotFoundItem : public ks::SequenceItem {
public:
    explicit MusicNotFoundItem();

    SequenceType type() const override;
    SequenceItem* clone() const override;
    bool finished() const override;
};

} // namespace ks

#endif // KS_MUSICITEM_H
