#ifndef KS_SMART_CHAR_HIDEAKI_H
#define KS_SMART_CHAR_HIDEAKI_H

#include "smart_character_bg.h"

namespace ks::smart_characters::hideaki {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body hideaki_basic_body;
extern const body hideaki_up_body;

// Per-(group × emotion) variants.
extern const variant hideaki_basic_happy;
extern const variant hideaki_basic_evil;
extern const variant hideaki_basic_disapproves;
extern const variant hideaki_basic_normal;
extern const variant hideaki_basic_ohshit;
extern const variant hideaki_basic_thinking;
extern const variant hideaki_basic_darkside;
extern const variant hideaki_basic_surprise;
extern const variant hideaki_basic_triangle;
extern const variant hideaki_basic_bored;
extern const variant hideaki_basic_angry;
extern const variant hideaki_basic_confused;
extern const variant hideaki_basic_sad;
extern const variant hideaki_basic_serious;
extern const variant hideaki_up_surprise;
extern const variant hideaki_up_angry;
extern const variant hideaki_up_serious;
extern const variant hideaki_up_bored;
extern const variant hideaki_up_happy;
extern const variant hideaki_up_closed;
extern const variant hideaki_up_normal;

}  // namespace ks::smart_characters::hideaki

#endif  // KS_SMART_CHAR_HIDEAKI_H
