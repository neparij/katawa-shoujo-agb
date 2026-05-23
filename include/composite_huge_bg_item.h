#ifndef KS_COMPOSITE_HUGE_BG_ITEM_H
#define KS_COMPOSITE_HUGE_BG_ITEM_H

#include "composite_bg_asset.h"
#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"

namespace ks {

class background_item;
class background_ptr;
struct composite_huge_bg_state;

class composite_huge_bg_item {
public:
    constexpr composite_huge_bg_item(const composite_bg_asset& asset, int variant_index)
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

    [[nodiscard]] bn::optional<background_ptr> create_background_ptr(
            const background_item& owner, bn::fixed x = 0, bn::fixed y = 0) const;

    bool operator==(const composite_huge_bg_item& other) const {
        return _asset == other._asset && _variant_index == other._variant_index;
    }

    bool operator!=(const composite_huge_bg_item& other) const {
        return !(*this == other);
    }

private:
    const composite_bg_asset* _asset;
    int                       _variant_index;
};

}  // namespace ks

#endif  // KS_COMPOSITE_HUGE_BG_ITEM_H
