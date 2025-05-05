#ifndef KS_SCRIPT_A1_WEDNESDAY
#define KS_SCRIPT_A1_WEDNESDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "bn_regular_bg_items_shizu_bg_behind.h"
#include "bn_regular_bg_items_misha_bg_perky.h"
#include "bn_regular_bg_items_misha_bg_hips.h"
#include "bn_regular_bg_items_shizu_bg_adjust.h"
#include "bn_regular_bg_items_misha_bg_cross.h"
#include "bn_regular_bg_items_shizu_bg_basic.h"
#include "bn_regular_bg_items_hanako_bg_emb.h"
#include "bn_regular_bg_items_emi_bg_basic_gym.h"
#include "bn_regular_bg_items_shizu_bg_cross.h"
#include "bn_regular_bg_items_emi_bg_sad_gym.h"
#include "bn_regular_bg_items_lilly_bg_cane.h"
#include "bn_regular_bg_items_hanako_bg_defarms.h"
#include "bn_regular_bg_items_emi_bg_excited_gym.h"
#include "bn_regular_bg_items_hanako_bg_def.h"
#include "bn_regular_bg_items_yuukoshang_bg_down.h"
#include "bn_regular_bg_items_yuukoshang_bg_up.h"
#include "bn_regular_bg_items_misha_bg_sign.h"
#include "bn_regular_bg_items_lilly_bg_basic.h"
#include "bn_regular_bg_items_hanako_bg_basic.h"
#include "bn_regular_bg_items_muto_bg_basic.h"
#include "bn_regular_bg_items_rin_bg_relaxed.h"
#include "bn_regular_bg_items_rin_bg_basic.h"
#include "bn_regular_bg_items_rin_bg_negative.h"
#include "bn_regular_bg_items_nurse_bg.h"
#include "bn_regular_bg_items_rin_bg_basic_close.h"
#include "bn_regular_bg_items_rin_bg_negative_close.h"
#include "bn_regular_bg_items_hanako_bg_cover.h"
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
#include "bn_sprite_items_yuukoshang_spr_down_closedhappy.h"
#include "bn_sprite_items_yuukoshang_spr_down_smile.h"
#include "bn_sprite_items_yuukoshang_spr_down_neutral.h"
#include "bn_sprite_items_yuukoshang_spr_up_neurotic.h"
#include "bn_sprite_items_yuukoshang_spr_up_panic.h"
#include "bn_sprite_items_yuukoshang_spr_up_worried.h"
#include "bn_sprite_items_shizu_spr_behind_blank.h"
#include "bn_sprite_items_shizu_spr_behind_frown.h"
#include "bn_sprite_items_misha_spr_sign_confused.h"
#include "bn_sprite_items_shizu_spr_basic_happy.h"
#include "bn_sprite_items_misha_spr_sign_smile.h"
#include "bn_sprite_items_lilly_spr_basic_smile.h"
#include "bn_sprite_items_lilly_spr_basic_smileclosed.h"
#include "bn_sprite_items_lilly_spr_cane_smileclosed.h"
#include "bn_sprite_items_hanako_spr_basic_worry.h"
#include "bn_sprite_items_muto_spr_basic_irritated.h"
#include "bn_sprite_items_muto_spr_basic_normal.h"
#include "bn_sprite_items_muto_spr_basic_smile.h"
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
#include "bn_sprite_items_rin_spr_basic_deadpan_close.h"
#include "bn_sprite_items_rin_spr_negative_spaciness_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpanamused_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpandelight_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpanupset_close.h"
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
#include "emi_basic_gym.h"
#include "shizu_cross.h"
#include "emi_sad_gym.h"
#include "lilly_cane.h"
#include "hanako_defarms.h"
#include "emi_excited_gym.h"
#include "hanako_def.h"
#include "yuukoshang_down.h"
#include "yuukoshang_up.h"
#include "misha_sign.h"
#include "lilly_basic.h"
#include "hanako_basic.h"
#include "muto_basic.h"
#include "rin_relaxed.h"
#include "rin_basic.h"
#include "rin_negative.h"
#include "nurse.h"
#include "rin_basic_close.h"
#include "rin_negative_close.h"
#include "hanako_cover.h"
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