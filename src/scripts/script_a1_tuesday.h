#ifndef KS_SCRIPT_A1_TUESDAY
#define KS_SCRIPT_A1_TUESDAY

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/hanako.h"
#include "smart_characters/lilly.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/kenji.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_council.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/lilly_tearoom.h"
#include "background_metas/lilly_tearoom_open.h"
#include "background_metas/school_miyagi.h"
#include "background_metas/tearoom_lillyhisao_noon.h"
#include "background_metas/tearoom_lillyhisao_sunset.h"
#include "background_metas/school_miyagi_ss.h"
#include "background_metas/school_library_ss.h"
#include "background_metas/hana_library_read.h"
#include "background_metas/hana_library_gasp.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/hana_library.h"
namespace ks {
    class ScriptA1Tuesday {
        public:
            virtual ~ScriptA1Tuesday() = default;
            // Labels
            SCENE_INLINE void a1_tuesday_smalltalk();
            SCENE_INLINE void a1_tuesday_risk_vs_reward();
            SCENE_INLINE void a1_tuesday_pseudo_tea_cosy();
            SCENE_INLINE void a1_tuesday_shared_library();
            SCENE_INLINE void a1_tuesday_bizarre_and_surreal();
            static void a1_tuesday();
            SCENE_INLINE void a1c3o1();
            SCENE_INLINE void a1c3o2();
            SCENE_INLINE void a1c4o1();
            SCENE_INLINE void a1c4o2();
            SCENE_INLINE void a1c5o1();
            SCENE_INLINE void a1c5o2();
            // Choice functions
            SCENE_INLINE void a1_tuesday_risk_vs_reward__menu_question_0();
            SCENE_INLINE void a1_tuesday_risk_vs_reward__menu_question_0_she_has_a_point_attack_aggressively();
            SCENE_INLINE void a1_tuesday_risk_vs_reward__menu_question_0_its_a_trap_its_smarter_to_play_defensively_here();
            SCENE_INLINE void a1_tuesday_shared_library__menu_question_0();
            SCENE_INLINE void a1_tuesday_shared_library__menu_question_0_hi_im_new_here_hisao_nakai_were_in_the_same_class();
            SCENE_INLINE void a1_tuesday_shared_library__menu_question_0_im_sorry_i_didnt_mean_to_startle_you();
            SCENE_INLINE void a1_tuesday_bizarre_and_surreal__menu_question_0();
            SCENE_INLINE void a1_tuesday_bizarre_and_surreal__menu_question_0_she_was_cute();
            SCENE_INLINE void a1_tuesday_bizarre_and_surreal__menu_question_0_she_wasnt_cute();
            // Conditions
            SCENE_INLINE void a1_tuesday_smalltalk__condition_0_0();
            SCENE_INLINE void a1_tuesday_risk_vs_reward__condition_0_0();
            SCENE_INLINE void a1_tuesday_pseudo_tea_cosy__condition_0_0();
            SCENE_INLINE void a1_tuesday_shared_library__condition_0_0();
            SCENE_INLINE void a1_tuesday_shared_library__condition_0_1();
            SCENE_INLINE void a1_tuesday_shared_library__condition_1_0();
            SCENE_INLINE void a1_tuesday_bizarre_and_surreal__condition_0_0();
            SCENE_INLINE void a1c4o1__condition_0_0();
    };
}

#endif // KS_SCRIPT_A1_TUESDAY