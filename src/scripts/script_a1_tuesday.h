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
#include "bn_music_items.h"
#include "bn_regular_bg_items_school_dormhisao.h"
#include "bn_regular_bg_items_school_scienceroom.h"
#include "bn_regular_bg_items_school_hallway3.h"
#include "bn_regular_bg_items_school_cafeteria.h"
#include "bn_regular_bg_items_school_lobby.h"
#include "bn_regular_bg_items_school_council.h"
#include "bn_regular_bg_items_school_staircase2.h"
#include "bn_regular_bg_items_school_hallway2.h"
#include "bn_regular_bg_items_lilly_tearoom.h"
#include "bn_regular_bg_items_lilly_tearoom_open.h"
#include "bn_regular_bg_items_school_miyagi.h"
#include "bn_regular_bg_items_tearoom_lillyhisao_noon.h"
#include "bn_regular_bg_items_tearoom_lillyhisao_sunset.h"
#include "bn_regular_bg_items_school_miyagi_ss.h"
#include "bn_regular_bg_items_school_library_ss.h"
#include "bn_regular_bg_items_school_dormhallway.h"
#include "bn_regular_bg_items_school_dormhisao_ss.h"
#include "bn_regular_bg_items_hana_library.h"
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
            static void a1c3o1(ks::SceneManager& scene);
            static void a1c3o2(ks::SceneManager& scene);
            static void a1c4o1(ks::SceneManager& scene);
            static void a1c4o2(ks::SceneManager& scene);
            static void a1c5o1(ks::SceneManager& scene);
            static void a1c5o2(ks::SceneManager& scene);
            // Choice functions
            static void a1_tuesday_risk_vs_reward__menu_question_0(ks::SceneManager& scene);
            static void a1_tuesday_risk_vs_reward__menu_question_0_she_has_a_point_attack_aggressively(ks::SceneManager& scene);
            static void a1_tuesday_risk_vs_reward__menu_question_0_its_a_trap_its_smarter_to_play_defensively_here(ks::SceneManager& scene);
            static void a1_tuesday_shared_library__menu_question_0(ks::SceneManager& scene);
            static void a1_tuesday_shared_library__menu_question_0_hi_im_new_here_hisao_nakai_were_in_the_same_class(ks::SceneManager& scene);
            static void a1_tuesday_shared_library__menu_question_0_im_sorry_i_didnt_mean_to_startle_you(ks::SceneManager& scene);
            static void a1_tuesday_bizarre_and_surreal__menu_question_0(ks::SceneManager& scene);
            static void a1_tuesday_bizarre_and_surreal__menu_question_0_she_was_cute(ks::SceneManager& scene);
            static void a1_tuesday_bizarre_and_surreal__menu_question_0_she_wasnt_cute(ks::SceneManager& scene);
            // Conditions
            static void a1_tuesday_smalltalk__condition_0_0(ks::SceneManager& scene);
            static void a1_tuesday_risk_vs_reward__condition_0_0(ks::SceneManager& scene);
            static void a1_tuesday_pseudo_tea_cosy__condition_0_0(ks::SceneManager& scene);
            static void a1_tuesday_shared_library__condition_0_0(ks::SceneManager& scene);
            static void a1_tuesday_shared_library__condition_0_1(ks::SceneManager& scene);
            static void a1_tuesday_shared_library__condition_1_0(ks::SceneManager& scene);
            static void a1_tuesday_bizarre_and_surreal__condition_0_0(ks::SceneManager& scene);
            static void a1c4o1__condition_0_0(ks::SceneManager& scene);
    };
}

#endif // KS_SCRIPT_A1_TUESDAY