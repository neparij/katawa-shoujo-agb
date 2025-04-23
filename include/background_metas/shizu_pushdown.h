#ifndef KS_BGMETA_SHIZU_PUSHDOWN
#define KS_BGMETA_SHIZU_PUSHDOWN

#include "background_meta.h"
#include "bn_regular_bg_items_shizu_pushdown.h"
#include "bn_sprite_items_thumb_shizu_pushdown.h"
namespace ks::background_metas {
    constexpr inline background_meta shizu_pushdown(
                     bn::regular_bg_items::shizu_pushdown,
                     bn::sprite_items::thumb_shizu_pushdown,
                     0x81990706);

}

#endif  // KS_BGMETA_SHIZU_PUSHDOWN
