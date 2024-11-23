#ifndef KS_DIALOGITEM_H
#define KS_DIALOGITEM_H

#include "sequenceitem.h"
#include <bn_string.h>

namespace ks {

class DialogItem : public ks::SequenceItem {
public:
    DialogItem(const bn::string<16>& title, const bn::string<512>& message);

    SequenceType type() const override;
    SequenceItem* clone() const override;

    const bn::string<16>& title() const;
    const bn::string<512>& message() const;

    bool finished() const override;
    void finished(bool flag);

private:
    bn::string<16> _title;
    bn::string<512> _message;
    bool _finished = false;
};

} // namespace ks

#endif // KS_DIALOGITEM_H
