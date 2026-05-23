#ifndef KS_BGMETA_WORRYTREE
#define KS_BGMETA_WORRYTREE

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_worrytree.h"
#include "bn_regular_bg_items_thumb_worrytree.h"
namespace ks::background_metas {
    constexpr inline background_meta worrytree(
                     bn::regular_bg_items::worrytree,
                     bn::regular_bg_items::thumb_worrytree,
                     DISPLAYABLE_BITMASK_NONE,
                     0x702457A5);

}

#endif  // KS_BGMETA_WORRYTREE
