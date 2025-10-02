#ifndef KS_BGMETA_SHIZU_TABLE_COMECLOSED
#define KS_BGMETA_SHIZU_TABLE_COMECLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_shizu_table_comeclosed.h"
#include "bn_regular_bg_items_thumb_shizu_table_comeclosed.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_table_comeclosed(
                     bn::regular_bg_items::shizu_table_comeclosed,
                     bn::regular_bg_items::thumb_shizu_table_comeclosed,
                     DISPLAYABLE_BITMASK_SHIZU_TABLE_COMECLOSED,
                     0x61A6CAD8);

}

#endif  // KS_BGMETA_SHIZU_TABLE_COMECLOSED
