#include "menu_extras_gallery_images.h"
#include "bn_log.h"
#include "bn_regular_bg_item.h"
#include "background_meta.h"
#include "background_metas.h"
#include "custom_background_metas.h"

#include "vfx_metas/pills.h"
#include "vfx_metas/stuffedcat.h"
#include "vfx_metas/teaset.h"
#include "vfx_metas/shangpai.h"
#include "vfx_metas/wine.h"
#include "vfx_metas/musicbox_closed.h"
#include "vfx_metas/musicbox_open.h"
#include "vfx_metas/hanaphone.h"
#include "vfx_metas/phonestrap.h"
#include "vfx_metas/hanaphonestrap.h"
#include "vfx_metas/startpistol.h"
#include "vfx_metas/invite.h"
#include "vfx_metas/sc_comp.h"
#include "vfx_metas/brailler.h"
#include "vfx_metas/chessboard.h"
#include "vfx_metas/kenjibox.h"
#include "vfx_metas/jigorocard.h"
#include "vfx_metas/letter_insert.h"
#include "vfx_metas/letter_open_insert.h"
#include "vfx_metas/letter_open_insert_2.h"
#include "vfx_metas/stallphoto_insert.h"

namespace ks::menu {

    namespace gallery_script {
        // Page 0
        static void other_iwanako() {
            prepare_scene_manager();
            show_event(background_metas::other_iwanako, OtherIwanakoEvent(), SCENE_TRANSITION_NONE, GALLERY_DISSOLVE_TIME);
        }

        static void hisao_class() {
            prepare_scene_manager();
            show_event(background_metas::hisao_class, HisaoClassStartEvent(), SCENE_TRANSITION_NONE, GALLERY_DISSOLVE_TIME);
            show_event(background_metas::hisao_class, HisaoClassMoveEvent(), SCENE_TRANSITION_NONE, 0);
            show_event(background_metas::hisao_class, HisaoClassEndEvent(), SCENE_TRANSITION_NONE, 0);
        }

        static void kenji_rooftop() {
            prepare_scene_manager();
            show_bg(background_metas::kenji_rooftop);
        }

        static void hisao_teacup() {
            prepare_scene_manager();
            show_bg(background_metas::hisao_teacup);
        }

        static void hisao_letter() {
            prepare_scene_manager();
            show_bg(background_metas::hisao_letter_closed);
            show_bg(background_metas::hisao_letter_open);
            show_bg(background_metas::hisao_letter_open_2);
        }

        static void akira_park() {
            prepare_scene_manager();
            show_bg(background_metas::akira_park);
        }

        static void emi_knockeddown() {
            prepare_scene_manager();
            show_bg(background_metas::emi_knockeddown);
        }

        static void emi_run_face() {
            prepare_scene_manager();
            show_bg(background_metas::emi_run_face);
        }

        static void emitrack_blocks() {
            prepare_scene_manager();
            show_bg(background_metas::emitrack_blocks);
            show_bg(background_metas::emitrack_blocks_close);
            show_bg(background_metas::emitrack_blocks_close_grin);
        }

        static void emitrack_running() {
            prepare_scene_manager();
            show_bg(background_metas::emitrack_running);
        }

        static void emitrack_finishtop() {
            prepare_scene_manager();
            show_bg(background_metas::emitrack_finishtop);
        }

        static void emitrack_finish() {
            prepare_scene_manager();
            show_bg(background_metas::emitrack_finish);
        }

        // Page 1
        static void picnic() {
            prepare_scene_manager();
            show_bg(background_metas::picnic_normal);
            show_bg(background_metas::picnic_rain);
        }

        static void emi_sleep() {
            prepare_scene_manager();
            show_bg(background_metas::emi_sleep_unsure);
            show_bg(background_metas::emi_sleep_normal);
            show_bg(background_metas::emi_sleep_weep);
            show_bg(background_metas::emi_sleep_cry);
        }

        static void emi_sleepy() {
            prepare_scene_manager();
            show_bg(background_metas::emi_sleepy);
            show_bg(background_metas::emi_sleepy_face);
            show_bg(background_metas::emi_sleepy_legs);
        }

        static void emi_firstkiss() {
            prepare_scene_manager();
            show_bg(background_metas::emi_firstkiss);
        }

        static void emi_bed() {
            prepare_scene_manager();
            show_bg(background_metas::emi_bed_normal);
            show_bg(background_metas::emi_bed_smile);
            show_bg(background_metas::emi_bed_happy);
            show_bg(background_metas::emi_bed_unsure);
            show_bg(background_metas::emi_bed_frown);
            show_bg(background_metas::emi_parkback);
            show_bg(background_metas::emi_parkback_frown);
        }

        static void emi_forehead() {
            prepare_scene_manager();
            show_bg(background_metas::emi_forehead);
        }

        static void emi_grinding() {
            prepare_scene_manager();
            show_bg(background_metas::emi_grinding_victory);
            show_bg(background_metas::emi_grinding_wink);
            show_bg(background_metas::emi_grinding_grin);
            show_bg(background_metas::emi_grinding_half_undress);
            show_bg(background_metas::emi_grinding_half_grin);
            show_bg(background_metas::emi_grinding_off_yawn);
            show_bg(background_metas::emi_grinding_off_closesurprise);
            show_bg(background_metas::emi_grinding_off_closearoused);
            show_bg(background_metas::emi_grinding_off_aroused);
            show_bg(background_metas::emi_grinding_off_arousedclosed);
            show_bg(background_metas::emi_grinding_off_come);
            show_bg(background_metas::emi_grinding_off_end);
        }

        static void emi_shed() {
            prepare_scene_manager();
            show_bg(background_metas::emi_shed_base1);
            show_bg(background_metas::emi_shed_base3);
            show_bg(background_metas::emi_shed_base4);
        }

        static void emi_grave() {
            prepare_scene_manager();
            show_bg(background_metas::emi_grave);
        }

        static void emi_cry_down() {
            prepare_scene_manager();
            show_bg(background_metas::emi_cry_down);
        }

        static void emi_miss() {
            prepare_scene_manager();
            show_bg(background_metas::emi_miss_closed);
            show_bg(background_metas::emi_miss_open);
        }

        static void emi_ending() {
            prepare_scene_manager();
            show_bg(background_metas::emi_ending_smile);
            show_bg(background_metas::emi_ending_serious);
            show_bg(background_metas::emi_ending_glad);
        }

        // Page 2
        static void hana_library() {
            prepare_scene_manager();
            show_bg(background_metas::hana_library);
            show_bg(background_metas::hana_library_read);
            show_bg(background_metas::hana_library_gasp);
        }

        static void hanako_shanghaiwindow() {
            prepare_scene_manager();
            show_event(background_metas::hanako_fw_base, HanakoFireworksEvent(), SCENE_TRANSITION_NONE, GALLERY_DISSOLVE_TIME);
            SceneManager::set_event_state(1);
            process();
        }

        static void hanako_presents1() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_presents1);
            show_bg(background_metas::hanako_presents2);
        }

        static void hanako_crayon() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_crayon1);
            show_bg(background_metas::hanako_crayon2);
        }

        static void hanako_breakdown() {
            // TODO: implement
            not_implemented();
        }

        static void hanako_cry() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_cry_closed);
            show_bg(background_metas::hanako_cry_open);
            show_bg(background_metas::hanako_cry_away);
        }

        static void hanako_billiards() {
            prepare_scene_manager();
            // TODO: implement
            show_bg(background_metas::hanako_billiards_break);
            show_bg(background_metas::hanako_billiards_distant);
            show_bg(background_metas::hanako_billiards_serious);
            show_bg(background_metas::hanako_billiards_timid);
            show_bg(background_metas::hanako_billiards_smile);
        }

        static void hanako_emptyclassroom() {
            // TODO: implement
            not_implemented();
        }

        static void hanako_rage() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_rage);
            show_bg(background_metas::hanako_rage_sad);
        }

        static void hisao_scar() {
            prepare_scene_manager();
            show_bg(background_metas::hisao_scar);
        }

        static void hanako_scars() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_scars);
        }

        static void hanako_bed() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_bed_boobs_blush);
            show_bg(background_metas::hanako_bed_boobs_glance);
            show_bg(background_metas::hanako_bed_crotch_blush);
            show_bg(background_metas::hanako_bed_crotch_glance);
        }

        // Page 3
        static void hanako_missionary() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_missionary_underwear);
            show_bg(background_metas::hanako_missionary_open);
            show_bg(background_metas::hanako_missionary_closed);
            show_bg(background_metas::hanako_missionary_clench);
        }

        static void hanako_after() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_after_worry);
            show_bg(background_metas::hanako_after_smile);
        }

        static void hanako_park() {
            prepare_scene_manager();
            show_bg(background_metas::hanako_park_alone);
            show_bg(background_metas::hanako_park_away);
            show_bg(background_metas::hanako_park_look);
            show_bg(background_metas::hanako_park_closed);
        }

        static void hanako_goodend() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            // TODO: Check if we want to include this image
            // show_bg(background_metas::hanako_goodend_close);
            //
            show_bg(background_metas::hanako_goodend);
            show_bg(background_metas::hanako_goodend_muffin);
        }

        static void lilly_tearoom() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_tearoom);
            show_bg(background_metas::lilly_tearoom_open);
        }

        static void lilly_touch() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_touch_uni);
            show_bg(background_metas::lilly_touch_cheong);
            show_bg(background_metas::lilly_touch_cas);
        }

        static void lilly_crane() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_crane);
        }

        static void lilly_bedroom() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_bedroom);
        }

        static void lilly_hanako_hug() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::lilly_hanako_hug);
        }

        static void lilly_sleeping() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_sleeping);
            show_bg(background_metas::lilly_sleeping_smile);
        }

        static void lilly_trainride() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_trainride_smiles);
            show_bg(background_metas::lilly_trainride_ni);
        }

        static void lilly_wheat() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_wheat_small);
        }

        // Page 4
        static void lilly_handjob() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hcg_handjob_chest_frown);
            show_bg(background_metas::lilly_hcg_handjob_chest_normal);
            show_bg(background_metas::lilly_hcg_handjob_stroke_flustopen_small);
            show_bg(background_metas::lilly_hcg_handjob_stroke_normopen_small);
            show_bg(background_metas::lilly_hcg_handjob_stroke_normshut_small);
        }

        static void lilly_cowgirl() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hcg_cowgirl_cry_small);
            show_bg(background_metas::lilly_hcg_cowgirl_frown_small);
            show_bg(background_metas::lilly_hcg_cowgirl_smile_small);
            show_bg(background_metas::lilly_hcg_cowgirl_strain_small);
            show_bg(background_metas::lilly_hcg_cowgirl_weaksmile_small);
        }

        static void lilly_bath() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hcg_bath_emb_small);
            show_bg(background_metas::lilly_hcg_bath_grab_small);
            show_bg(background_metas::lilly_hcg_bath_moan_small);
            show_bg(background_metas::lilly_hcg_bath_open_small);
            show_bg(background_metas::lilly_hcg_bath_smile_small);
        }

        static void lilly_afterbath() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hcg_afterbath_open_small);
            show_bg(background_metas::lilly_hcg_afterbath_shut_small);
        }

        static void lilly_kissing() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_kissing);
        }

        static void lilly_masturbate() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_masturbate);
            show_bg(background_metas::lilly_masturbate_come);
            show_bg(background_metas::lilly_masturbate_come_face);
        }

        static void lilly_restaurant() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_restaurant_listen);
            show_bg(background_metas::lilly_restaurant_sheepish);
            show_bg(background_metas::lilly_restaurant_eat);
            show_bg(background_metas::lilly_restaurant_chew);
            show_bg(background_metas::lilly_restaurant_wine);
        }

        static void lilly_sheets() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_sheets);
        }

        static void lilly_airport() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_airport);
            show_bg(background_metas::lilly_airport_end);
        }

        static void lilly_hospitalwindow() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hospitalwindow);
        }

        static void lilly_hospital() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_hospitalclosed);
            show_bg(background_metas::lilly_hospital);
        }

        static void lilly_goodend() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::lilly_goodend);
        }

        // Page 5
        static void rin_eating() {
            prepare_scene_manager();
            show_bg(background_metas::rin_eating);
        }

        static void rin_artclass() {
            prepare_scene_manager();
            show_bg(background_metas::rin_artclass1);
            show_bg(background_metas::rin_artclass2);
            show_bg(background_metas::rin_artclass3);
            show_bg(background_metas::rin_artclass4);
        }

        static void hisao_mirror() {
            prepare_scene_manager();
            show_bg(background_metas::hisao_mirror);
        }

        static void rin_painting() {
            prepare_scene_manager();
            show_bg(background_metas::rin_painting_base);
            show_bg(background_metas::rin_painting_foot);
            show_bg(background_metas::rin_painting_faceconcerned);
            show_bg(background_metas::rin_painting_concerned);
            show_bg(background_metas::rin_painting_reply);
        }

        static void rin_rain() {
            prepare_scene_manager();
            show_bg(background_metas::rin_rain_away);
            show_bg(background_metas::rin_rain_towards);
        }

        static void rin_high() {
            prepare_scene_manager();
            show_bg(background_metas::rin_high_frown);
            show_bg(background_metas::rin_high_grin);
            show_bg(background_metas::rin_high_grinwide);
            show_bg(background_metas::rin_high_oneeye);
            show_bg(background_metas::rin_high_open);
            show_bg(background_metas::rin_high_smile);
            show_bg(background_metas::rin_high_sleep);
        }

        static void rin_kiss() {
            prepare_scene_manager();
            show_bg(background_metas::rin_kiss);
        }

        static void rin_nap() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::rin_nap_total, DISPLAYABLE_BITMASK_RIN_NAP_TOTAL);
            show_bg(background_metas::rin_nap_total_wind, DISPLAYABLE_BITMASK_RIN_NAP_TOTAL_AWIND);
            show_bg(background_metas::rin_nap_close_wind, DISPLAYABLE_BITMASK_RIN_NAP_CLOSE_AWIND);
            show_bg(background_metas::rin_nap_close_tears, DISPLAYABLE_BITMASK_RIN_NAP_CLOSE_AWIND_TEARS);
        }

        static void rin_wisp() {
            prepare_scene_manager();
            show_bg(background_metas::rin_wisp1);
            show_bg(background_metas::rin_wisp2);
            show_bg(background_metas::rin_wisp3);
            show_bg(background_metas::rin_wisp4);
            show_bg(background_metas::rin_wisp5);
        }

        static void rin_galleryskylight() {
            prepare_scene_manager();
            show_bg(background_metas::rin_galleryskylight);
        }

        static void rin_orange() {
            prepare_scene_manager();
            show_bg(background_metas::rin_orange);
            show_bg(background_metas::rin_orange_large);
        }

        static void rin_masturbate() {
            // TODO: resize, or implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::rin_masturbate_away);
            show_bg(background_metas::rin_masturbate_surprise);
            show_bg(background_metas::rin_masturbate_frown);
            show_bg(background_metas::rin_masturbate_doubt);
            show_bg(background_metas::rin_masturbate_hug);
        }

        // Page 6
        static void rin_relief() {
            prepare_scene_manager();
            show_bg(background_metas::rin_relief_down);
            show_bg(background_metas::rin_relief_up);
        }

        static void rin_gallery() {
            prepare_scene_manager();
            show_bg(background_metas::rin_gallery);
        }

        static void rin_trueend() {
            // TODO: implement via CustomEvent
            not_implemented();
        }

        static void rin_wet() {
            // TODO: implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::rin_wet_pan_down);
            show_bg(background_metas::rin_wet_arms);
            show_bg(background_metas::rin_wet_face_up);
            show_bg(background_metas::rin_wet_face_down);
            show_bg(background_metas::rin_wet_towel_up);
            show_bg(background_metas::rin_wet_towel_down);
            show_bg(background_metas::rin_wet_towel_touch);
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
            show_bg(background_metas::shizu_shanghai_borednormal);
            show_bg(background_metas::shizu_shanghai_smirknormal);
            show_bg(background_metas::shizu_shanghai_smirklaugh);
        }

        static void showdown() {
            prepare_scene_manager();
            show_bg(background_metas::lilly_shizu_showdown);
        }

        static void shizu_chess() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_chess_base);
            show_bg(background_metas::shizu_chess_base3);
            show_bg(background_metas::shizu_chess_base2);
        }

        static void kenji_glasses() {
            not_implemented();
        }

        // Page 7
        static void shizu_tanabata() {
            prepare_scene_manager();
            show_bg(background_metas::shizutanabata);
        }

        static void shizu_confess() {
            prepare_scene_manager();
            show_bg(background_metas::shizuconfess_normal);
            show_bg(background_metas::shizuconfess_closed);
            show_bg(background_metas::shizuconfess_smile);
        }

        static void shizu_hands() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_hands);
        }

        static void shizu_couch() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_couch);
        }

        static void shizune_car() {
            prepare_scene_manager();
            show_bg(background_metas::shizune_car);
        }

        static void shizu_fishing() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_fishing_ah);
            show_bg(background_metas::shizu_fishing_sl);
        }

        static void shizune_tied() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::shizune_hcg_tied_blush_small);
            show_bg(background_metas::shizune_hcg_tied_smile_small);
            show_bg(background_metas::shizune_hcg_tied_stare_small);
            show_bg(background_metas::shizune_hcg_tied_close_small);
            show_bg(background_metas::shizune_hcg_tied_kinky1_small);
            show_bg(background_metas::shizune_hcg_tied_kinky2_small);
            show_bg(background_metas::shizune_hcg_tied_kinky3_small);
            show_bg(background_metas::shizune_hcg_tied_hisao2_small);
        }

        static void misha_sad() {
            prepare_scene_manager();
            show_bg(background_metas::misha_sad);
        }
        static void misha_naked() {
            prepare_scene_manager();
            show_bg(background_metas::misha_naked);
        }

        static void misha_sex() {
            prepare_scene_manager();
            show_bg(background_metas::misha_sex_aside);
            show_bg(background_metas::misha_sex_closed);
        }

        static void misha_roof() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::misha_roof_closed);
            show_bg(background_metas::misha_roof_angry);
            show_bg(background_metas::misha_roof_normal);
            show_bg(background_metas::misha_roof_sad);
        }

        static void shizu_roof() {
            not_implemented();
        }

        // Page 8
        static void shizu_flashback() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_flashback);
        }

        static void shizu_undressing() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_undressing_clothed_stare);
            show_bg(background_metas::shizu_undressing_clothed_kiss);
            show_bg(background_metas::shizu_undressing_clothed_blush);
            show_bg(background_metas::shizu_undressing_unclothed_blush);
            show_bg(background_metas::shizu_undressing_unclothed_closed);
            show_bg(background_metas::shizu_undressing_unclothed_kiss);
            show_bg(background_metas::shizu_undressing_unclothed_talk);
        }

        static void shizu_pushdown() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_pushdown);
        }

        static void shizu_straddle() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::shizu_straddle_open);
            show_bg(background_metas::shizu_straddle_tease);
            show_bg(background_metas::shizu_straddle_closed);
            show_bg(background_metas::shizu_straddle_smile);
            show_bg(background_metas::shizu_straddle_come);
        }

        static void shizu_table() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_table_smile);
            show_bg(background_metas::shizu_table_normal);
            show_bg(background_metas::shizu_table_comeopen);
            show_bg(background_metas::shizu_table_comeclosed);
        }

        static void misha_nightclass() {
            prepare_scene_manager();
            show_bg(background_metas::misha_nightclass);
        }

        static void shizu_badend() {
            prepare_scene_manager();
            show_bg(background_metas::shizu_badend);
        }

        static void shizu_goodend() {
            // TODO: Implement via CustomEvent
            prepare_scene_manager();
            show_bg(background_metas::shizu_goodend);
        }

        static void cutin() {
            prepare_scene_manager();

            show_vfx(vfx_metas::pills);
            show_vfx(vfx_metas::stuffedcat);
            show_vfx(vfx_metas::teaset);
            show_vfx(vfx_metas::shangpai);
            show_vfx(vfx_metas::wine);
            show_vfx(vfx_metas::musicbox_closed);
            show_vfx(vfx_metas::musicbox_open);
            show_vfx(vfx_metas::hanaphone);
            show_vfx(vfx_metas::phonestrap);
            show_vfx(vfx_metas::hanaphonestrap);
            show_vfx(vfx_metas::startpistol);
            show_vfx(vfx_metas::invite);
            show_vfx(vfx_metas::sc_comp);
            show_vfx(vfx_metas::brailler);
            show_vfx(vfx_metas::chessboard);
            show_vfx(vfx_metas::kenjibox);
            show_vfx(vfx_metas::jigorocard);
            show_vfx(vfx_metas::letter_insert);
            show_vfx(vfx_metas::letter_open_insert);
            show_vfx(vfx_metas::letter_open_insert_2);
            show_vfx(vfx_metas::stallphoto_insert);
        }

        static void completionbonus() {
            prepare_scene_manager();
            show_bg(background_metas::completionbonus);
        }

    }

    const gallery_image images_0[12] = {
        gallery_image(DISPLAYABLE_BITMASK_OTHER_IWANAKO_START, &background_metas::other_iwanako, gallery_script::other_iwanako),
        gallery_image(DISPLAYABLE_BITMASK_HISAO_CLASS_START, &background_metas::hisao_class, gallery_script::hisao_class),
        gallery_image(DISPLAYABLE_BITMASK_KENJI_ROOFTOP, &background_metas::kenji_rooftop, gallery_script::kenji_rooftop),
        gallery_image(DISPLAYABLE_BITMASK_HISAO_TEACUP, &background_metas::hisao_teacup, gallery_script::hisao_teacup),
        gallery_image(DISPLAYABLE_BITMASK_HISAO_LETTER_CLOSED, &background_metas::hisao_letter_closed, gallery_script::hisao_letter),
        gallery_image(DISPLAYABLE_BITMASK_AKIRA_PARK, &background_metas::akira_park, gallery_script::akira_park),
        gallery_image(DISPLAYABLE_BITMASK_EMI_KNOCKEDDOWN, &background_metas::emi_knockeddown, gallery_script::emi_knockeddown),
        gallery_image(DISPLAYABLE_BITMASK_EMI_RUN_FACE, &background_metas::emi_run_face, gallery_script::emi_run_face),
        gallery_image(DISPLAYABLE_BITMASK_EMITRACK_BLOCKS, &background_metas::emitrack_blocks, gallery_script::emitrack_blocks),
        gallery_image(DISPLAYABLE_BITMASK_EMITRACK_RUNNING, &background_metas::emitrack_running, gallery_script::emitrack_running),
        gallery_image(DISPLAYABLE_BITMASK_EMITRACK_FINISHTOP, &background_metas::emitrack_finishtop, gallery_script::emitrack_finishtop),
        gallery_image(DISPLAYABLE_BITMASK_EMITRACK_FINISH, &background_metas::emitrack_finish, gallery_script::emitrack_finish),
    };

    const gallery_image images_1[12] = {
        gallery_image(DISPLAYABLE_BITMASK_PICNIC_NORMAL, &background_metas::picnic_normal, gallery_script::picnic),
        gallery_image(DISPLAYABLE_BITMASK_EMI_SLEEP_UNSURE, &background_metas::emi_sleep_unsure, gallery_script::emi_sleep),
        gallery_image(DISPLAYABLE_BITMASK_EMI_SLEEPY, &background_metas::emi_sleepy, gallery_script::emi_sleepy),
        gallery_image(DISPLAYABLE_BITMASK_EMI_FIRSTKISS, &background_metas::emi_firstkiss, gallery_script::emi_firstkiss),
        gallery_image(DISPLAYABLE_BITMASK_EMI_BED_NORMAL, &background_metas::emi_bed_normal, gallery_script::emi_bed),
        gallery_image(DISPLAYABLE_BITMASK_EMI_FOREHEAD, &background_metas::emi_forehead, gallery_script::emi_forehead),
        gallery_image(DISPLAYABLE_BITMASK_EMI_GRINDING_VICTORY, &background_metas::emi_grinding_victory, gallery_script::emi_grinding),
        gallery_image(DISPLAYABLE_BITMASK_EMI_SHED_BASE1, &background_metas::emi_shed_base1, gallery_script::emi_shed),
        gallery_image(DISPLAYABLE_BITMASK_EMI_GRAVE, &background_metas::emi_grave, gallery_script::emi_grave),
        gallery_image(DISPLAYABLE_BITMASK_EMI_CRY_DOWN, &background_metas::emi_cry_down, gallery_script::emi_cry_down),
        gallery_image(DISPLAYABLE_BITMASK_EMI_MISS_CLOSED, &background_metas::emi_miss_closed, gallery_script::emi_miss),
        gallery_image(DISPLAYABLE_BITMASK_EMI_ENDING_SMILE, &background_metas::emi_ending_smile, gallery_script::emi_ending),
    };

    const gallery_image images_2[12] = {
        gallery_image(DISPLAYABLE_BITMASK_HANA_LIBRARY, &background_metas::hana_library, gallery_script::hana_library),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_SHANGHAIWINDOW, &background_metas::hanako_fw_base, gallery_script::hanako_shanghaiwindow),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_PRESENTS1, &background_metas::hanako_presents1, gallery_script::hanako_presents1),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_CRAYON1, &background_metas::hanako_crayon1, gallery_script::hanako_crayon),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_BREAKDOWN, &background_metas::hanako_breakdown_bg, gallery_script::hanako_breakdown), // TODO: thumbnail, script, bitmask
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_CRY_CLOSED, &background_metas::hanako_cry_closed, gallery_script::hanako_cry),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_BILLIARDS_BREAK, &background_metas::hanako_billiards_break, gallery_script::hanako_billiards),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_EMPTYCLASSROOM, &background_metas::hanako_emptyclassroom_bg, gallery_script::hanako_emptyclassroom), // TODO: thumbnail, script, bitmask
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_RAGE, &background_metas::hanako_rage, gallery_script::hanako_rage),
        gallery_image(DISPLAYABLE_BITMASK_HISAO_SCAR, &background_metas::hisao_scar, gallery_script::hisao_scar),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_SCARS, &background_metas::hanako_scars, gallery_script::hanako_scars),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_BED_BOOBS_BLUSH, &background_metas::hanako_bed_boobs_blush, gallery_script::hanako_bed),
    };

    const gallery_image images_3[12] = {
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_MISSIONARY_UNDERWEAR, &background_metas::hanako_missionary_underwear, gallery_script::hanako_missionary),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_AFTER_WORRY, &background_metas::hanako_after_worry, gallery_script::hanako_after),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_PARK_ALONE, &background_metas::hanako_park_alone, gallery_script::hanako_park),
        gallery_image(DISPLAYABLE_BITMASK_HANAKO_GOODEND, &background_metas::hanako_goodend, gallery_script::hanako_goodend),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_TEAROOM, &background_metas::lilly_tearoom, gallery_script::lilly_tearoom),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_TOUCH_UNI, &background_metas::lilly_touch_uni, gallery_script::lilly_touch),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_CRANE, &background_metas::lilly_crane, gallery_script::lilly_crane),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_BEDROOM, &background_metas::lilly_bedroom, gallery_script::lilly_bedroom),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_HANAKO_HUG, &background_metas::lilly_hanako_hug, gallery_script::lilly_hanako_hug),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_SLEEPING, &background_metas::lilly_sleeping, gallery_script::lilly_sleeping),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_TRAINRIDE_SMILES, &background_metas::lilly_trainride_smiles, gallery_script::lilly_trainride),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_WHEAT_SMALL, &background_metas::lilly_wheat_small, gallery_script::lilly_wheat),
    };

    const gallery_image images_4[12] = {
        gallery_image(DISPLAYABLE_BITMASK_LILLY_HANDJOB_CHEST_FROWN_SMALL, &background_metas::lilly_hcg_handjob_chest_frown, gallery_script::lilly_handjob), // TODO: event, bitmask
        gallery_image(DISPLAYABLE_BITMASK_LILLY_COWGIRL_CRY_SMALL, &background_metas::lilly_hcg_cowgirl_cry_small, gallery_script::lilly_cowgirl), // TODO: event, bitmask
        gallery_image(DISPLAYABLE_BITMASK_LILLY_BATH_EMB_SMALL, &background_metas::lilly_hcg_bath_emb_small, gallery_script::lilly_bath), // TODO: event, bitmask
        gallery_image(DISPLAYABLE_BITMASK_LILLY_AFTERBATH_OPEN_SMALL, &background_metas::lilly_hcg_afterbath_open_small, gallery_script::lilly_afterbath), // TODO: event, bitmask
        gallery_image(DISPLAYABLE_BITMASK_LILLY_KISSING, &background_metas::lilly_kissing, gallery_script::lilly_kissing),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_MASTURBATE, &background_metas::lilly_masturbate, gallery_script::lilly_masturbate),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_RESTAURANT_LISTEN, &background_metas::lilly_restaurant_listen, gallery_script::lilly_restaurant),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_SHEETS, &background_metas::lilly_sheets, gallery_script::lilly_sheets),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_AIRPORT, &background_metas::lilly_airport, gallery_script::lilly_airport),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_HOSPITALWINDOW, &background_metas::lilly_hospitalwindow, gallery_script::lilly_hospitalwindow),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_HOSPITALCLOSED, &background_metas::lilly_hospitalclosed, gallery_script::lilly_hospital),
        gallery_image(DISPLAYABLE_BITMASK_LILLY_GOODEND, &background_metas::lilly_goodend, gallery_script::lilly_goodend),
    };

    const gallery_image images_5[12] = {
        gallery_image(DISPLAYABLE_BITMASK_RIN_EATING, &background_metas::rin_eating, gallery_script::rin_eating),
        gallery_image(DISPLAYABLE_BITMASK_RIN_ARTCLASS1, &background_metas::rin_artclass1, gallery_script::rin_artclass),
        gallery_image(DISPLAYABLE_BITMASK_HISAO_MIRROR, &background_metas::hisao_mirror, gallery_script::hisao_mirror),
        gallery_image(DISPLAYABLE_BITMASK_RIN_PAINTING_BASE, &background_metas::rin_painting_base, gallery_script::rin_painting),
        gallery_image(DISPLAYABLE_BITMASK_RIN_RAIN_AWAY, &background_metas::rin_rain_away, gallery_script::rin_rain),
        gallery_image(DISPLAYABLE_BITMASK_RIN_HIGH_FROWN, &background_metas::rin_high_frown, gallery_script::rin_high),
        gallery_image(DISPLAYABLE_BITMASK_RIN_KISS, &background_metas::rin_kiss, gallery_script::rin_kiss),
        gallery_image(DISPLAYABLE_BITMASK_RIN_NAP_TOTAL, &background_metas::rin_nap_total, gallery_script::rin_nap),
        gallery_image(DISPLAYABLE_BITMASK_RIN_WISP1, &background_metas::rin_wisp1, gallery_script::rin_wisp),
        gallery_image(DISPLAYABLE_BITMASK_RIN_GALLERYSKYLIGHT, &background_metas::rin_galleryskylight, gallery_script::rin_galleryskylight),
        gallery_image(DISPLAYABLE_BITMASK_RIN_ORANGE, &background_metas::rin_orange, gallery_script::rin_orange),
        gallery_image(DISPLAYABLE_BITMASK_RIN_MASTURBATE_AWAY, &background_metas::rin_masturbate_away, gallery_script::rin_masturbate),
    };

    const gallery_image images_6[12] = {
        gallery_image(DISPLAYABLE_BITMASK_RIN_RELIEF_DOWN, &background_metas::rin_relief_down, gallery_script::rin_relief),
        gallery_image(DISPLAYABLE_BITMASK_RIN_GALLERY, &background_metas::rin_gallery, gallery_script::rin_gallery),
        gallery_image(DISPLAYABLE_BITMASK_RIN_TRUEEND_NORMAL, &background_metas::rin_trueend_normal, gallery_script::rin_trueend),
        gallery_image(DISPLAYABLE_BITMASK_RIN_WET_PAN_DOWN, &background_metas::rin_wet_pan_down, gallery_script::rin_wet), // TODO: implement via CustomEvent
        gallery_image(DISPLAYABLE_BITMASK_RIN_H2_PAN_SURPRISE, &background_metas::rin_h2_l_pan, gallery_script::rin_h2), // TODO: thumbnail, script, bitmask
        gallery_image(DISPLAYABLE_BITMASK_RIN_PAIR_BASE, &background_metas::rin_pair_base, gallery_script::rin_pair), // TODO: thumbnail, script
        gallery_image(DISPLAYABLE_BITMASK_RIN_H_CLOSED, &background_metas::rin_h_closed, gallery_script::rin_h), // TODO: thumbnail, script
        gallery_image(DISPLAYABLE_BITMASK_RIN_GOODEND_1, &background_metas::rin_goodend_base, gallery_script::rin_goodend), // TODO: thumbnail, script, bitmask
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_SHANGHAI, &background_metas::shizu_shanghai, gallery_script::shizu_shanghai),
        gallery_image(DISPLAYABLE_BITMASK_SHOWDOWN, &background_metas::lilly_shizu_showdown, gallery_script::showdown),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_CHESS_BASE, &background_metas::shizu_chess_base, gallery_script::shizu_chess),
        gallery_image(DISPLAYABLE_BITMASK_KENJI_GLASSES_CLOSED, &background_metas::kenji_glasses_bg, gallery_script::kenji_glasses), // TODO: thumbnail, script, bitmask

    };

    const gallery_image images_7[12] = {
        gallery_image(DISPLAYABLE_BITMASK_SHIZUTANABATA, &background_metas::shizutanabata, gallery_script::shizu_tanabata),
        gallery_image(DISPLAYABLE_BITMASK_SHIZUCONFESS_NORMAL, &background_metas::shizuconfess_normal, gallery_script::shizu_confess),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_HANDS, &background_metas::shizu_hands, gallery_script::shizu_hands),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_COUCH, &background_metas::shizu_couch, gallery_script::shizu_couch),
        gallery_image(DISPLAYABLE_BITMASK_SHIZUNE_CAR, &background_metas::shizune_car, gallery_script::shizune_car),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_FISHING_AH, &background_metas::shizu_fishing_ah, gallery_script::shizu_fishing),
        gallery_image(DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_BLUSH_SMALL, &background_metas::shizune_hcg_tied_blush_small, gallery_script::shizune_tied),
        gallery_image(DISPLAYABLE_BITMASK_MISHA_SAD, &background_metas::misha_sad, gallery_script::misha_sad),
        gallery_image(DISPLAYABLE_BITMASK_MISHA_NAKED, &background_metas::misha_naked, gallery_script::misha_naked),
        gallery_image(DISPLAYABLE_BITMASK_MISHA_SEX_ASIDE, &background_metas::misha_sex_aside, gallery_script::misha_sex),
        gallery_image(DISPLAYABLE_BITMASK_MISHA_ROOF_CLOSED, &background_metas::misha_roof_closed, gallery_script::misha_roof),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_ROOF, &background_metas::shizu_roof, gallery_script::shizu_roof), // TODO: thumbnail, script
    };

    const gallery_image images_8[10] = {
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_FLASHBACK, &background_metas::shizu_flashback, gallery_script::shizu_flashback),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_STARE, &background_metas::shizu_undressing_clothed_stare, gallery_script::shizu_undressing),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_PUSHDOWN, &background_metas::shizu_pushdown, gallery_script::shizu_pushdown),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_STRADDLE_OPEN, &background_metas::shizu_straddle_open, gallery_script::shizu_straddle),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_TABLE_SMILE, &background_metas::shizu_table_smile, gallery_script::shizu_table),
        gallery_image(DISPLAYABLE_BITMASK_MISHA_NIGHTCLASS, &background_metas::misha_nightclass, gallery_script::misha_nightclass),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_BADEND, &background_metas::shizu_badend, gallery_script::shizu_badend),
        gallery_image(DISPLAYABLE_BITMASK_SHIZU_GOODEND, &background_metas::shizu_goodend, gallery_script::shizu_goodend),
        gallery_image(DISPLAYABLE_BITMASK_NONE, &background_metas::event_missing, gallery_script::cutin, true),
        gallery_image(DISPLAYABLE_BITMASK_COMPLETIONBONUS, &background_metas::completionbonus, gallery_script::completionbonus),
    };

    const gallery_image images_null[1] = {
        gallery_image(DISPLAYABLE_BITMASK_NONE, nullptr, gallery_script::not_implemented)
    };
}