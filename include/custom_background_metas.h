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
#include "ks_huge_bg_items_event_drugs_en.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_slices_lilly.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_slices_shizu.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_both.h"
#include "bn_regular_bg_items_thumb_lilly_shizu_showdown.h"

namespace ks::background_metas {
    constexpr inline background_meta hisao_class(
        bn::regular_bg_items::hisao_class,
        bn::regular_bg_items::thumb_hisao_class,
        0xFFFF0000);

    constexpr inline background_meta emi_knockeddown(
        bn::regular_bg_items::emi_knockeddown_largepullout,
        bn::regular_bg_items::thumb_emi_knockeddown,
        0xFFFF0001);

    constexpr inline background_meta emi_knockeddown_facepullout(
        bn::regular_bg_items::emi_knockeddown_facepullout,
        bn::regular_bg_items::thumb_emi_knockeddown,
        0xFFFF0002);

    constexpr inline background_meta emi_knockeddown_largepullout(
        bn::regular_bg_items::emi_knockeddown_largepullout,
        bn::regular_bg_items::thumb_emi_knockeddown,
        0xFFFF0003);

    constexpr inline background_meta emi_knockeddown_legs(
        bn::regular_bg_items::emi_knockeddown_legs,
        bn::regular_bg_items::thumb_emi_knockeddown,
        0xFFFF0004);

    constexpr inline background_meta lilly_shizu_showdown_slices_lilly(
        bn::regular_bg_items::lilly_shizu_showdown_slices_lilly,
        bn::regular_bg_items::thumb_lilly_shizu_showdown,
        0xFFFF0005);

    constexpr inline background_meta lilly_shizu_showdown_slices_shizu(
        bn::regular_bg_items::lilly_shizu_showdown_slices_shizu,
        bn::regular_bg_items::thumb_lilly_shizu_showdown,
        0xFFFF0006);

    constexpr inline background_meta lilly_shizu_showdown_both(
        bn::regular_bg_items::lilly_shizu_showdown_both,
        bn::regular_bg_items::thumb_lilly_shizu_showdown,
        0xFFFF0007);

    constexpr inline huge_background_meta event_drugs_en(
        ks::huge_bg_items::event_drugs_en,
        bn::regular_bg_items::thumb_lilly_shizu_showdown,
        0xFFFF0008);

    constexpr inline background_meta kslogo_heart(
        bn::regular_bg_items::kslogo_heart,
        bn::regular_bg_items::thumb_event_missing,
        0x0FFFFF00);

    constexpr inline background_meta kslogo_words(
        bn::regular_bg_items::kslogo_words,
        bn::regular_bg_items::thumb_event_missing,
        0x0FFFFF01);

    inline const background_meta *get_custom_by_hash(const unsigned int hash) {
        switch (hash) {
            case 0xFFFF0000: return &hisao_class;
            case 0xFFFF0001: return &emi_knockeddown;
            case 0xFFFF0002: return &emi_knockeddown_facepullout;
            case 0xFFFF0003: return &emi_knockeddown_largepullout;
            case 0xFFFF0004: return &emi_knockeddown_legs;
            case 0xFFFF0005: return &lilly_shizu_showdown_slices_lilly;
            case 0xFFFF0006: return &lilly_shizu_showdown_slices_shizu;
            case 0xFFFF0007: return &lilly_shizu_showdown_both;
            default: return &event_missing;
        }
    }
}

#endif //CUSTOM_BACKGROUND_METAS_H
