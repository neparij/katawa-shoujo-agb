#include "script_a0_test.h"
namespace ks {
    class ScriptA0TestEn : public ScriptA0Test {
        public:
            static void a0_actname_scene1() {
                // POTENTIAL MEMLEAK!!!! better to provide it globally.
                bn::optional<bn::regular_bg_ptr> main_bg;
                ks::SceneManager scene(main_bg);
            
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::op_snowywoods));
                scene.add_sequence(ks::DialogItem("", "ao-s1" "Dialog 1"));
                scene.add_sequence(ks::DialogItem("", "ao-s1" "Dialog 2"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA0TestEn::a0e1(scene);}));
                // bn::vector<ks::ConditionItem, 2> a0_actname_scene1__condition_0;
                // a0_actname_scene1__condition_0.push_back(ks::ConditionItem("variable_name_a or variable_name_b", &ScriptA0TestEn::a0_actname_scene1__condition_0_0));
                // a0_actname_scene1__condition_0.push_back(ks::ConditionItem("None", &ScriptA0TestEn::a0_actname_scene1__condition_0_1));
                // scene.add_condition(a0_actname_scene1__condition_0);
                scene.add_sequence(ks::DialogItem("", "ao-s1" "Dialog 3"));
                scene.add_sequence(ks::DialogItem("", "ao-s1" "Dialog 4"));
                scene.start();
            
                while(!scene.is_finished()) {
                    scene.update();
                    bn::core::update();
                }
            }
            static void a0_actname() {
                a0_actname_scene1();
                bn::core::update();
            }
            static void a0e1(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("a0e1", "Str 1"));
                scene.add_sequence(ks::DialogItem("a0e1", "Str 2"));
                return;
            }
            static void a0_actname_scene1__condition_0_0(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("", "ao-s1-c1" "Dialog A or B 1"));
                scene.add_sequence(ks::DialogItem("", "ao-s1-c1" "Dialog A or B 2"));
            }
            static void a0_actname_scene1__condition_0_1(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("", "ao-s1-c1" "NOT Dialog A or B 1"));
                scene.add_sequence(ks::DialogItem("", "ao-s1-c1" "NOT Dialog A or B 2"));
            }
    };
}