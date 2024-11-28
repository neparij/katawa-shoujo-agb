#ifndef VIDTEST_CPP_H
#define VIDTEST_CPP_H

#include <gba.h>
#include "agmv_gba.h"
#include "gsmplayer/player.h"
// #include "open06_agmv.h"
#include "tc_act2_emi_agmv.h"
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
        // REG_BG2PA = 1 << 7 | 76;
        // REG_BG2PD = 1 << 7 | 76;
        REG_BG2PA = 128;
        REG_BG2PD = 128;
        vram = (u16*)VRAM_F;
        agmv = AGMV_Open(tc_act2_emi_agmv,tc_act2_emi_agmv_size);
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
        // _is_finished = true;

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
    // u32 frame_rate = 9600; // 10fps
    u32 frame_rate = 4800; // 30fps
    // u32 frame_rate = 2400; // 60fps
    int lastFr = 0;
    int FPS = 0;
    AGMV* agmv;
    u16* vram;
};

}

#endif // VIDTEST_CPP_H
