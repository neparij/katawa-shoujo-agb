#ifndef KS_REGULAR_COMPOSITE_BG_ITEM_H
#define KS_REGULAR_COMPOSITE_BG_ITEM_H

#include "composite_bg_asset.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_fixed.h"

namespace ks {

class background_item;
class background_ptr;

/**
 * Lightweight handle for a composite background variant.
 * Dissolve / blending use the same `background_item` → `background_ptr`
 * path as regular BGs; only `create_bg` implementation differs.
 */
class regular_composite_bg_item {
public:
    constexpr regular_composite_bg_item(const composite_bg_asset& asset, int variant_index)
        : _asset(&asset),
          _variant_index(variant_index) {
    }

    [[nodiscard]] constexpr const composite_bg_asset& asset() const {
        return *_asset;
    }

    [[nodiscard]] constexpr int variant_index() const {
        return _variant_index;
    }

    [[nodiscard]] constexpr const bn::bg_palette_item& palette_item() const {
        return *_asset->palette;
    }

    [[nodiscard]] bn::regular_bg_ptr create_bg(bn::fixed x = 0, bn::fixed y = 0) const;

    [[nodiscard]] bn::optional<bn::regular_bg_ptr> create_bg_optional(bn::fixed x = 0, bn::fixed y = 0) const;

    [[nodiscard]] bn::optional<background_ptr> create_background_ptr(
            const background_item& owner, bn::fixed x = 0, bn::fixed y = 0) const;

    bool operator==(const regular_composite_bg_item &other) const {
        return _asset == other._asset && _variant_index == other._variant_index;
    }

    bool operator!=(const regular_composite_bg_item &other) const {
        return !(*this == other);
    }

private:
    const composite_bg_asset* _asset;
    int                     _variant_index;
};

}  // namespace ks

#endif  // KS_REGULAR_COMPOSITE_BG_ITEM_H
