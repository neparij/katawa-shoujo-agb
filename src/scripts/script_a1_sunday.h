#ifndef KS_SCRIPT_A1_SUNDAY
#define KS_SCRIPT_A1_SUNDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/kenji.h"
#include "smart_characters/emi.h"
#include "smart_characters/rin.h"
#include "smart_characters/lilly.h"
#include "smart_characters/hanako.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_courtyard.h"
#include "background_metas/school_stalls1.h"
#include "background_metas/school_dormext_full.h"
#include "background_metas/mural.h"
#include "background_metas/school_gardens.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/misc_sky_ss.h"
#include "background_metas/school_dormext_full_ss.h"
#include "background_metas/misc_sky_ni.h"
#include "background_metas/school_dormext_full_ni.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/hana_library_read.h"
#include "background_metas/school_library.h"
#include "background_metas/school_stalls1_ni.h"
#include "background_metas/school_gardens2_ni.h"
#include "background_metas/school_stalls2.h"
#include "background_metas/school_miyagi.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_gate_ss.h"
#include "background_metas/school_road_ss.h"
#include "background_metas/suburb_shanghaiext.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/suburb_shanghaiext_ni.h"
#include "background_metas/suburb_roadcenter_ni.h"
#include "background_metas/school_stalls1_ss.h"
#include "background_metas/school_courtyard_ss.h"
#include "background_metas/school_stalls2_ss.h"
#include "background_metas/school_courtyard_ni.h"
#include "background_metas/school_roof_ni.h"
#include "background_metas/misc_sky.h"
#include "background_metas/school_staircase1.h"
#include "background_metas/school_roof.h"
#include "background_metas/kenji_rooftop.h"
#include "../events/nightsky_fireworks.cpp.h"
#include "../events/hanako_fireworks.cpp.h"
namespace ks {
    class ScriptA1Sunday {
        public:
            virtual ~ScriptA1Sunday() = default;
            // Labels
            SCENE_INLINE void a1_sunday_dont_panic();
            SCENE_INLINE void a1_sunday_is_carnival();
            SCENE_INLINE void a1_sunday_clouds_in_my_head();
            SCENE_INLINE void a1_sunday_promise_of_time();
            SCENE_INLINE void a1_sunday_nc5xb3();
            SCENE_INLINE void a1_sunday_movement();
            SCENE_INLINE void a1_sunday_throwing_balls();
            SCENE_INLINE void a1_sunday_the_deep_end();
            static void a1_sunday();
            SCENE_INLINE void stranger_lilly_and_hanako();
            SCENE_INLINE void stranger_union();
            SCENE_INLINE void lilly_and_hanako_union();
            // Choice functions
            // Conditions
            SCENE_INLINE void a1_sunday__condition_0_0();
            SCENE_INLINE void a1_sunday_dont_panic__condition_0_0();
            SCENE_INLINE void a1_sunday_is_carnival__condition_0_0();
            SCENE_INLINE void a1_sunday__condition_1_0();
            SCENE_INLINE void a1_sunday_clouds_in_my_head__condition_0_0();
            SCENE_INLINE void a1_sunday__condition_2_0();
            SCENE_INLINE void a1_sunday_promise_of_time__condition_0_0();
            SCENE_INLINE void a1_sunday__condition_3_0();
            SCENE_INLINE void a1_sunday_nc5xb3__condition_0_0();
            SCENE_INLINE void a1_sunday_movement__condition_0_0();
            SCENE_INLINE void a1_sunday__condition_4_0();
            SCENE_INLINE void a1_sunday_throwing_balls__condition_0_0();
            SCENE_INLINE void a1_sunday__condition_5_0();
            SCENE_INLINE void a1_sunday_the_deep_end__condition_0_0();
            SCENE_INLINE void a1_sunday__condition_6_0();
    };
}

#endif // KS_SCRIPT_A1_SUNDAY