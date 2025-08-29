#include "script_a1_monday.h"
#include "tl_index/script_a1_monday_5906962E_ru_tl_index.h"
#include "tl_index/script_a1_monday_8A5E92DC_ru_tl_index.h"
#include "tl_index/script_a1_monday_1AE3BA25_ru_tl_index.h"
#include "tl_index/script_a1_monday_70DD5068_ru_tl_index.h"
#include "tl_index/script_a1_monday_BC7A1E75_ru_tl_index.h"
#include "tl_index/script_a1_monday_C1236A43_ru_tl_index.h"
#include "tl_index/script_a1_monday_EED1D0B9_ru_tl_index.h"
#include "tl_index/script_a1_monday_EED1D0BA_ru_tl_index.h"
#include "tl_index/script_a1_monday_EED1D47A_ru_tl_index.h"
#include "tl_index/script_a1_monday_EED1D47B_ru_tl_index.h"
#include "tl_index/script_a1_monday_EED1D47C_ru_tl_index.h"
namespace ks {
    class ScriptA1MondayRu : public ScriptA1Monday {
        public:
            SCENE_INLINE void a1_monday_out_cold() {
                ks::SceneManager::set_label(LABEL_A1_MONDAY_OUT_COLD);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("5906962E", tl_5906962E_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::op_snowywoods, 0, 0, SCENE_TRANSITION_NONE, 60, PALETTE_VARIANT_DEFAULT));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_SERENE, 120));
                ks::SceneManager::set_line_hash(0x0B6F83DB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0xFD63DE25);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0xB286D292);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0x76A58408);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0x4D5FFF6E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 4));
                ks::SceneManager::set_line_hash(0xD527162E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                ks::SceneManager::set_line_hash(0x6EBA5CCA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0xF20AF46C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0x7AFBD48D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x65BD8837);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_rustling.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0xB4F63A41);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0xD2C1A963);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mystery, 11));
                ks::SceneManager::set_line_hash(0x3ACEBC4C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0xBFCFC877);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 13));
                ks::SceneManager::set_line_hash(0x3E4116EF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                ks::SceneManager::set_line_hash(0xBEFE80F4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0x0AC9874F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::other_iwanako, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0E4B01F5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 17));
                ks::SceneManager::set_line_hash(0xB47D2DA9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                ks::SceneManager::set_line_hash(0xDEBBD580);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                ks::SceneManager::set_line_hash(0x4AB5B04C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 20));
                ks::SceneManager::set_line_hash(0xF1F8C126);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 21));
                IF_NOT_EXIT(ks::SceneManager::music_stop(600));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::op_snowywoods, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(42));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCC98ED33);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 22));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::other_iwanako, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x543C3CD0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 23));
                ks::SceneManager::set_line_hash(0xD61543CB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 24));
                ks::SceneManager::set_line_hash(0xE4D6432D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                ks::SceneManager::set_line_hash(0x4238F0E6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                ks::SceneManager::set_line_hash(0x367938CE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 27));
                ks::SceneManager::set_line_hash(0xB5822DC3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 28));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::op_snowywoods, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                // TODO: Show snow
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB2A508C7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 29));
                ks::SceneManager::set_line_hash(0x73F72CE5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 30));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x02127230);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 31));
                IF_NOT_EXIT(ks::SceneManager::music_stop(30));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(42));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x018CC0D8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 32));
                ks::SceneManager::set_line_hash(0x4AD3C7E8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                ks::SceneManager::set_line_hash(0x4BD6FD5C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 34));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_TRAGIC, 3));
                ks::SceneManager::set_line_hash(0xAE0AC559);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 35));
                ks::SceneManager::set_line_hash(0xDD13369E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                ks::SceneManager::set_line_hash(0xCBF7B0BF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 37));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD0B07492);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 38));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(9));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartslow.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartfast.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // TODO: Hide heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(3));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_heartstop.8ad", SOUND_CHANNEL_SOUND));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(18));
                // TODO: Show heartattack
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA940C33B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Иванако", 39));
                ks::SceneManager::set_line_hash(0x76C6796B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 40));
                IF_NOT_EXIT(ks::SceneManager::set_background_transition(SCENE_TRANSITION_PASSOUTOP1));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x26FEA30A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 41));
                ks::SceneManager::set_line_hash(0xB592529E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 42));
                IF_NOT_EXIT(ks::SceneManager::pause(60));
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 0));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_out_cold__condition_0_0();
                } 
                
            
            }
            SCENE_INLINE void a1_monday_bundle_of_hisao() {
                ks::SceneManager::set_label(LABEL_A1_MONDAY_BUNDLE_OF_HISAO);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("8A5E92DC", tl_8A5E92DC_ru_intl));
                if (!ks::in_replay) {
                }
                ks::SceneManager::set_line_hash(0x82D891D9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::centered, 0));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::hosp_room, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                // TODO: Show sakura
                // TODO: Show hospitalmask
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                // renpy.music.set_volume(0.5, 0.0, channel="music"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_RAIN, 240));
                ks::SceneManager::set_line_hash(0x5569833D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 1));
                ks::SceneManager::set_line_hash(0xFAB9906A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 2));
                ks::SceneManager::set_line_hash(0xCE9D2DC6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 3));
                ks::SceneManager::set_line_hash(0x59F5B620);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 4));
                ks::SceneManager::set_line_hash(0x04B5AAE8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 5));
                ks::SceneManager::set_line_hash(0x442A6252);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 6));
                ks::SceneManager::set_line_hash(0x96955D3B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 7));
                ks::SceneManager::set_line_hash(0x144121D0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 8));
                ks::SceneManager::set_line_hash(0x79FC4659);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 9));
                ks::SceneManager::set_line_hash(0x98A560C7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 10));
                ks::SceneManager::set_line_hash(0x3D243EB3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 11));
                ks::SceneManager::set_line_hash(0xB06C3BF2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 12));
                ks::SceneManager::set_line_hash(0xB205B5F8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 13));
                ks::SceneManager::set_line_hash(0x129B5A2F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 14));
                ks::SceneManager::set_line_hash(0x9C7562A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 15));
                ks::SceneManager::set_line_hash(0xA6097B31);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 16));
                ks::SceneManager::set_line_hash(0x8E07FF0A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 17));
                ks::SceneManager::set_line_hash(0x2092B065);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 18));
                ks::SceneManager::set_line_hash(0x377C0756);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 19));
                ks::SceneManager::set_line_hash(0x4D0B600F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 20));
                ks::SceneManager::set_line_hash(0x5F3317FA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 21));
                ks::SceneManager::set_line_hash(0xF84D2FC1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 22));
                ks::SceneManager::set_line_hash(0x63697194);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 23));
                ks::SceneManager::set_line_hash(0xE47E5A39);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 24));
                ks::SceneManager::set_line_hash(0xA4B31530);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 25));
                ks::SceneManager::set_line_hash(0x47FB32F3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 26));
                ks::SceneManager::set_line_hash(0xCC946CC2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 27));
                ks::SceneManager::set_line_hash(0x2F578861);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 28));
                ks::SceneManager::set_line_hash(0x165D3B5F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 29));
                ks::SceneManager::set_line_hash(0xEE2B90B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 30));
                ks::SceneManager::set_line_hash(0x1ACBC172);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 31));
                ks::SceneManager::set_line_hash(0xCEC0E79A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 32));
                ks::SceneManager::set_line_hash(0xBA050408);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 33));
                ks::SceneManager::set_line_hash(0xBC3DD6FE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 34));
                ks::SceneManager::set_line_hash(0x68ADAC9C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 35));
                ks::SceneManager::set_line_hash(0xADFD7EC4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 36));
                ks::SceneManager::set_line_hash(0xD73E5E6A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 37));
                ks::SceneManager::set_line_hash(0x37E1ADFB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 38));
                ks::SceneManager::set_line_hash(0xAD8F7556);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 39));
                ks::SceneManager::set_line_hash(0xE268A02B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 40));
                ks::SceneManager::set_line_hash(0x16AD3B9C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::n, 41));
                // renpy.music.set_volume(1.0, 1.0, channel="music"); TODO: unknown assignment
                ks::SceneManager::set_line_hash(0xC12247CE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 42));
                ks::SceneManager::set_line_hash(0x0AF779DB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 43));
                ks::SceneManager::set_line_hash(0xEFBFC233);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 44));
                ks::SceneManager::set_line_hash(0x30B1AD55);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 45));
                ks::SceneManager::set_line_hash(0x8404C94B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 46));
                ks::SceneManager::set_line_hash(0x8FEDCA82);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 47));
                ks::SceneManager::set_line_hash(0x1B94D1E3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 48));
                ks::SceneManager::set_line_hash(0xC99BBE73);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 49));
                ks::SceneManager::set_line_hash(0xFFC85C55);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 50));
                ks::SceneManager::set_line_hash(0x503B9884);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 51));
                ks::SceneManager::set_line_hash(0x72C19BBA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 52));
                // renpy.music.set_volume(0.5, 2.0, channel="music"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_NONE, 60));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::WHITE));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_event(ks::background_metas::event_drugs_en, DrugsEvent(), SCENE_TRANSITION_NONE, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x272846F9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 53));
                ks::SceneManager::set_line_hash(0x8B441B83);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 54));
                ks::SceneManager::set_line_hash(0xB55DDCD7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 55));
                ks::SceneManager::set_line_hash(0xD15FD16D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 56));
                ks::SceneManager::set_line_hash(0x13708DD4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 57));
                ks::SceneManager::set_line_hash(0xFAFA4E1F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 58));
                // renpy.music.set_volume(1.0, 1.0, channel="music"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::hosp_room, 0, 0, SCENE_TRANSITION_NONE, 30, PALETTE_VARIANT_DEFAULT));
                // TODO: Show sakura
                // TODO: Show hospitalmask
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x704D4BA1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 59));
                ks::SceneManager::set_line_hash(0xAA7281B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 60));
                ks::SceneManager::set_line_hash(0x68A8D7DC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 61));
                ks::SceneManager::set_line_hash(0x814483F2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 62));
                ks::SceneManager::set_line_hash(0x42B4286F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 63));
                ks::SceneManager::set_line_hash(0x4E1C2CB1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 64));
                ks::SceneManager::set_line_hash(0x053E2BA1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 65));
                ks::SceneManager::set_line_hash(0x421D7FEA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 66));
                ks::SceneManager::set_line_hash(0xD5295D08);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 67));
                ks::SceneManager::set_line_hash(0x564CFF15);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 68));
                ks::SceneManager::set_line_hash(0xA9D2BCBC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 69));
                ks::SceneManager::set_line_hash(0xA0159EF7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 70));
                ks::SceneManager::set_line_hash(0x760E68C2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 71));
                ks::SceneManager::set_line_hash(0x538F99D6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 72));
                ks::SceneManager::set_line_hash(0x92041095);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 73));
                ks::SceneManager::set_line_hash(0x37EC8812);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 74));
                ks::SceneManager::set_line_hash(0x2460DAB9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 75));
                ks::SceneManager::set_line_hash(0x3C9F3B03);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 76));
                ks::SceneManager::set_line_hash(0x866CAF3B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 77));
                ks::SceneManager::set_line_hash(0x9C8703A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 78));
                ks::SceneManager::set_line_hash(0x7238810D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 79));
                ks::SceneManager::set_line_hash(0x1029D197);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 80));
                ks::SceneManager::set_line_hash(0xD974DB21);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 81));
                ks::SceneManager::set_line_hash(0x110D280C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 82));
                ks::SceneManager::set_line_hash(0xA0C2293B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 83));
                ks::SceneManager::set_line_hash(0x333384A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 84));
                ks::SceneManager::set_line_hash(0x753FF5CE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Отец", 85));
                ks::SceneManager::set_line_hash(0x3506CC45);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 86));
                ks::SceneManager::set_line_hash(0xF1A04EFC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("Доктор", 87));
                ks::SceneManager::set_line_hash(0x24F0BF5E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 88));
                ks::SceneManager::set_line_hash(0x3ED2FCBA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 89));
                IF_NOT_EXIT(ks::SceneManager::music_stop(600));
                ks::SceneManager::set_line_hash(0xE6B5ECBE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 90));
                ks::SceneManager::set_line_hash(0xE24A9E86);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 91));
                ks::SceneManager::set_line_hash(0x438BDD92);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 92));
                ks::SceneManager::set_line_hash(0x129EA6C7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 93));
                ks::SceneManager::set_line_hash(0x81C77E2A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 94));
                ks::SceneManager::set_line_hash(0xD74D91FF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 95));
                ks::SceneManager::set_line_hash(0xFDB7B309);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 96));
                ks::SceneManager::set_line_hash(0x80F0B4CB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 97));
                ks::SceneManager::set_line_hash(0x01DE955B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 98));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_bundle_of_hisao__condition_0_0();
                } 
                
            
            }
            SCENE_INLINE void a1_monday_gateway_effect() {
                ks::SceneManager::set_label(LABEL_A1_MONDAY_GATEWAY_EFFECT);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("1AE3BA25", tl_1AE3BA25_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_gate, 0, 0, SCENE_TRANSITION_NONE, 90, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_HAPPINESS));
                ks::SceneManager::set_line_hash(0x08231EF4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0xE4214078);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0x61B9F4ED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0x3C25A591);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0x1F48F3CA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x3F4B936F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_courtyard, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x564003B7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0x65BB27C7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0xAD075B06);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x3E7891AA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0xF9F51506);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0x7F78A6AA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                ks::SceneManager::set_line_hash(0x37546F62);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0xC1D10CDA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 13));
                ks::SceneManager::set_line_hash(0x69B94A0E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                ks::SceneManager::set_line_hash(0x0A96CE20);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0xC5932A27);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                ks::SceneManager::set_line_hash(0x3D7320F8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                ks::SceneManager::set_line_hash(0xF6C75F79);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                ks::SceneManager::set_line_hash(0x09C027BB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                ks::SceneManager::set_line_hash(0x7CCBB01D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 20));
                ks::SceneManager::set_line_hash(0x9531D121);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 21));
                ks::SceneManager::set_line_hash(0xE2C011CB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 22));
                ks::SceneManager::set_line_hash(0x3EE49EA3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 23));
                ks::SceneManager::set_line_hash(0x12ABC058);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 24));
                ks::SceneManager::set_line_hash(0x08FCD1F5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_lobby, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xAACE2703);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x972564B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu_, 27));
                ks::SceneManager::set_line_hash(0x00D36002);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 28));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC5DE30F4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu_, 29));
                ks::SceneManager::set_line_hash(0x98F0AD86);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 30));
                ks::SceneManager::set_line_hash(0x70C1D92C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 31));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_irritated, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1A0945A9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 32));
                ks::SceneManager::set_line_hash(0x8DE878A9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 33));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3CC1F71C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 34));
                ks::SceneManager::set_line_hash(0x2DE8F194);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 35));
                ks::SceneManager::set_line_hash(0x4368A12E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                ks::SceneManager::set_line_hash(0xDF2F7F4C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 37));
                ScriptA1MondayRu::a1_monday_gateway_effect__menu_question_0();
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_staircase2, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC52F51E8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 38));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x88D1B7F7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 39));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_dooropen.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0x2CBD7FCF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 40));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MUTO, -24, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(30));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_MUTO));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1F2150DE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 41));
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                ks::SceneManager::set_line_hash(0xB72BD9B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 42));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_gateway_effect__condition_0_0();
                } 
                
            
            }
            SCENE_INLINE void a1_monday_enter_stage_left() {
                ks::SceneManager::set_label(LABEL_A1_MONDAY_ENTER_STAGE_LEFT);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("70DD5068", tl_70DD5068_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_NONE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4684CF7F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                IF_NOT_EXIT(ks::SceneManager::set_event(ks::background_metas::hisao_class, HisaoClassStartEvent(), SCENE_TRANSITION_NONE, 30));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_NORMAL, 30));
                ks::SceneManager::set_line_hash(0xD9D9837A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0x47918B22);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0x3C25B6CA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0x602DE8BF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x93855C30);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                IF_NOT_EXIT(ks::SceneManager::set_event(ks::background_metas::hisao_class, HisaoClassMoveEvent(), SCENE_TRANSITION_NONE, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFA79A4E1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0xEB34BB96);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0x1892D33A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                ks::SceneManager::set_line_hash(0x0FD0020D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0x9CA5B5D7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0x02492EA5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                ks::SceneManager::set_line_hash(0xE19A31E6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 12));
                ks::SceneManager::set_line_hash(0x9AC368BC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 13));
                if (ks::progress.wanted_introduce || ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_0_0();
                } 
                else {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_0_1();
                } 
                
            
                IF_NOT_EXIT(ks::SceneManager::set_event(ks::background_metas::hisao_class, HisaoClassEndEvent(), SCENE_TRANSITION_NONE, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF7F0FC67);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                ks::SceneManager::set_line_hash(0x1A7D5ACB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0x516F23EA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                ks::SceneManager::set_line_hash(0x18B17892);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, -8, 0, SCENE_TRANSITION_NONE, 30, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_normal, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE0C80222);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 18));
                ks::SceneManager::set_line_hash(0x8B8C1B9B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 19));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MUTO, ks::sprite_metas::muto_basic, bn::regular_bg_items::muto_bg_basic, bn::sprite_items::muto_spr_basic_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5B2EFC8B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 20));
                ks::SceneManager::set_line_hash(0xB2730054);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 21));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_MUTO));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8D223F85);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 22));
                ks::SceneManager::set_line_hash(0xE7348B9F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 23));
                ks::SceneManager::set_line_hash(0x7F96E28E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 24));
                ks::SceneManager::set_line_hash(0x50146E2E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 25));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE53809B5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                ks::SceneManager::set_line_hash(0xF161F5E8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 27));
                IF_NOT_EXIT(ks::SceneManager::music_stop(60));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_cross, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x12B8FA62);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi_shi, 28));
                ks::SceneManager::set_line_hash(0xDED04274);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 29));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA63CC9B7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi_shi, 30));
                ks::SceneManager::set_line_hash(0x1E2E70FC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi_not_shi, 31));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_SHIZUNE, 60));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_MISHA, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::set_background_position(0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, PALETTE_VARIANT_DEFAULT, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1FD8FEE0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 32));
                ks::SceneManager::set_line_hash(0x164C5BF8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                ks::SceneManager::set_line_hash(0x936EFE67);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 34));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6B3EB9C8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 35));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDEA76D3C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8354293B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 37));
                ks::SceneManager::set_line_hash(0x2870816E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 38));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3FC67079);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 39));
                ks::SceneManager::set_line_hash(0x316E1B76);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 40));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x933EE056);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 41));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8FBDF9AC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 42));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6DFA9DD7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 43));
                if (ks::progress.wanted_introduce || ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_1_0();
                } 
                else {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_1_1();
                } 
                
            
                ks::SceneManager::set_line_hash(0x5290B138);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 44));
                ks::SceneManager::set_line_hash(0xFE8C3CDE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 45));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x65D609BB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 46));
                ks::SceneManager::set_line_hash(0x3D1D87AA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 47));
                ks::SceneManager::set_line_hash(0x36006641);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 48));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_cross, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2145CD10);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 49));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_smug, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x21E734A8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 50));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_cross, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1D314D4A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 51));
                ks::SceneManager::set_line_hash(0x5BE0408B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 52));
                ks::SceneManager::set_line_hash(0xBC8F1B2D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 53));
                ks::SceneManager::set_line_hash(0xB6D575AE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 54));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xB99AD216);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 55));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8563DB0B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 56));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8BB13870);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 57));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1EBE0C37);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 58));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x51C022E4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 59));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC806CA80);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::extend, 60));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1E544B61);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::extend, 61));
                ks::SceneManager::set_line_hash(0x399C7647);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 62));
                ks::SceneManager::set_line_hash(0x14C64B56);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 63));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1A3FC900);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 64));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x57D151DF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 65));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCDA848D0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 66));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x00670BC9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 67));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDDBEBF85);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 68));
                ks::SceneManager::set_line_hash(0x3CDE2DF6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 69));
                ks::SceneManager::set_line_hash(0xAA0A1F4D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 70));
                ks::SceneManager::set_line_hash(0x44B38A1E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 71));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_sad, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3E7716BC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 72));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8F8D8169);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 73));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDA959F53);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 74));
                ks::SceneManager::set_line_hash(0xC1261569);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 75));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_cross, bn::regular_bg_items::misha_bg_cross, bn::sprite_items::misha_spr_cross_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8A0DC78B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 76));
                ks::SceneManager::set_line_hash(0x76F8E5E2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 77));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x80D14997);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 78));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1BCAEB54);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 79));
                IF_NOT_EXIT(ks::SceneManager::music_stop(30));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_adjust, bn::regular_bg_items::shizu_bg_adjust, bn::sprite_items::shizu_spr_adjust_blush, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC648D010);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 80));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4C53ECA8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 81));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFB7C2DF4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 82));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_SHIZUNE, 300));
                ks::SceneManager::set_line_hash(0x56A06173);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 83));
                ks::SceneManager::set_line_hash(0x2CED39C5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 84));
                ks::SceneManager::set_line_hash(0x52D69739);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 85));
                ks::SceneManager::set_line_hash(0xA51E4C4A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 86));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4D8B2D54);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 87));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_confused, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xD50E24D2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 88));
                ks::SceneManager::set_line_hash(0x1D0F4264);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 89));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_laugh, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCF6832F0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 90));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x147F9553);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 91));
                ks::SceneManager::set_line_hash(0xDDE86000);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 92));
                ks::SceneManager::set_line_hash(0x852F4695);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 93));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFA112969);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 94));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x919991EF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 95));
                ks::SceneManager::set_line_hash(0xBCFAA2AB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 96));
                IF_NOT_EXIT(ks::SceneManager::music_stop(360));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x45E228E0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 97));
                ks::SceneManager::set_line_hash(0x92F285F1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 98));
                ks::SceneManager::set_line_hash(0x9AC6A13D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 99));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_normalbell.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0x224C7D77);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 100));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4953934B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 101));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_enter_stage_left__condition_2_0();
                } 
                
            
            }
            SCENE_INLINE void a1_monday_in_the_nursery() {
                ks::SceneManager::set_label(LABEL_A1_MONDAY_IN_THE_NURSERY);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("BC7A1E75", tl_BC7A1E75_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_staircase2, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3B4A144F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_crowd_indoors.8ad", SOUND_CHANNEL_AMBIENT, 360));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_cafeteria, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA1720942);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0xF3FB6F52);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_EASE));
                ks::SceneManager::set_line_hash(0x7555C5A7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 3));
                ks::SceneManager::set_line_hash(0x45D47B21);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_MISHA));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0FE332B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                ks::SceneManager::set_line_hash(0x8D78BB32);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0xC72D87CB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_frown, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal, PALETTE_VARIANT_DEFAULT, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0EFBA1E6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_frown, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE99B7D63);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 9));
                ks::SceneManager::set_line_hash(0x9163B238);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                ks::SceneManager::set_line_hash(0xA94F40B3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4E83038A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 12));
                ks::SceneManager::set_line_hash(0x1F48C0AB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 13));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBDD179A0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 14));
                ScriptA1MondayRu::a1_monday_in_the_nursery__menu_question_0();
                ks::SceneManager::set_line_hash(0x9E3841FA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0x81B28674);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                ks::SceneManager::set_line_hash(0x576067B2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                IF_NOT_EXIT(ks::SceneManager::music_stop(180));
                // renpy.music.set_volume(1.0, .5, channel="ambient"); TODO: unknown assignment
                IF_NOT_EXIT(ks::SceneManager::sfx_stop(SOUND_CHANNEL_AMBIENT, 180));
                ks::SceneManager::set_line_hash(0x3FCF1624);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_DAILY, 30));
                ks::SceneManager::set_line_hash(0xE0D2CAA9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_HANAKO, ks::sprite_metas::hanako_emb, bn::regular_bg_items::hanako_bg_emb, bn::sprite_items::hanako_spr_emb_downtimid, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_HANAKO, 82, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF014E926);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 20));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_HANAKO, ks::sprite_metas::hanako_defarms, bn::regular_bg_items::hanako_bg_defarms, bn::sprite_items::hanako_spr_defarms_shock, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_HANAKO, 108, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8E76C608);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 21));
                ks::SceneManager::set_line_hash(0x3717EA74);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 22));
                ks::SceneManager::set_line_hash(0xFD35171E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 23));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_HANAKO, 184, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_HANAKO));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xF18CF595);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 24));
                ks::SceneManager::set_line_hash(0x7721506A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                ks::SceneManager::set_line_hash(0xC43574DE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 26));
                ks::SceneManager::set_line_hash(0x4CCD40ED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 27));
                ks::SceneManager::set_line_hash(0x577720DB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 28));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_scienceroom, 0, 0, SCENE_TRANSITION_SHORTTIMESKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_normalbell.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0x98EE52A9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 29));
                ks::SceneManager::set_line_hash(0x69B5D40F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 30));
                ks::SceneManager::set_line_hash(0xAFC7CF80);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 31));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_blank, PALETTE_VARIANT_DEFAULT, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x2AC030D4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 32));
                ks::SceneManager::set_line_hash(0x6017FA73);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 33));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_basic, bn::regular_bg_items::shizu_bg_basic, bn::sprite_items::shizu_spr_basic_normal2, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x6F002A43);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 34));
                ks::SceneManager::set_line_hash(0xD756B9B6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 35));
                ks::SceneManager::set_line_hash(0x0CE85801);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 36));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x28550AC3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 37));
                ks::SceneManager::set_line_hash(0xCE66E236);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 38));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_SHIZU));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_MISHA));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_hallway3, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x114167BC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 39));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_courtyard, 0, 0, SCENE_TRANSITION_LOCATIONSKIP, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x8ECFD6B4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 40));
                ks::SceneManager::set_line_hash(0xA78DEDC9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 41));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT, 48, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_perky, bn::regular_bg_items::misha_bg_perky, bn::sprite_items::misha_spr_perky_smile, PALETTE_VARIANT_DEFAULT, -48, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0705C2D1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 42));
                ks::SceneManager::set_line_hash(0x422B727D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 43));
                ks::SceneManager::set_line_hash(0xEC1E88DF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 44));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_frustrated, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x5FB4FE87);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::shi, 45));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x14B5CF11);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 46));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x535DB478);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 47));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xE532284F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 48));
                ks::SceneManager::set_line_hash(0x56BC1E7A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 49));
                IF_NOT_EXIT(ks::SceneManager::music_stop(300));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_SHIZU));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_MISHA));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4F40B0C6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 50));
                ks::SceneManager::set_line_hash(0x5675899C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 51));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_nursehall, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x54076C12);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 52));
                ks::SceneManager::set_line_hash(0x71CE9464);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 53));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_doorknock2.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0xFB8E5519);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 54));
                ks::SceneManager::set_line_hash(0x7C9F2C94);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 55));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_dooropen.8ad", SOUND_CHANNEL_SOUND));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_nurseoffice, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xAE871971);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 56));
                ks::SceneManager::set_line_hash(0x8B999EB9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 57));
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_NURSE, 30));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x1CD7207A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk_, 58));
                ks::SceneManager::set_line_hash(0x83D2A5A1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 59));
                ks::SceneManager::set_line_hash(0x2CA77CB1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 60));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDC747DC3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 61));
                ks::SceneManager::set_line_hash(0x3A510824);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk_, 62));
                ks::SceneManager::set_line_hash(0xD4280452);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk_, 63));
                ks::SceneManager::set_line_hash(0xFE877C04);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 64));
                ks::SceneManager::set_line_hash(0x933C0610);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 65));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_snap.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0x8909D66E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 66));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBE403C4C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 67));
                ks::SceneManager::set_line_hash(0x523BCC66);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 68));
                ks::SceneManager::set_line_hash(0x75A0AA49);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 69));
                ks::SceneManager::set_line_hash(0x818F3626);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 70));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x4926EE5A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 71));
                ks::SceneManager::set_line_hash(0x19F18F3B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 72));
                ks::SceneManager::set_line_hash(0x87A9C4F1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 73));
                ks::SceneManager::set_line_hash(0xBC9D71AC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 74));
                ks::SceneManager::set_line_hash(0xC7E160DD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 75));
                ks::SceneManager::set_line_hash(0x579D523F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 76));
                ks::SceneManager::set_line_hash(0x9365BC66);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 77));
                ks::SceneManager::set_line_hash(0x87FA65B1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 78));
                ks::SceneManager::set_line_hash(0xA0882011);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 79));
                ks::SceneManager::set_line_hash(0x0F695305);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 80));
                ks::SceneManager::set_line_hash(0xD36387EE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 81));
                ks::SceneManager::set_line_hash(0x860A7F6F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 82));
                ks::SceneManager::set_line_hash(0xEF22DEE1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 83));
                ks::SceneManager::set_line_hash(0xB30B04DE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 84));
                ks::SceneManager::set_line_hash(0xFD6E1D03);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 85));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBE0700DD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 86));
                ks::SceneManager::set_line_hash(0x294AE9B0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 87));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_fabulous, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xC29986B7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 88));
                ks::SceneManager::set_line_hash(0x3B01E6DF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 89));
                ks::SceneManager::set_line_hash(0x01CEA08E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 90));
                ks::SceneManager::set_line_hash(0x7251C5EF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 91));
                ks::SceneManager::set_line_hash(0x89C9EE29);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 92));
                ks::SceneManager::set_line_hash(0x51EA444B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 93));
                ks::SceneManager::set_line_hash(0x6B031DC9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 94));
                ks::SceneManager::set_line_hash(0xD489685A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 95));
                ks::SceneManager::set_line_hash(0xBC783711);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 96));
                ks::SceneManager::set_line_hash(0x833DE3CE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 97));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x03D0DFE8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 98));
                ks::SceneManager::set_line_hash(0x5CCD8B5C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 99));
                ks::SceneManager::set_line_hash(0xF8C2AC72);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 100));
                ks::SceneManager::set_line_hash(0x1BF59A6C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 101));
                ks::SceneManager::set_line_hash(0xDA0495E3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 102));
                ks::SceneManager::set_line_hash(0x03FD00E6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 103));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x599A1B78);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 104));
                ks::SceneManager::set_line_hash(0x7C03F747);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 105));
                ks::SceneManager::set_line_hash(0xAA80204E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 106));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_concern, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3646AD53);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 107));
                ks::SceneManager::set_line_hash(0xB2CACD96);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 108));
                ks::SceneManager::set_line_hash(0xF031814F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 109));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_NURSE, ks::sprite_metas::nurse, bn::regular_bg_items::nurse_bg, bn::sprite_items::nurse_spr_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA386B978);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::nk, 110));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_nursehall, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(120));
                ks::SceneManager::set_line_hash(0x6F7F9290);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 111));
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_in_the_nursery__condition_0_0();
                } 
                
            
            }
            SCENE_INLINE void a1_monday_nobodys_room() {
                ks::SceneManager::set_label(LABEL_A1_MONDAY_NOBODYS_ROOM);
                IF_NOT_EXIT(ks::SceneManager::set_textdb("C1236A43", tl_C1236A43_ru_intl));
                if (!ks::in_replay) {
                }
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_courtyard, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_PEARLY, 240));
                ks::SceneManager::set_line_hash(0x866AD60B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x5218CAA5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0x6C877141);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0x47B038F1);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                ks::SceneManager::set_line_hash(0x084DCFAD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x4C066EBA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                ks::SceneManager::set_line_hash(0xA44A3F03);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 6));
                ks::SceneManager::set_line_hash(0x19AD8544);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 7));
                ks::SceneManager::set_line_hash(0x60003037);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 8));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_gardens, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xDFFD3265);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 9));
                ks::SceneManager::set_line_hash(0xC2C36D75);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 10));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormext_start, 8, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBF4DDEB4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 11));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhallground, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x836A3FFC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 12));
                ks::SceneManager::set_line_hash(0x12DF1DB8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 13));
                ks::SceneManager::set_line_hash(0x8E22371F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 14));
                ks::SceneManager::set_line_hash(0x4D920B63);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 15));
                ks::SceneManager::set_line_hash(0xAD55096E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 16));
                ks::SceneManager::set_line_hash(0x1CF9EC2E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 17));
                ks::SceneManager::set_line_hash(0xA273C1DE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 18));
                ks::SceneManager::set_line_hash(0xBDAD0D85);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 19));
                ks::SceneManager::set_line_hash(0xEE9A4025);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 20));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhallway, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0A69AEC4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 21));
                ks::SceneManager::set_line_hash(0x47AD45B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 22));
                ks::SceneManager::set_line_hash(0xCF9594BB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 23));
                ks::SceneManager::set_line_hash(0xEE68F4FD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 24));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_doorknock2.8ad", SOUND_CHANNEL_SOUND));
                IF_NOT_EXIT(ks::SceneManager::music_stop(180));
                ks::SceneManager::set_line_hash(0xCDC0C7ED);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 25));
                ks::SceneManager::set_line_hash(0x24CAE167);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 26));
                ks::SceneManager::set_line_hash(0xDA25C8FE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 27));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_KENJI, -24, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::set_character_position(CHARACTER_KENJI, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_KENJI, 30));
                ks::SceneManager::set_line_hash(0x150F9DCE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 28));
                ks::SceneManager::set_line_hash(0xEC5ABB20);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke_, 29));
                ks::SceneManager::set_line_hash(0xABA401E3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 30));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xEF36789A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 31));
                ks::SceneManager::set_line_hash(0x47F8BE3E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 32));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xCC21992E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 33));
                ks::SceneManager::set_line_hash(0xE3821887);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke_, 34));
                ks::SceneManager::set_line_hash(0x13832AF6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 35));
                ks::SceneManager::set_line_hash(0xB17C4455);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 36));
                ks::SceneManager::set_line_hash(0xF867E31C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 37));
                ks::SceneManager::set_line_hash(0x671C3537);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 38));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x056F9133);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 39));
                ks::SceneManager::set_line_hash(0xB4CB5695);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 40));
                ks::SceneManager::set_line_hash(0xD9D31884);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 41));
                ks::SceneManager::set_line_hash(0x7F7AA68D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 42));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x55C96ACA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 43));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3044167A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 44));
                ks::SceneManager::set_line_hash(0xF64A6471);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 45));
                ks::SceneManager::set_line_hash(0x56CB0426);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 46));
                ks::SceneManager::set_line_hash(0x2FF89935);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 47));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3E19E6C4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 48));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_happy, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xBEDE7132);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 49));
                ks::SceneManager::set_line_hash(0xD2AD17DF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 50));
                ks::SceneManager::set_line_hash(0x83C7467B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 51));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_neutral, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x15833B76);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 52));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_KENJI, ks::sprite_metas::kenji_basic, bn::regular_bg_items::kenji_bg_basic, bn::sprite_items::kenji_spr_basic_tsun, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x0B782252);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::ke, 53));
                IF_NOT_EXIT(ks::SceneManager::hide_character(CHARACTER_KENJI));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_stop(180));
                ks::SceneManager::set_line_hash(0x9D00FD5B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 54));
                IF_NOT_EXIT(ks::SceneManager::sfx_play("sfx_doorslam.8ad", SOUND_CHANNEL_SOUND));
                ks::SceneManager::set_line_hash(0x4CC6A42A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::extend, 55));
                ks::SceneManager::set_line_hash(0x8E56A26D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 56));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhisao_ss, 0, 0, SCENE_TRANSITION_LOCATIONCHANGE, 0, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::music_play(MUSIC_NIGHT, 60));
                ks::SceneManager::set_line_hash(0x4962ED9F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 57));
                ks::SceneManager::set_line_hash(0x728289EE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 58));
                ks::SceneManager::set_line_hash(0xF6A556DD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 59));
                ks::SceneManager::set_line_hash(0x59277B93);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 60));
                ks::SceneManager::set_line_hash(0x2E7E9F0B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 61));
                ks::SceneManager::set_line_hash(0xD2ADC7B7);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 62));
                ks::SceneManager::set_line_hash(0x598AC28C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 63));
                ks::SceneManager::set_line_hash(0x62BFFC0C);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 64));
                ks::SceneManager::set_line_hash(0x8D41647B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 65));
                ks::SceneManager::set_line_hash(0xA03AA09A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 66));
                ks::SceneManager::set_line_hash(0xDB062106);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 67));
                ks::SceneManager::set_line_hash(0x4443ADF2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 68));
                ks::SceneManager::set_line_hash(0xD3EB3C0F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 69));
                ks::SceneManager::set_line_hash(0x3CB054A8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 70));
                ks::SceneManager::set_line_hash(0xD971D66E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 71));
                ks::SceneManager::set_line_hash(0x1979C06E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 72));
                ks::SceneManager::set_line_hash(0x61F4F090);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 73));
                ks::SceneManager::set_line_hash(0x9F47D660);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 74));
                ks::SceneManager::set_line_hash(0x0FBA4C01);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 75));
                // TODO: Show pills
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(60));
                // TODO: Show pills
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x882582A9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 76));
                ks::SceneManager::set_line_hash(0x317317AA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 77));
                // TODO: Show pills
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::pause(60));
                // TODO: Hide pills
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x3E92260D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 78));
                ks::SceneManager::set_line_hash(0x819E5F09);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 79));
                ks::SceneManager::set_line_hash(0xBDB1D72F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 80));
                ks::SceneManager::set_line_hash(0x8814BBCE);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 81));
                ks::SceneManager::set_line_hash(0x05C6DB27);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 82));
                IF_NOT_EXIT(ks::SceneManager::music_stop(480));
                IF_NOT_EXIT(ks::SceneManager::set_background(ks::background_metas::school_dormhisao_ni, 0, 0, SCENE_TRANSITION_NONE, 90, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x833F200A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 83));
                ks::SceneManager::set_line_hash(0x7C4F732A);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 84));
                ks::SceneManager::set_line_hash(0xAFB5CD08);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 85));
                ks::SceneManager::set_line_hash(0x5924CC34);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 86));
                ks::SceneManager::set_line_hash(0x3DF2E08B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 87));
                IF_NOT_EXIT(ks::SceneManager::hide_background(SCENE_TRANSITION_SHUTEYE, 0));
                IF_NOT_EXIT(ks::SceneManager::enable_fill(ks::globals::colors::BLACK));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                if (ks::in_replay) {
                    ScriptA1MondayRu::a1_monday_nobodys_room__condition_0_0();
                } 
                
            
            }
            static void a1_monday() {
                SKIP_IF_LOAD_ANOTHER_SCENE(SCRIPT_A1_MONDAY);
                ks::SceneManager::set_script(SCRIPT_A1_MONDAY);
                IF_NOT_EXIT(ks::SceneManager::init_savedata(ks::progress));
                IF_NOT_EXIT(ks::SceneManager::set(ks::SceneManager("script_a1_monday", "ru")));
            
                IF_NOT_EXIT(a1_monday_out_cold()); // INLINE CALL
                IF_NOT_EXIT(ks::SceneManager::show_video(video_op_1_dxtv, video_op_1_dxtv_size, "video_op_1.ulc"));
                IF_NOT_EXIT(ks::SceneManager::set(ks::SceneManager("script_a1_monday", "ru")));
                IF_NOT_EXIT(ks::SceneManager::pause(60));
                IF_NOT_EXIT(a1_monday_bundle_of_hisao()); // INLINE CALL
                IF_NOT_EXIT(ks::SceneManager::show_video(video_tc_act1_dxtv, video_tc_act1_dxtv_size, "video_tc_act1.ulc"));
                IF_NOT_EXIT(ks::SceneManager::set(ks::SceneManager("script_a1_monday", "ru")));
                IF_NOT_EXIT(a1_monday_gateway_effect()); // INLINE CALL
                IF_NOT_EXIT(a1_monday_enter_stage_left()); // INLINE CALL
                IF_NOT_EXIT(a1_monday_in_the_nursery()); // INLINE CALL
                IF_NOT_EXIT(a1_monday_nobodys_room()); // INLINE CALL
            }
            SCENE_INLINE void a1c1o1() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("EED1D0B9", tl_EED1D0B9_ru_intl));
                ks::SceneManager::set_line_hash(0xE972EDAF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                ks::SceneManager::set_line_hash(0x999B6BEA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 1));
                ks::SceneManager::set_line_hash(0x71594EB9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 2));
                ks::SceneManager::set_line_hash(0xDBEAFEAB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 3));
                return;
            }
            SCENE_INLINE void a1c1o2() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("EED1D0BA", tl_EED1D0BA_ru_intl));
                ks::SceneManager::set_line_hash(0x8721F138);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                ks::SceneManager::set_line_hash(0x4BD0847E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 1));
                ks::SceneManager::set_line_hash(0x542B47F8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0xAB3FFB4B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 3));
                ks::SceneManager::set_line_hash(0x0A2FEC02);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 4));
                return;
            }
            SCENE_INLINE void a1c2o1() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("EED1D47A", tl_EED1D47A_ru_intl));
                ks::SceneManager::set_line_hash(0x9E9B516F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                ks::SceneManager::set_line_hash(0xEBF9B663);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0x9F64ACE3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 2));
                ks::SceneManager::set_line_hash(0x00470B87);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 3));
                ks::SceneManager::set_line_hash(0x3B2317A8);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                return;
            }
            SCENE_INLINE void a1c2o2() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("EED1D47B", tl_EED1D47B_ru_intl));
                ks::SceneManager::set_line_hash(0xBB0549DB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 0));
                ks::SceneManager::set_line_hash(0x3D146CAB);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 1));
                ks::SceneManager::set_line_hash(0xB9890A49);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0x8169B227);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 3));
                return;
            }
            SCENE_INLINE void a1c2o3() {
                IF_NOT_EXIT(ks::SceneManager::set_textdb("EED1D47C", tl_EED1D47C_ru_intl));
                ks::SceneManager::set_line_hash(0xC705F743);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 0));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_sign, bn::regular_bg_items::misha_bg_sign, bn::sprite_items::misha_spr_sign_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0x317FDC49);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 1));
                ks::SceneManager::set_line_hash(0x189D10C0);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 2));
                ks::SceneManager::set_line_hash(0xE2BD16F4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 3));
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_MISHA, ks::sprite_metas::misha_hips, bn::regular_bg_items::misha_bg_hips, bn::sprite_items::misha_spr_hips_grin, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                IF_NOT_EXIT(ks::SceneManager::show_character(CHARACTER_SHIZU, ks::sprite_metas::shizu_behind, bn::regular_bg_items::shizu_bg_behind, bn::sprite_items::shizu_spr_behind_smile, PALETTE_VARIANT_DEFAULT));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xFBE3E6B9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 4));
                ks::SceneManager::set_line_hash(0x50411499);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 5));
                return;
            }
            SCENE_INLINE void a1_monday_gateway_effect__menu_question_0() {
                ks::SceneManager::set_line_hash(0x82D50908);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mu, 43));
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 44});
                answers.push_back(ks::answer_ptr{1, 45});
                IF_NOT_EXIT(ks::SceneManager::show_dialog_question(answers));
                int answer = ks::SceneManager::get_dialog_question_answer();
                if (answer == 0) {
                    ScriptA1MondayRu::a1_monday_gateway_effect__menu_question_0_why();
                } else if (answer == 1) {
                    ScriptA1MondayRu::a1_monday_gateway_effect__menu_question_0_yeah_of_course();
                }
            }
            SCENE_INLINE void a1_monday_gateway_effect__menu_question_0_why() {
                ks::progress.wanted_introduce = false;
                IF_NOT_EXIT(ScriptA1MondayRu::a1c1o1()); // DIRECT CALL
            }
            SCENE_INLINE void a1_monday_gateway_effect__menu_question_0_yeah_of_course() {
                ks::progress.wanted_introduce = true;
                ks::progress.attraction_sc += 1;
                IF_NOT_EXIT(ScriptA1MondayRu::a1c1o2()); // DIRECT CALL
            }
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0() {
                ks::SceneManager::set_line_hash(0xA3D43C88);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 112));
                bn::vector<ks::answer_ptr, 5> answers;
                answers.push_back(ks::answer_ptr{0, 113});
                answers.push_back(ks::answer_ptr{1, 114});
                answers.push_back(ks::answer_ptr{2, 115});
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
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0_ask_about_the_library() {
                ks::progress.attraction_hanako += 1;
                IF_NOT_EXIT(ScriptA1MondayRu::a1c2o1()); // DIRECT CALL
            }
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness() {
                IF_NOT_EXIT(ScriptA1MondayRu::a1c2o2()); // DIRECT CALL
            }
            SCENE_INLINE void a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know() {
                ks::progress.attraction_sc += 1;
                IF_NOT_EXIT(ScriptA1MondayRu::a1c2o3()); // DIRECT CALL
            }
            SCENE_INLINE void a1_monday_out_cold__condition_0_0() {
                return;
            }
            SCENE_INLINE void a1_monday_bundle_of_hisao__condition_0_0() {
                return;
            }
            SCENE_INLINE void a1_monday_gateway_effect__condition_0_0() {
                return;
            }
            SCENE_INLINE void a1_monday_enter_stage_left__condition_0_0() {
                ks::SceneManager::set_line_hash(0x2A67B6B2);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 102));
                ks::SceneManager::set_line_hash(0x6A5D1F08);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 103));
                ks::SceneManager::set_line_hash(0xD1F87CFF);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 104));
                ks::SceneManager::set_line_hash(0x1849A988);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::hi, 105));
                ks::SceneManager::set_line_hash(0x507D51E5);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 106));
                ks::SceneManager::set_line_hash(0x5664DBAD);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 107));
                ks::SceneManager::set_line_hash(0x901CB25D);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 108));
                ks::SceneManager::set_line_hash(0x3B7CA9A6);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 109));
                ks::SceneManager::set_line_hash(0x69B3C30F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 110));
            }
            SCENE_INLINE void a1_monday_enter_stage_left__condition_0_1() {
                ks::SceneManager::set_line_hash(0x7DA40CE3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 111));
                ks::SceneManager::set_line_hash(0xFC729482);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 112));
                ks::SceneManager::set_line_hash(0x7CE46117);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 113));
                ks::SceneManager::set_line_hash(0x28358836);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 114));
                ks::SceneManager::set_line_hash(0x353392C3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 115));
                ks::SceneManager::set_line_hash(0x16F0DD2E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 116));
            }
            SCENE_INLINE void a1_monday_enter_stage_left__condition_1_0() {
                ks::SceneManager::set_line_hash(0xB595DC99);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 117));
            }
            SCENE_INLINE void a1_monday_enter_stage_left__condition_1_1() {
                ks::SceneManager::set_line_hash(0x93AF4FFA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 118));
                ks::SceneManager::set_line_hash(0x88D7D418);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::mi, 119));
                ks::SceneManager::set_line_hash(0xE75FECB3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog(ks::definitions::no_char, 120));
            }
            SCENE_INLINE void a1_monday_enter_stage_left__condition_2_0() {
                return;
            }
            SCENE_INLINE void a1_monday_in_the_nursery__condition_0_0() {
                return;
            }
            SCENE_INLINE void a1_monday_nobodys_room__condition_0_0() {
                return;
            }
    };
}