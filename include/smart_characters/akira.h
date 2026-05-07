#ifndef KS_SMART_CHAR_AKIRA_H
#define KS_SMART_CHAR_AKIRA_H

#include "smart_character_bg.h"

namespace ks::smart_characters::akira {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body akira_basic_body;
extern const body akira_basic_close_body;

// Per-(group × emotion) variants.
extern const variant akira_basic_evil;
extern const variant akira_basic_laugh;
extern const variant akira_basic_ending;
extern const variant akira_basic_annoyed;
extern const variant akira_basic_resigned;
extern const variant akira_basic_smile;
extern const variant akira_basic_kill;
extern const variant akira_basic_boo;
extern const variant akira_basic_lost;
extern const variant akira_basic_close_laugh;
extern const variant akira_basic_close_ending;
extern const variant akira_basic_close_boo;
extern const variant akira_basic_close_smile;
extern const variant akira_basic_close_annoyed;
extern const variant akira_basic_close_lost;
extern const variant akira_basic_close_resigned;
extern const variant akira_basic_close_distant;

}  // namespace ks::smart_characters::akira

#endif  // KS_SMART_CHAR_AKIRA_H
