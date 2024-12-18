#include "script_a1_monday.h"
#include "script_a1_monday_ru_tl_index.h"
namespace ks {
    class ScriptA1MondayRu : public ScriptA1Monday {
        public:
            static void a1_monday_out_cold() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods);
                ks::SceneManager::music_play("music_serene.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 0));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 1));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 2));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 3));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 4));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 5));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 6));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 7));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 8));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 9));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 10));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mystery", 11));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 12));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 13));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 14));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 15));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 16));
                ks::SceneManager::set_background(bn::regular_bg_items::other_iwanako);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 17));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 18));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 19));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 20));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 21));
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 22));
                ks::SceneManager::set_background(bn::regular_bg_items::other_iwanako);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 23));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 24));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 26));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 27));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 28));
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 29));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 30));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 31));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 32));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 33));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 34));
                ks::SceneManager::music_play("music_tragic.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 35));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 36));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 37));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 38));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 39));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 40));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 41));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 42));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_out_cold__condition_0_0();
                } 
                
            
            }
            static void a1_monday_bundle_of_hisao() {
                ks::SceneManager::free_resources();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("centered", 43));
                ks::SceneManager::set_background(bn::regular_bg_items::hosp_room);
                // renpy.music.set_volume(0.5, 0.0, channel="music"); TODO: unknown assignment
                ks::SceneManager::music_play("music_rain.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 44));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 45));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 46));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 47));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 48));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 49));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 50));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 51));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 52));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 53));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 54));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 55));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 56));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 57));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 58));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 59));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 60));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 61));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 62));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 63));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 64));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 65));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 66));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 67));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 68));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 69));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 70));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 71));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 72));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 73));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 74));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 75));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 76));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 77));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 78));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 79));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 80));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 81));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 82));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 83));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("n", 84));
                // renpy.music.set_volume(1.0, 1.0, channel="music"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 85));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 86));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 87));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 88));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 89));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 90));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 91));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 92));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 93));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 94));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 95));
                // renpy.music.set_volume(0.5, 2.0, channel="music"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 96));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 97));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 98));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 99));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 100));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 101));
                // renpy.music.set_volume(1.0, 1.0, channel="music"); TODO: unknown assignment
                ks::SceneManager::set_background(bn::regular_bg_items::hosp_room);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 102));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 103));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 104));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 105));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 106));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 107));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 108));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 109));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 110));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 111));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 112));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 113));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 114));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 115));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 116));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 117));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 118));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 119));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 120));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 121));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 122));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 123));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 124));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 125));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 126));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 127));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 128));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 129));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 130));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 131));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 132));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 133));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 134));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 135));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 136));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 137));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 138));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 139));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 140));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 141));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_bundle_of_hisao__condition_0_0();
                } 
                
            
            }
            static void a1_monday_gateway_effect() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_gate);
                ks::SceneManager::music_play("music_happiness.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 142));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 143));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 144));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 145));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 146));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 147));
                ks::SceneManager::set_background(bn::regular_bg_items::school_courtyard);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 148));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 149));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 150));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 151));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 152));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 153));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 154));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 155));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 156));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 157));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 158));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 159));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 160));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 161));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 162));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 164));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 165));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 166));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 167));
                ks::SceneManager::set_background(bn::regular_bg_items::school_lobby);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 168));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu_", 169));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 170));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu_", 171));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 172));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 173));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 174));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 175));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 176));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 177));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 178));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 179));
                ScriptA1MondayRu::a1_monday_gateway_effect__menu_question_0();
                ks::SceneManager::set_background(bn::regular_bg_items::school_staircase2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 180));
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 181));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 182));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 183));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 184));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_gateway_effect__condition_0_0();
                } 
                
            
            }
            static void a1_monday_enter_stage_left() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 185));
                ks::SceneManager::set_background(bn::regular_bg_items::hisao_class);
                ks::SceneManager::music_play("music_normal.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 186));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 187));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 188));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 189));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 190));
                ks::SceneManager::set_background(bn::regular_bg_items::hisao_class);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 191));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 192));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 193));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 194));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 195));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 196));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 197));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 198));
                if (ks::progress.wanted_introduce || ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_0_0();
                } 
                else {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_0_1();
                } 
                
            
                ks::SceneManager::set_background(bn::regular_bg_items::hisao_class);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 199));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 200));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 201));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 202));
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 203));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 204));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 205));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 206));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 207));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 208));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 209));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 210));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 211));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 212));
                ks::SceneManager::music_stop();
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi_shi", 213));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 214));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi_shi", 215));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi_not_shi", 216));
                ks::SceneManager::music_play("music_shizune.gsm");
                ks::SceneManager::set_character_position(0, -48, 0);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic, 48, 0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 217));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 218));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 219));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 220));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 221));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 222));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 223));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 224));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 225));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 226));
                if (ks::progress.wanted_introduce || ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_1_0();
                } 
                else {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_1_1();
                } 
                
            
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 227));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 228));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 229));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 230));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 231));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 232));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 233));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 234));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 235));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 236));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 237));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 238));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 239));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("extend", 240));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("extend", 241));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 242));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 243));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 213));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 244));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 245));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 246));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 247));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 248));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 249));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 250));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 251));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 252));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 253));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 254));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 255));
                ks::SceneManager::music_stop();
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_blush, ks::sprite_metas::shizu_adjust);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 256));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::music_play("music_shizune.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 257));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 258));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 259));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 260));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 261));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 262));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 263));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 264));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 265));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 266));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 267));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 268));
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 269));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 270));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 271));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 272));
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 273));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_2_0();
                } 
                
            
            }
            static void a1_monday_in_the_nursery() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_staircase2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 274));
                ks::SceneManager::set_background(bn::regular_bg_items::school_cafeteria);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 275));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 276));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::music_play("music_ease.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 277));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 278));
                ks::SceneManager::hide_character(0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 279));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 280));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 281));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, ks::sprite_metas::misha_hips, -48, 0);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic, 48, 0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 282));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 283));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 284));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 285));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 286));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 287));
                ScriptA1MondayRu::a1_monday_in_the_nursery__menu_question_0();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 288));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 289));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 163));
                ks::SceneManager::music_stop();
                // renpy.music.set_volume(1.0, .5, channel="ambient"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 290));
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                ks::SceneManager::music_play("music_daily.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 291));
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_emb, bn::sprite_items::hanako_spr_emb_downtimid, ks::sprite_metas::hanako_emb);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 292));
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_defarms, bn::sprite_items::hanako_spr_defarms_shock, ks::sprite_metas::hanako_defarms);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 293));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 294));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 295));
                ks::SceneManager::set_character_position(2, 120, 0);
                ks::SceneManager::hide_character(2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 296));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 297));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 298));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 299));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 300));
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 301));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 302));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 303));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind, 48, 0);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky, -48, 0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 304));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 305));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 306));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 307));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 308));
                ks::SceneManager::hide_character(1);
                ks::SceneManager::hide_character(0);
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 309));
                ks::SceneManager::set_background(bn::regular_bg_items::school_courtyard);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 310));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 311));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind, 48, 0);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky, -48, 0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 312));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 313));
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frustrated, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("shi", 163));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 314));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 315));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 316));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 317));
                ks::SceneManager::music_stop();
                ks::SceneManager::hide_character(1);
                ks::SceneManager::hide_character(0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 318));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 319));
                ks::SceneManager::set_background(bn::regular_bg_items::school_nursehall);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 320));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 321));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 322));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 323));
                ks::SceneManager::set_background(bn::regular_bg_items::school_nurseoffice);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 324));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 325));
                ks::SceneManager::music_play("music_nurse.gsm");
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk_", 326));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 327));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 328));
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_grin, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 329));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk_", 330));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk_", 331));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 332));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 333));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 334));
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 335));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 336));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 337));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 338));
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 339));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 340));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 341));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 342));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 343));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 344));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 345));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 346));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 347));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 348));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 349));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 350));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 351));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 352));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 353));
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_grin, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 354));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 355));
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 356));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 357));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 358));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 359));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 360));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 361));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 362));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 363));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 364));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 365));
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 366));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 367));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 368));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 369));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 370));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 371));
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 372));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 373));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 374));
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 375));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 254));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 376));
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("nk", 377));
                ks::SceneManager::set_background(bn::regular_bg_items::school_nursehall);
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 378));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_in_the_nursery__condition_0_0();
                } 
                
            
            }
            static void a1_monday_nobodys_room() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_courtyard);
                ks::SceneManager::music_play("music_pearly.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 379));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 380));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 381));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 382));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 383));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 384));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 385));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 386));
                ks::SceneManager::set_background(bn::regular_bg_items::school_gardens);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 387));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 388));
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormext_start);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 389));
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhallground);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 390));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 391));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 392));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 393));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 394));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 395));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 396));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 397));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 398));
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhallway);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 399));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 400));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 401));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 402));
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 403));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 404));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 405));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                ks::SceneManager::music_play("music_kenji.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 406));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke_", 407));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 408));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 409));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 410));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 411));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke_", 412));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 413));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 414));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 415));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 416));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 417));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 418));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 419));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 420));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 421));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 422));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 423));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 424));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 425));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 426));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 427));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 428));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 429));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 430));
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ke", 431));
                ks::SceneManager::hide_character(4);
                ks::SceneManager::music_stop();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 432));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("extend", 433));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 434));
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhisao_ss);
                ks::SceneManager::music_play("music_night.gsm");
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 435));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 436));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 437));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 438));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 439));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 440));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 441));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 442));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 443));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 444));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 445));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 446));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 447));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 448));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 449));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 450));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 451));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 452));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 453));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 454));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 455));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 456));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 457));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 458));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 459));
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhisao_ni);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 460));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 461));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 462));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 463));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 464));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_nobodys_room__condition_0_0();
                } 
                
            
            }
            static void a1_monday() {
                ks::SceneManager::set(ks::SceneManager("script_a1_monday", "ru", script_a1_monday_ru_intl));
            
                IF_NOT_EXIT(a1_monday_out_cold());
                IF_NOT_EXIT(a1_monday_bundle_of_hisao());
                IF_NOT_EXIT(a1_monday_gateway_effect());
                IF_NOT_EXIT(a1_monday_enter_stage_left());
                IF_NOT_EXIT(a1_monday_in_the_nursery());
                IF_NOT_EXIT(a1_monday_nobodys_room());
            }
            static void a1c1o1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 465));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 466));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 467));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 468));
                return;
            }
            static void a1c1o2() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 469));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 470));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 471));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 472));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 468));
                return;
            }
            static void a1c2o1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 473));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 474));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 475));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 476));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 477));
                return;
            }
            static void a1c2o2() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 478));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 479));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 480));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 481));
                return;
            }
            static void a1c2o3() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 482));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 483));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 484));
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 485));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 486));
                return;
            }
            static void a1_monday_gateway_effect__menu_question_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mu", 487));
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 488});
                answers.push_back(ks::answer_ptr{1, 489});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1MondayRu::a1_monday_gateway_effect__menu_question_0_why();
                } else if (answer == 1) {
                    ScriptA1MondayRu::a1_monday_gateway_effect__menu_question_0_yeah_of_course();
                }
            }
            static void a1_monday_gateway_effect__menu_question_0_why() {
                ks::progress.wanted_introduce = false;
                IF_NOT_EXIT(ScriptA1MondayRu::a1c1o1());
            }
            static void a1_monday_gateway_effect__menu_question_0_yeah_of_course() {
                ks::progress.wanted_introduce = true;
                ks::progress.attraction_sc += 1;
                IF_NOT_EXIT(ScriptA1MondayRu::a1c1o2());
            }
            static void a1_monday_in_the_nursery__menu_question_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 490));
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 491});
                answers.push_back(ks::answer_ptr{1, 492});
                answers.push_back(ks::answer_ptr{2, 493});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1MondayRu::a1_monday_in_the_nursery__menu_question_0_ask_about_the_library();
                } else if (answer == 1) {
                    ScriptA1MondayRu::a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness();
                } else if (answer == 2) {
                    ScriptA1MondayRu::a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know();
                }
            }
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_the_library() {
                ks::progress.attraction_hanako += 1;
                IF_NOT_EXIT(ScriptA1MondayRu::a1c2o1());
            }
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness() {
                IF_NOT_EXIT(ScriptA1MondayRu::a1c2o2());
            }
            static void a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know() {
                ks::progress.attraction_sc += 1;
                IF_NOT_EXIT(ScriptA1MondayRu::a1c2o3());
            }
            static void a1_monday_out_cold__condition_0_0() {
                return;
            }
            static void a1_monday_bundle_of_hisao__condition_0_0() {
                return;
            }
            static void a1_monday_gateway_effect__condition_0_0() {
                return;
            }
            static void a1_monday_enter_stage_left__condition_0_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 494));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 495));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 496));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("hi", 497));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 498));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 499));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 500));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 501));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 163));
            }
            static void a1_monday_enter_stage_left__condition_0_1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 502));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 503));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 504));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 505));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 506));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 507));
            }
            static void a1_monday_enter_stage_left__condition_1_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 508));
            }
            static void a1_monday_enter_stage_left__condition_1_1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 509));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("mi", 510));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("", 511));
            }
            static void a1_monday_enter_stage_left__condition_2_0() {
                return;
            }
            static void a1_monday_in_the_nursery__condition_0_0() {
                return;
            }
            static void a1_monday_nobodys_room__condition_0_0() {
                return;
            }
    };
}