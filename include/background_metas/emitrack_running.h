#ifndef KS_BGMETA_EMITRACK_RUNNING
#define KS_BGMETA_EMITRACK_RUNNING

#include "background_meta.h"
#include "bn_regular_bg_items_emitrack_running.h"
#include "bn_regular_bg_items_thumb_emitrack_running.h"
namespace ks::background_metas {
    constexpr inline background_meta emitrack_running(
                     bn::regular_bg_items::emitrack_running,
                     bn::regular_bg_items::thumb_emitrack_running,
                     0xACAA4418);

}

#endif  // KS_BGMETA_EMITRACK_RUNNING
