#ifndef KS_SMART_CHAR_YUUKO_H
#define KS_SMART_CHAR_YUUKO_H

#include "smart_character_bg.h"

namespace ks::smart_characters::yuuko {

extern const tileset_data tileset;

// Per-group bodies (one per pose × outfit × close).
extern const body yuuko_up_body;
extern const body yuuko_down_body;
extern const body yuuko_up_close_body;
extern const body yuuko_down_close_body;
extern const body yuukoshang_up_body;
extern const body yuukoshang_down_body;

// Per-(group × emotion) variants.
extern const variant yuuko_up_cry;
extern const variant yuuko_up_neutral;
extern const variant yuuko_up_closedhappy;
extern const variant yuuko_up_worried;
extern const variant yuuko_up_smile;
extern const variant yuuko_up_neurotic;
extern const variant yuuko_up_happy;
extern const variant yuuko_up_panic;
extern const variant yuuko_down_neurotic;
extern const variant yuuko_down_happy;
extern const variant yuuko_down_worried;
extern const variant yuuko_down_cry;
extern const variant yuuko_down_neutral;
extern const variant yuuko_down_smile;
extern const variant yuuko_down_closedhappy;
extern const variant yuuko_down_panic;
extern const variant yuuko_up_close_neutral;
extern const variant yuuko_up_close_closedhappy;
extern const variant yuuko_up_close_worried;
extern const variant yuuko_up_close_happy;
extern const variant yuuko_up_close_panic;
extern const variant yuuko_down_close_worried;
extern const variant yuuko_down_close_neutral;
extern const variant yuuko_down_close_closedhappy;
extern const variant yuuko_down_close_happy;
extern const variant yuuko_down_close_smile;
extern const variant yuukoshang_up_noglasses;
extern const variant yuukoshang_up_happy;
extern const variant yuukoshang_up_panic;
extern const variant yuukoshang_up_worried;
extern const variant yuukoshang_up_neurotic;
extern const variant yuukoshang_up_smile;
extern const variant yuukoshang_up_neutral;
extern const variant yuukoshang_up_closedhappy;
extern const variant yuukoshang_down_closedhappy;
extern const variant yuukoshang_down_happy;
extern const variant yuukoshang_down_worried;
extern const variant yuukoshang_down_panic;
extern const variant yuukoshang_down_smile;
extern const variant yuukoshang_down_neutral;
extern const variant yuukoshang_down_neurotic;

}  // namespace ks::smart_characters::yuuko

#endif  // KS_SMART_CHAR_YUUKO_H
