#include "video_player.h"
#include "../globals.h"
#include <gba_input.h>
#include <gba_interrupt.h>
#include <gba_video.h>

#include "bn_memory.h"
#include "bn_log.h"
#include "../sound_manager.h"
#include "../ulcv/ulcvplayer.h"
#include "../sound/sound_mixer.h"

#define VP_INLINE static inline __attribute__((always_inline))
#define VP_IWRAM __attribute__((section(".iwram")))

#define KEY_PRESSED(key) (~(REG_KEYINPUT) & key)

static uint32_t* g_scratchpad = nullptr;
static int g_scratchpad_size = 0;
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

void videoplayer_init(const uint8_t* video_file, const char* audio_file,
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

    // One frame buffer (currFrame) + 32 KB for the decompressed frame stream.
    // prevFrame is always read directly from VRAM, so no second buffer needed.
    constexpr int ulcv_scratchpad_size = 240 * 160 * 2 + 32 * 1024;
    const bool is_ulcv = ULCV::isULCV((uint32_t*)video_file);
    g_scratchpad_size = ulcv_scratchpad_size;

    if (g_scratchpad) {
        bn::memory::ewram_free(g_scratchpad);
        g_scratchpad = nullptr;
    }
    g_scratchpad = (uint32_t*)bn::memory::ewram_alloc(g_scratchpad_size);
    if (!g_scratchpad) {
        BN_LOG("Video init failed: no EWRAM scratchpad");
        return;
    }

    if (!is_ulcv) {
        BN_LOG("Video init skipped: ULCV stream expected");
        bn::memory::ewram_free(g_scratchpad);
        g_scratchpad = nullptr;
        g_scratchpad_size = 0;
        return;
    }
    ULCV::init((uint32_t*)video_file, g_scratchpad, g_scratchpad_size);
    g_audio_file = audio_file;

    irqInit();
    irqSet(IRQ_TIMER1, sound_mixer::update);
    irqEnable(IRQ_TIMER1);
}

void videoplayer_clean()
{
    irqDisable(IRQ_TIMER1);
    irqDisable(IRQ_TIMER2);
    if (g_scratchpad) {
        bn::memory::ewram_free(g_scratchpad);
        g_scratchpad = nullptr;
        g_scratchpad_size = 0;
    }
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
    if (!g_scratchpad) {
        BN_LOG("Video play skipped: scratchpad is null");
        return;
    }
    sound_started = false;
    ULCV::play();
    while (ULCV::hasMoreFrames()) {
        if (KEY_PRESSED(KEY_START)) {
            BN_LOG("Stop video immediately: Start was pressed");
            ks::sound_manager::stop<SOUND_CHANNEL_VIDEO>();
            break;
        }
        ULCV::decodeAndBlitFrame((uint32_t *)VRAM, inframe_updates);
    }
    inframe_updates();
    ULCV::stop();

    REG_BG2CNT = 0x0000;

    // Disable BG2 and Enable Force Blank screen (LCDC_OFF)
    REG_DISPCNT &= ~BG2_ENABLE;
    if (force_white) {
        REG_DISPCNT |= LCDC_OFF;
    }
}
