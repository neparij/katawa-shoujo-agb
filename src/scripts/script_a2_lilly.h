#ifndef KS_SCRIPT_A2_LILLY
#define KS_SCRIPT_A2_LILLY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/hanako.h"
#include "smart_characters/lilly.h"
#include "smart_characters/kenji.h"
#include "smart_characters/akira.h"
#include "smart_characters/hideaki.h"
#include "smart_characters/shopkeep.h"
#include "smart_characters/emi.h"
#include "smart_characters/rin.h"
#include "smart_characters/muto.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_dormbathroom.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/school_miyagi.h"
#include "background_metas/tearoom_everyone_noon.h"
#include "background_metas/lilly_touch_uni.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_dormhallground.h"
#include "background_metas/school_dormext_full.h"
#include "background_metas/school_gardens.h"
#include "background_metas/school_library.h"
#include "background_metas/city_street1.h"
#include "background_metas/icecream.h"
#include "background_metas/city_street2.h"
#include "background_metas/city_street3.h"
#include "background_metas/city_othello.h"
#include "background_metas/city_karaokeint.h"
#include "background_metas/suburb_roadcenter_ni.h"
#include "background_metas/school_road_ni.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/lilly_bedroom.h"
#include "background_metas/lilly_bedroom_large.h"
#include "background_metas/school_dormlilly.h"
#include "background_metas/lilly_hanako_hug.h"
#include "background_metas/hanako_presents1.h"
#include "background_metas/braille.h"
#include "background_metas/lilly_sleeping.h"
#include "background_metas/lilly_sleeping_smile.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_gate_ss.h"
#include "background_metas/school_road_ss.h"
#include "background_metas/misc_sky_ss.h"
#include "background_metas/lilly_sunsetwalk_bg.h"
#include "background_metas/suburb_konbiniint.h"
#include "background_metas/suburb_konbiniext_ni.h"
#include "background_metas/school_dormhanako.h"
#include "background_metas/school_dormext_full_ni.h"
#include "background_metas/hisao_letter_open.h"
#include "background_metas/hisao_letter_open_2.h"
#include "background_metas/school_staircase1.h"
#include "background_metas/school_roof.h"
#include "background_metas/lilly_crane.h"
#include "background_metas/school_room32.h"
#include "background_metas/hosp_ext.h"
namespace ks {
    class ScriptA2Lilly {
        public:
            virtual ~ScriptA2Lilly() = default;
            // Labels
            SCENE_INLINE void a2_lilly_earl_grey();
            SCENE_INLINE void a2_lilly_a_pound_sterling();
            SCENE_INLINE void a2_lilly_presents_and_presence();
            SCENE_INLINE void a2_lilly_unidentified_drinking_object();
            SCENE_INLINE void a2_lilly_the_day_after();
            SCENE_INLINE void a2_lilly_a_brief_history_of_thyme();
            SCENE_INLINE void a2_lilly_little_wing();
            SCENE_INLINE void a2_lilly_bon_voyage();
            static void a2_lilly();
            SCENE_INLINE void a2lc1o1();
            SCENE_INLINE void a2lc1o2();
            // Choice functions
            SCENE_INLINE void a2_lilly_a_brief_history_of_thyme__menu_question_0();
            SCENE_INLINE void a2_lilly_a_brief_history_of_thyme__menu_question_0_avoid_the_subject();
            SCENE_INLINE void a2_lilly_a_brief_history_of_thyme__menu_question_0_tell_the_truth();
            // Conditions
            SCENE_INLINE void a2_lilly_earl_grey__condition_0_0();
            SCENE_INLINE void a2_lilly_a_pound_sterling__condition_0_0();
            SCENE_INLINE void a2_lilly_presents_and_presence__condition_0_0();
            SCENE_INLINE void a2_lilly_unidentified_drinking_object__condition_0_0();
            SCENE_INLINE void a2_lilly_the_day_after__condition_0_0();
            SCENE_INLINE void a2_lilly_a_brief_history_of_thyme__condition_0_0();
            SCENE_INLINE void a2_lilly_little_wing__condition_0_0();
            SCENE_INLINE void a2_lilly_bon_voyage__condition_0_0();
    };
}

#endif // KS_SCRIPT_A2_LILLY