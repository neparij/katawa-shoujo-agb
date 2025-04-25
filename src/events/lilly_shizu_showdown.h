#ifndef LILLY_SHIZU_SHOWDOWN_H
#define LILLY_SHIZU_SHOWDOWN_H

#include "bn_regular_bg_items_lilly_shizu_showdown_slices_lilly.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_slices_shizu.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_both.h"

namespace ks {
    namespace background_metas {
        constexpr inline background_meta lilly_shizu_showdown_slices_lilly(
            bn::regular_bg_items::lilly_shizu_showdown_slices_lilly,
            bn::sprite_items::thumb_lilly_shizu_showdown,
            0xFFFF0005);

        constexpr inline background_meta lilly_shizu_showdown_slices_shizu(
            bn::regular_bg_items::lilly_shizu_showdown_slices_shizu,
            bn::sprite_items::thumb_lilly_shizu_showdown,
            0xFFFF0006);

        constexpr inline background_meta lilly_shizu_showdown_both(
            bn::regular_bg_items::lilly_shizu_showdown_both,
            bn::sprite_items::thumb_lilly_shizu_showdown,
            0xFFFF0007);
    }
}

#endif //LILLY_SHIZU_SHOWDOWN_H
