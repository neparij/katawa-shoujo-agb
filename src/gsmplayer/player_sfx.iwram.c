#include "player_sfx.h"

#include <gba_dma.h>
#include <gba_input.h>
#include <gba_interrupt.h>
#include <gba_sound.h>
#include <gba_systemcalls.h>
#include <gba_timers.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>  // for memset

#include "player_settings.h"
#include "../utils/gbfs/gbfs.h"

#define CODE_ROM __attribute__((section(".code")))
#define CODE_EWRAM __attribute__((section(".ewram")))
#define INLINE static inline __attribute__((always_inline))

// ------------------------------------
// SFX player (for uncompressed s8 PCM)
// ------------------------------------
// Audio is taken from the embedded GBFS file in ROM.
// FIFO channel A, Timer 0 and DMA1 are used.
// The sample rate is 36314hz.
// Each PCM chunk is 304 bytes and represents 304 samples.
// Two chunks are copied per frame.

static bool did_run = false;
static bool is_looping = false;
static bool is_paused = false;
ADGlobals ad;

static const signed char ima9_step_indices[16] =
    {
        -1, -1, -1, -1, 2, 4, 7, 12,
        -1, -1, -1, -1, 2, 4, 7, 12
};

const unsigned short ima_step_table[89] =
    {
        7,    8,    9,   10,   11,   12,   13,   14,   16,   17,
        19,   21,   23,   25,   28,   31,   34,   37,   41,   45,
        50,   55,   60,   66,   73,   80,   88,   97,  107,  118,
        130,  143,  157,  173,  190,  209,  230,  253,  279,  307,
        337,  371,  408,  449,  494,  544,  598,  658,  724,  796,
        876,  963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
        2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
        5894, 6484, 7132, 7845, 8630, 9493,10442,11487,12635,13899,
        15289,16818,18500,20350,22385,24623,27086,29794,32767
};

#define AUDIO_PROCESS_SFX(ON_STOP)                                       \
  did_run = true;                                                    \
  buffer = double_buffers[cur_buffer];                               \
                                                                     \
  if (src != NULL) {                                                 \
    if (src_pos < src_len) {                                         \
      u32 pending_bytes = src_len - src_pos;                         \
      u32 bytes_to_read =                                            \
          pending_bytes < BUFFER_SIZE_A ? pending_bytes : BUFFER_SIZE_A; \
      src_pos += BUFFER_SIZE_A / 2;                                        \
      if (src_pos >= src_len) {                                      \
        ON_STOP;                                                     \
      }                                                              \
    } else {                                                         \
      ON_STOP;                                                       \
    }                                                                \
  }


uint32_t fracumul(uint32_t x, uint32_t frac) __attribute__((long_call));
static const GBFS_FILE* fs;
static const u8* src = NULL;
static u32 src_len = 0;
static u32 src_pos = 0;
static s8 double_buffers[2][BUFFER_SIZE_A] __attribute__((aligned(4)));
static u32 cur_buffer = 0;
static s8* buffer;

INLINE void mute() {
  DSOUNDCTRL = DSOUNDCTRL & CHANNEL_A_MUTE;
}

INLINE void unmute() {
  DSOUNDCTRL = DSOUNDCTRL | CHANNEL_A_UNMUTE;
}

INLINE void turn_on_sound() {
  SETSNDRES(1);
  SNDSTAT = SNDSTAT_ENABLE;
  DSOUNDCTRL = DSOUNDCTRL_SETTINGS;
  mute();
}

INLINE void clear_buffers() {
    for (u32 i = 0; i < 2; i++) {
        u32* bufferPtr = (u32*)double_buffers[i];
        for (u32 j = 0; j < BUFFER_SIZE_A / 4; j++)
            bufferPtr[j] = 0;
    }
}


INLINE void init() {
  /* TMxCNT_L is count; TMxCNT_H is control */
  REG_TM0CNT_H = 0;
  REG_TM0CNT_L = 0x10000 - PERIOD_SIZE_A;
  REG_TM0CNT_H = TIMER_16MHZ | TIMER_START;

  mute();
  src = NULL;
}

INLINE void stop() {
  mute();
  src = NULL;
  cur_buffer = 0;
  clear_buffers();
}

INLINE void disable_audio_dma() {
  // This convoluted process disables DMA1 in a "safe" way,
  // avoiding DMA lockups.
  //
  // 32-bit write
  // enabled = 1; start timing = immediately; transfer type = 32 bits;
  // repeat = off; destination = fixed; other bits = no change
  REG_DMA1CNT = (REG_DMA1CNT & 0xcdff /*0b00000000000000001100110111111111*/) |
                (0x0004 << 16) | DMA_ENABLE | DMA32 | DMA_DST_FIXED;
  //
  // wait 4 cycles
  asm volatile("eor r0, r0; eor r0, r0" ::: "r0");
  asm volatile("eor r0, r0; eor r0, r0" ::: "r0");

  //
  // 16-bit write
  // enabled = 0; start timing = immediately; transfer type = 32 bits;
  // repeat = off; destination = fixed; other bits = no change
  REG_DMA1CNT_H = (REG_DMA1CNT_H & 0x4dff /*0b0100110111111111*/) |
                  0x500 /*0b0000010100000000*/;  // DMA32 | DMA_DST_FIXED
  //
  // wait 4 more cycles
  asm volatile("eor r0, r0; eor r0, r0" ::: "r0");
  asm volatile("eor r0, r0; eor r0, r0" ::: "r0");
}

INLINE void dsound_start_audio_copy(const void* source) {
  // disable DMA1
  disable_audio_dma();

  // setup DMA1 for audio
  REG_DMA1SAD = (intptr_t)source;
  REG_DMA1DAD = (intptr_t)FIFO_ADDR_A;
  REG_DMA1CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA32 | DMA_SPECIAL |
                DMA_ENABLE | 1;
}

INLINE void load_file(const char* name) {
  stop();

  src = gbfs_get_obj(fs, name, &src_len);
  start_ad(src);

  src_pos = 0;

  is_looping = false;
  is_paused = false;
}

CODE_ROM void player_sfx_init() {
  fs = find_first_gbfs_file(0);
  // turn_on_sound();
  init();
}

CODE_ROM void player_sfx_unload() {
  disable_audio_dma();
}

CODE_ROM void player_sfx_play(const char* name) {
  load_file(name);
}

CODE_ROM void player_sfx_setLoop(bool enable) {
  is_looping = enable;
}

CODE_ROM void player_sfx_setPause(bool enable) {
  is_paused = enable;
}

CODE_ROM PlayerSFXState player_sfx_getState() {
  PlayerSFXState state;
  state.pos = src_pos;
  state.isPlaying = src != NULL;
  state.isLooping = is_looping;
  return state;
}

CODE_ROM void player_sfx_setState(PlayerSFXState state) {
  src_pos = state.pos;
  is_looping = is_looping;
  did_run = false;
}

CODE_ROM void player_sfx_stop() {
  stop();
  is_looping = false;
  is_paused = false;
}

CODE_ROM bool player_sfx_isPlaying() {
  return src != NULL;
}

void player_sfx_onVBlank() {
  if (src != NULL) {
    dsound_start_audio_copy(double_buffers[cur_buffer]);
  }

  if (!did_run)
    return;

  if (src != NULL) {
    unmute();
    // dsound_start_audio_copy(double_buffers[cur_buffer]);
  }

  cur_buffer = !cur_buffer;
  did_run = false;
}

void player_sfx_update() {
  if (is_paused || src == NULL) {
    mute();
    return;
  }

  decode_ad(double_buffers[cur_buffer], ad.data, BUFFER_SIZE_A);
  // double_buffers
  ad.data += BUFFER_SIZE_A >> 1;

  // > audio processing (back buffer)
  AUDIO_PROCESS_SFX({
    if (is_looping) {
      src_pos = 0;
      start_ad(src);
      did_run = false;
    } else
      player_sfx_stop();
  });
}

INLINE int ima9_rescale(int step, unsigned int code)
{
    /* 0,1,2,3,4,5,6,9 */
    int diff = step >> 3;
    if(code & 1)
        diff += step >> 2;
    if(code & 2)
        diff += step >> 1;
    if(code & 4)
        diff += step;
    if((code & 7) == 7)
        diff += step >> 1;
    if(code & 8)
        diff = -diff;
    return diff;
}

void start_ad(const unsigned char *data)
{
    ad.data = data;
    ad.last_sample = 0;
    ad.last_index = 0;
}

void decode_ad(signed char *dst, const unsigned char *src, unsigned int len)
{
    int last_sample = ad.last_sample;
    int index = ad.last_index;
    unsigned int by = 0;

    while(len > 0)
    {
        int step, diff;
        unsigned int code;

        if(index < 0)
            index = 0;
        if(index > 88)
            index = 88;
        step = ima_step_table[index];

        if(len & 1)
            code = by >> 4;
        else
        {
            by = *src++;
            code = by & 0x0f;
        }

        diff = ima9_rescale(step, code);
        index += ima9_step_indices[code & 0x07];

        last_sample += diff;
        if(last_sample < -32768)
            last_sample = -32768;
        if(last_sample > 32767)
            last_sample = 32767;
        *dst++ = last_sample >> 8;

        len--;
    }

    ad.last_index = index;
    ad.last_sample = last_sample;
}
