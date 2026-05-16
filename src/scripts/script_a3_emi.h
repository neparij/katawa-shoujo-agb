#ifndef KS_SCRIPT_A3_EMI
#define KS_SCRIPT_A3_EMI

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/muto.h"
#include "smart_characters/emi.h"
#include "smart_characters/nurse.h"
#include "smart_characters/rin.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/kenji.h"
#include "smart_characters/meiko.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_track.h"
#include "background_metas/school_gate.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/suburb_konbiniext.h"
#include "background_metas/suburb_park.h"
#include "background_metas/emi_parkback.h"
#include "background_metas/emi_parkback_frown.h"
#include "background_metas/school_dormext_full.h"
#include "background_metas/school_track_on.h"
#include "background_metas/school_track_running.h"
#include "background_metas/school_nursehall.h"
#include "background_metas/school_nurseoffice.h"
#include "background_metas/school_staircase1.h"
#include "background_metas/school_roof.h"
#include "background_metas/rin_roof_boredom.h"
#include "background_metas/rin_roof_surprised.h"
#include "background_metas/rin_roof_nonchalant.h"
#include "background_metas/rin_roof_doubt.h"
#include "background_metas/rin_roof_disgust.h"
#include "background_metas/school_library.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/school_dormemi.h"
#include "background_metas/emi_grinding_victorytall.h"
#include "background_metas/emi_grinding_victory.h"
#include "background_metas/emi_grinding_wink.h"
#include "background_metas/emi_grinding_grin.h"
#include "background_metas/emi_grinding_half_undress.h"
#include "background_metas/emi_grinding_half_grin.h"
#include "background_metas/emi_grinding_off_yawn.h"
#include "background_metas/emi_grinding_off_closesurprise.h"
#include "background_metas/emi_grinding_off_closearoused.h"
#include "background_metas/emi_grinding_off_aroused.h"
#include "background_metas/emi_grinding_off_arousedclosed.h"
#include "background_metas/emi_grinding_off_come.h"
#include "background_metas/emi_grinding_off_end.h"
#include "background_metas/school_sportsstoreext.h"
#include "background_metas/school_sportsstoreroom.h"
#include "background_metas/emi_shed_base1.h"
#include "background_metas/emi_shed_base2.h"
#include "background_metas/emi_shed_base3.h"
#include "background_metas/emi_shed_base4.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/emi_firstkiss.h"
#include "background_metas/school_dormext_full_ni.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/emi_run_face.h"
#include "background_metas/busride.h"
#include "background_metas/city_street4.h"
#include "background_metas/city_alley.h"
#include "background_metas/emi_houseext.h"
#include "background_metas/emi_kitchen.h"
#include "background_metas/emi_dining.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_track_ni.h"
#include "background_metas/school_track_on_ni.h"
#include "background_metas/school_track_running_ni.h"
#include "background_metas/hisao_letter_open_2.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/emi_forehead.h"
namespace ks {
    class ScriptA3Emi {
        public:
            virtual ~ScriptA3Emi() = default;
            // Labels
            SCENE_INLINE void a3_emi_eet_ees_scienca();
            SCENE_INLINE void a3_emi_definitions();
            SCENE_INLINE void a3_emi_invisible_rock();
            SCENE_INLINE void a3_emi_lunch_and_science();
            SCENE_INLINE void a3_emi_up_down_and_up_again();
            SCENE_INLINE void a3_emi_storage_space();
            SCENE_INLINE void a3_emi_afterschool_plans();
            SCENE_INLINE void a3_emi_detached();
            SCENE_INLINE void a3_emi_phantom_pain();
            SCENE_INLINE void a3_emi_debate_expresses_doubt();
            SCENE_INLINE void a3_emi_guess_whos_coming_never_mind();
            SCENE_INLINE void a3_emi_instant_replay();
            static void a3_emi();
            SCENE_INLINE void a3ec1o1();
            SCENE_INLINE void a3ec1o2();
            SCENE_INLINE void a3ec2o1();
            SCENE_INLINE void a3ec2o2();
            SCENE_INLINE void a3ec3o1();
            SCENE_INLINE void a3ec3o2();
            SCENE_INLINE void a3ec4o1();
            SCENE_INLINE void a3ec4o2();
            SCENE_INLINE void a3ec5o1();
            SCENE_INLINE void a3ec5o2();
            // Choice functions
            SCENE_INLINE void a3_emi_definitions__menu_question_0();
            SCENE_INLINE void a3_emi_definitions__menu_question_0_press_emi();
            SCENE_INLINE void a3_emi_definitions__menu_question_0_let_it_rest();
            SCENE_INLINE void a3_emi_phantom_pain__menu_question_0();
            SCENE_INLINE void a3_emi_phantom_pain__menu_question_0_i_suppose_i_can_spare_a_few_minutes();
            SCENE_INLINE void a3_emi_phantom_pain__menu_question_0_no_i_have_other_things_to_worry_about();
            SCENE_INLINE void a3_emi_debate_expresses_doubt__condition_0__menu_question_0();
            SCENE_INLINE void a3_emi_debate_expresses_doubt__condition_0__menu_question_0_sure_why_not();
            SCENE_INLINE void a3_emi_debate_expresses_doubt__condition_0__menu_question_0_no_this_is_my_problem();
            SCENE_INLINE void a3_emi_guess_whos_coming_never_mind__condition_2__menu_question_0();
            SCENE_INLINE void a3_emi_guess_whos_coming_never_mind__condition_2__menu_question_0_go_after_her();
            SCENE_INLINE void a3_emi_guess_whos_coming_never_mind__condition_2__menu_question_0_talk_to_her_mom();
            SCENE_INLINE void a3_emi_instant_replay__menu_question_0();
            SCENE_INLINE void a3_emi_instant_replay__menu_question_0_downplay_the_issue();
            SCENE_INLINE void a3_emi_instant_replay__menu_question_0_give_in_and_let_misha_know();
            // Conditions
            SCENE_INLINE void a3_emi_eet_ees_scienca__condition_0_0();
            SCENE_INLINE void a3_emi_definitions__condition_0_0();
            SCENE_INLINE void a3_emi_invisible_rock__condition_0_0();
            SCENE_INLINE void a3_emi_invisible_rock__condition_0_1();
            SCENE_INLINE void a3_emi_invisible_rock__condition_1_0();
            SCENE_INLINE void a3_emi_lunch_and_science__condition_0_0();
            SCENE_INLINE void a3_emi_up_down_and_up_again__condition_0_0();
            SCENE_INLINE void a3_emi_storage_space__condition_0_0();
            SCENE_INLINE void a3_emi_afterschool_plans__condition_0_0();
            SCENE_INLINE void a3_emi_detached__condition_0_0();
            SCENE_INLINE void a3_emi_phantom_pain__condition_0_0();
            SCENE_INLINE void a3_emi_debate_expresses_doubt__condition_0_0();
            SCENE_INLINE void a3_emi_debate_expresses_doubt__condition_1_0();
            SCENE_INLINE void a3_emi_guess_whos_coming_never_mind__condition_0_0();
            SCENE_INLINE void a3_emi_guess_whos_coming_never_mind__condition_1_0();
            SCENE_INLINE void a3_emi_guess_whos_coming_never_mind__condition_2_0();
            SCENE_INLINE void a3_emi_guess_whos_coming_never_mind__condition_2_1();
            SCENE_INLINE void a3_emi_guess_whos_coming_never_mind__condition_3_0();
            SCENE_INLINE void a3_emi_instant_replay__condition_0_0();
            SCENE_INLINE void a3_emi__condition_0_0();
    };
}

#endif // KS_SCRIPT_A3_EMI