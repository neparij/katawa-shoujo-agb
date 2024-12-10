#ifndef KS_SCRIPT_A1_WEDNESDAY
#define KS_SCRIPT_A1_WEDNESDAY

#include "../sequence/assignmentitem.h"
#include "../sequence/backgrounditem.h"
#include "../sequence/dialogitem.h"
#include "../sequence/menuitem.h"
#include "../sequence/musicitem.h"
#include "../sequence/runlabelfinishitem.h"
#include "../sequence/runlabelitem.h"
#include "../sequence/spriteitem.h"
#include "../scenemanager.h"
#include "bn_regular_bg_items_school_scienceroom.h"
#include "bn_regular_bg_items_shizu_bg_behind.h"
#include "bn_regular_bg_items_misha_bg_perky.h"
#include "bn_regular_bg_items_misha_bg_hips.h"
#include "bn_regular_bg_items_shizu_bg_adjust.h"
#include "bn_regular_bg_items_misha_bg_cross.h"
#include "bn_regular_bg_items_shizu_bg_basic.h"
#include "bn_regular_bg_items_hanako_bg_emb.h"
#include "bn_regular_bg_items_school_hallway3.h"
#include "bn_regular_bg_items_emi_bg_basic.h"
#include "bn_regular_bg_items_shizu_bg_cross.h"
#include "bn_regular_bg_items_emi_bg_sad.h"
#include "bn_regular_bg_items_lilly_bg_cane.h"
#include "bn_regular_bg_items_hanako_bg_defarms.h"
#include "bn_regular_bg_items_emi_bg_excited.h"
#include "bn_regular_bg_items_hanako_bg_def.h"
#include "bn_regular_bg_items_suburb_roadcenter.h"
#include "bn_regular_bg_items_suburb_shanghaiext.h"
#include "bn_regular_bg_items_suburb_shanghaiint.h"
#include "bn_regular_bg_items_shizu_shanghai.h"
#include "bn_regular_bg_items_shizu_shanghai_borednormal.h"
#include "bn_regular_bg_items_shizu_shanghai_boredlaugh.h"
#include "bn_regular_bg_items_misha_bg_sign.h"
#include "bn_regular_bg_items_school_lobby.h"
#include "bn_regular_bg_items_school_miyagi.h"
#include "bn_regular_bg_items_lilly_bg_basic.h"
#include "bn_regular_bg_items_tearoom_everyone_noon.h"
#include "bn_regular_bg_items_hanako_bg_basic.h"
#include "bn_regular_bg_items_school_classroomart.h"
#include "bn_regular_bg_items_rin_eating.h"
#include "bn_regular_bg_items_rin_bg_relaxed.h"
#include "bn_regular_bg_items_rin_bg_basic.h"
#include "bn_regular_bg_items_rin_bg_negative.h"
#include "bn_regular_bg_items_school_staircase2.h"
#include "bn_regular_bg_items_nurse_bg.h"
#include "bn_regular_bg_items_school_courtyard.h"
#include "bn_regular_bg_items_school_dormext_start.h"
#include "bn_regular_bg_items_school_dormext_start_ss.h"
#include "bn_regular_bg_items_school_dormext_half_ni.h"
#include "bn_regular_bg_items_emi_knockeddown.h"
#include "bn_regular_bg_items_hanako_bg_cover.h"
#include "bn_sprite_items_shizu_spr_behind_smile.h"
#include "bn_sprite_items_misha_spr_perky_smile.h"
#include "bn_sprite_items_misha_spr_hips_grin.h"
#include "bn_sprite_items_shizu_spr_adjust_smug.h"
#include "bn_sprite_items_misha_spr_hips_smile.h"
#include "bn_sprite_items_shizu_spr_adjust_happy.h"
#include "bn_sprite_items_misha_spr_cross_laugh.h"
#include "bn_sprite_items_shizu_spr_basic_normal2.h"
#include "bn_sprite_items_hanako_spr_emb_downtimid.h"
#include "bn_sprite_items_misha_spr_perky_confused.h"
#include "bn_sprite_items_misha_spr_perky_sad.h"
#include "bn_sprite_items_shizu_spr_basic_frown.h"
#include "bn_sprite_items_shizu_spr_basic_normal.h"
#include "bn_sprite_items_hanako_spr_emb_timid.h"
#include "bn_sprite_items_emi_spr_basic_hes_gym.h"
#include "bn_sprite_items_misha_spr_hips_frown.h"
#include "bn_sprite_items_shizu_spr_cross_rage.h"
#include "bn_sprite_items_emi_spr_basic_closedsweat_gym.h"
#include "bn_sprite_items_shizu_spr_adjust_angry.h"
#include "bn_sprite_items_emi_spr_sad_depressed_gym.h"
#include "bn_sprite_items_shizu_spr_cross_angry.h"
#include "bn_sprite_items_misha_spr_cross_smile.h"
#include "bn_sprite_items_misha_spr_cross_grin.h"
#include "bn_sprite_items_emi_spr_sad_annoyed_gym.h"
#include "bn_sprite_items_lilly_spr_cane_smile.h"
#include "bn_sprite_items_hanako_spr_defarms_shock.h"
#include "bn_sprite_items_lilly_spr_cane_listen.h"
#include "bn_sprite_items_hanako_spr_defarms_worry.h"
#include "bn_sprite_items_emi_spr_excited_sad_gym.h"
#include "bn_sprite_items_lilly_spr_cane_weaksmile.h"
#include "bn_sprite_items_hanako_spr_def_worry.h"
#include "bn_sprite_items_emi_spr_basic_closedgrin_gym.h"
#include "bn_sprite_items_lilly_spr_cane_sad.h"
#include "bn_sprite_items_lilly_spr_cane_surprised.h"
#include "bn_sprite_items_lilly_spr_cane_concerned.h"
#include "bn_sprite_items_shizu_spr_behind_blank.h"
#include "bn_sprite_items_shizu_spr_behind_frown.h"
#include "bn_sprite_items_misha_spr_sign_confused.h"
#include "bn_sprite_items_shizu_spr_basic_happy.h"
#include "bn_sprite_items_misha_spr_sign_smile.h"
#include "bn_sprite_items_lilly_spr_basic_smile.h"
#include "bn_sprite_items_lilly_spr_basic_smileclosed.h"
#include "bn_sprite_items_lilly_spr_cane_smileclosed.h"
#include "bn_sprite_items_hanako_spr_basic_worry.h"
#include "bn_sprite_items_misha_spr_sign_sad.h"
#include "bn_sprite_items_rin_spr_relaxed_surprised.h"
#include "bn_sprite_items_rin_spr_basic_absent.h"
#include "bn_sprite_items_rin_spr_basic_deadpandelight.h"
#include "bn_sprite_items_rin_spr_relaxed_nonchalant.h"
#include "bn_sprite_items_rin_spr_basic_deadpan.h"
#include "bn_sprite_items_rin_spr_basic_awayabsent.h"
#include "bn_sprite_items_rin_spr_negative_spaciness.h"
#include "bn_sprite_items_rin_spr_basic_delight.h"
#include "bn_sprite_items_rin_spr_basic_lucid.h"
#include "bn_sprite_items_rin_spr_basic_deadpannormal.h"
#include "bn_sprite_items_misha_spr_cross_frown.h"
#include "bn_sprite_items_shizu_spr_basic_angry.h"
#include "bn_sprite_items_rin_spr_relaxed_sleepy.h"
#include "bn_sprite_items_rin_spr_negative_confused.h"
#include "bn_sprite_items_shizu_spr_behind_frustrated.h"
#include "bn_sprite_items_rin_spr_relaxed_boredom.h"
#include "bn_sprite_items_rin_spr_basic_deadpanupset.h"
#include "bn_sprite_items_nurse_spr_grin.h"
#include "bn_sprite_items_nurse_spr_concern.h"
#include "bn_sprite_items_nurse_spr_neutral.h"
#include "bn_sprite_items_nurse_spr_fabulous.h"
#include "bn_sprite_items_rin_spr_basic_deadpanamused.h"
#include "bn_sprite_items_rin_spr_basic_deadpansurprised.h"
#include "bn_sprite_items_rin_spr_basic_amused.h"
#include "bn_sprite_items_emi_spr_basic_shock_gym.h"
#include "bn_sprite_items_emi_spr_basic_happy_gym.h"
#include "bn_sprite_items_hanako_spr_def_shock.h"
#include "bn_sprite_items_hanako_spr_basic_bashful.h"
#include "bn_sprite_items_hanako_spr_cover_bashful.h"
#include "bn_sprite_items_hanako_spr_basic_normal.h"
#include "bn_sprite_items_hanako_spr_basic_distant.h"
#include "bn_sprite_items_hanako_spr_emb_smile.h"
#include "bn_sprite_items_hanako_spr_emb_sad.h"
#include "bn_sprite_items_hanako_spr_emb_downsad.h"
#include "bn_sprite_items_lilly_spr_cane_cheerful.h"
#include "bn_sprite_items_misha_spr_hips_laugh.h"
#include "shizu_behind.h"
#include "misha_perky.h"
#include "misha_hips.h"
#include "shizu_adjust.h"
#include "misha_cross.h"
#include "shizu_basic.h"
#include "hanako_emb.h"
#include "emi_basic.h"
#include "shizu_cross.h"
#include "emi_sad.h"
#include "lilly_cane.h"
#include "hanako_defarms.h"
#include "emi_excited.h"
#include "hanako_def.h"
#include "misha_sign.h"
#include "lilly_basic.h"
#include "hanako_basic.h"
#include "rin_relaxed.h"
#include "rin_basic.h"
#include "rin_negative.h"
#include "nurse.h"
#include "hanako_cover.h"
namespace ks {
    class ScriptA1Wednesday {
        public:
            virtual ~ScriptA1Wednesday() = default;
            // Labels
            static void a1_wednesday_lunch_evolution_theory();
            static void a1_wednesday_short_sharp_shock();
            static void a1_wednesday_meet_cute();
            static void a1_wednesday_detour_ahead();
            static void a1_wednesday_sip_p1();
            static void a1_wednesday_it_builds_character();
            static void a1_wednesday_a_private_lunch();
            static void a1_wednesday_waylay();
            static void a1_wednesday_the_other_green();
            static void a1_wednesday();
            static void separate_of_sss_and_mc();
            static void a1c6o1();
            static void a1c6o2();
            static void a1c6o3();
            static void a1c7o1();
            static void a1c7o2();
            // Choice functions
            static void a1_wednesday_lunch_evolution_theory__menu_question_0();
            static void a1_wednesday_lunch_evolution_theory__menu_question_0_read_my_book();
            static void a1_wednesday_lunch_evolution_theory__menu_question_0_go_talk_with_hanako();
            static void a1_wednesday_lunch_evolution_theory__menu_question_0_wait_for_shizune_and_misha_to_come_to_a_decision();
            static void a1_wednesday_waylay__menu_question_0();
            static void a1_wednesday_waylay__menu_question_0_yes();
            static void a1_wednesday_waylay__menu_question_0_maybe();
            // Conditions
            static void a1_wednesday_short_sharp_shock__condition_0_0();
            static void a1_wednesday_short_sharp_shock__condition_0_1();
            static void a1_wednesday_short_sharp_shock__condition_1_0();
            static void a1_wednesday_meet_cute__condition_0_0();
            static void a1_wednesday__condition_0_0();
            static void a1_wednesday__condition_0_1();
            static void a1_wednesday_detour_ahead__condition_0_0();
            static void a1_wednesday_sip_p1__condition_0_0();
            static void a1_wednesday__condition_1_0();
            static void a1_wednesday__condition_1_1();
            static void a1_wednesday_it_builds_character__condition_0_0();
            static void a1_wednesday__condition_2_0();
            static void a1_wednesday_a_private_lunch__condition_0_0();
            static void a1_wednesday_waylay__condition_0_0();
            static void a1_wednesday_the_other_green__condition_0_0();
    };
}

#endif // KS_SCRIPT_A1_WEDNESDAY