#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include <BN_LOG.h>
#include <gba.h>

// Constants
#define VRAM_F  0x6000000
#define VRAM_B  0x600A000
#define SHOW_BACKBUFFER 0x10
#define TIMER_256_PRESCALER 2

#define KEY_DOWN_NOW(key)  (~(REG_KEYINPUT) & key)

// Function prototypes
void videoplayer_init(const uint8_t* agmv_file,
                size_t agmv_size,
                const char* audio_file,
                unsigned char r_clear,
                unsigned char g_clear,
                unsigned char b_clear);
void videoplayer_play();
void videoplayer_clean();
bool videoplayer_is_playing();

#endif // VIDEO_PLAYER_H
