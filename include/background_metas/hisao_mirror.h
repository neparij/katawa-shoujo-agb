#ifndef KS_BGMETA_HISAO_MIRROR
#define KS_BGMETA_HISAO_MIRROR

#include "background_meta.h"
#include "bn_regular_bg_items_hisao_mirror.h"
#include "bn_regular_bg_items_thumb_hisao_mirror.h"
namespace ks::background_metas {
    constexpr inline background_meta hisao_mirror(
                     bn::regular_bg_items::hisao_mirror,
                     bn::regular_bg_items::thumb_hisao_mirror,
                     0x547CFC6E);

}

#endif  // KS_BGMETA_HISAO_MIRROR
