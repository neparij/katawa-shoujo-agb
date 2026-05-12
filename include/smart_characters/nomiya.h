#ifndef KS_SMART_CHAR_NOMIYA_H
#define KS_SMART_CHAR_NOMIYA_H

#include "smart_character_bg.h"

namespace ks::smart_characters::nomiya {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body nomiya_basic_body;
extern const body nomiya_basic_close_body;

// Per-(group × emotion) variants.
extern const variant nomiya_basic_talktongue;
extern const variant nomiya_basic_veryhappy;
extern const variant nomiya_basic_smile;
extern const variant nomiya_basic_frown;
extern const variant nomiya_basic_stern;
extern const variant nomiya_basic_talk;
extern const variant nomiya_basic_serious;
extern const variant nomiya_basic_dreamy;
extern const variant nomiya_basic_close_frown;

}  // namespace ks::smart_characters::nomiya

#endif  // KS_SMART_CHAR_NOMIYA_H
