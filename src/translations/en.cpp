#include "translation.h"
#include "en_definitions_labels.h"

namespace ks {

class TranslationEn final : public Translation {
public:
    language_t type() override {
        return LANG_ENGLISH;
    }
    const char* locale() override {return "en";}
    const char* language() override {return language_en();}
    #include "en_definitions_commons.inc"

    const char* menu_start() override {return "Start";}
    const char* menu_saves() override {return "Saves";}
    const char* menu_extras() override {return "Extras";}
    const char* menu_options() override {return "Options";}
    const char* menu_language() override {return "Language";}
    const char* menu_accessibility() override {return "Accessibility";}

    const char* menu_options_general() override {return "General";}
    const char* menu_options_sound() override {return "Sound";}
    const char* menu_options_hdisabled() override {return "Disable adult content";}
    const char* menu_options_language() override {return "Language selection…";}
    const char* menu_options_accessibility() override {return "Accessibility…";}
    const char* menu_options_music_volume() override {return "Music volume";}
    const char* menu_options_sfx_volume() override {return "SFX volume";}

    const char* menu_options_accessibility_display() override {return "Display";}
    const char* menu_options_accessibility_text_speed() override {return "Text speed";}
    const char* menu_options_accessibility_brightness() override {return "Brightness";}
    const char* menu_options_accessibility_high_contrast() override {return "High contrast";}
    const char* menu_options_accessibility_mental() override {return "Mental";}
    bn::array<const char*, 4> menu_options_accessibility_disable_disturbing_content() override {
        return {"Skip hurtful adult scenes"};
    }

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
    const char* menu_page() override {return "Page";}

    const char* language_en() override {return "English";}
    const char* language_ru() override {return "Russian";}
    const char* language_fr() override {return "French";}
    const char* language_it() override {return "Italian";}
    const char* language_es() override {return "Spanish";}
    const char* language_de() override {return "German";}
    const char* language_jp() override {return "Japanese";}
    const char* language_zh_hans() override {return "Simplified Chinese";}

    const char* screens_return() override {return "Return";}
    const char* screens_history() override {return "History (n/a)";}
    const char* screens_options() override {return "Options";}
    const char* screens_saves_menu() override {return "Saves";}
    const char* screens_main_menu() override {return "Main menu";}

    const char* textbutton_save() override {return "Save";}
    const char* saves_auto_suffix() override {return "(auto)";}

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

    opening_text opening_text_act1() override {return {"Act 1:", "Life Expectancy"};}
    opening_text opening_text_act2_emi() override {return {"Act 2:", "Form"};}
    opening_text opening_text_act2_hanako() override {return {"Act 2:", "Hide and Seek"};}
    opening_text opening_text_act2_lilly() override {return {"Act 2:", "Past"};}
    opening_text opening_text_act2_rin() override {return {"Act 2:", "Disconnect"};}
    opening_text opening_text_act2_shizune() override {return {"Act 2:", "Learning to Read"};}
    opening_text opening_text_act3_emi() override {return {"Act 3:", "Perspective"};}
    opening_text opening_text_act3_hanako() override {return {"Act 3:", "Castling"};}
    opening_text opening_text_act3_lilly() override {return {"Act 3:", "Present"};}
    opening_text opening_text_act3_rin() override {return {"Act 3:", "Distance"};}
    opening_text opening_text_act3_shizune() override {return {"Act 3:", "Sleight of Hand"};}
    opening_text opening_text_act4_emi() override {return {"Act 4:", "Motion"};}
    opening_text opening_text_act4_hanako() override {return {"Act 4:", "Scars"};}
    opening_text opening_text_act4_lilly() override {return {"Act 4:", "Future"};}
    opening_text opening_text_act4_rin() override {return {"Act 4:", "Dream"};}
    opening_text opening_text_act4_shizune() override {return {"Act 4:", "To My Other Self"};}
};
}
