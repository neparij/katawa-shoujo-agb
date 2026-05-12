#include "translation.h"

#include "act_opening.h"
#include "definitions_labels.h"

namespace ks::tl {

    language_t type() {
        return LANG_RUSSIAN;
    }
    const char* locale() {return "ru";}
    #include "definitions_commons.inc"

    const char* menu_start() {return "Старт";}
    const char* menu_saves() {return "Сохранения";}
    const char* menu_extras() {return "Дополнительное";}
    const char* menu_options() {return "Настройки";}
    const char* menu_accessibility() {return "Доступность";}

    const char* menu_options_general() {return "Основные";}
    const char* menu_options_sound() {return "Звук";}
    const char* menu_options_hdisabled() {return "Отключить 18+ контент";}
    const char* menu_options_language() {return "Выбор языка…";}
    const char* menu_options_accessibility() {return "Доступность…";}
    const char* menu_options_music_volume() {return "Громкость музыки";}
    const char* menu_options_sfx_volume() {return "Громкость звука";}

    const char* menu_options_accessibility_display() {return "Экран";}
    const char* menu_options_accessibility_text_speed() {return "Скорость текста";}
    const char* menu_options_accessibility_brightness() {return "Яркость";}
    const char* menu_options_accessibility_high_contrast() {return "Повышенный контраст";}
    const char* menu_options_accessibility_mental() {return "Психическое здоровье";}
    bn::array<const char*, 4> menu_options_accessibility_disable_disturbing_content() {
        return {"Пропуск сцен для взрослых, которые", "могут причинить боль",};
    }

    const char* menu_extras_jukebox() {return "Музыка";}
    const char* menu_extras_gallery() {return "Галерея";}
    const char* menu_extras_library() {return "Библиотека";}
    const char* menu_extras_cinema() {return "Видео";}

    unsigned int menu_extras_jukebox_xoffset() {return 0;}
    unsigned int menu_extras_gallery_xoffset() {return -8;}
    unsigned int menu_extras_library_xoffset() {return 0;}
    unsigned int menu_extras_cinema_xoffset() {return 0;}
    unsigned int menu_extras_return_xoffset() {return 0;}

    const char* menu_back() {return "Назад";}
    const char* menu_page() {return "Страница";}

    const char* screens_return() {return "Назад";}
    const char* screens_history() {return "История (н/д)";}
    const char* screens_options() {return "Настройки";}
    const char* screens_saves_menu() {return "Сохранения";}
    const char* screens_main_menu() {return "Главное меню";}

    const char* textbutton_save() {return "Сохранить";}
    const char* saves_auto_suffix() {return "(авто)";}

    const char* screens_playtime() {return "Наиграно";}
    const char* screens_current_scene() {return "Сцена";}
    const char* screens_current_track() {return "Композиция";}
    const char* screens_now_playing() {return "Сейчас играет";}

    const char* label(const label_t label) {
        if (const char* tl = get_label_translation(label); tl != nullptr) {
            return tl;
        }
        return definitions_no_scene();
    }

    opening_text opening_text_act1() {return {"Акт 1:", "Продолжительность", "жизни"};}
    opening_text opening_text_act2_emi() {return {"Акт 2:", "Приходим в форму", " "};}
    opening_text opening_text_act2_hanako() {return {"Акт 2:", "Игра в прятки"};}
    opening_text opening_text_act2_lilly() {return {"Акт 2:", "Прошлое"};}
    opening_text opening_text_act2_rin() {return {"Акт 2:", "Потеря связи"};}
    opening_text opening_text_act2_shizune() {return {"Акт 2:", "Учимся читать"};}
    opening_text opening_text_act3_emi() {return {"Акт 3:", "Перспектива"};}
    opening_text opening_text_act3_hanako() {return {"Акт 3:", "Рокировка"};}
    opening_text opening_text_act3_lilly() {return {"Акт 3:", "Настоящее"};}
    opening_text opening_text_act3_rin() {return {"Акт 3:", "Расстояние"};}
    opening_text opening_text_act3_shizune() {return {"Акт 3:", "Ловкость рук"};}
    opening_text opening_text_act4_emi() {return {"Акт 4:", "Движение"};}
    opening_text opening_text_act4_hanako() {return {"Акт 4:", "Шрамы"};}
    opening_text opening_text_act4_lilly() {return {"Акт 4:", "Будущее"};}
    opening_text opening_text_act4_rin() {return {"Акт 4:", "Мечта"};}
    opening_text opening_text_act4_shizune() {return {"Акт 4:", "Другой мне"};}
}
