#ifndef KS_CHAR_METAS
#define KS_CHAR_METAS

#include "sprite_metas/rinpan_basic.h"
#include "sprite_metas/rinpan_relaxed.h"
#include "sprite_metas/rinpan_basic_close.h"
#include "sprite_metas/rinpan_relaxed_close.h"
namespace ks::character_sprite_metas {
    inline const character_sprite_meta* get_by_hash(const unsigned int hash) {
        switch (hash) {
            case 0xE908: return &sprite_metas::rinpan_basic;
            case 0x2D7F: return &sprite_metas::rinpan_relaxed;
            case 0xCE97: return &sprite_metas::rinpan_basic_close;
            case 0xEAA1: return &sprite_metas::rinpan_relaxed_close;
            default: return nullptr;
        }
    }

};

#endif  // KS_CHAR_METAS
