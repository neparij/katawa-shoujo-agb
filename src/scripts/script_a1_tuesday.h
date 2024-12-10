#ifndef KS_SCRIPT_A1_TUESDAY
#define KS_SCRIPT_A1_TUESDAY

#include "../sequence/assignmentitem.h"
#include "../sequence/backgrounditem.h"
#include "../sequence/dialogitem.h"
#include "../sequence/menuitem.h"
#include "../sequence/musicitem.h"
#include "../sequence/runlabelfinishitem.h"
#include "../sequence/runlabelitem.h"
#include "../sequence/spriteitem.h"
#include "../scenemanager.h"
#include "bn_regular_bg_items_school_dormhisao.h"
#include "bn_regular_bg_items_school_scienceroom.h"
#include "bn_regular_bg_items_shizu_bg_behind.h"
#include "bn_regular_bg_items_shizu_bg_basic.h"
#include "bn_regular_bg_items_shizu_bg_cross.h"
#include "bn_regular_bg_items_misha_bg_hips.h"
#include "bn_regular_bg_items_misha_bg_perky.h"
#include "bn_regular_bg_items_misha_bg_sign.h"
#include "bn_regular_bg_items_shizu_bg_adjust.h"
#include "bn_regular_bg_items_misha_bg_cross.h"
#include "bn_regular_bg_items_school_hallway3.h"
#include "bn_regular_bg_items_school_cafeteria.h"
#include "bn_regular_bg_items_hanako_bg_def.h"
#include "bn_regular_bg_items_school_lobby.h"
#include "bn_regular_bg_items_school_council.h"
#include "bn_regular_bg_items_school_staircase2.h"
#include "bn_regular_bg_items_school_hallway2.h"
#include "bn_regular_bg_items_lilly_tearoom.h"
#include "bn_regular_bg_items_lilly_tearoom_open.h"
#include "bn_regular_bg_items_school_miyagi.h"
#include "bn_regular_bg_items_lilly_bg_basic.h"
#include "bn_regular_bg_items_lilly_bg_basic2.h"
#include "bn_regular_bg_items_tearoom_lillyhisao_noon.h"
#include "bn_regular_bg_items_tearoom_lillyhisao_sunset.h"
#include "bn_regular_bg_items_school_miyagi_ss.h"
#include "bn_regular_bg_items_lilly_bg_cane.h"
#include "bn_regular_bg_items_school_library_ss.h"
#include "bn_regular_bg_items_yuuko_bg_down.h"
#include "bn_regular_bg_items_yuuko_bg_up.h"
#include "bn_regular_bg_items_hana_library_read.h"
#include "bn_regular_bg_items_hana_library_gasp.h"
#include "bn_regular_bg_items_hanako_bg_defarms.h"
#include "bn_regular_bg_items_school_dormhallway.h"
#include "bn_regular_bg_items_kenji_bg_basic.h"
#include "bn_regular_bg_items_kenji_bg_rage.h"
#include "bn_regular_bg_items_school_dormhisao_ss.h"
#include "bn_regular_bg_items_hana_library.h"
#include "bn_regular_bg_items_hanako_bg_emb.h"
#include "bn_sprite_items_shizu_spr_behind_blank.h"
#include "bn_sprite_items_shizu_spr_basic_normal.h"
#include "bn_sprite_items_shizu_spr_cross_wut.h"
#include "bn_sprite_items_shizu_spr_cross_angry.h"
#include "bn_sprite_items_misha_spr_hips_grin.h"
#include "bn_sprite_items_shizu_spr_basic_angry.h"
#include "bn_sprite_items_misha_spr_perky_confused.h"
#include "bn_sprite_items_shizu_spr_basic_normal2.h"
#include "bn_sprite_items_misha_spr_sign_smile.h"
#include "bn_sprite_items_misha_spr_hips_laugh.h"
#include "bn_sprite_items_misha_spr_sign_confused.h"
#include "bn_sprite_items_shizu_spr_adjust_smug.h"
#include "bn_sprite_items_shizu_spr_adjust_happy.h"
#include "bn_sprite_items_misha_spr_hips_smile.h"
#include "bn_sprite_items_misha_spr_hips_frown.h"
#include "bn_sprite_items_shizu_spr_behind_frown.h"
#include "bn_sprite_items_misha_spr_sign_sad.h"
#include "bn_sprite_items_misha_spr_perky_smile.h"
#include "bn_sprite_items_shizu_spr_basic_sparkle.h"
#include "bn_sprite_items_shizu_spr_basic_happy.h"
#include "bn_sprite_items_shizu_spr_behind_smile.h"
#include "bn_sprite_items_misha_spr_cross_laugh.h"
#include "bn_sprite_items_shizu_spr_basic_frown.h"
#include "bn_sprite_items_misha_spr_cross_grin.h"
#include "bn_sprite_items_shizu_spr_adjust_blush.h"
#include "bn_sprite_items_misha_spr_cross_smile.h"
#include "bn_sprite_items_misha_spr_perky_sad.h"
#include "bn_sprite_items_hanako_spr_def_worry.h"
#include "bn_sprite_items_shizu_spr_adjust_frown.h"
#include "bn_sprite_items_lilly_spr_basic_smile.h"
#include "bn_sprite_items_lilly_spr_basic2_giggle.h"
#include "bn_sprite_items_lilly_spr_cane_smile.h"
#include "bn_sprite_items_lilly_spr_cane_smileclosed.h"
#include "bn_sprite_items_lilly_spr_cane_surprised.h"
#include "bn_sprite_items_lilly_spr_cane_weaksmile.h"
#include "bn_sprite_items_yuuko_spr_down_neutral.h"
#include "bn_sprite_items_yuuko_spr_up_neurotic.h"
#include "bn_sprite_items_yuuko_spr_up_worried.h"
#include "bn_sprite_items_lilly_spr_cane_sad.h"
#include "bn_sprite_items_yuuko_spr_down_smile.h"
#include "bn_sprite_items_yuuko_spr_down_happy.h"
#include "bn_sprite_items_lilly_spr_cane_reminisce.h"
#include "bn_sprite_items_yuuko_spr_up_panic.h"
#include "bn_sprite_items_lilly_spr_cane_sleepy.h"
#include "bn_sprite_items_hanako_spr_defarms_strain.h"
#include "bn_sprite_items_kenji_spr_basic_neutral.h"
#include "bn_sprite_items_kenji_spr_basic_tsun.h"
#include "bn_sprite_items_kenji_spr_rage_rage.h"
#include "bn_sprite_items_kenji_spr_basic_happy.h"
#include "bn_sprite_items_shizu_spr_behind_frustrated.h"
#include "bn_sprite_items_hanako_spr_emb_downtimid.h"
#include "bn_sprite_items_hanako_spr_emb_sad.h"
#include "bn_sprite_items_hanako_spr_emb_blushtimid.h"
#include "shizu_behind.h"
#include "shizu_basic.h"
#include "shizu_cross.h"
#include "misha_hips.h"
#include "misha_perky.h"
#include "misha_sign.h"
#include "shizu_adjust.h"
#include "misha_cross.h"
#include "hanako_def.h"
#include "lilly_basic.h"
#include "lilly_basic2.h"
#include "lilly_cane.h"
#include "yuuko_down.h"
#include "yuuko_up.h"
#include "hanako_defarms.h"
#include "kenji_basic.h"
#include "kenji_rage.h"
#include "hanako_emb.h"
namespace ks {
    class ScriptA1Tuesday {
        public:
            virtual ~ScriptA1Tuesday() = default;
            // Labels
            static void a1_tuesday_smalltalk();
            static void a1_tuesday_risk_vs_reward();
            static void a1_tuesday_pseudo_tea_cosy();
            static void a1_tuesday_shared_library();
            static void a1_tuesday_bizarre_and_surreal();
            static void a1_tuesday();
            static void a1c3o1();
            static void a1c3o2();
            static void a1c4o1();
            static void a1c4o2();
            static void a1c5o1();
            static void a1c5o2();
            // Choice functions
            static void a1_tuesday_risk_vs_reward__menu_question_0();
            static void a1_tuesday_risk_vs_reward__menu_question_0_she_has_a_point_attack_aggressively();
            static void a1_tuesday_risk_vs_reward__menu_question_0_its_a_trap_its_smarter_to_play_defensively_here();
            static void a1_tuesday_shared_library__menu_question_0();
            static void a1_tuesday_shared_library__menu_question_0_hi_im_new_here_hisao_nakai_were_in_the_same_class();
            static void a1_tuesday_shared_library__menu_question_0_im_sorry_i_didnt_mean_to_startle_you();
            static void a1_tuesday_bizarre_and_surreal__menu_question_0();
            static void a1_tuesday_bizarre_and_surreal__menu_question_0_she_was_cute();
            static void a1_tuesday_bizarre_and_surreal__menu_question_0_she_wasnt_cute();
            // Conditions
            static void a1_tuesday_smalltalk__condition_0_0();
            static void a1_tuesday_risk_vs_reward__condition_0_0();
            static void a1_tuesday_pseudo_tea_cosy__condition_0_0();
            static void a1_tuesday_shared_library__condition_0_0();
            static void a1_tuesday_shared_library__condition_0_1();
            static void a1_tuesday_shared_library__condition_1_0();
            static void a1_tuesday_bizarre_and_surreal__condition_0_0();
            static void a1c4o1__condition_0_0();
    };
}

#endif // KS_SCRIPT_A1_TUESDAY