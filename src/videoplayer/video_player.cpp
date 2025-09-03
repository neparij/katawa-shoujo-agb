#include "video_player.h"
#include "../globals.h"
#include <gba_interrupt.h>

#include "bn_memory.h"
#include "../sound_manager.h"
#include "../dxtvplayer/videoplayer.h"
#include "../sound/sound_mixer.h"

#define VP_INLINE static inline __attribute__((always_inline))
#define VP_IWRAM __attribute__((section(".iwram")))

#define KEY_PRESSED(key) (~(REG_KEYINPUT) & key)

static const char* g_audio_file;
static bool sound_started = false;
VP_INLINE void reset_video_state()
{
    // Show the front buffer only while the processing is done in the back buffer.
    REG_DISPCNT &= ~SHOW_BACKBUFFER;
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
    irqSet(IRQ_TIMER1, sound_mixer::update);
    irqEnable(IRQ_TIMER1);
}

void videoplayer_clean()
{
    irqDisable(IRQ_TIMER1);
    irqDisable(IRQ_TIMER2);
}

void inframe_updates() {
    ks::sound_manager::update();
}

void videoplayer_play(const bool force_white)
{
    sound_started = false;
    Video::play();
    while (Video::hasMoreFrames()) {
        if (KEY_PRESSED(KEY_START)) {
            BN_LOG("Stop video immediately: Start was pressed");
            ks::sound_manager::stop<SOUND_CHANNEL_VIDEO>();
            break;
        }
        Video::decodeAndBlitFrame((uint32_t *)VRAM_F, inframe_updates);
        if (!sound_started) {
            ks::sound_manager::play<SOUND_CHANNEL_VIDEO>(g_audio_file);
            sound_mixer::unmute();
            sound_started = true;
        }
    }
    inframe_updates();
    Video::stop();

    REG_BG2CNT = 0x0000;

    // Disable BG2 and Enable Force Blank screen (LCDC_OFF)
    REG_DISPCNT &= ~BG2_ENABLE;
    if (force_white) {
        REG_DISPCNT |= LCDC_OFF;
    }
}
