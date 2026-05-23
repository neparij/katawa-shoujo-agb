#include "regular_composite_bg_item.h"

#include "background_item.h"
#include "background_ptr.h"
#include "composite_bg_runtime.h"

namespace ks {

    bn::optional<background_ptr> regular_composite_bg_item::create_background_ptr(
            const background_item& owner, bn::fixed x, bn::fixed y) const {
        composite_bg_state* state = composite_bg_runtime::alloc_state();
        bn::optional<bn::regular_bg_ptr> regular =
                composite_bg_runtime::create_regular_bg(*this, x, y, *state);
        if(! regular) {
            composite_bg_runtime::free_state(state);
            return bn::nullopt;
        }
        return background_ptr(owner, *regular, state);
    }

    bn::regular_bg_ptr regular_composite_bg_item::create_bg(bn::fixed x, bn::fixed y) const {
        background_item owner(*this);
        if(auto optional = create_background_ptr(owner, x, y); optional.has_value()) {
            return optional->regular_ptr();
        }
        BN_ERROR("regular_composite_bg_item::create_bg failed");
    }

    bn::optional<bn::regular_bg_ptr> regular_composite_bg_item::create_bg_optional(
            bn::fixed x, bn::fixed y) const {
        background_item owner(*this);
        if(auto optional = create_background_ptr(owner, x, y); optional.has_value()) {
            return optional->regular_ptr();
        }
        return bn::nullopt;
    }

}  // namespace ks
