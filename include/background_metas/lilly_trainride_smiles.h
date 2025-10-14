#ifndef KS_BGMETA_LILLY_TRAINRIDE_SMILES
#define KS_BGMETA_LILLY_TRAINRIDE_SMILES

#include "background_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_lilly_trainride_smiles.h"
#include "bn_regular_bg_items_thumb_lilly_trainride_smiles.h"
namespace ks::background_metas {
    constexpr inline background_meta lilly_trainride_smiles(
                     bn::regular_bg_items::lilly_trainride_smiles,
                     bn::regular_bg_items::thumb_lilly_trainride_smiles,
                     DISPLAYABLE_BITMASK_LILLY_TRAINRIDE_SMILES,
                     0xDD67CF48);

}

#endif  // KS_BGMETA_LILLY_TRAINRIDE_SMILES
