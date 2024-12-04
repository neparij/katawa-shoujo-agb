#include "script_a0_test.h"
#include "script_a0_test_en_tl_index.h"
namespace ks {
    class ScriptA0TestEn : public ScriptA0Test {
        public:
            static void a0_actname_scene1() {
                // POTENTIAL MEMLEAK!!!! better to provide it globally.
                // bn::optional<bn::regular_bg_ptr> main_bg;
                constexpr ks::SceneManager scene = ks::SceneManager("script_a0_test", "en", script_a0_test_en_intl);
            
                ks::SceneManager::reset();
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods);
                ks::SceneManager::show_dialog(&scene, "ao-s1", 0);
                ks::SceneManager::show_dialog(&scene, "ao-s1", 1);
                ks::SceneManager::show_dialog(&scene, "a0-s1", 2);
                ks::SceneManager::show_dialog(&scene, "a0-s1", 3);
                ks::SceneManager::show_dialog(&scene, "a0-s1", 4);
                ks::SceneManager::show_dialog(&scene, "a0-s1", 5);
                ScriptA0TestEn::a0e1(scene);
                // bn::vector<ks::ConditionItem, 2> a0_actname_scene1__condition_0;
                // a0_actname_scene1__condition_0.push_back(ks::ConditionItem("variable_name_a or variable_name_b", &ScriptA0TestEn::a0_actname_scene1__condition_0_0));
                // a0_actname_scene1__condition_0.push_back(ks::ConditionItem("None", &ScriptA0TestEn::a0_actname_scene1__condition_0_1));
                // scene.add_condition(a0_actname_scene1__condition_0);
                ks::SceneManager::show_dialog(&scene, "ao-s1", 6);
                ks::SceneManager::show_dialog(&scene, "ao-s1", 7);
            }
            static void a0_actname() {
                a0_actname_scene1();
            }
            static void a0e1(const ks::SceneManager scene) {
                ks::SceneManager::show_dialog(&scene, "a0e1", 8);
                ks::SceneManager::show_dialog(&scene, "a0e1", 9);
                return;
            }
            static void a0_actname_scene1__condition_0_0(const ks::SceneManager scene) {
                ks::SceneManager::show_dialog(&scene, "ao-s1-c1", 10);
                ks::SceneManager::show_dialog(&scene, "ao-s1-c1", 11);
            }
            static void a0_actname_scene1__condition_0_1(const ks::SceneManager scene) {
                ks::SceneManager::show_dialog(&scene, "ao-s1-c1", 12);
                ks::SceneManager::show_dialog(&scene, "ao-s1-c1", 13);
            }
    };
}