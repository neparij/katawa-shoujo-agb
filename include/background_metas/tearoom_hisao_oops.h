#ifndef KS_BGMETA_TEAROOM_HISAO_OOPS
#define KS_BGMETA_TEAROOM_HISAO_OOPS

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_tearoom_hisao_oops.h"
#include "bn_regular_bg_items_thumb_tearoom_hisao_oops.h"
namespace ks::background_metas {
    constexpr inline background_meta tearoom_hisao_oops(
                     bn::regular_bg_items::tearoom_hisao_oops,
                     bn::regular_bg_items::thumb_tearoom_hisao_oops,
                     DISPLAYABLE_BITMASK_NONE,
                     0x68C44307);

}

#endif  // KS_BGMETA_TEAROOM_HISAO_OOPS
