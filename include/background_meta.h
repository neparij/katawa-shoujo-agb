#ifndef BACKGROUND_META_H
#define BACKGROUND_META_H

#include "ks_huge_bg_item.h"
#include "seen_bitmask.h"

namespace ks {
    class background_meta {
    public:
        constexpr background_meta(const bn::regular_bg_item &bg_item,
                                  const bn::regular_bg_item &thumbnail_item,
                                  const displayable_bitmask_t seen_bitmask_id,
                                  const unsigned int hash_id) : bg{bg_item},
                                                                thumbnail{thumbnail_item},
                                                                seen_bitmask{seen_bitmask_id},
                                                                hash{hash_id} {
        }

        bn::regular_bg_item bg;
        bn::regular_bg_item thumbnail;
        const displayable_bitmask_t seen_bitmask;
        const unsigned int hash;
    };

    class huge_background_meta {
    public:
        constexpr huge_background_meta(const huge_bg_item &bg_item,
                                  const bn::regular_bg_item &thumbnail_item,
                                  const displayable_bitmask_t seen_bitmask_id,
                                  const unsigned int hash_id) : bg{bg_item},
                                                                thumbnail{thumbnail_item},
                                                                seen_bitmask{seen_bitmask_id},
                                                                hash{hash_id} {
        }

        huge_bg_item bg;
        bn::regular_bg_item thumbnail;
        const displayable_bitmask_t seen_bitmask;
        const unsigned int hash;
    };
}

#endif //BACKGROUND_META_H
