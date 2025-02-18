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

void player8AD_init();
void player8AD_unload();
void player8AD_play(const char* name);
void player8AD_set_loop(bool enable);
void player8AD_set_pause(bool enable);
PlayerSFXState player8AD_get_state();
void player8AD_set_state(PlayerSFXState state);
void player8AD_stop();
bool player8AD_is_playing();
void player8AD_on_vblank();
void player8AD_update();



// 8ad decoder
void start_ad(const unsigned char *data);
void decode_ad(signed char *dst, const unsigned char *src, unsigned int len);


#ifdef __cplusplus
}
#endif

#endif  // PLAYER_SFX_H
