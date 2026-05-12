#ifndef KS_SCRIPT_A1_MONDAY
#define KS_SCRIPT_A1_MONDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/muto.h"
#include "smart_characters/misha.h"
#include "smart_characters/shizu.h"
#include "smart_characters/hanako.h"
#include "smart_characters/nurse.h"
#include "smart_characters/kenji.h"
#include "background_metas/school_gate.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_nursehall.h"
#include "background_metas/school_nurseoffice.h"
#include "background_metas/school_gardens.h"
#include "background_metas/school_dormext_start.h"
#include "background_metas/school_dormhallground.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_dormhisao_ni.h"
#include "../events/op_snowywoods.cpp.h"
#include "../events/other_iwanako.cpp.h"
#include "../events/hosp_room.cpp.h"
#include "../events/drugs.cpp.h"
#include "../events/hisao_class_start.cpp.h"
#include "../events/hisao_class_move.cpp.h"
#include "../events/hisao_class_end.cpp.h"
namespace ks {
    class ScriptA1Monday {
        public:
            virtual ~ScriptA1Monday() = default;
            // Labels
            SCENE_INLINE void a1_monday_out_cold();
            SCENE_INLINE void a1_monday_bundle_of_hisao();
            SCENE_INLINE void a1_monday_gateway_effect();
            SCENE_INLINE void a1_monday_enter_stage_left();
            SCENE_INLINE void a1_monday_in_the_nursery();
            SCENE_INLINE void a1_monday_nobodys_room();
            static void a1_monday();
            SCENE_INLINE void a1c1o1();
            SCENE_INLINE void a1c1o2();
            SCENE_INLINE void a1c2o1();
            SCENE_INLINE void a1c2o2();
            SCENE_INLINE void a1c2o3();
            // Choice functions
            SCENE_INLINE void a1_monday_gateway_effect__menu_question_0();
            SCENE_INLINE void a1_monday_gateway_effect__menu_question_0_why();
            SCENE_INLINE void a1_monday_gateway_effect__menu_question_0_yeah_of_course();
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0();
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0_ask_about_the_library();
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness();
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know();
            // Conditions
            SCENE_INLINE void a1_monday_out_cold__condition_0_0();
            SCENE_INLINE void a1_monday_bundle_of_hisao__condition_0_0();
            SCENE_INLINE void a1_monday_gateway_effect__condition_0_0();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_0_0();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_0_1();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_1_0();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_1_1();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_2_0();
            SCENE_INLINE void a1_monday_in_the_nursery__condition_0_0();
            SCENE_INLINE void a1_monday_nobodys_room__condition_0_0();
    };
}

#endif // KS_SCRIPT_A1_MONDAY