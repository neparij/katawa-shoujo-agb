// ReSharper disable CppUnusedIncludeDirective
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "definitions/scripts.h"
#include "definitions/labels.h"

typedef unsigned char gameState_t;
#define GS_INIT ((gameState_t)0)
#define GS_MENU_MAIN ((gameState_t)1)
#define GS_MENU_SAVES ((gameState_t)2)
#define GS_MENU_EXTRAS ((gameState_t)3)
#define GS_MENU_OPTIONS ((gameState_t)4)
#define GS_MENU_EXTRAS_JUKEBOX ((gameState_t)5)
#define GS_MENU_EXTRAS_CINEMA ((gameState_t)6)
#define GS_START_GAME ((gameState_t)7)
#define GS_LOAD_GAME ((gameState_t)8)
#define GS_GAME ((gameState_t)9)
#define GS_GAME_MENU ((gameState_t)10)
#define GS_GAME_MENU_SAVES ((gameState_t)11)
#define GS_RESET ((gameState_t)100)

typedef unsigned char forceRoute_t;
#define FR_NONE   ((forceRoute_t)0)
#define FR_EMI    ((forceRoute_t)1)
#define FR_HANAKO ((forceRoute_t)2)
#define FR_LILLY  ((forceRoute_t)3)
#define FR_RIN    ((forceRoute_t)4)
#define FR_SHIZU  ((forceRoute_t)5)
#define FR_KENJI  ((forceRoute_t)6)

typedef unsigned char language_t;
#define LANG_ENGLISH ((language_t)0)
#define LANG_RUSSIAN ((language_t)1)

typedef unsigned char sound_channel_t;
#define SOUND_CHANNEL_MUSIC ((sound_channel_t)0)
#define SOUND_CHANNEL_SOUND ((sound_channel_t)1)
#define SOUND_CHANNEL_AMBIENT ((sound_channel_t)2)
#define SOUND_CHANNEL_VIDEO ((sound_channel_t)3)

typedef unsigned char music_t;
#define MUSIC_NONE ((music_t)0)
#define MUSIC_TRANQUIL ((music_t)1)
#define MUSIC_NURSE ((music_t)2)
#define MUSIC_SOOTHING ((music_t)3)
#define MUSIC_TWINKLE ((music_t)4)
#define MUSIC_MOONLIGHT ((music_t)5)
#define MUSIC_RAIN ((music_t)6)
#define MUSIC_TRAGIC ((music_t)7)
#define MUSIC_COMFORT ((music_t)8)
#define MUSIC_LILLY ((music_t)9)
#define MUSIC_DAILY ((music_t)10)
#define MUSIC_EASE ((music_t)11)
#define MUSIC_ANOTHER ((music_t)12)
#define MUSIC_FRIENDSHIP ((music_t)13)
#define MUSIC_HAPPINESS ((music_t)14)
#define MUSIC_COMEDY ((music_t)15)
#define MUSIC_TENSION ((music_t)16)
#define MUSIC_RUNNING ((music_t)17)
#define MUSIC_INNOCENCE ((music_t)18)
#define MUSIC_HEART ((music_t)19)
#define MUSIC_SERENE ((music_t)20)
#define MUSIC_DRAMA ((music_t)21)
#define MUSIC_NIGHT ((music_t)22)
#define MUSIC_KENJI ((music_t)23)
#define MUSIC_HANAKO ((music_t)24)
#define MUSIC_RIN ((music_t)25)
#define MUSIC_TIMESKIP ((music_t)26)
#define MUSIC_DREAMY ((music_t)27)
#define MUSIC_JAZZ ((music_t)28)
#define MUSIC_ROMANCE ((music_t)29)
#define MUSIC_CREDITS ((music_t)30)
#define MUSIC_MUSICBOX ((music_t)31)
#define MUSIC_NORMAL ((music_t)32)
#define MUSIC_SADNESS ((music_t)33)
#define MUSIC_EMI ((music_t)34)
#define MUSIC_PEARLY ((music_t)35)
#define MUSIC_SHIZUNE ((music_t)36)
#define MUSIC_ONE ((music_t)37)
#define MUSIC_MENUS ((music_t)38)

typedef unsigned char scene_transition_t;
#define SCENE_TRANSITION_NONE ((scene_transition_t)0)
#define SCENE_TRANSITION_LOCATIONCHANGE ((scene_transition_t)1)
#define SCENE_TRANSITION_LOCATIONSKIP ((scene_transition_t)2)
#define SCENE_TRANSITION_SHORTTIMESKIP ((scene_transition_t)3)
#define SCENE_TRANSITION_SHORTTIMESKIPSILENT ((scene_transition_t)4)
#define SCENE_TRANSITION_OPENEYE ((scene_transition_t)5)
#define SCENE_TRANSITION_SHUTEYE ((scene_transition_t)6)
#define SCENE_TRANSITION_OPENEYEFAST ((scene_transition_t)7)
#define SCENE_TRANSITION_SHUTEYEFAST ((scene_transition_t)8)
#define SCENE_TRANSITION_OPENEYE_SHOCK ((scene_transition_t)9)
#define SCENE_TRANSITION_WHIP_RIGHT ((scene_transition_t)10)
#define SCENE_TRANSITION_WHIP_LEFT ((scene_transition_t)11)
#define SCENE_TRANSITION_FLASHBACK ((scene_transition_t)12) // TODO: Check the correctness (see: script-a2-emi)
#define SCENE_TRANSITION_DELAYBLINDS ((scene_transition_t)13)
#define SCENE_TRANSITION_HANDS_IN ((scene_transition_t)14)
#define SCENE_TRANSITION_HANDS_OUT ((scene_transition_t)15)
#define SCENE_TRANSITION_SOFTWIPEDOWN ((scene_transition_t)16)
#define SCENE_TRANSITION_SOFTWIPEUP ((scene_transition_t)17)
#define SCENE_TRANSITION_SILENTFLASH ((scene_transition_t)18)
#define SCENE_TRANSITION_FLASH ((scene_transition_t)19)
#define SCENE_TRANSITION_SILENTWHITEOUT ((scene_transition_t)20)
#define SCENE_TRANSITION_WHITEOUT ((scene_transition_t)21)
#define SCENE_TRANSITION_CAMERAFLASH ((scene_transition_t)22)
#define SCENE_TRANSITION_CAMERAFLASHLONG ((scene_transition_t)23)
#define SCENE_TRANSITION_PASSOUTOP1 ((scene_transition_t)24)
#define SCENE_TRANSITION_SHOWDOWN_THUNDER_LONG ((scene_transition_t)25)
#define SCENE_TRANSITION_SHOWDOWN_THUNDER_SHORT ((scene_transition_t)26)
#define SCENE_TRANSITION_DOTWIPE_UP ((scene_transition_t)27)
#define SCENE_TRANSITION_DOTWIPE_DOWN ((scene_transition_t)28)
#define SCENE_TRANSITION_CLOCKWIPE_IN ((scene_transition_t)29)
#define SCENE_TRANSITION_CLOCKWIPE_OUT ((scene_transition_t)30)

typedef unsigned char character_t;
#define CHARACTER_NONE ((character_t)0)
#define CHARACTER_AKIRA ((character_t)1)
#define CHARACTER_EMI ((character_t)2)
#define CHARACTER_EMICAS ((character_t)3)
#define CHARACTER_EMINUDE ((character_t)4)
#define CHARACTER_EMIWHEEL ((character_t)5)
#define CHARACTER_HANAGOWN ((character_t)6)
#define CHARACTER_HANAKO ((character_t)7)
#define CHARACTER_HIDEAKI ((character_t)8)
#define CHARACTER_JIGORO ((character_t)9)
#define CHARACTER_KENJI ((character_t)10)
#define CHARACTER_LILLY ((character_t)11)
#define CHARACTER_MEIKO ((character_t)12)
#define CHARACTER_MIKI ((character_t)13)
#define CHARACTER_MISHA ((character_t)14)
#define CHARACTER_MISHASHORT ((character_t)15)
#define CHARACTER_MUTO ((character_t)16)
#define CHARACTER_NOMIYA ((character_t)17)
#define CHARACTER_NURSE ((character_t)18)
#define CHARACTER_RIN ((character_t)19)
#define CHARACTER_RINPAN ((character_t)20)
#define CHARACTER_SAE ((character_t)21)
#define CHARACTER_SHIZU ((character_t)22)
#define CHARACTER_SHIZUYU ((character_t)23)
#define CHARACTER_SHOPKEEP ((character_t)24)
#define CHARACTER_YUUKO ((character_t)25)
#define CHARACTER_YUUKOSHANG ((character_t)26)

#endif //DEFINITIONS_H
