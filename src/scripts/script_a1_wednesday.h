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
#include "bn_music_items.h"
#include "bn_regular_bg_items_school_hallway3.h"
#include "bn_regular_bg_items_suburb_roadcenter.h"
#include "bn_regular_bg_items_suburb_shanghaiext.h"
#include "bn_regular_bg_items_suburb_shanghaiint.h"
#include "bn_regular_bg_items_shizu_shanghai.h"
#include "bn_regular_bg_items_shizu_shanghai_borednormal.h"
#include "bn_regular_bg_items_shizu_shanghai_boredlaugh.h"
#include "bn_regular_bg_items_school_scienceroom.h"
#include "bn_regular_bg_items_school_lobby.h"
#include "bn_regular_bg_items_school_miyagi.h"
#include "bn_regular_bg_items_tearoom_everyone_noon.h"
#include "bn_regular_bg_items_school_classroomart.h"
#include "bn_regular_bg_items_rin_eating.h"
#include "bn_regular_bg_items_school_staircase2.h"
#include "bn_regular_bg_items_school_courtyard.h"
#include "bn_regular_bg_items_school_dormext_start.h"
// #include "bn_regular_bg_items_mural_start.h"
#include "bn_regular_bg_items_school_dormext_start_ss.h"
#include "bn_regular_bg_items_school_dormext_half_ni.h"
namespace ks {
    class ScriptA1Wednesday {
        public:
            virtual ~ScriptA1Wednesday() = default;
            // Labels
            static void a1_wednesday_short_sharp_shock();
            static void a1_wednesday_detour_ahead();
            static void a1_wednesday_it_builds_character();
            static void a1_wednesday_sip_p1();
            static void a1_wednesday_meet_cute();
            static void a1_wednesday_lunch_evolution_theory();
            static void a1_wednesday_a_private_lunch();
            static void a1_wednesday_waylay();
            static void a1_wednesday_the_other_green();
            static void a1_wednesday();
            static void separate_of_sss_and_mc(ks::SceneManager& scene);
            static void a1c6o1(ks::SceneManager& scene);
            static void a1c6o2(ks::SceneManager& scene);
            static void a1c6o3(ks::SceneManager& scene);
            static void a1c7o1(ks::SceneManager& scene);
            static void a1c7o2(ks::SceneManager& scene);
            // Choice functions
            static void a1_wednesday_lunch_evolution_theory__menu_question_0(ks::SceneManager& scene);
            static void a1_wednesday_lunch_evolution_theory__menu_question_0_read_my_book(ks::SceneManager& scene);
            static void a1_wednesday_waylay__menu_question_0(ks::SceneManager& scene);
            static void a1_wednesday_waylay__menu_question_0_yes(ks::SceneManager& scene);
            static void a1_wednesday_waylay__menu_question_0_maybe(ks::SceneManager& scene);
            // Conditions
            static void a1_wednesday_short_sharp_shock__condition_0__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_short_sharp_shock__condition_0__condition_0_1(ks::SceneManager& scene);
            static void a1_wednesday_short_sharp_shock__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_short_sharp_shock__condition_0_1(ks::SceneManager& scene);
            static void a1_wednesday_detour_ahead__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_detour_ahead__condition_0_1(ks::SceneManager& scene);
            static void a1_wednesday_it_builds_character__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_sip_p1__condition_0__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_sip_p1__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_meet_cute__condition_0__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_meet_cute__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_lunch_evolution_theory__menu_question_0__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_a_private_lunch__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_waylay__condition_0_0(ks::SceneManager& scene);
            static void a1_wednesday_the_other_green__condition_0_0(ks::SceneManager& scene);
    };
}

#endif // KS_SCRIPT_A1_WEDNESDAY
