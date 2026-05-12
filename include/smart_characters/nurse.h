#ifndef KS_SMART_CHAR_NURSE_H
#define KS_SMART_CHAR_NURSE_H

#include "smart_character_bg.h"

namespace ks::smart_characters::nurse {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body nurse_default_body;
extern const body nurse_close_body;

// Per-(group × emotion) variants.
extern const variant nurse_default_neutral;
extern const variant nurse_default_fabulous;
extern const variant nurse_default_grin;
extern const variant nurse_default_concern;
extern const variant nurse_close_grin;
extern const variant nurse_close_fabulous;
extern const variant nurse_close_concern;
extern const variant nurse_close_neutral;

}  // namespace ks::smart_characters::nurse

#endif  // KS_SMART_CHAR_NURSE_H
