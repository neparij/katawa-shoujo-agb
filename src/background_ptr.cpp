#include "background_item.h"
#include "background_ptr.h"

namespace ks {

    const ks::background_item& background_ptr::item() const {
        return _item;
    }

    const bn::regular_bg_ptr & background_ptr::regular_ptr() const {
        if (_regular_ptr.has_value()) {
            return *_regular_ptr;
        }
        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr();
        }
        BN_ERROR("regular_ptr: Background pointer is not regular");
    }

    const bn::affine_bg_ptr & background_ptr::affine_ptr() const {
        if (_affine_ptr.has_value()) {
            return *_affine_ptr;
        }
        BN_ERROR("affine_ptr: Background pointer is not affine");
    }

    const bn::fixed_point& background_ptr::position() const {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->position();
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->position();
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->position();
        }

        BN_ERROR("position: Background pointer has no value");
    }

    void background_ptr::set_position(bn::fixed x, bn::fixed y) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_position(x, y);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_position(x, y);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_top_left_position(x, y);
        }

        BN_ERROR("set_position: Background pointer has no value");
    }

    void background_ptr::set_priority(int priority) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_priority(priority);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_priority(priority);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_priority(priority);
        }

        BN_ERROR("set_priority: Background pointer has no value");
    }

    void background_ptr::set_z_order(int order) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_z_order(order);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_z_order(order);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_z_order(order);
        }

        BN_ERROR("set_z_order: Background pointer has no value");
    }

    void background_ptr::set_blending_enabled(bool enabled) {
        if (_regular_ptr.has_value()) {
            return _regular_ptr->set_blending_enabled(enabled);
        }

        if (_affine_ptr.has_value()) {
            return _affine_ptr->set_blending_enabled(enabled);
        }

        if (_huge_ptr.has_value()) {
            return _huge_ptr->regular_bg_ptr().set_blending_enabled(enabled);
        }

        BN_ERROR("set_blending_enabled: Background pointer has no value");
    }
}
