#ifndef KS_CHAR_METAS
#define KS_CHAR_METAS

#include "sprite_metas/shizu_behind_nak.h"
#include "sprite_metas/shizu_adjust_cas.h"
#include "sprite_metas/shizu_basic_cas.h"
#include "sprite_metas/shizu_behind_cas.h"
#include "sprite_metas/shizu_cross_cas.h"
#include "sprite_metas/shizu_adjust.h"
#include "sprite_metas/shizu_basic.h"
#include "sprite_metas/shizu_behind.h"
#include "sprite_metas/shizu_cross.h"
#include "sprite_metas/misha_hips_cas.h"
#include "sprite_metas/misha_cross_cas.h"
#include "sprite_metas/misha_perky_cas.h"
#include "sprite_metas/misha_sign_cas.h"
#include "sprite_metas/misha_perky_yuk.h"
#include "sprite_metas/misha_sign_yuk.h"
#include "sprite_metas/misha_hips.h"
#include "sprite_metas/misha_cross.h"
#include "sprite_metas/misha_perky.h"
#include "sprite_metas/misha_sign.h"
#include "sprite_metas/emi_basic_gym.h"
#include "sprite_metas/emi_basic.h"
#include "sprite_metas/emi_excited_gym.h"
#include "sprite_metas/emi_excited.h"
#include "sprite_metas/emi_sad_gym.h"
#include "sprite_metas/emi_sad.h"
#include "sprite_metas/rin_basic_cas.h"
#include "sprite_metas/rin_negative_cas.h"
#include "sprite_metas/rin_relaxed_cas.h"
#include "sprite_metas/rin_basic.h"
#include "sprite_metas/rin_negative.h"
#include "sprite_metas/rin_relaxed.h"
#include "sprite_metas/rin_back.h"
#include "sprite_metas/rin_basic_cas_close.h"
#include "sprite_metas/rin_negative_cas_close.h"
#include "sprite_metas/rin_relaxed_cas_close.h"
#include "sprite_metas/rin_basic_close.h"
#include "sprite_metas/rin_negative_close.h"
#include "sprite_metas/rin_relaxed_close.h"
#include "sprite_metas/rin_relaxed_silhouette.h"
#include "sprite_metas/lilly_back_cas.h"
#include "sprite_metas/lilly_back.h"
#include "sprite_metas/lilly_basic_cas.h"
#include "sprite_metas/lilly_basic_paj.h"
#include "sprite_metas/lilly_basic.h"
#include "sprite_metas/lilly_basic1_paj.h"
#include "sprite_metas/lilly_basic2_cas.h"
#include "sprite_metas/lilly_basic2.h"
#include "sprite_metas/lilly_basic3_cas.h"
#include "sprite_metas/lilly_basic3.h"
#include "sprite_metas/lilly_behind_nak.h"
#include "sprite_metas/lilly_behind.h"
#include "sprite_metas/lilly_cane_cas.h"
#include "sprite_metas/lilly_cane.h"
#include "sprite_metas/hanako_basic_cas.h"
#include "sprite_metas/hanako_basic.h"
#include "sprite_metas/hanako_cover_cas.h"
#include "sprite_metas/hanako_cover.h"
#include "sprite_metas/hanako_def_cas.h"
#include "sprite_metas/hanako_def.h"
#include "sprite_metas/hanako_defarms_cas.h"
#include "sprite_metas/hanako_defarms.h"
#include "sprite_metas/hanako_emb_cas.h"
#include "sprite_metas/hanako_emb.h"
#include "sprite_metas/kenji_basic.h"
#include "sprite_metas/kenji_basic_naked.h"
#include "sprite_metas/kenji_rage.h"
#include "sprite_metas/nurse.h"
#include "sprite_metas/yuuko_up.h"
#include "sprite_metas/yuuko_down.h"
#include "sprite_metas/yuukoshang_up.h"
#include "sprite_metas/yuukoshang_down.h"
#include "sprite_metas/muto_basic.h"
#include "sprite_metas/muto_basic_close.h"
namespace ks::character_sprite_metas {
    inline const character_sprite_meta* get_by_hash(const unsigned int hash) {
        switch (hash) {
            case 0xD33B: return &sprite_metas::shizu_behind_nak;
            case 0x75CB: return &sprite_metas::shizu_adjust_cas;
            case 0x9409: return &sprite_metas::shizu_basic_cas;
            case 0x6F27: return &sprite_metas::shizu_behind_cas;
            case 0xE69C: return &sprite_metas::shizu_cross_cas;
            case 0x6CA1: return &sprite_metas::shizu_adjust;
            case 0x37DE: return &sprite_metas::shizu_basic;
            case 0x9633: return &sprite_metas::shizu_behind;
            case 0x220B: return &sprite_metas::shizu_cross;
            case 0xAA42: return &sprite_metas::misha_hips_cas;
            case 0x5E96: return &sprite_metas::misha_cross_cas;
            case 0xB0D1: return &sprite_metas::misha_perky_cas;
            case 0x6351: return &sprite_metas::misha_sign_cas;
            case 0x9966: return &sprite_metas::misha_perky_yuk;
            case 0xAA4A: return &sprite_metas::misha_sign_yuk;
            case 0x6626: return &sprite_metas::misha_hips;
            case 0xF00D: return &sprite_metas::misha_cross;
            case 0xD792: return &sprite_metas::misha_perky;
            case 0xD037: return &sprite_metas::misha_sign;
            case 0x6F2C: return &sprite_metas::emi_basic_gym;
            case 0x0C68: return &sprite_metas::emi_basic;
            case 0x8B49: return &sprite_metas::emi_excited_gym;
            case 0x562B: return &sprite_metas::emi_excited;
            case 0xED43: return &sprite_metas::emi_sad_gym;
            case 0x3DD6: return &sprite_metas::emi_sad;
            case 0x4EBA: return &sprite_metas::rin_basic_cas;
            case 0xFEFC: return &sprite_metas::rin_negative_cas;
            case 0x7969: return &sprite_metas::rin_relaxed_cas;
            case 0x6765: return &sprite_metas::rin_basic;
            case 0x75C0: return &sprite_metas::rin_negative;
            case 0xA9BE: return &sprite_metas::rin_relaxed;
            case 0xE17D: return &sprite_metas::rin_back;
            case 0x131F: return &sprite_metas::rin_basic_cas_close;
            case 0xD7E9: return &sprite_metas::rin_negative_cas_close;
            case 0xBFF7: return &sprite_metas::rin_relaxed_cas_close;
            case 0xEA6A: return &sprite_metas::rin_basic_close;
            case 0xD1BB: return &sprite_metas::rin_negative_close;
            case 0x8AD3: return &sprite_metas::rin_relaxed_close;
            case 0x1766: return &sprite_metas::rin_relaxed_silhouette;
            case 0x91C0: return &sprite_metas::lilly_back_cas;
            case 0x7A24: return &sprite_metas::lilly_back;
            case 0x53A5: return &sprite_metas::lilly_basic_cas;
            case 0x7E4F: return &sprite_metas::lilly_basic_paj;
            case 0xF429: return &sprite_metas::lilly_basic;
            case 0x97E3: return &sprite_metas::lilly_basic1_paj;
            case 0x3FFC: return &sprite_metas::lilly_basic2_cas;
            case 0xECE9: return &sprite_metas::lilly_basic2;
            case 0x7E30: return &sprite_metas::lilly_basic3_cas;
            case 0xF078: return &sprite_metas::lilly_basic3;
            case 0xBCA8: return &sprite_metas::lilly_behind_nak;
            case 0xB4AA: return &sprite_metas::lilly_behind;
            case 0x7AA3: return &sprite_metas::lilly_cane_cas;
            case 0xF5D6: return &sprite_metas::lilly_cane;
            case 0x7150: return &sprite_metas::hanako_basic_cas;
            case 0xAED6: return &sprite_metas::hanako_basic;
            case 0x121D: return &sprite_metas::hanako_cover_cas;
            case 0x682D: return &sprite_metas::hanako_cover;
            case 0x103B: return &sprite_metas::hanako_def_cas;
            case 0x67CC: return &sprite_metas::hanako_def;
            case 0x5A28: return &sprite_metas::hanako_defarms_cas;
            case 0x68F7: return &sprite_metas::hanako_defarms;
            case 0x0D6F: return &sprite_metas::hanako_emb_cas;
            case 0x0C38: return &sprite_metas::hanako_emb;
            case 0x0012: return &sprite_metas::kenji_basic;
            case 0xB06D: return &sprite_metas::kenji_basic_naked;
            case 0x2B77: return &sprite_metas::kenji_rage;
            case 0x54A1: return &sprite_metas::nurse;
            case 0x1B60: return &sprite_metas::yuuko_up;
            case 0xC85A: return &sprite_metas::yuuko_down;
            case 0x254F: return &sprite_metas::yuukoshang_up;
            case 0xE26A: return &sprite_metas::yuukoshang_down;
            case 0xB1B3: return &sprite_metas::muto_basic;
            case 0x2077: return &sprite_metas::muto_basic_close;
            default: return nullptr;
        }
    }

};

#endif  // KS_CHAR_METAS
