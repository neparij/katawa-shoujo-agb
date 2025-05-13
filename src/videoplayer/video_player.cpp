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
// BN_DATA_EWRAM_BSS uint32_t ScratchPad[160 * 128 / 2 + 15000 / 4 + 1];
// uint32_t* alignas(4) ScratchPad;

static const char* g_audio_file;
VP_INLINE void reset_video_state()
{
    REG_DISPCNT |= SHOW_BACKBUFFER;
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
            buffer[y * 160 + x] = color;
        }
    }
}

void videoplayer_init(const uint8_t* dxtv_file, size_t agmv_size, const char* audio_file,
                unsigned char r_clear, unsigned char g_clear, unsigned char b_clear)
{
    // Clear both buffers
    clear_screen((u16*)VRAM_F, RGB5(r_clear, g_clear, b_clear));
    clear_screen((u16*)VRAM_B, RGB5(g_clear, g_clear, b_clear));

    // Set video mode and buffers
    REG_DISPCNT = MODE_5 | BG2_ENABLE;
    REG_BG2CNT = 0x1C0B; // 0b0001110000001011
    REG_BG2PA = (int)(256 / (1.5f));  // For 160x128 video
    REG_BG2PD = (int)(256 / (1.25f));
    REG_BG2X = 0;
    REG_BG2Y = 0;

    reset_video_state();

    Video::init((uint32_t*)dxtv_file, (u32*)VRAM_B, VRAM_B - VRAM_F);
    g_audio_file = audio_file;

    irqInit();
    irqEnable(IRQ_VBLANK);
    irqSet(IRQ_VBLANK, ks::globals::ISR_VBlank);
}

void videoplayer_clean()
{
    irqDisable(IRQ_TIMER2);
}

void inframe_updates() {
    ks::sound_manager::update();
}

void videoplayer_play()
{
    bool sound_started = false;
    Video::play();
    while (Video::hasMoreFrames()) {
        Video::decodeAndBlitFrame((uint32_t *)VRAM_F, inframe_updates);
        if (!sound_started) {
            ks::sound_manager::play<SOUND_CHANNEL_VIDEO>(g_audio_file);
            sound_started = true;
        }
    }
    inframe_updates();
    Video::stop();
}
