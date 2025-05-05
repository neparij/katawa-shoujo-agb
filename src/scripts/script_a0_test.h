#ifndef KS_SCRIPT_A0_TEST
#define KS_SCRIPT_A0_TEST

#define SCENE_INLINE static inline __attribute__((always_inline))
#include "../scenemanager.h"
#include "../character.h"
#include "background_metas/op_snowywoods.h"
namespace ks {
    class ScriptA0Test {
        public:
            virtual ~ScriptA0Test() = default;
            // Labels
            SCENE_INLINE void a0_actname_scene1();
            static void a0_actname();
            SCENE_INLINE void a0e1();
            // Choice functions
            // Conditions
            SCENE_INLINE void a0_actname_scene1__condition_0_0();
            SCENE_INLINE void a0_actname_scene1__condition_0_1();
    };
}

#endif // KS_SCRIPT_A0_TEST