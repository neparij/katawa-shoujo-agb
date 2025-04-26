#ifndef KS_BGMETA_HANA_LIBRARY_SMILE
#define KS_BGMETA_HANA_LIBRARY_SMILE

#include "background_meta.h"
#include "bn_regular_bg_items_hana_library_smile.h"
#include "bn_regular_bg_items_thumb_hana_library_smile.h"
namespace ks::background_metas {
    constexpr inline background_meta hana_library_smile(
                     bn::regular_bg_items::hana_library_smile,
                     bn::regular_bg_items::thumb_hana_library_smile,
                     0x28FC69DE);

}

#endif  // KS_BGMETA_HANA_LIBRARY_SMILE
