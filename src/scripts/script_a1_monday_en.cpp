#include "script_a1_monday.h"
#include "script_a1_monday_en_tl_index.h"
namespace ks {
    class ScriptA1MondayEn : public ScriptA1Monday {
        public:
            static void a1_monday_out_cold() {
                ks::SceneManager::free_resources();
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods, 0, 0, 60));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play("music_serene.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 4));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_rustling.8ad"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mystery, 11));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 13));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::other_iwanako, 0, 0, 0));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 17));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Iwanako", 20));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 21));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods, 0, 0, 0));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 22));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::other_iwanako, 0, 0, 0));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 23));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 24));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 27));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 28));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods, 0, 0, 0));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 29));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Iwanako", 30));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Iwanako", 31));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Iwanako", 32));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 34));
                IF_NOT_EXIT(ks::SceneManager::music_play("music_tragic.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Iwanako", 35));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Iwanako", 37));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 38));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartstop.8ad"));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Iwanako", 39));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 40));
                // TODO: Show passoutOP1
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 41));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 42));
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_out_cold__condition_0_0();
                } 
                
            
            }
            static void a1_monday_bundle_of_hisao() {
                ks::SceneManager::free_resources();
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::centered, 43));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::hosp_room, 0, 0, 0));
                // TODO: Show sakura
                // TODO: Show hospitalmask
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // renpy.music.set_volume(0.5, 0.0, channel="music"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::music_play("music_rain.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 44));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 45));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 46));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 47));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 48));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 49));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 50));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 51));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 52));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 53));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 54));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 55));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 56));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 57));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 58));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 59));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 60));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 61));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 62));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 63));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 64));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 65));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 66));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 67));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 68));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 69));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 70));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 71));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 72));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 73));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 74));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 75));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 76));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 77));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 78));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 79));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 80));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 81));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 82));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 83));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 84));
                // renpy.music.set_volume(1.0, 1.0, channel="music"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 85));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 86));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 87));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 88));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 89));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 90));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 91));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 92));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 93));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Dad", 94));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 95));
                // renpy.music.set_volume(0.5, 2.0, channel="music"); TODO: unknown assignment
                // TODO: Show drugs
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 96));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 97));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 98));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 99));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 100));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 101));
                // renpy.music.set_volume(1.0, 1.0, channel="music"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::hosp_room, 0, 0, 0));
                // TODO: Show sakura
                // TODO: Show hospitalmask
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 102));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 103));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 104));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 105));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 106));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Dad", 107));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 108));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 109));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 110));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 111));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 112));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 113));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 114));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 115));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 116));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 117));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 118));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Dad", 119));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Dad", 120));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 121));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 122));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 123));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 124));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 125));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 126));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Dad", 127));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Dad", 128));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 129));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Doctor", 130));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 131));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 132));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 133));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 134));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 135));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 136));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 137));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 138));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 139));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 140));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 141));
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_bundle_of_hisao__condition_0_0();
                } 
                
            
            }
            static void a1_monday_gateway_effect() {
                ks::SceneManager::free_resources();
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_gate, 0, 0, 90));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play("music_happiness.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 142));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 143));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 144));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 145));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 146));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 147));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_courtyard, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 148));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 149));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 150));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 151));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 152));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 153));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 154));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 155));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 156));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 157));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 158));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 159));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 160));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 161));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 162));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 164));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 165));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 166));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 167));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_lobby, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 168));
                IF_NOT_EXIT(ks::SceneManager::show_character(0, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, ks::sprite_metas::muto_basic, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu_, 169));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 170));
                IF_NOT_EXIT(ks::SceneManager::show_character(0, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_smile, ks::sprite_metas::muto_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu_, 171));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 172));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 173));
                IF_NOT_EXIT(ks::SceneManager::show_character(0, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_irritated, ks::sprite_metas::muto_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 174));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 175));
                IF_NOT_EXIT(ks::SceneManager::show_character(0, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, ks::sprite_metas::muto_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 176));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 177));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 178));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 179));
                ScriptA1MondayEn::a1_monday_gateway_effect__menu_question_0();
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_staircase2, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 180));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::show_character(0, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, ks::sprite_metas::muto_basic, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 181));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_dooropen.8ad"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 182));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::hide_character(0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 183));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 184));
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_gateway_effect__condition_0_0();
                } 
                
            
            }
            static void a1_monday_enter_stage_left() {
                ks::SceneManager::free_resources();
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3, 0, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 185));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::hisao_class, 0, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play("music_normal.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 186));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 187));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 188));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 189));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 190));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::hisao_class, 0, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 191));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 192));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 193));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 194));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 195));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 196));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 197));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 198));
                if (ks::progress.wanted_introduce || ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_0_0();
                } 
                else {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_0_1();
                } 
                
            
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::hisao_class, 0, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 199));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 200));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 201));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 202));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom, -8, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(0, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, ks::sprite_metas::muto_basic, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 203));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 204));
                IF_NOT_EXIT(ks::SceneManager::show_character(0, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_smile, ks::sprite_metas::muto_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 205));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 206));
                ks::SceneManager::hide_character(0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 207));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 208));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 209));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 210));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 211));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 212));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi_shi, 213));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 214));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi_shi, 215));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi_not_shi, 216));
                IF_NOT_EXIT(ks::SceneManager::music_play("music_shizune.gsm"));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(1, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 217));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 218));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 219));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 220));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 221));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 222));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 223));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 224));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 225));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 226));
                if (ks::progress.wanted_introduce || ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_1_0();
                } 
                else {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_1_1();
                } 
                
            
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 227));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 228));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 229));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 230));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 231));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, ks::sprite_metas::misha_cross));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 232));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, ks::sprite_metas::shizu_adjust));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 233));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 234));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 235));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 236));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 237));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 238));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 239));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::extend, 240));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::extend, 241));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 242));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 243));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 213));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 244));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 245));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 246));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 247));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 248));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 249));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 250));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 251));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 252));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, ks::sprite_metas::misha_cross));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 253));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 254));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, ks::sprite_metas::shizu_adjust));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 255));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_blush, ks::sprite_metas::shizu_adjust));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 256));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play("music_shizune.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 257));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 258));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 259));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 260));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 261));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 262));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 263));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 264));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, ks::sprite_metas::shizu_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 265));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 266));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 267));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 268));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom, 0, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 269));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 270));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 271));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_normalbell.8ad"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 272));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 273));
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_enter_stage_left__condition_2_0();
                } 
                
            
            }
            static void a1_monday_in_the_nursery() {
                ks::SceneManager::free_resources();
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_staircase2, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 274));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_cafeteria, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 275));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 276));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play("music_ease.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 277));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 278));
                ks::SceneManager::hide_character(1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 279));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 280));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 281));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, ks::sprite_metas::misha_hips, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, ks::sprite_metas::shizu_basic, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 282));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, ks::sprite_metas::shizu_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 283));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 284));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 285));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 286));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 287));
                ScriptA1MondayEn::a1_monday_in_the_nursery__menu_question_0();
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 288));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 289));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 163));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                // renpy.music.set_volume(1.0, .5, channel="ambient"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 290));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom, 0, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play("music_daily.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 291));
                IF_NOT_EXIT(ks::SceneManager::show_character(3, bn::regular_bg_items::hanako_bg_emb, bn::sprite_items::hanako_spr_emb_downtimid, ks::sprite_metas::hanako_emb));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 292));
                IF_NOT_EXIT(ks::SceneManager::show_character(3, bn::regular_bg_items::hanako_bg_defarms, bn::sprite_items::hanako_spr_defarms_shock, ks::sprite_metas::hanako_defarms));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 293));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 294));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 295));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(3, 184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::hide_character(3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 296));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 297));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 298));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 299));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 300));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_scienceroom, 0, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_normalbell.8ad"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 301));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 302));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 303));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, ks::sprite_metas::shizu_behind, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 304));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, ks::sprite_metas::shizu_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 305));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 306));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 307));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 308));
                ks::SceneManager::hide_character(2);
                ks::SceneManager::hide_character(1);
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_hallway3, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 309));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_courtyard, 0, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 310));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 311));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, ks::sprite_metas::misha_perky, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 312));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 313));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frustrated, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 163));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 314));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 315));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 316));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 317));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                ks::SceneManager::hide_character(2);
                ks::SceneManager::hide_character(1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 318));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 319));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_nursehall, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 320));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 321));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_doorknock2.8ad"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 322));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 323));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_dooropen.8ad"));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_nurseoffice, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 324));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 325));
                IF_NOT_EXIT(ks::SceneManager::music_play("music_nurse.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk_, 326));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 327));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 328));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_grin, ks::sprite_metas::nurse));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 329));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk_, 330));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk_, 331));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 332));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 333));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_snap.8ad"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 334));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, ks::sprite_metas::nurse));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 335));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 336));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 337));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 338));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 339));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 340));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 341));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 342));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 343));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 344));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 345));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 346));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 347));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 348));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 349));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 350));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 351));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 352));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 353));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_grin, ks::sprite_metas::nurse));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 354));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 355));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, ks::sprite_metas::nurse));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 356));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 357));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 358));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 359));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 360));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 361));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 362));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 363));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 364));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 365));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, ks::sprite_metas::nurse));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 366));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 367));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 368));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 369));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 370));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 371));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 372));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 373));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 374));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, ks::sprite_metas::nurse));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 375));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 376));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 377));
                IF_NOT_EXIT(ks::SceneManager::show_character(4, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, ks::sprite_metas::nurse));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 378));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_nursehall, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 379));
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_in_the_nursery__condition_0_0();
                } 
                
            
            }
            static void a1_monday_nobodys_room() {
                ks::SceneManager::free_resources();
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_courtyard, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play("music_pearly.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 380));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 381));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 382));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 383));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 384));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 385));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 386));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 387));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_gardens, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 388));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 389));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_dormext_start, 8, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 390));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_dormhallground, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 391));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 392));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 393));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 394));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 395));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 396));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 397));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 398));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 399));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_dormhallway, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 400));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 401));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 402));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 403));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_doorknock2.8ad"));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 404));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 405));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 406));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(5, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play("music_kenji.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 407));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke_, 408));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 409));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 410));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 411));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 412));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke_, 413));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 414));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 415));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 416));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 417));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 418));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 419));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 420));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 421));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 422));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 423));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 424));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 425));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 426));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 427));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 428));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 429));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 430));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 431));
                IF_NOT_EXIT(ks::SceneManager::show_character(5, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, ks::sprite_metas::kenji_basic));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 432));
                ks::SceneManager::hide_character(5);
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 433));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_doorslam.8ad"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::extend, 434));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 435));
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_dormhisao_ss, 0, 0, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play("music_night.gsm"));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 436));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 437));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 438));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 439));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 440));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 441));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 442));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 443));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 444));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 445));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 446));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 447));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 448));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 449));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 450));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 451));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 452));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 453));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 454));
                // TODO: Show pills
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Show pills
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 455));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 456));
                // TODO: Show pills
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide pills
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 457));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 458));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 459));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 460));
                IF_NOT_EXIT(ks::SceneManager::music_stop());
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::school_dormhisao_ni, 0, 0, 90));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 461));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 462));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 463));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 464));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 465));
                if (ks::in_replay) {
                    ScriptA1MondayEn::a1_monday_nobodys_room__condition_0_0();
                } 
                
            
            }
            static void a1_monday() {
                IF_NOT_EXIT(ks::SceneManager::set_initial_progress(ks::progress));
                IF_NOT_EXIT(ks::SceneManager::set(ks::SceneManager("script_a1_monday", "en", script_a1_monday_en_intl)));
            
                IF_NOT_EXIT(a1_monday_out_cold());
                IF_NOT_EXIT(ks::SceneManager::show_video(video_op_1_agmv, video_op_1_agmv_size, "video_op_1.gsm"));IF_NOT_EXIT(ks::SceneManager::set(ks::SceneManager("script_a1_monday", "en", script_a1_monday_en_intl)));
            
                IF_NOT_EXIT(a1_monday_bundle_of_hisao());
                IF_NOT_EXIT(ks::SceneManager::show_video(video_tc_act1_agmv, video_tc_act1_agmv_size, "video_tc_act1.gsm"));IF_NOT_EXIT(ks::SceneManager::set(ks::SceneManager("script_a1_monday", "en", script_a1_monday_en_intl)));
            
                IF_NOT_EXIT(a1_monday_gateway_effect());
                IF_NOT_EXIT(a1_monday_enter_stage_left());
                IF_NOT_EXIT(a1_monday_in_the_nursery());
                IF_NOT_EXIT(a1_monday_nobodys_room());
            }
            static void a1c1o1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 466));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 467));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 468));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 469));
                return;
            }
            static void a1c1o2() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 470));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 471));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 472));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 473));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 469));
                return;
            }
            static void a1c2o1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 474));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 475));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 476));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 477));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 478));
                return;
            }
            static void a1c2o2() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 479));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 480));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 481));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 482));
                return;
            }
            static void a1c2o3() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 483));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, ks::sprite_metas::misha_sign));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 484));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 163));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 485));
                IF_NOT_EXIT(ks::SceneManager::show_character(1, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, ks::sprite_metas::misha_hips));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(2, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, ks::sprite_metas::shizu_behind));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 486));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 487));
                return;
            }
            static void a1_monday_gateway_effect__menu_question_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 488));
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 489});
                answers.push_back(ks::answer_ptr{1, 490});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1MondayEn::a1_monday_gateway_effect__menu_question_0_why();
                } else if (answer == 1) {
                    ScriptA1MondayEn::a1_monday_gateway_effect__menu_question_0_yeah_of_course();
                }
            }
            static void a1_monday_gateway_effect__menu_question_0_why() {
                ks::progress.wanted_introduce = false;
                IF_NOT_EXIT(ScriptA1MondayEn::a1c1o1());
            }
            static void a1_monday_gateway_effect__menu_question_0_yeah_of_course() {
                ks::progress.wanted_introduce = true;
                ks::progress.attraction_sc += 1;
                IF_NOT_EXIT(ScriptA1MondayEn::a1c1o2());
            }
            static void a1_monday_in_the_nursery__menu_question_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 491));
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 492});
                answers.push_back(ks::answer_ptr{1, 493});
                answers.push_back(ks::answer_ptr{2, 494});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
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
                IF_NOT_EXIT(ScriptA1MondayEn::a1c2o1());
            }
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness() {
                IF_NOT_EXIT(ScriptA1MondayEn::a1c2o2());
            }
            static void a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know() {
                ks::progress.attraction_sc += 1;
                IF_NOT_EXIT(ScriptA1MondayEn::a1c2o3());
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
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 495));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 496));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 497));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 498));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 497));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 499));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 500));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 501));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 163));
            }
            static void a1_monday_enter_stage_left__condition_0_1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 502));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 503));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 504));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 505));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 506));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 507));
            }
            static void a1_monday_enter_stage_left__condition_1_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 508));
            }
            static void a1_monday_enter_stage_left__condition_1_1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 509));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 510));
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 511));
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