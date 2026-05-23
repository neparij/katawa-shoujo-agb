#ifndef KS_COMPOSITES_SHIZU_TABLE_H
#define KS_COMPOSITES_SHIZU_TABLE_H

#include "background_meta.h"
#include "regular_composite_bg_item.h"
#include "bn_regular_bg_items_thumb_shizu_table.h"

namespace ks::composites {
extern const composite_bg_asset shizu_table_asset;
}

namespace ks::composite_background_metas {

constexpr inline composite_background_meta shizu_table_smile = {
    ks::regular_composite_bg_item(ks::composites::shizu_table_asset, 0),
    bn::regular_bg_items::thumb_shizu_table,
    DISPLAYABLE_BITMASK_SHIZU_TABLE_SMILE,
    0x93e8189c,
};

constexpr inline composite_background_meta shizu_table_normal = {
    ks::regular_composite_bg_item(ks::composites::shizu_table_asset, 1),
    bn::regular_bg_items::thumb_shizu_table,
    DISPLAYABLE_BITMASK_SHIZU_TABLE_NORMAL,
    0x7a90048b,
};

constexpr inline composite_background_meta shizu_table_comeopen = {
    ks::regular_composite_bg_item(ks::composites::shizu_table_asset, 2),
    bn::regular_bg_items::thumb_shizu_table,
    DISPLAYABLE_BITMASK_SHIZU_TABLE_COMEOPEN,
    0x0eecaabd,
};

constexpr inline composite_background_meta shizu_table_comeclosed = {
    ks::regular_composite_bg_item(ks::composites::shizu_table_asset, 3),
    bn::regular_bg_items::thumb_shizu_table,
    DISPLAYABLE_BITMASK_SHIZU_TABLE_COMECLOSED,
    0x61a6cad8,
};

}  // namespace ks::composite_background_metas

#endif  // KS_COMPOSITES_SHIZU_TABLE_H
