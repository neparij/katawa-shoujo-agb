#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include "definitions.h"
#include "bn_array.h"

namespace ks {
class Translation
{
public:

    virtual ~Translation() = default;
    virtual language_t type() = 0;
    virtual const char* language() = 0;

    virtual void (*script_a1_monday())() = 0;
    virtual void (*script_a1_tuesday())() = 0;
    virtual void (*script_a1_wednesday())() = 0;
    virtual void (*script_a1_thursday())() = 0;

    virtual const char* menu_author() = 0;
    virtual const char* menu_play_a0_test_scene() = 0;
    virtual const char* menu_play_a1_monday() = 0;
    virtual const char* menu_play_a1_tuesday() = 0;
    virtual const char* menu_play_a1_wednesday() = 0;
    virtual const char* menu_play_a1_thursday() = 0;
    virtual const char* menu_play_all() = 0;
    virtual const char* menu_video_test() = 0;

    virtual const char* menu_options_high_contrast() = 0;
    virtual const char* menu_options_hdisabled() = 0;
    virtual bn::array<char*, 4> menu_options_disable_disturbing_content() = 0;
    virtual const char* menu_options_language() = 0;

    virtual const char* menu_start() = 0;
    virtual const char* menu_saves() = 0;
    virtual const char* menu_extras() = 0;
    virtual const char* menu_options() = 0;

    virtual const char* menu_extras_jukebox() = 0;
    virtual const char* menu_extras_gallery() = 0;
    virtual const char* menu_extras_library() = 0;
    virtual const char* menu_extras_cinema() = 0;

    virtual unsigned int menu_extras_jukebox_xoffset() = 0;
    virtual unsigned int menu_extras_gallery_xoffset() = 0;
    virtual unsigned int menu_extras_library_xoffset() = 0;
    virtual unsigned int menu_extras_cinema_xoffset() = 0;
    virtual unsigned int menu_extras_return_xoffset() = 0;

    virtual const char* menu_back() = 0;

    virtual const char* screens_english() = 0;
    virtual const char* screens_russian() = 0;

    virtual const char* screens_return() = 0;
    virtual const char* screens_history() = 0;
    virtual const char* screens_options() = 0;
    virtual const char* screens_saves_menu() = 0;
    virtual const char* screens_main_menu() = 0;

    virtual const char* textbutton_save() = 0;

    virtual const char* screens_playtime() = 0;
    virtual const char* screens_current_scene() = 0;
    virtual const char* screens_current_track() = 0;

    // virtual char* script(script_t script) = 0;
    virtual const char* label(label_t label) = 0;

    virtual const char* definitions_no_scene() = 0;
    virtual const char* definitions_nothing() = 0;
    virtual const char* definitions_autosave() = 0;

    virtual const char* definitions_hi() = 0;
    virtual const char* definitions_ha() = 0;
    virtual const char* definitions_emi() = 0;
    virtual const char* definitions_rin() = 0;
    virtual const char* definitions_li() = 0;
    virtual const char* definitions_shi() = 0;
    virtual const char* definitions_mi() = 0;
    virtual const char* definitions_ke() = 0;
    virtual const char* definitions_mu() = 0;
    virtual const char* definitions_nk() = 0;
    virtual const char* definitions_no() = 0;
    virtual const char* definitions_yu() = 0;
    virtual const char* definitions_sa() = 0;
    virtual const char* definitions_aki() = 0;
    virtual const char* definitions_hh() = 0;
    virtual const char* definitions_hx() = 0;
    virtual const char* definitions_emm() = 0;
    virtual const char* definitions_sk() = 0;
    virtual const char* definitions_mk() = 0;

    virtual const char* definitions_mi_shi() = 0;
    virtual const char* definitions_mi_not_shi() = 0;

    virtual const char* definitions_mystery() = 0;

    virtual const char* definitions_ha_() = 0;
    virtual const char* definitions_emi_() = 0;
    virtual const char* definitions_rin_() = 0;
    virtual const char* definitions_li_() = 0;
    virtual const char* definitions_mi_() = 0;
    virtual const char* definitions_ke_() = 0;
    virtual const char* definitions_mu_() = 0;
    virtual const char* definitions_yu_() = 0;
    virtual const char* definitions_no_() = 0;
    virtual const char* definitions_sa_() = 0;
    virtual const char* definitions_aki_() = 0;
    virtual const char* definitions_nk_() = 0;
    virtual const char* definitions_hx_() = 0;
    virtual const char* definitions_hh_() = 0;
    virtual const char* definitions_emm_() = 0;

    const char* music(const music_t music) {
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
};
}

#endif // TRANSLATIONS_H
