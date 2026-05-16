#ifndef KS_SCRIPT_A2_RIN
#define KS_SCRIPT_A2_RIN

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/muto.h"
#include "smart_characters/emi.h"
#include "smart_characters/rin.h"
#include "smart_characters/misha.h"
#include "smart_characters/nomiya.h"
#include "smart_characters/kenji.h"
#include "smart_characters/shizu.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/meiko.h"
#include "smart_characters/nurse.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_staircase1.h"
#include "background_metas/school_roof.h"
#include "background_metas/rin_roof_boredom.h"
#include "background_metas/rin_roof_doubt.h"
#include "background_metas/rin_roof_nonchalant.h"
#include "background_metas/rin_roof_surprised.h"
#include "background_metas/misc_sky.h"
#include "background_metas/rin_artclass1.h"
#include "background_metas/rin_artclass2.h"
#include "background_metas/rin_artclass3.h"
#include "background_metas/rin_artclass4.h"
#include "background_metas/school_classroomart.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_dormbathroom.h"
#include "background_metas/hisao_mirror.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/bird_0.h"
#include "background_metas/bird_1.h"
#include "background_metas/bird_2.h"
#include "background_metas/bird_3.h"
#include "background_metas/bird_4.h"
#include "background_metas/bird_5.h"
#include "background_metas/bird_6.h"
#include "background_metas/bird_7.h"
#include "background_metas/bird_8.h"
#include "background_metas/bird_9.h"
#include "background_metas/watch_black.h"
#include "background_metas/school_library.h"
#include "background_metas/school_track.h"
#include "background_metas/emitrack_blocks.h"
#include "background_metas/emitrack_blocks_close.h"
#include "background_metas/emitrack_running.h"
#include "background_metas/emitrack_finish.h"
#include "background_metas/emitrack_blocks_close_grin.h"
#include "background_metas/emi_run_face.h"
#include "background_metas/school_track_on.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_backexit.h"
#include "background_metas/school_forest1.h"
#include "background_metas/school_forest2.h"
#include "background_metas/school_forestclearing.h"
#include "background_metas/worrytree.h"
#include "background_metas/school_dormext_full_ni.h"
#include "background_metas/hisao_letter_closed.h"
#include "background_metas/hisao_letter_open.h"
#include "background_metas/hisao_letter_open_2.h"
#include "background_metas/rin_painting_base.h"
#include "background_metas/rin_painting_foot.h"
#include "background_metas/rin_painting_reply.h"
#include "background_metas/rin_painting_concerned.h"
#include "background_metas/rin_painting_faceconcerned.h"
#include "background_metas/school_road.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/suburb_shanghaiext.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/rin_rain_away_close.h"
#include "background_metas/rin_rain_towards_close.h"
#include "background_metas/rin_rain_towards.h"
#include "background_metas/rin_rain_away.h"
#include "background_metas/school_dormext_full.h"
#include "background_metas/school_nurseoffice.h"
#include "background_metas/school_nursehall.h"
#include "background_metas/school_roof_blurred.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/school_dormrin.h"
#include "background_metas/rin_high_frown.h"
#include "background_metas/rin_high_oneeye.h"
#include "background_metas/rin_high_grin.h"
#include "background_metas/rin_high_grinwide.h"
#include "background_metas/rin_high_smile.h"
#include "background_metas/rin_kiss.h"
#include "background_metas/rin_high_open.h"
#include "background_metas/rin_high_sleep.h"
#include "background_metas/school_gardens.h"
#include "background_metas/school_hilltop_border.h"
#include "background_metas/school_hilltop_spring.h"
#include "background_metas/dandelion.h"
namespace ks {
    class ScriptA2Rin {
        public:
            virtual ~ScriptA2Rin() = default;
            // Labels
            SCENE_INLINE void a2_rin_a_wider_field_of_vision();
            SCENE_INLINE void a2_rin_studies_in_grayscale();
            SCENE_INLINE void a2_rin_interstitial();
            SCENE_INLINE void a2_rin_self_study();
            SCENE_INLINE void a2_rin_hisaos_smile();
            SCENE_INLINE void a2_rin_things_you_like();
            SCENE_INLINE void a2_rin_target_audience();
            SCENE_INLINE void a2_rin_eternity_in_an_hour();
            SCENE_INLINE void a2_rin_underwater_and_maple();
            SCENE_INLINE void a2_rin_iwanakos_regret();
            SCENE_INLINE void a2_rin_in_her_own_image();
            SCENE_INLINE void a2_rin_umbrella_logic_cake();
            SCENE_INLINE void a2_rin_six_meters_closer();
            SCENE_INLINE void a2_rin_indecision();
            SCENE_INLINE void a2_rin_signal_interference();
            SCENE_INLINE void a2_rin_dandelions();
            static void a2_rin();
            SCENE_INLINE void a2rc1o1();
            SCENE_INLINE void a2rc1o2();
            SCENE_INLINE void a2rc2o1();
            SCENE_INLINE void a2rc2o2();
            SCENE_INLINE void a2rc3o1();
            SCENE_INLINE void a2rc3o2();
            SCENE_INLINE void a2rc4o1();
            SCENE_INLINE void a2rc4o2();
            SCENE_INLINE void a2rc4o3();
            SCENE_INLINE void a2rc4o4();
            SCENE_INLINE void a2rc4o5();
            SCENE_INLINE void a2rc4o6();
            SCENE_INLINE void a2rc5o1();
            SCENE_INLINE void a2rc5o2();
            // Choice functions
            SCENE_INLINE void a2_rin_studies_in_grayscale__menu_question_0();
            SCENE_INLINE void a2_rin_studies_in_grayscale__menu_question_0_youre_amazing();
            SCENE_INLINE void a2_rin_studies_in_grayscale__menu_question_0_i_wish_i_was_as_good_as_you();
            SCENE_INLINE void a2_rin_things_you_like__menu_question_0();
            SCENE_INLINE void a2_rin_things_you_like__menu_question_0_its_refreshing();
            SCENE_INLINE void a2_rin_things_you_like__menu_question_0_it_makes_me_feel_like_im_stuck();
            SCENE_INLINE void a2_rin_underwater_and_maple__menu_question_0();
            SCENE_INLINE void a2_rin_underwater_and_maple__menu_question_0_i_want_to_be_more_like_rin();
            SCENE_INLINE void a2_rin_underwater_and_maple__menu_question_0_i_want_to_be_more_like_emi();
            SCENE_INLINE void a2_rin_in_her_own_image__menu_question_0();
            SCENE_INLINE void a2_rin_in_her_own_image__menu_question_0_i_think_youd_be_a_big_hit();
            SCENE_INLINE void a2_rin_in_her_own_image__menu_question_0_youd_be_wasting_your_talents_otherwise();
            SCENE_INLINE void a2_rin_in_her_own_image__menu_question_0_you_wont_get_a_chance_like_this_again();
            SCENE_INLINE void a2_rin_in_her_own_image__menu_question_0_because_it_would_be_exciting();
            SCENE_INLINE void a2_rin_in_her_own_image__menu_question_0_it_isnt_like_you_at_all_to_hesitate_like_this();
            SCENE_INLINE void a2_rin_in_her_own_image__menu_question_0_you_should_aim_high();
            SCENE_INLINE void a2_rin_dandelions__menu_question_0();
            SCENE_INLINE void a2_rin_dandelions__menu_question_0_what_about_me();
            SCENE_INLINE void a2_rin_dandelions__menu_question_0_what_about_emi();
            // Conditions
            SCENE_INLINE void a2_rin_a_wider_field_of_vision__condition_0_0();
            SCENE_INLINE void a2_rin_studies_in_grayscale__condition_0_0();
            SCENE_INLINE void a2_rin_interstitial__condition_0_0();
            SCENE_INLINE void a2_rin_self_study__condition_0_0();
            SCENE_INLINE void a2_rin_hisaos_smile__condition_0_0();
            SCENE_INLINE void a2_rin_things_you_like__condition_0_0();
            SCENE_INLINE void a2_rin_target_audience__condition_0_0();
            SCENE_INLINE void a2_rin_eternity_in_an_hour__condition_0_0();
            SCENE_INLINE void a2_rin_underwater_and_maple__condition_0_0();
            SCENE_INLINE void a2_rin_iwanakos_regret__condition_0_0();
            SCENE_INLINE void a2_rin_in_her_own_image__condition_0_0();
            SCENE_INLINE void a2_rin_in_her_own_image__condition_0_1();
            SCENE_INLINE void a2_rin_in_her_own_image__condition_0_2();
            SCENE_INLINE void a2_rin_in_her_own_image__condition_1_0();
            SCENE_INLINE void a2_rin_umbrella_logic_cake__condition_0_0();
            SCENE_INLINE void a2_rin_umbrella_logic_cake__condition_0_1();
            SCENE_INLINE void a2_rin_umbrella_logic_cake__condition_1_0();
            SCENE_INLINE void a2_rin_umbrella_logic_cake__condition_1_1();
            SCENE_INLINE void a2_rin_umbrella_logic_cake__condition_2_0();
            SCENE_INLINE void a2_rin_six_meters_closer__condition_0_0();
            SCENE_INLINE void a2_rin_indecision__condition_0_0();
            SCENE_INLINE void a2_rin_signal_interference__condition_0_0();
            SCENE_INLINE void a2_rin_dandelions__condition_0_0();
            SCENE_INLINE void a2_rin_dandelions__condition_1_0();
    };
}

#endif // KS_SCRIPT_A2_RIN