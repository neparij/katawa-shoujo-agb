#include "script_a1_tuesday.h"
#include "script_a1_tuesday_en_tl_index.h"
namespace ks {
    class ScriptA1TuesdayEn : public ScriptA1Tuesday {
        public:
            static void a1_tuesday_smalltalk() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhisao);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 0));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 1));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 2));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 3));
                ks::SceneManager::music_play("music_dreamy.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 4));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 5));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 6));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 7));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 8));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 9));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 10));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 11));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 12));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 13));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 14));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 15));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 16));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 17));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 18));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 19));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 20));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 21));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 22));
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 23));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 24));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_cross, bn::sprite_items::shizu_spr_cross_wut, ks::sprite_metas::shizu_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 26));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_cross, bn::sprite_items::shizu_spr_cross_angry, ks::sprite_metas::shizu_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_cross, bn::sprite_items::shizu_spr_cross_angry, ks::sprite_metas::shizu_cross, 48, 0);
                // TODO: Show bg
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips, -48, 0);
                ks::SceneManager::music_play("music_happiness.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 27));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_angry, ks::sprite_metas::shizu_basic);
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 28));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 29));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 30));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 31));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 32));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 33));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 34));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 35));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 36));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_confused, ks::sprite_metas::misha_sign);
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 37));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_confused, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 38));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 39));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 40));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 41));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 42));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 43));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 44));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 45));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 46));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_sad, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 47));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_angry, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 48));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 49));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_sparkle, ks::sprite_metas::shizu_basic);
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 50));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 51));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 52));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 53));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 54));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 55));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 56));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 57));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 58));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 59));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 60));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 61));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 62));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_happy, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 63));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 64));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 65));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 66));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 33));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 67));
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 68));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 69));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 70));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind, 48, 0);
                // TODO: Show bg
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips, -48, 0);
                ks::SceneManager::music_play("music_comedy.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 71));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 72));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 73));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 74));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 75));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 76));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 77));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 78));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 79));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_happy, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 80));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 81));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 82));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 83));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 84));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 85));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 86));
                ks::SceneManager::sfx_play("sfx_normalbell.pcm");
                ks::SceneManager::hide_character(0);
                ks::SceneManager::hide_character(1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 87));
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 88));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips, -120, 0);
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind, 120, 0);
                ks::SceneManager::set_character_position(1, -48, 0);
                ks::SceneManager::set_character_position(0, 48, 0);
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 89));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 90));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 91));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 92));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 93));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 94));
                ks::SceneManager::set_background(bn::regular_bg_items::school_cafeteria);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 95));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 96));
                ks::SceneManager::music_play("music_shizune.gsm");
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky, -48, 0);
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind, 48, 0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 97));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 98));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 99));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 100));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 101));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 102));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 103));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_happy, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 104));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 105));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 106));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 107));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, ks::sprite_metas::misha_cross);
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 108));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 109));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 110));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 111));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_blush, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 112));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 113));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 114));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 115));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_smile, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 116));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 117));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 118));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 119));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 120));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 121));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 122));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 123));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 124));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 125));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 126));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 127));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 128));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 129));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 130));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 131));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 132));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_happy, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 133));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 134));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 135));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 136));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 137));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 138));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 139));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 140));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 141));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_angry, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 142));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 143));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 144));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 145));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 146));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 147));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 148));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 149));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 150));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 151));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 152));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 153));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 154));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 155));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 156));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 157));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 158));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 159));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 160));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 161));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 162));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 163));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 164));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 165));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 166));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 85));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 167));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 168));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 169));
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_def, bn::sprite_items::hanako_spr_def_worry, ks::sprite_metas::hanako_def, 80, 0);
                ks::SceneManager::set_character_position(2, 120, 0);
                ks::SceneManager::hide_character(2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 170));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 171));
                if (ks::in_replay) {
                    ScriptA1TuesdayEn::a1_tuesday_smalltalk__condition_0_0();
                } 
                
            
            }
            static void a1_tuesday_risk_vs_reward() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_lobby);
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind, 48, 0);
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips, -48, 0);
                ks::SceneManager::music_play("music_ease.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 172));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 173));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 174));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 175));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 176));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 177));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 178));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 179));
                ks::SceneManager::hide_character(1);
                ks::SceneManager::hide_character(0);
                // TODO: Show bg
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 180));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 181));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic, 48, 0);
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky, -48, 0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 182));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 183));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 184));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 185));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 186));
                ks::SceneManager::sfx_play("sfx_dooropen.pcm");
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::school_council);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 187));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 188));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 189));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 190));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 191));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind, 48, 0);
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips, -48, 0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 192));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 193));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 194));
                ks::SceneManager::sfx_play("sfx_snap.pcm");
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_happy, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 195));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 196));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 197));
                ks::SceneManager::hide_character(0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 198));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 199));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_frown, ks::sprite_metas::shizu_adjust, 48, 0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 200));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 201));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                ks::SceneManager::music_play("music_running.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 202));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 203));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 204));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 205));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 206));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 207));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 208));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 209));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 210));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 211));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 212));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 213));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 214));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 215));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_happy, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 216));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_confused, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 217));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 218));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 219));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_sparkle, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 220));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_happy, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_smile, ks::sprite_metas::misha_cross);
                ScriptA1TuesdayEn::a1_tuesday_risk_vs_reward__menu_question_0();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 221));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 222));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 223));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 224));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 225));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 226));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 227));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 228));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 229));
                ks::SceneManager::music_stop();
                if (ks::in_replay) {
                    ScriptA1TuesdayEn::a1_tuesday_risk_vs_reward__condition_0_0();
                } 
                
            
            }
            static void a1_tuesday_pseudo_tea_cosy() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_staircase2);
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 230));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 231));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 232));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 233));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 234));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 235));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 236));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 237));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 238));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 239));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 240));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 241));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 242));
                ks::SceneManager::sfx_play("sfx_door_creak.pcm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 243));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 244));
                ks::SceneManager::music_play("music_lilly.gsm");
                ks::SceneManager::set_background(bn::regular_bg_items::lilly_tearoom);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 245));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 246));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 247));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 248));
                ks::SceneManager::set_background(bn::regular_bg_items::lilly_tearoom_open);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li_", 249));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 250));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 251));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 252));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 253));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 254));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li_", 255));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 256));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 257));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 258));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 259));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 260));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 261));
                ks::SceneManager::set_background(bn::regular_bg_items::lilly_tearoom);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 262));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li_", 263));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 264));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 265));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 266));
                ks::SceneManager::set_background(bn::regular_bg_items::lilly_tearoom_open);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li_", 267));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 268));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 269));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 270));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 33));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 271));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 272));
                ks::SceneManager::set_background(bn::regular_bg_items::school_miyagi);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 273));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 274));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 275));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 276));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 277));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 278));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 279));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 280));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_basic, bn::sprite_items::lilly_spr_basic_smile, ks::sprite_metas::lilly_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 281));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 282));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 283));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 284));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 285));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_basic2, bn::sprite_items::lilly_spr_basic2_giggle, ks::sprite_metas::lilly_basic2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 286));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 287));
                ks::SceneManager::set_background(bn::regular_bg_items::tearoom_lillyhisao_noon);
                // TODO: Show tearoom_hisao
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 288));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 289));
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 290));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 291));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 292));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 293));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 294));
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 295));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 296));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 297));
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 298));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 299));
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 300));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 301));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 302));
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 303));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 304));
                // TODO: Show tearoom_lilly
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 305));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 306));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 307));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 308));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 309));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 310));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 311));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 312));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 313));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 314));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 315));
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 316));
                ks::SceneManager::music_stop();
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 317));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 318));
                ks::SceneManager::set_background(bn::regular_bg_items::tearoom_lillyhisao_sunset);
                // TODO: Show tearoom_hisao
                // TODO: Show tearoom_lilly
                ks::SceneManager::music_play("music_tranquil.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 319));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 320));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 321));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 143));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 322));
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 323));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 324));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 325));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 326));
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 327));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 328));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 329));
                // TODO: Show tearoom_lilly
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 330));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 331));
                // TODO: Show tearoom_hisao
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 332));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 333));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 334));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 335));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 336));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 337));
                // TODO: Show tearoom_lilly
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 338));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 339));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 340));
                ks::SceneManager::set_background(bn::regular_bg_items::school_miyagi_ss);
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 341));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 342));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 343));
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 344));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 345));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 346));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smileclosed, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 347));
                ks::SceneManager::set_background(bn::regular_bg_items::school_library_ss);
                ks::SceneManager::music_play("music_happiness.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 348));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 349));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 350));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smileclosed, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 351));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 352));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 353));
                ks::SceneManager::sfx_play("sfx_impact.pcm");
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_surprised, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 354));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mystery", 355));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, ks::sprite_metas::lilly_cane, -48, 0);
                // TODO: Show bg
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_neutral, ks::sprite_metas::yuuko_down);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 356));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_neurotic, ks::sprite_metas::yuuko_up, 48, 0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 357));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 358));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 359));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_worried, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 360));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 361));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_sad, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 362));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_neurotic, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 363));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_smile, ks::sprite_metas::yuuko_down);
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 364));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 365));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 366));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 367));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 368));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_happy, ks::sprite_metas::yuuko_down);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 369));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_reminisce, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 370));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smile, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 371));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 372));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 373));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_panic, ks::sprite_metas::yuuko_up);
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 374));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu_", 375));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 376));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_worried, ks::sprite_metas::yuuko_up);
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smileclosed, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 377));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 378));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_neutral, ks::sprite_metas::yuuko_down);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 379));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 380));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 381));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 382));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 383));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_panic, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 384));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 385));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_sleepy, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 386));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 387));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 388));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_smile, ks::sprite_metas::yuuko_down);
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 389));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 390));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 391));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 392));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_neurotic, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 393));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_worried, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 394));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 395));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 396));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 397));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smileclosed, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 398));
                ks::SceneManager::music_stop();
                if (ks::in_replay) {
                    ScriptA1TuesdayEn::a1_tuesday_pseudo_tea_cosy__condition_0_0();
                } 
                
            
            }
            static void a1_tuesday_shared_library() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_library_ss);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 399));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 400));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 401));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 402));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 403));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 404));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 405));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 406));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 407));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 408));
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library_read);
                ks::SceneManager::music_play("music_another.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 409));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 410));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 411));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 412));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 413));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 414));
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library_gasp);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 415));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 416));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 417));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 418));
                ScriptA1TuesdayEn::a1_tuesday_shared_library__menu_question_0();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha", 419));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha", 420));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 421));
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_defarms, bn::sprite_items::hanako_spr_defarms_strain, ks::sprite_metas::hanako_defarms);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha", 422));
                // TODO: Show hanako:
                ks::SceneManager::hide_character(2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 423));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 424));
                ks::SceneManager::set_background(bn::regular_bg_items::school_library_ss);
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_smileclosed, ks::sprite_metas::lilly_cane, -48, 0);
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_neutral, ks::sprite_metas::yuuko_down, 48, 0);
                ks::SceneManager::music_play("music_pearly.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 425));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 426));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 427));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 428));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_smile, ks::sprite_metas::yuuko_down);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 429));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 430));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_surprised, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 431));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 432));
                ks::SceneManager::show_character(3, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_sad, ks::sprite_metas::lilly_cane);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 433));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_neurotic, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 434));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 435));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("li", 436));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 437));
                ks::SceneManager::hide_character(3);
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_neurotic, ks::sprite_metas::yuuko_up);
                // TODO: Show bg
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 438));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 439));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 440));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_smile, ks::sprite_metas::yuuko_down);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 441));
                if (ks::progress.im_new_here == true) {
                    ScriptA1TuesdayEn::a1_tuesday_shared_library__condition_0_0();
                } 
                else {
                    ScriptA1TuesdayEn::a1_tuesday_shared_library__condition_0_1();
                } 
                
            
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 442));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 443));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_neurotic, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 444));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 445));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 446));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_panic, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 447));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 448));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_smile, ks::sprite_metas::yuuko_down);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 449));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 450));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 451));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 452));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 453));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 454));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_neutral, ks::sprite_metas::yuuko_down);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 455));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 456));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 457));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 458));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 459));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 460));
                ks::SceneManager::music_stop();
                if (ks::in_replay) {
                    ScriptA1TuesdayEn::a1_tuesday_shared_library__condition_1_0();
                } 
                
            
            }
            static void a1_tuesday_bizarre_and_surreal() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhallway);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 461));
                ks::SceneManager::sfx_play("sfx_dooropen.pcm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 462));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mystery", 463));
                ks::SceneManager::music_play("music_kenji.gsm");
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 464));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 465));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 466));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 467));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 468));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 469));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 470));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 471));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 472));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 473));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_rage, bn::sprite_items::kenji_spr_rage_rage, ks::sprite_metas::kenji_rage);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 474));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 475));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 476));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 477));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 478));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 479));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 480));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 481));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 482));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_rage, bn::sprite_items::kenji_spr_rage_rage, ks::sprite_metas::kenji_rage);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 483));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 484));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 485));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 486));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 487));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 488));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 489));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 490));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 491));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 492));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 493));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 494));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 495));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 496));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 497));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 498));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 499));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 500));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 501));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 502));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 503));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 504));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 505));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 506));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 507));
                ScriptA1TuesdayEn::a1_tuesday_bizarre_and_surreal__menu_question_0();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 508));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 509));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 510));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 511));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 512));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 513));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 514));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 515));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 516));
                ks::SceneManager::music_stop();
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 517));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 518));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 519));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 520));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                ks::SceneManager::music_play("music_tension.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 521));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 522));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 523));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 524));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 525));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 526));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 527));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 528));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 529));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 530));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 531));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                ks::SceneManager::music_play("music_kenji.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 532));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 533));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 534));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 535));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 536));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 537));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 538));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 539));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 540));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 541));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 542));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 543));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 544));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 545));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 546));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 547));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 548));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 549));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 550));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 551));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 552));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 553));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 554));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 555));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 556));
                ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                ks::SceneManager::hide_character(5);
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 557));
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhisao_ss);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 558));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 559));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 560));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 561));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 562));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 563));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 564));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 565));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 566));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 567));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 568));
                if (ks::in_replay) {
                    ScriptA1TuesdayEn::a1_tuesday_bizarre_and_surreal__condition_0_0();
                } 
                
            
            }
            static void a1_tuesday() {
                ks::SceneManager::set(ks::SceneManager("script_a1_tuesday", "en", script_a1_tuesday_en_intl));
            
                IF_NOT_EXIT(a1_tuesday_smalltalk());
                IF_NOT_EXIT(a1_tuesday_risk_vs_reward());
                IF_NOT_EXIT(a1_tuesday_pseudo_tea_cosy());
                IF_NOT_EXIT(a1_tuesday_shared_library());
                IF_NOT_EXIT(a1_tuesday_bizarre_and_surreal());
            }
            static void a1c3o1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 569));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 570));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 571));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 572));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 573));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 574));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 575));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 576));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 577));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 578));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 579));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 580));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 581));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 582));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 583));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 25));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 584));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 585));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 586));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 587));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 588));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 589));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 590));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 591));
                ks::SceneManager::music_play("music_shizune.gsm");
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 592));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 593));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 594));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 595));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 596));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_sparkle, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 597));
                return;
            }
            static void a1c3o2() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 598));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 599));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 600));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 575));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 601));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 602));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 603));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frustrated, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 604));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 605));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 606));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 607));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 608));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 609));
                ks::SceneManager::music_play("music_normal.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 610));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 611));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 612));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 613));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 614));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 615));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 616));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 617));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 618));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 619));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 620));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_angry, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 621));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 622));
                ks::SceneManager::show_character(0, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 25));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 623));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 624));
                ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 625));
                return;
            }
            static void a1c4o1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 626));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 627));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 25));
                if (ks::progress.wanted_introduce || ks::in_replay) {
                    ScriptA1TuesdayEn::a1c4o1__condition_0_0();
                } 
                
            
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 628));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 629));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 630));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha_", 631));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 632));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 633));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 634));
                ks::SceneManager::set_background(bn::regular_bg_items::school_library_ss);
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_emb, bn::sprite_items::hanako_spr_emb_downtimid, ks::sprite_metas::hanako_emb);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 635));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 636));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 637));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha", 638));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha", 639));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 640));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 641));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 642));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 643));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 644));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 645));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 646));
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_emb, bn::sprite_items::hanako_spr_emb_sad, ks::sprite_metas::hanako_emb);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha", 647));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 648));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 25));
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_emb, bn::sprite_items::hanako_spr_emb_blushtimid, ks::sprite_metas::hanako_emb);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 649));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 650));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 651));
                return;
            }
            static void a1c4o2() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 652));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha_", 653));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 654));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 655));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 656));
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha_", 657));
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library_read);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 658));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 659));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 660));
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 661));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha_", 662));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha_", 663));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 664));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 633));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ha_", 665));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 666));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 667));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 668));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 669));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 25));
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library_read);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 670));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 671));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 672));
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library);
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library_read);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 673));
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library);
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library_read);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 674));
                ks::SceneManager::set_background(bn::regular_bg_items::hana_library);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 675));
                ks::SceneManager::sfx_play("sfx_impact.pcm");
                ks::SceneManager::set_background(bn::regular_bg_items::school_library_ss);
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_def, bn::sprite_items::hanako_spr_def_worry, ks::sprite_metas::hanako_def);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 676));
                return;
            }
            static void a1c5o1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 677));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 678));
                return;
            }
            static void a1c5o2() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 679));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 680));
                return;
            }
            static void a1_tuesday_risk_vs_reward__menu_question_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 681));
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 682});
                answers.push_back(ks::answer_ptr{1, 683});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1TuesdayEn::a1_tuesday_risk_vs_reward__menu_question_0_she_has_a_point_attack_aggressively();
                } else if (answer == 1) {
                    ScriptA1TuesdayEn::a1_tuesday_risk_vs_reward__menu_question_0_its_a_trap_its_smarter_to_play_defensively_here();
                }
            }
            static void a1_tuesday_risk_vs_reward__menu_question_0_she_has_a_point_attack_aggressively() {
                ks::progress.attraction_sc += 1;
                IF_NOT_EXIT(ScriptA1TuesdayEn::a1c3o1());
            }
            static void a1_tuesday_risk_vs_reward__menu_question_0_its_a_trap_its_smarter_to_play_defensively_here() {
                IF_NOT_EXIT(ScriptA1TuesdayEn::a1c3o2());
            }
            static void a1_tuesday_shared_library__menu_question_0() {
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 626});
                answers.push_back(ks::answer_ptr{1, 684});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1TuesdayEn::a1_tuesday_shared_library__menu_question_0_hi_im_new_here_hisao_nakai_were_in_the_same_class();
                } else if (answer == 1) {
                    ScriptA1TuesdayEn::a1_tuesday_shared_library__menu_question_0_im_sorry_i_didnt_mean_to_startle_you();
                }
            }
            static void a1_tuesday_shared_library__menu_question_0_hi_im_new_here_hisao_nakai_were_in_the_same_class() {
                ks::progress.im_new_here = true;
                IF_NOT_EXIT(ScriptA1TuesdayEn::a1c4o1());
            }
            static void a1_tuesday_shared_library__menu_question_0_im_sorry_i_didnt_mean_to_startle_you() {
                ks::progress.attraction_hanako += 1;
                IF_NOT_EXIT(ScriptA1TuesdayEn::a1c4o2());
            }
            static void a1_tuesday_bizarre_and_surreal__menu_question_0() {
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 685});
                answers.push_back(ks::answer_ptr{1, 686});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1TuesdayEn::a1_tuesday_bizarre_and_surreal__menu_question_0_she_was_cute();
                } else if (answer == 1) {
                    ScriptA1TuesdayEn::a1_tuesday_bizarre_and_surreal__menu_question_0_she_wasnt_cute();
                }
            }
            static void a1_tuesday_bizarre_and_surreal__menu_question_0_she_was_cute() {
                ks::progress.attraction_hanako += 1;
                IF_NOT_EXIT(ScriptA1TuesdayEn::a1c5o1());
            }
            static void a1_tuesday_bizarre_and_surreal__menu_question_0_she_wasnt_cute() {
                IF_NOT_EXIT(ScriptA1TuesdayEn::a1c5o2());
            }
            static void a1_tuesday_smalltalk__condition_0_0() {
                return;
            }
            static void a1_tuesday_risk_vs_reward__condition_0_0() {
                return;
            }
            static void a1_tuesday_pseudo_tea_cosy__condition_0_0() {
                return;
            }
            static void a1_tuesday_shared_library__condition_0_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 687));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_worried, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 688));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 689));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 690));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_down, bn::sprite_items::yuuko_spr_down_smile, ks::sprite_metas::yuuko_down);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 691));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 692));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 693));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 694));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 695));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 696));
            }
            static void a1_tuesday_shared_library__condition_0_1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 697));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 698));
                ks::SceneManager::show_character(4, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_worried, ks::sprite_metas::yuuko_up);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 699));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 700));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 692));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("yu", 693));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 694));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 695));
            }
            static void a1_tuesday_shared_library__condition_1_0() {
                return;
            }
            static void a1_tuesday_bizarre_and_surreal__condition_0_0() {
                return;
            }
            static void a1c4o1__condition_0_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 701));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 25));
            }
    };
}