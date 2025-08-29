#include "script_a1_friday.h"
#include "tl_index/script_a1_friday_586AD362_ru_tl_index.h"
#include "tl_index/script_a1_friday_9BFD77BF_ru_tl_index.h"
#include "tl_index/script_a1_friday_5697F250_ru_tl_index.h"
#include "tl_index/script_a1_friday_C8FC0CC9_ru_tl_index.h"
#include "tl_index/script_a1_friday_63FD258B_ru_tl_index.h"
#include "tl_index/script_a1_friday_D29AF3D8_ru_tl_index.h"
#include "tl_index/script_a1_friday_03DA99B5_ru_tl_index.h"
#include "tl_index/script_a1_friday_D7FBC85A_ru_tl_index.h"
#include "tl_index/script_a1_friday_B0381F35_ru_tl_index.h"
#include "tl_index/script_a1_friday_2DC5D5B3_ru_tl_index.h"
#include "tl_index/script_a1_friday_890886E3_ru_tl_index.h"
#include "tl_index/script_a1_friday_4D2DCD5F_ru_tl_index.h"
#include "tl_index/script_a1_friday_6F488CFB_ru_tl_index.h"
#include "tl_index/script_a1_friday_8F650623_ru_tl_index.h"
#include "tl_index/script_a1_friday_BFCD6512_ru_tl_index.h"
#include "tl_index/script_a1_friday_3A5E5047_ru_tl_index.h"
#include "tl_index/script_a1_friday_6BD34F2C_ru_tl_index.h"
#include "tl_index/script_a1_friday_5116FB4A_ru_tl_index.h"
#include "tl_index/script_a1_friday_EEACE0F5_ru_tl_index.h"
#include "tl_index/script_a1_friday_C2A7D689_ru_tl_index.h"
namespace ks {
    class ScriptA1FridayRu : public ScriptA1Friday {
        public:
            SCENE_INLINE void a1_friday_exercise() {
                ks::SceneManager::set_label(LABEL_A1_FRIDAY_EXERCISE);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("586AD362", tl_586AD362_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 0));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_alarmclock.8ad", SOUND_CHANNEL_SOUND));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhisao, 0, 0, SCENE_TRANSITION_OPENEYE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE2C5E9AF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x5F85BEDC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0xECD33704);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0x48BC94D5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0xECC2288C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x100D544D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                ks::SceneManager::set_line_hash(0x2B656B84);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_track, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_emirunning.8ad", SOUND_CHANNEL_AMBIENT, 18));
                ks::SceneManager::set_line_hash(0x215F61DF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0xAE49E957);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x77AC0611);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0xFAC8A9CB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 18));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_grin_gym, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_EMI, 30));
                ks::SceneManager::set_line_hash(0xC0B1A8F7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 11));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_closedgrin_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6757600A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 12));
                ks::SceneManager::set_line_hash(0x5A656A3F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 13));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_grin_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xAD424566);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 14));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_annoyed_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB2DC54A7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0x15057259);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 16));
                ks::SceneManager::set_line_hash(0x674B9741);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 17));
                ks::SceneManager::set_line_hash(0x5EA874D4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 18));
                ks::SceneManager::set_line_hash(0xAAED22BB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_happy_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7B27C1CB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 20));
                ks::SceneManager::set_line_hash(0x6DFBCA9E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 21));
                ks::SceneManager::set_line_hash(0x839E5A81);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 22));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited_gym, bn::regular_bg_items::emi_bg_excited_gym, bn::sprite_items::emi_spr_excited_proud_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xADF34CAE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 23));
                ks::SceneManager::set_line_hash(0xD0FD4F4E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 24));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_closedhappy_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0395F860);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 25));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_track_on, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA0087F6F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_emijogging.8ad", SOUND_CHANNEL_AMBIENT, 18));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_track_running, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF3886590);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 27));
                ks::SceneManager::set_line_hash(0x81578A9C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 28));
                ks::SceneManager::set_line_hash(0x3E4F9BA6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 29));
                ks::SceneManager::set_line_hash(0x05D9993C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 30));
                ks::SceneManager::set_line_hash(0xE95EC6B5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 31));
                ks::SceneManager::set_line_hash(0xC1126224);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 32));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_emirunning.8ad", SOUND_CHANNEL_AMBIENT));
                ks::SceneManager::set_line_hash(0xDFF2244C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                ks::SceneManager::set_line_hash(0xE59CE6DB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 34));
                ScriptA1FridayRu::a1_friday_exercise__menu_question_0();
                if (ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_exercise__condition_0_0();
                } 
                
            
            }
            SCENE_INLINE void a1_friday_invisible_hat() {
                ks::SceneManager::set_label(LABEL_A1_FRIDAY_INVISIBLE_HAT);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("9BFD77BF", tl_9BFD77BF_ru_intl));
                if (!ks::in_replay) {
                }
                if (!ks::progress.promised || ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_invisible_hat__condition_0_0();
                } 
                
            
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhisao, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9D92544D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x38499099);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0x878E3284);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0xB546F61A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0x1702F1B4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0xDCF9A8ED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                ks::SceneManager::set_line_hash(0x40EB9641);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0x647CFB3F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhallway, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x58625C26);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x197FDE7E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 9));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_KENJI, 30));
                ks::SceneManager::set_line_hash(0xB5E99207);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0x481D1D79);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 11));
                ks::SceneManager::set_line_hash(0xDC21A07B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0x4FB93284);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 13));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD520C002);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 14));
                ks::SceneManager::set_line_hash(0xBBE2CB4E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 15));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB0974217);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 16));
                ks::SceneManager::set_line_hash(0xFEEFC3C8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 17));
                ks::SceneManager::set_line_hash(0x227A7E7D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 18));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9BFE2D0C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 19));
                ks::SceneManager::set_line_hash(0xCD774B19);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 20));
                ks::SceneManager::set_line_hash(0xE1CBA379);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 21));
                ks::SceneManager::set_line_hash(0xA22BF841);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 22));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCC93C88A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 23));
                ks::SceneManager::set_line_hash(0x462FA0A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 24));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE649490A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 25));
                ks::SceneManager::set_line_hash(0x4BD0B96A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 26));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0EF978C1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 27));
                ks::SceneManager::set_line_hash(0x471D9125);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 28));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8649B078);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 29));
                ks::SceneManager::set_line_hash(0x531861EB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 30));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8B97581C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 31));
                ks::SceneManager::set_line_hash(0xD50EB017);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 32));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x81F87D44);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 33));
                ks::SceneManager::set_line_hash(0x0016E6EF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 34));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x85862817);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 35));
                ks::SceneManager::set_line_hash(0x76B6B21C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x154EA960);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 37));
                ks::SceneManager::set_line_hash(0xDAF87E08);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 38));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF23DC101);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 39));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x40D71A9B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 40));
                ks::SceneManager::set_line_hash(0x7C444F41);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 41));
                if ((!ks::progress.get_tired() && !ks::progress.go_through_shizu()) || ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_invisible_hat__condition_1_0();
                } 
                
            
                if (ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_invisible_hat__condition_2_0();
                } 
                
            
            }
            SCENE_INLINE void a1_friday_home_field_advantage() {
                ks::SceneManager::set_label(LABEL_A1_FRIDAY_HOME_FIELD_ADVANTAGE);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("5697F250", tl_5697F250_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhallway, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(18));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_doorslam.8ad", SOUND_CHANNEL_SOUND));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4576860E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_COMEDY, 18));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_SHIZU, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_KENJI));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_impact2.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0x40280DAC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF02A0EF3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhisao, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEC4CD976);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 3));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_SHIZU, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDBB6D5AB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 4));
                ks::SceneManager::set_line_hash(0xB3C02E1F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 5));
                ks::SceneManager::set_line_hash(0xD7E585CF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 6));
                ks::SceneManager::set_line_hash(0x2B70C73B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4E9D9FA9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 8));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x199E5DB0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 9));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3BBBC93B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 10));
                ks::SceneManager::set_line_hash(0xC63083E3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 11));
                ks::SceneManager::set_line_hash(0x31DCF63A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5456549A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 13));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF7B54B6D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 14));
                ks::SceneManager::set_line_hash(0xEF8A33C6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0xF644CE40);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 16));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(420));
                ks::SceneManager::set_line_hash(0xBBCD8096);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                ks::SceneManager::set_line_hash(0x82AAEFA8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7455E83D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 19));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5F30C620);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 20));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDC9BEA67);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 21));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCE3A0C25);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 22));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xAC549369);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 23));
                ks::SceneManager::set_line_hash(0x291DF836);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 24));
                ScriptA1FridayRu::a1_friday_home_field_advantage__menu_question_0();
                if (ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_home_field_advantage__condition_0_0();
                } 
                
            
            }
            SCENE_INLINE void a1_friday_slow_recovery() {
                ks::SceneManager::set_label(LABEL_A1_FRIDAY_SLOW_RECOVERY);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("C8FC0CC9", tl_C8FC0CC9_ru_intl));
                if (!ks::in_replay) {
                }
                if (ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_slow_recovery__condition_0_0();
                } 
                else {
                    ScriptA1FridayRu::a1_friday_slow_recovery__condition_0_1();
                } 
                
            
                ks::SceneManager::set_line_hash(0x4797AF13);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x3BD0FF71);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background_position(-8, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -90, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_ANOTHER, 120));
                ks::SceneManager::set_line_hash(0x9F79F845);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 2));
                ks::SceneManager::set_line_hash(0x8565E947);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 3));
                ks::SceneManager::set_line_hash(0x713FFEFF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5E8B44AB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                ks::SceneManager::set_line_hash(0x7CF13363);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0x372002E5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(-8, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -90, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE477B809);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 8));
                ks::SceneManager::set_line_hash(0xA5C8A821);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0x7D67762C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 10));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC09FCEE4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(-8, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -90, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ScriptA1FridayRu::a1_friday_slow_recovery__menu_question_0();
                if (ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_slow_recovery__condition_1_0();
                } 
                
            
            }
            SCENE_INLINE void a1_friday_no_recovery() {
                ks::SceneManager::set_label(LABEL_A1_FRIDAY_NO_RECOVERY);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("C2A7D689", tl_C2A7D689_ru_intl));
                if (!ks::in_replay) {
                }
                if (ks::progress.get_tired()) {
                    ScriptA1FridayRu::a1_friday_no_recovery__condition_0_0();
                } 
                
            
                if (!ks::progress.go_through_shizu() || ks::progress.kick_shizu) {
                    ScriptA1FridayRu::a1_friday_no_recovery__condition_1_0();
                } 
                
            
                if (ks::progress.get_tired() && ks::progress.go_through_shizu()) {
                    ScriptA1FridayRu::a1_friday_no_recovery__condition_2_0();
                } 
                else if (!ks::progress.kick_shizu || ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_no_recovery__condition_2_1();
                } 
                else {
                    ScriptA1FridayRu::a1_friday_no_recovery__condition_2_2();
                } 
                
            
                if (ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_no_recovery__condition_3_0();
                } 
                
            
            }
            SCENE_INLINE void a1_friday_no_free_lunch() {
                ks::SceneManager::set_label(LABEL_A1_FRIDAY_NO_FREE_LUNCH);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("63FD258B", tl_63FD258B_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_council, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x405589CC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x96AEDCA8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 1));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB0CE5ACC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 2));
                ks::SceneManager::set_line_hash(0x572D922D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0x57BED560);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 4));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_EASE, 240));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_cross, bn::regular_bg_items::shizu_bg_cross, bn::sprite_items::shizu_spr_cross_wut, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA9E185C9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frustrated, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2F987FD9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 6));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE5DCB9C7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 7));
                ks::SceneManager::set_line_hash(0x904EB39F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 8));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x446DEC46);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_cross, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6664BFCE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 10));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBAC5744E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 11));
                if (ks::progress.get_tired() || ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_no_free_lunch__condition_0_0();
                } 
                
            
                // renpy.music.play(music_ease, fadein=4.0, if_changed=True); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x72C2E47F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 12));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x65093E6D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 13));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_cross, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF3EB537C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 14));
                ks::SceneManager::set_line_hash(0xA414956A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x18CE50FB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 16));
                ks::SceneManager::set_line_hash(0x6D4A1320);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 17));
                ks::SceneManager::set_line_hash(0xC9E397A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                ks::SceneManager::set_line_hash(0x831818F6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 19));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x261ECBFD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 20));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDD3C1389);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 21));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x10ACF457);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 22));
                ks::SceneManager::set_line_hash(0x1A8354B3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 23));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x971BA578);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 24));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_angry, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE26E6514);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                ks::SceneManager::set_line_hash(0xC4E7CC97);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 26));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1458C77B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 27));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x50063FD1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 28));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2DA968BF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 29));
                ks::SceneManager::set_line_hash(0x2BB99939);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 30));
                ks::SceneManager::set_line_hash(0x0CC0315B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 31));
                ks::SceneManager::set_line_hash(0x379D3B27);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 32));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA4238251);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEB0E4E4F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 34));
                ks::SceneManager::set_line_hash(0x435C226E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 35));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFCBD0407);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 36));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0B55317E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 37));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2981CD82);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 38));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB7232129);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 39));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_warningbell.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0x58DECC27);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 40));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA1D1B32C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 41));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x76B77612);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 42));
                ks::SceneManager::set_line_hash(0x3123046F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 43));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_cross, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0E1BA43B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 44));
                ks::SceneManager::set_line_hash(0xC0F069FF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 45));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_angry, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x391D5D9B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 46));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4AB149DF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 47));
                ks::SceneManager::set_line_hash(0x7F35F259);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 48));
                ks::SceneManager::set_line_hash(0x4AB841FB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 49));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x83503576);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 50));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD03FA7B1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 51));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9A30A887);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 52));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_blush, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF93CC216);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 53));
                ks::SceneManager::set_line_hash(0xAF493DE0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 54));
                ks::SceneManager::set_line_hash(0xDA22E8F3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 55));
                ks::SceneManager::set_line_hash(0x40317CC6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 56));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x27EC23F9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 57));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD4CC749D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 58));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_cross, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCB1066B8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 59));
                ks::SceneManager::set_line_hash(0x8901D4E2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 60));
                ks::SceneManager::set_line_hash(0xFEB0C4E0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 61));
                ks::SceneManager::set_line_hash(0x441DD192);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 62));
                ks::SceneManager::set_line_hash(0x0D26B3BF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 63));
                ks::SceneManager::set_line_hash(0xEC04621F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 64));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCDEBB2F0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 65));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF0CD7CB6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 66));
                ks::SceneManager::set_line_hash(0xD449379C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 67));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x845312FB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 68));
                ks::SceneManager::set_line_hash(0x96822E76);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 69));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFE2287C1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 70));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD1E865E7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 71));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC00A4D65);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 72));
                ks::SceneManager::set_line_hash(0x4687C7EA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 73));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC1814798);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 74));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF068A718);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 75));
                IF_NOT_EXIT(ks::SceneManager::music_stop(360));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEC1F2877);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 76));
                ks::SceneManager::set_line_hash(0xCBB48ADE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 77));
                ks::SceneManager::set_line_hash(0x25CA8742);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 78));
                ks::SceneManager::set_line_hash(0x80850934);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 79));
                ks::SceneManager::set_line_hash(0xC8834590);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 80));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_normalbell.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0xB8DFC915);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 81));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA8DCB1C4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 82));
                IF_NOT_EXIT(ks::SceneManager::set_background_transition(SCENE_TRANSITION_SHORTTIMESKIP));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0BC75985);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 83));
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 90));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                if (ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_no_free_lunch__condition_1_0();
                } 
                
            
            }
            SCENE_INLINE void a1_friday_foot_and_mouth() {
                ks::SceneManager::set_label(LABEL_A1_FRIDAY_FOOT_AND_MOUTH);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("D29AF3D8", tl_D29AF3D8_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ScriptA1FridayRu::class_goes_lazily()); // DIRECT CALL
                IF_NOT_EXIT(ks::SceneManager::set_textdb("D29AF3D8", tl_D29AF3D8_ru_intl));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                // TODO: Show crowd
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_crowd_indoors.8ad", SOUND_CHANNEL_AMBIENT, 18));
                if (ks::progress.promised && ks::progress.go_for_it && !ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_foot_and_mouth__condition_0_0();
                } 
                else {
                    ScriptA1FridayRu::a1_friday_foot_and_mouth__condition_0_1();
                } 
                
            
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 60));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_staircase1, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCB3EEE09);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0xE3AF5546);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0xD33530CB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                // renpy.music.set_volume(0.5, 0.0, channel="ambient"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_rooftop.8ad", SOUND_CHANNEL_AMBIENT, 120));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_roof, -8, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedgrin, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x64A5F929);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed_silhouette, bn::regular_bg_items::rin_bg_relaxed_silhouette, bn::sprite_items::rin_spr_relaxed_surprised_silhouette, PALETTE_VARIANT_DEFAULT, 184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_EMI, -80, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_RIN, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_shock, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x166DF26D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_hes, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_EMI, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xED497C19);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 5));
                ks::SceneManager::set_line_hash(0x32A1761D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed, bn::regular_bg_items::rin_bg_relaxed, bn::sprite_items::rin_spr_relaxed_surprised, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_RIN, 120));
                ks::SceneManager::set_line_hash(0xABEDBA6C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 7));
                ks::SceneManager::set_line_hash(0x1E0B9EEA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA2685153);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 9));
                ks::SceneManager::set_line_hash(0xE11164B4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0x268A6C40);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 11));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed, bn::regular_bg_items::rin_bg_relaxed, bn::sprite_items::rin_spr_relaxed_nonchalant, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7B7A4347);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0x1E30C987);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 13));
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                ks::SceneManager::set_line_hash(0x261C4FCE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                ks::SceneManager::set_line_hash(0x4F65D12D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedgrin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6541A304);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 16));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpan, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6468DF01);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 17));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7D4E8290);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 18));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpanamused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9BAF25C8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 19));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_RIN));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_EMI));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6BA1C355);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 20));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_SOOTHING, 30));
                ks::SceneManager::set_line_hash(0x5D127BC3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 21));
                ks::SceneManager::set_line_hash(0x9BE52BB8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 22));
                ks::SceneManager::set_line_hash(0x423B76B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 23));
                ks::SceneManager::set_line_hash(0xE30C33CE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 24));
                ks::SceneManager::set_line_hash(0x57DA7559);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                ks::SceneManager::set_line_hash(0x7C88CE4D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                ks::SceneManager::set_line_hash(0x4F920888);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 27));
                ks::SceneManager::set_line_hash(0x6368F6A3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 28));
                ks::SceneManager::set_line_hash(0x9AAC60ED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 29));
                ks::SceneManager::set_line_hash(0x83FA1D07);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 30));
                ks::SceneManager::set_line_hash(0x9CDE50DA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 31));
                ks::SceneManager::set_line_hash(0xC20E2A62);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 32));
                ks::SceneManager::set_line_hash(0x96306B73);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                ks::SceneManager::set_line_hash(0xE9F26D24);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 34));
                ks::SceneManager::set_line_hash(0x54E1D82B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 35));
                ks::SceneManager::set_line_hash(0x42B34755);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpannormal, PALETTE_VARIANT_DEFAULT, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_happy, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD487AD96);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 37));
                ks::SceneManager::set_line_hash(0x7B96DB93);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 38));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_EMI, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_RIN, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(8, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_happy, PALETTE_VARIANT_DEFAULT, -60, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_deadpannormal_close, PALETTE_VARIANT_DEFAULT, 60, 0));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6BD2DA3F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 39));
                ks::SceneManager::set_line_hash(0xB811AFB7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 40));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedhappy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x970D6245);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 41));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_proud, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x367994D1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 42));
                ks::SceneManager::set_line_hash(0x1D1FF5C7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 43));
                ks::SceneManager::set_line_hash(0x4217EB85);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 44));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_amused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4247E48E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 45));
                ks::SceneManager::set_line_hash(0x2EAC68BA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 46));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_awayabsent_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCCA6009E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 47));
                ks::SceneManager::set_line_hash(0xF33992F4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 48));
                ks::SceneManager::set_line_hash(0x417D40F4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 49));
                ks::SceneManager::set_line_hash(0x13A2B64A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 50));
                ks::SceneManager::set_line_hash(0xEB251DB7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 51));
                ks::SceneManager::set_line_hash(0xA1CC5216);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 52));
                ks::SceneManager::set_line_hash(0x2B799592);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 53));
                ks::SceneManager::set_line_hash(0x595319EE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 54));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_absent_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB5C6DC00);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 55));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x22AEC382);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 56));
                ks::SceneManager::set_line_hash(0x456D0E4F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 57));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedhappy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9E917733);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 58));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_proud, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC8F0177C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 59));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_deadpan_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE7DCA5B8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 60));
                ks::SceneManager::set_line_hash(0x93C46404);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 61));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_annoyed, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7309A0BC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 62));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_deadpandelight_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD30447C3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 63));
                ks::SceneManager::set_line_hash(0x31E09863);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 64));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed_close, bn::regular_bg_items::rin_bg_relaxed_close, bn::sprite_items::rin_spr_relaxed_surprised_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB341A050);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 65));
                ks::SceneManager::set_line_hash(0x913D2833);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 66));
                ks::SceneManager::set_line_hash(0x3519E4DB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 67));
                ks::SceneManager::set_line_hash(0x1470F1CE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 68));
                ks::SceneManager::set_line_hash(0xF21B0963);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 69));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_awayabsent_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x56D22CA2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 70));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA9D6FCE7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 71));
                ks::SceneManager::set_line_hash(0x4B6DBD87);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 72));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_deadpannormal_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0746EB5E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 73));
                ks::SceneManager::set_line_hash(0x2E5021A6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 74));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedgrin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3E87E31F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 75));
                ks::SceneManager::set_line_hash(0x682D9A9E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 76));
                ks::SceneManager::set_line_hash(0xC422C843);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 77));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBADD8EC4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 78));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEDCA8D75);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 79));
                ks::SceneManager::set_line_hash(0x38C03843);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 80));
                ks::SceneManager::set_line_hash(0x1ACC2BB9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 81));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_deadpan_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB68574A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 82));
                ks::SceneManager::set_line_hash(0x3231E6D7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 83));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_surprised_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA51FB6F8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 84));
                ks::SceneManager::set_line_hash(0x5A636732);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 85));
                ks::SceneManager::set_line_hash(0x2B26039B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 86));
                ks::SceneManager::set_line_hash(0x8F62C342);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 87));
                ks::SceneManager::set_line_hash(0x8A1C9D0E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 88));
                ks::SceneManager::set_line_hash(0x84CD2EBC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 89));
                ks::SceneManager::set_line_hash(0x00D351E5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 90));
                ks::SceneManager::set_line_hash(0x922363A2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 91));
                ks::SceneManager::set_line_hash(0x0AB6692F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 92));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_lucid_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5027B5A5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 93));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_absent_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x42A75521);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 94));
                ks::SceneManager::set_line_hash(0x81E5833A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 95));
                ks::SceneManager::set_line_hash(0xEA2DB4B0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 96));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCA3F254E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 97));
                ks::SceneManager::set_line_hash(0xAC464BDF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 98));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_deadpan_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x973846D1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 99));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_shock, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9E56E604);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 100));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedgrin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC55B62A1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 101));
                ks::SceneManager::set_line_hash(0x75223F87);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 102));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_awayabsent_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x72B933A2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 103));
                ks::SceneManager::set_line_hash(0x0E136703);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 104));
                ks::SceneManager::set_line_hash(0x7C43D418);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 105));
                ks::SceneManager::set_line_hash(0x16F87EAB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 106));
                ks::SceneManager::set_line_hash(0x151A5DD9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 107));
                ks::SceneManager::set_line_hash(0x0189353D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 108));
                ks::SceneManager::set_line_hash(0x34477174);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 109));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x979C52ED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 110));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_absent_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCC74E881);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 111));
                ks::SceneManager::set_line_hash(0xC645BFBF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 112));
                ks::SceneManager::set_line_hash(0x147D67A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 113));
                ks::SceneManager::set_line_hash(0xED6A2F9F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 114));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_amused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2C898202);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 115));
                ks::SceneManager::set_line_hash(0x295F325E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 116));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_proud, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB8F930F7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 117));
                ks::SceneManager::set_line_hash(0x58C78828);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 118));
                ks::SceneManager::set_line_hash(0x8423BB82);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 119));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_annoyed, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x25C7577E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 120));
                ks::SceneManager::set_line_hash(0xD680D17A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 121));
                ks::SceneManager::set_line_hash(0x5F7B4A6C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 122));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedgrin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x349A6465);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 123));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_sad, bn::regular_bg_items::emi_bg_sad, bn::sprite_items::emi_spr_sad_depressed, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3E2A88B7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 124));
                ks::SceneManager::set_line_hash(0xEA4A5286);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 125));
                ks::SceneManager::set_line_hash(0x0FCE6E5D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 126));
                ks::SceneManager::set_line_hash(0xF28E377D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 127));
                ks::SceneManager::set_line_hash(0xC3B1D116);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 128));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x26A54306);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 129));
                ks::SceneManager::set_line_hash(0xC836493B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 130));
                ks::SceneManager::set_line_hash(0xE05D4E44);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 131));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_warningbell.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0xCCF08702);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 132));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_hes, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE6D89D92);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 133));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic_close, bn::regular_bg_items::rin_bg_basic_close, bn::sprite_items::rin_spr_basic_deadpan_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x112AA95F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 134));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_annoyed, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA519B596);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 135));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed_close, bn::regular_bg_items::rin_bg_relaxed_close, bn::sprite_items::rin_spr_relaxed_boredom_close, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA9F37592);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 136));
                IF_NOT_EXIT(ks::SceneManager::music_stop(240));
                ks::SceneManager::set_line_hash(0x7DC72BFE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 137));
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 120));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_staircase1, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9E984D6B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 138));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD07C7E5B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 139));
                // renpy.music.set_volume(1.0, 0.0, channel="ambient"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_library, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2CBB7606);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 140));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_impact2.8ad", SOUND_CHANNEL_SOUND));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_YUUKO, ks::sprite_metas::yuuko_up, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_panic, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_YUUKO, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_HAPPINESS, 120));
                ks::SceneManager::set_line_hash(0x8FDF52D9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 141));
                ks::SceneManager::set_line_hash(0x9F8CD934);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 142));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_YUUKO, ks::sprite_metas::yuuko_up, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_worried, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA4634187);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::yu, 143));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_YUUKO, ks::sprite_metas::yuuko_up, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_neurotic, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x04B21560);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::yu, 144));
                ks::SceneManager::set_line_hash(0x55894CE1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 145));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_YUUKO));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x13A2978A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 146));
                IF_NOT_EXIT(ks::SceneManager::music_stop(300));
                ks::SceneManager::set_line_hash(0xFDC9539B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 147));
                ks::SceneManager::set_line_hash(0x852ADC36);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 148));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::hana_library_read, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD0C2BE83);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 149));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_library_ss, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_TRANQUIL, 360));
                ks::SceneManager::set_line_hash(0x2621B745);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 150));
                ks::SceneManager::set_line_hash(0x56F6699B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 151));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_courtyard_ss, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x51F7F4FA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 152));
                if (ks::progress.get_tired() || ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_foot_and_mouth__condition_1_0();
                } 
                
            
                if (ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_foot_and_mouth__condition_2_0();
                } 
                
            
            }
            SCENE_INLINE void a1_friday_mind_your_step() {
                ks::SceneManager::set_label(LABEL_A1_FRIDAY_MIND_YOUR_STEP);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("03DA99B5", tl_03DA99B5_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_courtyard_ss, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // renpy.music.play(music_tranquil, fadein=3.0, if_changed=True); TODO: unknown assignment
                ks::SceneManager::set_line_hash(0x9B0DB7C8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_gate_ss, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x587F1AA7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_road_ss, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_back, bn::regular_bg_items::lilly_bg_back, bn::sprite_items::lilly_spr_back_smileclosed, PALETTE_VARIANT_SPRITE_SUNSET, 0, 0));
                // TODO: Show lillyprop
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4E996F30);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_surprised, PALETTE_VARIANT_SPRITE_SUNSET));
                // TODO: Hide lillyprop
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x149B4045);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0x984239DC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 4));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x49648EE8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBBDA78A7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 6));
                ks::SceneManager::set_line_hash(0x32DDF16D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 7));
                ks::SceneManager::set_line_hash(0x26A33B08);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x0F64C5DB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 9));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x17C60443);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0x1873ECD2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 11));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_ara, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x00929432);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 12));
                ks::SceneManager::set_line_hash(0x12D159FE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 13));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x12403D9A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 14));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_surprised, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3CF046D9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0x5EEE1E70);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 16));
                ks::SceneManager::set_line_hash(0x250B54C5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                ks::SceneManager::set_line_hash(0xA8583998);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 18));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x96E7E746);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                ks::SceneManager::set_line_hash(0xEBFB4CA1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 20));
                ks::SceneManager::set_line_hash(0xC7044B40);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 21));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEA5B993F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 22));
                ks::SceneManager::set_line_hash(0xA188329A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 23));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smileclosed, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB4A4D1C0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 24));
                ks::SceneManager::set_line_hash(0x95BBCFC6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                ks::SceneManager::set_line_hash(0x9CD598E1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                ks::SceneManager::set_line_hash(0x61E8464D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 27));
                ks::SceneManager::set_line_hash(0x559688D8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 28));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_giggle, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD502E160);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 29));
                ks::SceneManager::set_line_hash(0x136A3939);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 30));
                ks::SceneManager::set_line_hash(0xB7AF8001);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 31));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC9C5287C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 32));
                ks::SceneManager::set_line_hash(0x985073C9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                ks::SceneManager::set_line_hash(0xF83E0BE0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 34));
                ks::SceneManager::set_line_hash(0x9048F657);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 35));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smileclosed, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1E0C371D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                ks::SceneManager::set_line_hash(0x7F5EF4BB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 37));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEDFBD01A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 38));
                ks::SceneManager::set_line_hash(0x5715B0D1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 39));
                ks::SceneManager::set_line_hash(0x14DFCDBD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 40));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::suburb_roadcenter_ss, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_reminisce, PALETTE_VARIANT_SPRITE_SUNSET, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(360));
                ks::SceneManager::set_line_hash(0x2111B805);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 41));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC83A9564);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 42));
                ks::SceneManager::set_line_hash(0xCBEDD6BA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 43));
                ks::SceneManager::set_line_hash(0xD411A8CA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 44));
                ks::SceneManager::set_line_hash(0x0730A2EA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 45));
                ks::SceneManager::set_line_hash(0x4B6C5F75);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 46));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_planned, PALETTE_VARIANT_SPRITE_SUNSET));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8BC30994);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 47));
                ks::SceneManager::set_line_hash(0xD782FC68);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 48));
                ks::SceneManager::set_line_hash(0x6EB94C6B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 49));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::suburb_konbiniext_ss, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_DAILY, 120));
                ks::SceneManager::set_line_hash(0x3B080086);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 50));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::suburb_konbiniint, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2590DE8A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 51));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x78C1359A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 52));
                ks::SceneManager::set_line_hash(0x57556F2D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 53));
                ks::SceneManager::set_line_hash(0x6507B2B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 54));
                ks::SceneManager::set_line_hash(0xC33D34CE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 55));
                ks::SceneManager::set_line_hash(0x2AA63BA4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 56));
                ks::SceneManager::set_line_hash(0x9CFC0350);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 57));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_basic, bn::regular_bg_items::lilly_bg_basic, bn::sprite_items::lilly_spr_basic_smileclosed, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_LILLY, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF51FDBF7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 58));
                ks::SceneManager::set_line_hash(0x1862D3D9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 59));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_basic, bn::regular_bg_items::lilly_bg_basic, bn::sprite_items::lilly_spr_basic_smileclosed, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB5BEEB57);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 60));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_basic, bn::regular_bg_items::lilly_bg_basic, bn::sprite_items::lilly_spr_basic_concerned, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDC78B81A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 61));
                ks::SceneManager::set_line_hash(0x96109335);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 62));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_basic, bn::regular_bg_items::lilly_bg_basic, bn::sprite_items::lilly_spr_basic_smileclosed, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x86E153BC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 63));
                ks::SceneManager::set_line_hash(0x77AE4615);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 64));
                ks::SceneManager::set_line_hash(0x002B44E3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 65));
                ks::SceneManager::set_line_hash(0x8CB704A1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 66));
                ks::SceneManager::set_line_hash(0x9793826C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 67));
                ks::SceneManager::set_line_hash(0x9DE8DCB7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 68));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_basic, bn::regular_bg_items::lilly_bg_basic, bn::sprite_items::lilly_spr_basic_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x04AF807C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 69));
                ks::SceneManager::set_line_hash(0x57C6DF80);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 70));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_basic, bn::regular_bg_items::lilly_bg_basic, bn::sprite_items::lilly_spr_basic_smileclosed, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE9FA94A6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 71));
                ks::SceneManager::set_line_hash(0x5B70FEB6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 72));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::misc_sky_ni, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x427CDC43);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 73));
                ks::SceneManager::set_line_hash(0xB1DC39D1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 74));
                ks::SceneManager::set_line_hash(0xBC21EFF1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 75));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::suburb_konbiniext_ni, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_listen, PALETTE_VARIANT_SPRITE_NIGHT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1AFA69ED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 76));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_sleepy, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x685E5F2D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 77));
                ks::SceneManager::set_line_hash(0xCFB76AB7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 78));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x776D4F05);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 79));
                ks::SceneManager::set_line_hash(0xE2BB4825);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 80));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::suburb_roadcenter_ni, -8, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9B0EA5BA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 81));
                ks::SceneManager::set_line_hash(0x8F49C37F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 82));
                ks::SceneManager::set_line_hash(0x0D2A905A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 83));
                ks::SceneManager::set_line_hash(0x6EEA6516);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 84));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed, bn::regular_bg_items::rin_bg_relaxed, bn::sprite_items::rin_spr_relaxed_nonchalant, PALETTE_VARIANT_SPRITE_NIGHT, 184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_RIN, 80, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(480));
                ks::SceneManager::set_line_hash(0x133BD8AE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 85));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_surprised, PALETTE_VARIANT_SPRITE_NIGHT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9DA30FC0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 86));
                ks::SceneManager::set_line_hash(0xEC7E3D61);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 87));
                ks::SceneManager::set_line_hash(0x3F8738B5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 88));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x512E8B35);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 89));
                ks::SceneManager::set_line_hash(0xDCF3D46D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 90));
                ks::SceneManager::set_line_hash(0x38F9E2EA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 91));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_awayabsent, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background_position(8, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_RIN, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_LILLY, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xED1DA954);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 92));
                ks::SceneManager::set_line_hash(0xBA7C3794);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 93));
                ks::SceneManager::set_line_hash(0xF80330C1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 94));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_lucid, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_awayabsent, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x40ABA271);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 95));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_absent, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBD4DFEED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 96));
                ks::SceneManager::set_line_hash(0x52369E4F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 97));
                ks::SceneManager::set_line_hash(0xCB0F2F35);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 98));
                ks::SceneManager::set_line_hash(0xACDEFBA8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 99));
                ks::SceneManager::set_line_hash(0x8033AC0B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 100));
                ks::SceneManager::set_line_hash(0x7DBB065E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 101));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpan, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x18F5BAC6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 102));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_RIN, 30));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpannormal, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBAE8A643);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 103));
                ks::SceneManager::set_line_hash(0xFB3220AE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 104));
                ks::SceneManager::set_line_hash(0x7283159F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 105));
                ks::SceneManager::set_line_hash(0x03E154BF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 106));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_negative, bn::regular_bg_items::rin_bg_negative, bn::sprite_items::rin_spr_negative_spaciness, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC2834CAB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 107));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_absent, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x584FE7AA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 108));
                ks::SceneManager::set_line_hash(0x92A66C63);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 109));
                ks::SceneManager::set_line_hash(0x3AAF51C8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 110));
                ks::SceneManager::set_line_hash(0xB31E8A36);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 111));
                ks::SceneManager::set_line_hash(0x82CEDFAC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 112));
                ks::SceneManager::set_line_hash(0x6DF65B41);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 113));
                ks::SceneManager::set_line_hash(0x946608C5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 114));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_concerned, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA4CAD5B6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 115));
                ks::SceneManager::set_line_hash(0xA2AF9923);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 116));
                ks::SceneManager::set_line_hash(0xA0800027);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 117));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpan, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE2DCEAE1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 118));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed, bn::regular_bg_items::rin_bg_relaxed, bn::sprite_items::rin_spr_relaxed_nonchalant, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x06F6F6F2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 119));
                ks::SceneManager::set_line_hash(0xF817960A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 120));
                ks::SceneManager::set_line_hash(0xB8AFA404);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 121));
                ks::SceneManager::set_line_hash(0xEF4E5ABA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 122));
                ks::SceneManager::set_line_hash(0x761A192B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 123));
                ks::SceneManager::set_line_hash(0x2559F42E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 124));
                ks::SceneManager::set_line_hash(0xF7F7A456);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 125));
                ks::SceneManager::set_line_hash(0x7F63C0C6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 126));
                ks::SceneManager::set_line_hash(0x3B6B1908);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 127));
                ks::SceneManager::set_line_hash(0xDF97D3AD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 128));
                ks::SceneManager::set_line_hash(0x6D3EE8D2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 129));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_negative, bn::regular_bg_items::rin_bg_negative, bn::sprite_items::rin_spr_negative_annoyed, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x93C9BB14);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 130));
                ks::SceneManager::set_line_hash(0x00BCF367);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 131));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x651CB8B5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 132));
                ks::SceneManager::set_line_hash(0x8FE90FE0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 133));
                ks::SceneManager::set_line_hash(0x44742617);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 134));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpanupset, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBB8D44CF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 135));
                ks::SceneManager::set_line_hash(0xD7C52963);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 136));
                ks::SceneManager::set_line_hash(0x15ADE257);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 137));
                ks::SceneManager::set_line_hash(0x9D06B44C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 138));
                ks::SceneManager::set_line_hash(0xE167567C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 139));
                ks::SceneManager::set_line_hash(0x868E8208);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 140));
                ks::SceneManager::set_line_hash(0x7D0D1153);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 141));
                ks::SceneManager::set_line_hash(0x0940A289);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 142));
                ks::SceneManager::set_line_hash(0x3B44BB03);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 143));
                ks::SceneManager::set_line_hash(0xABDEACBB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 144));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed, bn::regular_bg_items::rin_bg_relaxed, bn::sprite_items::rin_spr_relaxed_surprised, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_surprised, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1AC72D00);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 145));
                ks::SceneManager::set_line_hash(0xC098DE39);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 146));
                ks::SceneManager::set_line_hash(0xE8657901);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 147));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed, bn::regular_bg_items::rin_bg_relaxed, bn::sprite_items::rin_spr_relaxed_disgust, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_listen, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5630C81E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 148));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_displeased, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD50C1E4D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 149));
                ks::SceneManager::set_line_hash(0x37AE10E2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 150));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpanupset, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7F3AFC77);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 151));
                ks::SceneManager::set_line_hash(0xAF294086);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 152));
                ks::SceneManager::set_line_hash(0xE4F55A2B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 153));
                ks::SceneManager::set_line_hash(0xAFB05B7A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 154));
                ks::SceneManager::set_line_hash(0xCA4C1F6C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 155));
                ks::SceneManager::set_line_hash(0x19850D31);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 156));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpannormal, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBE9761F9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 157));
                ks::SceneManager::set_line_hash(0xDAECCF5C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 158));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1B92D049);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 159));
                ks::SceneManager::set_line_hash(0x1A231AFB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 160));
                ks::SceneManager::set_line_hash(0x56CEC7FD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 161));
                ks::SceneManager::set_line_hash(0x2989DD41);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 162));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_awayabsent, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0669D200);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_absent, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                ks::SceneManager::set_line_hash(0x2382702B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 164));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_road_ni, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // renpy.music.set_volume(0.1, 0.0, channel="ambient"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_cicadas.8ad", SOUND_CHANNEL_AMBIENT));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_DREAMY, 120));
                ks::SceneManager::set_line_hash(0xB135E4AA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 165));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_awayabsent, PALETTE_VARIANT_SPRITE_NIGHT, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smileclosed, PALETTE_VARIANT_SPRITE_NIGHT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5FB91670);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 166));
                ks::SceneManager::set_line_hash(0x595942AB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 167));
                ks::SceneManager::set_line_hash(0x4614981C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 168));
                ks::SceneManager::set_line_hash(0x4B2EA2C2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 169));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpan, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0BB7357D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 170));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA0BF7A18);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 171));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_deadpannormal, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6FCF8C7D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 172));
                ks::SceneManager::set_line_hash(0x12A3F2AF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 173));
                ks::SceneManager::set_line_hash(0x9CD7CABA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 174));
                ks::SceneManager::set_line_hash(0xB5EDC0AE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 175));
                ks::SceneManager::set_line_hash(0x6A0A7334);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 176));
                ks::SceneManager::set_line_hash(0x26F20661);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 177));
                ks::SceneManager::set_line_hash(0x3F8C039C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 178));
                ks::SceneManager::set_line_hash(0x7A96003E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 179));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_concerned, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4ADA70BB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 180));
                ks::SceneManager::set_line_hash(0x5BB4A32B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 181));
                ks::SceneManager::set_line_hash(0xDBB28A4A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 182));
                ks::SceneManager::set_line_hash(0x14DBA702);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 183));
                ks::SceneManager::set_line_hash(0x22CC9297);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 184));
                ScriptA1FridayRu::a1_friday_mind_your_step__menu_question_0();
                if (ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_mind_your_step__condition_0_0();
                } 
                
            
            }
            static void a1_friday() {
                SKIP_IF_LOAD_ANOTHER_SCENE(SCRIPT_A1_FRIDAY);
                ks::SceneManager::set_script(SCRIPT_A1_FRIDAY);
                IF_NOT_EXIT(ks::SceneManager::init_savedata(ks::progress));
                IF_NOT_EXIT(ks::SceneManager::set(ks::SceneManager("script_a1_friday", "ru")));
            
                IF_NOT_EXIT(ks::SceneManager::timeskip()); // INLINE CALL
                if (ks::progress.promised) {
                    ScriptA1FridayRu::a1_friday__condition_0_0();
                } 
                
            
                if (!ks::progress.promised || !ks::progress.go_for_it) {
                    ScriptA1FridayRu::a1_friday__condition_1_0();
                } 
                
            
                if (!ks::progress.get_tired() && ks::progress.go_through_shizu()) {
                    ScriptA1FridayRu::a1_friday__condition_2_0();
                } 
                
            
                if (ks::progress.get_tired() || !ks::progress.go_through_shizu() || ks::progress.kick_shizu) {
                    ScriptA1FridayRu::a1_friday__condition_3_0();
                } 
                
            
                if ((ks::progress.go_for_it && ks::progress.are_student_council) || (!ks::progress.go_for_it && !ks::progress.kick_shizu)) {
                    ScriptA1FridayRu::a1_friday__condition_4_0();
                } 
                else {
                    ScriptA1FridayRu::a1_friday__condition_4_1();
                } 
                
            
            }
            SCENE_INLINE void class_goes_lazily() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("D7FBC85A", tl_D7FBC85A_ru_intl));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_NORMAL, 180));
                ks::SceneManager::set_line_hash(0x0356EE68);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x0E2C7194);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0x54F7D609);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDB697F33);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 3));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x538369DD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 4));
                ks::SceneManager::set_line_hash(0xC1B3FCBB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 5));
                ks::SceneManager::set_line_hash(0x2B5D3F2A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_irritated, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6E68DDB0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 7));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA3EAC2B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 8));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_normalbell.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0xF4987DE0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0x8F049C2A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                // TODO: Show crowd
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_crowd_indoors.8ad", SOUND_CHANNEL_AMBIENT, 18));
                ks::SceneManager::set_line_hash(0x04E0509A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                return;
            }
            SCENE_INLINE void mas_doesnt_bother() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("B0381F35", tl_B0381F35_ru_intl));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                ks::SceneManager::set_line_hash(0x794D733D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_normalbell.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0x2E990E57);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                // TODO: Show crowd
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_crowd_indoors.8ad", SOUND_CHANNEL_AMBIENT, 18));
                ks::SceneManager::set_line_hash(0x3926CAC3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                return;
            }
            SCENE_INLINE void choice_go_for_it() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("2DC5D5B3", tl_2DC5D5B3_ru_intl));
                ks::SceneManager::set_line_hash(0xC1068A3A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x18319741);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_track_running, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFE79AE36);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0xA48B91F9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0xE1D87BAA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited_gym, bn::regular_bg_items::emi_bg_excited_gym, bn::sprite_items::emi_spr_excited_proud_gym, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x831B5A45);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 5));
                ks::SceneManager::set_line_hash(0x33631255);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 6));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited_gym, bn::regular_bg_items::emi_bg_excited_gym, bn::sprite_items::emi_spr_excited_laugh_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_EMI, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_EMI));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_emipacing.8ad", SOUND_CHANNEL_AMBIENT));
                ks::SceneManager::set_line_hash(0x08CD5004);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0xC6981BEB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x47516BF7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0xA2DD8B70);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0xA183ADA8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                ks::SceneManager::set_line_hash(0xC11D0284);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0x0D7862AB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 13));
                ks::SceneManager::set_line_hash(0x99AA9E85);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                ks::SceneManager::set_line_hash(0x602BB0B4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0x659B901C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                IF_NOT_EXIT(ks::SceneManager::music_stop(12));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xAEF70717);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                ks::SceneManager::set_line_hash(0x5E6B4A2B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_track_on, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6C1AF0D8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 12));
                ks::SceneManager::set_line_hash(0x3B84570B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 20));
                ks::SceneManager::set_line_hash(0xC2A6774D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 21));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_emisprinting.8ad", SOUND_CHANNEL_AMBIENT));
                ks::SceneManager::set_line_hash(0x659A98D8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 22));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_shock_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_EMI, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 6));
                ks::SceneManager::set_line_hash(0x4587E829);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 23));
                ks::SceneManager::set_line_hash(0x6CBEE0B2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 24));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x243AC928);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                ks::SceneManager::set_line_hash(0xFB514F5E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xACA6FEE5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 27));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_hes_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA65A6FEE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 28));
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_SHUTEYEFAST, 0));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x41D2D929);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 29));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(60));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD7E9A5DE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 30));
                ks::SceneManager::set_line_hash(0xFA43BE0A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 31));
                ks::SceneManager::set_line_hash(0xADC05FA7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 32));
                ks::SceneManager::set_line_hash(0xA37EBE30);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_RAIN, 120));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_track_on, 0, 0, SCENE_TRANSITION_OPENEYE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_hes_gym, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA3B0F4B8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 34));
                ks::SceneManager::set_line_hash(0x340E2AA9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 35));
                ks::SceneManager::set_line_hash(0xB5ED4BD5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_sad_gym, bn::regular_bg_items::emi_bg_sad_gym, bn::sprite_items::emi_spr_sad_annoyed_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9B17DB82);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 37));
                ks::SceneManager::set_line_hash(0x83C566B7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 38));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_annoyed_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE3DAE7B2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 39));
                ks::SceneManager::set_line_hash(0xF9C5A256);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 40));
                ks::SceneManager::set_line_hash(0x96573779);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 41));
                ks::SceneManager::set_line_hash(0x39F28A42);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 42));
                ks::SceneManager::set_line_hash(0x3DA7E9D4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 43));
                ks::SceneManager::set_line_hash(0x37476ADF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 44));
                ks::SceneManager::set_line_hash(0x23B13857);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 45));
                ks::SceneManager::set_line_hash(0xDBFC4EFA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 46));
                IF_NOT_EXIT(ks::SceneManager::music_stop(60));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_nurseoffice, 8, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_shock_gym, PALETTE_VARIANT_DEFAULT, 184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_EMI, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFE451B88);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 47));
                ks::SceneManager::set_line_hash(0x5FD98B7D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 48));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_NURSE, 30));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_grin, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE064B8B8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 49));
                ks::SceneManager::set_line_hash(0x2B207629);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 50));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4E6961DD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 51));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited_gym, bn::regular_bg_items::emi_bg_excited_gym, bn::sprite_items::emi_spr_excited_sad_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE40628AB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 52));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB8553DF9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 53));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEADAED52);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 54));
                ks::SceneManager::set_line_hash(0x3C8FA006);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 55));
                ks::SceneManager::set_line_hash(0x911DE354);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 56));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCEE27C81);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 57));
                ks::SceneManager::set_line_hash(0xDE96BF64);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 58));
                ks::SceneManager::set_line_hash(0x05A68BEC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 59));
                ks::SceneManager::set_line_hash(0xAFB3DD7D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 60));
                ks::SceneManager::set_line_hash(0xFA117772);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 61));
                ks::SceneManager::set_line_hash(0x22B380E8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 62));
                ks::SceneManager::set_line_hash(0xB73CDE0A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 63));
                ks::SceneManager::set_line_hash(0x6ED6C313);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 64));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_hes_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDF32606E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 65));
                ks::SceneManager::set_line_hash(0x9AEB893A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 66));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_closedsweat_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC270BB12);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 67));
                ks::SceneManager::set_line_hash(0xE35CE342);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 68));
                ks::SceneManager::set_line_hash(0x8EFFDEC8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 69));
                ks::SceneManager::set_line_hash(0xF7013A21);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 70));
                ks::SceneManager::set_line_hash(0xEFEDB962);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 71));
                ks::SceneManager::set_line_hash(0x808AD875);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 72));
                ks::SceneManager::set_line_hash(0x2D2274D2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 73));
                ks::SceneManager::set_line_hash(0x75FC63D8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 74));
                ks::SceneManager::set_line_hash(0x73CE3CEC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 75));
                ks::SceneManager::set_line_hash(0x8904F436);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 76));
                ks::SceneManager::set_line_hash(0x06E90281);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 77));
                ks::SceneManager::set_line_hash(0x6A36F57B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 78));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(8, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_NURSE, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_EMI));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB138F0E1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 79));
                ks::SceneManager::set_line_hash(0xF84DFC07);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 80));
                ks::SceneManager::set_line_hash(0x542DC5D4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 81));
                ks::SceneManager::set_line_hash(0x933378E3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 82));
                ks::SceneManager::set_line_hash(0xAB152B55);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 83));
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_nurseoffice, 8, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x05809F64);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 84));
                ks::SceneManager::set_line_hash(0x9CBBD6DE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 85));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_sad_gym, bn::regular_bg_items::emi_bg_sad_gym, bn::sprite_items::emi_spr_sad_depressed_gym, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_DREAMY, 30));
                ks::SceneManager::set_line_hash(0x7C38D48D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 86));
                ks::SceneManager::set_line_hash(0x4B5249B2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 87));
                ks::SceneManager::set_line_hash(0x396CFFD7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 88));
                ks::SceneManager::set_line_hash(0x7AA77E30);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 89));
                ks::SceneManager::set_line_hash(0xB441E502);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 90));
                ks::SceneManager::set_line_hash(0xCB4D16F7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 91));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_sad_gym, bn::regular_bg_items::emi_bg_sad_gym, bn::sprite_items::emi_spr_sad_shy_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD40F929B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 92));
                ks::SceneManager::set_line_hash(0x4D3C3D87);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 93));
                ks::SceneManager::set_line_hash(0x6238C482);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 94));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited_gym, bn::regular_bg_items::emi_bg_excited_gym, bn::sprite_items::emi_spr_excited_proud_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB0AC98D9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 95));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_grin_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE5A1067C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 96));
                ks::SceneManager::set_line_hash(0xC5E01C65);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 97));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic_gym, bn::regular_bg_items::emi_bg_basic_gym, bn::sprite_items::emi_spr_basic_closedgrin_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD13A39A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 98));
                ks::SceneManager::set_line_hash(0x38C03843);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 99));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_sad_gym, bn::regular_bg_items::emi_bg_sad_gym, bn::sprite_items::emi_spr_sad_shy_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF6EFEC3E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 100));
                ks::SceneManager::set_line_hash(0x818F2D2D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 101));
                ks::SceneManager::set_line_hash(0x3151DE48);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 102));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited_gym, bn::regular_bg_items::emi_bg_excited_gym, bn::sprite_items::emi_spr_excited_joy_gym, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x42ACB340);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 103));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_EMI));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background_transition(SCENE_TRANSITION_SHORTTIMESKIP));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2E0799E8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 104));
                ks::SceneManager::set_line_hash(0x14560647);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 105));
                ks::SceneManager::set_line_hash(0x579BC9D7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 106));
                ks::SceneManager::set_line_hash(0x2D0D1CC0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 107));
                ks::SceneManager::set_line_hash(0x65D15C55);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 108));
                ks::SceneManager::set_line_hash(0xA4ADE7F1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 109));
                IF_NOT_EXIT(ks::SceneManager::music_stop(300));
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_SHUTEYE, 0));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::DARKGREY));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xAF572319);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 110));
                ks::SceneManager::set_line_hash(0xC09CBE38);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 111));
                ks::SceneManager::set_line_hash(0xEEC5F26C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 112));
                ks::SceneManager::set_line_hash(0xB101E091);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 113));
                ks::SceneManager::set_line_hash(0xC72B28F2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 114));
                ks::SceneManager::set_line_hash(0xBC776221);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 115));
                ks::SceneManager::set_line_hash(0xCF597CFD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 116));
                ks::SceneManager::set_line_hash(0x95054A4D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 117));
                ks::SceneManager::set_line_hash(0x032DC394);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 118));
                ks::SceneManager::set_line_hash(0xFC40E484);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 119));
                ks::SceneManager::set_line_hash(0x4A813C73);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 120));
                ks::SceneManager::set_line_hash(0x7CF13363);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 121));
                ks::SceneManager::set_line_hash(0xF3C95F2F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 122));
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 30));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(120));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_nurseoffice, 8, 0, SCENE_TRANSITION_OPENEYE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_DAILY, 360));
                ks::SceneManager::set_line_hash(0x678A1351);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 123));
                ks::SceneManager::set_line_hash(0xFF6B7928);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 124));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCE4DC1FB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 125));
                ks::SceneManager::set_line_hash(0xEEBA8631);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 126));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFE68A38F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 127));
                ks::SceneManager::set_line_hash(0xCF4126FC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 128));
                ks::SceneManager::set_line_hash(0x1E8891C2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 129));
                ks::SceneManager::set_line_hash(0xD65E15D7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 130));
                ks::SceneManager::set_line_hash(0x1F4DAF66);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 131));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x346ACC53);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 132));
                ks::SceneManager::set_line_hash(0x00CC8111);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 133));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4939C965);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 134));
                ks::SceneManager::set_line_hash(0x9C660C99);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 135));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1305C758);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 136));
                // renpy.music.set_volume(0.5, 0.2, channel="music"); TODO: unknown assignment
                // TODO: Show bg
                // TODO: Show transform bg 0, 0
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_NURSE, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(24));
                // TODO: Show bg
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEBD7A997);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 137));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, PALETTE_VARIANT_DEFAULT));
                // TODO: Hide dizzy_bg
                // TODO: Hide dizzy_fg
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8895F653);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 138));
                // renpy.music.set_volume(1.0, 2.0, channel="music"); TODO: unknown assignment
                ks::SceneManager::set_line_hash(0xADAF7DB8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 139));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3B2CDAC3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 140));
                ks::SceneManager::set_line_hash(0xF47074E8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 141));
                ks::SceneManager::set_line_hash(0x5B87D768);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 142));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x661CB215);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 143));
                ks::SceneManager::set_line_hash(0x1CE90F1E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 144));
                ks::SceneManager::set_line_hash(0xFD8C7757);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 145));
                ks::SceneManager::set_line_hash(0xE22BD89D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 146));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE79E27C3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 147));
                ks::SceneManager::set_line_hash(0x0D85A486);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 148));
                ks::SceneManager::set_line_hash(0xC0BF9FF6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 149));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE1CE5E90);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 150));
                ks::SceneManager::set_line_hash(0x240187EE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 151));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5F9E0C9F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 152));
                ks::SceneManager::set_line_hash(0x3D301CCF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 153));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_nursehall, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(240));
                ks::SceneManager::set_line_hash(0xEB590806);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 154));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_courtyard, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8DF9FE77);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 155));
                ks::SceneManager::set_line_hash(0x1BF39C7E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 156));
                return;
            }
            SCENE_INLINE void choice_take_it_easy() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("890886E3", tl_890886E3_ru_intl));
                IF_NOT_EXIT(ks::SceneManager::music_stop(600));
                ks::SceneManager::set_line_hash(0xAFFA27E7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x72142E0F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0x6B417969);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0x9EEF347C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0xA53371A9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x2B49114F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_track_on, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE7169831);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0xDF0682FB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0xB790D4EF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x47AB63ED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0x2BD24249);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0x68B96016);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                ks::SceneManager::set_line_hash(0x9C425036);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0x23E02B5A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 13));
                ks::SceneManager::set_line_hash(0xE701B158);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                ks::SceneManager::set_line_hash(0x22F772D6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0xAE88469F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 120));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_track, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF73A3D34);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                ks::SceneManager::set_line_hash(0xFF728C1D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                return;
            }
            SCENE_INLINE void choice_dodge_subject() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("4D2DCD5F", tl_4D2DCD5F_ru_intl));
                ks::SceneManager::set_line_hash(0x90181E95);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x37DA1552);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0x99088746);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEC4CD976);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 3));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2C1866B8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 4));
                ks::SceneManager::set_line_hash(0x7672A9B8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 5));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4E9D9FA9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 6));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD4D65A77);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 7));
                ks::SceneManager::set_line_hash(0x7EC028F6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x2DE30052);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 9));
                ks::SceneManager::set_line_hash(0x4865ACC6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 10));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x42D41527);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                ks::SceneManager::set_line_hash(0x3472D9A5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0x84F5E4FE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 13));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_DREAMY, 120));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7455E83D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 14));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9C960561);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 15));
                ks::SceneManager::set_line_hash(0x94992D92);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                ks::SceneManager::set_line_hash(0x08073CB5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                ks::SceneManager::set_line_hash(0x39FA68E4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                ks::SceneManager::set_line_hash(0x5F71804E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                ks::SceneManager::set_line_hash(0xEAE45536);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 20));
                ks::SceneManager::set_line_hash(0x300BD81E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 21));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7AB61E10);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 22));
                ks::SceneManager::set_line_hash(0xE0016B88);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 23));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9DD38E21);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 24));
                ks::SceneManager::set_line_hash(0xB529CB2E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 25));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1458C77B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 26));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_cross, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6209200E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 27));
                ks::SceneManager::set_line_hash(0xCD86AEFA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 28));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFCBD0407);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 29));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1E1FFB00);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 30));
                ks::SceneManager::set_line_hash(0xF47074E8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 31));
                ks::SceneManager::set_line_hash(0xFFBFF27F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 32));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA1D1B32C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 33));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x61F49296);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 34));
                ks::SceneManager::set_line_hash(0x4F807009);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 35));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x391D5D9B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 36));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB9D1413D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 37));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7D4E5FF3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 38));
                ks::SceneManager::set_line_hash(0x2C7892A7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 39));
                ks::SceneManager::set_line_hash(0xDCB1AF2F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 40));
                ks::SceneManager::set_line_hash(0xFBE97A89);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 41));
                ks::SceneManager::set_line_hash(0x2919D0CC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 42));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2D6AD815);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 43));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7F62EB6D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 44));
                ks::SceneManager::set_line_hash(0x922336DF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 45));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x73DFFC1D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 46));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x540CF13F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 47));
                ks::SceneManager::set_line_hash(0x51610305);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 48));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1C153250);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 49));
                IF_NOT_EXIT(ks::SceneManager::music_stop(420));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_courtyard, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA74E2BC4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 50));
                ks::SceneManager::set_line_hash(0x041FDFA7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 51));
                ks::SceneManager::set_line_hash(0xDEBF47F3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 52));
                ks::SceneManager::set_line_hash(0x332F6C9E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 53));
                ks::SceneManager::set_line_hash(0x35B3F90A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 54));
                return;
            }
            SCENE_INLINE void choice_kick_shizu() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("6F488CFB", tl_6F488CFB_ru_intl));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_RAIN, 240));
                ks::SceneManager::set_line_hash(0x8E838781);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x90181E95);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 1));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0A104731);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEC4CD976);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 3));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD3BB0EC2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 4));
                ks::SceneManager::set_line_hash(0xF9BC0F2C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 5));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4E9D9FA9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 6));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9B1C2828);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 7));
                ks::SceneManager::set_line_hash(0xB32B574A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0xE96C7492);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0x75999DC5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 10));
                ks::SceneManager::set_line_hash(0x6BA6F36C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 11));
                ks::SceneManager::set_line_hash(0x96B6665F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7455E83D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 13));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC046FF79);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 14));
                ks::SceneManager::set_line_hash(0x6362F942);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 15));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x89BBFAE6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 16));
                ks::SceneManager::set_line_hash(0x8D02013A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 17));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x433076A2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 18));
                ks::SceneManager::set_line_hash(0x1F2A3CA2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 19));
                ks::SceneManager::set_line_hash(0xA43D1936);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 20));
                IF_NOT_EXIT(ks::SceneManager::music_stop(360));
                ks::SceneManager::set_line_hash(0x79CD8F0B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 21));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB580457B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 22));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_sad, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1458C77B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 23));
                ks::SceneManager::set_line_hash(0xA4A63FB5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 24));
                ks::SceneManager::set_line_hash(0xEE9BCEA2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                ks::SceneManager::set_line_hash(0x30955973);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_SHIZU));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_MISHA));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x47CBD3D7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 27));
                return;
            }
            SCENE_INLINE void choice_fun_at_office() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("8F650623", tl_8F650623_ru_intl));
                IF_NOT_EXIT(ks::SceneManager::music_stop(240));
                ks::SceneManager::set_line_hash(0x440B1083);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x0D404C2B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 1));
                ks::SceneManager::set_line_hash(0xC1DA56A7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 2));
                ks::SceneManager::set_line_hash(0xB27F4115);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 3));
                ks::SceneManager::set_line_hash(0xE2A75453);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x66ECA8C8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 5));
                ks::SceneManager::set_line_hash(0xF83215DA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 6));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4F686628);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 7));
                ks::SceneManager::set_line_hash(0x182D35CC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 8));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_sad, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC83F6DEA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 9));
                ks::SceneManager::set_line_hash(0x66AC02E5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0x7CF13363);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                ks::SceneManager::set_line_hash(0x3DC7F88D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0xD63AB91A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 13));
                ks::SceneManager::set_line_hash(0xAC2A25A1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 14));
                ks::SceneManager::set_line_hash(0xF714D8AA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_MISHA));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFE70C3D5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                ks::SceneManager::set_line_hash(0x6FAEDAAB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                return;
            }
            SCENE_INLINE void choice_dont_want_talk() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("BFCD6512", tl_BFCD6512_ru_intl));
                ks::SceneManager::set_line_hash(0xA2DDD8A1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD4D65A77);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 1));
                ks::SceneManager::set_line_hash(0xF47074E8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEF30779D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4EB2B681);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 4));
                ks::SceneManager::set_line_hash(0x81087A7E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x944A8BC6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(-8, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -90, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x61D07FA4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 7));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3072BD5F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 8));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7010550B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 9));
                ks::SceneManager::set_line_hash(0x7350CD85);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0xBB0C906C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                ks::SceneManager::set_line_hash(0x2E3F379D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0x13805F13);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 13));
                ks::SceneManager::set_line_hash(0x7494EC72);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                ScriptA1FridayRu::choice_dont_want_talk__menu_question_0();
                return;
            }
            SCENE_INLINE void choice_emi_lunch() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("3A5E5047", tl_3A5E5047_ru_intl));
                ks::SceneManager::set_line_hash(0x76D8B919);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x798C3193);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 1));
                ks::SceneManager::set_line_hash(0xCABE1291);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4DC02D49);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0xECAF560A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 4));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3640E343);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                ks::SceneManager::set_line_hash(0xE0294E80);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0xB12BEED3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0xE73C03A2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 8));
                ks::SceneManager::set_line_hash(0x4A3C19D6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 9));
                ks::SceneManager::set_line_hash(0x12B67240);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0x87D8B684);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                ks::SceneManager::set_line_hash(0x58C67865);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 12));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF84876FC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 13));
                ks::SceneManager::set_line_hash(0x4A45A91D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_MISHA));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(180));
                ks::SceneManager::set_line_hash(0x835ED90D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0xDAF88D13);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                return;
            }
            SCENE_INLINE void choice_shizune_lunch() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("6BD34F2C", tl_6BD34F2C_ru_intl));
                ks::SceneManager::set_line_hash(0x046D5E57);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x45EED01C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 1));
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_normalbell.8ad", SOUND_CHANNEL_SOUND));
                IF_NOT_EXIT(ks::SceneManager::pause(420));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_crowd_indoors.8ad", SOUND_CHANNEL_AMBIENT, 18));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                // TODO: Show crowd
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF160E4A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0xDEBF47F3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0x332F6C9E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x35B3F90A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 60));
                return;
            }
            SCENE_INLINE void choice_not_good_condition() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("5116FB4A", tl_5116FB4A_ru_intl));
                // renpy.music.set_volume(0.1, 1.0, channel="ambient"); TODO: unknown assignment
                ks::SceneManager::set_line_hash(0xD0D77172);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_oops, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x51E97809);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 1));
                ks::SceneManager::set_line_hash(0x5F575C3B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_concerned, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2FAFF924);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0x7E374B4A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x47419CD3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 5));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_oops, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF0562983);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 6));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_sad, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x45FA661C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0x067D2622);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x6857E334);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0x47DE883B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 10));
                ks::SceneManager::set_line_hash(0x247478BC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 11));
                ks::SceneManager::set_line_hash(0x73BAA7CB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 12));
                ks::SceneManager::set_line_hash(0x91665584);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 13));
                ks::SceneManager::set_line_hash(0x47E4DDEC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                ks::SceneManager::set_line_hash(0x8D93AE4B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                if (ks::progress.talk_with_hanako) {
                    ScriptA1FridayRu::choice_not_good_condition__condition_0_0();
                } 
                
            
                ks::SceneManager::set_line_hash(0xD3D9EA36);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                ks::SceneManager::set_line_hash(0x07B0C11F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 17));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x62C259D9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                // renpy.music.set_volume(0.5, 5.0, channel="ambient"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormext_half_ni, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed, bn::regular_bg_items::rin_bg_relaxed, bn::sprite_items::rin_spr_relaxed_surprised, PALETTE_VARIANT_SPRITE_NIGHT, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_NIGHT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x52512BF8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_relaxed, bn::regular_bg_items::rin_bg_relaxed, bn::sprite_items::rin_spr_relaxed_disgust, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x99AB11A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 20));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7F59EA06);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 21));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_basic, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_upset, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_RIN, 30));
                ks::SceneManager::set_line_hash(0x15265106);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 22));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_surprised, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7155EFB4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 23));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_negative, bn::regular_bg_items::rin_bg_negative, bn::sprite_items::rin_spr_negative_annoyed, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x49D62A7F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 24));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_concerned, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA0E8E0BE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 25));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_negative, bn::regular_bg_items::rin_bg_negative, bn::sprite_items::rin_spr_negative_confused, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8DD828A9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 26));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_negative, bn::regular_bg_items::rin_bg_negative, bn::sprite_items::rin_spr_negative_worried, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x71A8A8D8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 27));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_negative, bn::regular_bg_items::rin_bg_negative, bn::sprite_items::rin_spr_negative_confused, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE062676C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 28));
                ks::SceneManager::set_line_hash(0x304C4B78);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 29));
                ks::SceneManager::set_line_hash(0x17F21472);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 30));
                ks::SceneManager::set_line_hash(0xFE430621);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 31));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_negative, bn::regular_bg_items::rin_bg_negative, bn::sprite_items::rin_spr_negative_annoyed, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8F49C42C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 32));
                ks::SceneManager::set_line_hash(0xE4B371F5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_RIN, ks::sprite_metas::rin_negative, bn::regular_bg_items::rin_bg_negative, bn::sprite_items::rin_spr_negative_angry, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x887B28EB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::rin, 34));
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_RIN));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_LILLY, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(-8, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4080483A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 35));
                ks::SceneManager::set_line_hash(0xD85C958B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                ks::SceneManager::set_line_hash(0x07AC104A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 37));
                ks::SceneManager::set_line_hash(0x45C171DC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 38));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_oops, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFF97366B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 39));
                ks::SceneManager::set_line_hash(0xC8DCBFA9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 40));
                ks::SceneManager::set_line_hash(0xFC227E48);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 41));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x55E91C49);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 42));
                ks::SceneManager::set_line_hash(0x13F38470);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 43));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_giggle, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5819D57E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 44));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDF264742);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 45));
                ks::SceneManager::set_line_hash(0xB0C1F019);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 46));
                ks::SceneManager::set_line_hash(0x51A46C62);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 47));
                ks::SceneManager::set_line_hash(0x7479499B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 48));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_cheerful, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5F0463B6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 49));
                ks::SceneManager::set_line_hash(0xC624DB9F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 50));
                ks::SceneManager::set_line_hash(0x1EEC0D02);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 51));
                ks::SceneManager::set_line_hash(0xA7F29A48);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 52));
                ks::SceneManager::set_line_hash(0x323572A8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 53));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x58123543);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 54));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_LILLY));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 162));
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 90));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                return;
            }
            SCENE_INLINE void choice_not_much_talking() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("EEACE0F5", tl_EEACE0F5_ru_intl));
                // renpy.music.set_volume(0.1, 1.0, channel="ambient"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::music_stop(300));
                ks::SceneManager::set_line_hash(0xC2F3C2E2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                ks::SceneManager::set_line_hash(0xBC812847);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 1));
                ks::SceneManager::set_line_hash(0x2D492CA3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_sad, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7E857206);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 3));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_concerned, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4EAE82E7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x8D0E0025);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 5));
                ks::SceneManager::set_line_hash(0xF2D291B7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0x48B02CF0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 7));
                ks::SceneManager::set_line_hash(0x5EB3B1C3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 8));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_LILLY));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_RIN));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x708A2D20);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 180));
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 90));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                return;
            }
            SCENE_INLINE void a1_friday_exercise__menu_question_0() {
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 35});
                answers.push_back(ks::answer_ptr{1, 36});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1FridayRu::a1_friday_exercise__menu_question_0_go_for_it();
                } else if (answer == 1) {
                    ScriptA1FridayRu::a1_friday_exercise__menu_question_0_take_it_easy();
                }
            }
            SCENE_INLINE void a1_friday_exercise__menu_question_0_go_for_it() {
                ks::progress.go_for_it = true;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_go_for_it()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_exercise__menu_question_0_take_it_easy() {
                ks::progress.go_for_it = false;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_take_it_easy()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_home_field_advantage__menu_question_0() {
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 25});
                answers.push_back(ks::answer_ptr{1, 26});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1FridayRu::a1_friday_home_field_advantage__menu_question_0_try_to_dodge_the_subject();
                } else if (answer == 1) {
                    ScriptA1FridayRu::a1_friday_home_field_advantage__menu_question_0_kick_them_out_of_my_room();
                }
            }
            SCENE_INLINE void a1_friday_home_field_advantage__menu_question_0_try_to_dodge_the_subject() {
                ks::progress.kick_shizu = false;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_dodge_subject()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_home_field_advantage__menu_question_0_kick_them_out_of_my_room() {
                ks::progress.kick_shizu = true;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_kick_shizu()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_slow_recovery__menu_question_0() {
                ks::SceneManager::set_line_hash(0x0DDB179F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 12));
                bn::vector<ks::answer_ptr, 5> answers;
                if (true) answers.push_back({0, 13});
                if (true) answers.push_back({1, 14});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1FridayRu::a1_friday_slow_recovery__menu_question_0_yeah_i_sure_was_having_fun_fun_fun_at_the_nurses_office();
                } else if (answer == 1) {
                    ScriptA1FridayRu::a1_friday_slow_recovery__menu_question_0_i_dont_want_to_talk_about_it_okay();
                }
            }
            SCENE_INLINE void a1_friday_slow_recovery__menu_question_0_yeah_i_sure_was_having_fun_fun_fun_at_the_nurses_office() {
                ks::progress.fun_fun_at_office = true;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_fun_at_office()); // DIRECT CALL
                IF_NOT_EXIT(ScriptA1FridayRu::mas_doesnt_bother()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_slow_recovery__menu_question_0_i_dont_want_to_talk_about_it_okay() {
                ks::progress.fun_fun_at_office = false;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_dont_want_talk()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_mind_your_step__menu_question_0() {
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 185});
                answers.push_back(ks::answer_ptr{1, 186});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1FridayRu::a1_friday_mind_your_step__menu_question_0_sorry_im_not_in_very_good_condition();
                } else if (answer == 1) {
                    ScriptA1FridayRu::a1_friday_mind_your_step__menu_question_0_i_dont_really_want_to_talk_about_it();
                }
            }
            SCENE_INLINE void a1_friday_mind_your_step__menu_question_0_sorry_im_not_in_very_good_condition() {
                ks::progress.not_much_talking = false;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_not_good_condition()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_mind_your_step__menu_question_0_i_dont_really_want_to_talk_about_it() {
                ks::progress.not_much_talking = true;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_not_much_talking()); // DIRECT CALL
            }
            SCENE_INLINE void choice_dont_want_talk__menu_question_0() {
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 15});
                answers.push_back(ks::answer_ptr{1, 16});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1FridayRu::choice_dont_want_talk__menu_question_0_ill_go_to_the_lunch_with_emi_and_her_friend();
                } else if (answer == 1) {
                    ScriptA1FridayRu::choice_dont_want_talk__menu_question_0_ill_go_with_shizune_after_all_im_in_the_student_council_now();
                }
            }
            SCENE_INLINE void choice_dont_want_talk__menu_question_0_ill_go_to_the_lunch_with_emi_and_her_friend() {
                ks::progress.are_student_council = false;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_emi_lunch()); // DIRECT CALL
            }
            SCENE_INLINE void choice_dont_want_talk__menu_question_0_ill_go_with_shizune_after_all_im_in_the_student_council_now() {
                ks::progress.are_student_council = true;
                IF_NOT_EXIT(ScriptA1FridayRu::choice_shizune_lunch()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_exercise__condition_0_0() {
                return;
            }
            SCENE_INLINE void a1_friday__condition_0_0() {
                IF_NOT_EXIT(a1_friday_exercise()); // INLINE CALL
            }
            SCENE_INLINE void a1_friday_invisible_hat__condition_0_0() {
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 0));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhisao, 0, 0, SCENE_TRANSITION_OPENEYE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(12));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormbathroom, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCEE6ADF5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 42));
            }
            SCENE_INLINE void a1_friday_invisible_hat__condition_1_0() {
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x591659DD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 43));
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_KENJI));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2A4EFF4C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 44));
            }
            SCENE_INLINE void a1_friday_invisible_hat__condition_2_0() {
                return;
            }
            SCENE_INLINE void a1_friday__condition_1_0() {
                IF_NOT_EXIT(a1_friday_invisible_hat()); // INLINE CALL
            }
            SCENE_INLINE void a1_friday_home_field_advantage__condition_0_0() {
                return;
            }
            SCENE_INLINE void a1_friday__condition_2_0() {
                IF_NOT_EXIT(a1_friday_home_field_advantage()); // INLINE CALL
            }
            SCENE_INLINE void a1_friday_no_recovery__condition_0_0() {
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x75A5D5E4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFCC30921);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 1));
                ks::SceneManager::set_line_hash(0xDCE6139B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_irritated, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x80330C1A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 3));
                ks::SceneManager::set_line_hash(0xA83FDA3C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x2D357800);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                ks::SceneManager::set_line_hash(0x55AE4B3F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2429B78D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0xD8873A5C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
            }
            SCENE_INLINE void a1_friday_no_recovery__condition_1_0() {
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBAA605FD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0x10766AF8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
            }
            SCENE_INLINE void a1_friday_slow_recovery__condition_0_0() {
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
            }
            SCENE_INLINE void a1_friday_slow_recovery__condition_0_1() {
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_MUTO));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
            }
            SCENE_INLINE void a1_friday_slow_recovery__condition_1_0() {
                return;
            }
            SCENE_INLINE void a1_friday_no_recovery__condition_2_0() {
                IF_NOT_EXIT(a1_friday_slow_recovery()); // INLINE CALL
            }
            SCENE_INLINE void a1_friday_no_recovery__condition_2_1() {
                IF_NOT_EXIT(ScriptA1FridayRu::class_goes_lazily()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_no_recovery__condition_2_2() {
                IF_NOT_EXIT(ScriptA1FridayRu::mas_doesnt_bother()); // DIRECT CALL
            }
            SCENE_INLINE void a1_friday_no_recovery__condition_3_0() {
                return;
            }
            SCENE_INLINE void a1_friday__condition_3_0() {
                IF_NOT_EXIT(a1_friday_no_recovery()); // INLINE CALL
            }
            SCENE_INLINE void a1_friday_no_free_lunch__condition_0_0() {
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_council, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3F1C9D72);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 84));
                ks::SceneManager::set_line_hash(0x11251682);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 85));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_normalbell.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0xAB480982);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 86));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCF3B7D8E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 87));
            }
            SCENE_INLINE void a1_friday_no_free_lunch__condition_1_0() {
                return;
            }
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_0__condition_0_0() {
                ks::SceneManager::set_line_hash(0x5B148961);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 153));
                ks::SceneManager::set_line_hash(0x17664F5C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 154));
                ks::SceneManager::set_line_hash(0xBC2DB264);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 155));
                ks::SceneManager::set_line_hash(0xC28B287C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 156));
            }
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_0_0() {
                ks::SceneManager::set_line_hash(0xCB0EFFB1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 157));
                ks::SceneManager::set_line_hash(0x09D83E00);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 158));
                ks::SceneManager::set_line_hash(0xCC9163A3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 159));
                ks::SceneManager::set_line_hash(0xA75A5EE8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 160));
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 60));
                // TODO: Hide crowd
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBD6D668B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 161));
                ks::SceneManager::set_line_hash(0xAE19C2D4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 162));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_EMI, 18));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_happy, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6C501EF1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_proud, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1C8B0816);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 164));
            }
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_0_1() {
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_EMI, 18));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_happy, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC2A6774D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 165));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_proud, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFE71DE3A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 166));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x7AFB43FF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 167));
                ks::SceneManager::set_line_hash(0x5A626450);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 168));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedgrin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF45852D3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 169));
                ks::SceneManager::set_line_hash(0x9CD53608);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 170));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_proud, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x383A9D4A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 171));
                ks::SceneManager::set_line_hash(0xBB20DB65);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 172));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedgrin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA1AD190B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 173));
                ks::SceneManager::set_line_hash(0x5C2CB793);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 174));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_excited, bn::regular_bg_items::emi_bg_excited, bn::sprite_items::emi_spr_excited_proud, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8B66FD13);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 175));
                ks::SceneManager::set_line_hash(0x68B71FF0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 176));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x577B042C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 177));
                ks::SceneManager::set_line_hash(0xD4878ACD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 178));
                ks::SceneManager::set_line_hash(0xC53D707F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 179));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedgrin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6EE46D95);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 180));
                ks::SceneManager::set_line_hash(0x6D1AB3C3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 181));
                ks::SceneManager::set_line_hash(0x4EC79367);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 182));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_basic, bn::regular_bg_items::emi_bg_basic, bn::sprite_items::emi_spr_basic_closedhappy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x160A3C97);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 183));
                ks::SceneManager::set_line_hash(0x08464D30);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 184));
                ks::SceneManager::set_line_hash(0x014F6F3A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 185));
                ks::SceneManager::set_line_hash(0x08C98424);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 186));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_EMI, ks::sprite_metas::emi_sad, bn::regular_bg_items::emi_bg_sad, bn::sprite_items::emi_spr_sad_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x41E201FE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 187));
                ks::SceneManager::set_line_hash(0xD75A29DA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 188));
                ks::SceneManager::set_line_hash(0x9A41732F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::emi, 189));
                ks::SceneManager::set_line_hash(0x3E16EE6B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 190));
                if (ks::progress.go_through_shizu() && !ks::progress.got_kenji() || ks::in_replay) {
                    ScriptA1FridayRu::a1_friday_foot_and_mouth__condition_0__condition_0_0();
                } 
                
            
            }
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_1_0() {
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhisao_ss, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x43ACA9A2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 191));
                ks::SceneManager::set_line_hash(0x973407DC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 192));
                ks::SceneManager::set_line_hash(0x83652BB4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 193));
                ks::SceneManager::set_line_hash(0xB55A21AA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 194));
                ks::SceneManager::set_line_hash(0xAED62C21);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 195));
                ks::SceneManager::set_line_hash(0x08F34C87);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 196));
                ks::SceneManager::set_line_hash(0x999FF128);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 197));
                ks::SceneManager::set_line_hash(0xA8D42800);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 198));
                IF_NOT_EXIT(ks::SceneManager::music_stop(300));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhisao_ni, 0, 0, SCENE_TRANSITION_NONE, 90, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x399E859F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 199));
                ks::SceneManager::set_line_hash(0xF0354890);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 200));
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_SHUTEYE, 0));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
            }
            SCENE_INLINE void a1_friday_foot_and_mouth__condition_2_0() {
                return;
            }
            SCENE_INLINE void a1_friday_mind_your_step__condition_0_0() {
                return;
            }
            SCENE_INLINE void a1_friday__condition_4__condition_0_0() {
                IF_NOT_EXIT(a1_friday_mind_your_step()); // INLINE CALL
            }
            SCENE_INLINE void a1_friday__condition_4_0() {
                IF_NOT_EXIT(a1_friday_no_free_lunch()); // INLINE CALL
            }
            SCENE_INLINE void a1_friday__condition_4_1() {
                IF_NOT_EXIT(a1_friday_foot_and_mouth()); // INLINE CALL
                if (!ks::progress.get_tired()) {
                    ScriptA1FridayRu::a1_friday__condition_4__condition_0_0();
                } 
                
            
            }
            SCENE_INLINE void choice_not_good_condition__condition_0_0() {
                ks::SceneManager::set_line_hash(0x77A761ED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 55));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_oops, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x9A8E95F2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::li, 56));
                ks::SceneManager::set_line_hash(0x0D591211);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 57));
                ks::SceneManager::set_line_hash(0xF9237E50);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 58));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_LILLY, ks::sprite_metas::lilly_cane, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_sad, PALETTE_VARIANT_SPRITE_NIGHT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6403CE21);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 59));
            }
    };
}