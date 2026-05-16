#ifndef KS_SCRIPT_A4_LILLY
#define KS_SCRIPT_A4_LILLY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/misha.h"
#include "smart_characters/hanako.h"
#include "smart_characters/shizu.h"
#include "smart_characters/lilly.h"
#include "smart_characters/akira.h"
#include "smart_characters/nurse.h"
#include "smart_characters/kenji.h"
#include "smart_characters/muto.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/hideaki.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/lilly_tearoom.h"
#include "background_metas/lilly_tearoom_open.h"
#include "background_metas/school_miyagi.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/lilly_bedroom.h"
#include "background_metas/school_dormlilly.h"
#include "background_metas/lilly_kissing.h"
#include "background_metas/school_nursehall.h"
#include "background_metas/school_nurseoffice.h"
#include "background_metas/school_gate_ss.h"
#include "background_metas/school_road_ss.h"
#include "background_metas/suburb_konbiniint.h"
#include "background_metas/suburb_konbiniext_ss.h"
#include "background_metas/school_dormext_full_ni.h"
#include "background_metas/city_restaurant.h"
#include "background_metas/lilly_restaurant_listen.h"
#include "background_metas/lilly_restaurant_sheepish.h"
#include "background_metas/lilly_restaurant_wine.h"
#include "background_metas/lilly_touch_cheong.h"
#include "background_metas/lilly_restaurant_eat.h"
#include "background_metas/lilly_restaurant_chew.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/lilly_sleeping_smile.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_dormext_full.h"
#include "background_metas/school_gardens.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/hisao_teacup.h"
#include "background_metas/lilly_masturbate.h"
#include "background_metas/lilly_masturbate_come_face.h"
#include "background_metas/lilly_masturbate_come.h"
#include "background_metas/misc_ceiling.h"
#include "background_metas/school_library.h"
#include "background_metas/school_hallway3_blurred.h"
#include "background_metas/suburb_park_ss.h"
#include "background_metas/akira_park.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/suburb_shanghaiext.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/school_council.h"
#include "background_metas/lilly_sheets.h"
#include "background_metas/school_council_ss.h"
#include "background_metas/school_courtyard_ss.h"
#include "background_metas/lilly_touch_cas.h"
#include "background_metas/school_gate_ni.h"
#include "background_metas/school_library_ss.h"
#include "background_metas/hana_library.h"
#include "background_metas/hana_library_read.h"
#include "background_metas/hana_library_smile.h"
#include "background_metas/school_gardens_ni.h"
#include "background_metas/school_courtyard_ni.h"
#include "background_metas/shizu_houseext_ni.h"
#include "background_metas/shizu_houseext_lights.h"
#include "background_metas/city_street4_ni.h"
#include "background_metas/hosp_ext.h"
#include "background_metas/lilly_airport.h"
#include "background_metas/lilly_airport_end.h"
#include "background_metas/hosp_room2.h"
#include "background_metas/lilly_hospitalwindow.h"
#include "background_metas/school_dormhisao_blurred_ni.h"
#include "background_metas/lilly_hospitalclosed.h"
#include "background_metas/lilly_hospital.h"
#include "background_metas/lilly_hilltop.h"
#include "background_metas/lilly_goodend.h"
namespace ks {
    class ScriptA4Lilly {
        public:
            virtual ~ScriptA4Lilly() = default;
            // Labels
            SCENE_INLINE void a4_lilly_slow_steps();
            SCENE_INLINE void a4_lilly_pajamas_and_suits();
            SCENE_INLINE void a4_lilly_correct_procedure();
            SCENE_INLINE void a4_lilly_out_and_about();
            SCENE_INLINE void a4_lilly_a_mornings_reverse();
            SCENE_INLINE void a4_lilly_blackout();
            SCENE_INLINE void a4_lilly_context();
            SCENE_INLINE void a4_lilly_a_faraway_future();
            SCENE_INLINE void a4_lilly_farewell();
            SCENE_INLINE void a4_lilly_false_cadence();
            SCENE_INLINE void a4_lilly_under_a_maudlin_sky();
            SCENE_INLINE void a4_lilly_under_a_bright_sky();
            SCENE_INLINE void a4_lilly_forwards();
            static void a4_lilly();
            SCENE_INLINE void a4lc1o1();
            SCENE_INLINE void a4lc1o2();
            // Choice functions
            SCENE_INLINE void a4_lilly_out_and_about__menu_question_0();
            SCENE_INLINE void a4_lilly_out_and_about__menu_question_0_mention_the_letter();
            SCENE_INLINE void a4_lilly_out_and_about__menu_question_0_drop_the_subject();
            // Conditions
            SCENE_INLINE void a4_lilly_slow_steps__condition_0_0();
            SCENE_INLINE void a4_lilly_pajamas_and_suits__condition_0_0();
            SCENE_INLINE void a4_lilly_correct_procedure__condition_0_0();
            SCENE_INLINE void a4_lilly_out_and_about__condition_0_0();
            SCENE_INLINE void a4_lilly_a_mornings_reverse__condition_0_0();
            SCENE_INLINE void a4_lilly_blackout__condition_0_0();
            SCENE_INLINE void a4_lilly_context__condition_0_0();
            SCENE_INLINE void a4_lilly_a_faraway_future__condition_0_0();
            SCENE_INLINE void a4_lilly_farewell__condition_0_0();
            SCENE_INLINE void a4_lilly__condition_0_0();
            SCENE_INLINE void a4_lilly_false_cadence__condition_0_0();
            SCENE_INLINE void a4_lilly_under_a_maudlin_sky__condition_0_0();
            SCENE_INLINE void a4_lilly_under_a_bright_sky__condition_0_0();
            SCENE_INLINE void a4_lilly_forwards__condition_0_0();
    };
}

#endif // KS_SCRIPT_A4_LILLY