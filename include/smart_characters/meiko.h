#ifndef KS_SMART_CHAR_MEIKO_H
#define KS_SMART_CHAR_MEIKO_H

#include "smart_character_bg.h"

namespace ks::smart_characters::meiko {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body meiko_basic_body;

// Per-(group × emotion) variants.
extern const variant meiko_basic_serious;
extern const variant meiko_basic_wink;
extern const variant meiko_basic_smile;
extern const variant meiko_basic_worry;
extern const variant meiko_basic_happy;

}  // namespace ks::smart_characters::meiko

#endif  // KS_SMART_CHAR_MEIKO_H
