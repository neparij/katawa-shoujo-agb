#ifndef PLAYER_SETTINGS_H
#define PLAYER_SETTINGS_H

// See: https://pineight.com/gba/samplerates/
// For the samplerates table

/*
 * Period   Buffer  Sample rate
 * 266      1056	63072.24
 * 308      912     54471.48
 * 399      704     42048.16
 * 418      672     40136.88
 * 462      608 	36314.32
 * 532      528 	31536.12
 * 627      448 	26757.92
 * 798      352     21024.08
 * 836      336     20068.44
 * 924      304     18157.16
 * 1254     224     13378.96
 * 1463     192     11467.68
 * 1596     176     10512.04
 * 2508     112     6689.48
 * 2926     96      5733.84
*/

#define DSOUNDCTRL_SETTINGS 0xfb0c; /*0b1111101100001100*/

// #define BUFFER_SIZE_B 304 * 2 // DOUBLE buffer size for GSM at 18157 Hz
#define BUFFER_SIZE_B 224 * 2 // DOUBLE buffer size for GSM at 13379 Hz
#define BUFFER_SIZE_A 192 // DOUBLE buffer size for PCM at 11468 Hz
// #define BUFFER_SIZE_A 56 * 2 // DOUBLE buffer size for PCM at 11468 Hz

// #define PERIOD_SIZE_B 462 // amount of cycles for GSM at 18157 Hz
#define PERIOD_SIZE_B 627 // amount of cycles for GSM at 13379 Hz
#define PERIOD_SIZE_A 1463 // amount of cycles for PCM at 11468 Hz
// #define PERIOD_SIZE_A 2508 // amount of cycles for PCM at 11468 Hz

#define TIMER_16MHZ 0

#define FIFO_ADDR_A 0x040000a0
#define CHANNEL_A_MUTE 0xfcff  /*0b1111110011111111*/
#define CHANNEL_A_UNMUTE 0x300 /*0b0000001100000000*/

#define FIFO_ADDR_B 0x040000A4
#define CHANNEL_B_MUTE 0xcfff   /*0b1100111111111111*/
#define CHANNEL_B_UNMUTE 0x3000 /*0b0011000000000000*/

#define AUDIO_CHUNK_SIZE_GSM 33
// #define AUDIO_CHUNK_SIZE_PCM 304
#define AUDIO_CHUNK_SIZE_PCM 96

#define FRACUMUL_PRECISION 0xFFFFFFFF
// #define AS_MSECS_GSM 1146880000
#define AS_MSECS_GSM 1146880000
// #define AS_MSECS_PCM 118273043  // 0xffffffff * (1000/36314)
#define AS_MSECS_PCM 0xffffffff * (1000/11468)

#define AS_CURSOR_GSM 3201039125
#define AS_CURSOR_PCM 1348619731

#define REG_DMA1CNT_L *(vu16*)(REG_BASE + 0x0c4)
#define REG_DMA1CNT_H *(vu16*)(REG_BASE + 0x0c6)

#define REG_DMA2CNT_L *(vu16*)(REG_BASE + 0x0d0)
#define REG_DMA2CNT_H *(vu16*)(REG_BASE + 0x0d2)

#endif // PLAYER_SETTINGS_H
