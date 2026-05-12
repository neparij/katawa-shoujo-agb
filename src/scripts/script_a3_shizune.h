#ifndef KS_SCRIPT_A3_SHIZUNE
#define KS_SCRIPT_A3_SHIZUNE

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/hideaki.h"
#include "smart_characters/lilly.h"
#include "smart_characters/akira.h"
#include "smart_characters/jigoro.h"
#include "smart_characters/kenji.h"
#include "smart_characters/yuuko.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_council.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/city_station.h"
#include "background_metas/shizu_houseext.h"
#include "background_metas/shizu_living.h"
#include "background_metas/shizune_car.h"
#include "background_metas/shizu_fishing.h"
#include "background_metas/shizu_fishing_ah.h"
#include "background_metas/shizu_fishing_sl.h"
#include "background_metas/shizu_fishing_ss.h"
#include "background_metas/shizu_houseext_lights.h"
#include "background_metas/shizu_guesthisao.h"
#include "background_metas/shizu_park.h"
#include "background_metas/shizu_garden.h"
#include "background_metas/shizu_couch.h"
#include "background_metas/shizune_hcg_tied_smile_small.h"
#include "background_metas/shizune_hcg_tied_blush_small.h"
#include "background_metas/shizune_hcg_tied_blush.h"
#include "background_metas/shizune_hcg_tied_hisao2.h"
#include "background_metas/shizune_hcg_tied_stare.h"
#include "background_metas/shizune_hcg_tied_stare_small.h"
#include "background_metas/shizune_hcg_tied_close_small.h"
#include "background_metas/shizune_hcg_tied_hisao2_small.h"
#include "background_metas/shizune_hcg_tied_kinky3_small.h"
#include "background_metas/shizune_hcg_tied_kinky2_small.h"
#include "background_metas/shizune_hcg_tied_kinky2.h"
#include "background_metas/shizune_hcg_tied_kinky1_small.h"
#include "background_metas/shizune_hcg_tied_close.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/hisao_letter_open.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/misha_sad.h"
#include "background_metas/school_courtyard_ss.h"
#include "background_metas/suburb_roadcenter_ss.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_council_ss.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/school_library.h"
#include "background_metas/school_dormext_full_ss.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_roof.h"
#include "background_metas/shizu_hands.h"
#include "background_metas/misha_roof_closed.h"
#include "background_metas/misha_roof_normal.h"
#include "background_metas/misha_roof_sad.h"
#include "background_metas/misha_roof_angry.h"
#include "background_metas/shizu_flashback.h"
#include "background_metas/misha_naked.h"
#include "background_metas/misha_sex_aside.h"
#include "background_metas/misha_sex_closed.h"
namespace ks {
    class ScriptA3Shizune {
        public:
            virtual ~ScriptA3Shizune() = default;
            // Labels
            SCENE_INLINE void a3_shizune_force_feedback();
            SCENE_INLINE void a3_shizune_united_nations();
            SCENE_INLINE void a3_shizune_use_mention_distinction();
            SCENE_INLINE void a3_shizune_family_plot();
            SCENE_INLINE void a3_shizune_pangrammatic_window();
            SCENE_INLINE void a3_shizune_closer();
            SCENE_INLINE void a3_shizune_confrontation();
            SCENE_INLINE void a3_shizune_the_anchor();
            SCENE_INLINE void a3_shizune_roadmap();
            SCENE_INLINE void a3_shizune_acute_triangle();
            SCENE_INLINE void a3_shizune_dewey_decimated();
            SCENE_INLINE void a3_shizune_tongue_tied();
            SCENE_INLINE void a3_shizune_look_ahead();
            SCENE_INLINE void a3_shizune_look_aside();
            static void a3_shizune();
            SCENE_INLINE void aside_and_ahead_1();
            SCENE_INLINE void aside_and_ahead_2();
            SCENE_INLINE void aside_and_ahead_3();
            SCENE_INLINE void a3sc1o1();
            SCENE_INLINE void a3sc1o2();
            // Choice functions
            SCENE_INLINE void a3_shizune_tongue_tied__menu_question_0();
            SCENE_INLINE void a3_shizune_tongue_tied__menu_question_0_comfort_misha();
            SCENE_INLINE void a3_shizune_tongue_tied__menu_question_0_refuse();
            // Conditions
            SCENE_INLINE void a3_shizune_force_feedback__condition_0_0();
            SCENE_INLINE void a3_shizune_force_feedback__condition_1_0();
            SCENE_INLINE void a3_shizune_united_nations__condition_0_0();
            SCENE_INLINE void a3_shizune_use_mention_distinction__condition_0_0();
            SCENE_INLINE void a3_shizune_family_plot__condition_0_0();
            SCENE_INLINE void a3_shizune_pangrammatic_window__condition_0_0();
            SCENE_INLINE void a3_shizune_closer__condition_0_0();
            SCENE_INLINE void a3_shizune_closer__condition_0_1();
            SCENE_INLINE void a3_shizune_closer__condition_1_0();
            SCENE_INLINE void a3_shizune_confrontation__condition_0_0();
            SCENE_INLINE void a3_shizune_confrontation__condition_1_0();
            SCENE_INLINE void a3_shizune_the_anchor__condition_0_0();
            SCENE_INLINE void a3_shizune_roadmap__condition_0_0();
            SCENE_INLINE void a3_shizune_acute_triangle__condition_0_0();
            SCENE_INLINE void a3_shizune_acute_triangle__condition_0_1();
            SCENE_INLINE void a3_shizune_acute_triangle__condition_1_0();
            SCENE_INLINE void a3_shizune_dewey_decimated__condition_0_0();
            SCENE_INLINE void a3_shizune_tongue_tied__condition_0_0();
            SCENE_INLINE void a3_shizune_look_ahead__condition_0_0();
            SCENE_INLINE void a3_shizune_look_ahead__condition_0_1();
            SCENE_INLINE void a3_shizune_look_ahead__condition_1_0();
            SCENE_INLINE void a3_shizune_look_aside__condition_0_0();
            SCENE_INLINE void a3_shizune__condition_0_0();
            SCENE_INLINE void a3_shizune__condition_0_1();
    };
}

#endif // KS_SCRIPT_A3_SHIZUNE