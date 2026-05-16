#ifndef KS_SCRIPT_A4_HANAKO
#define KS_SCRIPT_A4_HANAKO

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "smart_characters/shizu.h"
#include "smart_characters/misha.h"
#include "smart_characters/kenji.h"
#include "smart_characters/hanako.h"
#include "smart_characters/miki.h"
#include "smart_characters/yuuko.h"
#include "smart_characters/muto.h"
#include "background_metas/school_scienceroom.h"
#include "background_metas/hanako_emptyclassroom_bg.h"
#include "background_metas/school_cafeteria.h"
#include "background_metas/school_dormhallway.h"
#include "background_metas/school_dormhanako.h"
#include "background_metas/school_dormhisao_ni.h"
#include "background_metas/school_dormhisao.h"
#include "background_metas/school_dormhisao_blurred.h"
#include "background_metas/hanako_rage.h"
#include "background_metas/hanako_rage_sad.h"
#include "background_metas/school_girlsdormhall.h"
#include "background_metas/suburb_shanghaiint.h"
#include "background_metas/hisao_letter_open.h"
#include "background_metas/school_dormhisao_ss.h"
#include "background_metas/school_library.h"
#include "background_metas/hanako_eye.h"
#include "background_metas/hisao_scar_large.h"
#include "background_metas/hisao_scar.h"
#include "background_metas/city_street1.h"
#include "background_metas/city_street1_blurred.h"
#include "background_metas/misc_sky.h"
#include "background_metas/city_karaokeint.h"
#include "background_metas/city_street2.h"
#include "background_metas/school_library_ss.h"
#include "background_metas/school_hallway3.h"
#include "background_metas/school_staircase2.h"
#include "background_metas/school_lobby.h"
#include "background_metas/school_courtyard_ss.h"
#include "background_metas/school_gardens.h"
#include "background_metas/school_dormhallground.h"
#include "background_metas/hanako_scars.h"
#include "background_metas/hanako_scars_large.h"
#include "background_metas/hanako_bed_boobs_glance.h"
#include "background_metas/hanako_bed_boobs_blush.h"
#include "background_metas/hanako_bed_crotch_blush.h"
#include "background_metas/hanako_bed_crotch_glance.h"
#include "background_metas/hanako_missionary_underwear.h"
#include "background_metas/hanako_missionary_closed.h"
#include "background_metas/hanako_missionary_open.h"
#include "background_metas/hanako_missionary_clench.h"
#include "background_metas/hanako_after_worry.h"
#include "background_metas/hanako_after_smile.h"
#include "background_metas/suburb_park.h"
#include "background_metas/hanako_park_alone.h"
#include "background_metas/hanako_park_away.h"
#include "background_metas/hanako_park_look.h"
#include "background_metas/hanako_park_closed.h"
#include "background_metas/suburb_roadcenter.h"
#include "background_metas/hanako_goodend_close.h"
#include "background_metas/hanako_goodend.h"
namespace ks {
    class ScriptA4Hanako {
        public:
            virtual ~ScriptA4Hanako() = default;
            // Labels
            SCENE_INLINE void a4_hanako_truancy();
            SCENE_INLINE void a4_hanako_faraway_presence();
            SCENE_INLINE void a4_hanako_misstep();
            SCENE_INLINE void a4_hanako_cut_petals();
            SCENE_INLINE void a4_hanako_continuing_melody();
            SCENE_INLINE void a4_hanako_shanghai_studiousness();
            SCENE_INLINE void a4_hanako_his_past();
            SCENE_INLINE void a4_hanako_city_rendezvous();
            SCENE_INLINE void a4_hanako_whispered_touch();
            SCENE_INLINE void a4_hanako_indeterminate_future();
            SCENE_INLINE void a4_hanako_adulthood();
            static void a4_hanako();
            // Choice functions
            SCENE_INLINE void a4_hanako_faraway_presence__menu_question_0();
            SCENE_INLINE void a4_hanako_faraway_presence__menu_question_0_agree_with_lilly();
            SCENE_INLINE void a4_hanako_faraway_presence__menu_question_0_trust_my_own_judgment();
            // Conditions
            SCENE_INLINE void a4_hanako_truancy__condition_0_0();
            SCENE_INLINE void a4_hanako_faraway_presence__condition_0_0();
            SCENE_INLINE void a4_hanako_faraway_presence__condition_0_1();
            SCENE_INLINE void a4_hanako_faraway_presence__condition_0_2();
            SCENE_INLINE void a4_hanako_faraway_presence__condition_1_0();
            SCENE_INLINE void a4_hanako_misstep__condition_0_0();
            SCENE_INLINE void a4_hanako__condition_0_0();
            SCENE_INLINE void a4_hanako_cut_petals__condition_0_0();
            SCENE_INLINE void a4_hanako__condition_1_0();
            SCENE_INLINE void a4_hanako__condition_2_0();
            SCENE_INLINE void a4_hanako_continuing_melody__condition_0_0();
            SCENE_INLINE void a4_hanako_continuing_melody__condition_1_0();
            SCENE_INLINE void a4_hanako_shanghai_studiousness__condition_0_0();
            SCENE_INLINE void a4_hanako_his_past__condition_0_0();
            SCENE_INLINE void a4_hanako_city_rendezvous__condition_0_0();
            SCENE_INLINE void a4_hanako_whispered_touch__condition_0__condition_0_0();
            SCENE_INLINE void a4_hanako_whispered_touch__condition_0_0();
            SCENE_INLINE void a4_hanako_whispered_touch__condition_1_0();
            SCENE_INLINE void a4_hanako_indeterminate_future__condition_0_0();
            SCENE_INLINE void a4_hanako_adulthood__condition_0_0();
    };
}

#endif // KS_SCRIPT_A4_HANAKO