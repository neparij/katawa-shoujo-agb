#ifndef BACKGROUND_ITEM_H
#define BACKGROUND_ITEM_H

// #include "background_ptr.h"  // Removed to break circular dependency
#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_regular_bg_item.h"
#include "bn_affine_bg_item.h"
#include "ks_huge_bg_item.h"

namespace ks {
    class background_ptr; // <-- forward declaration

    class background_item {
    public:
        explicit constexpr background_item(const bn::regular_bg_item &regular_bg)
            : _regular(regular_bg),
              _affine(bn::nullopt),
              _huge(bn::nullopt) {
        }

        explicit constexpr background_item(const bn::affine_bg_item &affine_bg)
            : _regular(bn::nullopt),
              _affine(affine_bg),
              _huge(bn::nullopt) {
        }

        explicit constexpr background_item(const ks::huge_bg_item &huge_bg)
            : _regular(bn::nullopt),
              _affine(bn::nullopt),
              _huge(huge_bg) {
        }

        // Copy constructor and assignment
        constexpr background_item(const background_item &) = default;

        constexpr background_item &operator=(const background_item &) = default;

        // Move constructor and assignment
        constexpr background_item(background_item &&other) noexcept
            : _regular(bn::move(other._regular)),
              _affine(bn::move(other._affine)),
              _huge(bn::move(other._huge)) {
        }

        constexpr background_item &operator=(background_item &&other) noexcept {
            if (this != &other) {
                _regular = bn::move(other._regular);
                _affine = bn::move(other._affine);
                _huge = bn::move(other._huge);
            }
            return *this;
        }

        // Destructor
        constexpr ~background_item() = default;


        bool operator==(const ks::background_item &other) const {
            return _regular == other._regular &&
                   _affine == other._affine &&
                   _huge == other._huge;
        }

        bool operator!=(const ks::background_item &other) const {
            return !(*this == other);
        }

        bool has_value() const;

        bool is_regular() const;

        bool is_affine() const;

        bool is_huge() const;

        [[nodiscard]] ks::background_ptr create_bg();

        [[nodiscard]] ks::background_ptr create_bg(bn::fixed x, bn::fixed y);

        [[nodiscard]] bn::optional<ks::background_ptr> create_bg_optional();

        [[nodiscard]] bn::optional<ks::background_ptr> create_bg_optional(bn::fixed x, bn::fixed y);

    private:
        void asserts() const {
            BN_ASSERT((_regular.has_value() ? 1 : 0) +
                      (_affine.has_value() ? 1 : 0) +
                      (_huge.has_value() ? 1 : 0) <= 1,
                      "Only regular, affine or huge bg can be set at once");
        }

        bn::optional<bn::regular_bg_item> _regular;
        bn::optional<bn::affine_bg_item> _affine;
        bn::optional<ks::huge_bg_item> _huge;
    };
}

#endif //BACKGROUND_ITEM_H
