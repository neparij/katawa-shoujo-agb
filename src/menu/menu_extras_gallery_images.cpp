#include "menu_extras_gallery_images.h"
#include "bn_log.h"
#include "bn_regular_bg_item.h"
#include "background_meta.h"
#include "background_metas.h"
#include "custom_background_metas.h"

namespace ks::menu {

    namespace gallery_script {
        // Page 0
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

        // Page 1
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
            show_bg(background_metas::emi_grinding_victory);
            process();
            show_bg(background_metas::emi_grinding_wink);
            process();
            show_bg(background_metas::emi_grinding_grin);
            process();
            show_bg(background_metas::emi_grinding_half_undress);
            process();
            show_bg(background_metas::emi_grinding_half_grin);
            process();
            show_bg(background_metas::emi_grinding_off_yawn);
            process();
            show_bg(background_metas::emi_grinding_off_closesurprise);
            process();
            show_bg(background_metas::emi_grinding_off_closearoused);
            process();
            show_bg(background_metas::emi_grinding_off_aroused);
            process();
            show_bg(background_metas::emi_grinding_off_arousedclosed);
            process();
            show_bg(background_metas::emi_grinding_off_come);
            process();
            show_bg(background_metas::emi_grinding_off_end);
            process();
        }

        static void emi_shed() {
            prepare_scene_manager();
            show_bg(background_metas::emi_shed_base1);
            process();
            show_bg(background_metas::emi_shed_base3);
            process();
            show_bg(background_metas::emi_shed_base4);
            process();
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

        // Page 2
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
            // TODO: implement
            not_implemented();
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
            // TODO: implement
            not_implemented();
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

        // Page 3
        static void hanako_missionary() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_missionary_underwear);
            process();
            show_bg(background_metas::hanako_missionary_open);
            process();
            show_bg(background_metas::hanako_missionary_closed);
            process();
            show_bg(background_metas::hanako_missionary_clench);
            process();
        }

        static void hanako_after() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_after_worry);
            process();
            show_bg(background_metas::hanako_after_smile);
            process();
        }

        static void hanako_park() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_park_alone);
            process();
            show_bg(background_metas::hanako_park_away);
            process();
            show_bg(background_metas::hanako_park_look);
            process();
            show_bg(background_metas::hanako_park_closed);
            process();
        }

        static void hanako_goodend() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            // TODO: Check if we want to include this image
            // show_bg(background_metas::hanako_goodend_close);
            // process();
            show_bg(background_metas::hanako_goodend);
            process();
            show_bg(background_metas::hanako_goodend_muffin);
            process();
        }

        static void lilly_tearoom() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_tearoom);
            process();
            show_bg(background_metas::lilly_tearoom_open);
            process();
        }

        static void lilly_touch() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_touch_uni);
            process();
            show_bg(background_metas::lilly_touch_cheong);
            process();
            show_bg(background_metas::lilly_touch_cas);
            process();
        }

        static void lilly_crane() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_crane);
            process();
        }

        static void lilly_bedroom() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_bedroom);
            process();
        }

        static void lilly_hanako_hug() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::lilly_hanako_hug);
            process();
        }

        static void lilly_sleeping() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_sleeping);
            process();
            show_bg(background_metas::lilly_sleeping_smile);
            process();
        }

        static void lilly_trainride() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_trainride_smiles);
            process();
            show_bg(background_metas::lilly_trainride_ni);
            process();
        }

        static void lilly_wheat() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_wheat_small);
            process();
        }

        // Page 4
        static void lilly_handjob() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hcg_handjob_chest_frown);
            process();
            show_bg(background_metas::lilly_hcg_handjob_chest_normal);
            process();
            show_bg(background_metas::lilly_hcg_handjob_stroke_flustopen_small);
            process();
            show_bg(background_metas::lilly_hcg_handjob_stroke_normopen_small);
            process();
            show_bg(background_metas::lilly_hcg_handjob_stroke_normshut_small);
            process();
        }

        static void lilly_cowgirl() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hcg_cowgirl_cry_small);
            process();
            show_bg(background_metas::lilly_hcg_cowgirl_frown_small);
            process();
            show_bg(background_metas::lilly_hcg_cowgirl_smile_small);
            process();
            show_bg(background_metas::lilly_hcg_cowgirl_strain_small);
            process();
            show_bg(background_metas::lilly_hcg_cowgirl_weaksmile_small);
            process();
        }

        static void lilly_bath() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hcg_bath_emb_small);
            process();
            show_bg(background_metas::lilly_hcg_bath_grab_small);
            process();
            show_bg(background_metas::lilly_hcg_bath_moan_small);
            process();
            show_bg(background_metas::lilly_hcg_bath_open_small);
            process();
            show_bg(background_metas::lilly_hcg_bath_smile_small);
            process();
        }

        static void lilly_afterbath() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hcg_afterbath_open_small);
            process();
            show_bg(background_metas::lilly_hcg_afterbath_shut_small);
            process();
        }

        static void lilly_kissing() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_kissing);
            process();
        }

        static void lilly_masturbate() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_masturbate);
            process();
            show_bg(background_metas::lilly_masturbate_come);
            process();
            show_bg(background_metas::lilly_masturbate_come_face);
            process();
        }

        static void lilly_restaurant() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_restaurant_listen);
            process();
            show_bg(background_metas::lilly_restaurant_sheepish);
            process();
            show_bg(background_metas::lilly_restaurant_eat);
            process();
            show_bg(background_metas::lilly_restaurant_chew);
            process();
            show_bg(background_metas::lilly_restaurant_wine);
            process();
        }

        static void lilly_sheets() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_sheets);
            process();
        }

        static void lilly_airport() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_airport);
            process();
            show_bg(background_metas::lilly_airport_end);
            process();
        }

        static void lilly_hospitalwindow() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hospitalwindow);
            process();
        }

        static void lilly_hospital() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hospitalclosed);
            process();
            show_bg(background_metas::lilly_hospital);
            process();
        }

        static void lilly_goodend() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::lilly_goodend);
            process();
        }

        // Page 5
        static void rin_eating() {
            prepare_scene_manager();
            show_bg(background_metas::rin_eating);
            process();
        }

        static void rin_artclass() {
            prepare_scene_manager();
            show_bg(background_metas::rin_artclass1);
            process();
            show_bg(background_metas::rin_artclass2);
            process();
            show_bg(background_metas::rin_artclass3);
            process();
            show_bg(background_metas::rin_artclass4);
            process();
        }

        static void hisao_mirror() {
            prepare_scene_manager();
            show_bg(background_metas::hisao_mirror);
            process();
        }

        static void rin_painting() {
            prepare_scene_manager();
            show_bg(background_metas::rin_painting_base);
            process();
            show_bg(background_metas::rin_painting_foot);
            process();
            show_bg(background_metas::rin_painting_faceconcerned);
            process();
            show_bg(background_metas::rin_painting_concerned);
            process();
            show_bg(background_metas::rin_painting_reply);
            process();
        }

        static void rin_rain() {
            prepare_scene_manager();
            show_bg(background_metas::rin_rain_away);
            process();
            show_bg(background_metas::rin_rain_towards);
            process();
        }

        static void rin_high() {
            prepare_scene_manager();
            show_bg(background_metas::rin_high_frown);
            process();
            show_bg(background_metas::rin_high_grin);
            process();
            show_bg(background_metas::rin_high_grinwide);
            process();
            show_bg(background_metas::rin_high_oneeye);
            process();
            show_bg(background_metas::rin_high_open);
            process();
            show_bg(background_metas::rin_high_smile);
            process();
            show_bg(background_metas::rin_high_sleep);
            process();
        }

        static void rin_kiss() {
            prepare_scene_manager();
            show_bg(background_metas::rin_kiss);
            process();
        }

        static void rin_nap() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::rin_nap_total);
            process();
            show_bg(background_metas::rin_nap_total_wind);
            process();
            show_bg(background_metas::rin_nap_close_wind);
            process();
            show_bg(background_metas::rin_nap_close_tears);
            process();
        }

        static void rin_wisp() {
            prepare_scene_manager();
            show_bg(background_metas::rin_wisp1);
            process();
            show_bg(background_metas::rin_wisp2);
            process();
            show_bg(background_metas::rin_wisp3);
            process();
            show_bg(background_metas::rin_wisp4);
            process();
            show_bg(background_metas::rin_wisp5);
            process();
        }

        static void rin_galleryskylight() {
            prepare_scene_manager();
            show_bg(background_metas::rin_galleryskylight);
            process();
        }

        static void rin_orange() {
            prepare_scene_manager();
            show_bg(background_metas::rin_orange);
            process();
            show_bg(background_metas::rin_orange_large);
            process();
        }

        static void rin_masturbate() {
            // TODO: resize, or implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::rin_masturbate_away);
            process();
            show_bg(background_metas::rin_masturbate_surprise);
            process();
            show_bg(background_metas::rin_masturbate_frown);
            process();
            show_bg(background_metas::rin_masturbate_doubt);
            process();
            show_bg(background_metas::rin_masturbate_hug);
            process();
        }

        // Page 6
        static void rin_relief() {
            prepare_scene_manager();
            show_bg(background_metas::rin_relief_down);
            process();
            show_bg(background_metas::rin_relief_up);
            process();
        }

        static void rin_gallery() {
            prepare_scene_manager();
            show_bg(background_metas::rin_gallery);
            process();
        }

        static void rin_trueend() {
            // TODO: implement via CustomEvent
            not_implemented();
        }

        static void rin_wet() {
            // TODO: implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::rin_wet_pan_down);
            process();
            show_bg(background_metas::rin_wet_arms);
            process();
            show_bg(background_metas::rin_wet_face_up);
            process();
            show_bg(background_metas::rin_wet_face_down);
            process();
            show_bg(background_metas::rin_wet_towel_up);
            process();
            show_bg(background_metas::rin_wet_towel_down);
            process();
            show_bg(background_metas::rin_wet_towel_touch);
            process();
        }

        static void rin_h2() {
            not_implemented();
        }

        static void rin_pair() {
            not_implemented();
        }

        static void rin_h() {
            not_implemented();
        }

        static void rin_goodend() {
            not_implemented();
        }

        static void shizu_shanghai() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_shanghai);
            process();
            show_bg(background_metas::shizu_shanghai_borednormal);
            process();
            show_bg(background_metas::shizu_shanghai_smirknormal);
            process();
            show_bg(background_metas::shizu_shanghai_smirklaugh);
            process();
        }

        static void showdown() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_shizu_showdown);
            process();
        }

        static void shizu_chess() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_chess_base);
            process();
            show_bg(background_metas::shizu_chess_base3);
            process();
            show_bg(background_metas::shizu_chess_base2);
            process();
        }

        static void kenji_glasses() {
            not_implemented();
        }

        // Page 7
        static void shizu_tanabata() {
            prepare_scene_manager();
            show_bg(background_metas::shizutanabata);
            process();
        }

        static void shizu_confess() {
            prepare_scene_manager();
            show_bg(background_metas::shizuconfess_normal);
            process();
            show_bg(background_metas::shizuconfess_closed);
            process();
            show_bg(background_metas::shizuconfess_smile);
            process();
        }

        static void shizu_hands() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_hands);
            process();
        }

        static void shizu_couch() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_couch);
            process();
        }

        static void shizune_car() {
            prepare_scene_manager();
            show_bg(background_metas::shizune_car);
            process();
        }

        static void shizu_fishing() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_fishing_ah);
            process();
            show_bg(background_metas::shizu_fishing_sl);
            process();
        }

        static void shizune_tied() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::shizune_hcg_tied_blush_small);
            process();
            show_bg(background_metas::shizune_hcg_tied_smile_small);
            process();
            show_bg(background_metas::shizune_hcg_tied_stare_small);
            process();
            show_bg(background_metas::shizune_hcg_tied_close_small);
            process();
            show_bg(background_metas::shizune_hcg_tied_kinky1_small);
            process();
            show_bg(background_metas::shizune_hcg_tied_kinky2_small);
            process();
            show_bg(background_metas::shizune_hcg_tied_kinky3_small);
            process();
            show_bg(background_metas::shizune_hcg_tied_hisao2_small);
            process();
        }

        static void misha_sad() {
            prepare_scene_manager();
            show_bg(background_metas::misha_sad);
            process();
        }
        static void misha_naked() {
            prepare_scene_manager();
            show_bg(background_metas::misha_naked);
            process();
        }

        static void misha_sex() {
            prepare_scene_manager();
            show_bg(background_metas::misha_sex_aside);
            process();
            show_bg(background_metas::misha_sex_closed);
            process();
        }

        static void misha_roof() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::misha_roof_closed);
            process();
            show_bg(background_metas::misha_roof_angry);
            process();
            show_bg(background_metas::misha_roof_normal);
            process();
            show_bg(background_metas::misha_roof_sad);
            process();
        }

        static void shizu_roof() {
            not_implemented();
        }

        // Page 8
        static void shizu_flashback() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_flashback);
            process();
        }

        static void shizu_undressing() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_undressing_clothed_stare);
            process();
            show_bg(background_metas::shizu_undressing_clothed_kiss);
            process();
            show_bg(background_metas::shizu_undressing_clothed_blush);
            process();
            show_bg(background_metas::shizu_undressing_unclothed_blush);
            process();
            show_bg(background_metas::shizu_undressing_unclothed_closed);
            process();
            show_bg(background_metas::shizu_undressing_unclothed_kiss);
            process();
            show_bg(background_metas::shizu_undressing_unclothed_talk);
            process();
        }

        static void shizu_pushdown() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_pushdown);
            process();
        }

        static void shizu_straddle() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::shizu_straddle_open);
            process();
            show_bg(background_metas::shizu_straddle_tease);
            process();
            show_bg(background_metas::shizu_straddle_closed);
            process();
            show_bg(background_metas::shizu_straddle_smile);
            process();
            show_bg(background_metas::shizu_straddle_come);
            process();
        }

        static void shizu_table() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_table_smile);
            process();
            show_bg(background_metas::shizu_table_normal);
            process();
            show_bg(background_metas::shizu_table_comeopen);
            process();
            show_bg(background_metas::shizu_table_comeclosed);
            process();
        }

        static void misha_nightclass() {
            prepare_scene_manager();
            show_bg(background_metas::misha_nightclass);
            process();
        }

        static void shizu_badend() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_badend);
            process();
        }

        static void shizu_goodend() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::shizu_goodend);
            process();
        }

        static void cutin() {
            not_implemented();
        }

        static void completionbonus() {
            prepare_scene_manager();
            show_bg(background_metas::completionbonus);
            process();
        }

    }

    const gallery_image images_0[12] = {
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
    };

    const gallery_image images_1[12] = {
        gallery_image(&background_metas::picnic_normal, gallery_script::picnic),
        gallery_image(&background_metas::emi_sleep_unsure, gallery_script::emi_sleep),
        gallery_image(&background_metas::emi_sleepy, gallery_script::emi_sleepy),
        gallery_image(&background_metas::emi_firstkiss, gallery_script::emi_firstkiss),
        gallery_image(&background_metas::emi_bed_normal, gallery_script::emi_bed),
        gallery_image(&background_metas::emi_forehead, gallery_script::emi_forehead),
        gallery_image(&background_metas::emi_grinding_victory, gallery_script::emi_grinding),
        gallery_image(&background_metas::emi_shed_base1, gallery_script::emi_shed),
        gallery_image(&background_metas::emi_grave, gallery_script::emi_grave),
        gallery_image(&background_metas::emi_cry_down, gallery_script::emi_cry_down),
        gallery_image(&background_metas::emi_miss_closed, gallery_script::emi_miss),
        gallery_image(&background_metas::emi_ending_smile, gallery_script::emi_ending),
    };

    const gallery_image images_2[12] = {
        gallery_image(&background_metas::hana_library, gallery_script::hana_library),
        gallery_image(&background_metas::hanako_fw_base, gallery_script::hanako_shanghaiwindow),
        gallery_image(&background_metas::hanako_presents1, gallery_script::hanako_presents1),
        gallery_image(&background_metas::hanako_crayon1, gallery_script::hanako_crayon),
        gallery_image(&background_metas::hanako_breakdown_bg, gallery_script::hanako_breakdown), // TODO: thumbnail, script
        gallery_image(&background_metas::hanako_cry_closed, gallery_script::hanako_cry),
        gallery_image(&background_metas::hanako_billiards_break, gallery_script::hanako_billiards),
        gallery_image(&background_metas::hanako_emptyclassroom_bg, gallery_script::hanako_emptyclassroom), // TODO: thumbnail, script
        gallery_image(&background_metas::hanako_rage, gallery_script::hanako_rage),
        gallery_image(&background_metas::hisao_scar, gallery_script::hisao_scar),
        gallery_image(&background_metas::hanako_scars, gallery_script::hanako_scars),
        gallery_image(&background_metas::hanako_bed_boobs_blush, gallery_script::hanako_bed),
    };

    const gallery_image images_3[12] = {
        gallery_image(&background_metas::hanako_missionary_underwear, gallery_script::hanako_missionary),
        gallery_image(&background_metas::hanako_after_worry, gallery_script::hanako_after),
        gallery_image(&background_metas::hanako_park_alone, gallery_script::hanako_park),
        gallery_image(&background_metas::hanako_goodend, gallery_script::hanako_goodend),
        gallery_image(&background_metas::lilly_tearoom, gallery_script::lilly_tearoom),
        gallery_image(&background_metas::lilly_touch_uni, gallery_script::lilly_touch),
        gallery_image(&background_metas::lilly_crane, gallery_script::lilly_crane),
        gallery_image(&background_metas::lilly_bedroom, gallery_script::lilly_bedroom),
        gallery_image(&background_metas::lilly_hanako_hug, gallery_script::lilly_hanako_hug),
        gallery_image(&background_metas::lilly_sleeping, gallery_script::lilly_sleeping),
        gallery_image(&background_metas::lilly_trainride_smiles, gallery_script::lilly_trainride),
        gallery_image(&background_metas::lilly_wheat_small, gallery_script::lilly_wheat),
    };

    const gallery_image images_4[12] = {
        gallery_image(&background_metas::lilly_hcg_handjob_chest_frown, gallery_script::lilly_handjob),
        gallery_image(&background_metas::lilly_hcg_cowgirl_cry_small, gallery_script::lilly_cowgirl),
        gallery_image(&background_metas::lilly_hcg_bath_emb_small, gallery_script::lilly_bath),
        gallery_image(&background_metas::lilly_hcg_afterbath_open_small, gallery_script::lilly_afterbath),
        gallery_image(&background_metas::lilly_kissing, gallery_script::lilly_kissing),
        gallery_image(&background_metas::lilly_masturbate, gallery_script::lilly_masturbate),
        gallery_image(&background_metas::lilly_restaurant_listen, gallery_script::lilly_restaurant),
        gallery_image(&background_metas::lilly_sheets, gallery_script::lilly_sheets),
        gallery_image(&background_metas::lilly_airport, gallery_script::lilly_airport),
        gallery_image(&background_metas::lilly_hospitalwindow, gallery_script::lilly_hospitalwindow),
        gallery_image(&background_metas::lilly_hospitalclosed, gallery_script::lilly_hospital),
        gallery_image(&background_metas::lilly_goodend, gallery_script::lilly_goodend),
    };

    const gallery_image images_5[12] = {
        gallery_image(&background_metas::rin_eating, gallery_script::rin_eating),
        gallery_image(&background_metas::rin_artclass1, gallery_script::rin_artclass),
        gallery_image(&background_metas::hisao_mirror, gallery_script::hisao_mirror),
        gallery_image(&background_metas::rin_painting_base, gallery_script::rin_painting),
        gallery_image(&background_metas::rin_rain_away, gallery_script::rin_rain),
        gallery_image(&background_metas::rin_high_frown, gallery_script::rin_high),
        gallery_image(&background_metas::rin_kiss, gallery_script::rin_kiss),
        gallery_image(&background_metas::rin_nap_total, gallery_script::rin_nap),
        gallery_image(&background_metas::rin_wisp1, gallery_script::rin_wisp),
        gallery_image(&background_metas::rin_galleryskylight, gallery_script::rin_galleryskylight),
        gallery_image(&background_metas::rin_orange, gallery_script::rin_orange),
        gallery_image(&background_metas::rin_masturbate_away, gallery_script::rin_masturbate),
    };

    const gallery_image images_6[12] = {
        gallery_image(&background_metas::rin_relief_down, gallery_script::rin_relief),
        gallery_image(&background_metas::rin_gallery, gallery_script::rin_gallery),
        gallery_image(&background_metas::rin_trueend_normal, gallery_script::rin_trueend),
        gallery_image(&background_metas::rin_wet_pan_down, gallery_script::rin_wet), // TODO: implement via CustomEvent
        gallery_image(&background_metas::rin_h2_l_pan, gallery_script::rin_h2), // TODO: thumbnail, script
        gallery_image(&background_metas::rin_pair_base, gallery_script::rin_pair), // TODO: thumbnail, script
        gallery_image(&background_metas::rin_h_closed, gallery_script::rin_h), // TODO: thumbnail, script
        gallery_image(&background_metas::rin_goodend_base, gallery_script::rin_goodend), // TODO: thumbnail, script
        gallery_image(&background_metas::shizu_shanghai, gallery_script::shizu_shanghai),
        gallery_image(&background_metas::lilly_shizu_showdown, gallery_script::showdown),
        gallery_image(&background_metas::shizu_chess_base, gallery_script::shizu_chess),
        gallery_image(&background_metas::kenji_glasses_bg, gallery_script::kenji_glasses), // TODO: thumbnail, script

    };

    const gallery_image images_7[12] = {
        gallery_image(&background_metas::shizutanabata, gallery_script::shizu_tanabata),
        gallery_image(&background_metas::shizuconfess_normal, gallery_script::shizu_confess),
        gallery_image(&background_metas::shizu_hands, gallery_script::shizu_hands),
        gallery_image(&background_metas::shizu_couch, gallery_script::shizu_couch),
        gallery_image(&background_metas::shizune_car, gallery_script::shizune_car),
        gallery_image(&background_metas::shizu_fishing_ah, gallery_script::shizu_fishing),
        gallery_image(&background_metas::shizune_hcg_tied_blush_small, gallery_script::shizune_tied),
        gallery_image(&background_metas::misha_sad, gallery_script::misha_sad),
        gallery_image(&background_metas::misha_naked, gallery_script::misha_naked),
        gallery_image(&background_metas::misha_sex_aside, gallery_script::misha_sex),
        gallery_image(&background_metas::misha_roof_closed, gallery_script::misha_roof),
        gallery_image(&background_metas::shizu_roof, gallery_script::shizu_roof), // TODO: thumbnail, script
    };

    const gallery_image images_8[10] = {
        gallery_image(&background_metas::shizu_flashback, gallery_script::shizu_flashback),
        gallery_image(&background_metas::shizu_undressing_clothed_stare, gallery_script::shizu_undressing),
        gallery_image(&background_metas::shizu_pushdown, gallery_script::shizu_pushdown),
        gallery_image(&background_metas::shizu_straddle_open, gallery_script::shizu_straddle),
        gallery_image(&background_metas::shizu_table_smile, gallery_script::shizu_table),
        gallery_image(&background_metas::misha_nightclass, gallery_script::misha_nightclass),
        gallery_image(&background_metas::shizu_badend, gallery_script::shizu_badend),
        gallery_image(&background_metas::shizu_goodend, gallery_script::shizu_goodend),
        gallery_image(&background_metas::event_missing, gallery_script::cutin), // TODO: items list.
        gallery_image(&background_metas::completionbonus, gallery_script::completionbonus),
    };

    const gallery_image images_null[1] = {
        gallery_image(nullptr, gallery_script::not_implemented)
    };
}