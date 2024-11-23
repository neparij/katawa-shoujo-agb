#include "istartitem.h"


namespace ks {

IStartItem::IStartItem(){}

SequenceType IStartItem::type() const {
    return ks::SequenceType::RunLabel;
}

SequenceItem* IStartItem::clone() const {
    return new IStartItem(*this);
}

bool IStartItem::finished() const {
    return true;
}

} // namespace ks
