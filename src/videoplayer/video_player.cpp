#include "video_player.h"
#include "../amgvplayer/agmv_gba.h"
#include "../gsmplayer/player_8ad.h"
#include "../gsmplayer/player_gsm.h"
#include "../globals.h"
#include <gba_interrupt.h>

#include "../sound_manager.h"

#define VP_INLINE static inline __attribute__((always_inline))
#define VP_IWRAM __attribute__((section(".iwram")))

static AGMV* g_agmv = nullptr;
static const char* g_audio_file;
static volatile bool g_is_finished = true;
static volatile int g_nextFrame = 0;
static int g_currentFrame = 0;
static u16* g_front_buffer = (u16*)VRAM_F;
static u16* g_back_buffer = (u16*)VRAM_B;
static u16* g_buffer = (u16*)VRAM_F;
static unsigned char quart_number = 0;

VP_INLINE void reset_video_state()
{
    g_is_finished = false;
    g_nextFrame = 0;
    g_currentFrame = 0;
    g_buffer = g_front_buffer;
    REG_DISPCNT |= SHOW_BACKBUFFER;
}

VP_INLINE u16* flip_buffers(u16* buffer)
{
    if (buffer == g_front_buffer) {
        REG_DISPCNT &= ~SHOW_BACKBUFFER;
        return g_back_buffer;
    } else {
        REG_DISPCNT |= SHOW_BACKBUFFER;
        return g_front_buffer;
    }
}


VP_INLINE void VP_IWRAM update()
{
    bool willRender = (g_currentFrame != g_nextFrame);
    if (willRender && !AGMV_IsVideoDone(g_agmv)) {
        AGMV_StreamMovie(g_agmv, quart_number);
        quart_number++;
    }


    ks::sound_manager::update();
    VBlankIntrWait();

    if (willRender && quart_number == 4) {
        if (g_currentFrame == 0) {
            ks::sound_manager::play<SOUND_CHANNEL_MUSIC>(g_audio_file);
        }
        if (AGMV_IsVideoDone(g_agmv)) {
            g_is_finished = true;
        }
        AGMV_DisplayFrame(g_buffer, 160, 128, g_agmv);
        quart_number = 0;
        g_currentFrame++;
        g_buffer = flip_buffers(g_buffer);
    }

    if (KEY_DOWN_NOW(KEY_START)) {
        // TODO: REMOVE
        g_is_finished = true;
        playerGSM_stop();
    }

}

VP_INLINE void stream()
{
    g_nextFrame = g_nextFrame + 1;
}

VP_INLINE void clear_screen(volatile u16* buffer, u16 color)
{
    for (int y = 0; y < 128; y++) {
        for (int x = 0; x < 160; x++) {
            buffer[y * 128 + x] = color;
        }
    }
}

void videoplayer_init(const uint8_t* agmv_file, size_t agmv_size, const char* audio_file,
                unsigned char r_clear, unsigned char g_clear, unsigned char b_clear)
{

    // Clear both buffers
    clear_screen(g_front_buffer, RGB5(r_clear, g_clear, b_clear));
    clear_screen(g_back_buffer, RGB5(r_clear, g_clear, b_clear));
    reset_video_state();

    // Open AGMV video and initialize audio
    g_agmv = AGMV_Open(agmv_file, agmv_size);
    AGMV_DisableAudio(g_agmv);
    // player_unload();
    // player_sfx_unload();
    // player_init();
    g_audio_file = audio_file;

    // // Clear both buffers
    // clear_screen(g_front_buffer, RGB5(r_clear, g_clear, b_clear));
    // clear_screen(g_back_buffer, RGB5(r_clear, g_clear, b_clear));

    // Set video mode and buffers
    REG_DISPCNT = MODE_5 | BG2_ENABLE;
    REG_BG2PA = 128;  // For 240x160 video
    REG_BG2PD = 128;

    // Configure Timer 2 for 15 FPS (4375 * 2 ticks at 1:256 prescaler)
    REG_TM2CNT_H = 0;
    REG_TM2CNT_L = 0x10000 - (4375 * 2);
    REG_TM2CNT_H = TIMER_256_PRESCALER | TIMER_IRQ | TIMER_START;

    // Disable HBL to avoid conflict with Butano
    // irqDisable(IRQ_HBLANK);
    // irqDisable(IRQ_VBLANK);

    // Enable interrupts
    irqInit();
    irqEnable(IRQ_VBLANK);
    irqEnable(IRQ_TIMER2);
    // irqSet(IRQ_VBLANK, player_onVBlank);
    irqSet(IRQ_VBLANK, ks::globals::ISR_VBlank);
    irqSet(IRQ_TIMER2, stream);
}

void videoplayer_clean()
{
    // irqInit();
    // irqSet(IRQ_TIMER2, nullptr);
    // irqSet(IRQ_VBLANK, nullptr);

    if (g_agmv) {
        AGMV_Close(g_agmv);
        g_agmv = nullptr;
    }
}

void videoplayer_play()
{
    while (!g_is_finished) {
        update();
    }
}

bool videoplayer_is_playing()
{
    return !g_is_finished;
}
