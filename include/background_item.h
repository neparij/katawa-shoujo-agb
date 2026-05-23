#ifndef BACKGROUND_ITEM_H
#define BACKGROUND_ITEM_H

// #include "background_ptr.h"  // Removed to break circular dependency
#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_regular_bg_item.h"
#include "bn_affine_bg_item.h"
#include "ks_huge_bg_item.h"
#include "composite_huge_bg_item.h"
#include "regular_composite_bg_item.h"

namespace ks {
    class background_ptr; // <-- forward declaration

    class background_item {
    public:
        explicit constexpr background_item(const bn::regular_bg_item &regular_bg)
            : _regular(regular_bg),
              _affine(bn::nullopt),
              _huge(bn::nullopt),
              _regular_composite(bn::nullopt),
              _composite_huge(bn::nullopt) {
        }

        explicit constexpr background_item(const bn::affine_bg_item& affine_bg)
            : _regular(bn::nullopt),
              _affine(affine_bg),
              _huge(bn::nullopt),
              _regular_composite(bn::nullopt),
              _composite_huge(bn::nullopt) {
        }

        explicit constexpr background_item(const ks::huge_bg_item& huge_bg)
            : _regular(bn::nullopt),
              _affine(bn::nullopt),
              _huge(huge_bg),
              _regular_composite(bn::nullopt),
              _composite_huge(bn::nullopt) {
            BN_LOG("background_item(const ks::huge_bg_item &huge_bg)");
        }

        explicit constexpr background_item(const ks::regular_composite_bg_item& composite_bg)
            : _regular(bn::nullopt),
              _affine(bn::nullopt),
              _huge(bn::nullopt),
              _regular_composite(composite_bg),
              _composite_huge(bn::nullopt) {
        }

        explicit constexpr background_item(const ks::composite_huge_bg_item& composite_huge)
            : _regular(bn::nullopt),
              _affine(bn::nullopt),
              _huge(bn::nullopt),
              _regular_composite(bn::nullopt),
              _composite_huge(composite_huge) {
        }

        // Copy constructor and assignment
        constexpr background_item(const background_item &) = default;

        constexpr background_item &operator=(const background_item &) = default;

        [[nodiscard]] constexpr const bn::regular_bg_tiles_item& regular_tiles_item() const;

        [[nodiscard]] constexpr const bn::bg_palette_item& palette_item() const;

        // Move constructor and assignment
        constexpr background_item(background_item &&other) noexcept
            : _regular(bn::move(other._regular)),
              _affine(bn::move(other._affine)),
              _huge(bn::move(other._huge)),
              _regular_composite(bn::move(other._regular_composite)),
              _composite_huge(bn::move(other._composite_huge)) {
        }

        constexpr background_item& operator=(background_item&& other) noexcept {
            if(this != &other) {
                _regular = bn::move(other._regular);
                _affine = bn::move(other._affine);
                _huge = bn::move(other._huge);
                _regular_composite = bn::move(other._regular_composite);
                _composite_huge = bn::move(other._composite_huge);
            }
            return *this;
        }

        // Destructor
        constexpr ~background_item() = default;


        bool operator==(const ks::background_item &other) const {
            return _regular == other._regular &&
                   _affine == other._affine &&
                   _huge == other._huge &&
                   _regular_composite == other._regular_composite &&
                   _composite_huge == other._composite_huge;
        }

        bool operator!=(const ks::background_item &other) const {
            return !(*this == other);
        }

        bool has_value() const;

        bool is_regular() const;

        bool is_affine() const;

        bool is_huge() const;

        bool is_regular_composite() const;

        bool is_composite_huge() const;

        [[nodiscard]] bool is_composite_huge_variant_switch(const background_item& other) const;

        [[nodiscard]] bool is_composite_variant_switch(const background_item& other) const;

        [[nodiscard]] int composite_huge_variant_index() const;

        [[nodiscard]] int composite_variant_index() const;

        [[nodiscard]] ks::background_ptr create_bg();

        [[nodiscard]] ks::background_ptr create_bg(bn::fixed x, bn::fixed y);

        [[nodiscard]] bn::optional<ks::background_ptr> create_bg_optional();

        [[nodiscard]] bn::optional<ks::background_ptr> create_bg_optional(bn::fixed x, bn::fixed y);

    private:
        void asserts() const {
            BN_ASSERT((_regular.has_value() ? 1 : 0) +
                      (_affine.has_value() ? 1 : 0) +
                      (_huge.has_value() ? 1 : 0) +
                      (_regular_composite.has_value() ? 1 : 0) +
                      (_composite_huge.has_value() ? 1 : 0) <= 1,
                      "Only one background type can be set at once");
        }

        bn::optional<bn::regular_bg_item> _regular;
        bn::optional<bn::affine_bg_item> _affine;
        bn::optional<ks::huge_bg_item> _huge;
        bn::optional<ks::regular_composite_bg_item> _regular_composite;
        bn::optional<ks::composite_huge_bg_item> _composite_huge;
    };

    constexpr const bn::regular_bg_tiles_item & background_item::regular_tiles_item() const {
        BN_ASSERT(_regular.has_value(), "Regular bg item is not set");
        return _regular->tiles_item();
    }

    constexpr const bn::bg_palette_item& background_item::palette_item() const {
        if (_regular.has_value()) {
            return _regular->palette_item();
        }
        if(_regular_composite.has_value()) {
            return _regular_composite->palette_item();
        }
        if(_composite_huge.has_value()) {
            return _composite_huge->palette_item();
        }
        if (_affine.has_value()) {
            return _affine->palette_item();
        }
        BN_ASSERT(_huge.has_value(), "Huge bg item is not set");
        return _huge->palette_item();
    }
}

#endif //BACKGROUND_ITEM_H
