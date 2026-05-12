#ifndef KS_SMART_CHAR_JIGORO_H
#define KS_SMART_CHAR_JIGORO_H

#include "smart_character_bg.h"

namespace ks::smart_characters::jigoro {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body jigoro_basic_body;

// Per-(group × emotion) variants.
extern const variant jigoro_basic_smug;
extern const variant jigoro_basic_laugh;
extern const variant jigoro_basic_angry;
extern const variant jigoro_basic_neutral;

}  // namespace ks::smart_characters::jigoro

#endif  // KS_SMART_CHAR_JIGORO_H
