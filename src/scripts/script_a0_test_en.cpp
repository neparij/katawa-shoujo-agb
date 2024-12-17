#include "bn_regular_bg_items_hanako_bg_def.h"
#include "bn_regular_bg_items_lilly_bg_cane.h"
#include "bn_regular_bg_items_rin_bg_basic.h"
#include "bn_regular_bg_items_yuuko_bg_up.h"
#include "bn_sprite_items_hanako_spr_def_shock.h"
#include "bn_sprite_items_lilly_spr_cane_weaksmile.h"
#include "bn_sprite_items_rin_spr_basic_delight.h"
#include "bn_sprite_items_yuuko_spr_up_worried.h"
#include "hanako_def.h"
#include "lilly_cane.h"
#include "rin_basic.h"
#include "script_a0_test.h"
#include "script_a0_test_en_tl_index.h"
#include "yuuko_up.h"
namespace ks {
    class ScriptA0TestEn : public ScriptA0Test {
        public:
            static void a0_actname_scene1() {
                ks::SceneManager::free_resources();
                ks::SceneManager::set_background(bn::regular_bg_items::op_snowywoods);
                ks::SceneManager::show_dialog("ao-s1", 0);
                ks::SceneManager::show_dialog("ao-s1", 1);
                ks::SceneManager::show_character(0, bn::regular_bg_items::hanako_bg_def, bn::sprite_items::hanako_spr_def_shock, ks::sprite_metas::hanako_def, -80, 0);
                ks::SceneManager::show_character(1, bn::regular_bg_items::yuuko_bg_up, bn::sprite_items::yuuko_spr_up_worried, ks::sprite_metas::yuuko_up, 80, 0);
                ks::SceneManager::show_dialog("a0-s1", 2);
                ks::SceneManager::show_character(2, bn::regular_bg_items::lilly_bg_cane, bn::sprite_items::lilly_spr_cane_weaksmile, ks::sprite_metas::lilly_cane, -40, 0);
                ks::SceneManager::show_dialog("a0-s1", 3);
                ks::SceneManager::show_character(3, bn::regular_bg_items::rin_bg_basic, bn::sprite_items::rin_spr_basic_delight, ks::sprite_metas::rin_basic, 40, 0);
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
