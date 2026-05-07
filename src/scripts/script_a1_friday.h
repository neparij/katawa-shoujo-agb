#ifndef KS_SCRIPT_A1_FRIDAY
#define KS_SCRIPT_A1_FRIDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/emi.h"
#include "smart_characters/kenji.h"
#include "smart_characters/misha.h"
#include "smart_characters/shizu.h"
#include "smart_characters/rin.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/lilly.h"
#include "smart_characters/muto.h"
#include "smart_characters/nurse.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_track.h"
#include "background_metas/school_track_on.h"
#include "background_metas/school_track_running.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_council.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_staircase1.h"
#include "background_metas/school_roof.h"
#include "background_metas/school_library.h"
#include "background_metas/hana_library_read.h"
#include "background_metas/school_library_ss.h"
#include "background_metas/school_courtyard_ss.h"
#include "background_metas/school_gate_ss.h"
#include "background_metas/school_road_ss.h"
#include "background_metas/suburb_roadcenter_ss.h"
#include "background_metas/suburb_konbiniext_ss.h"
#include "background_metas/suburb_konbiniint.h"
#include "background_metas/misc_sky_ni.h"
#include "background_metas/suburb_konbiniext_ni.h"
#include "background_metas/suburb_roadcenter_ni.h"
#include "background_metas/school_road_ni.h"
#include "background_metas/school_nurseoffice.h"
#include "background_metas/school_nursehall.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_dormext_half_ni.h"
#include "background_metas/school_dormbathroom.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_dormhisao_ni.h"
namespace ks {
    class ScriptA1Friday {
        public:
            virtual ~ScriptA1Friday() = default;
            // Labels
            SCENE_INLINE void a1_friday_exercise();
            SCENE_INLINE void a1_friday_invisible_hat();
            SCENE_INLINE void a1_friday_home_field_advantage();
            SCENE_INLINE void a1_friday_slow_recovery();
            SCENE_INLINE void a1_friday_no_recovery();
            SCENE_INLINE void a1_friday_no_free_lunch();
            SCENE_INLINE void a1_friday_foot_and_mouth();
            SCENE_INLINE void a1_friday_mind_your_step();
            static void a1_friday();
            SCENE_INLINE void class_goes_lazily();
            SCENE_INLINE void mas_doesnt_bother();
            SCENE_INLINE void a1c9o1();
            SCENE_INLINE void a1c9o2();
            SCENE_INLINE void a1c10o1();
            SCENE_INLINE void a1c10o2();
            SCENE_INLINE void a1c11o1();
            SCENE_INLINE void a1c11o2();
            SCENE_INLINE void a1c12o1();
            SCENE_INLINE void a1c12o2();
            SCENE_INLINE void a1c13o1();
            SCENE_INLINE void a1c13o2();
            // Choice functions
            SCENE_INLINE void a1_friday_exercise__menu_question_0();
            SCENE_INLINE void a1_friday_exercise__menu_question_0_go_for_it();
            SCENE_INLINE void a1_friday_exercise__menu_question_0_take_it_easy();
            SCENE_INLINE void a1_friday_home_field_advantage__menu_question_0();
            SCENE_INLINE void a1_friday_home_field_advantage__menu_question_0_try_to_dodge_the_subject();
            SCENE_INLINE void a1_friday_home_field_advantage__menu_question_0_kick_them_out_of_my_room();
            SCENE_INLINE void a1_friday_slow_recovery__menu_question_0();
            SCENE_INLINE void a1_friday_slow_recovery__menu_question_0_yeah_i_sure_was_having_fun_fun_fun_at_the_nurses_office();
            SCENE_INLINE void a1_friday_slow_recovery__menu_question_0_i_dont_want_to_talk_about_it_okay();
            SCENE_INLINE void a1_friday_mind_your_step__menu_question_0();
            SCENE_INLINE void a1_friday_mind_your_step__menu_question_0_sorry_im_not_in_very_good_condition();
            SCENE_INLINE void a1_friday_mind_your_step__menu_question_0_i_dont_really_want_to_talk_about_it();
            SCENE_INLINE void a1c11o2__menu_question_0();
            SCENE_INLINE void a1c11o2__menu_question_0_ill_go_to_the_lunch_with_emi_and_her_friend();
            SCENE_INLINE void a1c11o2__menu_question_0_ill_go_with_shizune_after_all_im_in_the_student_council_now();
            // Conditions
            SCENE_INLINE void a1_friday_exercise__condition_0_0();
            SCENE_INLINE void a1_friday__condition_0_0();
            SCENE_INLINE void a1_friday_invisible_hat__condition_0_0();
            SCENE_INLINE void a1_friday_invisible_hat__condition_1_0();
            SCENE_INLINE void a1_friday_invisible_hat__condition_2_0();
            SCENE_INLINE void a1_friday__condition_1_0();
            SCENE_INLINE void a1_friday_home_field_advantage__condition_0_0();
            SCENE_INLINE void a1_friday__condition_2_0();
            SCENE_INLINE void a1_friday_no_recovery__condition_0_0();
            SCENE_INLINE void a1_friday_no_recovery__condition_1_0();
            SCENE_INLINE void a1_friday_slow_recovery__condition_0_0();
            SCENE_INLINE void a1_friday_slow_recovery__condition_0_1();
            SCENE_INLINE void a1_friday_slow_recovery__condition_1_0();
            SCENE_INLINE void a1_friday_no_recovery__condition_2_0();
            SCENE_INLINE void a1_friday_no_recovery__condition_2_1();
            SCENE_INLINE void a1_friday_no_recovery__condition_2_2();
            SCENE_INLINE void a1_friday_no_recovery__condition_3_0();
            SCENE_INLINE void a1_friday__condition_3_0();
            SCENE_INLINE void a1_friday_no_free_lunch__condition_0_0();
            SCENE_INLINE void a1_friday_no_free_lunch__condition_1_0();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_0_0();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_1__condition_0_0();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_1_0();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_1_1();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_2_0();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_3_0();
            SCENE_INLINE void a1_friday_mind_your_step__condition_0_0();
            SCENE_INLINE void a1_friday__condition_4__condition_0_0();
            SCENE_INLINE void a1_friday__condition_4_0();
            SCENE_INLINE void a1_friday__condition_4_1();
            SCENE_INLINE void a1c13o1__condition_0_0();
    };
}

#endif // KS_SCRIPT_A1_FRIDAY