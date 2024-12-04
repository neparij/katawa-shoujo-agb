#ifndef SPRITE_META_H
#define SPRITE_META_H

namespace ks {

class character_sprite_meta {
public:
    constexpr character_sprite_meta(const int offset_x, const int offset_y):
        offset_x(offset_x),
        offset_y(offset_y) {}
    const int offset_x;
    const int offset_y;
};

}

#endif
