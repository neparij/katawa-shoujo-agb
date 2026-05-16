#ifndef KS_SCRIPT_A2_EMI
#define KS_SCRIPT_A2_EMI

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/emi.h"
#include "smart_characters/rin.h"
#include "smart_characters/misha.h"
#include "smart_characters/nurse.h"
#include "smart_characters/meiko.h"
#include "smart_characters/shizu.h"
#include "smart_characters/kenji.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/lilly.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_track.h"
#include "background_metas/school_track_on.h"
#include "background_metas/school_track_running.h"
#include "background_metas/emi_run_face.h"
#include "background_metas/school_dormbathroom.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_staircase1.h"
#include "background_metas/school_roof.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/school_courtyard_ni.h"
#include "background_metas/school_track_ni.h"
#include "background_metas/school_nurseoffice.h"
#include "background_metas/school_nursehall.h"
#include "background_metas/emitrack_blocks.h"
#include "background_metas/emitrack_blocks_close.h"
#include "background_metas/emitrack_running.h"
#include "background_metas/emitrack_finishtop.h"
#include "background_metas/emitrack_blocks_close_grin.h"
#include "background_metas/emitrack_finish.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/hisao_letter_closed.h"
#include "background_metas/hisao_letter_open.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/school_gate.h"
#include "background_metas/school_road.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/suburb_park.h"
#include "background_metas/picnic_normal.h"
#include "background_metas/picnic_rain.h"
#include "background_metas/suburb_shanghaiext.h"
#include "background_metas/school_dormext_full.h"
#include "background_metas/school_library.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/emi_sleepy_face.h"
#include "background_metas/emi_sleepy_legs.h"
#include "background_metas/emi_sleepy.h"
#include "background_metas/school_dormemi.h"
#include "background_metas/emi_bed_normal_f.h"
#include "background_metas/emi_bed_unsure.h"
#include "background_metas/emi_bed_happy.h"
#include "background_metas/emi_bed_normal.h"
#include "background_metas/emi_bed_frown.h"
#include "background_metas/emi_bed_smile.h"
#include "background_metas/emi_sleep_unsure.h"
#include "background_metas/emi_sleep_normal.h"
#include "background_metas/emi_sleep_weep.h"
#include "background_metas/emi_sleep_cry.h"
#include "background_metas/emi_firstkiss.h"
#include "background_metas/suburb_shanghaiint.h"
namespace ks {
    class ScriptA2Emi {
        public:
            virtual ~ScriptA2Emi() = default;
            // Labels
            SCENE_INLINE void a2_emi_morning_run();
            SCENE_INLINE void a2_emi_clouds_time_travel_and_thou();
            SCENE_INLINE void a2_emi_questions_that_need_answering();
            SCENE_INLINE void a2_emi_second_times_the_worst();
            SCENE_INLINE void a2_emi_an_apple_a_day();
            SCENE_INLINE void a2_emi_track_meeting();
            SCENE_INLINE void a2_emi_down_that_medicine_now();
            SCENE_INLINE void a2_emi_piracy_on_the_high_seas();
            SCENE_INLINE void a2_emi_famous_last_words();
            SCENE_INLINE void a2_emi_tracking_absences();
            SCENE_INLINE void a2_emi_dropping_by();
            SCENE_INLINE void a2_emi_the_first_morning_after();
            SCENE_INLINE void a2_emi_the_real_beginning();
            static void a2_emi();
            SCENE_INLINE void a2ec1o1();
            SCENE_INLINE void a2ec1o2();
            // Choice functions
            SCENE_INLINE void a2_emi_famous_last_words__menu_question_0();
            SCENE_INLINE void a2_emi_famous_last_words__menu_question_0_offer_to_run_with_emi();
            SCENE_INLINE void a2_emi_famous_last_words__menu_question_0_keep_quiet();
            // Conditions
            SCENE_INLINE void a2_emi_morning_run__condition_0_0();
            SCENE_INLINE void a2_emi_clouds_time_travel_and_thou__condition_0_0();
            SCENE_INLINE void a2_emi_questions_that_need_answering__condition_0_0();
            SCENE_INLINE void a2_emi_second_times_the_worst__condition_0_0();
            SCENE_INLINE void a2_emi_an_apple_a_day__condition_0_0();
            SCENE_INLINE void a2_emi_track_meeting__condition_0_0();
            SCENE_INLINE void a2_emi_down_that_medicine_now__condition_0_0();
            SCENE_INLINE void a2_emi_piracy_on_the_high_seas__condition_0_0();
            SCENE_INLINE void a2_emi_famous_last_words__condition_0_0();
            SCENE_INLINE void a2_emi_famous_last_words__condition_0_1();
            SCENE_INLINE void a2_emi_famous_last_words__condition_1_0();
            SCENE_INLINE void a2_emi_tracking_absences__condition_0_0();
            SCENE_INLINE void a2_emi_tracking_absences__condition_0_1();
            SCENE_INLINE void a2_emi_tracking_absences__condition_1_0();
            SCENE_INLINE void a2_emi_dropping_by__condition_0_0();
            SCENE_INLINE void a2_emi_the_first_morning_after__condition_0_0();
            SCENE_INLINE void a2_emi_the_real_beginning__condition_0_0();
    };
}

#endif // KS_SCRIPT_A2_EMI