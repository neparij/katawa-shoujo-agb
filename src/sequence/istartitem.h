#ifndef KS_ISTARTITEM_H
#define KS_ISTARTITEM_H

#include "sequenceitem.h"
#include "../scenemanager.h"

namespace ks {

class IStartItem : public ks::SequenceItem {
public:
    explicit IStartItem();

    SequenceType type() const override;
    SequenceItem* clone() const override;

    bool finished() const override;
};

} // namespace ks

#endif // KS_ISTARTITEM_H
