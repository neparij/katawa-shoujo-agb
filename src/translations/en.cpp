#include "translation.h"
#include "en_definitions_labels.h"
#include "../scripts/script_a1_monday_en.cpp"
#include "../scripts/script_a1_tuesday_en.cpp"
#include "../scripts/script_a1_wednesday_en.cpp"
#include "../scripts/script_a1_thursday_en.cpp"

namespace ks {

class TranslationEn final : public Translation {
public:
    language_t type() override {
        return LANG_ENGLISH;
    }
    const char* language() override {return screens_english();}

    void (*script_a1_monday())() override { return &ScriptA1MondayEn::a1_monday; }
    void (*script_a1_tuesday())() override { return &ScriptA1TuesdayEn::a1_tuesday; }
    void (*script_a1_wednesday())() override { return &ScriptA1WednesdayEn::a1_wednesday; }
    void (*script_a1_thursday())() override { return &ScriptA1ThursdayEn::a1_thursday; }

    const char* menu_author() override {return "port by NeParij";}
    const char* menu_play_a0_test_scene() override {return "Test Scene";}
    const char* menu_play_a1_monday() override {return "Act 1. Monday";}
    const char* menu_play_a1_tuesday() override {return "Act 1. Tuesday";}
    const char* menu_play_a1_wednesday() override {return "Act 1. Wednesday";}
    const char* menu_play_a1_thursday() override {return "Act 1. Thursday (beta)";}
    const char* menu_play_all() override {return "Play all available";}
    const char* menu_video_test() override {return "Video tests";}

    const char* menu_options_high_contrast() override {return "High contrast";}
    const char* menu_options_hdisabled() override {return "Disable adult content";}
    bn::array<char*, 4> menu_options_disable_disturbing_content() override {
        return {"Skip hurtful adult scenes",};
    }
    const char* menu_options_language() override {return "Language";}

    const char* menu_start() override {return "Start";}
    const char* menu_saves() override {return "Saves";}
    const char* menu_extras() override {return "Extras";}
    const char* menu_options() override {return "Options";}

    const char* menu_extras_jukebox() override {return "Jukebox";}
    const char* menu_extras_gallery() override {return "Gallery";}
    const char* menu_extras_library() override {return "Library";}
    const char* menu_extras_cinema() override {return "Cinema";}

    unsigned int menu_extras_jukebox_xoffset() override {return 0;}
    unsigned int menu_extras_gallery_xoffset() override {return 0;}
    unsigned int menu_extras_library_xoffset() override {return 0;}
    unsigned int menu_extras_cinema_xoffset() override {return 0;}
    unsigned int menu_extras_return_xoffset() override {return 0;}

    const char* menu_back() override {return "Back";}

    const char* screens_english() override {return "English";}
    const char* screens_russian() override {return "Russian";}

    const char* screens_return() override {return "Return";}
    const char* screens_history() override {return "History (n/a)";}
    const char* screens_options() override {return "Options (n/a)";}
    const char* screens_saves_menu() override {return "Saves";}
    const char* screens_main_menu() override {return "Main menu";}

    const char* textbutton_save() override {return "Save";}

    const char* screens_playtime() override {return "Playtime";}
    const char* screens_current_scene() override {return "Scene";}
    const char* screens_current_track() override {return "Track";}
    const char* screens_now_playing() override {return "Now playing";}

    const char* label(const label_t label) override {
        if (const char* tl = get_label_en_translation(label); tl != nullptr) {
            return tl;
        }
        return definitions_no_scene();
    }

    const char* definitions_no_scene() override {return "No scene";}
    const char* definitions_nothing() override {return "Nothing";}
    const char* definitions_autosave() override {return "(auto)";}

    const char* definitions_hi() override {return "Hisao";}
    const char* definitions_ha() override {return "Hanako";}
    const char* definitions_emi() override {return "Emi";}
    const char* definitions_rin() override {return "Rin";}
    const char* definitions_li() override {return "Lilly";}
    const char* definitions_shi() override {return "Shizune";}
    const char* definitions_mi() override {return "Misha";}
    const char* definitions_ke() override {return "Kenji";}
    const char* definitions_mu() override {return "Mutou";}
    const char* definitions_nk() override {return "Nurse";}
    const char* definitions_no() override {return "Nomiya";}
    const char* definitions_yu() override {return "Yuuko";}
    const char* definitions_sa() override {return "Sae";}
    const char* definitions_aki() override {return "Akira";}
    const char* definitions_hh() override {return "Hideaki";}
    const char* definitions_hx() override {return "Jigoro";}
    const char* definitions_emm() override {return "Meiko";}
    const char* definitions_sk() override {return "Shopkeep";}
    const char* definitions_mk() override {return "Miki";}

    const char* definitions_mi_shi() override {return "Shizune";}
    const char* definitions_mi_not_shi() override {return "{s}Shizune{/s} Misha";}

    const char* definitions_mystery() override {return "???";}

    const char* definitions_ha_() override {return "Purple-haired girl";}
    const char* definitions_emi_() override {return "Twintails girl";}
    const char* definitions_rin_() override {return "Strange girl";}
    const char* definitions_li_() override {return "Wavy-haired girl";}
    const char* definitions_mi_() override {return "Laughing girl";}
    const char* definitions_ke_() override {return "Bespectacled hallmate";}
    const char* definitions_mu_() override {return "Tall man";}
    const char* definitions_yu_() override {return "Librarian";}
    const char* definitions_no_() override {return "Silver-haired man";}
    const char* definitions_sa_() override {return "Gallery owner";}
    const char* definitions_aki_() override {return "Well-dressed person";}
    const char* definitions_nk_() override {return "Smiling man";}
    const char* definitions_hx_() override {return "Huge man";}
    const char* definitions_hh_() override {return "Slim girl";}
    const char* definitions_emm_() override {return "Woman with braid";}

};
}
