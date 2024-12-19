#include "translation.h"
#include "scripts/script_a1_monday_en.cpp"
#include "scripts/script_a1_tuesday_en.cpp"
#include "scripts/script_a1_wednesday_en.cpp"

namespace ks {
class TranslationEn : public Translation {
public:
    const Type type() {
        return Type::EN;
    }
    const char* language() {return screens_english();}

    void (*script_a1_monday())() { return &ScriptA1MondayEn::a1_monday; }
    void (*script_a1_tuesday())() { return &ScriptA1TuesdayEn::a1_tuesday; }
    void (*script_a1_wednesday())() { return &ScriptA1WednesdayEn::a1_wednesday; }

    const char* menu_author() {return "port by NeParij";}
    const char* menu_play_a0_test_scene() {return "Test Scene";}
    const char* menu_play_a1_monday() {return "Act 1. Monday";}
    const char* menu_play_a1_tuesday() {return "Act 1. Tuesday";}
    const char* menu_play_a1_wednesday() {return "Act 1. Wednesday";}
    const char* menu_play_all() {return "Play all available";}
    const char* menu_language() {return "Language";}

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
};
}
