#ifndef PLAYER_H
#define PLAYER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <gba_types.h>
#include "PlaybackState.h"

#define RATE_LEVELS 3
#define AUDIO_SYNC_LIMIT 2

void playerGSM_init();
void playerGSM_unload();
void playerGSM_play(const char* name);
void playerGSM_set_loop(bool enable);
void playerGSM_set_pause(bool enable);
void playerGSM_seek(unsigned int msecs);
void playerGSM_set_rate(int rate);
void playerGSM_stop();
bool playerGSM_is_playing();
void playerGSM_on_vblank();
void playerGSM_update(int expectedAudioChunk,
                   void (*onAudioChunks)(unsigned int current));
float playerGSM_get_volume();
void playerGSM_set_volume(const float newVolume);

unsigned int playerGSM_get_cursor();
void playerGSM_set_cursor(unsigned int cursor);

#ifdef __cplusplus
}
#endif

#endif  // PLAYER_H
