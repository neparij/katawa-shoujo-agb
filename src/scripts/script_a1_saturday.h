#ifndef KS_SCRIPT_A1_SATURDAY
#define KS_SCRIPT_A1_SATURDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "bn_regular_bg_items_muto_bg_basic.h"
#include "bn_regular_bg_items_hanako_bg_emb.h"
#include "bn_regular_bg_items_lilly_bg_basic.h"
#include "bn_regular_bg_items_emi_bg_basic.h"
#include "bn_regular_bg_items_emi_bg_excited.h"
#include "bn_regular_bg_items_emi_bg_sad.h"
#include "bn_regular_bg_items_rin_bg_negative.h"
#include "bn_regular_bg_items_rin_bg_basic.h"
#include "bn_regular_bg_items_rin_bg_basic_close.h"
#include "bn_regular_bg_items_shizu_bg_behind.h"
#include "bn_regular_bg_items_misha_bg_hips.h"
#include "bn_regular_bg_items_shizu_bg_basic.h"
#include "bn_regular_bg_items_shizu_bg_adjust.h"
#include "bn_regular_bg_items_misha_bg_sign.h"
#include "bn_regular_bg_items_misha_bg_perky.h"
#include "bn_regular_bg_items_misha_bg_cross.h"
#include "bn_regular_bg_items_yuukoshang_bg_down.h"
#include "bn_regular_bg_items_shizu_bg_cross.h"
#include "bn_regular_bg_items_hanako_bg_basic.h"
#include "bn_regular_bg_items_hanako_bg_cover.h"
#include "bn_regular_bg_items_hanako_bg_def.h"
#include "bn_regular_bg_items_hanako_bg_defarms.h"
#include "bn_regular_bg_items_rin_bg_negative_close.h"
#include "bn_regular_bg_items_yuukoshang_bg_up.h"
#include "bn_regular_bg_items_lilly_bg_basic3.h"
#include "bn_regular_bg_items_lilly_bg_basic2.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_dormext_half.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_classroomart.h"
#include "background_metas/mural.h"
#include "background_metas/school_dormext_half_ss.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/misc_sky.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/shizu_shanghai.h"
#include "background_metas/shizu_shanghai_normallaugh.h"
#include "background_metas/shizu_shanghai_smirklaugh.h"
#include "background_metas/shizu_shanghai_smirknormal.h"
#include "background_metas/shizu_shanghai_borednormal.h"
#include "background_metas/shizu_shanghai_boredlaugh.h"
#include "background_metas/suburb_shanghaiext.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/school_council.h"
#include "background_metas/school_council_ss.h"
#include "background_metas/school_council_ni.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/school_library.h"
#include "background_metas/hana_library_read.h"
#include "background_metas/hana_library.h"
#include "background_metas/school_library_ss.h"
#include "background_metas/school_dormext_full_ni.h"
#include "background_metas/school_gate.h"
#include "background_metas/suburb_park.h"
#include "background_metas/school_gate_ni.h"
#include "background_metas/school_courtyard_ni.h"
#include "bn_sprite_items_muto_spr_basic_irritated.h"
#include "bn_sprite_items_muto_spr_basic_normal.h"
#include "bn_sprite_items_muto_spr_basic_smile.h"
#include "bn_sprite_items_hanako_spr_emb_downtimid.h"
#include "bn_sprite_items_lilly_spr_basic_smileclosed.h"
#include "bn_sprite_items_hanako_spr_emb_downsmile.h"
#include "bn_sprite_items_hanako_spr_emb_downsad.h"
#include "bn_sprite_items_emi_spr_basic_closedgrin.h"
#include "bn_sprite_items_emi_spr_excited_happy.h"
#include "bn_sprite_items_emi_spr_excited_laugh.h"
#include "bn_sprite_items_emi_spr_excited_proud.h"
#include "bn_sprite_items_emi_spr_basic_grin.h"
#include "bn_sprite_items_emi_spr_basic_annoyed.h"
#include "bn_sprite_items_emi_spr_basic_closedsweat.h"
#include "bn_sprite_items_emi_spr_sad_angry.h"
#include "bn_sprite_items_emi_spr_basic_closedhappy.h"
#include "bn_sprite_items_emi_spr_basic_happy.h"
#include "bn_sprite_items_rin_spr_negative_spaciness.h"
#include "bn_sprite_items_rin_spr_basic_awayabsent.h"
#include "bn_sprite_items_rin_spr_basic_absent.h"
#include "bn_sprite_items_rin_spr_basic_deadpannormal.h"
#include "bn_sprite_items_rin_spr_basic_deadpan.h"
#include "bn_sprite_items_rin_spr_basic_deadpandelight.h"
#include "bn_sprite_items_rin_spr_basic_lucid.h"
#include "bn_sprite_items_emi_spr_basic_confused.h"
#include "bn_sprite_items_rin_spr_basic_awayabsent_close.h"
#include "bn_sprite_items_rin_spr_basic_absent_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpan_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpancontemplation_close.h"
#include "bn_sprite_items_emi_spr_excited_amused.h"
#include "bn_sprite_items_emi_spr_sad_shy.h"
#include "bn_sprite_items_emi_spr_sad_grin.h"
#include "bn_sprite_items_emi_spr_sad_depressed.h"
#include "bn_sprite_items_emi_spr_basic_shock.h"
#include "bn_sprite_items_shizu_spr_behind_blank.h"
#include "bn_sprite_items_misha_spr_hips_smile.h"
#include "bn_sprite_items_misha_spr_hips_grin.h"
#include "bn_sprite_items_shizu_spr_basic_normal2.h"
#include "bn_sprite_items_shizu_spr_adjust_happy.h"
#include "bn_sprite_items_misha_spr_sign_smile.h"
#include "bn_sprite_items_misha_spr_perky_smile.h"
#include "bn_sprite_items_shizu_spr_behind_smile.h"
#include "bn_sprite_items_shizu_spr_adjust_smug.h"
#include "bn_sprite_items_shizu_spr_basic_angry.h"
#include "bn_sprite_items_misha_spr_perky_confused.h"
#include "bn_sprite_items_misha_spr_hips_frown.h"
#include "bn_sprite_items_shizu_spr_behind_frown.h"
#include "bn_sprite_items_misha_spr_hips_laugh.h"
#include "bn_sprite_items_shizu_spr_basic_normal.h"
#include "bn_sprite_items_shizu_spr_behind_frustrated.h"
#include "bn_sprite_items_misha_spr_cross_laugh.h"
#include "bn_sprite_items_misha_spr_cross_grin.h"
#include "bn_sprite_items_yuukoshang_spr_down_neutral.h"
#include "bn_sprite_items_misha_spr_cross_smile.h"
#include "bn_sprite_items_shizu_spr_basic_happy.h"
#include "bn_sprite_items_shizu_spr_basic_sparkle.h"
#include "bn_sprite_items_shizu_spr_cross_angry.h"
#include "bn_sprite_items_shizu_spr_adjust_angry.h"
#include "bn_sprite_items_shizu_spr_cross_rage.h"
#include "bn_sprite_items_shizu_spr_cross_wut.h"
#include "bn_sprite_items_misha_spr_perky_sad.h"
#include "bn_sprite_items_misha_spr_sign_confused.h"
#include "bn_sprite_items_shizu_spr_adjust_blush.h"
#include "bn_sprite_items_hanako_spr_basic_worry.h"
#include "bn_sprite_items_hanako_spr_basic_normal.h"
#include "bn_sprite_items_hanako_spr_cover_distant.h"
#include "bn_sprite_items_hanako_spr_cover_worry.h"
#include "bn_sprite_items_hanako_spr_cover_smile.h"
#include "bn_sprite_items_hanako_spr_def_shock.h"
#include "bn_sprite_items_hanako_spr_def_worry.h"
#include "bn_sprite_items_hanako_spr_basic_distant.h"
#include "bn_sprite_items_hanako_spr_emb_emb.h"
#include "bn_sprite_items_hanako_spr_basic_bashful.h"
#include "bn_sprite_items_hanako_spr_basic_smile.h"
#include "bn_sprite_items_hanako_spr_defarms_worry.h"
#include "bn_sprite_items_hanako_spr_emb_smile.h"
#include "bn_sprite_items_rin_spr_basic_delight.h"
#include "bn_sprite_items_rin_spr_negative_worried.h"
#include "bn_sprite_items_rin_spr_negative_spaciness_close.h"
#include "bn_sprite_items_rin_spr_negative_annoyed_close.h"
#include "bn_sprite_items_rin_spr_basic_deadpanupset_close.h"
#include "bn_sprite_items_yuukoshang_spr_up_neurotic.h"
#include "bn_sprite_items_yuukoshang_spr_down_closedhappy.h"
#include "bn_sprite_items_lilly_spr_basic_smile.h"
#include "bn_sprite_items_lilly_spr_basic_weaksmile.h"
#include "bn_sprite_items_lilly_spr_basic_displeased.h"
#include "bn_sprite_items_lilly_spr_basic3_listen.h"
#include "bn_sprite_items_lilly_spr_basic3_oops.h"
#include "bn_sprite_items_lilly_spr_basic_concerned.h"
#include "bn_sprite_items_lilly_spr_basic_reminisce.h"
#include "bn_sprite_items_lilly_spr_basic3_surprised.h"
#include "bn_sprite_items_lilly_spr_basic2_giggle.h"
#include "bn_sprite_items_lilly_spr_basic_cheerful.h"
#include "bn_sprite_items_emi_spr_basic_hes.h"
#include "muto_basic.h"
#include "hanako_emb.h"
#include "lilly_basic.h"
#include "emi_basic.h"
#include "emi_excited.h"
#include "emi_sad.h"
#include "rin_negative.h"
#include "rin_basic.h"
#include "rin_basic_close.h"
#include "shizu_behind.h"
#include "misha_hips.h"
#include "shizu_basic.h"
#include "shizu_adjust.h"
#include "misha_sign.h"
#include "misha_perky.h"
#include "misha_cross.h"
#include "yuukoshang_down.h"
#include "shizu_cross.h"
#include "hanako_basic.h"
#include "hanako_cover.h"
#include "hanako_def.h"
#include "hanako_defarms.h"
#include "rin_negative_close.h"
#include "yuukoshang_up.h"
#include "lilly_basic3.h"
#include "lilly_basic2.h"
namespace ks {
    class ScriptA1Saturday {
        public:
            virtual ~ScriptA1Saturday() = default;
            // Labels
            SCENE_INLINE void a1_saturday_support();
            SCENE_INLINE void a1_saturday_an_asethetics();
            SCENE_INLINE void a1_saturday_creative_pain();
            SCENE_INLINE void a1_saturday_proper_exercise();
            SCENE_INLINE void a1_saturday_sip_p2();
            SCENE_INLINE void a1_saturday_shanghaied();
            SCENE_INLINE void a1_saturday_quiet();
            static void a1_saturday();
            SCENE_INLINE void a1c14o1();
            SCENE_INLINE void a1c14o2();
            // Choice functions
            SCENE_INLINE void a1_saturday_creative_pain__menu_question_0();
            SCENE_INLINE void a1_saturday_creative_pain__menu_question_0_i_just_kinda_stuck_with_her_i_think();
            SCENE_INLINE void a1_saturday_creative_pain__menu_question_0_im_interested_in_the_art_club();
            SCENE_INLINE void a1_saturday_sip_p2__menu_question_0();
            SCENE_INLINE void a1_saturday_sip_p2__menu_question_0_go_for_a_walk_into_town();
            SCENE_INLINE void a1_saturday_sip_p2__menu_question_0_go_to_the_library();
            // Conditions
            SCENE_INLINE void a1_saturday__condition_0__condition_0__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_0__condition_0__condition_0_1();
            SCENE_INLINE void a1_saturday__condition_0__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_0__condition_0_1();
            SCENE_INLINE void a1_saturday__condition_0__condition_0_2();
            SCENE_INLINE void a1_saturday__condition_0__condition_0_3();
            SCENE_INLINE void a1_saturday__condition_0_0();
            SCENE_INLINE void a1_saturday_support__condition_0_0();
            SCENE_INLINE void a1_saturday_support__condition_0_1();
            SCENE_INLINE void a1_saturday_support__condition_1_0();
            SCENE_INLINE void a1_saturday_support__condition_2_0();
            SCENE_INLINE void a1_saturday__condition_1_0();
            SCENE_INLINE void a1_saturday__condition_2_0();
            SCENE_INLINE void a1_saturday_an_asethetics__condition_0_0();
            SCENE_INLINE void a1_saturday_an_asethetics__condition_1_0();
            SCENE_INLINE void a1_saturday__condition_3_0();
            SCENE_INLINE void a1_saturday_creative_pain__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_4_0();
            SCENE_INLINE void a1_saturday_proper_exercise__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_5_0();
            SCENE_INLINE void a1_saturday_sip_p2__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_6_0();
            SCENE_INLINE void a1_saturday_shanghaied__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_7_0();
            SCENE_INLINE void a1_saturday_quiet__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_8_0();
    };
}

#endif // KS_SCRIPT_A1_SATURDAY