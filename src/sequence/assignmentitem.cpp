#include "assignmentitem.h"

namespace ks {

AssignmentItem::AssignmentItem(const bn::string<128>& assignment)
    : _assignment(assignment) {}

SequenceType AssignmentItem::type() const {
    return ks::SequenceType::Assignment;
}

SequenceItem* AssignmentItem::clone() const {
    return new AssignmentItem(*this);
}

bool AssignmentItem::finished() const {
    return true;
}

} // namespace ks
