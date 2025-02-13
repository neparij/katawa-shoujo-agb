#ifndef SPRITE_META_H
#define SPRITE_META_H

namespace ks {

class character_sprite_meta {
public:
    constexpr character_sprite_meta(const int initial_offset_x, const int initial_offset_y) :
        offset_x{initial_offset_x},
        offset_y{initial_offset_y} {}

    int offset_x;
    int offset_y;
};

}

#endif
