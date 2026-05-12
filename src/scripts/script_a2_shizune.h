#ifndef KS_SCRIPT_A2_SHIZUNE
#define KS_SCRIPT_A2_SHIZUNE

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/kenji.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/hanako.h"
#include "smart_characters/lilly.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_dormext_full.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_staircase1.h"
#include "background_metas/school_roof.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_road.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/suburb_shanghaiext.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_council.h"
#include "background_metas/shizu_chess_large.h"
#include "background_metas/shizu_chess_base.h"
#include "background_metas/shizu_chess_base3.h"
#include "background_metas/shizu_chess_base2.h"
#include "background_metas/school_council_ss.h"
#include "background_metas/school_gardens2.h"
#include "background_metas/school_gardens.h"
#include "background_metas/kenji_glasses_bg.h"
#include "background_metas/school_road_ss.h"
#include "background_metas/school_courtyard_ss.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/school_courtyard_ni.h"
#include "background_metas/school_gate_ni.h"
#include "background_metas/shizutanabata.h"
#include "background_metas/suburb_tanabata_ni.h"
#include "background_metas/school_gardens_ni.h"
#include "background_metas/shizuconfess_normal.h"
#include "background_metas/shizuconfess_smile.h"
#include "background_metas/shizuconfess_closed.h"
namespace ks {
    class ScriptA2Shizune {
        public:
            virtual ~ScriptA2Shizune() = default;
            // Labels
            SCENE_INLINE void a2_shizune_message_passing();
            SCENE_INLINE void a2_shizune_talk_to_the_hand();
            SCENE_INLINE void a2_shizune_chinese_whispers();
            SCENE_INLINE void a2_shizune_advanced_game_theory();
            SCENE_INLINE void a2_shizune_bread_scissors_paper();
            SCENE_INLINE void a2_shizune_interface();
            SCENE_INLINE void a2_shizune_spring_into_action();
            SCENE_INLINE void a2_shizune_past_imperfective();
            SCENE_INLINE void a2_shizune_when_stars_embrace();
            static void a2_shizune();
            // Choice functions
            // Conditions
            SCENE_INLINE void a2_shizune_message_passing__condition_0_0();
            SCENE_INLINE void a2_shizune_talk_to_the_hand__condition_0_0();
            SCENE_INLINE void a2_shizune_chinese_whispers__condition_0_0();
            SCENE_INLINE void a2_shizune_advanced_game_theory__condition_0_0();
            SCENE_INLINE void a2_shizune_bread_scissors_paper__condition_0_0();
            SCENE_INLINE void a2_shizune_interface__condition_0_0();
            SCENE_INLINE void a2_shizune_spring_into_action__condition_0_0();
            SCENE_INLINE void a2_shizune_past_imperfective__condition_0_0();
            SCENE_INLINE void a2_shizune_when_stars_embrace__condition_0_0();
    };
}

#endif // KS_SCRIPT_A2_SHIZUNE