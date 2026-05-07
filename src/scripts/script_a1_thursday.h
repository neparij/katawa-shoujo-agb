#ifndef KS_SCRIPT_A1_THURSDAY
#define KS_SCRIPT_A1_THURSDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/emi.h"
#include "smart_characters/kenji.h"
#include "smart_characters/lilly.h"
#include "smart_characters/misha.h"
#include "smart_characters/shizu.h"
#include "smart_characters/hanako.h"
#include "smart_characters/rin.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_track.h"
#include "background_metas/school_track_running.h"
#include "background_metas/school_track_on.h"
#include "background_metas/school_dormext_half.h"
#include "background_metas/school_dormbathroom.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/lilly_shizu_showdown.h"
#include "background_metas/school_council_ss.h"
#include "background_metas/school_council_ni.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_room32.h"
#include "background_metas/school_gardens2_ni.h"
#include "background_metas/school_dormext_half_ni.h"
#include "background_metas/mural_unfinished.h"
#include "background_metas/school_dormhisao_ni.h"
#include "../events/lilly_shizu_showdown_slices.cpp.h"
#include "../events/lilly_shizu_showdown_lilly.cpp.h"
#include "../events/lilly_shizu_showdown_shizu.cpp.h"
namespace ks {
    class ScriptA1Thursday {
        public:
            virtual ~ScriptA1Thursday() = default;
            // Labels
            SCENE_INLINE void a1_thursday_the_running_girl();
            SCENE_INLINE void a1_thursday_soap();
            SCENE_INLINE void a1_thursday_cold_war();
            SCENE_INLINE void a1_thursday_proof_of_competency();
            SCENE_INLINE void a1_thursday_event_horizon();
            SCENE_INLINE void a1_thursday_above_and_beyond();
            SCENE_INLINE void a1_thursday_paint_by_numbers();
            SCENE_INLINE void a1_thursday_things_you_can_do();
            static void a1_thursday();
            SCENE_INLINE void a1c8o1();
            SCENE_INLINE void a1c8o2();
            // Choice functions
            SCENE_INLINE void a1_thursday_cold_war__menu_question_0();
            SCENE_INLINE void a1_thursday_cold_war__menu_question_0_dont_drag_me_into_this_ive_done_my_part();
            SCENE_INLINE void a1_thursday_cold_war__menu_question_0_hey_come_on_cut_me_and_lilly_some_slack();
            // Conditions
            SCENE_INLINE void a1_thursday_the_running_girl__condition_0_0();
            SCENE_INLINE void a1_thursday_the_running_girl__condition_0_1();
            SCENE_INLINE void a1_thursday_the_running_girl__condition_1_0();
            SCENE_INLINE void a1_thursday_the_running_girl__condition_2_0();
            SCENE_INLINE void a1_thursday_the_running_girl__condition_2_1();
            SCENE_INLINE void a1_thursday_the_running_girl__condition_3_0();
            SCENE_INLINE void a1_thursday_the_running_girl__condition_3_1();
            SCENE_INLINE void a1_thursday_the_running_girl__condition_4_0();
            SCENE_INLINE void a1_thursday_soap__condition_0_0();
            SCENE_INLINE void a1_thursday_cold_war__condition_0__condition_0_0();
            SCENE_INLINE void a1_thursday_cold_war__condition_0__condition_0_1();
            SCENE_INLINE void a1_thursday_cold_war__condition_0_0();
            SCENE_INLINE void a1_thursday_cold_war__condition_1_0();
            SCENE_INLINE void a1_thursday_proof_of_competency__condition_0_0();
            SCENE_INLINE void a1_thursday_proof_of_competency__condition_1_0();
            SCENE_INLINE void a1_thursday__condition_0_0();
            SCENE_INLINE void a1_thursday_event_horizon__condition_0_0();
            SCENE_INLINE void a1_thursday__condition_1_0();
            SCENE_INLINE void a1_thursday_above_and_beyond__condition_0_0();
            SCENE_INLINE void a1_thursday__condition_2_0();
            SCENE_INLINE void a1_thursday_paint_by_numbers__condition_0_0();
            SCENE_INLINE void a1_thursday__condition_3_0();
            SCENE_INLINE void a1_thursday_things_you_can_do__condition_0_0();
            SCENE_INLINE void a1_thursday__condition_4_0();
            SCENE_INLINE void a1_thursday__condition_5_0();
            SCENE_INLINE void a1_thursday__condition_5_1();
    };
}

#endif // KS_SCRIPT_A1_THURSDAY