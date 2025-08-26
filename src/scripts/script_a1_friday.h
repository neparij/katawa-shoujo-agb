#ifndef KS_SCRIPT_A1_FRIDAY
#define KS_SCRIPT_A1_FRIDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "bn_regular_bg_items_emi_bg_basic_gym.h"
#include "bn_regular_bg_items_emi_bg_excited_gym.h"
#include "bn_regular_bg_items_kenji_bg_basic.h"
#include "bn_regular_bg_items_misha_bg_perky.h"
#include "bn_regular_bg_items_shizu_bg_basic.h"
#include "bn_regular_bg_items_misha_bg_hips.h"
#include "bn_regular_bg_items_shizu_bg_behind.h"
#include "bn_regular_bg_items_misha_bg_sign.h"
#include "bn_regular_bg_items_shizu_bg_adjust.h"
#include "bn_regular_bg_items_shizu_bg_cross.h"
#include "bn_regular_bg_items_misha_bg_cross.h"
#include "bn_regular_bg_items_emi_bg_basic.h"
#include "bn_regular_bg_items_rin_bg_relaxed_silhouette.h"
#include "bn_regular_bg_items_rin_bg_relaxed.h"
#include "bn_regular_bg_items_rin_bg_basic.h"
#include "bn_regular_bg_items_rin_bg_basic_close.h"
#include "bn_regular_bg_items_emi_bg_excited.h"
#include "bn_regular_bg_items_rin_bg_relaxed_close.h"
#include "bn_regular_bg_items_emi_bg_sad.h"
#include "bn_regular_bg_items_yuuko_bg_up.h"
#include "bn_regular_bg_items_lilly_bg_back.h"
#include "bn_regular_bg_items_lilly_bg_cane.h"
#include "bn_regular_bg_items_lilly_bg_basic.h"
#include "bn_regular_bg_items_rin_bg_negative.h"
#include "bn_regular_bg_items_muto_bg_basic.h"
#include "bn_regular_bg_items_emi_bg_sad_gym.h"
#include "bn_regular_bg_items_nurse_bg.h"
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
#include "bn_sprite_items_emi_spr_basic_grin_gym.h"
#include "bn_sprite_items_emi_spr_basic_closedgrin_gym.h"
#include "bn_sprite_items_emi_spr_basic_annoyed_gym.h"
#include "bn_sprite_items_emi_spr_basic_happy_gym.h"
#include "bn_sprite_items_emi_spr_excited_proud_gym.h"
#include "bn_sprite_items_emi_spr_basic_closedhappy_gym.h"
#include "bn_sprite_items_kenji_spr_basic_neutral.h"
#include "bn_sprite_items_kenji_spr_basic_tsun.h"
#include "bn_sprite_items_kenji_spr_basic_happy.h"
#include "bn_sprite_items_misha_spr_perky_smile.h"
#include "bn_sprite_items_shizu_spr_basic_normal2.h"
#include "bn_sprite_items_misha_spr_hips_smile.h"
#include "bn_sprite_items_shizu_spr_behind_smile.h"
#include "bn_sprite_items_misha_spr_hips_grin.h"
#include "bn_sprite_items_shizu_spr_basic_normal.h"
#include "bn_sprite_items_misha_spr_hips_frown.h"
#include "bn_sprite_items_misha_spr_sign_smile.h"
#include "bn_sprite_items_shizu_spr_adjust_happy.h"
#include "bn_sprite_items_misha_spr_perky_confused.h"
#include "bn_sprite_items_misha_spr_perky_sad.h"
#include "bn_sprite_items_shizu_spr_cross_wut.h"
#include "bn_sprite_items_shizu_spr_behind_frustrated.h"
#include "bn_sprite_items_misha_spr_cross_laugh.h"
#include "bn_sprite_items_shizu_spr_basic_angry.h"
#include "bn_sprite_items_shizu_spr_behind_frown.h"
#include "bn_sprite_items_shizu_spr_basic_frown.h"
#include "bn_sprite_items_shizu_spr_behind_blank.h"
#include "bn_sprite_items_shizu_spr_adjust_smug.h"
#include "bn_sprite_items_shizu_spr_adjust_blush.h"
#include "bn_sprite_items_emi_spr_basic_closedgrin.h"
#include "bn_sprite_items_rin_spr_relaxed_surprised_silhouette.h"
#include "bn_sprite_items_emi_spr_basic_shock.h"
#include "bn_sprite_items_emi_spr_basic_hes.h"
#include "bn_sprite_items_rin_spr_relaxed_surprised.h"
#include "bn_sprite_items_emi_spr_basic_confused.h"
#include "bn_sprite_items_rin_spr_relaxed_nonchalant.h"
#include "bn_sprite_items_rin_spr_basic_deadpan.h"
#include "bn_sprite_items_emi_spr_basic_grin.h"
#include "bn_sprite_items_rin_spr_basic_deadpanamused.h"
#include "bn_sprite_items_rin_spr_basic_deadpannormal.h"
#include "bn_sprite_items_emi_spr_basic_happy.h"
#include "bn_sprite_items_rin_spr_basic_deadpannormal_close.h"
#include "bn_sprite_items_emi_spr_basic_closedhappy.h"
#include "bn_sprite_items_emi_spr_excited_proud.h"
#include "bn_sprite_items_emi_spr_excited_amused.h"
#include "bn_sprite_items_rin_spr_basic_awayabsent_close.h"
#include "bn_sprite_items_rin_spr_basic_absent_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpan_close.h"
#include "bn_sprite_items_emi_spr_basic_annoyed.h"
#include "bn_sprite_items_rin_spr_basic_deadpandelight_close.h"
#include "bn_sprite_items_rin_spr_relaxed_surprised_close.h"
#include "bn_sprite_items_rin_spr_basic_surprised_close.h"
#include "bn_sprite_items_rin_spr_basic_lucid_close.h"
#include "bn_sprite_items_emi_spr_excited_laugh.h"
#include "bn_sprite_items_emi_spr_sad_depressed.h"
#include "bn_sprite_items_rin_spr_relaxed_boredom_close.h"
#include "bn_sprite_items_yuuko_spr_up_panic.h"
#include "bn_sprite_items_yuuko_spr_up_worried.h"
#include "bn_sprite_items_yuuko_spr_up_neurotic.h"
#include "bn_sprite_items_lilly_spr_back_smileclosed.h"
#include "bn_sprite_items_lilly_spr_cane_surprised.h"
#include "bn_sprite_items_lilly_spr_cane_weaksmile.h"
#include "bn_sprite_items_lilly_spr_cane_smile.h"
#include "bn_sprite_items_lilly_spr_cane_ara.h"
#include "bn_sprite_items_lilly_spr_cane_smileclosed.h"
#include "bn_sprite_items_lilly_spr_cane_giggle.h"
#include "bn_sprite_items_lilly_spr_cane_reminisce.h"
#include "bn_sprite_items_lilly_spr_cane_planned.h"
#include "bn_sprite_items_lilly_spr_basic_smileclosed.h"
#include "bn_sprite_items_lilly_spr_basic_concerned.h"
#include "bn_sprite_items_lilly_spr_basic_smile.h"
#include "bn_sprite_items_lilly_spr_cane_listen.h"
#include "bn_sprite_items_lilly_spr_cane_sleepy.h"
#include "bn_sprite_items_rin_spr_basic_awayabsent.h"
#include "bn_sprite_items_rin_spr_basic_lucid.h"
#include "bn_sprite_items_rin_spr_basic_absent.h"
#include "bn_sprite_items_rin_spr_negative_spaciness.h"
#include "bn_sprite_items_lilly_spr_cane_concerned.h"
#include "bn_sprite_items_rin_spr_negative_annoyed.h"
#include "bn_sprite_items_rin_spr_basic_deadpanupset.h"
#include "bn_sprite_items_rin_spr_relaxed_disgust.h"
#include "bn_sprite_items_lilly_spr_cane_displeased.h"
#include "bn_sprite_items_muto_spr_basic_normal.h"
#include "bn_sprite_items_muto_spr_basic_smile.h"
#include "bn_sprite_items_muto_spr_basic_irritated.h"
#include "bn_sprite_items_emi_spr_excited_laugh_gym.h"
#include "bn_sprite_items_emi_spr_basic_shock_gym.h"
#include "bn_sprite_items_emi_spr_basic_hes_gym.h"
#include "bn_sprite_items_emi_spr_sad_annoyed_gym.h"
#include "bn_sprite_items_nurse_spr_grin.h"
#include "bn_sprite_items_nurse_spr_fabulous.h"
#include "bn_sprite_items_emi_spr_excited_sad_gym.h"
#include "bn_sprite_items_nurse_spr_concern.h"
#include "bn_sprite_items_nurse_spr_neutral.h"
#include "bn_sprite_items_emi_spr_basic_closedsweat_gym.h"
#include "bn_sprite_items_emi_spr_sad_depressed_gym.h"
#include "bn_sprite_items_emi_spr_sad_shy_gym.h"
#include "bn_sprite_items_emi_spr_excited_joy_gym.h"
#include "bn_sprite_items_misha_spr_sign_confused.h"
#include "bn_sprite_items_shizu_spr_behind_sad.h"
#include "bn_sprite_items_misha_spr_sign_sad.h"
#include "bn_sprite_items_lilly_spr_cane_oops.h"
#include "bn_sprite_items_lilly_spr_cane_sad.h"
#include "bn_sprite_items_rin_spr_basic_upset.h"
#include "bn_sprite_items_rin_spr_negative_confused.h"
#include "bn_sprite_items_rin_spr_negative_worried.h"
#include "bn_sprite_items_rin_spr_negative_angry.h"
#include "bn_sprite_items_lilly_spr_cane_cheerful.h"
#include "bn_sprite_items_emi_spr_sad_grin.h"
#include "emi_basic_gym.h"
#include "emi_excited_gym.h"
#include "kenji_basic.h"
#include "misha_perky.h"
#include "shizu_basic.h"
#include "misha_hips.h"
#include "shizu_behind.h"
#include "misha_sign.h"
#include "shizu_adjust.h"
#include "shizu_cross.h"
#include "misha_cross.h"
#include "emi_basic.h"
#include "rin_relaxed_silhouette.h"
#include "rin_relaxed.h"
#include "rin_basic.h"
#include "rin_basic_close.h"
#include "emi_excited.h"
#include "rin_relaxed_close.h"
#include "emi_sad.h"
#include "yuuko_up.h"
#include "lilly_back.h"
#include "lilly_cane.h"
#include "lilly_basic.h"
#include "rin_negative.h"
#include "muto_basic.h"
#include "emi_sad_gym.h"
#include "nurse.h"
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
            SCENE_INLINE void choice_go_for_it();
            SCENE_INLINE void choice_take_it_easy();
            SCENE_INLINE void choice_dodge_subject();
            SCENE_INLINE void choice_kick_shizu();
            SCENE_INLINE void choice_fun_at_office();
            SCENE_INLINE void choice_dont_want_talk();
            SCENE_INLINE void choice_emi_lunch();
            SCENE_INLINE void choice_shizune_lunch();
            SCENE_INLINE void choice_not_good_condition();
            SCENE_INLINE void choice_not_much_talking();
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
            SCENE_INLINE void choice_dont_want_talk__menu_question_0();
            SCENE_INLINE void choice_dont_want_talk__menu_question_0_ill_go_to_the_lunch_with_emi_and_her_friend();
            SCENE_INLINE void choice_dont_want_talk__menu_question_0_ill_go_with_shizune_after_all_im_in_the_student_council_now();
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
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_0__condition_0_0();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_0_0();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_0_1();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_1_0();
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_2_0();
            SCENE_INLINE void a1_friday_mind_your_step__condition_0_0();
            SCENE_INLINE void a1_friday__condition_4__condition_0_0();
            SCENE_INLINE void a1_friday__condition_4_0();
            SCENE_INLINE void a1_friday__condition_4_1();
            SCENE_INLINE void choice_not_good_condition__condition_0_0();
    };
}

#endif // KS_SCRIPT_A1_FRIDAY