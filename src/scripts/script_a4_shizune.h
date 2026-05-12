#ifndef KS_SCRIPT_A4_SHIZUNE
#define KS_SCRIPT_A4_SHIZUNE

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/hideaki.h"
#include "smart_characters/jigoro.h"
#include "smart_characters/kenji.h"
#include "smart_characters/lilly.h"
#include "background_metas/school_library.h"
#include "background_metas/school_council.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_roof.h"
#include "background_metas/misc_sky.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/school_gate.h"
#include "background_metas/school_gardens.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/shizu_roof.h"
#include "background_metas/shizu_roof_towardsangry.h"
#include "background_metas/shizu_roof_towardsnormal.h"
#include "background_metas/shizu_roof_smile.h"
#include "background_metas/school_council_ss.h"
#include "background_metas/shizu_undressing_clothed_stare.h"
#include "background_metas/shizu_undressing_clothed_kiss.h"
#include "background_metas/shizu_undressing_clothed_blush.h"
#include "background_metas/shizu_undressing_unclothed_closed.h"
#include "background_metas/shizu_undressing_unclothed_blush.h"
#include "background_metas/shizu_undressing_unclothed_kiss.h"
#include "background_metas/shizu_undressing_unclothed_talk.h"
#include "background_metas/school_council_ni.h"
#include "background_metas/shizu_pushdown.h"
#include "background_metas/shizu_straddle_open.h"
#include "background_metas/shizu_straddle_tease.h"
#include "background_metas/shizu_straddle_closed.h"
#include "background_metas/shizu_straddle_smile.h"
#include "background_metas/shizu_straddle_come.h"
#include "background_metas/shizu_table_smile.h"
#include "background_metas/shizu_table_normal.h"
#include "background_metas/shizu_table_comeopen.h"
#include "background_metas/shizu_table_comeclosed.h"
#include "background_metas/school_courtyard_ni.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/misha_nightclass.h"
#include "background_metas/school_room34_ni.h"
#include "background_metas/shizu_goodend.h"
#include "background_metas/school_miyagi.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/school_backexit.h"
#include "background_metas/shizu_badend.h"
namespace ks {
    class ScriptA4Shizune {
        public:
            virtual ~ScriptA4Shizune() = default;
            // Labels
            SCENE_INLINE void a4_shizune_grand_strategy();
            SCENE_INLINE void a4_shizune_off_by_one();
            SCENE_INLINE void a4_shizune_invasion();
            SCENE_INLINE void a4_shizune_parfait();
            SCENE_INLINE void a4_shizune_the_summit();
            SCENE_INLINE void a4_shizune_succession();
            SCENE_INLINE void a4_shizune_sneaking_mission();
            SCENE_INLINE void a4_shizune_infinity();
            SCENE_INLINE void a4_shizune_present_tense();
            SCENE_INLINE void a4_shizune_spiral();
            SCENE_INLINE void a4_shizune_terminal();
            static void a4_shizune();
            // Choice functions
            // Conditions
            SCENE_INLINE void a4_shizune_grand_strategy__condition_0_0();
            SCENE_INLINE void a4_shizune_off_by_one__condition_0_0();
            SCENE_INLINE void a4_shizune_invasion__condition_0_0();
            SCENE_INLINE void a4_shizune_parfait__condition_0_0();
            SCENE_INLINE void a4_shizune_the_summit__condition_0_0();
            SCENE_INLINE void a4_shizune_the_summit__condition_0_1();
            SCENE_INLINE void a4_shizune_the_summit__condition_1_0();
            SCENE_INLINE void a4_shizune_succession__condition_0_0();
            SCENE_INLINE void a4_shizune_sneaking_mission__condition_0_0();
            SCENE_INLINE void a4_shizune_infinity__condition_0_0();
            SCENE_INLINE void a4_shizune_present_tense__condition_0_0();
            SCENE_INLINE void a4_shizune_spiral__condition_0_0();
            SCENE_INLINE void a4_shizune_terminal__condition_0_0();
            SCENE_INLINE void a4_shizune__condition_0_0();
            SCENE_INLINE void a4_shizune__condition_0_1();
    };
}

#endif // KS_SCRIPT_A4_SHIZUNE