#ifndef KS_SMART_CHAR_MIKI_H
#define KS_SMART_CHAR_MIKI_H

#include "smart_character_bg.h"

namespace ks::smart_characters::miki {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body miki_basic_body;
extern const body miki_basic_close_body;

// Per-(group × emotion) variants.
extern const variant miki_basic_grinclosed;
extern const variant miki_basic_smile;
extern const variant miki_basic_grin;
extern const variant miki_basic_wink;
extern const variant miki_basic_whistle;
extern const variant miki_basic_serious;
extern const variant miki_basic_close_whistle;
extern const variant miki_basic_close_angry;
extern const variant miki_basic_close_grin;
extern const variant miki_basic_close_confused;
extern const variant miki_basic_close_serious;
extern const variant miki_basic_close_grinclosed;
extern const variant miki_basic_close_smile;
extern const variant miki_basic_close_wink;

}  // namespace ks::smart_characters::miki

#endif  // KS_SMART_CHAR_MIKI_H
