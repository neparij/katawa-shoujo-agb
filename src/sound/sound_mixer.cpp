#include "sound_mixer.h"

#include "sound_mixer_prefs.h"

#include <gba_dma.h>
#include <gba_sound.h>
#include <gba_timers.h>

#include "bn_log.h"
#include "bn_math.h"
#include "gba_math.h"
#include "player_8ad.h"
#include "player_ulc.h"
#include "../scenemanager.h"
#include "../sound_manager.h"
#include "../../../butano/butano/hw/include/bn_hw_irq.h"
#include "libulc/ulc_Specs.h"

#ifndef CODE_ROM
#define CODE_ROM __attribute__((section(".code")))
#endif

#ifndef CODE_EWRAM
#define CODE_EWRAM __attribute__((section(".ewram")))
#endif

#ifndef INLINE
#define INLINE static inline __attribute__((always_inline))
#endif

namespace sound_mixer {

    static bool is_muted = true;
    static u8 cur_buffer = 0;
    static s8 double_buffers[1+SOUND_ENGINE_STEREO][2][SOUND_ENGINE_BUFFER_SIZE];// __attribute__((aligned(4)));

    INLINE void clear_buffers() {
        for (u8 channel_n = 0; channel_n < 1+SOUND_ENGINE_STEREO; channel_n++) {
            for (u8 buffer_n = 0; buffer_n < 2; buffer_n++) {
                u32 *bufferPtr = (u32 *) double_buffers[channel_n][buffer_n];
                for (u32 j = 0; j < SOUND_ENGINE_BUFFER_SIZE / 4; j++)
                    bufferPtr[j] = 0;
            }
        }
    }

    INLINE void clear_current_buffers() {
        for (u8 channel_n = 0; channel_n < 1+SOUND_ENGINE_STEREO; channel_n++) {
            u32 *bufferPtr = (u32 *) double_buffers[channel_n][cur_buffer];
            for (u32 j = 0; j < SOUND_ENGINE_BUFFER_SIZE / 4; j++)
                bufferPtr[j] = 0;
        }
    }

    void mute() {
        BN_LOG(" >>>>>>>>>>>> MUTE!");
        // clear_buffers();
        // DSOUNDCTRL &= ~(DSOUNDCTRL_AL | DSOUNDCTRL_AR);
        is_muted = true;
    }

    void unmute() {
        BN_LOG(" >>>>>>>>>>>> UNMUTE!");
        // clear_buffers();
        // DSOUNDCTRL |= (DSOUNDCTRL_AL | DSOUNDCTRL_AR);
        is_muted = false;
    }

    void init() {
        SNDSTAT = SNDSTAT_ENABLE;
        SETSNDRES(1);

#if SOUND_ENGINE_STEREO
        DSOUNDCTRL = DSOUNDCTRL_A100 | DSOUNDCTRL_B100 | DSOUNDCTRL_AL | DSOUNDCTRL_BR | DSOUNDCTRL_ATIMER(1) | DSOUNDCTRL_BTIMER(1) | DSOUNDCTRL_ARESET | DSOUNDCTRL_BRESET;
#else
        DSOUNDCTRL = DSOUNDCTRL_A100 | DSOUNDCTRL_AL | DSOUNDCTRL_AR | DSOUNDCTRL_ATIMER(1) | DSOUNDCTRL_ARESET;
#endif


        REG_TM1CNT = 0;
        REG_TM1CNT_L = 0x10000 - SOUND_ENGINE_PERIOD_SIZE;
        REG_TM1CNT_H = TIMER_16MHZ | TIMER_START;

        clear_buffers();
        cur_buffer = 1;
        // Left channel (or Mono channel)
        REG_DMA1SAD = (intptr_t)double_buffers;
        REG_DMA1CNT = 0;
        REG_DMA1DAD = FIFO_ADDR_A;
        REG_DMA1CNT = DMA_DST_FIXED | DMA_SRC_FIXED | DMA32 | DMA_SPECIAL | DMA_ENABLE;

#if SOUND_ENGINE_STEREO
        // Right channel
        REG_DMA2SAD = (intptr_t)double_buffers + SOUND_ENGINE_BUFFER_SIZE * 2;
        REG_DMA2CNT = 0;
        REG_DMA2DAD = FIFO_ADDR_B;
        REG_DMA2CNT = DMA_DST_FIXED | DMA_SRC_FIXED | DMA32 | DMA_SPECIAL | DMA_ENABLE;
#endif

        mute();
        playerULC_init();
        player8AD_init();
        unmute();
    }

    INLINE void mix_audio_resampled_linear(const s8* in_buf, s8* out_buf, const int in_len, const int out_len, bn::fixed volume) {
        const u32 step = (in_len << 16) / out_len;  // 16.16 fixed-point
        u32 pos = 0;

        for (int i = 0; i < out_len; i++) {
            const int index = pos >> 16;
            const u16 frac = pos & 0xFFFF;

            // Signed 8-bit values extended to 16 bits
            const s16 s1 = in_buf[index];
            const s16 s2 = (index + 1 < in_len) ? in_buf[index + 1] : s1;

            // Linear interpolation
            const s16 interp = ((s1 * (0x10000 - frac)) + (s2 * frac)) >> 16;

            // out_buf[i] += (s8)interp;
            out_buf[i] = CLAMP(out_buf[i] + ((s8)interp * volume).integer(), -128, 127);
            pos += step;
        }
    }

    INLINE void mix_audio(s8 *src_buffer, const int src_size, bn::fixed volume = 1.0) {
        if (is_muted) {
            volume = 0;
        }
        if (src_size != SOUND_ENGINE_BUFFER_SIZE) {
            mix_audio_resampled_linear(src_buffer, double_buffers[0][cur_buffer], src_size, SOUND_ENGINE_BUFFER_SIZE, volume);
        } else {
            for (int i = 0; i < SOUND_ENGINE_BUFFER_SIZE; i++) {
                double_buffers[0][cur_buffer][i] = CLAMP(double_buffers[0][cur_buffer][i] + (src_buffer[i] * volume).integer(), -128, 127);
            }
        }
    }

    void directsound_copy() {
        if(cur_buffer == 0) {
            // Left channel (or Mono channel)
            REG_DMA1CNT = 0;
            REG_DMA1CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA32 | DMA_SPECIAL | DMA_ENABLE | 1;

#if SOUND_ENGINE_STEREO
            // Right channel
            REG_DMA2CNT = 0;
            REG_DMA2CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA32 | DMA_SPECIAL | DMA_ENABLE;
#endif
        }
        cur_buffer = !cur_buffer;
    }

    INLINE void mix_all() {
        mix_audio(playerULC_get_buffer(), BUFFER_SIZE_ULC, ks::sound_manager::get_mixed_volume<SOUND_CHANNEL_MUSIC>());
        mix_audio(player8AD_get_buffer(0), BUFFER_SIZE_8AD, ks::sound_manager::get_mixed_volume<SOUND_CHANNEL_SOUND>());
        mix_audio(player8AD_get_buffer(1), BUFFER_SIZE_8AD, ks::sound_manager::get_mixed_volume<SOUND_CHANNEL_AMBIENT>());
    }

    void update() {
        clear_current_buffers();
        playerULC_update();
        player8AD_update();
#if !SOUND_ENGINE_MIX_ON_VBLANK
        mix_all();
#endif
    }

    void on_vblank() {
#if SOUND_ENGINE_MIX_ON_VBLANK
        mix_all();
#endif
        directsound_copy();
    }
}
