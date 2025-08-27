#ifndef BACKGROUND_META_H
#define BACKGROUND_META_H

#include "ks_huge_bg_item.h"

namespace ks {
    class background_meta {
    public:
        constexpr background_meta(const bn::regular_bg_item &bg_item,
                                  const bn::regular_bg_item &thumbnail_item,
                                  const unsigned int hash_id) : bg{bg_item},
                                                                thumbnail{thumbnail_item},
                                                                hash{hash_id} {
        }

        bn::regular_bg_item bg;
        bn::regular_bg_item thumbnail;
        const unsigned int hash;
    };

    class huge_background_meta {
    public:
        constexpr huge_background_meta(const huge_bg_item &bg_item,
                                  const bn::regular_bg_item &thumbnail_item,
                                  const unsigned int hash_id) : bg{bg_item},
                                                                thumbnail{thumbnail_item},
                                                                hash{hash_id} {
        }

        huge_bg_item bg;
        bn::regular_bg_item thumbnail;
        const unsigned int hash;
    };
}

#endif //BACKGROUND_META_H
