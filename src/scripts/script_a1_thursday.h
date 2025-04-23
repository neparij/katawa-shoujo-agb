#ifndef KS_SCRIPT_A1_THURSDAY
#define KS_SCRIPT_A1_THURSDAY

#include "../scenemanager.h"
#include "../character.h"
#include "bn_regular_bg_items_emi_bg_basic_gym.h"
#include "bn_regular_bg_items_emi_bg_sad_gym.h"
#include "bn_regular_bg_items_emi_bg_excited_gym.h"
#include "bn_regular_bg_items_kenji_bg_basic_naked.h"
#include "bn_regular_bg_items_lilly_bg_cane.h"
#include "bn_regular_bg_items_misha_bg_hips.h"
#include "bn_regular_bg_items_shizu_bg_behind.h"
#include "bn_regular_bg_items_shizu_bg_adjust.h"
#include "bn_regular_bg_items_misha_bg_cross.h"
#include "bn_regular_bg_items_shizu_bg_basic.h"
#include "bn_regular_bg_items_shizu_bg_cross.h"
#include "bn_regular_bg_items_misha_bg_perky.h"
#include "bn_regular_bg_items_misha_bg_sign.h"
#include "bn_regular_bg_items_hanako_bg_emb.h"
#include "bn_regular_bg_items_hanako_bg_def.h"
#include "bn_regular_bg_items_hanako_bg_basic.h"
#include "bn_regular_bg_items_hanako_bg_cover.h"
#include "bn_regular_bg_items_lilly_bg_basic3.h"
#include "bn_regular_bg_items_lilly_bg_basic.h"
#include "bn_regular_bg_items_lilly_bg_basic2.h"
#include "bn_regular_bg_items_kenji_bg_basic.h"
#include "bn_regular_bg_items_rin_bg_basic_close.h"
#include "bn_regular_bg_items_rin_bg_relaxed_close.h"
#include "bn_regular_bg_items_rin_bg_negative_close.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_track.h"
#include "background_metas/school_track_running.h"
#include "background_metas/school_track_on.h"
#include "background_metas/school_dormext_half.h"
#include "background_metas/school_dormbathroom.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/lilly_shizu_showdown_large.h"
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
#include "bn_sprite_items_emi_spr_basic_grin_gym.h"
#include "bn_sprite_items_emi_spr_basic_closedgrin_gym.h"
#include "bn_sprite_items_emi_spr_sad_shy_gym.h"
#include "bn_sprite_items_emi_spr_sad_grin_gym.h"
#include "bn_sprite_items_emi_spr_basic_happy_gym.h"
#include "bn_sprite_items_emi_spr_basic_confused_gym.h"
#include "bn_sprite_items_emi_spr_excited_laugh_gym.h"
#include "bn_sprite_items_emi_spr_basic_closedhappy_gym.h"
#include "bn_sprite_items_emi_spr_excited_proud_gym.h"
#include "bn_sprite_items_emi_spr_excited_joy_gym.h"
#include "bn_sprite_items_emi_spr_basic_annoyed_gym.h"
#include "bn_sprite_items_emi_spr_excited_amused_gym.h"
#include "bn_sprite_items_kenji_spr_basic_neutral_naked.h"
#include "bn_sprite_items_kenji_spr_basic_tsun_naked.h"
#include "bn_sprite_items_kenji_spr_basic_happy_naked.h"
#include "bn_sprite_items_lilly_spr_cane_concerned.h"
#include "bn_sprite_items_lilly_spr_cane_surprised.h"
#include "bn_sprite_items_lilly_spr_cane_listen.h"
#include "bn_sprite_items_lilly_spr_cane_weaksmile.h"
#include "bn_sprite_items_lilly_spr_cane_smile.h"
#include "bn_sprite_items_misha_spr_hips_grin.h"
#include "bn_sprite_items_shizu_spr_behind_blank.h"
#include "bn_sprite_items_misha_spr_hips_smile.h"
#include "bn_sprite_items_shizu_spr_behind_smile.h"
#include "bn_sprite_items_shizu_spr_adjust_smug.h"
#include "bn_sprite_items_misha_spr_cross_smile.h"
#include "bn_sprite_items_shizu_spr_basic_angry.h"
#include "bn_sprite_items_misha_spr_hips_frown.h"
#include "bn_sprite_items_shizu_spr_behind_frown.h"
#include "bn_sprite_items_misha_spr_cross_laugh.h"
#include "bn_sprite_items_shizu_spr_cross_angry.h"
#include "bn_sprite_items_misha_spr_cross_frown.h"
#include "bn_sprite_items_lilly_spr_cane_displeased.h"
#include "bn_sprite_items_shizu_spr_adjust_angry.h"
#include "bn_sprite_items_shizu_spr_behind_frustrated.h"
#include "bn_sprite_items_misha_spr_perky_confused.h"
#include "bn_sprite_items_misha_spr_sign_confused.h"
#include "bn_sprite_items_shizu_spr_basic_frown.h"
#include "bn_sprite_items_misha_spr_cross_grin.h"
#include "bn_sprite_items_misha_spr_perky_sad.h"
#include "bn_sprite_items_shizu_spr_basic_normal.h"
#include "bn_sprite_items_shizu_spr_basic_normal2.h"
#include "bn_sprite_items_misha_spr_perky_smile.h"
#include "bn_sprite_items_shizu_spr_adjust_blush.h"
#include "bn_sprite_items_hanako_spr_emb_timid.h"
#include "bn_sprite_items_hanako_spr_emb_blushtimid.h"
#include "bn_sprite_items_hanako_spr_emb_downsad.h"
#include "bn_sprite_items_hanako_spr_emb_downtimid.h"
#include "bn_sprite_items_misha_spr_hips_laugh.h"
#include "bn_sprite_items_misha_spr_sign_smile.h"
#include "bn_sprite_items_shizu_spr_basic_sparkle.h"
#include "bn_sprite_items_shizu_spr_adjust_happy.h"
#include "bn_sprite_items_shizu_spr_basic_happy.h"
#include "bn_sprite_items_hanako_spr_def_worry.h"
#include "bn_sprite_items_hanako_spr_basic_worry.h"
#include "bn_sprite_items_hanako_spr_cover_worry.h"
#include "bn_sprite_items_hanako_spr_basic_normal.h"
#include "bn_sprite_items_hanako_spr_emb_downsmile.h"
#include "bn_sprite_items_lilly_spr_basic3_surprised.h"
#include "bn_sprite_items_lilly_spr_basic_smile.h"
#include "bn_sprite_items_lilly_spr_basic_smileclosed.h"
#include "bn_sprite_items_lilly_spr_basic_weaksmile.h"
#include "bn_sprite_items_lilly_spr_basic3_listen.h"
#include "bn_sprite_items_lilly_spr_basic2_ara.h"
#include "bn_sprite_items_kenji_spr_basic_tsun.h"
#include "bn_sprite_items_hanako_spr_cover_distant.h"
#include "bn_sprite_items_kenji_spr_basic_happy.h"
#include "bn_sprite_items_kenji_spr_basic_neutral.h"
#include "bn_sprite_items_hanako_spr_basic_distant.h"
#include "bn_sprite_items_hanako_spr_basic_bashful.h"
#include "bn_sprite_items_hanako_spr_basic_smile.h"
#include "bn_sprite_items_lilly_spr_basic_displeased.h"
#include "bn_sprite_items_lilly_spr_basic_concerned.h"
#include "bn_sprite_items_hanako_spr_emb_smile.h"
#include "bn_sprite_items_lilly_spr_cane_smileclosed.h"
#include "bn_sprite_items_lilly_spr_cane_giggle.h"
#include "bn_sprite_items_hanako_spr_emb_emb.h"
#include "bn_sprite_items_rin_spr_basic_awayabsent_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpan_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpanupset_close.h"
#include "bn_sprite_items_rin_spr_relaxed_nonchalant_close.h"
#include "bn_sprite_items_rin_spr_basic_absent_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpannormal_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpancontemplation_close.h"
#include "bn_sprite_items_rin_spr_negative_spaciness_close.h"
#include "bn_sprite_items_rin_spr_negative_annoyed_close.h"
#include "bn_sprite_items_rin_spr_basic_lucid_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpandelight_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpanamused_close.h"
#include "bn_sprite_items_rin_spr_basic_delight_close.h"
#include "bn_sprite_items_rin_spr_basic_amused_close.h"
#include "bn_sprite_items_lilly_spr_cane_reminisce.h"
#include "bn_sprite_items_emi_spr_excited_circle_gym.h"
#include "emi_basic_gym.h"
#include "emi_sad_gym.h"
#include "emi_excited_gym.h"
#include "kenji_basic_naked.h"
#include "lilly_cane.h"
#include "misha_hips.h"
#include "shizu_behind.h"
#include "shizu_adjust.h"
#include "misha_cross.h"
#include "shizu_basic.h"
#include "shizu_cross.h"
#include "misha_perky.h"
#include "misha_sign.h"
#include "hanako_emb.h"
#include "hanako_def.h"
#include "hanako_basic.h"
#include "hanako_cover.h"
#include "lilly_basic3.h"
#include "lilly_basic.h"
#include "lilly_basic2.h"
#include "kenji_basic.h"
#include "rin_basic_close.h"
#include "rin_relaxed_close.h"
#include "rin_negative_close.h"
namespace ks {
    class ScriptA1Thursday {
        public:
            virtual ~ScriptA1Thursday() = default;
            // Labels
            static void a1_thursday_the_running_girl();
            static void a1_thursday_soap();
            static void a1_thursday_cold_war();
            static void a1_thursday_proof_of_competency();
            static void a1_thursday_event_horizon();
            static void a1_thursday_above_and_beyond();
            static void a1_thursday_paint_by_numbers();
            static void a1_thursday_things_you_can_do();
            static void a1_thursday();
            static void a1c8o1();
            static void a1c8o2();
            // Choice functions
            static void a1_thursday_cold_war__menu_question_0();
            static void a1_thursday_cold_war__menu_question_0_dont_drag_me_into_this_ive_done_my_part();
            static void a1_thursday_cold_war__menu_question_0_hey_come_on_cut_me_and_lilly_some_slack();
            // Conditions
            static void a1_thursday_the_running_girl__condition_0_0();
            static void a1_thursday_the_running_girl__condition_0_1();
            static void a1_thursday_the_running_girl__condition_1_0();
            static void a1_thursday_the_running_girl__condition_2_0();
            static void a1_thursday_the_running_girl__condition_2_1();
            static void a1_thursday_the_running_girl__condition_3_0();
            static void a1_thursday_the_running_girl__condition_3_1();
            static void a1_thursday_the_running_girl__condition_4_0();
            static void a1_thursday_soap__condition_0_0();
            static void a1_thursday_cold_war__condition_0__condition_0_0();
            static void a1_thursday_cold_war__condition_0__condition_0_1();
            static void a1_thursday_cold_war__condition_0_0();
            static void a1_thursday_cold_war__condition_1_0();
            static void a1_thursday_proof_of_competency__condition_0_0();
            static void a1_thursday_proof_of_competency__condition_1_0();
            static void a1_thursday__condition_0_0();
            static void a1_thursday_event_horizon__condition_0_0();
            static void a1_thursday__condition_1_0();
            static void a1_thursday_above_and_beyond__condition_0_0();
            static void a1_thursday__condition_2_0();
            static void a1_thursday_paint_by_numbers__condition_0_0();
            static void a1_thursday__condition_3_0();
            static void a1_thursday_things_you_can_do__condition_0_0();
            static void a1_thursday__condition_4_0();
            static void a1_thursday__condition_5_0();
            static void a1_thursday__condition_5_1();
    };
}

#endif // KS_SCRIPT_A1_THURSDAY