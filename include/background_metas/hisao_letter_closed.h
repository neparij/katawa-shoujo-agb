#ifndef KS_BGMETA_HISAO_LETTER_CLOSED
#define KS_BGMETA_HISAO_LETTER_CLOSED

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hisao_letter_closed.h"
#include "bn_regular_bg_items_thumb_hisao_letter_closed.h"
namespace ks::background_metas {
    constexpr inline background_meta hisao_letter_closed(
                     bn::regular_bg_items::hisao_letter_closed,
                     bn::regular_bg_items::thumb_hisao_letter_closed,
                     DISPLAYABLE_BITMASK_HISAO_LETTER_CLOSED,
                     0xEE5BAAF9);

}

#endif  // KS_BGMETA_HISAO_LETTER_CLOSED
