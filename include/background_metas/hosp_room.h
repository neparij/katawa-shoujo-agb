#ifndef KS_BGMETA_HOSP_ROOM
#define KS_BGMETA_HOSP_ROOM

#include "background_meta.h"
#include "bn_regular_bg_items_hosp_room.h"
#include "bn_sprite_items_thumb_hosp_room.h"
namespace ks::background_metas {
    constexpr inline background_meta hosp_room(
                     bn::regular_bg_items::hosp_room,
                     bn::sprite_items::thumb_hosp_room,
                     0x3E47FD6A);

}

#endif  // KS_BGMETA_HOSP_ROOM
