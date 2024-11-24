#ifndef KS_SCRIPT_A0_TEST
#define KS_SCRIPT_A0_TEST

#include "../sequence/assignmentitem.h"
#include "../sequence/backgrounditem.h"
#include "../sequence/dialogitem.h"
#include "../sequence/menuitem.h"
#include "../sequence/musicitem.h"
#include "../sequence/runlabelfinishitem.h"
#include "../sequence/runlabelitem.h"
#include "../sequence/spriteitem.h"
#include "../scenemanager.h"
#include "bn_music_items.h"
#include "bn_regular_bg_items_op_snowywoods.h"
namespace ks {
    class ScriptA0Test {
        public:
            virtual ~ScriptA0Test() = default;
            // Labels
            static void a0_actname_scene1();
            static void a0_actname();
            static void a0e1(ks::SceneManager& scene);
            // Choice functions
            // Conditions
            static void a0_actname_scene1__condition_0_0(ks::SceneManager& scene);
            static void a0_actname_scene1__condition_0_1(ks::SceneManager& scene);
    };
}

#endif // KS_SCRIPT_A0_TEST