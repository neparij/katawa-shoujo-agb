#include "script_a1_monday.h"
#include "script_a1_monday_en_tl_index.h"
namespace ks {
    class ScriptA1MondayEn : public ScriptA1Monday {
        public:
            static void a1_monday_out_cold() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods);
                ks::SceneManager::music_play("music_serene.gsm");
                ks::SceneManager::show_dialog("", 0);
                ks::SceneManager::show_dialog("", 1);
                ks::SceneManager::show_dialog("", 2);
                ks::SceneManager::show_dialog("", 3);
                ks::SceneManager::show_dialog("hi", 4);
                ks::SceneManager::show_dialog("", 5);
                ks::SceneManager::show_dialog("", 6);
                ks::SceneManager::show_dialog("", 7);
                ks::SceneManager::show_dialog("", 8);
                ks::SceneManager::show_dialog("", 9);
                ks::SceneManager::show_dialog("", 10);
                ks::SceneManager::show_dialog("mystery", 11);
                ks::SceneManager::show_dialog("", 12);
                ks::SceneManager::show_dialog("", 13);
                ks::SceneManager::show_dialog("", 14);
                ks::SceneManager::show_dialog("", 15);
                ks::SceneManager::show_dialog("", 16);
                ks::SceneManager::set_background(bn::regular_bg_items::other_iwanako);
                ks::SceneManager::show_dialog("hi", 17);
                ks::SceneManager::show_dialog("", 18);
                ks::SceneManager::show_dialog("", 19);
                ks::SceneManager::show_dialog("Iwanako", 20);
                ks::SceneManager::show_dialog("", 21);
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods);
                ks::SceneManager::show_dialog("", 22);
                ks::SceneManager::set_background(bn::regular_bg_items::other_iwanako);
                ks::SceneManager::show_dialog("hi", 23);
                ks::SceneManager::show_dialog("", 24);
                ks::SceneManager::show_dialog("", 25);
                ks::SceneManager::show_dialog("", 26);
                ks::SceneManager::show_dialog("", 27);
                ks::SceneManager::show_dialog("", 28);
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods);
                ks::SceneManager::show_dialog("", 29);
                ks::SceneManager::show_dialog("Iwanako", 30);
                ks::SceneManager::show_dialog("Iwanako", 31);
                ks::SceneManager::music_stop();
                ks::SceneManager::show_dialog("Iwanako", 32);
                ks::SceneManager::show_dialog("", 33);
                ks::SceneManager::show_dialog("", 34);
                ks::SceneManager::music_play("music_tragic.gsm");
                ks::SceneManager::show_dialog("Iwanako", 35);
                ks::SceneManager::show_dialog("", 36);
                ks::SceneManager::show_dialog("Iwanako", 37);
                ks::SceneManager::show_dialog("", 38);
                ks::SceneManager::music_stop();
                ks::SceneManager::show_dialog("Iwanako", 39);
                ks::SceneManager::show_dialog("", 40);
                ks::SceneManager::show_dialog("n", 41);
                ks::SceneManager::show_dialog("n", 42);
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_out_cold__condition_0_0();
                } 
                
            
            }
            static void a1_monday_bundle_of_hisao() {
                ks::SceneManager::free_resources();
                ks::SceneManager::show_dialog("centered", 43);
                ks::SceneManager::set_background(bn::regular_bg_items::hosp_room);
                // renpy.music.set_volume(0.5, 0.0, channel="music"); TODO: unknown assignment
                ks::SceneManager::music_play("music_rain.gsm");
                ks::SceneManager::show_dialog("n", 44);
                ks::SceneManager::show_dialog("n", 45);
                ks::SceneManager::show_dialog("n", 46);
                ks::SceneManager::show_dialog("n", 47);
                ks::SceneManager::show_dialog("n", 48);
                ks::SceneManager::show_dialog("n", 49);
                ks::SceneManager::show_dialog("n", 50);
                ks::SceneManager::show_dialog("n", 51);
                ks::SceneManager::show_dialog("n", 52);
                ks::SceneManager::show_dialog("n", 53);
                ks::SceneManager::show_dialog("n", 54);
                ks::SceneManager::show_dialog("n", 55);
                ks::SceneManager::show_dialog("n", 56);
                ks::SceneManager::show_dialog("n", 57);
                ks::SceneManager::show_dialog("n", 58);
                ks::SceneManager::show_dialog("n", 59);
                ks::SceneManager::show_dialog("n", 60);
                ks::SceneManager::show_dialog("n", 61);
                ks::SceneManager::show_dialog("n", 62);
                ks::SceneManager::show_dialog("n", 63);
                ks::SceneManager::show_dialog("n", 64);
                ks::SceneManager::show_dialog("n", 65);
                ks::SceneManager::show_dialog("n", 66);
                ks::SceneManager::show_dialog("n", 67);
                ks::SceneManager::show_dialog("n", 68);
                ks::SceneManager::show_dialog("n", 69);
                ks::SceneManager::show_dialog("n", 70);
                ks::SceneManager::show_dialog("n", 71);
                ks::SceneManager::show_dialog("n", 72);
                ks::SceneManager::show_dialog("n", 73);
                ks::SceneManager::show_dialog("n", 74);
                ks::SceneManager::show_dialog("n", 75);
                ks::SceneManager::show_dialog("n", 76);
                ks::SceneManager::show_dialog("n", 77);
                ks::SceneManager::show_dialog("n", 78);
                ks::SceneManager::show_dialog("n", 79);
                ks::SceneManager::show_dialog("n", 80);
                ks::SceneManager::show_dialog("n", 81);
                ks::SceneManager::show_dialog("n", 82);
                ks::SceneManager::show_dialog("n", 83);
                ks::SceneManager::show_dialog("n", 84);
                // renpy.music.set_volume(1.0, 1.0, channel="music"); TODO: unknown assignment
                ks::SceneManager::show_dialog("", 85);
                ks::SceneManager::show_dialog("", 86);
                ks::SceneManager::show_dialog("", 87);
                ks::SceneManager::show_dialog("", 88);
                ks::SceneManager::show_dialog("Doctor", 89);
                ks::SceneManager::show_dialog("", 90);
                ks::SceneManager::show_dialog("Doctor", 91);
                ks::SceneManager::show_dialog("Doctor", 92);
                ks::SceneManager::show_dialog("", 93);
                ks::SceneManager::show_dialog("Dad", 94);
                ks::SceneManager::show_dialog("", 95);
                // renpy.music.set_volume(0.5, 2.0, channel="music"); TODO: unknown assignment
                ks::SceneManager::show_dialog("", 96);
                ks::SceneManager::show_dialog("", 97);
                ks::SceneManager::show_dialog("", 98);
                ks::SceneManager::show_dialog("", 99);
                ks::SceneManager::show_dialog("", 100);
                ks::SceneManager::show_dialog("", 101);
                // renpy.music.set_volume(1.0, 1.0, channel="music"); TODO: unknown assignment
                ks::SceneManager::set_background(bn::regular_bg_items::hosp_room);
                ks::SceneManager::show_dialog("Doctor", 102);
                ks::SceneManager::show_dialog("Doctor", 103);
                ks::SceneManager::show_dialog("", 104);
                ks::SceneManager::show_dialog("Doctor", 105);
                ks::SceneManager::show_dialog("", 106);
                ks::SceneManager::show_dialog("Dad", 107);
                ks::SceneManager::show_dialog("", 108);
                ks::SceneManager::show_dialog("", 109);
                ks::SceneManager::show_dialog("Doctor", 110);
                ks::SceneManager::show_dialog("Doctor", 111);
                ks::SceneManager::show_dialog("Doctor", 112);
                ks::SceneManager::show_dialog("Doctor", 113);
                ks::SceneManager::show_dialog("", 114);
                ks::SceneManager::show_dialog("Doctor", 115);
                ks::SceneManager::show_dialog("Doctor", 116);
                ks::SceneManager::show_dialog("", 117);
                ks::SceneManager::show_dialog("", 118);
                ks::SceneManager::show_dialog("Dad", 119);
                ks::SceneManager::show_dialog("Dad", 120);
                ks::SceneManager::show_dialog("", 121);
                ks::SceneManager::show_dialog("Doctor", 122);
                ks::SceneManager::show_dialog("", 123);
                ks::SceneManager::show_dialog("Doctor", 124);
                ks::SceneManager::show_dialog("", 125);
                ks::SceneManager::show_dialog("", 126);
                ks::SceneManager::show_dialog("Dad", 127);
                ks::SceneManager::show_dialog("Dad", 128);
                ks::SceneManager::show_dialog("Doctor", 129);
                ks::SceneManager::show_dialog("Doctor", 130);
                ks::SceneManager::show_dialog("", 131);
                ks::SceneManager::show_dialog("", 132);
                ks::SceneManager::music_stop();
                ks::SceneManager::show_dialog("", 133);
                ks::SceneManager::show_dialog("", 134);
                ks::SceneManager::show_dialog("", 135);
                ks::SceneManager::show_dialog("", 136);
                ks::SceneManager::show_dialog("", 137);
                ks::SceneManager::show_dialog("", 138);
                ks::SceneManager::show_dialog("", 139);
                ks::SceneManager::show_dialog("", 140);
                ks::SceneManager::show_dialog("", 141);
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_bundle_of_hisao__condition_0_0();
                } 
                
            
            }
            static void a1_monday_gateway_effect() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_gate);
                ks::SceneManager::music_play("music_happiness.gsm");
                ks::SceneManager::show_dialog("", 142);
                ks::SceneManager::show_dialog("", 143);
                ks::SceneManager::show_dialog("", 144);
                ks::SceneManager::show_dialog("", 145);
                ks::SceneManager::show_dialog("", 146);
                ks::SceneManager::show_dialog("", 147);
                ks::SceneManager::set_background(bn::regular_bg_items::school_courtyard);
                ks::SceneManager::show_dialog("", 148);
                ks::SceneManager::show_dialog("", 149);
                ks::SceneManager::show_dialog("", 150);
                ks::SceneManager::show_dialog("", 151);
                ks::SceneManager::show_dialog("", 152);
                ks::SceneManager::show_dialog("", 153);
                ks::SceneManager::show_dialog("", 154);
                ks::SceneManager::show_dialog("", 155);
                ks::SceneManager::show_dialog("", 156);
                ks::SceneManager::show_dialog("", 157);
                ks::SceneManager::show_dialog("", 158);
                ks::SceneManager::show_dialog("", 159);
                ks::SceneManager::show_dialog("", 160);
                ks::SceneManager::show_dialog("", 161);
                ks::SceneManager::show_dialog("", 162);
                ks::SceneManager::show_dialog("", 163);
                ks::SceneManager::show_dialog("", 164);
                ks::SceneManager::show_dialog("", 165);
                ks::SceneManager::show_dialog("", 166);
                ks::SceneManager::show_dialog("", 167);
                ks::SceneManager::set_background(bn::regular_bg_items::school_lobby);
                ks::SceneManager::show_dialog("", 168);
                ks::SceneManager::show_dialog("mu_", 169);
                ks::SceneManager::show_dialog("hi", 170);
                ks::SceneManager::show_dialog("mu_", 171);
                ks::SceneManager::show_dialog("mu", 172);
                ks::SceneManager::show_dialog("", 173);
                ks::SceneManager::show_dialog("mu", 174);
                ks::SceneManager::show_dialog("hi", 175);
                ks::SceneManager::show_dialog("mu", 176);
                ks::SceneManager::show_dialog("", 177);
                ks::SceneManager::show_dialog("", 178);
                ks::SceneManager::show_dialog("", 179);
                ScriptA1MondayEn::a1_monday_gateway_effect__menu_question_0();
                ks::SceneManager::set_background(bn::regular_bg_items::school_staircase2);
                ks::SceneManager::show_dialog("", 180);
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3);
                ks::SceneManager::show_dialog("", 181);
                ks::SceneManager::show_dialog("", 182);
                ks::SceneManager::show_dialog("mu", 183);
                ks::SceneManager::music_stop();
                ks::SceneManager::show_dialog("", 184);
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_gateway_effect__condition_0_0();
                } 
                
            
            }
            static void a1_monday_enter_stage_left() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3);
                ks::SceneManager::show_dialog("", 185);
                ks::SceneManager::set_background(bn::regular_bg_items::hisao_class);
                ks::SceneManager::music_play("music_normal.gsm");
                ks::SceneManager::show_dialog("", 186);
                ks::SceneManager::show_dialog("", 187);
                ks::SceneManager::show_dialog("", 188);
                ks::SceneManager::show_dialog("", 189);
                ks::SceneManager::show_dialog("", 190);
                ks::SceneManager::set_background(bn::regular_bg_items::hisao_class);
                ks::SceneManager::show_dialog("", 191);
                ks::SceneManager::show_dialog("", 192);
                ks::SceneManager::show_dialog("", 193);
                ks::SceneManager::show_dialog("", 194);
                ks::SceneManager::show_dialog("", 195);
                ks::SceneManager::show_dialog("", 196);
                ks::SceneManager::show_dialog("mu", 197);
                ks::SceneManager::show_dialog("", 198);
                if (ks::progress.wanted_introduce || ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_0_0();
                } 
                else {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_0_1();
                } 
                
            
                ks::SceneManager::set_background(bn::regular_bg_items::hisao_class);
                ks::SceneManager::show_dialog("", 199);
                ks::SceneManager::show_dialog("", 200);
                ks::SceneManager::show_dialog("", 201);
                ks::SceneManager::show_dialog("", 202);
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                ks::SceneManager::show_dialog("mu", 203);
                ks::SceneManager::show_dialog("hi", 204);
                ks::SceneManager::show_dialog("mu", 205);
                ks::SceneManager::show_dialog("mu", 206);
                ks::SceneManager::show_dialog("", 207);
                ks::SceneManager::show_dialog("", 208);
                ks::SceneManager::show_dialog("", 209);
                ks::SceneManager::show_dialog("mu", 210);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("", 211);
                ks::SceneManager::show_dialog("hi", 212);
                ks::SceneManager::music_stop();
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                ks::SceneManager::show_dialog("mi_shi", 213);
                ks::SceneManager::show_dialog("", 214);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi_shi", 215);
                ks::SceneManager::show_dialog("mi_not_shi", 216);
                ks::SceneManager::music_play("music_shizune.gsm");
                ks::SceneManager::set_character_position(0, -48, 0);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic, 48, 0);
                ks::SceneManager::show_dialog("", 217);
                ks::SceneManager::show_dialog("", 218);
                ks::SceneManager::show_dialog("hi", 219);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("", 220);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("", 221);
                ks::SceneManager::show_dialog("", 222);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 223);
                ks::SceneManager::show_dialog("mi", 224);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 225);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("mi", 226);
                if (ks::progress.wanted_introduce || ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_1_0();
                } 
                else {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_1_1();
                } 
                
            
                ks::SceneManager::show_dialog("mi", 227);
                ks::SceneManager::show_dialog("", 228);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 229);
                ks::SceneManager::show_dialog("", 230);
                ks::SceneManager::show_dialog("hi", 231);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, ks::sprite_metas::misha_cross);
                ks::SceneManager::show_dialog("mi", 232);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                ks::SceneManager::show_dialog("mi", 233);
                ks::SceneManager::show_dialog("hi", 234);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_dialog("", 235);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("", 236);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 237);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 238);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                ks::SceneManager::show_dialog("mi", 239);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("extend", 240);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("extend", 241);
                ks::SceneManager::show_dialog("", 242);
                ks::SceneManager::show_dialog("hi", 243);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 213);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 244);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 245);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("", 246);
                ks::SceneManager::show_dialog("", 247);
                ks::SceneManager::show_dialog("", 248);
                ks::SceneManager::show_dialog("", 249);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("mi", 250);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("mi", 251);
                ks::SceneManager::show_dialog("mi", 252);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross);
                ks::SceneManager::show_dialog("mi", 253);
                ks::SceneManager::show_dialog("hi", 254);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("mi", 255);
                ks::SceneManager::music_stop();
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_blush, ks::sprite_metas::shizu_adjust);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 256);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::music_play("music_shizune.gsm");
                ks::SceneManager::show_dialog("mi", 257);
                ks::SceneManager::show_dialog("hi", 258);
                ks::SceneManager::show_dialog("", 259);
                ks::SceneManager::show_dialog("", 260);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("shi", 261);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("mi", 262);
                ks::SceneManager::show_dialog("hi", 263);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 264);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, ks::sprite_metas::shizu_basic);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_dialog("", 265);
                ks::SceneManager::show_dialog("hi", 266);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_dialog("mi", 267);
                ks::SceneManager::show_dialog("", 268);
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                ks::SceneManager::show_dialog("", 269);
                ks::SceneManager::show_dialog("", 270);
                ks::SceneManager::show_dialog("", 271);
                ks::SceneManager::show_dialog("", 272);
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3);
                ks::SceneManager::show_dialog("", 273);
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_2_0();
                } 
                
            
            }
            static void a1_monday_in_the_nursery() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_staircase2);
                ks::SceneManager::show_dialog("", 274);
                ks::SceneManager::set_background(bn::regular_bg_items::school_cafeteria);
                ks::SceneManager::show_dialog("", 275);
                ks::SceneManager::show_dialog("", 276);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::music_play("music_ease.gsm");
                ks::SceneManager::show_dialog("mi", 277);
                ks::SceneManager::show_dialog("", 278);
                ks::SceneManager::hide_character(0);
                ks::SceneManager::show_dialog("", 279);
                ks::SceneManager::show_dialog("", 280);
                ks::SceneManager::show_dialog("", 281);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, ks::sprite_metas::misha_hips, -48, 0);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic, 48, 0);
                ks::SceneManager::show_dialog("", 282);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, ks::sprite_metas::shizu_basic);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_dialog("", 283);
                ks::SceneManager::show_dialog("", 284);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("mi", 285);
                ks::SceneManager::show_dialog("hi", 286);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 287);
                ScriptA1MondayEn::a1_monday_in_the_nursery__menu_question_0();
                ks::SceneManager::show_dialog("", 288);
                ks::SceneManager::show_dialog("", 289);
                ks::SceneManager::show_dialog("", 163);
                ks::SceneManager::music_stop();
                // renpy.music.set_volume(1.0, .5, channel="ambient"); TODO: unknown assignment
                ks::SceneManager::show_dialog("", 290);
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                ks::SceneManager::music_play("music_daily.gsm");
                ks::SceneManager::show_dialog("", 291);
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_emb, bn::sprite_items::hanako_spr_emb_downtimid, ks::sprite_metas::hanako_emb);
                ks::SceneManager::show_dialog("", 292);
                ks::SceneManager::show_character(2, bn::regular_bg_items::hanako_bg_defarms, bn::sprite_items::hanako_spr_defarms_shock, ks::sprite_metas::hanako_defarms);
                ks::SceneManager::show_dialog("", 293);
                ks::SceneManager::show_dialog("", 294);
                ks::SceneManager::show_dialog("", 295);
                ks::SceneManager::set_character_position(2, 120, 0);
                ks::SceneManager::hide_character(2);
                ks::SceneManager::show_dialog("", 296);
                ks::SceneManager::show_dialog("", 297);
                ks::SceneManager::show_dialog("", 298);
                ks::SceneManager::show_dialog("", 299);
                ks::SceneManager::show_dialog("", 300);
                ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom);
                ks::SceneManager::show_dialog("", 301);
                ks::SceneManager::show_dialog("", 302);
                ks::SceneManager::show_dialog("", 303);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind, 48, 0);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky, -48, 0);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_dialog("mi", 304);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_dialog("mi", 305);
                ks::SceneManager::show_dialog("hi", 306);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 307);
                ks::SceneManager::show_dialog("mi", 308);
                ks::SceneManager::hide_character(1);
                ks::SceneManager::hide_character(0);
                ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3);
                ks::SceneManager::show_dialog("", 309);
                ks::SceneManager::set_background(bn::regular_bg_items::school_courtyard);
                ks::SceneManager::show_dialog("", 310);
                ks::SceneManager::show_dialog("", 311);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind, 48, 0);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky, -48, 0);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_dialog("mi", 312);
                ks::SceneManager::show_dialog("hi", 313);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frustrated, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("shi", 163);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_dialog("mi", 314);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                ks::SceneManager::show_dialog("mi", 315);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("mi", 316);
                ks::SceneManager::show_dialog("hi", 317);
                ks::SceneManager::music_stop();
                ks::SceneManager::hide_character(1);
                ks::SceneManager::hide_character(0);
                ks::SceneManager::show_dialog("", 318);
                ks::SceneManager::show_dialog("", 319);
                ks::SceneManager::set_background(bn::regular_bg_items::school_nursehall);
                ks::SceneManager::show_dialog("", 320);
                ks::SceneManager::show_dialog("", 321);
                ks::SceneManager::show_dialog("", 322);
                ks::SceneManager::show_dialog("", 323);
                ks::SceneManager::set_background(bn::regular_bg_items::school_nurseoffice);
                ks::SceneManager::show_dialog("", 324);
                ks::SceneManager::show_dialog("", 325);
                ks::SceneManager::music_play("music_nurse.gsm");
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("nk_", 326);
                ks::SceneManager::show_dialog("", 327);
                ks::SceneManager::show_dialog("hi", 328);
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_grin, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("", 329);
                ks::SceneManager::show_dialog("nk_", 330);
                ks::SceneManager::show_dialog("nk_", 331);
                ks::SceneManager::show_dialog("", 332);
                ks::SceneManager::show_dialog("hi", 333);
                ks::SceneManager::show_dialog("", 334);
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("nk", 335);
                ks::SceneManager::show_dialog("nk", 336);
                ks::SceneManager::show_dialog("", 337);
                ks::SceneManager::show_dialog("hi", 338);
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("nk", 339);
                ks::SceneManager::show_dialog("nk", 340);
                ks::SceneManager::show_dialog("nk", 341);
                ks::SceneManager::show_dialog("", 342);
                ks::SceneManager::show_dialog("hi", 343);
                ks::SceneManager::show_dialog("nk", 344);
                ks::SceneManager::show_dialog("", 345);
                ks::SceneManager::show_dialog("hi", 346);
                ks::SceneManager::show_dialog("nk", 347);
                ks::SceneManager::show_dialog("", 348);
                ks::SceneManager::show_dialog("nk", 349);
                ks::SceneManager::show_dialog("", 350);
                ks::SceneManager::show_dialog("", 351);
                ks::SceneManager::show_dialog("", 352);
                ks::SceneManager::show_dialog("", 353);
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_grin, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("", 354);
                ks::SceneManager::show_dialog("nk", 355);
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("nk", 356);
                ks::SceneManager::show_dialog("", 357);
                ks::SceneManager::show_dialog("hi", 358);
                ks::SceneManager::show_dialog("nk", 359);
                ks::SceneManager::show_dialog("hi", 360);
                ks::SceneManager::show_dialog("", 361);
                ks::SceneManager::show_dialog("", 362);
                ks::SceneManager::show_dialog("nk", 363);
                ks::SceneManager::show_dialog("nk", 364);
                ks::SceneManager::show_dialog("hi", 365);
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("", 366);
                ks::SceneManager::show_dialog("nk", 367);
                ks::SceneManager::show_dialog("nk", 368);
                ks::SceneManager::show_dialog("nk", 369);
                ks::SceneManager::show_dialog("nk", 370);
                ks::SceneManager::show_dialog("hi", 371);
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("nk", 372);
                ks::SceneManager::show_dialog("nk", 373);
                ks::SceneManager::show_dialog("", 374);
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("nk", 375);
                ks::SceneManager::show_dialog("hi", 376);
                ks::SceneManager::show_dialog("", 377);
                ks::SceneManager::show_character(3, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse);
                ks::SceneManager::show_dialog("nk", 378);
                ks::SceneManager::set_background(bn::regular_bg_items::school_nursehall);
                ks::SceneManager::music_stop();
                ks::SceneManager::show_dialog("", 379);
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_in_the_nursery__condition_0_0();
                } 
                
            
            }
            static void a1_monday_nobodys_room() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::school_courtyard);
                ks::SceneManager::music_play("music_pearly.gsm");
                ks::SceneManager::show_dialog("", 380);
                ks::SceneManager::show_dialog("", 381);
                ks::SceneManager::show_dialog("", 382);
                ks::SceneManager::show_dialog("", 383);
                ks::SceneManager::show_dialog("", 384);
                ks::SceneManager::show_dialog("", 163);
                ks::SceneManager::show_dialog("", 385);
                ks::SceneManager::show_dialog("", 386);
                ks::SceneManager::show_dialog("", 387);
                ks::SceneManager::set_background(bn::regular_bg_items::school_gardens);
                ks::SceneManager::show_dialog("", 388);
                ks::SceneManager::show_dialog("", 389);
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormext_start);
                ks::SceneManager::show_dialog("", 390);
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhallground);
                ks::SceneManager::show_dialog("", 391);
                ks::SceneManager::show_dialog("hi", 392);
                ks::SceneManager::show_dialog("", 393);
                ks::SceneManager::show_dialog("", 394);
                ks::SceneManager::show_dialog("", 395);
                ks::SceneManager::show_dialog("", 396);
                ks::SceneManager::show_dialog("", 397);
                ks::SceneManager::show_dialog("", 398);
                ks::SceneManager::show_dialog("", 399);
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhallway);
                ks::SceneManager::show_dialog("", 400);
                ks::SceneManager::show_dialog("", 401);
                ks::SceneManager::show_dialog("", 402);
                ks::SceneManager::show_dialog("", 403);
                ks::SceneManager::music_stop();
                ks::SceneManager::show_dialog("", 404);
                ks::SceneManager::show_dialog("hi", 405);
                ks::SceneManager::show_dialog("", 406);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                ks::SceneManager::music_play("music_kenji.gsm");
                ks::SceneManager::show_dialog("", 407);
                ks::SceneManager::show_dialog("ke_", 408);
                ks::SceneManager::show_dialog("", 409);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                ks::SceneManager::show_dialog("", 410);
                ks::SceneManager::show_dialog("hi", 411);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic);
                ks::SceneManager::show_dialog("", 412);
                ks::SceneManager::show_dialog("ke_", 413);
                ks::SceneManager::show_dialog("hi", 414);
                ks::SceneManager::show_dialog("", 415);
                ks::SceneManager::show_dialog("ke", 416);
                ks::SceneManager::show_dialog("hi", 417);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                ks::SceneManager::show_dialog("ke", 418);
                ks::SceneManager::show_dialog("", 419);
                ks::SceneManager::show_dialog("hi", 420);
                ks::SceneManager::show_dialog("", 421);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                ks::SceneManager::show_dialog("ke", 422);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                ks::SceneManager::show_dialog("ke", 423);
                ks::SceneManager::show_dialog("ke", 424);
                ks::SceneManager::show_dialog("hi", 425);
                ks::SceneManager::show_dialog("", 426);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                ks::SceneManager::show_dialog("ke", 427);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic);
                ks::SceneManager::show_dialog("ke", 428);
                ks::SceneManager::show_dialog("ke", 429);
                ks::SceneManager::show_dialog("ke", 430);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic);
                ks::SceneManager::show_dialog("", 431);
                ks::SceneManager::show_character(4, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic);
                ks::SceneManager::show_dialog("ke", 432);
                ks::SceneManager::hide_character(4);
                ks::SceneManager::music_stop();
                ks::SceneManager::show_dialog("", 433);
                ks::SceneManager::show_dialog("extend", 434);
                ks::SceneManager::show_dialog("", 435);
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhisao_ss);
                ks::SceneManager::music_play("music_night.gsm");
                ks::SceneManager::show_dialog("", 436);
                ks::SceneManager::show_dialog("", 437);
                ks::SceneManager::show_dialog("", 438);
                ks::SceneManager::show_dialog("", 439);
                ks::SceneManager::show_dialog("", 440);
                ks::SceneManager::show_dialog("", 441);
                ks::SceneManager::show_dialog("", 442);
                ks::SceneManager::show_dialog("", 443);
                ks::SceneManager::show_dialog("", 444);
                ks::SceneManager::show_dialog("", 445);
                ks::SceneManager::show_dialog("", 446);
                ks::SceneManager::show_dialog("", 447);
                ks::SceneManager::show_dialog("", 448);
                ks::SceneManager::show_dialog("", 449);
                ks::SceneManager::show_dialog("", 450);
                ks::SceneManager::show_dialog("", 451);
                ks::SceneManager::show_dialog("", 452);
                ks::SceneManager::show_dialog("", 453);
                ks::SceneManager::show_dialog("", 454);
                ks::SceneManager::show_dialog("", 455);
                ks::SceneManager::show_dialog("", 456);
                ks::SceneManager::show_dialog("", 457);
                ks::SceneManager::show_dialog("", 458);
                ks::SceneManager::show_dialog("", 459);
                ks::SceneManager::show_dialog("", 163);
                ks::SceneManager::show_dialog("", 460);
                ks::SceneManager::music_stop();
                ks::SceneManager::set_background(bn::regular_bg_items::school_dormhisao_ni);
                ks::SceneManager::show_dialog("", 461);
                ks::SceneManager::show_dialog("", 462);
                ks::SceneManager::show_dialog("", 463);
                ks::SceneManager::show_dialog("", 464);
                ks::SceneManager::show_dialog("", 465);
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_nobodys_room__condition_0_0();
                } 
                
            
            }
            static void a1_monday() {
                ks::SceneManager::set(ks::SceneManager("script_a1_monday", "en", script_a1_monday_en_intl));
            
                a1_monday_out_cold();
                a1_monday_bundle_of_hisao();
                a1_monday_gateway_effect();
                a1_monday_enter_stage_left();
                a1_monday_in_the_nursery();
                a1_monday_nobodys_room();
            }
            static void a1c1o1() {
                ks::SceneManager::show_dialog("hi", 466);
                ks::SceneManager::show_dialog("mu", 467);
                ks::SceneManager::show_dialog("hi", 468);
                ks::SceneManager::show_dialog("mu", 469);
                return;
            }
            static void a1c1o2() {
                ks::SceneManager::show_dialog("hi", 470);
                ks::SceneManager::show_dialog("mu", 471);
                ks::SceneManager::show_dialog("", 472);
                ks::SceneManager::show_dialog("hi", 473);
                ks::SceneManager::show_dialog("mu", 469);
                return;
            }
            static void a1c2o1() {
                ks::SceneManager::show_dialog("hi", 474);
                ks::SceneManager::show_dialog("", 475);
                ks::SceneManager::show_dialog("mi", 476);
                ks::SceneManager::show_dialog("hi", 477);
                ks::SceneManager::show_dialog("", 478);
                return;
            }
            static void a1c2o2() {
                ks::SceneManager::show_dialog("", 479);
                ks::SceneManager::show_dialog("", 480);
                ks::SceneManager::show_dialog("", 481);
                ks::SceneManager::show_dialog("", 482);
                return;
            }
            static void a1c2o3() {
                ks::SceneManager::show_dialog("hi", 483);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign);
                ks::SceneManager::show_dialog("mi", 484);
                ks::SceneManager::show_dialog("", 163);
                ks::SceneManager::show_dialog("hi", 485);
                ks::SceneManager::show_character(0, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips);
                ks::SceneManager::show_character(1, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind);
                ks::SceneManager::show_dialog("", 486);
                ks::SceneManager::show_dialog("", 487);
                return;
            }
            static void a1_monday_gateway_effect__menu_question_0() {
                ks::SceneManager::show_dialog("mu", 488);
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 489});
                answers.push_back(ks::answer_ptr{1, 490});
                ks::SceneManager::show_dialog_question(answers);
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1MondayEn::a1_monday_gateway_effect__menu_question_0_why();
                } else if (answer == 1) {
                    ScriptA1MondayEn::a1_monday_gateway_effect__menu_question_0_yeah_of_course();
                }
            }
            static void a1_monday_gateway_effect__menu_question_0_why() {
                ks::progress.wanted_introduce = false;
                ScriptA1MondayEn::a1c1o1();
            }
            static void a1_monday_gateway_effect__menu_question_0_yeah_of_course() {
                ks::progress.wanted_introduce = true;
                ks::progress.attraction_sc += 1;
                ScriptA1MondayEn::a1c1o2();
            }
            static void a1_monday_in_the_nursery__menu_question_0() {
                ks::SceneManager::show_dialog("hi", 491);
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 492});
                answers.push_back(ks::answer_ptr{1, 493});
                answers.push_back(ks::answer_ptr{2, 494});
                ks::SceneManager::show_dialog_question(answers);
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1MondayEn::a1_monday_in_the_nursery__menu_question_0_ask_about_the_library();
                } else if (answer == 1) {
                    ScriptA1MondayEn::a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness();
                } else if (answer == 2) {
                    ScriptA1MondayEn::a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know();
                }
            }
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_the_library() {
                ks::progress.attraction_hanako += 1;
                ScriptA1MondayEn::a1c2o1();
            }
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness() {
                ScriptA1MondayEn::a1c2o2();
            }
            static void a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know() {
                ks::progress.attraction_sc += 1;
                ScriptA1MondayEn::a1c2o3();
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
                ks::SceneManager::show_dialog("", 495);
                ks::SceneManager::show_dialog("hi", 496);
                ks::SceneManager::show_dialog("", 497);
                ks::SceneManager::show_dialog("hi", 498);
                ks::SceneManager::show_dialog("", 497);
                ks::SceneManager::show_dialog("", 499);
                ks::SceneManager::show_dialog("", 500);
                ks::SceneManager::show_dialog("", 501);
                ks::SceneManager::show_dialog("", 163);
            }
            static void a1_monday_enter_stage_left__condition_0_1() {
                ks::SceneManager::show_dialog("", 502);
                ks::SceneManager::show_dialog("", 503);
                ks::SceneManager::show_dialog("", 504);
                ks::SceneManager::show_dialog("", 505);
                ks::SceneManager::show_dialog("", 506);
                ks::SceneManager::show_dialog("", 507);
            }
            static void a1_monday_enter_stage_left__condition_1_0() {
                ks::SceneManager::show_dialog("mi", 508);
            }
            static void a1_monday_enter_stage_left__condition_1_1() {
                ks::SceneManager::show_dialog("", 509);
                ks::SceneManager::show_dialog("mi", 510);
                ks::SceneManager::show_dialog("", 511);
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