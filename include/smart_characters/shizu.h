#ifndef KS_SMART_CHAR_SHIZU_H
#define KS_SMART_CHAR_SHIZU_H

#include "smart_character_bg.h"

namespace ks::smart_characters::shizu {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body shizu_adjust_cas_body;
extern const body shizu_adjust_body;
extern const body shizu_basic_cas_body;
extern const body shizu_basic_body;
extern const body shizu_behind_nak_body;
extern const body shizu_behind_body;
extern const body shizu_behind_cas_body;
extern const body shizu_cross_cas_body;
extern const body shizu_cross_body;
extern const body shizu_adjust_cas_close_body;
extern const body shizu_adjust_close_body;
extern const body shizu_basic_cas_close_body;
extern const body shizu_basic_close_body;
extern const body shizu_behind_close_body;
extern const body shizu_behind_cas_close_body;
extern const body shizu_cross_close_body;
extern const body shizu_out_close_body;
extern const body shizuyu_basic_body;
extern const body shizuyu_cross_body;
extern const body shizuyu_basic_close_body;
extern const body shizuyu_cross_close_body;

// Per-(group × emotion) variants.
extern const variant shizu_adjust_cas_happy;
extern const variant shizu_adjust_cas_frown;
extern const variant shizu_adjust_cas_smug;
extern const variant shizu_adjust_noglasses;
extern const variant shizu_adjust_smug;
extern const variant shizu_adjust_angry;
extern const variant shizu_adjust_blush;
extern const variant shizu_adjust_frown;
extern const variant shizu_adjust_happy;
extern const variant shizu_basic_cas_angry;
extern const variant shizu_basic_cas_happy;
extern const variant shizu_basic_cas_sparkle;
extern const variant shizu_basic_cas_normal2;
extern const variant shizu_basic_cas_frown;
extern const variant shizu_basic_cas_normal;
extern const variant shizu_basic_normal;
extern const variant shizu_basic_angry;
extern const variant shizu_basic_normal2;
extern const variant shizu_basic_sparkle;
extern const variant shizu_basic_frown;
extern const variant shizu_basic_happy;
extern const variant shizu_behind_nak_frown;
extern const variant shizu_behind_nak_smile;
extern const variant shizu_behind_nak_blank;
extern const variant shizu_behind_nak_smilelow;
extern const variant shizu_behind_sad;
extern const variant shizu_behind_smile;
extern const variant shizu_behind_frustrated;
extern const variant shizu_behind_blank;
extern const variant shizu_behind_frown;
extern const variant shizu_behind_cas_frustrated;
extern const variant shizu_behind_cas_smile;
extern const variant shizu_behind_cas_frown;
extern const variant shizu_behind_cas_blank;
extern const variant shizu_cross_cas_angry;
extern const variant shizu_cross_cas_wut;
extern const variant shizu_cross_rageclosed;
extern const variant shizu_cross_rage;
extern const variant shizu_cross_angry;
extern const variant shizu_cross_wut;
extern const variant shizu_adjust_cas_close_blush;
extern const variant shizu_adjust_cas_close_smug;
extern const variant shizu_adjust_cas_close_frown;
extern const variant shizu_adjust_cas_close_happy;
extern const variant shizu_adjust_close_happy;
extern const variant shizu_adjust_close_angry;
extern const variant shizu_adjust_close_blush;
extern const variant shizu_adjust_close_smug;
extern const variant shizu_adjust_close_frown;
extern const variant shizu_basic_cas_close_normal2;
extern const variant shizu_basic_cas_close_angry;
extern const variant shizu_basic_cas_close_happy;
extern const variant shizu_basic_cas_close_normal;
extern const variant shizu_basic_close_frown;
extern const variant shizu_basic_close_normal2;
extern const variant shizu_basic_close_sparkle;
extern const variant shizu_basic_close_normal;
extern const variant shizu_basic_close_happy;
extern const variant shizu_basic_close_angry;
extern const variant shizu_behind_close_sad;
extern const variant shizu_behind_close_blank;
extern const variant shizu_behind_close_smile;
extern const variant shizu_behind_close_frustrated;
extern const variant shizu_behind_close_frown;
extern const variant shizu_behind_cas_close_frustrated;
extern const variant shizu_behind_cas_close_smile;
extern const variant shizu_behind_cas_close_sad;
extern const variant shizu_behind_cas_close_blank;
extern const variant shizu_cross_close_wut;
extern const variant shizu_cross_close_stunned;
extern const variant shizu_cross_close_angry;
extern const variant shizu_out_close_serious;
extern const variant shizuyu_basic_aside;
extern const variant shizuyu_basic_blush;
extern const variant shizuyu_basic_happy;
extern const variant shizuyu_cross_blush;
extern const variant shizuyu_cross_happy;
extern const variant shizuyu_cross_angry;
extern const variant shizuyu_basic_close_angry;
extern const variant shizuyu_basic_close_happy;
extern const variant shizuyu_cross_close_blush;
extern const variant shizuyu_cross_close_happy;
extern const variant shizuyu_cross_close_angry;

}  // namespace ks::smart_characters::shizu

#endif  // KS_SMART_CHAR_SHIZU_H
