#include "video_player.h"
#include "../amgvplayer/agmv_gba.h"
#include "../gsmplayer/player_8ad.h"
#include "../gsmplayer/player_gsm.h"
#include "../globals.h"
#include <gba_interrupt.h>

#include "bn_memory.h"
#include "../sound_manager.h"
#include "../dxtvplayer/videoplayer.h"

#define VP_INLINE static inline __attribute__((always_inline))
#define VP_IWRAM __attribute__((section(".iwram")))

// BN_DATA_EWRAM_BSS uint32_t ScratchPad[160 * 128 / 2 + 15000 / 4 + 1];
BN_DATA_EWRAM_BSS uint32_t ScratchPad[160 * 128 / 2 + 15000 / 4 + 1];
// uint32_t* alignas(4) ScratchPad;

static const char* g_audio_file;
// static int g_currentFrame = 0;
static u16* g_front_buffer = (u16*)VRAM_F;
static u16* g_back_buffer = (u16*)VRAM_B;
static u16* g_buffer = (u16*)VRAM_F;

VP_INLINE void reset_video_state()
{
    g_buffer = g_front_buffer;
    REG_DISPCNT |= SHOW_BACKBUFFER;
    for (int i = 0; i < sizeof(ScratchPad); i++) {
        ScratchPad[i] = 0;
    }
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
    ks::sound_manager::update();
    VBlankIntrWait();
}

VP_INLINE void clear_screen(volatile u16* buffer, u16 color)
{
    for (int y = 0; y < 128; y++) {
        for (int x = 0; x < 160; x++) {
            buffer[y * 128 + x] = color;
        }
    }
}

void videoplayer_init(const uint8_t* dxtv_file, size_t agmv_size, const char* audio_file,
                unsigned char r_clear, unsigned char g_clear, unsigned char b_clear)
{

    // Clear both buffers
    // clear_screen(g_front_buffer, RGB5(r_clear, g_clear, b_clear));
    // clear_screen(g_back_buffer, RGB5(r_clear, g_clear, b_clear));
    reset_video_state();

    // int size = 160 * 128 / 2 + 15000 / 4 + 1;
    // ScratchPad = (uint32_t*)bn::memory::ewram_alloc(size);

    // Open AGMV video and initialize audio
    // Video::init((uint32_t*)dxtv_file, (uint32_t*)ScratchPad, size);
    Video::init((uint32_t*)dxtv_file, ScratchPad, sizeof(ScratchPad));
    // g_agmv = AGMV_Open(dxtv_file, agmv_size);
    // AGMV_DisableAudio(g_agmv);


    g_audio_file = audio_file;

    // Set video mode and buffers
    REG_DISPCNT = MODE_5 | BG2_ENABLE;
    REG_BG2CNT = 0x1C0B; // 0b0001110000001011
    REG_BG2PA = (int)(256 / (1.5f));  // For 160x128 video
    REG_BG2PD = (int)(256 / (1.25f));
    REG_BG2X = 0;
    REG_BG2Y = 0;

    // Configure Timer 2 for 15 FPS (4375 * 2 ticks at 1:256 prescaler)
    // REG_TM2CNT_H = 0;
    // REG_TM2CNT_L = 0x10000 - (4375 * 2);
    // REG_TM2CNT_H = TIMER_256_PRESCALER | TIMER_IRQ | TIMER_START;

    // Disable HBL to avoid conflict with Butano
    // irqDisable(IRQ_HBLANK);
    // irqDisable(IRQ_VBLANK);

    // Enable interrupts
    irqInit();
    irqEnable(IRQ_VBLANK);
    // irqEnable(IRQ_TIMER2);
    // irqSet(IRQ_VBLANK, player_onVBlank);
    irqSet(IRQ_VBLANK, ks::globals::ISR_VBlank);
    // irqSet(IRQ_TIMER2, stream);
}

void videoplayer_clean()
{
    // bn::memory::ewram_free(ScratchPad);
    // irqInit();
    irqDisable(IRQ_TIMER2);
    // irqInit();
    // irqSet(IRQ_TIMER2, nullptr);
    // irqSet(IRQ_VBLANK, nullptr);


    // if (g_agmv) {
        // Video::stop();
        // AGMV_Close(g_agmv);
        // g_agmv = nullptr;
    // }
}

inline void inframe_updates() {
    // ks::sound_manager::update();
}

void videoplayer_play()
{
    // while (!g_is_finished) {
    //     update();
    // }

    ks::sound_manager::play<SOUND_CHANNEL_MUSIC>(g_audio_file);
    Video::play();
    do
    {
        ks::sound_manager::update();
        // Video::decodeAndBlitFrame((uint32_t *)VRAM, inframe_updates);
        Video::decodeAndBlitFrame((uint32_t *)VRAM_F);
    } while (Video::hasMoreFrames());
    Video::stop();
}
