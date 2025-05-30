#include "ks_huge_bg_item.h"
#include "bn_fixed.h"

namespace ks {
    huge_bg huge_bg_item::create_bg() const {
        return huge_bg::create(*this);
    }

    huge_bg huge_bg_item::create_bg(const bn::fixed x, const bn::fixed y) const {
        return huge_bg::create(x, y, *this);
    }
}
