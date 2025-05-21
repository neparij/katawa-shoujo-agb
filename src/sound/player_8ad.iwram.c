/* Uses original playad.iwram.c from 8ad by Damian Yerrick

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

*/

#include "player_8ad.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>  // for memset

#include "../utils/gbfs/gbfs.h"

#define CODE_ROM __attribute__((section(".code")))
#define CODE_EWRAM __attribute__((section(".ewram")))
#define INLINE static inline __attribute__((always_inline))

static const signed char ima9_step_indices[16] =
{
    -1, -1, -1, -1, 2, 4, 7, 12,
    -1, -1, -1, -1, 2, 4, 7, 12
};

const unsigned short ima_step_table[89] =
{
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17,
    19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118,
    130, 143, 157, 173, 190, 209, 230, 253, 279, 307,
    337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
    2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
    5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

#define AUDIO_PROCESS_SFX(CH, ON_STOP)                                   \
  channels[CH].did_run = true;                                           \
                                                                         \
  if (channels[CH].src != NULL) {                                        \
    if (channels[CH].src_pos < channels[CH].src_len) {                   \
      u32 pending_bytes = channels[CH].src_len - channels[CH].src_pos;   \
      u32 bytes_to_read =                                                \
          pending_bytes < BUFFER_SIZE_8AD ? pending_bytes : BUFFER_SIZE_8AD; \
      channels[CH].src_pos += BUFFER_SIZE_8AD / 2;                         \
      if (channels[CH].src_pos >= channels[CH].src_len) {                \
        ON_STOP;                                                         \
      }                                                                  \
    } else {                                                             \
      ON_STOP;                                                           \
    }                                                                    \
  }

static const GBFS_FILE *fs;
static ADChannel channels[2];

INLINE void clear_buffers(const u8 ch) {
    u32 *bufferPtr = (u32 *) channels[ch].out_buffer;
    for (u32 j = 0; j < BUFFER_SIZE_8AD / 4; j++)
        bufferPtr[j] = 0;
}

INLINE void init() {
    channels[0].src = NULL;
    channels[1].src = NULL;
    clear_buffers(0);
    clear_buffers(1);
}

INLINE void stop(const u8 ch) {
    channels[ch].src = NULL;
    clear_buffers(ch);
}

INLINE void load_file(const char *name, const u8 ch) {
    stop(ch);

    channels[ch].src = (u8 *) gbfs_get_obj(fs, name, &channels[ch].src_len);
    start_ad(channels[ch].src, ch);

    channels[ch].src_pos = 0;

    channels[ch].is_looping = false;
    channels[ch].is_paused = false;
}

CODE_ROM void player8AD_init() {
    fs = find_first_gbfs_file(0);
    init();
}

CODE_ROM void player8AD_unload() {
    // disable_audio_dma();
}

CODE_ROM void player8AD_play(const char *name, const u8 ch) {
    load_file(name, ch);
}

CODE_ROM void player8AD_set_loop(bool enable, const u8 ch) {
    channels[ch].is_looping = enable;
}

CODE_ROM void player8AD_set_pause(bool enable, const u8 ch) {
    channels[ch].is_paused = enable;
}

CODE_ROM void player8AD_stop(const u8 ch) {
    stop(ch);
    channels[ch].is_looping = false;
    channels[ch].is_paused = false;
}

CODE_ROM bool player8AD_is_playing(const u8 ch) {
    return channels[ch].src != NULL;
}

void player8AD_update() {
    for (u8 ch = 0; ch < 2; ch++) {
        if (channels[ch].src != NULL) {
            decode_ad(channels[ch].out_buffer, channels[ch].ad.data, BUFFER_SIZE_8AD, ch);
            channels[ch].ad.data += BUFFER_SIZE_8AD >> 1;

            AUDIO_PROCESS_SFX(ch, {
                if (channels[ch].is_looping) {
                    channels[ch].src_pos = 0;
                    start_ad(channels[ch].src, ch);
                    channels[ch].did_run = false;
                } else
                    player8AD_stop(ch);
                });
        }
    }
}

s8* player8AD_get_buffer(const u8 ch) {
    return channels[ch].out_buffer;
}

INLINE int ima9_rescale(int step, unsigned int code) {
    /* 0,1,2,3,4,5,6,9 */
    int diff = step >> 3;
    if (code & 1)
        diff += step >> 2;
    if (code & 2)
        diff += step >> 1;
    if (code & 4)
        diff += step;
    if ((code & 7) == 7)
        diff += step >> 1;
    if (code & 8)
        diff = -diff;
    return diff;
}

void start_ad(const unsigned char *data, const u8 ch) {
    channels[ch].ad.data = data;
    channels[ch].ad.last_sample = 0;
    channels[ch].ad.last_index = 0;
}

void decode_ad(signed char *dst, const unsigned char *src, unsigned int len, const u8 ch) {
    int last_sample = channels[ch].ad.last_sample;
    int index = channels[ch].ad.last_index;
    unsigned int by = 0;

    while (len > 0) {
        int step, diff;
        unsigned int code;

        if (index < 0)
            index = 0;
        if (index > 88)
            index = 88;
        step = ima_step_table[index];

        if (len & 1)
            code = by >> 4;
        else {
            by = *src++;
            code = by & 0x0f;
        }

        diff = ima9_rescale(step, code);
        index += ima9_step_indices[code & 0x07];

        last_sample += diff;
        if (last_sample < -32768)
            last_sample = -32768;
        if (last_sample > 32767)
            last_sample = 32767;
        *dst++ = last_sample >> 8;

        len--;
    }

    channels[ch].ad.last_index = index;
    channels[ch].ad.last_sample = last_sample;
}
