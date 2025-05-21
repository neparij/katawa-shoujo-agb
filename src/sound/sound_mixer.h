#ifndef SOUND_ENGINE_MANAGER_H
#define SOUND_ENGINE_MANAGER_H
#include <gba_types.h>

namespace sound_mixer {
    void init();
    void mute();
    void unmute();
    void mix_audio(const s8 *src_buffer, int src_size);
    void directsound_copy();
    void update();
    void on_vblank();
}

#endif //SOUND_ENGINE_MANAGER_H
