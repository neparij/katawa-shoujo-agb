#ifndef SOUND_ENGINE_MANAGER_H
#define SOUND_ENGINE_MANAGER_H
#include <gba_types.h>

#include "bn_fixed.h"

namespace sound_mixer {
    void init();
    void mute();
    void unmute();
    void mix_audio(const s8 *src_buffer, int src_size, bn::fixed volume);
    void directsound_copy();
    void update();
}

#endif //SOUND_ENGINE_MANAGER_H
