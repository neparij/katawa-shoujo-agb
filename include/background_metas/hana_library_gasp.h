#ifndef KS_BGMETA_HANA_LIBRARY_GASP
#define KS_BGMETA_HANA_LIBRARY_GASP

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_hana_library_gasp.h"
#include "bn_regular_bg_items_thumb_hana_library_gasp.h"
namespace ks::background_metas {
    constexpr inline background_meta hana_library_gasp(
                     bn::regular_bg_items::hana_library_gasp,
                     bn::regular_bg_items::thumb_hana_library_gasp,
                     DISPLAYABLE_BITMASK_HANA_LIBRARY_GASP,
                     0xCF7F47FE);

}

#endif  // KS_BGMETA_HANA_LIBRARY_GASP
