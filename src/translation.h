#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H


namespace ks {

enum class TranslationType {
    EN,
    RU,
};
class Translation
{
public:

    virtual ~Translation() = default;
    virtual TranslationType type() = 0;
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
    virtual const char* menu_language() = 0;

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
    virtual const char* screens_save_game() = 0;
    virtual const char* screens_load_game() = 0;
    virtual const char* screens_main_menu() = 0;

    virtual const char* screens_playtime() = 0;
    virtual const char* screens_current_scene() = 0;
    virtual const char* screens_current_track() = 0;

    virtual const char* definitions_no_scene() = 0;
    virtual const char* definitions_nothing() = 0;

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

};
}

#endif // TRANSLATIONS_H
