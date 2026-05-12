#ifndef KS_SCRIPT_A1_WEDNESDAY
#define KS_SCRIPT_A1_WEDNESDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/hanako.h"
#include "smart_characters/emi.h"
#include "smart_characters/lilly.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/muto.h"
#include "smart_characters/rin.h"
#include "smart_characters/nurse.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/suburb_shanghaiext.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/shizu_shanghai.h"
#include "background_metas/shizu_shanghai_borednormal.h"
#include "background_metas/shizu_shanghai_boredlaugh.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_miyagi.h"
#include "background_metas/tearoom_everyone_noon.h"
#include "background_metas/school_classroomart.h"
#include "background_metas/rin_eating.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_dormext_start.h"
#include "background_metas/mural_start.h"
#include "background_metas/school_dormext_start_ss.h"
#include "background_metas/school_dormext_half_ni.h"
#include "../events/emi_knockeddown_facepullout.cpp.h"
#include "../events/emi_knockeddown_largepullout.cpp.h"
#include "../events/emi_knockeddown_legs.cpp.h"
#include "../events/emi_knockeddown.cpp.h"
namespace ks {
    class ScriptA1Wednesday {
        public:
            virtual ~ScriptA1Wednesday() = default;
            // Labels
            SCENE_INLINE void a1_wednesday_lunch_evolution_theory();
            SCENE_INLINE void a1_wednesday_short_sharp_shock();
            SCENE_INLINE void a1_wednesday_meet_cute();
            SCENE_INLINE void a1_wednesday_detour_ahead();
            SCENE_INLINE void a1_wednesday_sip_p1();
            SCENE_INLINE void a1_wednesday_it_builds_character();
            SCENE_INLINE void a1_wednesday_a_private_lunch();
            SCENE_INLINE void a1_wednesday_waylay();
            SCENE_INLINE void a1_wednesday_the_other_green();
            static void a1_wednesday();
            SCENE_INLINE void separate_of_sss_and_mc();
            SCENE_INLINE void a1c6o1();
            SCENE_INLINE void a1c6o2();
            SCENE_INLINE void a1c6o3();
            SCENE_INLINE void a1c7o1();
            SCENE_INLINE void a1c7o2();
            // Choice functions
            SCENE_INLINE void a1_wednesday_lunch_evolution_theory__menu_question_0();
            SCENE_INLINE void a1_wednesday_lunch_evolution_theory__menu_question_0_read_my_book();
            SCENE_INLINE void a1_wednesday_lunch_evolution_theory__menu_question_0_go_talk_with_hanako();
            SCENE_INLINE void a1_wednesday_lunch_evolution_theory__menu_question_0_wait_for_shizune_and_misha_to_come_to_a_decision();
            SCENE_INLINE void a1_wednesday_waylay__menu_question_0();
            SCENE_INLINE void a1_wednesday_waylay__menu_question_0_yes();
            SCENE_INLINE void a1_wednesday_waylay__menu_question_0_maybe();
            // Conditions
            SCENE_INLINE void a1_wednesday_short_sharp_shock__condition_0_0();
            SCENE_INLINE void a1_wednesday_short_sharp_shock__condition_0_1();
            SCENE_INLINE void a1_wednesday_short_sharp_shock__condition_1_0();
            SCENE_INLINE void a1_wednesday_meet_cute__condition_0_0();
            SCENE_INLINE void a1_wednesday__condition_0_0();
            SCENE_INLINE void a1_wednesday__condition_0_1();
            SCENE_INLINE void a1_wednesday_detour_ahead__condition_0_0();
            SCENE_INLINE void a1_wednesday_sip_p1__condition_0_0();
            SCENE_INLINE void a1_wednesday__condition_1_0();
            SCENE_INLINE void a1_wednesday__condition_1_1();
            SCENE_INLINE void a1_wednesday_it_builds_character__condition_0_0();
            SCENE_INLINE void a1_wednesday__condition_2_0();
            SCENE_INLINE void a1_wednesday_a_private_lunch__condition_0_0();
            SCENE_INLINE void a1_wednesday_waylay__condition_0_0();
            SCENE_INLINE void a1_wednesday_the_other_green__condition_0_0();
    };
}

#endif // KS_SCRIPT_A1_WEDNESDAY