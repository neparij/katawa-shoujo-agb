#include "script_a0_test.h"
#include "script_a0_test_en_tl_index.h"
namespace ks {
    class ScriptA0TestEn : public ScriptA0Test {
        public:
            static void a0_actname_scene1() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods, 0, 0, 0);
                ks::SceneManager::update_visuals();
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1", 0));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1", 1));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0-s1", 2));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0-s1", 3));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0-s1", 4));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0-s1", 5));
                IF_NOT_EXIT(ScriptA0TestEn::a0e1());
                if (ks::progress.attraction_sc > 1 || ks::in_replay) {
                    ScriptA0TestEn::a0_actname_scene1__condition_0_0();
                } 
                else {
                    ScriptA0TestEn::a0_actname_scene1__condition_0_1();
                } 
                
            
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1", 6));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1", 7));
            }
            static void a0_actname() {
                IF_NOT_EXIT(ks::SceneManager::set(ks::SceneManager("script_a0_test", "en", script_a0_test_en_intl)));
            
                IF_NOT_EXIT(a0_actname_scene1());
            }
            static void a0e1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0e1", 8));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("a0e1", 9));
                return;
            }
            static void a0_actname_scene1__condition_0_0() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1-c1", 10));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1-c1", 11));
            }
            static void a0_actname_scene1__condition_0_1() {
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1-c1", 12));
                IF_NOT_EXIT(ks::SceneManager::show_dialog("ao-s1-c1", 13));
            }
    };
}