#include "script_a0_test.h"
#include "script_a0_test_en_tl_index.h"
namespace ks {
    class ScriptA0TestEn : public ScriptA0Test {
        public:
            static void a0_actname_scene1() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_label(LABEL_A0_ACTNAME_SCENE1);
                IF_NOT_EXIT(ks::SceneManager::autosave());
                IF_NOT_EXIT(ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods, 0, 0, 0));
                IF_NOT_EXIT(ks::SceneManager::update_visuals());
                ks::SceneManager::set_line_hash(0xA9C688F3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1", 0));
                ks::SceneManager::set_line_hash(0xCFEF3618);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1", 1));
                ks::SceneManager::set_line_hash(0x1F77A4E4);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0-s1", 2));
                ks::SceneManager::set_line_hash(0xC8DDBA0B);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0-s1", 3));
                ks::SceneManager::set_line_hash(0xAE5AB71E);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0-s1", 4));
                ks::SceneManager::set_line_hash(0xE596A096);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0-s1", 5));
                IF_NOT_EXIT(ScriptA0TestEn::a0e1());
                if (ks::progress.attraction_sc > 1 || ks::in_replay) {
                    ScriptA0TestEn::a0_actname_scene1__condition_0_0();
                } 
                else {
                    ScriptA0TestEn::a0_actname_scene1__condition_0_1();
                } 
                
            
                ks::SceneManager::set_line_hash(0x3BB93AEC);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1", 6));
                ks::SceneManager::set_line_hash(0x255D2E73);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1", 7));
            }
            static void a0_actname() {
                ks::SceneManager::set_script(SCRIPT_A0_ACTNAME);
                IF_NOT_EXIT(ks::SceneManager::init_savedata(ks::progress));
                IF_NOT_EXIT(ks::SceneManager::set(ks::SceneManager("script_a0_test", "en", script_a0_test_en_intl)));
            
                IF_NOT_EXIT(a0_actname_scene1());
            }
            static void a0e1() {
                ks::SceneManager::set_line_hash(0x93E1BF7F);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0e1", 8));
                ks::SceneManager::set_line_hash(0xC5A5C4C9);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0e1", 9));
                return;
            }
            static void a0_actname_scene1__condition_0_0() {
                ks::SceneManager::set_line_hash(0x8DD85CF3);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1-c1", 10));
                ks::SceneManager::set_line_hash(0x06C8B385);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1-c1", 11));
            }
            static void a0_actname_scene1__condition_0_1() {
                ks::SceneManager::set_line_hash(0x6CC9BAEA);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1-c1", 12));
                ks::SceneManager::set_line_hash(0x55C98B34);
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1-c1", 13));
            }
    };
}