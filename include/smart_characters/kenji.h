#ifndef KS_SMART_CHAR_KENJI_H
#define KS_SMART_CHAR_KENJI_H

#include "smart_character_bg.h"

namespace ks::smart_characters::kenji {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body kenji_basic_body;
extern const body kenji_basic_naked_body;
extern const body kenji_rage_body;
extern const body kenji_basic_close_body;
extern const body kenji_rage_close_body;

// Per-(group × emotion) variants.
extern const variant kenji_basic_neutral;
extern const variant kenji_basic_happy;
extern const variant kenji_basic_tsun;
extern const variant kenji_basic_naked_happy;
extern const variant kenji_basic_naked_neutral;
extern const variant kenji_basic_naked_tsun;
extern const variant kenji_rage_rage;
extern const variant kenji_basic_close_tsun;
extern const variant kenji_basic_close_happy;
extern const variant kenji_basic_close_neutral;
extern const variant kenji_rage_close_rage;

}  // namespace ks::smart_characters::kenji

#endif  // KS_SMART_CHAR_KENJI_H
