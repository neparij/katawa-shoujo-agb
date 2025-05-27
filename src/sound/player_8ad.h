#ifndef PLAYER_SFX_H
#define PLAYER_SFX_H

#define BUFFER_SIZE_8AD 192

#ifdef __cplusplus
extern "C" {
#endif

#include <gba_types.h>

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
        s8 out_buffer[BUFFER_SIZE_8AD] __attribute__((aligned(4)));
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
    void player8AD_update();
    s8*  player8AD_get_buffer(u8 ch);

    // 8ad decoder
    void start_ad(const unsigned char *data, const u8 ch);
    void decode_ad(signed char *dst, const unsigned char *src, unsigned int len, const u8 ch);

#ifdef __cplusplus
}
#endif

#endif  // PLAYER_SFX_H
