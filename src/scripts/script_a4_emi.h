#ifndef KS_SCRIPT_A4_EMI
#define KS_SCRIPT_A4_EMI

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/nurse.h"
#include "smart_characters/emi.h"
#include "smart_characters/rin.h"
#include "smart_characters/meiko.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_track.h"
#include "background_metas/school_track_on.h"
#include "background_metas/school_track_running.h"
#include "background_metas/school_nurseoffice.h"
#include "background_metas/school_nursehall.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_staircase1.h"
#include "background_metas/school_roof.h"
#include "background_metas/school_gate.h"
#include "background_metas/city_street4.h"
#include "background_metas/emi_houseext.h"
#include "background_metas/emi_dining.h"
#include "background_metas/city_graveyard.h"
#include "background_metas/emi_grave.h"
#include "background_metas/emi_cry_down.h"
#include "background_metas/school_gate_ss.h"
#include "background_metas/school_dormext_full_ss.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/school_dormemi.h"
#include "background_metas/emi_miss_closed.h"
#include "background_metas/emi_miss_open.h"
#include "background_metas/emi_ending_smile.h"
#include "background_metas/emi_ending_serious.h"
#include "background_metas/emi_ending_glad.h"
namespace ks {
    class ScriptA4Emi {
        public:
            virtual ~ScriptA4Emi() = default;
            // Labels
            SCENE_INLINE void a4_emi_a_swing_and_a_miss();
            SCENE_INLINE void a4_emi_saving_throw();
            SCENE_INLINE void a4_emi_whispers_of_the_past();
            SCENE_INLINE void a4_emi_hooray_for_socks();
            SCENE_INLINE void a4_emi_clean_teeth();
            static void a4_emi();
            // Choice functions
            // Conditions
            SCENE_INLINE void a4_emi_a_swing_and_a_miss__condition_0_0();
            SCENE_INLINE void a4_emi_saving_throw__condition_0_0();
            SCENE_INLINE void a4_emi__condition_0_0();
            SCENE_INLINE void a4_emi_whispers_of_the_past__condition_0_0();
            SCENE_INLINE void a4_emi_whispers_of_the_past__condition_1_0();
            SCENE_INLINE void a4_emi_whispers_of_the_past__condition_1_1();
            SCENE_INLINE void a4_emi_whispers_of_the_past__condition_2_0();
            SCENE_INLINE void a4_emi_hooray_for_socks__condition_0_0();
            SCENE_INLINE void a4_emi_clean_teeth__condition_0_0();
    };
}

#endif // KS_SCRIPT_A4_EMI