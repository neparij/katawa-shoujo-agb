#ifndef VFX_META_H
#define VFX_META_H

#include "seen_bitmask.h"

namespace ks {
    class vfx_meta {
    public:
        constexpr vfx_meta(const bn::regular_bg_item &bg_item,
                           const displayable_bitmask_t seen_bitmask_id) : bg{bg_item},
                                                         seen_bitmask{seen_bitmask_id} {
        }

        bn::regular_bg_item bg;
        const displayable_bitmask_t seen_bitmask;
    };
}

#endif //VFX_META_H
