#include "background_item.h"
#include "background_ptr.h"
#include "bn_assert.h"

namespace ks {
    bool background_item::has_value() const {
        asserts();
        return _regular.has_value() || _affine.has_value() || _huge.has_value();
    }

    bool background_item::is_regular() const {
        asserts();
        return _regular.has_value();
    }

    bool background_item::is_affine() const {
        asserts();
        return _affine.has_value();
    }

    bool background_item::is_huge() const {
        asserts();
        return _huge.has_value();
    }

    [[nodiscard]] ks::background_ptr background_item::create_bg() {
        return create_bg(0, 0);
    }

    [[nodiscard]] ks::background_ptr background_item::create_bg(bn::fixed x, bn::fixed y) {
        BN_ASSERT(has_value(), "Background item is empty");

        if (is_regular()) {
            return ks::background_ptr(*this, _regular->create_bg(x, y));
        }

        if (is_affine()) {
            return ks::background_ptr(*this, _affine->create_bg(x, y));
        }

        if (is_huge()) {
            return ks::background_ptr(*this, _huge->create_bg(x, y));
        }

        BN_ERROR("Unknown background type");
    }

    [[nodiscard]] bn::optional<ks::background_ptr> background_item::create_bg_optional() {
        return create_bg_optional(0, 0);
    }

    [[nodiscard]] bn::optional<ks::background_ptr> background_item::create_bg_optional(bn::fixed x, bn::fixed y) {
        BN_ASSERT(has_value(), "Background item is empty");

        if (is_regular()) {
            if (auto optional = _regular->create_bg_optional(x, y); optional.has_value()) {
                return ks::background_ptr(*this, *optional);
            }
        }

        if (is_affine()) {
            if (auto optional = _affine->create_bg_optional(x, y); optional.has_value()) {
                return ks::background_ptr(*this, *optional);
            }
        }

        if (is_huge()) {
            BN_ERROR("HUGE Background doesn't support optional creation");
        }

        return bn::nullopt;
    }
}
