#ifndef KS_SCRIPT_A1_MONDAY
#define KS_SCRIPT_A1_MONDAY

#include "../sequence/assignmentitem.h"
#include "../sequence/backgrounditem.h"
#include "../sequence/dialogitem.h"
#include "../sequence/menuitem.h"
#include "../sequence/musicitem.h"
#include "../sequence/runlabelfinishitem.h"
#include "../sequence/runlabelitem.h"
#include "../sequence/spriteitem.h"
#include "../scenemanager.h"
#include "bn_regular_bg_items_op_snowywoods.h"
#include "bn_regular_bg_items_other_iwanako.h"
#include "bn_regular_bg_items_hosp_room.h"
#include "bn_regular_bg_items_school_gate.h"
#include "bn_regular_bg_items_school_courtyard.h"
#include "bn_regular_bg_items_school_lobby.h"
#include "bn_regular_bg_items_school_staircase2.h"
#include "bn_regular_bg_items_school_hallway3.h"
#include "bn_regular_bg_items_hisao_class.h"
#include "bn_regular_bg_items_school_scienceroom.h"
#include "bn_regular_bg_items_misha_bg_perky.h"
#include "bn_regular_bg_items_misha_bg_cross.h"
#include "bn_regular_bg_items_misha_bg_hips.h"
#include "bn_regular_bg_items_shizu_bg_basic.h"
#include "bn_regular_bg_items_shizu_bg_behind.h"
#include "bn_regular_bg_items_misha_bg_sign.h"
#include "bn_regular_bg_items_shizu_bg_adjust.h"
#include "bn_regular_bg_items_school_cafeteria.h"
#include "bn_regular_bg_items_school_nursehall.h"
#include "bn_regular_bg_items_school_nurseoffice.h"
#include "bn_regular_bg_items_school_gardens.h"
#include "bn_regular_bg_items_school_dormext_start.h"
#include "bn_regular_bg_items_school_dormhallground.h"
#include "bn_regular_bg_items_school_dormhallway.h"
#include "bn_regular_bg_items_school_dormhisao_ss.h"
#include "bn_regular_bg_items_school_dormhisao_ni.h"
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
#include "bn_sprite_items_shizu_spr_behind_frustrated.h"
#include "misha_perky.h"
#include "misha_cross.h"
#include "misha_hips.h"
#include "shizu_basic.h"
#include "shizu_behind.h"
#include "misha_sign.h"
#include "shizu_adjust.h"
namespace ks {
    class ScriptA1Monday {
        public:
            virtual ~ScriptA1Monday() = default;
            // Labels
            static void a1_monday_out_cold();
            static void a1_monday_bundle_of_hisao();
            static void a1_monday_gateway_effect();
            static void a1_monday_enter_stage_left();
            static void a1_monday_in_the_nursery();
            static void a1_monday_nobodys_room();
            static void a1_monday();
            static void a1c1o1(const ks::SceneManager scene);
            static void a1c1o2(const ks::SceneManager scene);
            static void a1c2o1(const ks::SceneManager scene);
            static void a1c2o2(const ks::SceneManager scene);
            static void a1c2o3(const ks::SceneManager scene);
            // Choice functions
            static void a1_monday_gateway_effect__menu_question_0(const ks::SceneManager scene);
            static void a1_monday_gateway_effect__menu_question_0_why(const ks::SceneManager scene);
            static void a1_monday_gateway_effect__menu_question_0_yeah_of_course(const ks::SceneManager scene);
            static void a1_monday_in_the_nursery__menu_question_0(const ks::SceneManager scene);
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_the_library(const ks::SceneManager scene);
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness(const ks::SceneManager scene);
            static void a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know(const ks::SceneManager scene);
            // Conditions
            static void a1_monday_out_cold__condition_0_0(const ks::SceneManager scene);
            static void a1_monday_bundle_of_hisao__condition_0_0(const ks::SceneManager scene);
            static void a1_monday_gateway_effect__condition_0_0(const ks::SceneManager scene);
            static void a1_monday_enter_stage_left__condition_0_0(const ks::SceneManager scene);
            static void a1_monday_enter_stage_left__condition_0_1(const ks::SceneManager scene);
            static void a1_monday_enter_stage_left__condition_1_0(const ks::SceneManager scene);
            static void a1_monday_enter_stage_left__condition_1_1(const ks::SceneManager scene);
            static void a1_monday_enter_stage_left__condition_2_0(const ks::SceneManager scene);
            static void a1_monday_in_the_nursery__condition_0_0(const ks::SceneManager scene);
            static void a1_monday_nobodys_room__condition_0_0(const ks::SceneManager scene);
    };
}

#endif // KS_SCRIPT_A1_MONDAY