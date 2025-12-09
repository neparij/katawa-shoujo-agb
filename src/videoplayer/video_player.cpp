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

static uint32_t* g_scratchpad = nullptr;
static const char* g_audio_file;
static bool sound_started = false;

VP_INLINE void clear_screen(volatile u16* buffer, const u16 color)
{
    for (int y = 0; y < 160; y++) {
        for (int x = 0; x < 240; x++) {
            buffer[y * 240 + x] = color;
        }
    }
}

void videoplayer_init(const uint8_t* dxtv_file, const char* audio_file,
                const unsigned char r_clear, const unsigned char g_clear, const unsigned char b_clear)
{
    // Clear both buffers
    clear_screen((u16*)VRAM, RGB5(r_clear, g_clear, b_clear));

    // Set video mode and buffers

    REG_DISPCNT = MODE_3 | BG2_ENABLE; // 240x160
    REG_BG2CNT = 0x1C0B; // 0b0001110000001011
    REG_BG2PA = (int)(256 / (1.0f));  // For 240x160 video
    REG_BG2PD = (int)(256 / (1.0f));
    REG_BG2X = 0;
    REG_BG2Y = 0;

    constexpr int scratchpad_size = 240 * 160 * 2; // Size in bytes
    g_scratchpad = (uint32_t*)bn::memory::ewram_alloc(scratchpad_size); // EWRAM for video decoding
    Video::init((uint32_t*)dxtv_file, g_scratchpad, scratchpad_size);
    g_audio_file = audio_file;

    irqInit();
    irqSet(IRQ_TIMER1, sound_mixer::update);
    irqEnable(IRQ_TIMER1);
}

void videoplayer_clean()
{
    irqDisable(IRQ_TIMER1);
    irqDisable(IRQ_TIMER2);
    bn::memory::ewram_free(g_scratchpad);
}

void inframe_updates() {
    if (!sound_started) {
        ks::sound_manager::play<SOUND_CHANNEL_VIDEO>(g_audio_file);
        sound_mixer::unmute();
        sound_started = true;
    }

    ks::sound_manager::update();
    ks::globals::update_system_stats();
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
        Video::decodeAndBlitFrame((uint32_t *)VRAM, inframe_updates);
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
