#ifndef KS_SCRIPT_A1_SATURDAY
#define KS_SCRIPT_A1_SATURDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/muto.h"
#include "smart_characters/hanako.h"
#include "smart_characters/lilly.h"
#include "smart_characters/emi.h"
#include "smart_characters/rin.h"
#include "smart_characters/nomiya.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/akira.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_dormext_half.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_classroomart.h"
#include "background_metas/mural.h"
#include "background_metas/school_dormext_half_ss.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/misc_sky.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/shizu_shanghai.h"
#include "background_metas/shizu_shanghai_normallaugh.h"
#include "background_metas/shizu_shanghai_smirklaugh.h"
#include "background_metas/shizu_shanghai_smirknormal.h"
#include "background_metas/shizu_shanghai_borednormal.h"
#include "background_metas/shizu_shanghai_boredlaugh.h"
#include "background_metas/suburb_shanghaiext.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/school_council.h"
#include "background_metas/school_council_ss.h"
#include "background_metas/school_council_ni.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/school_library.h"
#include "background_metas/hana_library_read.h"
#include "background_metas/hana_library.h"
#include "background_metas/school_library_ss.h"
#include "background_metas/school_dormext_full_ni.h"
#include "background_metas/school_gate.h"
#include "background_metas/suburb_park.h"
#include "background_metas/school_gate_ni.h"
#include "background_metas/school_courtyard_ni.h"
namespace ks {
    class ScriptA1Saturday {
        public:
            virtual ~ScriptA1Saturday() = default;
            // Labels
            SCENE_INLINE void a1_saturday_support();
            SCENE_INLINE void a1_saturday_an_asethetics();
            SCENE_INLINE void a1_saturday_creative_pain();
            SCENE_INLINE void a1_saturday_proper_exercise();
            SCENE_INLINE void a1_saturday_sip_p2();
            SCENE_INLINE void a1_saturday_shanghaied();
            SCENE_INLINE void a1_saturday_quiet();
            static void a1_saturday();
            SCENE_INLINE void a1c14o1();
            SCENE_INLINE void a1c14o2();
            // Choice functions
            SCENE_INLINE void a1_saturday_creative_pain__menu_question_0();
            SCENE_INLINE void a1_saturday_creative_pain__menu_question_0_i_just_kinda_stuck_with_her_i_think();
            SCENE_INLINE void a1_saturday_creative_pain__menu_question_0_im_interested_in_the_art_club();
            SCENE_INLINE void a1_saturday_sip_p2__menu_question_0();
            SCENE_INLINE void a1_saturday_sip_p2__menu_question_0_go_for_a_walk_into_town();
            SCENE_INLINE void a1_saturday_sip_p2__menu_question_0_go_to_the_library();
            // Conditions
            SCENE_INLINE void a1_saturday__condition_0__condition_0__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_0__condition_0__condition_0_1();
            SCENE_INLINE void a1_saturday__condition_0__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_0__condition_0_1();
            SCENE_INLINE void a1_saturday__condition_0__condition_0_2();
            SCENE_INLINE void a1_saturday__condition_0__condition_0_3();
            SCENE_INLINE void a1_saturday__condition_0_0();
            SCENE_INLINE void a1_saturday_support__condition_0_0();
            SCENE_INLINE void a1_saturday_support__condition_0_1();
            SCENE_INLINE void a1_saturday_support__condition_1_0();
            SCENE_INLINE void a1_saturday_support__condition_2_0();
            SCENE_INLINE void a1_saturday__condition_1_0();
            SCENE_INLINE void a1_saturday__condition_2_0();
            SCENE_INLINE void a1_saturday_an_asethetics__condition_0_0();
            SCENE_INLINE void a1_saturday_an_asethetics__condition_1_0();
            SCENE_INLINE void a1_saturday__condition_3_0();
            SCENE_INLINE void a1_saturday_creative_pain__condition_0_0();
            SCENE_INLINE void a1_saturday_creative_pain__condition_1_0();
            SCENE_INLINE void a1_saturday__condition_4_0();
            SCENE_INLINE void a1_saturday_proper_exercise__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_5_0();
            SCENE_INLINE void a1_saturday_sip_p2__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_6_0();
            SCENE_INLINE void a1_saturday_shanghaied__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_7_0();
            SCENE_INLINE void a1_saturday_quiet__condition_0_0();
            SCENE_INLINE void a1_saturday__condition_8_0();
    };
}

#endif // KS_SCRIPT_A1_SATURDAY