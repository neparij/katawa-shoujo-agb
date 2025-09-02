#include "translation.h"
#include "ru_definitions_labels.h"

namespace ks {
class TranslationRu final : public Translation {
public:
    language_t type() override {
        return LANG_RUSSIAN;
    }
    const char* locale() override {return "ru";}
    const char* language() override {return screens_russian();}

    const char* menu_author() override {return "порт от NeParij";}
    const char* menu_play_a0_test_scene() override {return "Тестовая сцена";}
    const char* menu_play_a1_monday() override {return "Акт 1. Понедельник";}
    const char* menu_play_a1_tuesday() override {return "Акт 1. Вторник";}
    const char* menu_play_a1_wednesday() override {return "Акт 1. Среда";}
    const char* menu_play_a1_thursday() override {return "Акт 1. Четверг (beta)";}
    const char* menu_play_a1_friday() override {return "Акт 1. Пятница (beta)";}
    const char* menu_play_a1_saturday() override {return "Акт 1. Суббота (beta)";}
    const char* menu_play_a1_sunday() override {return "Акт 1. Воскресенье (beta)";}
    const char* menu_play_all() override {return "Играть все доступные";}
    const char* menu_video_test() override {return "Тест видео";}

    const char* menu_options_high_contrast() override {return "Повышенный контраст";}
    const char* menu_options_hdisabled() override {return "Отключить 18+ контент";}
    bn::array<char*, 4> menu_options_disable_disturbing_content() override {
        return {"Пропуск сцен для взрослых,", "которые могут причинить", "боль",};
    }
    const char* menu_options_language() override {return "Язык";}

    const char* menu_start() override {return "Старт";}
    const char* menu_saves() override {return "Сохранения";}
    const char* menu_extras() override {return "Дополнительное";}
    const char* menu_options() override {return "Настройки";}

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

    const char* screens_english() override {return "Английский";}
    const char* screens_russian() override {return "Русский";}

    const char* screens_return() override {return "Назад";}
    const char* screens_history() override {return "История (н/д)";}
    const char* screens_options() override {return "Настройки (н/д)";}
    const char* screens_saves_menu() override {return "Сохранения";}
    const char* screens_main_menu() override {return "Главное меню";}

    const char* textbutton_save() override {return "Сохранить";}

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

    const char* definitions_no_scene() override {return "Нет сцены";}
    const char* definitions_nothing() override {return "Ничего";}
    const char* definitions_autosave() override {return "(авто)";}

    const char* definitions_hi() override {return "Хисао";}
    const char* definitions_ha() override {return "Ханако";}
    const char* definitions_emi() override {return "Эми";}
    const char* definitions_rin() override {return "Рин";}
    const char* definitions_li() override {return "Лилли";}
    const char* definitions_shi() override {return "Сидзунэ";}
    const char* definitions_mi() override {return "Миша";}
    const char* definitions_ke() override {return "Кендзи";}
    const char* definitions_mu() override {return "Муто";}
    const char* definitions_nk() override {return "Фельдшер";}
    const char* definitions_no() override {return "Номия";}
    const char* definitions_yu() override {return "Юко";}
    const char* definitions_sa() override {return "Саэ";}
    const char* definitions_aki() override {return "Акира";}
    const char* definitions_hh() override {return "Хидэаки";}
    const char* definitions_hx() override {return "Дзигоро";}
    const char* definitions_emm() override {return "Меэко";}
    const char* definitions_sk() override {return "Продавец";}
    const char* definitions_mk() override {return "Мики";}

    const char* definitions_mi_shi() override {return "Сидзунэ";}
    const char* definitions_mi_not_shi() override {return "{s}Сидзунэ{/s} Миша";}

    const char* definitions_mystery() override {return "???";}

    const char* definitions_ha_() override {return "Фиолето-волосая";}
    const char* definitions_emi_() override {return "Хвостичка";}
    const char* definitions_rin_() override {return "Странная";}
    const char* definitions_li_() override {return "Светло-волосая";}
    const char* definitions_mi_() override {return "Весёлая";}
    const char* definitions_ke_() override {return "Сосед в очках";}
    const char* definitions_mu_() override {return "Высокий";}
    const char* definitions_yu_() override {return "Библиотекарь";}
    const char* definitions_no_() override {return "Седовласый";}
    const char* definitions_sa_() override {return "Владелица галереи";}
    const char* definitions_aki_() override {return "Хорошо одетая";}
    const char* definitions_nk_() override {return "Улыбающийся";}
    const char* definitions_hx_() override {return "Огромный";}
    const char* definitions_hh_() override {return "Стройная";}
    const char* definitions_emm_() override {return "Женщина с косой";}

    opening_text opening_text_act1() override {return {"Акт 1:", "Продолжительность", "жизни"};}
};
}
