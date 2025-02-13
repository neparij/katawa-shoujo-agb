#include "translation.h"
#include "scripts/script_a1_monday_ru.cpp"
#include "scripts/script_a1_tuesday_ru.cpp"
#include "scripts/script_a1_wednesday_ru.cpp"
#include "scripts/script_a1_thursday_ru.cpp"

namespace ks {
class TranslationRu : public Translation {
public:
    TranslationType type() {
        return TranslationType::RU;
    }
    const char* language() {return screens_russian();}

    void (*script_a1_monday())() { return &ScriptA1MondayRu::a1_monday; }
    void (*script_a1_tuesday())() { return &ScriptA1TuesdayRu::a1_tuesday; }
    void (*script_a1_wednesday())() { return &ScriptA1WednesdayRu::a1_wednesday; }
    void (*script_a1_thursday())() { return &ScriptA1ThursdayRu::a1_thursday; }

    const char* menu_author() {return "порт от NeParij";}
    const char* menu_play_a0_test_scene() {return "Тестовая сцена";}
    const char* menu_play_a1_monday() {return "Акт 1. Понедельник";}
    const char* menu_play_a1_tuesday() {return "Акт 1. Вторник";}
    const char* menu_play_a1_wednesday() {return "Акт 1. Среда";}
    const char* menu_play_a1_thursday() {return "Акт 1. Четверг (beta)";}
    const char* menu_play_all() {return "Играть все доступные";}
    const char* menu_video_test() {return "Тест видео";}
    const char* menu_language() {return "Язык";}

    const char* menu_start() {return "Старт";}
    const char* menu_saves() {return "Сохранения";}
    const char* menu_extras() {return "Дополнительное";}
    const char* menu_options() {return "Настройки";}

    const char* menu_extras_jukebox() {return "Музыка";}
    const char* menu_extras_gallery() {return "Галерея";}
    const char* menu_extras_library() {return "Библиотека";}
    const char* menu_extras_cinema() {return "Видео";}

    unsigned int menu_extras_jukebox_xoffset() {return 0;}
    unsigned int menu_extras_gallery_xoffset() {return -8;}
    unsigned int menu_extras_library_xoffset() {return 0;}
    unsigned int menu_extras_cinema_xoffset() {return 0;}
    unsigned int menu_extras_return_xoffset() {return 0;}

    const char* menu_back() {return "< Назад";}

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

    const char* definitions_hi() {return "Хисао";}
    const char* definitions_ha() {return "Ханако";}
    const char* definitions_emi() {return "Эми";}
    const char* definitions_rin() {return "Рин";}
    const char* definitions_li() {return "Лилли";}
    const char* definitions_shi() {return "Сидзунэ";}
    const char* definitions_mi() {return "Миша";}
    const char* definitions_ke() {return "Кендзи";}
    const char* definitions_mu() {return "Муто";}
    const char* definitions_nk() {return "Фельдшер";}
    const char* definitions_no() {return "Номия";}
    const char* definitions_yu() {return "Юко";}
    const char* definitions_sa() {return "Саэ";}
    const char* definitions_aki() {return "Акира";}
    const char* definitions_hh() {return "Хидэаки";}
    const char* definitions_hx() {return "Дзигоро";}
    const char* definitions_emm() {return "Меэко";}
    const char* definitions_sk() {return "Продавец";}
    const char* definitions_mk() {return "Мики";}

    const char* definitions_mi_shi() {return "Сидзунэ";}
    const char* definitions_mi_not_shi() {return "{s}Сидзунэ{/s} Миша";}

    const char* definitions_mystery() {return "???";}

    const char* definitions_ha_() {return "Фиолето-волосая";}
    const char* definitions_emi_() {return "Хвостичка";}
    const char* definitions_rin_() {return "Странная";}
    const char* definitions_li_() {return "Светло-волосая";}
    const char* definitions_mi_() {return "Весёлая";}
    const char* definitions_ke_() {return "Сосед в очках";}
    const char* definitions_mu_() {return "Высокий";}
    const char* definitions_yu_() {return "Библиотекарь";}
    const char* definitions_no_() {return "Седовласый";}
    const char* definitions_sa_() {return "Владелица галереи";}
    const char* definitions_aki_() {return "Хорошо одетая";}
    const char* definitions_nk_() {return "Улыбающийся";}
    const char* definitions_hx_() {return "Огромный";}
    const char* definitions_hh_() {return "Стройная";}
    const char* definitions_emm_() {return "Женщина с косой";}

};
}
