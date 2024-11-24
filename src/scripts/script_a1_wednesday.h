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
            static void scene__a1_wednesday__short_sharp_shock();
            static void scene__a1_wednesday__detour_ahead();
            static void scene__a1_wednesday__it_builds_character();
            static void scene__a1_wednesday__sip_p1();
            static void scene__a1_wednesday__meet_cute();
            static void scene__a1_wednesday__lunch_evolution_theory();
            static void scene__a1_wednesday__a_private_lunch();
            static void scene__a1_wednesday__waylay();
            static void scene__a1_wednesday__the_other_green();
            static void scene__a1_wednesday();
            static void scene__separate_of_sss_and_mc(ks::SceneManager& scene);
            static void scene__a1c6o1(ks::SceneManager& scene);
            static void scene__a1c6o2(ks::SceneManager& scene);
            static void scene__a1c6o3(ks::SceneManager& scene);
            static void scene__a1c7o1(ks::SceneManager& scene);
            static void scene__a1c7o2(ks::SceneManager& scene);
            // Choice functions
            static void scene__a1_wednesday__lunch_evolution_theory__menu_question_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__lunch_evolution_theory__menu_question_0_read_my_book(ks::SceneManager& scene);
            static void scene__a1_wednesday__waylay__menu_question_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__waylay__menu_question_0_yes(ks::SceneManager& scene);
            static void scene__a1_wednesday__waylay__menu_question_0_maybe(ks::SceneManager& scene);
            // Conditions
            static void scene__a1_wednesday__short_sharp_shock__condition_0__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__short_sharp_shock__condition_0__condition_0_1(ks::SceneManager& scene);
            static void scene__a1_wednesday__short_sharp_shock__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__short_sharp_shock__condition_0_1(ks::SceneManager& scene);
            static void scene__a1_wednesday__detour_ahead__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__detour_ahead__condition_0_1(ks::SceneManager& scene);
            static void scene__a1_wednesday__it_builds_character__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__sip_p1__condition_0__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__sip_p1__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__meet_cute__condition_0__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__meet_cute__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__lunch_evolution_theory__menu_question_0__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__a_private_lunch__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__waylay__condition_0_0(ks::SceneManager& scene);
            static void scene__a1_wednesday__the_other_green__condition_0_0(ks::SceneManager& scene);
    };
}

#endif // KS_SCRIPT_A1_WEDNESDAY
