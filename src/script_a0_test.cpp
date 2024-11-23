#ifndef KS_SCRIPT_A0_TEST
#define KS_SCRIPT_A0_TEST

#include "sequence/assignmentitem.h"
#include "sequence/backgrounditem.h"
#include "sequence/dialogitem.h"
#include "sequence/menuitem.h"
#include "sequence/musicitem.h"
#include "sequence/runlabelfinishitem.h"
#include "sequence/runlabelitem.h"
#include "sequence/spriteitem.h"
#include "bn_music_items.h"
#include "scenemanager.h"
// Backgrounds
#include "bn_regular_bg_items_mainbg.h"

// Events

namespace
{
// Signatures
void scene__a0_actname__scene1();
void scene__a0_actname();
void scene__a0e1(ks::SceneManager& scene);

// Scenario - NOT USED

// Labels
void scene__a0_actname__scene1() {
    // POTENTIAL MEMLEAK!!!! better to provide it globally.
    bn::optional<bn::regular_bg_ptr> main_bg;
    ks::SceneManager scene(main_bg);

    scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::mainbg));
    scene.add_sequence(ks::DialogItem("", "ao-s1" "Dialog 1"));
    scene.add_sequence(ks::DialogItem("", "ao-s1" "Dialog 2"));
    scene.add_sequence(ks::RunLabelItem(&scene__a0e1));
        // bn::vector<ks::ConditionItem, 2> scene__a0_actname__scene1__condition_0;
        // scene__a0_actname__scene1__condition_0.push_back(ks::ConditionItem("variable_name_a or variable_name_b", &scene__a0_actname__scene1__condition_0_0));
        // scene__a0_actname__scene1__condition_0.push_back(ks::ConditionItem("None", &scene__a0_actname__scene1__condition_0_1));
        // scene.add_condition(scene__a0_actname__scene1__condition_0);
    scene.add_sequence(ks::DialogItem("", "ao-s1" "Dialog 3"));
    scene.add_sequence(ks::DialogItem("", "ao-s1" "Dialog 4"));
    scene.start();

    while (!scene.is_finished()) {
        scene.update();
        bn::core::update();
    }
}
void scene__a0_actname() {
    scene__a0_actname__scene1();
    bn::core::update();
}
void scene__a0e1(ks::SceneManager& scene) {
    scene.add_sequence(ks::DialogItem("a0e1", "Str 1"));
    scene.add_sequence(ks::DialogItem("a0e1", "Str 2"));
    return;
}

// Menu

// Conditions
void scene__a0_actname__scene1__condition_0_0(ks::SceneManager& scene) {
    scene.add_sequence(ks::DialogItem("", "ao-s1-c1" "Dialog A or B 1"));
    scene.add_sequence(ks::DialogItem("", "ao-s1-c1" "Dialog A or B 2"));
}
void scene__a0_actname__scene1__condition_0_1(ks::SceneManager& scene) {
    scene.add_sequence(ks::DialogItem("", "ao-s1-c1" "NOT Dialog A or B 1"));
    scene.add_sequence(ks::DialogItem("", "ao-s1-c1" "NOT Dialog A or B 2"));
}

}

#endif // KS_SCRIPT_A0_TEST
