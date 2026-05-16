#ifndef KS_SCRIPT_A3_HANAKO
#define KS_SCRIPT_A3_HANAKO

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/hanako.h"
#include "smart_characters/lilly.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/miki.h"
#include "smart_characters/shopkeep.h"
#include "smart_characters/muto.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/nurse.h"
#include "smart_characters/akira.h"
#include "background_metas/school_miyagi_ss.h"
#include "background_metas/school_hallway2.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/school_dormext_full_ni.h"
#include "background_metas/school_track.h"
#include "background_metas/school_gardens.h"
#include "background_metas/misc_sky.h"
#include "background_metas/school_gate.h"
#include "background_metas/school_road.h"
#include "background_metas/city_street1.h"
#include "background_metas/city_karaokeint.h"
#include "background_metas/city_street2.h"
#include "background_metas/city_street3.h"
#include "background_metas/city_street4.h"
#include "background_metas/city_othello.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/hanako_breakdown_down.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_nurseoffice.h"
#include "background_metas/school_nursehall.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_dormhisao_blurred_ss.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/school_dormlilly.h"
#include "background_metas/school_dormhanako.h"
#include "background_metas/hanako_cry_closed.h"
#include "background_metas/hanako_cry_away.h"
#include "background_metas/hanako_cry_open.h"
#include "background_metas/lilly_bedroom.h"
#include "background_metas/lilly_bedroom_large.h"
#include "background_metas/hanako_presents2.h"
#include "background_metas/lilly_hanako_hug.h"
#include "background_metas/hanako_dolls.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_gardens2.h"
#include "background_metas/city_street2_ni.h"
#include "background_metas/city_street3_ni.h"
#include "background_metas/city_karaokeext.h"
#include "background_metas/city_clubint.h"
#include "background_metas/city_clubpool.h"
#include "background_metas/hanako_billiards_break.h"
#include "background_metas/hanako_billiards_smile.h"
#include "background_metas/hanako_billiards_smile_close.h"
#include "background_metas/hanako_billiards_serious.h"
#include "background_metas/hanako_billiards_distant.h"
#include "background_metas/hanako_billiards_timid.h"
#include "background_metas/school_dormext_full.h"
namespace ks {
    class ScriptA3Hanako {
        public:
            virtual ~ScriptA3Hanako() = default;
            // Labels
            SCENE_INLINE void a3_hanako_invitation();
            SCENE_INLINE void a3_hanako_shady_encounter();
            SCENE_INLINE void a3_hanako_antiques_and_pie();
            SCENE_INLINE void a3_hanako_falling();
            SCENE_INLINE void a3_hanako_treading_softly();
            SCENE_INLINE void a3_hanako_reaching_out();
            SCENE_INLINE void a3_hanako_one_more_year();
            SCENE_INLINE void a3_hanako_one_piece_of_paper();
            SCENE_INLINE void a3_hanako_stripes_and_solids();
            SCENE_INLINE void a3_hanako_beginning_of_the_end();
            static void a3_hanako();
            SCENE_INLINE void a3hc1o1();
            SCENE_INLINE void a3hc1o2();
            SCENE_INLINE void a3hc2o1();
            SCENE_INLINE void a3hc2o2();
            // Choice functions
            SCENE_INLINE void a3_hanako_shady_encounter__menu_question_0();
            SCENE_INLINE void a3_hanako_shady_encounter__menu_question_0_admit_it();
            SCENE_INLINE void a3_hanako_shady_encounter__menu_question_0_deny_it();
            SCENE_INLINE void a3_hanako_beginning_of_the_end__menu_question_0();
            SCENE_INLINE void a3_hanako_beginning_of_the_end__menu_question_0_do_you_want_to_go_into_the_city();
            SCENE_INLINE void a3_hanako_beginning_of_the_end__menu_question_0_how_about_we_call_it_a_day();
            // Conditions
            SCENE_INLINE void a3_hanako_invitation__condition_0_0();
            SCENE_INLINE void a3_hanako_shady_encounter__condition_0_0();
            SCENE_INLINE void a3_hanako_antiques_and_pie__condition_0_0();
            SCENE_INLINE void a3_hanako_falling__condition_0_0();
            SCENE_INLINE void a3_hanako_treading_softly__condition_0_0();
            SCENE_INLINE void a3_hanako_reaching_out__condition_0_0();
            SCENE_INLINE void a3_hanako_one_more_year__condition_0_0();
            SCENE_INLINE void a3_hanako_one_piece_of_paper__condition_0_0();
            SCENE_INLINE void a3_hanako_stripes_and_solids__condition_0_0();
            SCENE_INLINE void a3_hanako_beginning_of_the_end__condition_0_0();
    };
}

#endif // KS_SCRIPT_A3_HANAKO