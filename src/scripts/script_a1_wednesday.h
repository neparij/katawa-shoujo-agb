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
#include "bn_regular_bg_items_school_hallway3.h"
#include "bn_regular_bg_items_misha_bg_hips.h"
#include "bn_regular_bg_items_shizu_bg_cross.h"
#include "bn_regular_bg_items_shizu_bg_adjust.h"
#include "bn_regular_bg_items_misha_bg_cross.h"
#include "bn_regular_bg_items_shizu_bg_basic.h"
#include "bn_regular_bg_items_misha_bg_perky.h"
#include "bn_regular_bg_items_suburb_roadcenter.h"
#include "bn_regular_bg_items_suburb_shanghaiext.h"
#include "bn_regular_bg_items_suburb_shanghaiint.h"
#include "bn_regular_bg_items_shizu_bg_behind.h"
#include "bn_regular_bg_items_shizu_shanghai.h"
#include "bn_regular_bg_items_shizu_shanghai_borednormal.h"
#include "bn_regular_bg_items_shizu_shanghai_boredlaugh.h"
#include "bn_regular_bg_items_misha_bg_sign.h"
#include "bn_regular_bg_items_school_scienceroom.h"
#include "bn_regular_bg_items_school_lobby.h"
#include "bn_regular_bg_items_school_miyagi.h"
#include "bn_regular_bg_items_tearoom_everyone_noon.h"
#include "bn_regular_bg_items_school_classroomart.h"
#include "bn_regular_bg_items_rin_eating.h"
#include "bn_regular_bg_items_rin_bg_relaxed.h"
#include "bn_regular_bg_items_rin_bg_basic.h"
#include "bn_regular_bg_items_rin_bg_negative.h"
#include "bn_regular_bg_items_school_staircase2.h"
#include "bn_regular_bg_items_school_courtyard.h"
#include "bn_regular_bg_items_school_dormext_start.h"
#include "bn_regular_bg_items_school_dormext_start_ss.h"
#include "bn_regular_bg_items_school_dormext_half_ni.h"
#include "bn_sprite_items_misha_spr_hips_frown.h"
#include "bn_sprite_items_shizu_spr_cross_rage.h"
#include "bn_sprite_items_misha_spr_hips_grin.h"
#include "bn_sprite_items_shizu_spr_adjust_angry.h"
#include "bn_sprite_items_misha_spr_hips_smile.h"
#include "bn_sprite_items_shizu_spr_cross_angry.h"
#include "bn_sprite_items_misha_spr_cross_smile.h"
#include "bn_sprite_items_misha_spr_cross_grin.h"
#include "bn_sprite_items_shizu_spr_basic_frown.h"
#include "bn_sprite_items_misha_spr_perky_smile.h"
#include "bn_sprite_items_shizu_spr_basic_normal.h"
#include "bn_sprite_items_shizu_spr_behind_smile.h"
#include "bn_sprite_items_shizu_spr_adjust_happy.h"
#include "bn_sprite_items_shizu_spr_adjust_smug.h"
#include "bn_sprite_items_shizu_spr_behind_blank.h"
#include "bn_sprite_items_shizu_spr_behind_frown.h"
#include "bn_sprite_items_misha_spr_perky_sad.h"
#include "bn_sprite_items_misha_spr_sign_confused.h"
#include "bn_sprite_items_misha_spr_cross_laugh.h"
#include "bn_sprite_items_shizu_spr_basic_normal2.h"
#include "bn_sprite_items_shizu_spr_basic_happy.h"
#include "bn_sprite_items_misha_spr_perky_confused.h"
#include "bn_sprite_items_misha_spr_sign_smile.h"
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
#include "bn_sprite_items_rin_spr_basic_deadpanamused.h"
#include "bn_sprite_items_rin_spr_basic_deadpansurprised.h"
#include "bn_sprite_items_rin_spr_basic_amused.h"
#include "bn_sprite_items_misha_spr_hips_laugh.h"
#include "misha_hips.h"
#include "shizu_cross.h"
#include "shizu_adjust.h"
#include "misha_cross.h"
#include "shizu_basic.h"
#include "misha_perky.h"
#include "shizu_behind.h"
#include "misha_sign.h"
#include "rin_relaxed.h"
#include "rin_basic.h"
#include "rin_negative.h"
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
            static void separate_of_sss_and_mc(const ks::SceneManager scene);
            static void a1c6o1(const ks::SceneManager scene);
            static void a1c6o2(const ks::SceneManager scene);
            static void a1c6o3(const ks::SceneManager scene);
            static void a1c7o1(const ks::SceneManager scene);
            static void a1c7o2(const ks::SceneManager scene);
            // Choice functions
            static void a1_wednesday_lunch_evolution_theory__menu_question_0(const ks::SceneManager scene);
            static void a1_wednesday_lunch_evolution_theory__menu_question_0_read_my_book(const ks::SceneManager scene);
            static void a1_wednesday_waylay__menu_question_0(const ks::SceneManager scene);
            static void a1_wednesday_waylay__menu_question_0_yes(const ks::SceneManager scene);
            static void a1_wednesday_waylay__menu_question_0_maybe(const ks::SceneManager scene);
            // Conditions
            static void a1_wednesday_short_sharp_shock__condition_0__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_short_sharp_shock__condition_0__condition_0_1(const ks::SceneManager scene);
            static void a1_wednesday_short_sharp_shock__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_short_sharp_shock__condition_0_1(const ks::SceneManager scene);
            static void a1_wednesday_detour_ahead__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_detour_ahead__condition_0_1(const ks::SceneManager scene);
            static void a1_wednesday_it_builds_character__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_sip_p1__condition_0__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_sip_p1__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_meet_cute__condition_0__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_meet_cute__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_lunch_evolution_theory__menu_question_0__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_a_private_lunch__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_waylay__condition_0_0(const ks::SceneManager scene);
            static void a1_wednesday_the_other_green__condition_0_0(const ks::SceneManager scene);
    };
}

#endif // KS_SCRIPT_A1_WEDNESDAY