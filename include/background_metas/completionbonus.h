#ifndef KS_BGMETA_COMPLETIONBONUS
#define KS_BGMETA_COMPLETIONBONUS

#include "background_meta.h"
#include "bn_regular_bg_items_completionbonus.h"
#include "bn_sprite_items_thumb_completionbonus.h"
namespace ks::background_metas {
    constexpr inline background_meta completionbonus(
                     bn::regular_bg_items::completionbonus,
                     bn::sprite_items::thumb_completionbonus,
                     0x9ADEBFF5);

}

#endif  // KS_BGMETA_COMPLETIONBONUS
