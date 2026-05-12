#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include "definitions.h"
#include "bn_array.h"

namespace ks {
    struct opening_text;
}

namespace ks::tl {

    extern language_t type();
    extern const char* locale();

    extern const char* menu_start();
    extern const char* menu_saves();
    extern const char* menu_extras();
    extern const char* menu_options();
    extern const char* menu_accessibility();

    extern const char* menu_options_general();
    extern const char* menu_options_sound();
    extern const char* menu_options_hdisabled();
    extern const char* menu_options_accessibility();
    extern const char* menu_options_music_volume();
    extern const char* menu_options_sfx_volume();

    extern const char* menu_options_accessibility_display();
    extern const char* menu_options_accessibility_text_speed();
    extern const char* menu_options_accessibility_brightness();
    extern const char* menu_options_accessibility_high_contrast();
    extern const char* menu_options_accessibility_mental();
    extern bn::array<const char*, 4> menu_options_accessibility_disable_disturbing_content();

    extern const char* menu_extras_jukebox();
    extern const char* menu_extras_gallery();
    extern const char* menu_extras_library();
    extern const char* menu_extras_cinema();

    extern unsigned int menu_extras_jukebox_xoffset();
    extern unsigned int menu_extras_gallery_xoffset();
    extern unsigned int menu_extras_library_xoffset();
    extern unsigned int menu_extras_cinema_xoffset();
    extern unsigned int menu_extras_return_xoffset();

    extern const char* menu_back();
    extern const char* menu_page();

    extern const char* screens_return();
    extern const char* screens_history();
    extern const char* screens_options();
    extern const char* screens_saves_menu();
    extern const char* screens_main_menu();

    extern const char* textbutton_save();
    extern const char* saves_auto_suffix();

    extern const char* screens_playtime();
    extern const char* screens_current_scene();
    extern const char* screens_current_track();
    extern const char* screens_now_playing();

    // extern char* script(script_t script);
    extern const char* label(label_t label);

    extern const char* definitions_no_scene();
    extern const char* definitions_nothing();

    extern const char* definitions_hi();
    extern const char* definitions_ha();
    extern const char* definitions_emi();
    extern const char* definitions_rin();
    extern const char* definitions_li();
    extern const char* definitions_shi();
    extern const char* definitions_mi();
    extern const char* definitions_ke();
    extern const char* definitions_mu();
    extern const char* definitions_nk();
    extern const char* definitions_no();
    extern const char* definitions_yu();
    extern const char* definitions_sa();
    extern const char* definitions_aki();
    extern const char* definitions_hh();
    extern const char* definitions_hx();
    extern const char* definitions_emm();
    extern const char* definitions_sk();
    extern const char* definitions_mk();

    extern const char* definitions_mi_shi();
    extern const char* definitions_mi_not_shi();

    extern const char* definitions_mystery();

    extern const char* definitions_ha_();
    extern const char* definitions_emi_();
    extern const char* definitions_rin_();
    extern const char* definitions_li_();
    extern const char* definitions_mi_();
    extern const char* definitions_ke_();
    extern const char* definitions_mu_();
    extern const char* definitions_yu_();
    extern const char* definitions_no_();
    extern const char* definitions_sa_();
    extern const char* definitions_aki_();
    extern const char* definitions_nk_();
    extern const char* definitions_hx_();
    extern const char* definitions_hh_();
    extern const char* definitions_emm_();

    extern opening_text opening_text_act1();
    extern opening_text opening_text_act2_emi();
    extern opening_text opening_text_act2_hanako();
    extern opening_text opening_text_act2_lilly();
    extern opening_text opening_text_act2_rin();
    extern opening_text opening_text_act2_shizune();
    extern opening_text opening_text_act3_emi();
    extern opening_text opening_text_act3_hanako();
    extern opening_text opening_text_act3_lilly();
    extern opening_text opening_text_act3_rin();
    extern opening_text opening_text_act3_shizune();
    extern opening_text opening_text_act4_emi();
    extern opening_text opening_text_act4_hanako();
    extern opening_text opening_text_act4_lilly();
    extern opening_text opening_text_act4_rin();
    extern opening_text opening_text_act4_shizune();

    inline const char* music(const music_t music) {
        switch (music) {
            case MUSIC_TRANQUIL: return "Afternoon";
            case MUSIC_NURSE: return "Ah Eh I Oh You";
            case MUSIC_SOOTHING: return "Air Guitar";
            case MUSIC_TWINKLE: return "Aria de l'Etoile";
            case MUSIC_MOONLIGHT: return "Breathlessly";
            case MUSIC_RAIN: return "Caged Heart";
            case MUSIC_TRAGIC: return "Cold Iron";
            case MUSIC_COMFORT: return "Comfort";
            case MUSIC_LILLY: return "Concord";
            case MUSIC_DAILY: return "Daylight";
            case MUSIC_EASE: return "Ease";
            case MUSIC_ANOTHER: return "Everyday Fantasy";
            case MUSIC_FRIENDSHIP: return "Friendship";
            case MUSIC_HAPPINESS: return "Fripperies";
            case MUSIC_COMEDY: return "Generic Happy Music";
            case MUSIC_TENSION: return "High Tension";
            case MUSIC_RUNNING: return "Hokabi";
            case MUSIC_INNOCENCE: return "Innocence";
            case MUSIC_HEART: return "Letting my Heart Speak";
            case MUSIC_SERENE: return "Lullaby of Open Eyes";
            case MUSIC_DRAMA: return "Moment of Decision";
            case MUSIC_NIGHT: return "Nocturne";
            case MUSIC_KENJI: return "Out of the Loop";
            case MUSIC_HANAKO: return "Painful History";
            case MUSIC_RIN: return "Parity";
            case MUSIC_TIMESKIP: return "Passing of Time";
            case MUSIC_DREAMY: return "Raindrops and Puddles";
            case MUSIC_JAZZ: return "Red Velvet";
            case MUSIC_ROMANCE: return "Romance in Andante II";
            case MUSIC_CREDITS: return "Romance in Andante";
            case MUSIC_MUSICBOX: return "Sarabande from BWV1010";
            case MUSIC_NORMAL: return "School Days";
            case MUSIC_SADNESS: return "Shadow of the Truth";
            case MUSIC_EMI: return "Standing Tall";
            case MUSIC_PEARLY: return "Stride";
            case MUSIC_SHIZUNE: return "The Student Council";
            case MUSIC_ONE: return "To Become One";
            case MUSIC_MENUS: return "Wiosna";
            default: return definitions_nothing();
        }
    }
}

#endif // TRANSLATIONS_H
