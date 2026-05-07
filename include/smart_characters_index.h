#ifndef KS_SMART_CHARACTERS_INDEX_H
#define KS_SMART_CHARACTERS_INDEX_H

#include "smart_character_bg.h"
#include "smart_characters/akira.h"
#include "smart_characters/emi.h"
#include "smart_characters/hanako.h"
#include "smart_characters/hideaki.h"
#include "smart_characters/jigoro.h"
#include "smart_characters/kenji.h"
#include "smart_characters/lilly.h"
#include "smart_characters/meiko.h"
#include "smart_characters/miki.h"
#include "smart_characters/misha.h"
#include "smart_characters/muto.h"
#include "smart_characters/nomiya.h"
#include "smart_characters/nurse.h"
#include "smart_characters/rin.h"
#include "smart_characters/sae.h"
#include "smart_characters/shizu.h"
#include "smart_characters/shopkeep.h"
#include "smart_characters/yuuko.h"

namespace ks::smart_characters {

/// Resolve a group hash (as stored in save thumbnails)
/// back to the `variant` of that group's base-emotion
/// face. Returns `nullptr` on miss. Caller composes the
/// sprite from `face_tiles` + face shape + the shared
/// `bn::sprite_palette_items::pal_char_obj`.
inline const variant* get_thumbnail_by_hash(const unsigned int hash) {
    switch (hash) {
        case 0x0012: return &kenji::kenji_basic_tsun;
        case 0x02D6: return &akira::akira_basic_smile;
        case 0x03A2: return &lilly::lilly_basic2_cas_close_ara;
        case 0x066D: return &lilly::lilly_cane_cas_close_smileclosed;
        case 0x079A: return &shizu::shizu_behind_close_smile;
        case 0x0AA7: return &hanako::hanako_def_close_worry;
        case 0x0C38: return &hanako::hanako_emb_timid;
        case 0x0D6F: return &hanako::hanako_emb_cas_timid;
        case 0x0EC2: return &misha::misha_cross_close_smile;
        case 0x103B: return &hanako::hanako_def_cas_worry;
        case 0x121D: return &hanako::hanako_cover_cas_distant;
        case 0x131F: return &rin::rin_basic_cas_close_absent;
        case 0x1423: return &lilly::lilly_basic3_cas_close_listen;
        case 0x164D: return &hideaki::hideaki_up_normal;
        case 0x1766: return &rin::rin_relaxed_silhouette_surprised;
        case 0x1A22: return &shizu::shizu_adjust_cas_close_happy;
        case 0x1B60: return &yuuko::yuuko_up_smile;
        case 0x1B7E: return &miki::miki_basic_close_smile;
        case 0x205C: return &emi::emi_sad_close_shy;
        case 0x219B: return &hanako::hanako_cover_cas_close_distant;
        case 0x220B: return &shizu::shizu_cross_angry;
        case 0x2474: return &misha::misha_perky_close_smile;
        case 0x24E3: return &misha::mishashort_hips_close_smile;
        case 0x254F: return &yuuko::yuukoshang_up_smile;
        case 0x2869: return &misha::mishashort_hips_cas_smile;
        case 0x29A2: return &shizu::shizu_basic_cas_close_normal;
        case 0x2B56: return &kenji::kenji_rage_close_rage;
        case 0x2B77: return &kenji::kenji_rage_rage;
        case 0x2BBB: return &shizu::shizuyu_cross_close_happy;
        case 0x2D7F: return &rin::rinpan_relaxed_doubt;
        case 0x3571: return &lilly::lilly_basic1_paj_close_ara;
        case 0x3641: return &misha::misha_sign_close_smile;
        case 0x37A4: return &hanako::hanako_cover_close_distant;
        case 0x37DE: return &shizu::shizu_basic_normal;
        case 0x3940: return &lilly::lilly_basic_paj_close_smileclosed;
        case 0x3DD6: return &emi::emi_sad_shy;
        case 0x3F47: return &lilly::lilly_cane_close_smileclosed;
        case 0x3FFC: return &lilly::lilly_basic2_cas_ara;
        case 0x40B9: return &hanako::hanagown_stock_normalblush;
        case 0x43F4: return &lilly::lilly_basic_che_close_smileclosed;
        case 0x44A8: return &sae::sae_basic_neutral;
        case 0x489B: return &emi::emicas_basic_close_smile;
        case 0x4984: return &meiko::meiko_basic_smile;
        case 0x4A15: return &shizu::shizuyu_basic_happy;
        case 0x4BCF: return &shizu::shizuyu_cross_happy;
        case 0x4EBA: return &rin::rin_basic_cas_absent;
        case 0x53A5: return &lilly::lilly_basic_cas_smileclosed;
        case 0x5446: return &lilly::lilly_basic2_close_ara;
        case 0x54A1: return &nurse::nurse_default_neutral;
        case 0x562B: return &emi::emi_excited_smile;
        case 0x564C: return &misha::mishashort_sign_cas_smile;
        case 0x5855: return &hanako::hanako_def_cas_close_worry;
        case 0x5A28: return &hanako::hanako_defarms_cas_worry;
        case 0x5E96: return &misha::misha_cross_cas_grin;
        case 0x5F59: return &emi::emi_sad_gym_close_shy;
        case 0x60B9: return &lilly::lilly_behind_che_close_cheerful;
        case 0x6351: return &misha::misha_sign_cas_smile;
        case 0x6626: return &misha::misha_hips_smile;
        case 0x6692: return &shizu::shizu_behind_cas_close_smile;
        case 0x6765: return &rin::rin_basic_absent;
        case 0x67CC: return &hanako::hanako_def_worry;
        case 0x682D: return &hanako::hanako_cover_distant;
        case 0x68F7: return &hanako::hanako_defarms_worry;
        case 0x6CA1: return &shizu::shizu_adjust_happy;
        case 0x6F27: return &shizu::shizu_behind_cas_smile;
        case 0x6FE6: return &hideaki::hideaki_basic_normal;
        case 0x7150: return &hanako::hanako_basic_cas_normal;
        case 0x721A: return &lilly::lilly_basic3_che_close_listen;
        case 0x75C0: return &rin::rin_negative_spaciness;
        case 0x75CB: return &shizu::shizu_adjust_cas_happy;
        case 0x770E: return &misha::mishashort_cross_smile;
        case 0x7969: return &rin::rin_relaxed_cas_doubt;
        case 0x7A24: return &lilly::lilly_back_smileclosed;
        case 0x7AA3: return &lilly::lilly_cane_cas_smileclosed;
        case 0x7E11: return &misha::mishashort_sign_close_smile;
        case 0x7E30: return &lilly::lilly_basic3_cas_listen;
        case 0x7E4F: return &lilly::lilly_basic_paj_smileclosed;
        case 0x8005: return &lilly::lilly_basic_cas_close_smileclosed;
        case 0x87A7: return &misha::misha_hips_close_smile;
        case 0x896C: return &emi::emicas_basic_smile;
        case 0x8AD3: return &rin::rin_relaxed_close_doubt;
        case 0x8B49: return &emi::emi_excited_gym_smile;
        case 0x8DC7: return &hanako::hanako_basic_close_normal;
        case 0x9008: return &hanako::hanako_defarms_cas_close_worry;
        case 0x91C0: return &lilly::lilly_back_cas_smileclosed;
        case 0x92AF: return &shopkeep::shopkeep_basic_neutral;
        case 0x92B3: return &nomiya::nomiya_basic_smile;
        case 0x92CF: return &hanako::hanako_emb_cas_close_timid;
        case 0x9409: return &shizu::shizu_basic_cas_normal;
        case 0x9633: return &shizu::shizu_behind_smile;
        case 0x975C: return &shizu::shizu_out_close_serious;
        case 0x97E3: return &lilly::lilly_basic1_paj_ara;
        case 0x9966: return &misha::misha_perky_yuk_smile;
        case 0x99CB: return &misha::mishashort_perky_cas_smile;
        case 0xA2B7: return &lilly::lilly_behind_close_cheerful;
        case 0xA3C1: return &misha::mishashort_cross_cas_grin;
        case 0xA45E: return &misha::mishashort_sign_smile;
        case 0xA67E: return &hanako::hanako_emb_close_timid;
        case 0xA6F5: return &akira::akira_basic_close_smile;
        case 0xA8C0: return &kenji::kenji_basic_close_tsun;
        case 0xA8DD: return &lilly::lilly_basic3_close_listen;
        case 0xA9BE: return &rin::rin_relaxed_doubt;
        case 0xAA42: return &misha::misha_hips_cas_smile;
        case 0xAA4A: return &misha::misha_sign_yuk_smile;
        case 0xAB61: return &hanako::hanagown_basic_close_normal;
        case 0xAEB6: return &shizu::shizu_basic_close_normal;
        case 0xAED6: return &hanako::hanako_basic_normal;
        case 0xB06D: return &kenji::kenji_basic_naked_tsun;
        case 0xB0D1: return &misha::misha_perky_cas_smile;
        case 0xB0E7: return &nurse::nurse_close_neutral;
        case 0xB1B3: return &muto::muto_basic_normal;
        case 0xB4A6: return &lilly::lilly_basic_close_smileclosed;
        case 0xB4AA: return &lilly::lilly_behind_cheerful;
        case 0xBB83: return &emi::emiwheel_basic_grin;
        case 0xBCA8: return &lilly::lilly_behind_nak_smileclosed;
        case 0xBFBA: return &lilly::lilly_back_cas_close_smileclosed;
        case 0xBFF7: return &rin::rin_relaxed_cas_close_doubt;
        case 0xC075: return &misha::mishashort_perky_close_smile;
        case 0xC24D: return &lilly::lilly_basic2_che_close_arablush;
        case 0xC4D2: return &emi::emi_excited_close_smile;
        case 0xC85A: return &yuuko::yuuko_down_smile;
        case 0xCC2B: return &emi::emiwheel_basic_close_grin;
        case 0xCC3E: return &misha::mishashort_hips_smile;
        case 0xCE09: return &shizu::shizuyu_basic_close_happy;
        case 0xD037: return &misha::misha_sign_smile;
        case 0xD059: return &emi::emicas_up_close_smile;
        case 0xD1BB: return &rin::rin_negative_close_spaciness;
        case 0xD33B: return &shizu::shizu_behind_nak_smile;
        case 0xD412: return &emi::emicas_up_smile;
        case 0xD4AF: return &shizu::shizu_adjust_close_happy;
        case 0xD792: return &misha::misha_perky_smile;
        case 0xD7E9: return &rin::rin_negative_cas_close_spaciness;
        case 0xD9BF: return &miki::miki_basic_smile;
        case 0xDAB1: return &nomiya::nomiya_basic_close_frown;
        case 0xDCAD: return &yuuko::yuuko_down_close_smile;
        case 0xE26A: return &yuuko::yuukoshang_down_smile;
        case 0xE381: return &misha::mishashort_perky_smile;
        case 0xE574: return &emi::eminude_basic_close_grin;
        case 0xE69C: return &shizu::shizu_cross_cas_angry;
        case 0xE84F: return &hanako::hanagown_basic_normal;
        case 0xE908: return &rin::rinpan_basic_absent;
        case 0xEA6A: return &rin::rin_basic_close_absent;
        case 0xEAA1: return &rin::rinpan_relaxed_close_doubt;
        case 0xECE9: return &lilly::lilly_basic2_ara;
        case 0xED43: return &emi::emi_sad_gym_shy;
        case 0xEE30: return &jigoro::jigoro_basic_neutral;
        case 0xEEC0: return &hanako::hanako_basic_cas_close_normal;
        case 0xF00D: return &misha::misha_cross_smile;
        case 0xF078: return &lilly::lilly_basic3_listen;
        case 0xF25A: return &emi::eminude_basic_grin;
        case 0xF429: return &lilly::lilly_basic_smileclosed;
        case 0xF5D6: return &lilly::lilly_cane_smileclosed;
        case 0xFAAC: return &shizu::shizu_cross_close_angry;
        case 0xFEFC: return &rin::rin_negative_cas_spaciness;
        default: return nullptr;
    }
}

}  // namespace ks::smart_characters

#endif  // KS_SMART_CHARACTERS_INDEX_H
