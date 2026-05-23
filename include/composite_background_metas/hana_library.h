#ifndef KS_COMPOSITES_HANA_LIBRARY_H
#define KS_COMPOSITES_HANA_LIBRARY_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_hana_library.h"

namespace ks::composites {
extern const composite_bg_asset hana_library_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta hana_library_default = {
    ks::regular_composite_bg_item(ks::composites::hana_library_asset, 0),
    bn::regular_bg_items::thumb_hana_library,
    DISPLAYABLE_BITMASK_HANA_LIBRARY,
    0x092915a0,
};

constexpr inline composite_background_meta hana_library_read = {
    ks::regular_composite_bg_item(ks::composites::hana_library_asset, 1),
    bn::regular_bg_items::thumb_hana_library,
    DISPLAYABLE_BITMASK_HANA_LIBRARY_READ,
    0x3baddf80,
};

constexpr inline composite_background_meta hana_library_gasp = {
    ks::regular_composite_bg_item(ks::composites::hana_library_asset, 2),
    bn::regular_bg_items::thumb_hana_library,
    DISPLAYABLE_BITMASK_HANA_LIBRARY_GASP,
    0xcf7f47fe,
};

constexpr inline composite_background_meta hana_library_smile = {
    ks::regular_composite_bg_item(ks::composites::hana_library_asset, 3),
    bn::regular_bg_items::thumb_hana_library,
    DISPLAYABLE_BITMASK_NONE,
    0x28fc69de,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_HANA_LIBRARY_H
