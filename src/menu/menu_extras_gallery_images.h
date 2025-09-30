#ifndef MENU_EXTRAS_GALLERY_IMAGES_H
#define MENU_EXTRAS_GALLERY_IMAGES_H

#include "bn_log.h"
#include "bn_regular_bg_item.h"
#include "background_meta.h"
#include "background_metas.h"
#include "custom_background_metas.h"
#include "../events/hanako_fireworks.cpp.h"
#include "../events/hisao_class_end.cpp.h"
#include "../events/hisao_class_move.cpp.h"
#include "../events/hisao_class_start.cpp.h"
#include "../events/other_iwanako.cpp.h"

#define GALLERY_IMAGE_ELEMENTS 7
#define GALLERY_CUSTOM_EVENTS_ELEMENTS 3
#define GALLERY_DISSOLVE_TIME 30

namespace ks::menu {
    struct gallery_image {
        const background_meta *thumbnail;
        void (*script)();
    };

    namespace gallery_script {
        static __attribute__((always_inline)) void prepare_scene_manager() {
            SceneManager::set(SceneManager("gallery"));
        }

        static __attribute__((always_inline)) void process() {
            SceneManager::update_visuals();
            while (!bn::keypad::a_pressed() && !bn::keypad::b_pressed()) {
                globals::main_update();
            }
        }

        static __attribute__((always_inline)) void show_bg(const background_meta& bg) {
            SceneManager::set_background(bg, 0, 0, SCENE_TRANSITION_NONE, GALLERY_DISSOLVE_TIME, PALETTE_VARIANT_DEFAULT);
        }

        static void other_iwanako() {
            prepare_scene_manager();
            SceneManager::set_event(background_metas::other_iwanako, OtherIwanakoEvent(), SCENE_TRANSITION_NONE, GALLERY_DISSOLVE_TIME);
            process();
        }

        static void hisao_class() {
            prepare_scene_manager();
            SceneManager::set_event(background_metas::hisao_class, HisaoClassStartEvent(), SCENE_TRANSITION_NONE, GALLERY_DISSOLVE_TIME);
            process();
            SceneManager::set_event(background_metas::hisao_class, HisaoClassMoveEvent(), SCENE_TRANSITION_NONE, 0);
            process();
            SceneManager::set_event(background_metas::hisao_class, HisaoClassEndEvent(), SCENE_TRANSITION_NONE, 0);
            process();
        }

        static void kenji_rooftop() {
            prepare_scene_manager();
            show_bg(background_metas::kenji_rooftop);
            process();
        }

        static void hisao_teacup() {
            prepare_scene_manager();
            show_bg(background_metas::hisao_teacup);
            process();
        }

        static void hisao_letter() {
            prepare_scene_manager();
            show_bg(background_metas::hisao_letter_closed);
            process();
            show_bg(background_metas::hisao_letter_open);
            process();
            show_bg(background_metas::hisao_letter_open_2);
            process();
        }

        static void akira_park() {
            prepare_scene_manager();
            show_bg(background_metas::akira_park);
            process();
        }

        static void emi_knockeddown() {
            prepare_scene_manager();
            show_bg(background_metas::emi_knockeddown);
            process();
        }

        static void emi_run_face() {
            prepare_scene_manager();
            show_bg(background_metas::emi_run_face);
            process();
        }

        static void emitrack_blocks() {
            prepare_scene_manager();
            show_bg(background_metas::emitrack_blocks);
            process();
            show_bg(background_metas::emitrack_blocks_close);
            process();
            show_bg(background_metas::emitrack_blocks_close_grin);
            process();
        }

        static void emitrack_running() {
            prepare_scene_manager();
            show_bg(background_metas::emitrack_running);
            process();
        }

        static void emitrack_finishtop() {
            prepare_scene_manager();
            show_bg(background_metas::emitrack_finishtop);
            process();
        }

        static void emitrack_finish() {
            prepare_scene_manager();
            show_bg(background_metas::emitrack_finish);
            process();
        }

        static void picnic() {
            prepare_scene_manager();
            show_bg(background_metas::picnic_normal);
            process();
            show_bg(background_metas::picnic_rain);
            process();
        }

        static void emi_sleep() {
            prepare_scene_manager();
            show_bg(background_metas::emi_sleep_unsure);
            process();
            show_bg(background_metas::emi_sleep_normal);
            process();
            show_bg(background_metas::emi_sleep_weep);
            process();
            show_bg(background_metas::emi_sleep_cry);
            process();
        }

        static void emi_sleepy() {
            prepare_scene_manager();
            show_bg(background_metas::emi_sleepy);
            process();
            show_bg(background_metas::emi_sleepy_face);
            process();
            show_bg(background_metas::emi_sleepy_legs);
            process();
        }

        static void emi_firstkiss() {
            prepare_scene_manager();
            show_bg(background_metas::emi_firstkiss);
            process();
        }

        static void emi_bed() {
            prepare_scene_manager();
            show_bg(background_metas::emi_bed_normal);
            process();
            show_bg(background_metas::emi_bed_smile);
            process();
            show_bg(background_metas::emi_bed_happy);
            process();
            show_bg(background_metas::emi_bed_unsure);
            process();
            show_bg(background_metas::emi_bed_frown);
            process();
            show_bg(background_metas::emi_parkback);
            process();
            show_bg(background_metas::emi_parkback_frown);
            process();
        }

        static void emi_forehead() {
            prepare_scene_manager();
            show_bg(background_metas::emi_forehead);
            process();
        }

        static void emi_grinding() {
            prepare_scene_manager();
            // TODO: implement
        }

        static void emi_shed() {
            prepare_scene_manager();
            // TODO: implement
        }

        static void emi_grave() {
            prepare_scene_manager();
            show_bg(background_metas::emi_grave);
            process();
        }

        static void emi_cry_down() {
            prepare_scene_manager();
            show_bg(background_metas::emi_cry_down);
            process();
        }

        static void emi_miss() {
            prepare_scene_manager();
            show_bg(background_metas::emi_miss_closed);
            process();
            show_bg(background_metas::emi_miss_open);
            process();
        }

        static void emi_ending() {
            prepare_scene_manager();
            show_bg(background_metas::emi_ending_smile);
            process();
            show_bg(background_metas::emi_ending_serious);
            process();
            show_bg(background_metas::emi_ending_glad);
            process();
        }

        static void hana_library() {
            prepare_scene_manager();
            show_bg(background_metas::hana_library);
            process();
            show_bg(background_metas::hana_library_read);
            process();
            show_bg(background_metas::hana_library_gasp);
            process();
        }

        static void hanako_shanghaiwindow() {
            prepare_scene_manager();
            SceneManager::set_event(background_metas::hanako_fw_base, HanakoFireworksEvent(), SCENE_TRANSITION_NONE, GALLERY_DISSOLVE_TIME);
            process();
            SceneManager::set_event_state(1);
            process();
        }

        static void hanako_presents1() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_presents1);
            process();
            show_bg(background_metas::hanako_presents2);
            process();
        }

        static void hanako_crayon() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_crayon1);
            process();
            show_bg(background_metas::hanako_crayon2);
            process();
        }

        static void hanako_breakdown() {
            prepare_scene_manager();
            // TODO: implement
        }

        static void hanako_cry() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_cry_closed);
            process();
            show_bg(background_metas::hanako_cry_open);
            process();
            show_bg(background_metas::hanako_cry_away);
            process();
        }

        static void hanako_billiards() {
            prepare_scene_manager();
            // TODO: implement
            show_bg(background_metas::hanako_billiards_break);
            process();
            show_bg(background_metas::hanako_billiards_distant);
            process();
            show_bg(background_metas::hanako_billiards_serious);
            process();
            show_bg(background_metas::hanako_billiards_timid);
            process();
            show_bg(background_metas::hanako_billiards_smile);
            process();
        }

        static void hanako_emptyclassroom() {
            prepare_scene_manager();
            // TODO: implement
            show_bg(background_metas::hanako_emptyclassroom_bg);
            process();
        }

        static void hanako_rage() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_rage);
            process();
            show_bg(background_metas::hanako_rage_sad);
            process();
        }

        static void hisao_scar() {
            prepare_scene_manager();
            show_bg(background_metas::hisao_scar);
            process();
        }

        static void hanako_scars() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_scars);
            process();
        }

        static void hanako_bed() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_bed_boobs_blush);
            process();
            show_bg(background_metas::hanako_bed_boobs_glance);
            process();
            show_bg(background_metas::hanako_bed_crotch_blush);
            process();
            show_bg(background_metas::hanako_bed_crotch_glance);
            process();
        }

    }

    inline bn::array<gallery_image, 12> get_gallery_images(const int page) {
        switch (page) {
            case 0: {
                return bn::array<gallery_image, 12>({
                    gallery_image(&background_metas::other_iwanako, gallery_script::other_iwanako),
                    gallery_image(&background_metas::hisao_class, gallery_script::hisao_class),
                    gallery_image(&background_metas::kenji_rooftop, gallery_script::kenji_rooftop),
                    gallery_image(&background_metas::hisao_teacup, gallery_script::hisao_teacup),
                    gallery_image(&background_metas::hisao_letter_closed, gallery_script::hisao_letter),
                    gallery_image(&background_metas::akira_park, gallery_script::akira_park),
                    gallery_image(&background_metas::emi_knockeddown, gallery_script::emi_knockeddown),
                    gallery_image(&background_metas::emi_run_face, gallery_script::emi_run_face),
                    gallery_image(&background_metas::emitrack_blocks, gallery_script::emitrack_blocks),
                    gallery_image(&background_metas::emitrack_running, gallery_script::emitrack_running),
                    gallery_image(&background_metas::emitrack_finishtop, gallery_script::emitrack_finishtop),
                    gallery_image(&background_metas::emitrack_finish, gallery_script::emitrack_finish),
                });
            }
            case 1: {
                return bn::array<gallery_image, 12>({
                    gallery_image(&background_metas::picnic_normal, gallery_script::picnic),
                    gallery_image(&background_metas::emi_sleep_unsure, gallery_script::emi_sleep),
                    gallery_image(&background_metas::emi_sleepy, gallery_script::emi_sleepy),
                    gallery_image(&background_metas::emi_firstkiss, gallery_script::emi_firstkiss),
                    gallery_image(&background_metas::emi_bed_normal, gallery_script::emi_bed),
                    gallery_image(&background_metas::emi_forehead, gallery_script::emi_forehead),
                    // gallery_image(&background_metas::emi_grinding, gallery_script::emi_grinding),
                    // gallery_image(&background_metas::emi_shed, gallery_script::emi_shed),
                    gallery_image(&background_metas::emi_grave, gallery_script::emi_grave),
                    gallery_image(&background_metas::emi_cry_down, gallery_script::emi_cry_down),
                    gallery_image(&background_metas::emi_miss_closed, gallery_script::emi_miss),
                    gallery_image(&background_metas::emi_ending_smile, gallery_script::emi_ending),
                });
            }
            case 2: {
                return bn::array<gallery_image, 12>({
                    gallery_image(&background_metas::hana_library, gallery_script::hana_library),
                    gallery_image(&background_metas::hanako_fw_base, gallery_script::hanako_shanghaiwindow),
                    gallery_image(&background_metas::hanako_presents1, gallery_script::hanako_presents1),
                    gallery_image(&background_metas::hanako_crayon1, gallery_script::hanako_crayon),
                    // gallery_image(&background_metas::hanako_breakdown_down, gallery_script::hanako_breakdown),
                    gallery_image(&background_metas::hanako_cry_closed, gallery_script::hanako_cry),
                    gallery_image(&background_metas::hanako_billiards_break, gallery_script::hanako_billiards),
                    gallery_image(&background_metas::hanako_emptyclassroom_bg, gallery_script::hanako_emptyclassroom),
                    gallery_image(&background_metas::hanako_rage, gallery_script::hanako_rage),
                    gallery_image(&background_metas::hisao_scar, gallery_script::hisao_scar),
                    gallery_image(&background_metas::hanako_scars, gallery_script::hanako_scars),
                    gallery_image(&background_metas::hanako_bed_boobs_blush, gallery_script::hanako_bed),
                });
            }
            default:
                BN_ERROR("Invalid page number: ", page);
                return bn::array<gallery_image, 12>({});
        }
    }


    // define _gallery_images = (


    //     ("thumb/hanako_missionary.jpg", "evh hanako_missionary_underwear", "evh hanako_missionary_underwear", "evh hanako_missionary_open", "evh hanako_missionary_closed", "evh hanako_missionary_clench"),
    //     ("thumb/hanako_after.jpg", "ev hanako_after_worry", "ev hanako_after_smile"),
    //     ("thumb/hanako_park.jpg", "ev hanako_park_alone", "ev hanako_park_away", "ev hanako_park_look", "ev hanako_park_closed"),
    //     ("thumb/hanako_goodend.jpg", "unlock_ev hanako_goodend_close", "unlock_ev hanako_goodend", "unlock_ev hanako_goodend_muffin"),
    //     ("thumb/lilly_tearoom.jpg", "ev lilly_tearoom", "ev lilly_tearoom_open"),
    //     ("thumb/lilly_touch.jpg", "ev lilly_touch_uni", "ev lilly_touch_cheong", "ev lilly_touch_cas"),
    //     ("thumb/lilly_crane.jpg", "ev lilly_crane"),
    //     ("thumb/lilly_bedroom.jpg", "ev lilly_bedroom"),
    //     ("thumb/lilly_hanako_hug.jpg", Trigger("ev lilly_hanako_hug", "unlock_ev lilly_hanako_hug_end")),
    //     ("thumb/lilly_sleeping.jpg", "ev lilly_sleeping", "ev lilly_sleeping_smile"),
    //     ("thumb/lilly_trainride.jpg", Trigger("evfg lilly_trainride", "ev lilly_trainride"), Trigger("evfg lilly_trainride_smiles", "ev lilly_trainride_smiles"), "ev lilly_trainride_ni"),
    //     ("thumb/lilly_wheat.jpg", "unlock_ev lilly_wheat_close", "ev lilly_wheat_small"),
    //     ("thumb/lilly_handjob.jpg", "evhunlock lilly_handjob_chest_frown_small", "evhunlock lilly_handjob_chest_normal_small", "evh lilly_handjob_stroke_flustopen_small", "evh lilly_handjob_stroke_normopen_small", "evh lilly_handjob_stroke_normshut_small"),
    //     ("thumb/lilly_cowgirl.jpg", "evh lilly_cowgirl_cry_small", "evh lilly_cowgirl_frown_small", "evh lilly_cowgirl_smile_small", "evh lilly_cowgirl_strain_small", "evh lilly_cowgirl_weaksmile_small"),
    //     ("thumb/lilly_bath.jpg", "evh lilly_bath_emb_small", "evh lilly_bath_grab_small", "evh lilly_bath_moan_small", "evh lilly_bath_open_small", "evh lilly_bath_smile_small"),
    //     ("thumb/lilly_afterbath.jpg", "evh lilly_afterbath_open_small", "evh lilly_afterbath_shut_small"),
    //     ("thumb/lilly_kissing.jpg", "ev lilly_kissing"),
    //     ("thumb/lilly_masturbate.jpg", "evh lilly_masturbate", "evh lilly_masturbate_come", "evh lilly_masturbate_come_face"),
    //     ("thumb/lilly_restaurant.jpg", Trigger("ev lilly_restaurant_listen", "evul lilly_restaurant_listen"), Trigger("ev lilly_restaurant_sheepish", "evul lilly_restaurant_sheepish"), "ev lilly_restaurant_eat", "ev lilly_restaurant_chew", "ev lilly_restaurant_wine"),
    //     ("thumb/lilly_sheets.jpg", "ev lilly_sheets"),
    //     ("thumb/lilly_airport.jpg", "ev lilly_airport", "ev lilly_airport_end"),
    //     ("thumb/lilly_hospitalwindow.jpg", "ev lilly_hospitalwindow"),
    //     ("thumb/lilly_hospital.jpg", Trigger("ev lilly_hospitalclosed", "unlock_ev lilly_hospitalclosed"), Trigger("ev lilly_hospital", "unlock_ev lilly_hospital")),
    //     ("thumb/lilly_goodend.jpg", "unlock_ev lilly_goodend"),
    //     ("thumb/rin_eating.jpg", "ev rin_eating"),
    //     ("thumb/rin_artclass.jpg", "ev rin_artclass1", "ev rin_artclass2", "ev rin_artclass3", "ev rin_artclass4"),
    //     ("thumb/hisao_mirror.jpg", Trigger("ev hisao_mirror", "ev hisao_mirror_800")),
    //     ("thumb/rin_painting.jpg", "ev rin_painting_base", "ev rin_painting_foot", "ev rin_painting_faceconcerned", "ev rin_painting_concerned", "ev rin_painting_reply"),
    //     ("thumb/rin_rain.jpg", "ev rin_rain_away", "ev rin_rain_towards"),
    //     ("thumb/rin_high.jpg", "ev rin_high_frown", "ev rin_high_grin", "ev rin_high_grinwide", "ev rin_high_oneeye", "ev rin_high_open", "ev rin_high_smile", "ev rin_high_sleep"),
    //     ("thumb/rin_kiss.jpg", "ev rin_kiss"),
    //     ("thumb/rin_nap.jpg", "ev rin_nap_total", "ev rin_nap_total_awind", "ev rin_nap_close_awind", "ev rin_nap_close_awind_tears"),
    //     ("thumb/rin_wisp.jpg", "ev rin_wisp1", "ev rin_wisp2", "ev rin_wisp3", "ev rin_wisp4", "ev rin_wisp5"),
    //     ("thumb/rin_galleryskylight.jpg", "ovl rin_galleryskylight"),
    //     ("thumb/rin_orange.jpg", "ev rin_orange", "ev rin_orange_large"),
    //     ("thumb/rin_masturbate.jpg", "ev rin_masturbate_away","ev rin_masturbate_surprise", "ev rin_masturbate_frown", "ev rin_masturbate_doubt", "ev rin_masturbate_hug"),
    //     ("thumb/rin_relief.jpg", "evh rin_relief_down", "evh rin_relief_up"),
    //     ("thumb/rin_gallery.jpg", "ev rin_gallery"),
    //     ("thumb/rin_trueend.jpg", "ev rin_trueend_normal", "ev rin_trueend_smile", "ev rin_trueend_weaksmile", "ev rin_trueend_sad", "ev rin_trueend_closed", "ev rin_trueend_hug", "ev rin_trueend_hugclosed", "ev rin_trueend_gone"),
    //     ("thumb/rin_wet.jpg", "ev rin_wet_pan_down", "ev rin_wet_arms", "ev rin_wet_face_up", "ev rin_wet_face_down", "ev rin_wet_towel_up", "ev rin_wet_towel_down", "ev rin_wet_towel_touch"),
    //     ("thumb/rin_h2.jpg", "evh rin_h2_pan_surprise", "evh rin_h2_pan_away", "evh rin_h2_pan_closed", "evh rin_h2_nopan_closed", "evh rin_h2_hisao_closed"),
    //     ("thumb/rin_pair.jpg", "ev rin_pair_base_clothes","ev rin_pair_base"),
    //     ("thumb/rin_h.jpg", "evh rin_h_closed", "evh rin_h_left", "evh rin_h_normal", "evh rin_h_right", "evh rin_h_strain", "evh rin_h_closed_close", "evh rin_h_left_close", "evh rin_h_normal_close", "evh rin_h_right_close", "evh rin_h_strain_close"),
    //     ("thumb/rin_goodend.jpg", Trigger("rin goodend_1", "ev rin_goodend_1"), Trigger("rin goodend_1b", "ev rin_goodend_1b"), Trigger("rin goodend_2", "ev rin_goodend_2")),
    //     ("thumb/shizu_shanghai.jpg", "ev shizu_shanghai", "ev shizu_shanghai_borednormal", "ev shizu_shanghai_smirknormal", "ev shizu_shanghai_smirklaugh"),
    //     ("thumb/showdown.jpg", "ev showdown"),
    //     ("thumb/shizu_chess.jpg", "ev shizu_chess_base", "ev shizu_chess_base3", "ev shizu_chess_base2"),
    //     ("thumb/kenji_glasses.jpg", Trigger("evmg kenji_glasses_closed", "evul kenji_glasses_closed"), Trigger("evmg kenji_glasses_frown", "evul kenji_glasses_frown"), Trigger("evmg kenji_glasses_normal", "evul kenji_glasses_normal")),
    //     ("thumb/shizu_tanabata.jpg", "ev shizutanabata"),
    //     ("thumb/shizu_confess.jpg", "ev shizuconfess_normal", "ev shizuconfess_closed", "ev shizuconfess_smile"),
    //     ("thumb/shizu_hands.jpg", "ev shizu_hands"),
    //     ("thumb/shizu_couch.jpg", "ev shizu_couch"),
    //     ("thumb/shizune_car.jpg", "ev shizune_car"),
    //     ("thumb/shizu_fishing.jpg", "ev shizu_fishing_ah", "ev shizu_fishing_sl"),
    //     ("thumb/shizune_tied.jpg", "evh shizune_hcg_tied_blush_small", "evh shizune_hcg_tied_smile_small", "evh shizune_hcg_tied_stare_small", "evh shizune_hcg_tied_close_small", "evh shizune_hcg_tied_kinky1_small", "evh shizune_hcg_tied_kinky2_small", "evh shizune_hcg_tied_kinky3_small", Trigger("evh shizune_hcg_tied_kinky3_small", "evhul shizune_hcg_tied_hisao2_small")),
    //     ("thumb/misha_sad.jpg", "ev misha_sad"),
    //     ("thumb/misha_naked.jpg", "evh misha_naked"),
    //     ("thumb/misha_sex.jpg", "evh misha_sex_aside", "evh misha_sex_closed"),
    //     ("thumb/misha_roof.jpg", "ev misha_roof_closed", "ev misha_roof_angry", "ev misha_roof_normal", "ev misha_roof_sad"),
    //     ("thumb/shizu_roof.jpg", "ev shizu_roof","ev shizu_roof_smile", "ev shizu_roof_towardsnormal", "ev shizu_roof_towardsangry", "ev shizu_roof2_towardsangry"),
    //     ("thumb/shizu_flashback.jpg", "ev shizu_flashback"),
    //     ("thumb/shizu_undressing.jpg", "evh shizu_undressing_clothed_stare", "evh shizu_undressing_clothed_kiss", "evh shizu_undressing_clothed_blush", "evh shizu_undressing_unclothed_blush", "evh shizu_undressing_unclothed_closed", "evh shizu_undressing_unclothed_kiss", "evh shizu_undressing_unclothed_talk"),
    //     ("thumb/shizu_pushdown.jpg", "evh shizu_pushdown"),
    //     ("thumb/shizu_straddle.jpg", "evh shizu_straddle_open", "evh shizu_straddle_tease", "evh shizu_straddle_closed", "evh shizu_straddle_smile", "evh shizu_straddle_come"),
    //     ("thumb/shizu_table.jpg", "evh shizu_table_smile", "evh shizu_table_normal", "evh shizu_table_comeopen", "evh shizu_table_comeclosed"),
    //     ("thumb/misha_nightclass.jpg", "ev misha_nightclass"),
    //     ("thumb/shizu_badend.jpg", "ev shizu_badend"),
    //     ("thumb/shizu_goodend.jpg", "ev shizu_goodend", "ev shizu_goodend_pan"),
    //     ("thumb/cutin.png", "pills", "stuffedcat", "teaset", "shangpai", "wine", "musicbox closed", "musicbox open", "hanaphone", "phonestrap", "hanaphonestrap", "insert startpistol","invite", "sc_comp", "brailler", "chessboard", "kenjibox", "jigorocard", "letter_insert", "letter_open_insert", "letter_open_insert_2", "stallphoto_insert"),
    //     ("thumb/completionbonus.jpg", "completionbonus")
    // )


}

#endif //MENU_EXTRAS_GALLERY_IMAGES_H
