#include "script_a0_test.h"
#include "script_a0_test_en_tl_index.h"
namespace ks {
    class ScriptA0TestEn : public ScriptA0Test {
        public:
            static void a0_actname_scene1() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods);
                ks::SceneManager::show_dialog("ao-s1", 0);
                ks::SceneManager::show_dialog("ao-s1", 1);
                ks::SceneManager::show_dialog("a0-s1", 2);
                ks::SceneManager::show_dialog("a0-s1", 3);
                ks::SceneManager::show_dialog("a0-s1", 4);
                ks::SceneManager::show_dialog("a0-s1", 5);
                ScriptA0TestEn::a0e1();
                if (ks::progress.attraction_sc > 1 || ks::in_replay) {
                    ScriptA0TestEn::a0_actname_scene1__condition_0_0();
                } 
                else {
                    ScriptA0TestEn::a0_actname_scene1__condition_0_1();
                } 
                
            
                ks::SceneManager::show_dialog("ao-s1", 6);
                ks::SceneManager::show_dialog("ao-s1", 7);
            }
            static void a0_actname() {
                ks::SceneManager::set(ks::SceneManager("script_a0_test", "en", script_a0_test_en_intl));
            
                a0_actname_scene1();
            }
            static void a0e1() {
                ks::SceneManager::show_dialog("a0e1", 8);
                ks::SceneManager::show_dialog("a0e1", 9);
                return;
            }
            static void a0_actname_scene1__condition_0_0() {
                ks::SceneManager::show_dialog("ao-s1-c1", 10);
                ks::SceneManager::show_dialog("ao-s1-c1", 11);
            }
            static void a0_actname_scene1__condition_0_1() {
                ks::SceneManager::show_dialog("ao-s1-c1", 12);
                ks::SceneManager::show_dialog("ao-s1-c1", 13);
            }
    };
}