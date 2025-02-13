#ifndef PLAYER_SFX_H
#define PLAYER_SFX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct {
  unsigned int pos;
  bool isPlaying;
  bool isLooping;
} PlayerSFXState;

typedef struct ADGlobals
{
    const unsigned char *data;
    int last_sample;
    int last_index;
} ADGlobals;

extern ADGlobals ad;

void player_sfx_init();
void player_sfx_unload();
void player_sfx_play(const char* name);
void player_sfx_setLoop(bool enable);
void player_sfx_setPause(bool enable);
PlayerSFXState player_sfx_getState();
void player_sfx_setState(PlayerSFXState state);
void player_sfx_stop();
bool player_sfx_isPlaying();
void player_sfx_onVBlank();
void player_sfx_update();



// 8ad decoder
void start_ad(const unsigned char *data);
void decode_ad(signed char *dst, const unsigned char *src, unsigned int len);


#ifdef __cplusplus
}
#endif

#endif  // PLAYER_SFX_H
