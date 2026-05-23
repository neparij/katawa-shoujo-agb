#ifndef CUSTOM_BACKGROUND_METAS_H
#define CUSTOM_BACKGROUND_METAS_H


#include <bn_regular_bg_items_kslogo_heart.h>
#include <bn_regular_bg_items_kslogo_words.h>

#include "event_missing.h"
#include "bn_regular_bg_items_hisao_class.h"
#include "bn_regular_bg_items_thumb_hisao_class.h"
#include "bn_regular_bg_items_emi_knockeddown_largepullout.h"
#include "bn_regular_bg_items_thumb_emi_knockeddown.h"
#include "bn_regular_bg_items_emi_knockeddown_facepullout.h"
#include "bn_regular_bg_items_emi_knockeddown_legs.h"
#include "bn_regular_bg_items_hanako_fw_base.h"
#include "bn_regular_bg_items_hosp_room.h"
#include "ks_huge_bg_items_event_drugs.h"
#include "bn_regular_bg_items_thumb_event_drugs.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_slices_lilly.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_slices_shizu.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_both.h"
#include "bn_regular_bg_items_op_snowywoods.h"
#include "bn_regular_bg_items_other_iwanako.h"
#include "bn_regular_bg_items_other_iwanako_nosnow.h"
#include "bn_regular_bg_items_thumb_hanako_fw_flash.h"
#include "bn_regular_bg_items_thumb_hosp_room.h"
#include "bn_regular_bg_items_thumb_lilly_shizu_showdown.h"
#include "bn_regular_bg_items_thumb_op_snowywoods.h"
#include "bn_regular_bg_items_thumb_other_iwanako.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_thumb_rin_wet.h"
#include "bn_regular_bg_items_thumb_rin_h.h"
#include "bn_regular_bg_items_thumb_rin_h2.h"
#include "bn_regular_bg_items_thumb_rin_goodend.h"
#include "bn_regular_bg_items_thumb_rin_pair.h"
#include "bn_regular_bg_items_thumb_emi_sleep.h"
#include "bn_regular_bg_items_thumb_picnic.h"
#include "bn_regular_bg_items_thumb_hana_library.h"
#include "bn_regular_bg_items_thumb_shizu_shanghai.h"
#include "bn_regular_bg_items_thumb_shizu_undressing.h"
#include "bn_regular_bg_items_thumb_shizu_straddle.h"
#include "bn_regular_bg_items_thumb_shizu_table.h"
#include "bn_regular_bg_items_thumb_shizune_tied.h"

// TODO: add before-compile tool to generate unique hashes for each background
// How to calculate hash:
// Use MD5 hash of the background name and take first 8 digits.
// Example: hisao_class -> 506DE7CF
// Bash oneliner: echo -en "hisao_class" | md5 | awk '{print $1}' | cut -c1-8 | tr '[:lower:]' '[:upper:]' | sed 's/^/0x/'

namespace ks::background_metas {
    constexpr inline background_meta hisao_class(
        bn::regular_bg_items::hisao_class,
        bn::regular_bg_items::thumb_hisao_class,
        DISPLAYABLE_BITMASK_HISAO_CLASS_START,
        0xFFFF0000);

    constexpr inline background_meta emi_knockeddown(
        bn::regular_bg_items::emi_knockeddown_largepullout,
        bn::regular_bg_items::thumb_emi_knockeddown,
        DISPLAYABLE_BITMASK_EMI_KNOCKEDDOWN,
        0xFFFF0001);

    constexpr inline background_meta emi_knockeddown_facepullout(
        bn::regular_bg_items::emi_knockeddown_facepullout,
        bn::regular_bg_items::thumb_emi_knockeddown,
        DISPLAYABLE_BITMASK_EMI_KNOCKEDDOWN,
        0xFFFF0002);

    constexpr inline background_meta emi_knockeddown_largepullout(
        bn::regular_bg_items::emi_knockeddown_largepullout,
        bn::regular_bg_items::thumb_emi_knockeddown,
        DISPLAYABLE_BITMASK_EMI_KNOCKEDDOWN,
        0xFFFF0003);

    constexpr inline background_meta emi_knockeddown_legs(
        bn::regular_bg_items::emi_knockeddown_legs,
        bn::regular_bg_items::thumb_emi_knockeddown,
        DISPLAYABLE_BITMASK_EMI_KNOCKEDDOWN,
        0xFFFF0004);

    constexpr inline background_meta lilly_shizu_showdown_slices_lilly(
        bn::regular_bg_items::lilly_shizu_showdown_slices_lilly,
        bn::regular_bg_items::thumb_lilly_shizu_showdown,
        DISPLAYABLE_BITMASK_SHOWDOWN,
        0xFFFF0005);

    constexpr inline background_meta lilly_shizu_showdown_slices_shizu(
        bn::regular_bg_items::lilly_shizu_showdown_slices_shizu,
        bn::regular_bg_items::thumb_lilly_shizu_showdown,
        DISPLAYABLE_BITMASK_SHOWDOWN,
        0xFFFF0006);

    constexpr inline background_meta lilly_shizu_showdown_both(
        bn::regular_bg_items::lilly_shizu_showdown_both,
        bn::regular_bg_items::thumb_lilly_shizu_showdown,
        DISPLAYABLE_BITMASK_SHOWDOWN,
        0xFFFF0007);

    constexpr inline huge_background_meta event_drugs(
        ks::huge_bg_items::event_drugs,
        bn::regular_bg_items::thumb_event_drugs,
        DISPLAYABLE_BITMASK_NONE,
        0xFFFF0008);

    constexpr inline background_meta op_snowywoods(
        bn::regular_bg_items::op_snowywoods,
        bn::regular_bg_items::thumb_op_snowywoods,
        DISPLAYABLE_BITMASK_NONE,
        0xFFFF0009);

    constexpr inline background_meta other_iwanako(
        bn::regular_bg_items::other_iwanako_nosnow,
        bn::regular_bg_items::thumb_other_iwanako,
        DISPLAYABLE_BITMASK_OTHER_IWANAKO_START,
        0xFFFF000A);

    constexpr inline background_meta hosp_room(
                 bn::regular_bg_items::hosp_room,
                 bn::regular_bg_items::thumb_hosp_room,
                 DISPLAYABLE_BITMASK_NONE,
                 0x3E47FD6A);

    constexpr inline background_meta hanako_fw_base(
                bn::regular_bg_items::hanako_fw_base,
                bn::regular_bg_items::thumb_hanako_fw_flash,
                DISPLAYABLE_BITMASK_HANAKO_SHANGHAIWINDOW,
                0xE13A5821);

    constexpr inline background_meta kslogo_heart(
        bn::regular_bg_items::kslogo_heart,
        bn::regular_bg_items::thumb_event_missing,
        DISPLAYABLE_BITMASK_NONE,
        0x0FFFFF00);

    constexpr inline background_meta kslogo_words(
        bn::regular_bg_items::kslogo_words,
        bn::regular_bg_items::thumb_event_missing,
        DISPLAYABLE_BITMASK_NONE,
        0x0FFFFF01);

    // composite_huge at runtime; thumb-only for gallery/saves.
    constexpr inline background_meta rin_wet_pan_down(
        bn::regular_bg_items::thumb_rin_wet,
        bn::regular_bg_items::thumb_rin_wet,
        DISPLAYABLE_BITMASK_RIN_WET_PAN_DOWN,
        0x101E4A44);

    constexpr inline background_meta rin_wet_arms(
        bn::regular_bg_items::thumb_rin_wet,
        bn::regular_bg_items::thumb_rin_wet,
        DISPLAYABLE_BITMASK_RIN_WET_ARMS,
        0x7FBD8C8C);

    // composite at runtime; thumb-only for gallery/saves.
    constexpr inline background_meta rin_h_closed(
        bn::regular_bg_items::thumb_rin_h,
        bn::regular_bg_items::thumb_rin_h,
        DISPLAYABLE_BITMASK_RIN_H_CLOSED,
        0xD0FE448D);

    constexpr inline background_meta rin_h2_pan_surprise(
        bn::regular_bg_items::thumb_rin_h2,
        bn::regular_bg_items::thumb_rin_h2,
        DISPLAYABLE_BITMASK_RIN_H2_PAN_SURPRISE,
        0x6C60BF4A);

    constexpr inline background_meta rin_goodend_1(
        bn::regular_bg_items::thumb_rin_goodend,
        bn::regular_bg_items::thumb_rin_goodend,
        DISPLAYABLE_BITMASK_RIN_GOODEND_1,
        0x8AB58058);

    constexpr inline background_meta rin_pair_c_hn_rn(
        bn::regular_bg_items::thumb_rin_pair,
        bn::regular_bg_items::thumb_rin_pair,
        DISPLAYABLE_BITMASK_RIN_PAIR_BASE,
        0x0A6B4E80);

    // composite at runtime; thumb-only for gallery/saves.
    constexpr inline background_meta emi_sleep_unsure(
        bn::regular_bg_items::thumb_emi_sleep,
        bn::regular_bg_items::thumb_emi_sleep,
        DISPLAYABLE_BITMASK_EMI_SLEEP_UNSURE,
        0x09B2DDB8);

    constexpr inline background_meta emi_sleep_normal(
        bn::regular_bg_items::thumb_emi_sleep,
        bn::regular_bg_items::thumb_emi_sleep,
        DISPLAYABLE_BITMASK_EMI_SLEEP_NORMAL,
        0x4D12722B);

    constexpr inline background_meta emi_sleep_weep(
        bn::regular_bg_items::thumb_emi_sleep,
        bn::regular_bg_items::thumb_emi_sleep,
        DISPLAYABLE_BITMASK_EMI_SLEEP_WEEP,
        0xD9BD6EF2);

    constexpr inline background_meta emi_sleep_cry(
        bn::regular_bg_items::thumb_emi_sleep,
        bn::regular_bg_items::thumb_emi_sleep,
        DISPLAYABLE_BITMASK_EMI_SLEEP_CRY,
        0x515384F8);

    // composite at runtime; thumb-only for gallery/saves.
    constexpr inline background_meta picnic_normal(
        bn::regular_bg_items::thumb_picnic,
        bn::regular_bg_items::thumb_picnic,
        DISPLAYABLE_BITMASK_PICNIC_NORMAL,
        0xA4EF2B3D);

    constexpr inline background_meta picnic_rain(
        bn::regular_bg_items::thumb_picnic,
        bn::regular_bg_items::thumb_picnic,
        DISPLAYABLE_BITMASK_PICNIC_RAIN,
        0x49D3D12B);

    // composite at runtime; thumb-only for gallery/saves.
    constexpr inline background_meta hana_library_default(
        bn::regular_bg_items::thumb_hana_library,
        bn::regular_bg_items::thumb_hana_library,
        DISPLAYABLE_BITMASK_HANA_LIBRARY,
        0x092915A0);

    constexpr inline background_meta hana_library_read(
        bn::regular_bg_items::thumb_hana_library,
        bn::regular_bg_items::thumb_hana_library,
        DISPLAYABLE_BITMASK_HANA_LIBRARY_READ,
        0x3BADDF80);

    constexpr inline background_meta hana_library_gasp(
        bn::regular_bg_items::thumb_hana_library,
        bn::regular_bg_items::thumb_hana_library,
        DISPLAYABLE_BITMASK_HANA_LIBRARY_GASP,
        0xCF7F47FE);

    constexpr inline background_meta hana_library_smile(
        bn::regular_bg_items::thumb_hana_library,
        bn::regular_bg_items::thumb_hana_library,
        DISPLAYABLE_BITMASK_NONE,
        0x28FC69DE);

    // composite at runtime; thumb-only for gallery/saves.
    constexpr inline background_meta shizu_shanghai_default(
        bn::regular_bg_items::thumb_shizu_shanghai,
        bn::regular_bg_items::thumb_shizu_shanghai,
        DISPLAYABLE_BITMASK_SHIZU_SHANGHAI,
        0x9425AC62);

    constexpr inline background_meta shizu_shanghai_boredlaugh(
        bn::regular_bg_items::thumb_shizu_shanghai,
        bn::regular_bg_items::thumb_shizu_shanghai,
        DISPLAYABLE_BITMASK_NONE,
        0x8E491684);

    constexpr inline background_meta shizu_shanghai_borednormal(
        bn::regular_bg_items::thumb_shizu_shanghai,
        bn::regular_bg_items::thumb_shizu_shanghai,
        DISPLAYABLE_BITMASK_SHIZU_SHANGHAI_BOREDNORMAL,
        0xA2ABB1B8);

    constexpr inline background_meta shizu_shanghai_normallaugh(
        bn::regular_bg_items::thumb_shizu_shanghai,
        bn::regular_bg_items::thumb_shizu_shanghai,
        DISPLAYABLE_BITMASK_NONE,
        0xE24226CA);

    constexpr inline background_meta shizu_shanghai_smirklaugh(
        bn::regular_bg_items::thumb_shizu_shanghai,
        bn::regular_bg_items::thumb_shizu_shanghai,
        DISPLAYABLE_BITMASK_SHIZU_SHANGHAI_SMIRKLAUGH,
        0xE49E0B6C);

    constexpr inline background_meta shizu_shanghai_smirknormal(
        bn::regular_bg_items::thumb_shizu_shanghai,
        bn::regular_bg_items::thumb_shizu_shanghai,
        DISPLAYABLE_BITMASK_SHIZU_SHANGHAI_SMIRKNORMAL,
        0x0CFEBE5E);

    // composite at runtime; thumb-only for gallery/saves.
    constexpr inline background_meta shizu_undressing_clothed_stare(
        bn::regular_bg_items::thumb_shizu_undressing,
        bn::regular_bg_items::thumb_shizu_undressing,
        DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_STARE,
        0xC44FE6B4);

    constexpr inline background_meta shizu_undressing_clothed_kiss(
        bn::regular_bg_items::thumb_shizu_undressing,
        bn::regular_bg_items::thumb_shizu_undressing,
        DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_KISS,
        0xC4C2CC63);

    constexpr inline background_meta shizu_undressing_clothed_blush(
        bn::regular_bg_items::thumb_shizu_undressing,
        bn::regular_bg_items::thumb_shizu_undressing,
        DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_BLUSH,
        0x3A073DCC);

    constexpr inline background_meta shizu_undressing_unclothed_closed(
        bn::regular_bg_items::thumb_shizu_undressing,
        bn::regular_bg_items::thumb_shizu_undressing,
        DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_CLOSED,
        0x072E261D);

    constexpr inline background_meta shizu_undressing_unclothed_blush(
        bn::regular_bg_items::thumb_shizu_undressing,
        bn::regular_bg_items::thumb_shizu_undressing,
        DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_BLUSH,
        0x6EBB3CBA);

    constexpr inline background_meta shizu_undressing_unclothed_kiss(
        bn::regular_bg_items::thumb_shizu_undressing,
        bn::regular_bg_items::thumb_shizu_undressing,
        DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_KISS,
        0x1F3F9121);

    constexpr inline background_meta shizu_undressing_unclothed_talk(
        bn::regular_bg_items::thumb_shizu_undressing,
        bn::regular_bg_items::thumb_shizu_undressing,
        DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_TALK,
        0x497161B3);

    constexpr inline background_meta shizu_straddle_open(
        bn::regular_bg_items::thumb_shizu_straddle,
        bn::regular_bg_items::thumb_shizu_straddle,
        DISPLAYABLE_BITMASK_SHIZU_STRADDLE_OPEN,
        0x609E25BC);

    constexpr inline background_meta shizu_straddle_tease(
        bn::regular_bg_items::thumb_shizu_straddle,
        bn::regular_bg_items::thumb_shizu_straddle,
        DISPLAYABLE_BITMASK_SHIZU_STRADDLE_TEASE,
        0x9666EA8A);

    constexpr inline background_meta shizu_straddle_closed(
        bn::regular_bg_items::thumb_shizu_straddle,
        bn::regular_bg_items::thumb_shizu_straddle,
        DISPLAYABLE_BITMASK_SHIZU_STRADDLE_CLOSED,
        0x50DFADCB);

    constexpr inline background_meta shizu_straddle_smile(
        bn::regular_bg_items::thumb_shizu_straddle,
        bn::regular_bg_items::thumb_shizu_straddle,
        DISPLAYABLE_BITMASK_SHIZU_STRADDLE_SMILE,
        0xB6BB09FC);

    constexpr inline background_meta shizu_straddle_come(
        bn::regular_bg_items::thumb_shizu_straddle,
        bn::regular_bg_items::thumb_shizu_straddle,
        DISPLAYABLE_BITMASK_SHIZU_STRADDLE_COME,
        0xEC59D299);

    constexpr inline background_meta shizu_table_smile(
        bn::regular_bg_items::thumb_shizu_table,
        bn::regular_bg_items::thumb_shizu_table,
        DISPLAYABLE_BITMASK_SHIZU_TABLE_SMILE,
        0x93E8189C);

    constexpr inline background_meta shizu_table_normal(
        bn::regular_bg_items::thumb_shizu_table,
        bn::regular_bg_items::thumb_shizu_table,
        DISPLAYABLE_BITMASK_SHIZU_TABLE_NORMAL,
        0x7A90048B);

    constexpr inline background_meta shizu_table_comeopen(
        bn::regular_bg_items::thumb_shizu_table,
        bn::regular_bg_items::thumb_shizu_table,
        DISPLAYABLE_BITMASK_SHIZU_TABLE_COMEOPEN,
        0x0EECAABD);

    constexpr inline background_meta shizu_table_comeclosed(
        bn::regular_bg_items::thumb_shizu_table,
        bn::regular_bg_items::thumb_shizu_table,
        DISPLAYABLE_BITMASK_SHIZU_TABLE_COMECLOSED,
        0x61A6CAD8);

    constexpr inline background_meta shizune_hcg_tied_blush(
        bn::regular_bg_items::thumb_shizune_tied,
        bn::regular_bg_items::thumb_shizune_tied,
        DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_BLUSH,
        0xB5D68A89);

    constexpr inline background_meta shizune_hcg_tied_smile(
        bn::regular_bg_items::thumb_shizune_tied,
        bn::regular_bg_items::thumb_shizune_tied,
        DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_SMILE,
        0xEA7DA516);

    constexpr inline background_meta shizune_hcg_tied_stare(
        bn::regular_bg_items::thumb_shizune_tied,
        bn::regular_bg_items::thumb_shizune_tied,
        DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_STARE,
        0x9D02A3DE);

    constexpr inline background_meta shizune_hcg_tied_close(
        bn::regular_bg_items::thumb_shizune_tied,
        bn::regular_bg_items::thumb_shizune_tied,
        DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_CLOSE,
        0xB0780A17);

    constexpr inline background_meta shizune_hcg_tied_kinky1(
        bn::regular_bg_items::thumb_shizune_tied,
        bn::regular_bg_items::thumb_shizune_tied,
        DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_KINKY1,
        0xEC815210);

    constexpr inline background_meta shizune_hcg_tied_kinky2(
        bn::regular_bg_items::thumb_shizune_tied,
        bn::regular_bg_items::thumb_shizune_tied,
        DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_KINKY2,
        0x0E394C83);

    constexpr inline background_meta shizune_hcg_tied_kinky3(
        bn::regular_bg_items::thumb_shizune_tied,
        bn::regular_bg_items::thumb_shizune_tied,
        DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_KINKY3,
        0xCAAA6F67);

    inline const bn::regular_bg_item& get_custom_thumbnail_by_hash(const unsigned int hash) {
        switch (hash) {
            case 0xFFFF0000: return hisao_class.thumbnail;
            case 0xFFFF0001: return emi_knockeddown.thumbnail;
            case 0xFFFF0002: return emi_knockeddown_facepullout.thumbnail;
            case 0xFFFF0003: return emi_knockeddown_largepullout.thumbnail;
            case 0xFFFF0004: return emi_knockeddown_legs.thumbnail;
            case 0xFFFF0005: return lilly_shizu_showdown_slices_lilly.thumbnail;
            case 0xFFFF0006: return lilly_shizu_showdown_slices_shizu.thumbnail;
            case 0xFFFF0007: return lilly_shizu_showdown_both.thumbnail;
            case 0xFFFF0008: return event_drugs.thumbnail;
            case 0xFFFF0009: return op_snowywoods.thumbnail;
            case 0xFFFF000A: return other_iwanako.thumbnail;
            case 0x3E47FD6A: return hosp_room.thumbnail;
            case 0xE13A5821: return hanako_fw_base.thumbnail;
            case 0x101E4A44: return rin_wet_pan_down.thumbnail;
            case 0x7FBD8C8C: return rin_wet_arms.thumbnail;
            case 0xD0FE448D: return rin_h_closed.thumbnail;
            case 0xB2A237FA: return bn::regular_bg_items::thumb_rin_h;
            case 0xB783FCC3: return bn::regular_bg_items::thumb_rin_h;
            case 0x823E033F: return bn::regular_bg_items::thumb_rin_h;
            case 0x9DFC70B0: return bn::regular_bg_items::thumb_rin_h;
            case 0x6D8C5931: return bn::regular_bg_items::thumb_rin_h;
            case 0xBE664BFD: return bn::regular_bg_items::thumb_rin_h;
            case 0x6BF21BE8: return bn::regular_bg_items::thumb_rin_h;
            case 0x2713A330: return bn::regular_bg_items::thumb_rin_h;
            case 0x21AACB6F: return bn::regular_bg_items::thumb_rin_h;
            case 0x6C60BF4A: return rin_h2_pan_surprise.thumbnail;
            case 0xCD24BD8F: return bn::regular_bg_items::thumb_rin_h2;
            case 0xD9351E8A: return bn::regular_bg_items::thumb_rin_h2;
            case 0xF16A04EE: return bn::regular_bg_items::thumb_rin_h2;
            case 0x0575DE92: return bn::regular_bg_items::thumb_rin_h2;
            case 0xA0104552: return bn::regular_bg_items::thumb_rin_h2;
            case 0x65D832D6: return bn::regular_bg_items::thumb_rin_h2;
            case 0x82D4A5C9: return rin_h2_pan_surprise.thumbnail;
            case 0x5CD67806: return bn::regular_bg_items::thumb_rin_h2;
            case 0xB4E12CFF: return rin_h2_pan_surprise.thumbnail;
            case 0x2AED8B87: return bn::regular_bg_items::thumb_rin_h2;
            case 0x05D3D33D: return bn::regular_bg_items::thumb_rin_h2;
            case 0x7DDB5F0A: return bn::regular_bg_items::thumb_rin_h2;
            case 0x8AB58058: return rin_goodend_1.thumbnail;
            case 0x6DFB6768: return bn::regular_bg_items::thumb_rin_goodend;
            case 0x222FA88A: return bn::regular_bg_items::thumb_rin_goodend;
            case 0xE3B01A2D: return rin_goodend_1.thumbnail;
            case 0xDFA80E3C: return rin_goodend_1.thumbnail;
            case 0xE65AAFD6: return bn::regular_bg_items::thumb_rin_goodend;
            case 0x0A6B4E80: return rin_pair_c_hn_rn.thumbnail;
            case 0x45BD3726: return bn::regular_bg_items::thumb_rin_pair;
            case 0xE0D94C23: return bn::regular_bg_items::thumb_rin_pair;
            case 0x6FC9B0B2: return bn::regular_bg_items::thumb_rin_pair;
            case 0xA7C033CC: return bn::regular_bg_items::thumb_rin_pair;
            case 0x4F9D84EB: return bn::regular_bg_items::thumb_rin_pair;
            case 0x6A0FC25F: return bn::regular_bg_items::thumb_rin_pair;
            case 0x92C4C567: return bn::regular_bg_items::thumb_rin_pair;
            case 0xA1AA2511: return bn::regular_bg_items::thumb_rin_pair;
            case 0xCAEED655: return bn::regular_bg_items::thumb_rin_pair;
            case 0xC2CBD9BB: return bn::regular_bg_items::thumb_rin_pair;
            case 0x8B38939B: return bn::regular_bg_items::thumb_rin_pair;
            case 0x956B789D: return bn::regular_bg_items::thumb_rin_pair;
            case 0x48B260D5: return bn::regular_bg_items::thumb_rin_pair;
            case 0x09B2DDB8: return emi_sleep_unsure.thumbnail;
            case 0x4D12722B: return emi_sleep_normal.thumbnail;
            case 0xD9BD6EF2: return emi_sleep_weep.thumbnail;
            case 0x515384F8: return emi_sleep_cry.thumbnail;
            case 0xA4EF2B3D: return picnic_normal.thumbnail;
            case 0x49D3D12B: return picnic_rain.thumbnail;
            case 0x092915A0: return hana_library_default.thumbnail;
            case 0x3BADDF80: return hana_library_read.thumbnail;
            case 0xCF7F47FE: return hana_library_gasp.thumbnail;
            case 0x28FC69DE: return hana_library_smile.thumbnail;
            case 0x9425AC62: return shizu_shanghai_default.thumbnail;
            case 0x8E491684: return shizu_shanghai_boredlaugh.thumbnail;
            case 0xA2ABB1B8: return shizu_shanghai_borednormal.thumbnail;
            case 0xE24226CA: return shizu_shanghai_normallaugh.thumbnail;
            case 0xE49E0B6C: return shizu_shanghai_smirklaugh.thumbnail;
            case 0x0CFEBE5E: return shizu_shanghai_smirknormal.thumbnail;
            case 0xC44FE6B4: return shizu_undressing_clothed_stare.thumbnail;
            case 0xC4C2CC63: return shizu_undressing_clothed_kiss.thumbnail;
            case 0x3A073DCC: return shizu_undressing_clothed_blush.thumbnail;
            case 0x072E261D: return shizu_undressing_unclothed_closed.thumbnail;
            case 0x6EBB3CBA: return shizu_undressing_unclothed_blush.thumbnail;
            case 0x1F3F9121: return shizu_undressing_unclothed_kiss.thumbnail;
            case 0x497161B3: return shizu_undressing_unclothed_talk.thumbnail;
            case 0x609E25BC: return shizu_straddle_open.thumbnail;
            case 0x9666EA8A: return shizu_straddle_tease.thumbnail;
            case 0x50DFADCB: return shizu_straddle_closed.thumbnail;
            case 0xB6BB09FC: return shizu_straddle_smile.thumbnail;
            case 0xEC59D299: return shizu_straddle_come.thumbnail;
            case 0x93E8189C: return shizu_table_smile.thumbnail;
            case 0x7A90048B: return shizu_table_normal.thumbnail;
            case 0x0EECAABD: return shizu_table_comeopen.thumbnail;
            case 0x61A6CAD8: return shizu_table_comeclosed.thumbnail;
            case 0xEA7DA516: return shizune_hcg_tied_smile.thumbnail;
            case 0xB5D68A89: return shizune_hcg_tied_blush.thumbnail;
            case 0x79997E98: return shizune_hcg_tied_blush.thumbnail;
            case 0xEF3CB195: return shizune_hcg_tied_stare.thumbnail;
            case 0x9D02A3DE: return shizune_hcg_tied_stare.thumbnail;
            case 0x2EE9AAC0: return shizune_hcg_tied_close.thumbnail;
            case 0xCAAA6F67: return shizune_hcg_tied_kinky3.thumbnail;
            case 0x0E394C83: return shizune_hcg_tied_kinky2.thumbnail;
            case 0xC6B36DB0: return shizune_hcg_tied_kinky2.thumbnail;
            case 0xEC815210: return shizune_hcg_tied_kinky1.thumbnail;
            case 0xB0780A17: return shizune_hcg_tied_close.thumbnail;
            default: return event_missing.thumbnail;
        }
    }
}

#endif //CUSTOM_BACKGROUND_METAS_H
