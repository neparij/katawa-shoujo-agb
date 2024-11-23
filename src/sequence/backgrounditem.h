#ifndef KS_BACKGROUNDITEM_H
#define KS_BACKGROUNDITEM_H

#include "sequenceitem.h"
#include <bn_regular_bg_item.h>

namespace ks {

class BackgroundItem : public ks::SequenceItem {
public:
    explicit BackgroundItem(const bn::regular_bg_item& item);

    SequenceType type() const override;
    SequenceItem* clone() const override;
    const bn::regular_bg_item& item() const;
    bool finished() const override;

private:
    bn::regular_bg_item _item;
};

} // namespace ks

#endif // KS_BACKGROUNDITEM_H
