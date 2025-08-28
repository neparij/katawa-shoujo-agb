#ifndef BACKGROUND_PTR_H
#define BACKGROUND_PTR_H

#include "background_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_affine_bg_ptr.h"
#include "ks_huge_bg.h"

namespace ks {

    class background_ptr {
    public:
        explicit constexpr background_ptr(const ks::background_item &item, const bn::regular_bg_ptr &regular_ptr)
            : _item(item),
              _regular_ptr(regular_ptr),
              _affine_ptr(bn::nullopt),
              _huge_ptr(bn::nullopt) {
        }

        explicit constexpr background_ptr(const ks::background_item &item, const bn::affine_bg_ptr &affine_ptr)
            : _item(item),
              _regular_ptr(bn::nullopt),
              _affine_ptr(affine_ptr),
              _huge_ptr(bn::nullopt) {
        }

        explicit constexpr background_ptr(const ks::background_item &item, const huge_bg &huge_ptr)
            : _item(item),
              _regular_ptr(bn::nullopt),
              _affine_ptr(bn::nullopt),
              // _huge_ptr(huge_ptr) {
              _huge_ptr(bn::nullopt) {
        }

        explicit constexpr background_ptr(const ks::background_item &item, bn::nullopt_t null)
            : _item(item),
              _regular_ptr(bn::nullopt),
              _affine_ptr(bn::nullopt),
              _huge_ptr(bn::nullopt) {
        }

        // Move constructor and assignment
        background_ptr(background_ptr&&) noexcept = default;
        background_ptr& operator=(background_ptr&&) noexcept = default;

        // Copy constructor and assignment
        background_ptr(const background_ptr&) = default;
        background_ptr& operator=(const background_ptr&) = default;

        ~background_ptr() = default;

        const ks::background_item& item() const;
        const bn::regular_bg_ptr& regular_ptr() const;
        const bn::affine_bg_ptr& affine_ptr() const;
        const bn::fixed_point& position() const;
        void set_position(bn::fixed x, bn::fixed y);
        void set_priority(int priority);
        void set_z_order(int order);
        void set_blending_enabled(bool enabled);

    private:
        ks::background_item _item;
        bn::optional<bn::regular_bg_ptr> _regular_ptr;
        bn::optional<bn::affine_bg_ptr> _affine_ptr;
        bn::optional<ks::huge_bg> _huge_ptr;
    };
}

#endif //BACKGROUND_PTR_H
