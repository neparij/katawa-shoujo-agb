#ifndef KS_SMART_CHAR_SAE_H
#define KS_SMART_CHAR_SAE_H

#include "smart_character_bg.h"

namespace ks::smart_characters::sae {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body sae_basic_body;

// Per-(group × emotion) variants.
extern const variant sae_basic_doubt;
extern const variant sae_basic_neutral;
extern const variant sae_basic_scowlsmoke;
extern const variant sae_basic_smilesmoke;
extern const variant sae_basic_doubtsmoke;
extern const variant sae_basic_smile;
extern const variant sae_basic_neutralsmoke;
extern const variant sae_basic_scowl;

}  // namespace ks::smart_characters::sae

#endif  // KS_SMART_CHAR_SAE_H
