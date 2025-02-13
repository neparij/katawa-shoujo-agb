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

void player_init();
void player_unload();
void player_playGSM(const char* name);
void player_setLoop(bool enable);
void player_setPause(bool enable);
void player_seek(unsigned int msecs);
void player_setRate(int rate);
void player_stop();
bool player_isPlaying();
void player_onVBlank();
void player_update(int expectedAudioChunk,
                   void (*onAudioChunks)(unsigned int current));
void player_setVolume(const float newVolume);

unsigned int player_getCursor();
void player_setCursor(unsigned int cursor);

#ifdef __cplusplus
}
#endif

#endif  // PLAYER_H
