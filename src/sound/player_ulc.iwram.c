#include <gba_dma.h>
#include "gba_math.h"
#include <stdlib.h>

#include "player_ulc.h"
#include "../utils/gbfs/gbfs.h"
#include "ulcGBA.h"

#ifndef CODE_ROM
#define CODE_ROM __attribute__((section(".code")))
#endif

#ifndef INLINE
#define INLINE static inline __attribute__((always_inline))
#endif

static const GBFS_FILE* fs;
static const unsigned char* src = NULL;
static u32 src_len = 0;
static s8 out_buffer[BUFFER_SIZE_ULC] __attribute__((aligned(4)));

static int ulc_remaining_bytes = 0;
static bool is_looping = false;

INLINE void clear_buffers() {
    u32 *bufferPtr = (u32 *)out_buffer;
    for (u32 j = 0; j < BUFFER_SIZE_ULC / 4; j++)
        bufferPtr[j] = 0;
}

INLINE void stop() {
    src = NULL;
    ulc_State.SoundFile = NULL;
    ulc_State.nBufProc = 0;
    ulc_State.LastSubBlockSize = 0;
    ulc_State.nBlkRem = 0;
    ulc_State.NextData = NULL;
}

INLINE void start_playback() {
    ulc_State.SoundFile = (struct ulc_FileHeader_t*)src;
    ulc_State.RdBufIdx = 0; // current read buffer
    ulc_State.nBufProc = 0;
    ulc_State.LastSubBlockSize = 0;
    ulc_State.nBlkRem = ulc_State.SoundFile->nBlocks - 1;
    ulc_State.NextData = src + ulc_State.SoundFile->StreamOffs;
    ulc_State.PauseBit = 0;
    ulc_remaining_bytes = 0;
}

INLINE void load_file(const char* name) {
    src = gbfs_get_obj(fs, name, &src_len);
}

CODE_ROM void playerULC_init() {
    fs = find_first_gbfs_file(0);
    clear_buffers();
}

CODE_ROM void playerULC_play(const char* name) {
    stop();
    load_file(name);
    start_playback();
}

CODE_ROM void playerULC_set_loop(bool enable) {
    is_looping = enable;
}

CODE_ROM void playerULC_set_pause(const bool enable) {
    ulc_State.PauseBit = enable ? 1 : 0;
}

CODE_ROM void playerULC_stop() {
    stop();
    clear_buffers();
}

CODE_ROM bool playerULC_is_playing() {
  return src != NULL;
}

void playerULC_update() {
    if (src == NULL) return;

    int buffer_remaining_bytes = BUFFER_SIZE_ULC;
    while(buffer_remaining_bytes) {
        // Decode if need more samples
        if(ulc_remaining_bytes == 0) {
            ulc_UpdatePlayer();
            ulc_remaining_bytes = ulc_State.SoundFile->BlockSize;
        }

        const int bytes_to_fill = min(ulc_remaining_bytes, buffer_remaining_bytes);
        const int dstPos = BUFFER_SIZE_ULC - buffer_remaining_bytes;
        const int srcPos = ulc_State.SoundFile->BlockSize - ulc_remaining_bytes;
        buffer_remaining_bytes -= bytes_to_fill;
        ulc_remaining_bytes -= bytes_to_fill;

        for (int i = 0; i < bytes_to_fill; i++) {
           out_buffer[dstPos + i] = ulc_OutputBuffer[srcPos + i];
        }
    }

    if (ulc_State.nBlkRem == 0) {
        if (is_looping) {
            start_playback();
        } else {
            stop();
            clear_buffers();
        }
    }
}

s8* playerULC_get_buffer() {
    return out_buffer;
}
