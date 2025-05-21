#ifndef SOUND_MIXER_PREFS_H
#define SOUND_MIXER_PREFS_H

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

// Output buffers is set to 18157 Hz
#define SOUND_ENGINE_BUFFER_SIZE 224 // Sound output buffer size
#define SOUND_ENGINE_PERIOD_SIZE 1254 // Sound output timers period size

// Output buffers is set to 13379 Hz
// #define SOUND_ENGINE_BUFFER_SIZE 224 // Sound output buffer size
// #define SOUND_ENGINE_PERIOD_SIZE 1254 // Sound output timers period size

#define SOUND_ENGINE_MIX_ON_VBLANK false

// #define SOUND_ENGINE_ULC_BS 256 // ULC block size: This should be permanent for all ULC files
// #define SOUND_ENGINE_8AD_BS 192 // 8AD block size: This should be permanent for all 8AD files

#define SOUND_ENGINE_STEREO (ULC_STEREO_SUPPORT)

#define FIFO_ADDR_A 0x040000A0
#define FIFO_ADDR_B 0x040000A4
#define TIMER_16MHZ 0

#define SOUND_ENGINE_8AD_CHANNELS 2 // This is a number of SFX channels (mono)


#endif //SOUND_MIXER_PREFS_H
