#ifndef KS_SCRIPT_A1_MONDAY
#define KS_SCRIPT_A1_MONDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "bn_regular_bg_items_muto_bg_basic.h"
#include "bn_regular_bg_items_misha_bg_perky.h"
#include "bn_regular_bg_items_misha_bg_cross.h"
#include "bn_regular_bg_items_misha_bg_hips.h"
#include "bn_regular_bg_items_shizu_bg_basic.h"
#include "bn_regular_bg_items_shizu_bg_behind.h"
#include "bn_regular_bg_items_misha_bg_sign.h"
#include "bn_regular_bg_items_shizu_bg_adjust.h"
#include "bn_regular_bg_items_hanako_bg_emb.h"
#include "bn_regular_bg_items_hanako_bg_defarms.h"
#include "bn_regular_bg_items_nurse_bg.h"
#include "bn_regular_bg_items_kenji_bg_basic.h"
#include "background_metas/school_gate.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_nursehall.h"
#include "background_metas/school_nurseoffice.h"
#include "background_metas/school_gardens.h"
#include "background_metas/school_dormext_start.h"
#include "background_metas/school_dormhallground.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_dormhisao_ni.h"
#include "bn_sprite_items_muto_spr_basic_normal.h"
#include "bn_sprite_items_muto_spr_basic_smile.h"
#include "bn_sprite_items_muto_spr_basic_irritated.h"
#include "bn_sprite_items_misha_spr_perky_smile.h"
#include "bn_sprite_items_misha_spr_cross_laugh.h"
#include "bn_sprite_items_misha_spr_hips_grin.h"
#include "bn_sprite_items_shizu_spr_basic_normal.h"
#include "bn_sprite_items_shizu_spr_behind_blank.h"
#include "bn_sprite_items_misha_spr_sign_smile.h"
#include "bn_sprite_items_shizu_spr_adjust_happy.h"
#include "bn_sprite_items_shizu_spr_behind_smile.h"
#include "bn_sprite_items_misha_spr_hips_smile.h"
#include "bn_sprite_items_shizu_spr_basic_normal2.h"
#include "bn_sprite_items_misha_spr_cross_grin.h"
#include "bn_sprite_items_shizu_spr_adjust_smug.h"
#include "bn_sprite_items_misha_spr_perky_confused.h"
#include "bn_sprite_items_shizu_spr_behind_frown.h"
#include "bn_sprite_items_misha_spr_hips_laugh.h"
#include "bn_sprite_items_misha_spr_perky_sad.h"
#include "bn_sprite_items_shizu_spr_adjust_blush.h"
#include "bn_sprite_items_shizu_spr_basic_frown.h"
#include "bn_sprite_items_misha_spr_hips_frown.h"
#include "bn_sprite_items_hanako_spr_emb_downtimid.h"
#include "bn_sprite_items_hanako_spr_defarms_shock.h"
#include "bn_sprite_items_shizu_spr_behind_frustrated.h"
#include "bn_sprite_items_nurse_spr_neutral.h"
#include "bn_sprite_items_nurse_spr_grin.h"
#include "bn_sprite_items_nurse_spr_fabulous.h"
#include "bn_sprite_items_nurse_spr_concern.h"
#include "bn_sprite_items_kenji_spr_basic_tsun.h"
#include "bn_sprite_items_kenji_spr_basic_happy.h"
#include "bn_sprite_items_kenji_spr_basic_neutral.h"
#include "muto_basic.h"
#include "misha_perky.h"
#include "misha_cross.h"
#include "misha_hips.h"
#include "shizu_basic.h"
#include "shizu_behind.h"
#include "misha_sign.h"
#include "shizu_adjust.h"
#include "hanako_emb.h"
#include "hanako_defarms.h"
#include "nurse.h"
#include "kenji_basic.h"
#include "../events/op_snowywoods.cpp.h"
#include "../events/other_iwanako.cpp.h"
#include "../events/hosp_room.cpp.h"
#include "../events/drugs.cpp.h"
#include "../events/hisao_class_start.cpp.h"
#include "../events/hisao_class_move.cpp.h"
#include "../events/hisao_class_end.cpp.h"
#include "video_op_1_dxtv.h"
#include "video_tc_act1_dxtv.h"
namespace ks {
    class ScriptA1Monday {
        public:
            virtual ~ScriptA1Monday() = default;
            // Labels
            SCENE_INLINE void a1_monday_out_cold();
            SCENE_INLINE void a1_monday_bundle_of_hisao();
            SCENE_INLINE void a1_monday_gateway_effect();
            SCENE_INLINE void a1_monday_enter_stage_left();
            SCENE_INLINE void a1_monday_in_the_nursery();
            SCENE_INLINE void a1_monday_nobodys_room();
            static void a1_monday();
            SCENE_INLINE void a1c1o1();
            SCENE_INLINE void a1c1o2();
            SCENE_INLINE void a1c2o1();
            SCENE_INLINE void a1c2o2();
            SCENE_INLINE void a1c2o3();
            // Choice functions
            SCENE_INLINE void a1_monday_gateway_effect__menu_question_0();
            SCENE_INLINE void a1_monday_gateway_effect__menu_question_0_why();
            SCENE_INLINE void a1_monday_gateway_effect__menu_question_0_yeah_of_course();
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0();
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0_ask_about_the_library();
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness();
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know();
            // Conditions
            SCENE_INLINE void a1_monday_out_cold__condition_0_0();
            SCENE_INLINE void a1_monday_bundle_of_hisao__condition_0_0();
            SCENE_INLINE void a1_monday_gateway_effect__condition_0_0();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_0_0();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_0_1();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_1_0();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_1_1();
            SCENE_INLINE void a1_monday_enter_stage_left__condition_2_0();
            SCENE_INLINE void a1_monday_in_the_nursery__condition_0_0();
            SCENE_INLINE void a1_monday_nobodys_room__condition_0_0();
    };
}

#endif // KS_SCRIPT_A1_MONDAY