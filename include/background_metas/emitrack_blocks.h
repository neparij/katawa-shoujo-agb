#ifndef KS_BGMETA_EMITRACK_BLOCKS
#define KS_BGMETA_EMITRACK_BLOCKS

#include "background_meta.h"
#include "bn_regular_bg_items_emitrack_blocks.h"
#include "bn_regular_bg_items_thumb_emitrack_blocks.h"
namespace ks::background_metas {
    constexpr inline background_meta emitrack_blocks(
                     bn::regular_bg_items::emitrack_blocks,
                     bn::regular_bg_items::thumb_emitrack_blocks,
                     0xDF65B386);

}

#endif  // KS_BGMETA_EMITRACK_BLOCKS
