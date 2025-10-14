#ifndef KS_BGMETA_SHIZU_TABLE_NORMAL
#define KS_BGMETA_SHIZU_TABLE_NORMAL

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_table_normal.h"
#include "bn_regular_bg_items_thumb_shizu_table_normal.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_table_normal(
                     bn::regular_bg_items::shizu_table_normal,
                     bn::regular_bg_items::thumb_shizu_table_normal,
                     DISPLAYABLE_BITMASK_SHIZU_TABLE_NORMAL,
                     0x7A90048B);

}

#endif  // KS_BGMETA_SHIZU_TABLE_NORMAL
