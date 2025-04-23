#ifndef KS_BGMETA_HANAKO_FW_FLASH
#define KS_BGMETA_HANAKO_FW_FLASH

#include "background_meta.h"
#include "bn_regular_bg_items_hanako_fw_flash.h"
#include "bn_sprite_items_thumb_hanako_fw_flash.h"
namespace ks::background_metas {
    constexpr inline background_meta hanako_fw_flash(
                     bn::regular_bg_items::hanako_fw_flash,
                     bn::sprite_items::thumb_hanako_fw_flash,
                     0xE13A5821);

}

#endif  // KS_BGMETA_HANAKO_FW_FLASH
