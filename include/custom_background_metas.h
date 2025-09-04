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
#include "bn_regular_bg_items_thumb_event_drugs.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_slices_lilly.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_slices_shizu.h"
#include "bn_regular_bg_items_lilly_shizu_showdown_both.h"
#include "bn_regular_bg_items_op_snowywoods.h"
#include "bn_regular_bg_items_other_iwanako.h"
#include "bn_regular_bg_items_other_iwanako_nosnow.h"
#include "bn_regular_bg_items_thumb_lilly_shizu_showdown.h"
#include "bn_regular_bg_items_thumb_op_snowywoods.h"
#include "bn_regular_bg_items_thumb_other_iwanako.h"

// TODO: add before-compile tool to generate unique hashes for each background
// How to calculate hash:
// Use MD5 hash of the background name and take first 8 digits.
// Example: hisao_class -> 506DE7CF
// Bash oneliner: echo -en "hisao_class" | md5 | awk '{print $1}' | cut -c1-8 | tr '[:lower:]' '[:upper:]' | sed 's/^/0x/'

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
        bn::regular_bg_items::thumb_event_drugs,
        0xFFFF0008);

    constexpr inline background_meta op_snowywoods(
        bn::regular_bg_items::op_snowywoods,
        bn::regular_bg_items::thumb_op_snowywoods,
        0xFFFF0009);

    constexpr inline background_meta other_iwanako(
        bn::regular_bg_items::other_iwanako_nosnow,
        bn::regular_bg_items::thumb_other_iwanako,
        0x0FFF000A);

    constexpr inline background_meta kslogo_heart(
        bn::regular_bg_items::kslogo_heart,
        bn::regular_bg_items::thumb_event_missing,
        0x0FFFFF00);

    constexpr inline background_meta kslogo_words(
        bn::regular_bg_items::kslogo_words,
        bn::regular_bg_items::thumb_event_missing,
        0x0FFFFF01);

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
            case 0xFFFF0008: return event_drugs_en.thumbnail;
            case 0xFFFF0009: return op_snowywoods.thumbnail;
            case 0xFFFF000A: return other_iwanako.thumbnail;
            default: return event_missing.thumbnail;
        }
    }
}

#endif //CUSTOM_BACKGROUND_METAS_H
