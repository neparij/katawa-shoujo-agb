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
#include "bn_music_items.h"
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
#include "bn_regular_bg_items_school_cafeteria.h"
#include "bn_regular_bg_items_school_nursehall.h"
#include "bn_regular_bg_items_school_nurseoffice.h"
#include "bn_regular_bg_items_school_gardens.h"
#include "bn_regular_bg_items_school_dormext_start.h"
#include "bn_regular_bg_items_school_dormhallground.h"
#include "bn_regular_bg_items_school_dormhallway.h"
#include "bn_regular_bg_items_school_dormhisao_ss.h"
#include "bn_regular_bg_items_school_dormhisao_ni.h"
namespace ks {
    class ScriptA1Monday {
        public:
            virtual ~ScriptA1Monday() = default;
            // Labels
            static void scene__a1_monday__out_cold();
            static void scene__a1_monday__bundle_of_hisao();
            static void scene__a1_monday__gateway_effect();
            static void scene__a1_monday__enter_stage_left();
            static void scene__a1_monday__in_the_nursery();
            static void scene__a1_monday__nobodys_room();
            static void scene__a1_monday();
            static void scene__a1c1o1(ks::SceneManager& scene);
            static void scene__a1c1o2(ks::SceneManager& scene);
            static void scene__a1c2o1(ks::SceneManager& scene);
            static void scene__a1c2o2(ks::SceneManager& scene);
            static void scene__a1c2o3(ks::SceneManager& scene);
            // Choice functions
            static void scene__a1_monday__gateway_effect__menu_question_0(ks::SceneManager& scene);
            static void scene__a1_monday__gateway_effect__menu_question_0_why(ks::SceneManager& scene);
            static void scene__a1_monday__gateway_effect__menu_question_0_yeah_of_course(ks::SceneManager& scene);
            static void scene__a1_monday__in_the_nursery__menu_question_0(ks::SceneManager& scene);
            static void scene__a1_monday__in_the_nursery__menu_question_0_ask_about_the_library(ks::SceneManager& scene);
            static void scene__a1_monday__in_the_nursery__menu_question_0_ask_about_shizunes_deafness(ks::SceneManager& scene);
            static void scene__a1_monday__in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know(ks::SceneManager& scene);
            // Conditions
            static void scene__a1_monday__out_cold__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_monday__bundle_of_hisao__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_monday__gateway_effect__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_monday__enter_stage_left__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_monday__enter_stage_left__condition_0_1(ks::SceneManager& scene);
            static void scene__a1_monday__enter_stage_left__condition_1_0(ks::SceneManager& scene);
            static void scene__a1_monday__enter_stage_left__condition_1_1(ks::SceneManager& scene);
            static void scene__a1_monday__enter_stage_left__condition_2_0(ks::SceneManager& scene);
            static void scene__a1_monday__in_the_nursery__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_monday__nobodys_room__condition_0_0(ks::SceneManager& scene);
    };
}

#endif // KS_SCRIPT_A1_MONDAY