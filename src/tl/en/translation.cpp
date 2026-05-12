#include "translation.h"

#include "act_opening.h"
#include "definitions_labels.h"

namespace ks::tl {
    language_t type() {
        return LANG_ENGLISH;
    }
    const char* locale() {return "en";}
    #include "definitions_commons.inc"

    const char* menu_start() {return "Start";}
    const char* menu_saves() {return "Saves";}
    const char* menu_extras() {return "Extras";}
    const char* menu_options() {return "Options";}
    const char* menu_accessibility() {return "Accessibility";}

    const char* menu_options_general() {return "General";}
    const char* menu_options_sound() {return "Sound";}
    const char* menu_options_hdisabled() {return "Disable adult content";}
    const char* menu_options_accessibility() {return "Accessibility…";}
    const char* menu_options_music_volume() {return "Music volume";}
    const char* menu_options_sfx_volume() {return "SFX volume";}

    const char* menu_options_accessibility_display() {return "Display";}
    const char* menu_options_accessibility_text_speed() {return "Text speed";}
    const char* menu_options_accessibility_brightness() {return "Brightness";}
    const char* menu_options_accessibility_high_contrast() {return "High contrast";}
    const char* menu_options_accessibility_mental() {return "Mental";}
    bn::array<const char*, 4> menu_options_accessibility_disable_disturbing_content() {
        return {"Skip hurtful adult scenes"};
    }

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
    const char* menu_page() {return "Page";}

    const char* screens_return() {return "Return";}
    const char* screens_history() {return "History (n/a)";}
    const char* screens_options() {return "Options";}
    const char* screens_saves_menu() {return "Saves";}
    const char* screens_main_menu() {return "Main menu";}

    const char* textbutton_save() {return "Save";}
    const char* saves_auto_suffix() {return "(auto)";}

    const char* screens_playtime() {return "Playtime";}
    const char* screens_current_scene() {return "Scene";}
    const char* screens_current_track() {return "Track";}
    const char* screens_now_playing() {return "Now playing";}

    const char* label(const label_t label) {
        if (const char* tl = get_label_translation(label); tl != nullptr) {
            return tl;
        }
        return definitions_no_scene();
    }

    opening_text opening_text_act1() {return {"Act 1:", "Life Expectancy"};}
    opening_text opening_text_act2_emi() {return {"Act 2:", "Form"};}
    opening_text opening_text_act2_hanako() {return {"Act 2:", "Hide and Seek"};}
    opening_text opening_text_act2_lilly() {return {"Act 2:", "Past"};}
    opening_text opening_text_act2_rin() {return {"Act 2:", "Disconnect"};}
    opening_text opening_text_act2_shizune() {return {"Act 2:", "Learning to Read"};}
    opening_text opening_text_act3_emi() {return {"Act 3:", "Perspective"};}
    opening_text opening_text_act3_hanako() {return {"Act 3:", "Castling"};}
    opening_text opening_text_act3_lilly() {return {"Act 3:", "Present"};}
    opening_text opening_text_act3_rin() {return {"Act 3:", "Distance"};}
    opening_text opening_text_act3_shizune() {return {"Act 3:", "Sleight of Hand"};}
    opening_text opening_text_act4_emi() {return {"Act 4:", "Motion"};}
    opening_text opening_text_act4_hanako() {return {"Act 4:", "Scars"};}
    opening_text opening_text_act4_lilly() {return {"Act 4:", "Future"};}
    opening_text opening_text_act4_rin() {return {"Act 4:", "Dream"};}
    opening_text opening_text_act4_shizune() {return {"Act 4:", "To My Other Self"};}
}
