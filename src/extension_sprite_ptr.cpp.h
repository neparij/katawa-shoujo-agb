#ifndef EXTENSION_SPRITE_PTR_CPP_H
#define EXTENSION_SPRITE_PTR_CPP_H

#include "bn_sprite_item.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_builder.h"

namespace bn {
    inline sprite_ptr create_sprite_4bpp(const sprite_item& item, fixed x, fixed y, sprite_palette_ptr palette)
    {
        return sprite_ptr::create(bn::fixed_point(x, y), item.shape_size(), item.tiles_item().create_tiles(), palette);
    }
}

#endif // EXTENSION_SPRITE_PTR_CPP_H
