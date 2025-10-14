#ifndef KS_BGMETA_HANAKO_BILLIARDS_SMILE_CLOSE
#define KS_BGMETA_HANAKO_BILLIARDS_SMILE_CLOSE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hanako_billiards_smile_close.h"
#include "bn_regular_bg_items_thumb_hanako_billiards_smile_close.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_billiards_smile_close(
                     bn::regular_bg_items::hanako_billiards_smile_close,
                     bn::regular_bg_items::thumb_hanako_billiards_smile_close,
                     DISPLAYABLE_BITMASK_NONE,
                     0x51814D15);

}

#endif  // KS_BGMETA_HANAKO_BILLIARDS_SMILE_CLOSE
