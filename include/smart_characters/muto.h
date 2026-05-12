#ifndef KS_SMART_CHAR_MUTO_H
#define KS_SMART_CHAR_MUTO_H

#include "smart_character_bg.h"

namespace ks::smart_characters::muto {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body muto_basic_body;
extern const body muto_basic_close_body;

// Per-(group × emotion) variants.
extern const variant muto_basic_normal;
extern const variant muto_basic_irritated;
extern const variant muto_basic_smile;
extern const variant muto_basic_close_smile;

}  // namespace ks::smart_characters::muto

#endif  // KS_SMART_CHAR_MUTO_H
