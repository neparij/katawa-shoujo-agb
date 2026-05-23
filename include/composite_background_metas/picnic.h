#ifndef KS_COMPOSITES_PICNIC_H
#define KS_COMPOSITES_PICNIC_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_picnic.h"

namespace ks::composites {
extern const composite_bg_asset picnic_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta picnic_normal = {
    ks::regular_composite_bg_item(ks::composites::picnic_asset, 0),
    bn::regular_bg_items::thumb_picnic,
    DISPLAYABLE_BITMASK_PICNIC_NORMAL,
    0xa4ef2b3d,
};

constexpr inline composite_background_meta picnic_rain = {
    ks::regular_composite_bg_item(ks::composites::picnic_asset, 1),
    bn::regular_bg_items::thumb_picnic,
    DISPLAYABLE_BITMASK_PICNIC_RAIN,
    0x49d3d12b,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_PICNIC_H
