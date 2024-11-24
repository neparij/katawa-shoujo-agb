#ifndef KS_SEQUENCEITEM_H
#define KS_SEQUENCEITEM_H

#include <bn_string.h>

namespace ks {

enum class SequenceType {
    IStart = 0,
    Background = 1,
    Dialog = 2,
    Music = 3,
    MusicStop = 4,
    MusicNotFound = 5,
    Sprite = 6,
    Assignment = 7,
    Menu = 8,
    RunLabel = 9,
    // RunLabelFinish = -1,
};

class SequenceItem {
public:
    virtual ~SequenceItem() = default;

    virtual SequenceType type() const = 0;
    virtual SequenceItem* clone() const = 0; // Pure virtual clone method
    virtual bool finished() const = 0;
};

} // namespace ks

#endif // KS_SEQUENCEITEM_H
