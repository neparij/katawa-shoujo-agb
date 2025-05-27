#include "sound_mixer.h"

#include "sound_mixer_prefs.h"

#include <gba_dma.h>
#include <gba_interrupt.h>
#include <gba_sound.h>
#include <gba_timers.h>

#include "bn_core.h"
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
    static bool IWRAM_DATA initialized = false;
    static bool IWRAM_DATA is_muted = true;
    static u8 IWRAM_DATA cur_buffer = 0;
    static s8 IWRAM_DATA double_buffers[2][SOUND_ENGINE_BUFFER_SIZE] __attribute__((aligned(4)));

    INLINE void clear_buffers() {
        for (u8 buffer_n = 0; buffer_n < 2; buffer_n++) {
            u32 *bufferPtr = (u32 *) double_buffers[buffer_n];
            for (u32 j = 0; j < SOUND_ENGINE_BUFFER_SIZE / 4; j++)
                bufferPtr[j] = 0;
        }
    }

    INLINE void clear_current_buffers() {
        u32 *bufferPtr = (u32 *) double_buffers[cur_buffer];
        for (u32 j = 0; j < SOUND_ENGINE_BUFFER_SIZE / 4; j++)
            bufferPtr[j] = 0;
    }

    void mute() {
        BN_LOG(" >>>>>>>>>>>> MUTE!");
        SNDSTAT &= ~SNDSTAT_ENABLE;
        is_muted = true;
    }

    void unmute() {
        BN_LOG(" >>>>>>>>>>>> UNMUTE!");
        // SNDSTAT |= SNDSTAT_ENABLE;
        is_muted = false;
    }

    void init() {
        BN_LOG("Initializing sound mixer...");
        clear_buffers();

        SNDSTAT = SNDSTAT_ENABLE;
        SETSNDRES(1);

        DSOUNDCTRL = DSOUNDCTRL_A100 | DSOUNDCTRL_AL | DSOUNDCTRL_AR | DSOUNDCTRL_ATIMER(0) | DSOUNDCTRL_ARESET;
        // mute();

        if (!initialized) {
        cur_buffer = 0;
        REG_DMA1CNT = 0;
        REG_DMA1SAD = (intptr_t)double_buffers;
        REG_DMA1DAD = FIFO_ADDR_A;
        REG_DMA1CNT = DMA_DST_FIXED | DMA_SRC_FIXED | DMA32 | DMA_SPECIAL | DMA_ENABLE;

            initialized = true;
            REG_TM0CNT_H = 0;
            REG_TM0CNT_L = SOUND_ENGINE_TM0_RESTART;
            REG_TM0CNT_H = TIMER_START;

            REG_TM1CNT_L = 0x10000 - (SOUND_ENGINE_BUFFER_SIZE);
            REG_TM1CNT_H = TIMER_START | TIMER_IRQ | TIMER_COUNT;
        }
            playerULC_init();
            player8AD_init();
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

    void mix_audio(const s8 *src_buffer, const int src_size, const bn::fixed volume = 1.0) {
        if (src_buffer == nullptr) {
            return;
        }
        if (src_size != SOUND_ENGINE_BUFFER_SIZE) {
            mix_audio_resampled_linear(src_buffer, double_buffers[cur_buffer], src_size, SOUND_ENGINE_BUFFER_SIZE, volume);
        } else {
            for (int i = 0; i < SOUND_ENGINE_BUFFER_SIZE; i++) {
                double_buffers[cur_buffer][i] = CLAMP(double_buffers[cur_buffer][i] + (src_buffer[i] * volume).integer(), -128, 127);
            }
        }
    }

    void directsound_copy() {
        if (cur_buffer == 0) {
            REG_DMA1CNT = 0;
            REG_DMA1SAD = (intptr_t) double_buffers;
            REG_DMA1CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA32 | DMA_SPECIAL | DMA_ENABLE;
        }
        cur_buffer ^= 1;
    }

    INLINE void mix_all() {
        if (is_muted) {
            return;
        }
        mix_audio(playerULC_get_buffer(), BUFFER_SIZE_ULC, ks::sound_manager::get_mixed_volume<SOUND_CHANNEL_MUSIC>());
        mix_audio(player8AD_get_buffer(0), BUFFER_SIZE_8AD, ks::sound_manager::get_mixed_volume<SOUND_CHANNEL_SOUND>());
        mix_audio(player8AD_get_buffer(1), BUFFER_SIZE_8AD, ks::sound_manager::get_mixed_volume<SOUND_CHANNEL_AMBIENT>());
    }

    void update() {
        if (is_muted) {
            clear_buffers();
            // cur_buffer = 0;
            return;
        }
        directsound_copy();

        clear_current_buffers();
        playerULC_update();
        player8AD_update();
        mix_all();

        SNDSTAT |= SNDSTAT_ENABLE;
    }
}

