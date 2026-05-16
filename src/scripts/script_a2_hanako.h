#ifndef KS_SCRIPT_A2_HANAKO
#define KS_SCRIPT_A2_HANAKO

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/misha.h"
#include "smart_characters/shizu.h"
#include "smart_characters/hanako.h"
#include "smart_characters/lilly.h"
#include "smart_characters/muto.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/kenji.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/school_gate.h"
#include "background_metas/school_road.h"
#include "background_metas/suburb_konbiniext.h"
#include "background_metas/suburb_konbiniint.h"
#include "background_metas/suburb_konbiniext_ss.h"
#include "background_metas/school_road_ss.h"
#include "background_metas/school_dormext_full_ss.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_miyagi.h"
#include "background_metas/misc_sky.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_council.h"
#include "background_metas/school_library.h"
#include "background_metas/hana_library_read.h"
#include "background_metas/school_library_ss.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/lilly_bedroom.h"
#include "background_metas/lilly_bedroom_large.h"
#include "background_metas/school_dormlilly.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/hana_library_smile.h"
#include "background_metas/hana_library.h"
#include "background_metas/hanako_crayon1.h"
#include "background_metas/hanako_crayon2.h"
namespace ks {
    class ScriptA2Hanako {
        public:
            virtual ~ScriptA2Hanako() = default;
            // Labels
            SCENE_INLINE void a2_hanako_to_town_to_town();
            SCENE_INLINE void a2_hanako_tea_leaves();
            SCENE_INLINE void a2_hanako_office_confessional();
            SCENE_INLINE void a2_hanako_chess_and_slides();
            SCENE_INLINE void a2_hanako_rise_and_shine();
            SCENE_INLINE void a2_hanako_mad_hatter();
            SCENE_INLINE void a2_hanako_small_change();
            SCENE_INLINE void a2_hanako_absenteeism();
            SCENE_INLINE void a2_hanako_equivalent_exchange();
            static void a2_hanako();
            // Choice functions
            SCENE_INLINE void a2_hanako__menu_question_0();
            SCENE_INLINE void a2_hanako__menu_question_0_what_do_you_think_hanako();
            SCENE_INLINE void a2_hanako__menu_question_0_ive_done_enough_work_for_the_council_already();
            // Conditions
            SCENE_INLINE void a2_hanako_to_town_to_town__condition_0_0();
            SCENE_INLINE void a2_hanako_tea_leaves__condition_0_0();
            SCENE_INLINE void a2_hanako_office_confessional__condition_0_0();
            SCENE_INLINE void a2_hanako__condition_0_0();
            SCENE_INLINE void a2_hanako_chess_and_slides__condition_0_0();
            SCENE_INLINE void a2_hanako__condition_1_0();
            SCENE_INLINE void a2_hanako_rise_and_shine__condition_0_0();
            SCENE_INLINE void a2_hanako_mad_hatter__condition_0_0();
            SCENE_INLINE void a2_hanako_mad_hatter__condition_0_1();
            SCENE_INLINE void a2_hanako_mad_hatter__condition_1_0();
            SCENE_INLINE void a2_hanako_small_change__condition_0_0();
            SCENE_INLINE void a2_hanako_absenteeism__condition_0_0();
            SCENE_INLINE void a2_hanako_equivalent_exchange__condition_0_0();
    };
}

#endif // KS_SCRIPT_A2_HANAKO