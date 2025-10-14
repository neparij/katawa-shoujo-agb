#ifndef KS_BGMETA_LILLY_RESTAURANT_LISTEN
#define KS_BGMETA_LILLY_RESTAURANT_LISTEN

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_restaurant_listen.h"
#include "bn_regular_bg_items_thumb_lilly_restaurant_listen.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_restaurant_listen(
                     bn::regular_bg_items::lilly_restaurant_listen,
                     bn::regular_bg_items::thumb_lilly_restaurant_listen,
                     DISPLAYABLE_BITMASK_LILLY_RESTAURANT_LISTEN,
                     0x48786F43);

}

#endif  // KS_BGMETA_LILLY_RESTAURANT_LISTEN
