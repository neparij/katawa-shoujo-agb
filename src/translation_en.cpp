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

    const char* menu_back() {return "< Back";}

    const char* screens_english() {return "English";}
    const char* screens_russian() {return "Russian";}

    const char* screens_return() {return "Return";}
    const char* screens_history() {return "History (n/a)";}
    const char* screens_options() {return "Options (n/a)";}
    const char* screens_save_game() {return "Save game (n/a)";}
    const char* screens_load_game() {return "Load game (n/a)";}
    const char* screens_main_menu() {return "Main menu";}

    const char* screens_playtime() {return "Playtime";}
    const char* screens_current_scene() {return "Scene";}
    const char* screens_current_track() {return "Track";}

    const char* definitions_no_scene() {return "No scene";}
    const char* definitions_nothing() {return "Nothing";}

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
