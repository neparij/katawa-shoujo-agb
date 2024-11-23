#ifndef KS_ASSIGNMENTITEM_H
#define KS_ASSIGNMENTITEM_H

#include "sequenceitem.h"
#include <bn_string.h>

namespace ks {

class AssignmentItem : public ks::SequenceItem {
public:
    explicit AssignmentItem(const bn::string<128>& assignment);

    SequenceType type() const override;
    SequenceItem* clone() const override;
    bool finished() const override;

private:
    bn::string<128> _assignment;
};

} // namespace ks

#endif // KS_ASSIGNMENTITEM_H
