#ifndef KS_SCRIPT_A3_LILLY
#define KS_SCRIPT_A3_LILLY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/muto.h"
#include "smart_characters/hanako.h"
#include "smart_characters/misha.h"
#include "smart_characters/shizu.h"
#include "smart_characters/kenji.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/akira.h"
#include "smart_characters/lilly.h"
#include "background_metas/misc_sky.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_dormhisao_blurred.h"
#include "background_metas/school_library_ss.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_dormhisao_blurred_ss.h"
#include "background_metas/hosp_ext.h"
#include "background_metas/city_station.h"
#include "background_metas/lilly_trainride.h"
#include "background_metas/lilly_trainride_smiles.h"
#include "background_metas/hok_houseext.h"
#include "background_metas/hok_lounge.h"
#include "background_metas/hok_kitchen.h"
#include "background_metas/hok_lounge_ni.h"
#include "background_metas/hok_bath.h"
#include "background_metas/hok_road.h"
#include "background_metas/hok_wheat.h"
#include "background_metas/lilly_wheat_large.h"
#include "background_metas/lilly_wheat_small.h"
#include "background_metas/lilly_hcg_handjob_chest_normal.h"
#include "background_metas/lilly_hcg_handjob_chest_frown.h"
#include "background_metas/lilly_hcg_handjob_stroke_normopen.h"
#include "background_metas/lilly_hcg_handjob_stroke_normshut_small.h"
#include "background_metas/lilly_hcg_handjob_stroke_flustopen_small.h"
#include "background_metas/lilly_hcg_handjob_stroke_normopen_small.h"
#include "background_metas/lilly_hcg_cowgirl_smile_small.h"
#include "background_metas/lilly_hcg_cowgirl_weaksmile_small.h"
#include "background_metas/lilly_hcg_cowgirl_strain_small.h"
#include "background_metas/lilly_hcg_cowgirl_frown_small.h"
#include "background_metas/lilly_hcg_cowgirl_cry_small.h"
#include "background_metas/lilly_hcg_bath_smile_small.h"
#include "background_metas/lilly_hcg_bath_emb_small.h"
#include "background_metas/lilly_hcg_bath_open_small.h"
#include "background_metas/lilly_hcg_bath_grab_small.h"
#include "background_metas/lilly_hcg_bath_moan_small.h"
#include "background_metas/lilly_hcg_afterbath_open_small.h"
#include "background_metas/lilly_hcg_afterbath_shut_small.h"
#include "background_metas/lilly_trainride_ni.h"
namespace ks {
    class ScriptA3Lilly {
        public:
            virtual ~ScriptA3Lilly() = default;
            // Labels
            SCENE_INLINE void a3_lilly_day_by_day();
            SCENE_INLINE void a3_lilly_minor_discord();
            SCENE_INLINE void a3_lilly_dissonance();
            SCENE_INLINE void a3_lilly_a_world_away();
            SCENE_INLINE void a3_lilly_renewal();
            SCENE_INLINE void a3_lilly_northern_sojourn();
            SCENE_INLINE void a3_lilly_prelude();
            SCENE_INLINE void a3_lilly_crescendo();
            SCENE_INLINE void a3_lilly_diminuendo();
            SCENE_INLINE void a3_lilly_gray_outlook();
            SCENE_INLINE void a3_lilly_rhapsody_in_blue();
            SCENE_INLINE void a3_lilly_the_momentary_present();
            static void a3_lilly();
            SCENE_INLINE void a3lc1o1();
            SCENE_INLINE void a3lc1o2();
            SCENE_INLINE void a3lc2o1();
            SCENE_INLINE void a3lc2o2();
            SCENE_INLINE void a3lc3o1();
            SCENE_INLINE void a3lc3o2();
            SCENE_INLINE void a3lc4o1();
            SCENE_INLINE void a3lc4o2();
            // Choice functions
            SCENE_INLINE void a3_lilly_minor_discord__menu_question_0();
            SCENE_INLINE void a3_lilly_minor_discord__menu_question_0_humor_him();
            SCENE_INLINE void a3_lilly_minor_discord__menu_question_0_ignore_his_insane_ramblings();
            SCENE_INLINE void a3_lilly_minor_discord__menu_question_1();
            SCENE_INLINE void a3_lilly_minor_discord__menu_question_1_ask_about_hanako();
            SCENE_INLINE void a3_lilly_minor_discord__menu_question_1_keep_it_to_myself();
            SCENE_INLINE void a3_lilly_prelude__menu_question_0();
            SCENE_INLINE void a3_lilly_prelude__menu_question_0_address_it();
            SCENE_INLINE void a3_lilly_prelude__menu_question_0_wave_her_off();
            SCENE_INLINE void a3_lilly_the_momentary_present__menu_question_0();
            SCENE_INLINE void a3_lilly_the_momentary_present__menu_question_0_talk_about_hanako();
            SCENE_INLINE void a3_lilly_the_momentary_present__menu_question_0_talk_about_school();
            // Conditions
            SCENE_INLINE void a3_lilly_day_by_day__condition_0_0();
            SCENE_INLINE void a3_lilly_minor_discord__condition_0_0();
            SCENE_INLINE void a3_lilly_dissonance__condition_0_0();
            SCENE_INLINE void a3_lilly_a_world_away__condition_0_0();
            SCENE_INLINE void a3_lilly_renewal__condition_0_0();
            SCENE_INLINE void a3_lilly_northern_sojourn__condition_0_0();
            SCENE_INLINE void a3_lilly_prelude__condition_0_0();
            SCENE_INLINE void a3_lilly_crescendo__condition_0_0();
            SCENE_INLINE void a3_lilly_diminuendo__condition_0_0();
            SCENE_INLINE void a3_lilly_gray_outlook__condition_0_0();
            SCENE_INLINE void a3_lilly_rhapsody_in_blue__condition_0_0();
            SCENE_INLINE void a3_lilly_the_momentary_present__condition_0_0();
    };
}

#endif // KS_SCRIPT_A3_LILLY