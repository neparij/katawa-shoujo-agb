#include "translation.h"
#include "scripts/script_a1_monday_en.cpp"
#include "scripts/script_a1_tuesday_en.cpp"
#include "scripts/script_a1_wednesday_en.cpp"
#include "scripts/script_a1_thursday_en.cpp"

namespace ks {

class TranslationEn : public Translation {
public:
    language_t type() {
        return LANG_ENGLISH;
    }
    const char* language() {return screens_english();}

    void (*script_a1_monday())() { return &ScriptA1MondayEn::a1_monday; }
    void (*script_a1_tuesday())() { return &ScriptA1TuesdayEn::a1_tuesday; }
    void (*script_a1_wednesday())() { return &ScriptA1WednesdayEn::a1_wednesday; }
    void (*script_a1_thursday())() { return &ScriptA1ThursdayEn::a1_thursday; }

    const char* menu_author() {return "port by NeParij";}
    const char* menu_play_a0_test_scene() {return "Test Scene";}
    const char* menu_play_a1_monday() {return "Act 1. Monday";}
    const char* menu_play_a1_tuesday() {return "Act 1. Tuesday";}
    const char* menu_play_a1_wednesday() {return "Act 1. Wednesday";}
    const char* menu_play_a1_thursday() {return "Act 1. Thursday (beta)";}
    const char* menu_play_all() {return "Play all available";}
    const char* menu_video_test() {return "Video tests";}

    const char* menu_options_high_contrast() {return "High contrast";}
    const char* menu_options_hdisabled() {return "Disable adult content";}
    bn::array<char*, 4> menu_options_disable_disturbing_content() {
        return {"Skip hurtful adult scenes",};
    }
    const char* menu_options_language() {return "Language";}

    const char* menu_start() {return "Start";}
    const char* menu_saves() {return "Saves";}
    const char* menu_extras() {return "Extras";}
    const char* menu_options() {return "Options";}

    const char* menu_extras_jukebox() {return "Jukebox";}
    const char* menu_extras_gallery() {return "Gallery";}
    const char* menu_extras_library() {return "Library";}
    const char* menu_extras_cinema() {return "Cinema";}

    unsigned int menu_extras_jukebox_xoffset() {return 0;}
    unsigned int menu_extras_gallery_xoffset() {return 0;}
    unsigned int menu_extras_library_xoffset() {return 0;}
    unsigned int menu_extras_cinema_xoffset() {return 0;}
    unsigned int menu_extras_return_xoffset() {return 0;}

    const char* menu_back() {return "Back";}

    const char* screens_english() {return "English";}
    const char* screens_russian() {return "Russian";}

    const char* screens_return() {return "Return";}
    const char* screens_history() {return "History (n/a)";}
    const char* screens_options() {return "Options (n/a)";}
    const char* screens_saves_menu() {return "Saves";}
    const char* screens_main_menu() {return "Main menu";}

    const char* textbutton_save() {return "Save";}

    const char* screens_playtime() {return "Playtime";}
    const char* screens_current_scene() {return "Scene";}
    const char* screens_current_track() {return "Track";}

    // virtual char* script(script_t script) = 0;
    // virtual char* label(label_t label) = 0;
    const char* label(label_t label) override {
        switch (label) {
            case LABEL_A1_MONDAY_OUT_COLD: return "Out Cold";
            case LABEL_A1_MONDAY_BUNDLE_OF_HISAO: return "Bundle of Hisao";
            case LABEL_A1_MONDAY_GATEWAY_EFFECT: return "Gateway Effect";
            case LABEL_A1_MONDAY_ENTER_STAGE_LEFT: return "Enter Stage Left";
            case LABEL_A1_MONDAY_IN_THE_NURSERY: return "In the Nursery";
            case LABEL_A1_MONDAY_NOBODYS_ROOM: return "Nobody's Room";
            case LABEL_A1_TUESDAY_SMALLTALK: return "Smalltalk";
            case LABEL_A1_TUESDAY_RISK_VS_REWARD: return "Risk vs. Reward";
            case LABEL_A1_TUESDAY_PSEUDO_TEA_COSY: return "Pseudo Tea Cosy";
            case LABEL_A1_TUESDAY_SHARED_LIBRARY: return "Shared Library";
            case LABEL_A1_TUESDAY_BIZARRE_AND_SURREAL: return "Bizarre and Surreal";
            case LABEL_A1_WEDNESDAY_LUNCH_EVOLUTION_THEORY: return "Lunch Evolution Theory";
            case LABEL_A1_WEDNESDAY_SHORT_SHARP_SHOCK: return "Short Sharp Shock";
            case LABEL_A1_WEDNESDAY_MEET_CUTE: return "Meet Cute";
            case LABEL_A1_WEDNESDAY_DETOUR_AHEAD: return "Detour Ahead";
            case LABEL_A1_WEDNESDAY_SIP_P1: return "Sip (Part 1)";
            case LABEL_A1_WEDNESDAY_IT_BUILDS_CHARACTER: return "It Builds Character";
            case LABEL_A1_WEDNESDAY_A_PRIVATE_LUNCH: return "A Private Lunch";
            case LABEL_A1_WEDNESDAY_WAYLAY: return "Waylay";
            case LABEL_A1_WEDNESDAY_THE_OTHER_GREEN: return "The Other Green";
            case LABEL_A1_THURSDAY_THE_RUNNING_GIRL: return "The Running Girl";
            case LABEL_A1_THURSDAY_SOAP: return "Soap";
            case LABEL_A1_THURSDAY_COLD_WAR: return "Cold War";
            case LABEL_A1_THURSDAY_PROOF_OF_COMPETENCY: return "Proof of Competency";
            case LABEL_A1_THURSDAY_EVENT_HORIZON: return "Event Horizon";
            case LABEL_A1_THURSDAY_ABOVE_AND_BEYOND: return "Above and Beyond";
            case LABEL_A1_THURSDAY_PAINT_BY_NUMBERS: return "Paint by Numbers";
            case LABEL_A1_THURSDAY_THINGS_YOU_CAN_DO: return "Things You Can Do";
            case LABEL_A1_FRIDAY_EXERCISE: return "Exercise";
            case LABEL_A1_FRIDAY_INVISIBLE_HAT: return "Invisible Hat";
            case LABEL_A1_FRIDAY_HOME_FIELD_ADVANTAGE: return "Home Field Advantage";
            case LABEL_A1_FRIDAY_NO_RECOVERY: return "No Recovery";
            case LABEL_A1_FRIDAY_SLOW_RECOVERY: return "Slow Recovery";
            case LABEL_A1_FRIDAY_NO_FREE_LUNCH: return "No Free Lunch";
            case LABEL_A1_FRIDAY_FOOT_AND_MOUTH: return "Foot and Mouth";
            case LABEL_A1_FRIDAY_MIND_YOUR_STEP: return "Mind Your Step";
            case LABEL_A1_SATURDAY_SUPPORT: return "Support";
            case LABEL_A1_SATURDAY_AN_AESTHETICS: return "An Aesthetics";
            case LABEL_A1_SATURDAY_CREATIVE_PAIN: return "Creative Pain";
            case LABEL_A1_SATURDAY_PROPER_EXERCISE: return "Proper Exercise";
            case LABEL_A1_SATURDAY_SIP_P2: return "Sip (Part 2)";
            case LABEL_A1_SATURDAY_SHANGHAIED: return "Shanghaied";
            case LABEL_A1_SATURDAY_QUIET: return "Quiet";
            case LABEL_A1_SUNDAY_DONT_PANIC: return "Don't Panic";
            case LABEL_A1_SUNDAY_IS_CARNIVAL: return "Is Carnival!";
            case LABEL_A1_SUNDAY_CLOUDS_IN_MY_HEAD: return "Clouds in My Head";
            case LABEL_A1_SUNDAY_PROMISE_OF_TIME: return "Promise of Time";
            case LABEL_A1_SUNDAY_NC5XB3: return "Nc5xb3";
            case LABEL_A1_SUNDAY_MOVEMENT: return "Movement";
            case LABEL_A1_SUNDAY_THROWING_BALLS: return "Throwing Balls";
            case LABEL_A1_SUNDAY_THE_DEEP_END: return "The Deep End";
            default: return definitions_no_scene();
        }
    }

    const char* definitions_no_scene() {return "No scene";}
    const char* definitions_nothing() {return "Nothing";}
    const char* definitions_autosave() {return "(auto)";}

    const char* definitions_hi() {return "Hisao";}
    const char* definitions_ha() {return "Hanako";}
    const char* definitions_emi() {return "Emi";}
    const char* definitions_rin() {return "Rin";}
    const char* definitions_li() {return "Lilly";}
    const char* definitions_shi() {return "Shizune";}
    const char* definitions_mi() {return "Misha";}
    const char* definitions_ke() {return "Kenji";}
    const char* definitions_mu() {return "Mutou";}
    const char* definitions_nk() {return "Nurse";}
    const char* definitions_no() {return "Nomiya";}
    const char* definitions_yu() {return "Yuuko";}
    const char* definitions_sa() {return "Sae";}
    const char* definitions_aki() {return "Akira";}
    const char* definitions_hh() {return "Hideaki";}
    const char* definitions_hx() {return "Jigoro";}
    const char* definitions_emm() {return "Meiko";}
    const char* definitions_sk() {return "Shopkeep";}
    const char* definitions_mk() {return "Miki";}

    const char* definitions_mi_shi() {return "Shizune";}
    const char* definitions_mi_not_shi() {return "{s}Shizune{/s} Misha";}

    const char* definitions_mystery() {return "???";}

    const char* definitions_ha_() {return "Purple-haired girl";}
    const char* definitions_emi_() {return "Twintails girl";}
    const char* definitions_rin_() {return "Strange girl";}
    const char* definitions_li_() {return "Wavy-haired girl";}
    const char* definitions_mi_() {return "Laughing girl";}
    const char* definitions_ke_() {return "Bespectacled hallmate";}
    const char* definitions_mu_() {return "Tall man";}
    const char* definitions_yu_() {return "Librarian";}
    const char* definitions_no_() {return "Silver-haired man";}
    const char* definitions_sa_() {return "Gallery owner";}
    const char* definitions_aki_() {return "Well-dressed person";}
    const char* definitions_nk_() {return "Smiling man";}
    const char* definitions_hx_() {return "Huge man";}
    const char* definitions_hh_() {return "Slim girl";}
    const char* definitions_emm_() {return "Woman with braid";}

};
}
