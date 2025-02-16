#include "translation.h"
#include "scripts/script_a1_monday_ru.cpp"
#include "scripts/script_a1_tuesday_ru.cpp"
#include "scripts/script_a1_wednesday_ru.cpp"
#include "scripts/script_a1_thursday_ru.cpp"

namespace ks {
class TranslationRu : public Translation {
public:
    language_t type() {
        return LANG_RUSSIAN;
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

    const char* menu_options_high_contrast() {return "Повышенный контраст";}
    const char* menu_options_hdisabled() {return "Отключить 18+ контент";}
    bn::array<char*, 4> menu_options_disable_disturbing_content() {
        return {"Пропуск сцен для взрослых,", "которые могут причинить", "боль",};
    }
    const char* menu_options_language() {return "Язык";}

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

    const char* menu_back() {return "Назад";}

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

    const char* label(label_t label) override {
        switch (label) {
            case LABEL_A1_MONDAY_OUT_COLD: return "На Морозе";
            case LABEL_A1_MONDAY_BUNDLE_OF_HISAO: return "Бремя Хисао";
            case LABEL_A1_MONDAY_GATEWAY_EFFECT: return "Воздействие ворот";
            case LABEL_A1_MONDAY_ENTER_STAGE_LEFT: return "Вход на сцену слева";
            case LABEL_A1_MONDAY_IN_THE_NURSERY: return "In the Nursery";
            case LABEL_A1_MONDAY_NOBODYS_ROOM: return "Nobody's Room";
            case LABEL_A1_TUESDAY_SMALLTALK: return "Smalltalk";
            case LABEL_A1_TUESDAY_RISK_VS_REWARD: return "Risk vs. Reward";
            case LABEL_A1_TUESDAY_PSEUDO_TEA_COSY: return "Pseudo Tea Cosy";
            case LABEL_A1_TUESDAY_SHARED_LIBRARY: return "Shared Library";
            case LABEL_A1_TUESDAY_BIZARRE_AND_SURREAL: return "Bizarre and Surreal";
            case LABEL_A1_WEDNESDAY_LUNCH_EVOLUTION_THEORY: return "Lunch Evolution Theory";
            case LABEL_A1_WEDNESDAY_SHORT_SHARP_SHOCK: return "Short Sharp Shock";
            case LABEL_A1_WEDNESDAY_MEET_CUTE: return "Meet Cute";
            case LABEL_A1_WEDNESDAY_DETOUR_AHEAD: return "Detour Ahead";
            case LABEL_A1_WEDNESDAY_SIP_P1: return "Sip (Part 1)";
            case LABEL_A1_WEDNESDAY_IT_BUILDS_CHARACTER: return "It Builds Character";
            case LABEL_A1_WEDNESDAY_A_PRIVATE_LUNCH: return "A Private Lunch";
            case LABEL_A1_WEDNESDAY_WAYLAY: return "Waylay";
            case LABEL_A1_WEDNESDAY_THE_OTHER_GREEN: return "The Other Green";
            case LABEL_A1_THURSDAY_THE_RUNNING_GIRL: return "The Running Girl";
            case LABEL_A1_THURSDAY_SOAP: return "Soap";
            case LABEL_A1_THURSDAY_COLD_WAR: return "Cold War";
            case LABEL_A1_THURSDAY_PROOF_OF_COMPETENCY: return "Proof of Competency";
            case LABEL_A1_THURSDAY_EVENT_HORIZON: return "Event Horizon";
            case LABEL_A1_THURSDAY_ABOVE_AND_BEYOND: return "Above and Beyond";
            case LABEL_A1_THURSDAY_PAINT_BY_NUMBERS: return "Paint by Numbers";
            case LABEL_A1_THURSDAY_THINGS_YOU_CAN_DO: return "Things You Can Do";
            case LABEL_A1_FRIDAY_EXERCISE: return "Exercise";
            case LABEL_A1_FRIDAY_INVISIBLE_HAT: return "Invisible Hat";
            case LABEL_A1_FRIDAY_HOME_FIELD_ADVANTAGE: return "Home Field Advantage";
            case LABEL_A1_FRIDAY_NO_RECOVERY: return "No Recovery";
            case LABEL_A1_FRIDAY_SLOW_RECOVERY: return "Slow Recovery";
            case LABEL_A1_FRIDAY_NO_FREE_LUNCH: return "No Free Lunch";
            case LABEL_A1_FRIDAY_FOOT_AND_MOUTH: return "Foot and Mouth";
            case LABEL_A1_FRIDAY_MIND_YOUR_STEP: return "Mind Your Step";
            case LABEL_A1_SATURDAY_SUPPORT: return "Support";
            case LABEL_A1_SATURDAY_AN_AESTHETICS: return "An Aesthetics";
            case LABEL_A1_SATURDAY_CREATIVE_PAIN: return "Creative Pain";
            case LABEL_A1_SATURDAY_PROPER_EXERCISE: return "Proper Exercise";
            case LABEL_A1_SATURDAY_SIP_P2: return "Sip (Part 2)";
            case LABEL_A1_SATURDAY_SHANGHAIED: return "Shanghaied";
            case LABEL_A1_SATURDAY_QUIET: return "Quiet";
            case LABEL_A1_SUNDAY_DONT_PANIC: return "Don't Panic";
            case LABEL_A1_SUNDAY_IS_CARNIVAL: return "Is Carnival!";
            case LABEL_A1_SUNDAY_CLOUDS_IN_MY_HEAD: return "Clouds in My Head";
            case LABEL_A1_SUNDAY_PROMISE_OF_TIME: return "Promise of Time";
            case LABEL_A1_SUNDAY_NC5XB3: return "Nc5xb3";
            case LABEL_A1_SUNDAY_MOVEMENT: return "Movement";
            case LABEL_A1_SUNDAY_THROWING_BALLS: return "Throwing Balls";
            case LABEL_A1_SUNDAY_THE_DEEP_END: return "The Deep End";
            default: return "Unknown Label";
        }
    }

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
