#include "translation.h"
#include "ru_definitions_labels.h"

namespace ks {
class TranslationRu final : public Translation {
public:
    language_t type() override {
        return LANG_RUSSIAN;
    }
    const char* locale() override {return "ru";}
    const char* language() override {return language_ru();}
    #include "ru_definitions_commons.inc"

    const char* menu_start() override {return "Старт";}
    const char* menu_saves() override {return "Сохранения";}
    const char* menu_extras() override {return "Дополнительное";}
    const char* menu_options() override {return "Настройки";}
    const char* menu_language() override {return "Язык";}
    const char* menu_accessibility() override {return "Доступность";}

    const char* menu_options_general() override {return "Основные";}
    const char* menu_options_sound() override {return "Звук";}
    const char* menu_options_hdisabled() override {return "Отключить 18+ контент";}
    const char* menu_options_language() override {return "Выбор языка…";}
    const char* menu_options_accessibility() override {return "Доступность…";}
    const char* menu_options_music_volume() override {return "Громкость музыки";}
    const char* menu_options_sfx_volume() override {return "Громкость звука";}

    const char* menu_options_accessibility_display() override {return "Экран";}
    const char* menu_options_accessibility_text_speed() override {return "Скорость текста";}
    const char* menu_options_accessibility_brightness() override {return "Яркость";}
    const char* menu_options_accessibility_high_contrast() override {return "Повышенный контраст";}
    const char* menu_options_accessibility_mental() override {return "Психическое здоровье";}
    bn::array<const char*, 4> menu_options_accessibility_disable_disturbing_content() override {
        return {"Пропуск сцен для взрослых, которые", "могут причинить боль",};
    }

    const char* menu_extras_jukebox() override {return "Музыка";}
    const char* menu_extras_gallery() override {return "Галерея";}
    const char* menu_extras_library() override {return "Библиотека";}
    const char* menu_extras_cinema() override {return "Видео";}

    unsigned int menu_extras_jukebox_xoffset() override {return 0;}
    unsigned int menu_extras_gallery_xoffset() override {return -8;}
    unsigned int menu_extras_library_xoffset() override {return 0;}
    unsigned int menu_extras_cinema_xoffset() override {return 0;}
    unsigned int menu_extras_return_xoffset() override {return 0;}

    const char* menu_back() override {return "Назад";}
    const char* menu_page() override {return "Страница";}

    const char* screens_return() override {return "Назад";}
    const char* screens_history() override {return "История (н/д)";}
    const char* screens_options() override {return "Настройки";}
    const char* screens_saves_menu() override {return "Сохранения";}
    const char* screens_main_menu() override {return "Главное меню";}

    const char* textbutton_save() override {return "Сохранить";}
    const char* saves_auto_suffix() override {return "(авто)";}

    const char* screens_playtime() override {return "Наиграно";}
    const char* screens_current_scene() override {return "Сцена";}
    const char* screens_current_track() override {return "Композиция";}
    const char* screens_now_playing() override {return "Сейчас играет";}

    const char* label(const label_t label) override {
        if (const char* tl = get_label_ru_translation(label); tl != nullptr) {
            return tl;
        }
        return definitions_no_scene();
    }

    opening_text opening_text_act1() override {return {"Акт 1:", "Продолжительность", "жизни"};}
    opening_text opening_text_act2_emi() override {return {"Акт 2:", "Приходим в форму", " "};}
    opening_text opening_text_act2_hanako() override {return {"Акт 2:", "Игра в прятки"};}
    opening_text opening_text_act2_lilly() override {return {"Акт 2:", "Прошлое"};}
    opening_text opening_text_act2_rin() override {return {"Акт 2:", "Потеря связи"};}
    opening_text opening_text_act2_shizune() override {return {"Акт 2:", "Учимся читать"};}
    opening_text opening_text_act3_emi() override {return {"Акт 3:", "Перспектива"};}
    opening_text opening_text_act3_hanako() override {return {"Акт 3:", "Рокировка"};}
    opening_text opening_text_act3_lilly() override {return {"Акт 3:", "Настоящее"};}
    opening_text opening_text_act3_rin() override {return {"Акт 3:", "Расстояние"};}
    opening_text opening_text_act3_shizune() override {return {"Акт 3:", "Ловкость рук"};}
    opening_text opening_text_act4_emi() override {return {"Акт 4:", "Движение"};}
    opening_text opening_text_act4_hanako() override {return {"Акт 4:", "Шрамы"};}
    opening_text opening_text_act4_lilly() override {return {"Акт 4:", "Будущее"};}
    opening_text opening_text_act4_rin() override {return {"Акт 4:", "Мечта"};}
    opening_text opening_text_act4_shizune() override {return {"Акт 4:", "Другой мне"};}
};
}
