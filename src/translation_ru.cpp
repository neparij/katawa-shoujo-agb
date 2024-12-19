#include "translation.h"
#include "scripts/script_a1_monday_ru.cpp"
#include "scripts/script_a1_tuesday_ru.cpp"
#include "scripts/script_a1_wednesday_ru.cpp"

namespace ks {
class TranslationRu : public Translation {
public:
    const Type type() {
        return Type::RU;
    }
    const char* language() {return screens_russian();}

    void (*script_a1_monday())() { return &ScriptA1MondayRu::a1_monday; }
    void (*script_a1_tuesday())() { return &ScriptA1TuesdayRu::a1_tuesday; }
    void (*script_a1_wednesday())() { return &ScriptA1WednesdayRu::a1_wednesday; }

    const char* menu_author() {return "порт от NeParij";}
    const char* menu_play_a0_test_scene() {return "Тестовая сцена";}
    const char* menu_play_a1_monday() {return "Акт 1. Понедельник";}
    const char* menu_play_a1_tuesday() {return "Акт 1. Вторник";}
    const char* menu_play_a1_wednesday() {return "Акт 1. Среда";}
    const char* menu_play_all() {return "Играть все доступные";}
    const char* menu_language() {return "Язык";}

    const char* screens_english() {return "Английский";}
    const char* screens_russian() {return "Русский";}

    const char* screens_return() {return "Назад";}
    const char* screens_history() {return "История (н/д)";}
    const char* screens_options() {return "Настройки (н/д)";}
    const char* screens_save_game() {return "Сохранить (н/д)";}
    const char* screens_load_game() {return "Загрузить (н/д)";}
    const char* screens_main_menu() {return "Главное меню";}

    const char* screens_playtime() {return "Наиграно";}
    const char* screens_current_scene() {return "Сцена";}
    const char* screens_current_track() {return "Композиция";}

    const char* definitions_no_scene() {return "Нет сцены";}
    const char* definitions_nothing() {return "Ничего";}
};
}
