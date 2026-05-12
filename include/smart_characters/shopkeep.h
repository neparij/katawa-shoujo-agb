#ifndef KS_SMART_CHAR_SHOPKEEP_H
#define KS_SMART_CHAR_SHOPKEEP_H

#include "smart_character_bg.h"

namespace ks::smart_characters::shopkeep {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body shopkeep_basic_body;

// Per-(group × emotion) variants.
extern const variant shopkeep_basic_surprised;
extern const variant shopkeep_basic_happy;
extern const variant shopkeep_basic_thinking;
extern const variant shopkeep_basic_neutral;

}  // namespace ks::smart_characters::shopkeep

#endif  // KS_SMART_CHAR_SHOPKEEP_H
