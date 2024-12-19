#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include "bn_string.h"

namespace ks {
class Translation
{
public:
    enum class Type {
        EN,
        RU,
    };

    virtual ~Translation() = default;
    virtual const Type type() = 0;
    virtual const char* language() = 0;

    virtual void (*script_a1_monday())() = 0;
    virtual void (*script_a1_tuesday())() = 0;
    virtual void (*script_a1_wednesday())() = 0;

    virtual const char* menu_author() = 0;
    virtual const char* menu_play_a0_test_scene() = 0;
    virtual const char* menu_play_a1_monday() = 0;
    virtual const char* menu_play_a1_tuesday() = 0;
    virtual const char* menu_play_a1_wednesday() = 0;
    virtual const char* menu_play_all() = 0;
    virtual const char* menu_language() = 0;

    virtual const char* screens_english() = 0;
    virtual const char* screens_russian() = 0;

    virtual const char* screens_return() = 0;
    virtual const char* screens_history() = 0;
    virtual const char* screens_options() = 0;
    virtual const char* screens_save_game() = 0;
    virtual const char* screens_load_game() = 0;
    virtual const char* screens_main_menu() = 0;

    virtual const char* screens_playtime() = 0;
    virtual const char* screens_current_scene() = 0;
    virtual const char* screens_current_track() = 0;

    virtual const char* definitions_no_scene() = 0;
    virtual const char* definitions_nothing() = 0;
};
}

#endif // TRANSLATIONS_H
