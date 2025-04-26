#ifndef SPRITE_META_H
#define SPRITE_META_H

namespace ks {
    class character_sprite_meta {
    public:
        constexpr character_sprite_meta(const int initial_offset_x,
                                        const int initial_offset_y,
                                        const bn::sprite_item &thumbnail_item,
                                        const unsigned short hash_id)
            : offset_x{initial_offset_x},
              offset_y{initial_offset_y},
              thumbnail(thumbnail_item),
              hash{hash_id} {
        }

        int offset_x;
        int offset_y;
        bn::sprite_item thumbnail;
        unsigned short hash;
    };
}

#endif
