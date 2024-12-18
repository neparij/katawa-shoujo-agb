#ifndef VIDTEST_CPP_H
#define VIDTEST_CPP_H

#include <gba.h>
#include "amgvplayer/agmv_gba.h"
#include "gsmplayer/player.h"
#include "video_tc_act2_emi_agmv.h"
#include "video_4ls_agmv.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "constants.h"
#include "globals.h"


#define VRAM_F  0x6000000
#define VRAM_B	0x600A000


namespace ks
{
class VidTest
{
public:
    VidTest(const GBFS_FILE* _fs)
    {
        SetVideoMode(AGMV_MODE_3);
        EnableTimer2();
        // REG_BG2PA = 1 << 7 | 76; // For AGMV_HIGH_QUALITY video
        // REG_BG2PD = 1 << 7 | 76; // For AGMV_HIGH_QUALITY video

        REG_BG2PA = 128;  // For 240x160 video
        REG_BG2PD = 128;  // For 240x160 video
        vram = (u16*)VRAM_F;
        // agmv = AGMV_Open(video_tc_act2_emi_agmv, video_tc_act2_emi_agmv_size);
        agmv = AGMV_Open(video_4ls_agmv, video_4ls_agmv_size);
        irqInit();
        irqEnable(IRQ_VBLANK);
    }


    bool is_finished()
    {
        return _is_finished;
    }

    void BN_CODE_IWRAM update()
    {
        if (_is_finished) return;

        // VBlankIntrWait();
        if((REG_TM2CNT/frame_rate)!=lastFr) {

            AGMV_StreamMovie(agmv);
            AGMV_DisplayFrame(vram,240,160,agmv);

            if(AGMV_IsVideoDone(agmv)){
                _is_finished = true;
                AGMV_Close(agmv);
                // irqInit();
                // irqEnable(IRQ_VBLANK);
            }

            FPS+=1;
            if(lastFr>(REG_TM2CNT/frame_rate)){
                FPS=0;
            }

            lastFr=(REG_TM2CNT/frame_rate);
        }

    }

private:
    bool _is_finished = false;
    // u32 frame_rate = 10000;
    // u32 frame_rate = 14400; // 10fps
    // u32 frame_rate = 9600; // 15fps
    // u32 frame_rate = 6400; // 20fps
    // u32 frame_rate = 4800; // 30fps
    // u32 frame_rate = 2400; // 60fps

    u32 frame_rate = 4200; // Looks like a truth for 4LS logo at 30 FPS with AGMV_OPT_GBA_I,AGMV_MID_QUALITY,AGMV_LZSS_COMPRESSION

    int lastFr = 0;
    int FPS = 0;
    AGMV* agmv;
    u16* vram;
};

}

#endif // VIDTEST_CPP_H
