#ifndef PLAYER_SFX_H
#define PLAYER_SFX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <gba_types.h>

#include "player_settings.h"

    typedef struct ADGlobals
    {
        const unsigned char *data;
        int last_sample;
        int last_index;
    } ADGlobals;

    typedef struct ADChannel {
        ADGlobals ad;
        u8* src;
        u32 src_len;
        u32 src_pos;
        s8 double_buffers[2][BUFFER_SIZE_A] __attribute__((aligned(4)));
        bool did_run;
        bool is_looping;
        bool is_paused;
    } ADChannel;

    void player8AD_init();
    void player8AD_unload();
    void player8AD_play(const char* name, u8 ch);
    void player8AD_set_loop(bool enable, u8 ch);
    void player8AD_set_pause(bool enable, u8 ch);
    void player8AD_stop(u8 ch);
    bool player8AD_is_playing(u8 ch);
    void player8AD_on_vblank();
    void player8AD_update();

    // mixer
    void mix_audio(s8* output_buffer);

    // 8ad decoder
    void start_ad(const unsigned char *data, const u8 ch);
    void decode_ad(signed char *dst, const unsigned char *src, unsigned int len, const u8 ch);


#ifdef __cplusplus
}
#endif

#endif  // PLAYER_SFX_H
