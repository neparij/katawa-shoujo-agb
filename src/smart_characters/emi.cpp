#include "smart_characters/emi.h"

#include "bn_regular_bg_tiles_items_emi_tiles_0.h"
#include "bn_regular_bg_tiles_items_emi_tiles_1.h"
#include "bn_regular_bg_tiles_items_emi_tiles_2.h"
#include "bn_bg_palette_items_pal_char_bg.h"
#include "bn_sprite_tiles_items_emi_thumb_basic.h"
#include "bn_sprite_tiles_items_emi_thumb_basic_close.h"
#include "bn_sprite_tiles_items_emi_thumb_basic_gym.h"
#include "bn_sprite_tiles_items_emi_thumb_basic_gym_close.h"
#include "bn_sprite_tiles_items_emi_thumb_excited.h"
#include "bn_sprite_tiles_items_emi_thumb_excited_close.h"
#include "bn_sprite_tiles_items_emi_thumb_excited_gym.h"
#include "bn_sprite_tiles_items_emi_thumb_excited_gym_close.h"
#include "bn_sprite_tiles_items_emi_thumb_sad.h"
#include "bn_sprite_tiles_items_emi_thumb_sad_close.h"
#include "bn_sprite_tiles_items_emi_thumb_sad_gym.h"
#include "bn_sprite_tiles_items_emi_thumb_sad_gym_close.h"
#include "bn_sprite_tiles_items_emicas_thumb_basic.h"
#include "bn_sprite_tiles_items_emicas_thumb_basic_close.h"
#include "bn_sprite_tiles_items_emicas_thumb_up.h"
#include "bn_sprite_tiles_items_emicas_thumb_up_close.h"
#include "bn_sprite_tiles_items_eminude_thumb_basic.h"
#include "bn_sprite_tiles_items_eminude_thumb_basic_close.h"
#include "bn_sprite_tiles_items_emiwheel_thumb_basic.h"
#include "bn_sprite_tiles_items_emiwheel_thumb_basic_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_annoyed.h"
#include "bn_sprite_tiles_items_emi_spr_basic_annoyed_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_annoyed_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_annoyed_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedgrin.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedgrin_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedgrin_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedgrin_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedhappy.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedhappy_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedhappy_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedhappy_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedsweat.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedsweat_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_closedsweat_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_concentrate.h"
#include "bn_sprite_tiles_items_emi_spr_basic_concentrate_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_confused.h"
#include "bn_sprite_tiles_items_emi_spr_basic_confused_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_confused_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_confused_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_grin.h"
#include "bn_sprite_tiles_items_emi_spr_basic_grin_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_grin_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_grin_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_happy.h"
#include "bn_sprite_tiles_items_emi_spr_basic_happy_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_happy_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_happy_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_happyblush_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_hes.h"
#include "bn_sprite_tiles_items_emi_spr_basic_hes_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_hes_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_hes_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_shock.h"
#include "bn_sprite_tiles_items_emi_spr_basic_shock_close.h"
#include "bn_sprite_tiles_items_emi_spr_basic_shock_gym.h"
#include "bn_sprite_tiles_items_emi_spr_basic_shock_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_amused.h"
#include "bn_sprite_tiles_items_emi_spr_excited_amused_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_amused_gym.h"
#include "bn_sprite_tiles_items_emi_spr_excited_amused_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_circle.h"
#include "bn_sprite_tiles_items_emi_spr_excited_circle_gym.h"
#include "bn_sprite_tiles_items_emi_spr_excited_happy.h"
#include "bn_sprite_tiles_items_emi_spr_excited_happy_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_happy_gym.h"
#include "bn_sprite_tiles_items_emi_spr_excited_happy_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_hesitant_gym.h"
#include "bn_sprite_tiles_items_emi_spr_excited_joy.h"
#include "bn_sprite_tiles_items_emi_spr_excited_joy_gym.h"
#include "bn_sprite_tiles_items_emi_spr_excited_laugh.h"
#include "bn_sprite_tiles_items_emi_spr_excited_laugh_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_laugh_gym.h"
#include "bn_sprite_tiles_items_emi_spr_excited_laugh_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_proud.h"
#include "bn_sprite_tiles_items_emi_spr_excited_proud_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_proud_gym.h"
#include "bn_sprite_tiles_items_emi_spr_excited_proud_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_sad.h"
#include "bn_sprite_tiles_items_emi_spr_excited_sad_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_sad_gym.h"
#include "bn_sprite_tiles_items_emi_spr_excited_sad_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_smile.h"
#include "bn_sprite_tiles_items_emi_spr_excited_smile_close.h"
#include "bn_sprite_tiles_items_emi_spr_excited_smile_gym.h"
#include "bn_sprite_tiles_items_emi_spr_sad_angry.h"
#include "bn_sprite_tiles_items_emi_spr_sad_angry_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_angry_gym.h"
#include "bn_sprite_tiles_items_emi_spr_sad_angry_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_annoyed.h"
#include "bn_sprite_tiles_items_emi_spr_sad_annoyed_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_annoyed_gym.h"
#include "bn_sprite_tiles_items_emi_spr_sad_annoyed_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_depressed.h"
#include "bn_sprite_tiles_items_emi_spr_sad_depressed_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_depressed_gym.h"
#include "bn_sprite_tiles_items_emi_spr_sad_depressed_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_grin.h"
#include "bn_sprite_tiles_items_emi_spr_sad_grin_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_grin_gym.h"
#include "bn_sprite_tiles_items_emi_spr_sad_grin_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_grit.h"
#include "bn_sprite_tiles_items_emi_spr_sad_grit_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_grit_gym.h"
#include "bn_sprite_tiles_items_emi_spr_sad_pout.h"
#include "bn_sprite_tiles_items_emi_spr_sad_pout_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_pout_gym.h"
#include "bn_sprite_tiles_items_emi_spr_sad_pout_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_shy.h"
#include "bn_sprite_tiles_items_emi_spr_sad_shy_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_shy_gym.h"
#include "bn_sprite_tiles_items_emi_spr_sad_shy_gym_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_shyblush.h"
#include "bn_sprite_tiles_items_emi_spr_sad_shyblush_close.h"
#include "bn_sprite_tiles_items_emi_spr_sad_shyblush_gym.h"
#include "bn_sprite_tiles_items_emi_spr_sad_shyblush_gym_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_angry.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_angry_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_awayfrown.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_awayfrown_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_blush.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_blush_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_closedsmile.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_closedsmile_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_evil.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_frown.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_frown_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_grin.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_grit.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_happy.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_happy_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_neutral.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_neutral_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_pout.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_sad.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_sad_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_smile.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_smile_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_weaksmile.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_weaksmile_close.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_wink.h"
#include "bn_sprite_tiles_items_emicas_spr_basic_wink_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_angry.h"
#include "bn_sprite_tiles_items_emicas_spr_up_angry_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_awayfrown.h"
#include "bn_sprite_tiles_items_emicas_spr_up_awayfrown_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_blush_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_closedsmile.h"
#include "bn_sprite_tiles_items_emicas_spr_up_closedsmile_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_frown.h"
#include "bn_sprite_tiles_items_emicas_spr_up_frown_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_grin.h"
#include "bn_sprite_tiles_items_emicas_spr_up_grin_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_happy.h"
#include "bn_sprite_tiles_items_emicas_spr_up_happy_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_neutral.h"
#include "bn_sprite_tiles_items_emicas_spr_up_neutral_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_pout.h"
#include "bn_sprite_tiles_items_emicas_spr_up_sad.h"
#include "bn_sprite_tiles_items_emicas_spr_up_sad_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_smile.h"
#include "bn_sprite_tiles_items_emicas_spr_up_smile_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_weaksmile.h"
#include "bn_sprite_tiles_items_emicas_spr_up_weaksmile_close.h"
#include "bn_sprite_tiles_items_emicas_spr_up_wink.h"
#include "bn_sprite_tiles_items_emicas_spr_up_wink_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_angry_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_awayfrown.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_blush.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_blush_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_closedsmile.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_closedsmile_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_evil.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_evil_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_frown.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_frown_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_grin.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_grin_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_happy.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_happy_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_neutral.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_neutral_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_pout.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_pout_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_sad_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_smile_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_weaksmile.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_weaksmile_close.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_wink.h"
#include "bn_sprite_tiles_items_eminude_spr_basic_wink_close.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_angry.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_awayfrown.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_awayfrown_close.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_blush.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_blush_close.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_closedsmile.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_closedsmile_close.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_evil.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_frown.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_grin.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_grin_close.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_happy.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_neutral.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_neutral_close.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_pout.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_sad.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_smile.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_weaksmile.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_wink.h"
#include "bn_sprite_tiles_items_emiwheel_spr_basic_wink_close.h"

namespace ks::smart_characters::emi {

static const bn::regular_bg_tiles_item* const slab_table[3] = {
    &bn::regular_bg_tiles_items::emi_tiles_0,
    &bn::regular_bg_tiles_items::emi_tiles_1,
    &bn::regular_bg_tiles_items::emi_tiles_2,
};

const tileset_data tileset = {
    /* slabs       */ slab_table,
    /* slab_count  */ 3,
    /* palette     */ &bn::bg_palette_items::pal_char_bg,
};

alignas(int) static const uint16_t emi_basic_gym_body_used[115] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114,
};

alignas(int) static const unsigned char emi_basic_gym_body_map_rle[296] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD1, 0x00, 0x04, 0x01,
    0x00, 0x02, 0x00, 0x03, 0xB6, 0x00, 0x0A, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08,
    0x00, 0x09, 0xB2, 0x00, 0x00, 0x0A, 0x86, 0x00, 0x02, 0x0B, 0x00, 0x0C, 0xB0, 0x00, 0x00, 0x0D,
    0x86, 0x00, 0x02, 0x0E, 0x00, 0x0F, 0xAE, 0x00, 0x02, 0x10, 0x00, 0x11, 0x86, 0x00, 0x02, 0x12,
    0x00, 0x13, 0xAE, 0x00, 0x02, 0x14, 0x00, 0x15, 0x86, 0x00, 0x04, 0x16, 0x00, 0x17, 0x00, 0x18,
    0xAC, 0x00, 0x10, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F,
    0x00, 0x20, 0x00, 0x21, 0xAC, 0x00, 0x10, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0xAE, 0x00, 0x0E, 0x2B, 0x00, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0xAE, 0x00, 0x0E, 0x33, 0x00, 0x34,
    0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0xAC, 0x00, 0x0A, 0x3B,
    0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x80, 0x00, 0x02, 0x41, 0x00, 0x42,
    0xAC, 0x00, 0x10, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49,
    0x00, 0x4A, 0x00, 0x4B, 0xAC, 0x00, 0x0E, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50,
    0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0xAE, 0x00, 0x0C, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57,
    0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0xAE, 0x00, 0x0E, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E,
    0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0xAE, 0x00, 0x0E, 0x63, 0x00, 0x64, 0x00, 0x65,
    0x00, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0xAC, 0x00, 0x02, 0x6B, 0x00, 0x6C,
    0x80, 0x00, 0x0A, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00, 0x92, 0x00, 0x00, 0x00,
};

const body emi_basic_gym_body = {
    /* used_tiles      */ emi_basic_gym_body_used,
    /* used_count      */ 115,
    /* map_compressed  */ emi_basic_gym_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 21,
    /* vis_y0          */ 9,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_basic_gym,
};

alignas(int) static const uint16_t emi_basic_body_used[119] = {
    0, 1, 2, 115, 116, 117, 118, 119, 120, 121, 122, 123, 12, 124, 125, 15,
    126, 127, 128, 19, 129, 21, 130, 131, 24, 132, 133, 134, 135, 136, 137, 138,
    139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 42, 149, 150, 151, 152, 153,
    154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169,
    170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185,
    186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201,
    202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217,
    218, 219, 220, 221, 222, 223, 224,
};

alignas(int) static const unsigned char emi_basic_body_map_rle[304] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD1, 0x00, 0x04, 0x01,
    0x00, 0x02, 0x00, 0x03, 0xB6, 0x00, 0x0A, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08,
    0x00, 0x09, 0xB2, 0x00, 0x00, 0x0A, 0x86, 0x00, 0x02, 0x0B, 0x00, 0x0C, 0xB0, 0x00, 0x00, 0x0D,
    0x86, 0x00, 0x02, 0x0E, 0x00, 0x0F, 0xAE, 0x00, 0x02, 0x10, 0x00, 0x11, 0x86, 0x00, 0x02, 0x12,
    0x00, 0x13, 0xAE, 0x00, 0x02, 0x14, 0x00, 0x15, 0x86, 0x00, 0x04, 0x16, 0x00, 0x17, 0x00, 0x18,
    0xAC, 0x00, 0x10, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F,
    0x00, 0x20, 0x00, 0x21, 0xAC, 0x00, 0x10, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0xAC, 0x00, 0x10, 0x2B, 0x00, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0xAE, 0x00, 0x0E, 0x34,
    0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0xAC, 0x00,
    0x0A, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x80, 0x00, 0x02, 0x42,
    0x00, 0x43, 0xAC, 0x00, 0x10, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49,
    0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0xAC, 0x00, 0x10, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50,
    0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0xAC, 0x00, 0x0E, 0x56, 0x00, 0x57,
    0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0xAC, 0x00, 0x0E, 0x5E,
    0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0xAE, 0x00,
    0x0E, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D,
    0xAC, 0x00, 0x02, 0x6E, 0x00, 0x6F, 0x80, 0x00, 0x0C, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73,
    0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x90, 0x00, 0x00, 0x00,
};

const body emi_basic_body = {
    /* used_tiles      */ emi_basic_body_used,
    /* used_count      */ 119,
    /* map_compressed  */ emi_basic_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 21,
    /* vis_y0          */ 9,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_basic,
};

alignas(int) static const uint16_t emi_excited_gym_body_used[109] = {
    0, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255,
    256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271,
    272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287,
    288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303,
    304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319,
    320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332,
};

alignas(int) static const unsigned char emi_excited_gym_body_map_rle[280] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8D, 0x00,
    0x0A, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0xB0, 0x00, 0x0C, 0x07,
    0x00, 0x08, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0xB0, 0x00, 0x02, 0x0E,
    0x00, 0x0F, 0x86, 0x00, 0x02, 0x10, 0x00, 0x11, 0xAE, 0x00, 0x02, 0x12, 0x00, 0x13, 0x86, 0x00,
    0x02, 0x14, 0x00, 0x15, 0xAE, 0x00, 0x02, 0x16, 0x00, 0x17, 0x86, 0x00, 0x06, 0x18, 0x00, 0x19,
    0x00, 0x1A, 0x00, 0x1B, 0xA8, 0x00, 0x04, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x86, 0x00, 0x04, 0x1F,
    0x00, 0x20, 0x00, 0x21, 0xAA, 0x00, 0x12, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0xAC, 0x00, 0x10, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0xAC, 0x00,
    0x10, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C,
    0x00, 0x3D, 0xAE, 0x00, 0x0C, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43,
    0x00, 0x44, 0xB0, 0x00, 0x0C, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A,
    0x00, 0x4B, 0xB0, 0x00, 0x0C, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51,
    0x00, 0x52, 0xB2, 0x00, 0x0A, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58,
    0xB2, 0x00, 0x0A, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0xB0, 0x00,
    0x0C, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0xB0, 0x00,
    0x0C, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00, 0x90, 0x00, 0x00, 0x00,
};

const body emi_excited_gym_body = {
    /* used_tiles      */ emi_excited_gym_body_used,
    /* used_count      */ 109,
    /* map_compressed  */ emi_excited_gym_body_map_rle,
    /* vis_x0          */ 11,
    /* vis_x1          */ 22,
    /* vis_y0          */ 10,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_excited_gym,
};

alignas(int) static const uint16_t emi_excited_body_used[111] = {
    0, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347,
    348, 349, 350, 351, 352, 353, 354, 355, 247, 356, 357, 358, 251, 359, 360, 361,
    362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377,
    378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393,
    394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409,
    410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425,
    426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440,
};

alignas(int) static const unsigned char emi_excited_body_map_rle[284] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8D, 0x00,
    0x0A, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0xB0, 0x00, 0x0E, 0x07,
    0x00, 0x08, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0x00, 0x0E, 0xAE, 0x00,
    0x02, 0x0F, 0x00, 0x10, 0x86, 0x00, 0x02, 0x11, 0x00, 0x12, 0xAE, 0x00, 0x02, 0x13, 0x00, 0x14,
    0x86, 0x00, 0x02, 0x15, 0x00, 0x16, 0xAE, 0x00, 0x02, 0x17, 0x00, 0x18, 0x86, 0x00, 0x06, 0x19,
    0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0xA8, 0x00, 0x04, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x86, 0x00,
    0x04, 0x20, 0x00, 0x21, 0x00, 0x22, 0xAA, 0x00, 0x12, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0xAC, 0x00, 0x10, 0x2D,
    0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35,
    0xAC, 0x00, 0x10, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C,
    0x00, 0x3D, 0x00, 0x3E, 0xAE, 0x00, 0x0C, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43,
    0x00, 0x44, 0x00, 0x45, 0xAE, 0x00, 0x0E, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A,
    0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0xB0, 0x00, 0x0C, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51,
    0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0xB2, 0x00, 0x0A, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58,
    0x00, 0x59, 0x00, 0x5A, 0xB2, 0x00, 0x0A, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F,
    0x00, 0x60, 0xB0, 0x00, 0x0C, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66,
    0x00, 0x67, 0xB0, 0x00, 0x0C, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D,
    0x00, 0x6E, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x90, 0x00, 0x00, 0x00,
};

const body emi_excited_body = {
    /* used_tiles      */ emi_excited_body_used,
    /* used_count      */ 111,
    /* map_compressed  */ emi_excited_body_map_rle,
    /* vis_x0          */ 11,
    /* vis_x1          */ 22,
    /* vis_y0          */ 10,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_excited,
};

alignas(int) static const uint16_t emi_sad_gym_body_used[97] = {
    0, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455,
    456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471,
    472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487,
    488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503,
    504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519,
    520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535,
    536,
};

alignas(int) static const unsigned char emi_sad_gym_body_map_rle[248] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD1, 0x00, 0x06, 0x01,
    0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x0C, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08,
    0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0xB8, 0x00, 0x04, 0x0C, 0x00, 0x0D, 0x00, 0x0E, 0xB8, 0x00,
    0x04, 0x0F, 0x00, 0x10, 0x00, 0x11, 0xB8, 0x00, 0x04, 0x12, 0x00, 0x13, 0x00, 0x14, 0xB8, 0x00,
    0x04, 0x15, 0x00, 0x16, 0x00, 0x17, 0xB0, 0x00, 0x0E, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B,
    0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0xAE, 0x00, 0x0E, 0x20, 0x00, 0x21, 0x00, 0x22,
    0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0xAE, 0x00, 0x0C, 0x28, 0x00, 0x29,
    0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0xB0, 0x00, 0x0C, 0x2F, 0x00, 0x30,
    0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0xB0, 0x00, 0x0A, 0x36, 0x00, 0x37,
    0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0xB2, 0x00, 0x0C, 0x3C, 0x00, 0x3D, 0x00, 0x3E,
    0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0xB0, 0x00, 0x0A, 0x43, 0x00, 0x44, 0x00, 0x45,
    0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0xB2, 0x00, 0x0A, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C,
    0x00, 0x4D, 0x00, 0x4E, 0xB2, 0x00, 0x0A, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53,
    0x00, 0x54, 0xB2, 0x00, 0x0A, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A,
    0xB2, 0x00, 0x0A, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00, 0x92, 0x00, 0x00, 0x00,
};

const body emi_sad_gym_body = {
    /* used_tiles      */ emi_sad_gym_body_used,
    /* used_count      */ 97,
    /* map_compressed  */ emi_sad_gym_body_map_rle,
    /* vis_x0          */ 13,
    /* vis_x1          */ 21,
    /* vis_y0          */ 9,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_sad_gym,
};

alignas(int) static const uint16_t emi_sad_body_used[95] = {
    0, 537, 538, 539, 444, 540, 541, 542, 543, 544, 545, 451, 546, 547, 548, 549,
    550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565,
    566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581,
    582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597,
    598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613,
    614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628,
};

alignas(int) static const unsigned char emi_sad_body_map_rle[244] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD1, 0x00, 0x06, 0x01,
    0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x0C, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08,
    0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0xB8, 0x00, 0x04, 0x0C, 0x00, 0x0D, 0x00, 0x0E, 0xB8, 0x00,
    0x04, 0x0F, 0x00, 0x10, 0x00, 0x11, 0xB8, 0x00, 0x04, 0x12, 0x00, 0x13, 0x00, 0x14, 0xB8, 0x00,
    0x04, 0x15, 0x00, 0x16, 0x00, 0x17, 0xB0, 0x00, 0x0E, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B,
    0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0xAE, 0x00, 0x0E, 0x20, 0x00, 0x21, 0x00, 0x22,
    0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0xAE, 0x00, 0x0C, 0x28, 0x00, 0x29,
    0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0xB0, 0x00, 0x0A, 0x2F, 0x00, 0x30,
    0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0xB2, 0x00, 0x0A, 0x35, 0x00, 0x36, 0x00, 0x37,
    0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0xB2, 0x00, 0x0A, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E,
    0x00, 0x3F, 0x00, 0x40, 0xB2, 0x00, 0x0A, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45,
    0x00, 0x46, 0xB2, 0x00, 0x0A, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C,
    0xB2, 0x00, 0x0A, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0xB2, 0x00,
    0x0A, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0xB2, 0x00, 0x0A, 0x59,
    0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
    0x92, 0x00, 0x00, 0x00,
};

const body emi_sad_body = {
    /* used_tiles      */ emi_sad_body_used,
    /* used_count      */ 95,
    /* map_compressed  */ emi_sad_body_map_rle,
    /* vis_x0          */ 13,
    /* vis_x1          */ 21,
    /* vis_y0          */ 9,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_sad,
};

alignas(int) static const uint16_t emi_basic_gym_close_body_used[176] = {
    0, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643,
    644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654, 655, 656, 657, 658, 659,
    660, 661, 662, 663, 664, 665, 666, 667, 668, 669, 670, 671, 672, 673, 674, 675,
    676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 686, 483, 687, 688, 689, 690,
    691, 692, 693, 694, 695, 696, 697, 698, 699, 700, 701, 702, 703, 704, 705, 706,
    707, 708, 709, 710, 711, 712, 713, 714, 715, 716, 717, 718, 719, 720, 721, 722,
    723, 724, 725, 726, 727, 728, 729, 730, 731, 732, 733, 734, 735, 736, 737, 738,
    739, 740, 741, 742, 743, 744, 745, 746, 747, 748, 749, 750, 751, 752, 753, 754,
    755, 756, 757, 758, 759, 760, 761, 762, 763, 764, 765, 766, 767, 768, 769, 770,
    771, 772, 773, 774, 775, 776, 777, 778, 779, 780, 781, 782, 783, 784, 785, 786,
    787, 788, 789, 790, 791, 792, 793, 794, 795, 796, 797, 798, 799, 800, 801, 802,
};

alignas(int) static const unsigned char emi_basic_gym_close_body_map_rle[432] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8D, 0x00, 0x0C, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x08, 0xAA, 0x00,
    0x00, 0x09, 0x8E, 0x00, 0x02, 0x0A, 0x00, 0x0B, 0xA8, 0x00, 0x00, 0x0C, 0x8E, 0x00, 0x02, 0x0D,
    0x00, 0x0E, 0xA8, 0x00, 0x00, 0x0F, 0x8E, 0x00, 0x02, 0x10, 0x00, 0x11, 0xA8, 0x00, 0x00, 0x12,
    0x8E, 0x00, 0x02, 0x13, 0x00, 0x14, 0xA6, 0x00, 0x02, 0x15, 0x00, 0x16, 0x8E, 0x00, 0x02, 0x17,
    0x00, 0x18, 0xA6, 0x00, 0x02, 0x19, 0x00, 0x1A, 0x8E, 0x00, 0x04, 0x1B, 0x00, 0x1C, 0x00, 0x1D,
    0xA4, 0x00, 0x02, 0x1E, 0x00, 0x1F, 0x8E, 0x00, 0x06, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23,
    0xA2, 0x00, 0x1A, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A,
    0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0xA2, 0x00,
    0x1A, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39,
    0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0xA2, 0x00, 0x18, 0x40,
    0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48,
    0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0xA6, 0x00, 0x16, 0x4D, 0x00, 0x4E, 0x00, 0x4F,
    0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57,
    0x00, 0x58, 0xA6, 0x00, 0x18, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x53,
    0x00, 0x53, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0xA4, 0x00,
    0x10, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B,
    0x00, 0x6C, 0x80, 0x00, 0x04, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0xA4, 0x00, 0x10, 0x70, 0x00, 0x71,
    0x00, 0x72, 0x00, 0x73, 0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0x00, 0x77, 0x00, 0x78, 0x82, 0x00,
    0x04, 0x79, 0x00, 0x7A, 0x00, 0x7B, 0xA2, 0x00, 0x10, 0x7C, 0x00, 0x7D, 0x00, 0x7E, 0x00, 0x7F,
    0x00, 0x80, 0x00, 0x81, 0x00, 0x82, 0x00, 0x83, 0x00, 0x84, 0x80, 0x00, 0x06, 0x85, 0x00, 0x86,
    0x00, 0x87, 0x00, 0x88, 0xA0, 0x00, 0x1A, 0x89, 0x00, 0x8A, 0x00, 0x8B, 0x00, 0x8C, 0x00, 0x8D,
    0x00, 0x8E, 0x00, 0x8F, 0x00, 0x90, 0x00, 0x91, 0x00, 0x92, 0x00, 0x93, 0x00, 0x94, 0x00, 0x95,
    0x00, 0x96, 0xA2, 0x00, 0x18, 0x97, 0x00, 0x98, 0x00, 0x99, 0x00, 0x9A, 0x00, 0x9B, 0x00, 0x9C,
    0x00, 0x9D, 0x00, 0x9E, 0x00, 0x9F, 0x00, 0xA0, 0x00, 0xA1, 0x00, 0xA2, 0x00, 0xA3, 0xA4, 0x00,
    0x16, 0xA4, 0x00, 0xA5, 0x00, 0xA6, 0x00, 0xA7, 0x00, 0xA8, 0x00, 0xA9, 0x00, 0xAA, 0x00, 0xAB,
    0x00, 0xAC, 0x00, 0xAD, 0x00, 0xAE, 0x00, 0xAF, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8E, 0x00,
};

const body emi_basic_gym_close_body = {
    /* used_tiles      */ emi_basic_gym_close_body_used,
    /* used_count      */ 176,
    /* map_compressed  */ emi_basic_gym_close_body_map_rle,
    /* vis_x0          */ 9,
    /* vis_x1          */ 24,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_basic_gym_close,
};

alignas(int) static const uint16_t emi_basic_close_body_used[178] = {
    0, 629, 803, 804, 805, 806, 807, 808, 809, 637, 810, 639, 811, 812, 813, 814,
    815, 816, 646, 817, 818, 819, 820, 821, 822, 823, 824, 825, 826, 827, 828, 829,
    830, 831, 832, 663, 833, 834, 835, 836, 837, 838, 839, 840, 841, 710, 842, 843,
    844, 845, 846, 847, 848, 849, 850, 851, 852, 853, 854, 855, 856, 857, 858, 691,
    859, 860, 861, 862, 863, 864, 865, 866, 867, 868, 869, 870, 871, 872, 873, 874,
    875, 876, 877, 878, 879, 880, 881, 882, 883, 884, 885, 886, 887, 888, 889, 890,
    891, 892, 893, 894, 895, 896, 897, 898, 899, 900, 901, 902, 903, 904, 905, 906,
    907, 908, 909, 910, 911, 912, 913, 914, 915, 916, 917, 918, 919, 920, 921, 922,
    923, 924, 925, 926, 927, 928, 929, 930, 931, 932, 933, 934, 935, 936, 937, 938,
    939, 940, 941, 942, 943, 944, 945, 946, 947, 948, 949, 950, 951, 952, 953, 954,
    955, 956, 957, 958, 959, 960, 961, 962, 963, 964, 965, 966, 967, 968, 969, 970,
    971, 972,
};

alignas(int) static const unsigned char emi_basic_close_body_map_rle[440] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8D, 0x00, 0x0C, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x08, 0xAA, 0x00,
    0x00, 0x09, 0x8E, 0x00, 0x02, 0x0A, 0x00, 0x0B, 0xA8, 0x00, 0x00, 0x0C, 0x8E, 0x00, 0x02, 0x0D,
    0x00, 0x0E, 0xA8, 0x00, 0x00, 0x0F, 0x8E, 0x00, 0x02, 0x10, 0x00, 0x11, 0xA8, 0x00, 0x00, 0x12,
    0x8E, 0x00, 0x02, 0x13, 0x00, 0x14, 0xA6, 0x00, 0x02, 0x15, 0x00, 0x16, 0x8E, 0x00, 0x02, 0x17,
    0x00, 0x18, 0xA6, 0x00, 0x02, 0x19, 0x00, 0x1A, 0x8E, 0x00, 0x04, 0x1B, 0x00, 0x1C, 0x00, 0x1D,
    0xA4, 0x00, 0x02, 0x1E, 0x00, 0x1F, 0x8E, 0x00, 0x06, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23,
    0xA2, 0x00, 0x1A, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A,
    0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0xA2, 0x00,
    0x1A, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39,
    0x00, 0x3A, 0x00, 0x3B, 0x00, 0x2D, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0xA2, 0x00, 0x18, 0x3F,
    0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47,
    0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0xA6, 0x00, 0x18, 0x4C, 0x00, 0x4D, 0x00, 0x4E,
    0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56,
    0x00, 0x57, 0x00, 0x58, 0xA4, 0x00, 0x18, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D,
    0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65,
    0xA4, 0x00, 0x10, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C,
    0x00, 0x6D, 0x00, 0x6E, 0x80, 0x00, 0x04, 0x6F, 0x00, 0x70, 0x00, 0x71, 0xA4, 0x00, 0x10, 0x72,
    0x00, 0x73, 0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0x00, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00, 0x7A,
    0x80, 0x00, 0x06, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E, 0xA0, 0x00, 0x12, 0x7F, 0x00, 0x80,
    0x00, 0x81, 0x00, 0x82, 0x00, 0x83, 0x00, 0x84, 0x00, 0x2D, 0x00, 0x85, 0x00, 0x86, 0x00, 0x87,
    0x80, 0x00, 0x06, 0x88, 0x00, 0x89, 0x00, 0x8A, 0x00, 0x8B, 0xA0, 0x00, 0x1A, 0x8C, 0x00, 0x8D,
    0x00, 0x8E, 0x00, 0x8F, 0x00, 0x90, 0x00, 0x91, 0x00, 0x2D, 0x00, 0x92, 0x00, 0x93, 0x00, 0x94,
    0x00, 0x95, 0x00, 0x96, 0x00, 0x97, 0x00, 0x98, 0xA2, 0x00, 0x18, 0x99, 0x00, 0x9A, 0x00, 0x9B,
    0x00, 0x9C, 0x00, 0x9D, 0x00, 0x9E, 0x00, 0x2D, 0x00, 0x9F, 0x00, 0xA0, 0x00, 0xA1, 0x00, 0xA2,
    0x00, 0xA3, 0x00, 0xA4, 0xA4, 0x00, 0x18, 0xA5, 0x00, 0xA6, 0x00, 0xA7, 0x00, 0xA8, 0x00, 0xA9,
    0x00, 0xAA, 0x00, 0xAB, 0x00, 0xAC, 0x00, 0xAD, 0x00, 0xAE, 0x00, 0xAF, 0x00, 0xB0, 0x00, 0xB1,
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8C, 0x00,
};

const body emi_basic_close_body = {
    /* used_tiles      */ emi_basic_close_body_used,
    /* used_count      */ 178,
    /* map_compressed  */ emi_basic_close_body_map_rle,
    /* vis_x0          */ 9,
    /* vis_x1          */ 24,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_basic_close,
};

alignas(int) static const uint16_t emi_excited_gym_close_body_used[172] = {
    0, 973, 974, 346, 975, 976, 977, 978, 979, 980, 981, 982, 983, 984, 985, 986,
    987, 988, 989, 990, 991, 992, 993, 994, 995, 996, 997, 998, 999, 1000, 1001, 1002,
    1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018,
    1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034,
    1035, 1036, 1037, 1038, 1039, 1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050,
    1051, 1052, 1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1066,
    1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082,
    1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098,
    1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114,
    1115, 1116, 1117, 1118, 1119, 1120, 1121, 1122, 1123, 1124, 1125, 1126, 1127, 1128, 1129, 1130,
    1131, 1132, 1133, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142,
};

alignas(int) static const unsigned char emi_excited_gym_close_body_map_rle[420] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x93, 0x00, 0x04, 0x01, 0x00, 0x02,
    0x00, 0x03, 0xB4, 0x00, 0x0E, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00, 0x09,
    0x00, 0x0A, 0x00, 0x0B, 0xAA, 0x00, 0x00, 0x0C, 0x8E, 0x00, 0x00, 0x0D, 0xAA, 0x00, 0x00, 0x0E,
    0x8E, 0x00, 0x02, 0x0F, 0x00, 0x10, 0xA8, 0x00, 0x00, 0x11, 0x8E, 0x00, 0x02, 0x12, 0x00, 0x13,
    0xA8, 0x00, 0x00, 0x14, 0x8E, 0x00, 0x02, 0x15, 0x00, 0x16, 0xA6, 0x00, 0x02, 0x17, 0x00, 0x18,
    0x8E, 0x00, 0x04, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0xA4, 0x00, 0x02, 0x1C, 0x00, 0x1D, 0x8E, 0x00,
    0x06, 0x1E, 0x00, 0x1F, 0x00, 0x20, 0x00, 0x21, 0xA0, 0x00, 0x04, 0x22, 0x00, 0x23, 0x00, 0x24,
    0x90, 0x00, 0x06, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x9E, 0x00, 0x04, 0x29, 0x00, 0x2A,
    0x00, 0x2B, 0x8E, 0x00, 0x08, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x9E, 0x00,
    0x18, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38,
    0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x80, 0x00, 0x00, 0x3E, 0xA0, 0x00,
    0x1C, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46,
    0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0xA2, 0x00,
    0x18, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55,
    0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0xA6, 0x00, 0x16, 0x5B, 0x00, 0x5C,
    0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64,
    0x00, 0x65, 0x00, 0x66, 0xA6, 0x00, 0x16, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B,
    0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0xA6, 0x00,
    0x16, 0x73, 0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0x00, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00, 0x7A,
    0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E, 0xA6, 0x00, 0x16, 0x7F, 0x00, 0x80, 0x00, 0x81,
    0x00, 0x82, 0x00, 0x83, 0x00, 0x84, 0x00, 0x85, 0x00, 0x86, 0x00, 0x87, 0x00, 0x88, 0x00, 0x89,
    0x00, 0x8A, 0xA6, 0x00, 0x16, 0x8B, 0x00, 0x8C, 0x00, 0x8D, 0x00, 0x8E, 0x00, 0x8F, 0x00, 0x90,
    0x00, 0x91, 0x00, 0x92, 0x00, 0x93, 0x00, 0x94, 0x00, 0x95, 0x00, 0x96, 0xA6, 0x00, 0x14, 0x97,
    0x00, 0x98, 0x00, 0x99, 0x00, 0x9A, 0x00, 0x9B, 0x00, 0x9C, 0x00, 0x9D, 0x00, 0x9E, 0x00, 0x9F,
    0x00, 0xA0, 0x00, 0xA1, 0xAA, 0x00, 0x12, 0xA2, 0x00, 0xA3, 0x00, 0xA4, 0x00, 0xA5, 0x00, 0xA6,
    0x00, 0xA7, 0x00, 0xA8, 0x00, 0xA9, 0x00, 0xAA, 0x00, 0xAB, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
    0x8E, 0x00, 0x00, 0x00,
};

const body emi_excited_gym_close_body = {
    /* used_tiles      */ emi_excited_gym_close_body_used,
    /* used_count      */ 172,
    /* map_compressed  */ emi_excited_gym_close_body_map_rle,
    /* vis_x0          */ 8,
    /* vis_x1          */ 24,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_excited_gym_close,
};

alignas(int) static const uint16_t emi_excited_close_body_used[173] = {
    0, 1143, 1144, 346, 1145, 1146, 1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156,
    1157, 1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167, 1168, 1169, 1170, 1171, 1172,
    1173, 1174, 1175, 1176, 1177, 1178, 1179, 1180, 1181, 1182, 1183, 1184, 1185, 1186, 1187, 1188,
    1019, 1189, 1190, 1191, 1192, 1193, 1194, 1195, 1196, 1197, 1198, 1199, 1200, 1201, 1202, 1203,
    1204, 1205, 1206, 1207, 1208, 1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1048, 1218,
    1219, 1220, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 710, 1229, 1230, 1231, 1232, 1233,
    1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245, 1246, 1247, 1248, 1249,
    1250, 1251, 1252, 1253, 1254, 1255, 1256, 1257, 1258, 1259, 1260, 1261, 1262, 1263, 1264, 1265,
    1266, 1267, 1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 1276, 1277, 1278, 1279, 1280, 1281,
    1282, 1283, 1284, 1285, 1286, 1287, 1288, 1289, 1290, 1291, 1292, 1293, 1294, 1295, 1296, 1297,
    1298, 1299, 1300, 1301, 1302, 1303, 1304, 1305, 1306, 1307, 1308, 1309, 1310,
};

alignas(int) static const unsigned char emi_excited_close_body_map_rle[420] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x93, 0x00, 0x04, 0x01, 0x00, 0x02,
    0x00, 0x03, 0xB4, 0x00, 0x0E, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00, 0x09,
    0x00, 0x0A, 0x00, 0x0B, 0xAA, 0x00, 0x00, 0x0C, 0x8E, 0x00, 0x00, 0x0D, 0xAA, 0x00, 0x00, 0x0E,
    0x8E, 0x00, 0x02, 0x0F, 0x00, 0x10, 0xA8, 0x00, 0x00, 0x11, 0x8E, 0x00, 0x02, 0x12, 0x00, 0x13,
    0xA8, 0x00, 0x00, 0x14, 0x8E, 0x00, 0x02, 0x15, 0x00, 0x16, 0xA6, 0x00, 0x02, 0x17, 0x00, 0x18,
    0x8E, 0x00, 0x04, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0xA4, 0x00, 0x02, 0x1C, 0x00, 0x1D, 0x8E, 0x00,
    0x06, 0x1E, 0x00, 0x1F, 0x00, 0x20, 0x00, 0x21, 0xA0, 0x00, 0x04, 0x22, 0x00, 0x23, 0x00, 0x24,
    0x90, 0x00, 0x06, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x9E, 0x00, 0x04, 0x29, 0x00, 0x2A,
    0x00, 0x2B, 0x8E, 0x00, 0x08, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x9E, 0x00,
    0x1C, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38,
    0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0xA0, 0x00,
    0x1C, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47,
    0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0xA2, 0x00,
    0x18, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56,
    0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0xA6, 0x00, 0x16, 0x5C, 0x00, 0x5D,
    0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65,
    0x00, 0x66, 0x00, 0x67, 0xA6, 0x00, 0x16, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C,
    0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73, 0xA6, 0x00,
    0x16, 0x74, 0x00, 0x75, 0x00, 0x76, 0x00, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00, 0x7A, 0x00, 0x7B,
    0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E, 0x00, 0x7F, 0xA6, 0x00, 0x16, 0x80, 0x00, 0x81, 0x00, 0x82,
    0x00, 0x83, 0x00, 0x84, 0x00, 0x85, 0x00, 0x86, 0x00, 0x87, 0x00, 0x88, 0x00, 0x89, 0x00, 0x8A,
    0x00, 0x8B, 0xA6, 0x00, 0x16, 0x8C, 0x00, 0x8D, 0x00, 0x8E, 0x00, 0x8F, 0x00, 0x90, 0x00, 0x91,
    0x00, 0x92, 0x00, 0x93, 0x00, 0x94, 0x00, 0x95, 0x00, 0x96, 0x00, 0x97, 0xA6, 0x00, 0x16, 0x98,
    0x00, 0x99, 0x00, 0x9A, 0x00, 0x9B, 0x00, 0x9C, 0x00, 0x9D, 0x00, 0x5A, 0x00, 0x9E, 0x00, 0x9F,
    0x00, 0xA0, 0x00, 0xA1, 0x00, 0xA2, 0xA8, 0x00, 0x12, 0xA3, 0x00, 0xA4, 0x00, 0xA5, 0x00, 0xA6,
    0x00, 0xA7, 0x00, 0xA8, 0x00, 0xA9, 0x00, 0xAA, 0x00, 0xAB, 0x00, 0xAC, 0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0x8E, 0x00,
};

const body emi_excited_close_body = {
    /* used_tiles      */ emi_excited_close_body_used,
    /* used_count      */ 173,
    /* map_compressed  */ emi_excited_close_body_map_rle,
    /* vis_x0          */ 8,
    /* vis_x1          */ 24,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_excited_close,
};

alignas(int) static const uint16_t emi_sad_gym_close_body_used[136] = {
    0, 1311, 1312, 1313, 1314, 1315, 1316, 1317, 451, 1318, 1319, 1320, 1321, 1322, 1323, 1324,
    1325, 1326, 1327, 1328, 1329, 1330, 1331, 1332, 1047, 1333, 1334, 1335, 1336, 1337, 1338, 1339,
    1340, 1341, 1342, 1343, 1344, 1345, 1346, 1347, 1348, 1349, 1350, 1351, 1352, 1353, 1354, 1355,
    1356, 1357, 1358, 1359, 1360, 1361, 1362, 1363, 710, 1364, 1365, 1366, 1367, 1368, 1369, 1370,
    1371, 1372, 1373, 1374, 1375, 1376, 1377, 1378, 1379, 1380, 1381, 1382, 1383, 1384, 1385, 1386,
    1387, 1388, 1389, 1390, 1391, 1392, 1393, 1394, 1395, 1396, 1397, 1398, 1399, 1400, 1401, 1402,
    1403, 1404, 1405, 1406, 1407, 1408, 1409, 1410, 1140, 1411, 1412, 1413, 1414, 1415, 1416, 1417,
    1418, 1419, 1420, 1421, 1422, 1423, 1424, 1425, 1426, 1427, 1428, 1429, 1430, 1431, 1432, 1433,
    1434, 1435, 1436, 1437, 1438, 1439, 1440, 1441,
};

alignas(int) static const unsigned char emi_sad_gym_close_body_map_rle[340] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8F, 0x00, 0x0A, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0xC0, 0x00, 0x02, 0x07, 0x00, 0x08, 0xA8, 0x00,
    0x00, 0x09, 0x8E, 0x00, 0x02, 0x0A, 0x00, 0x0B, 0xA8, 0x00, 0x00, 0x0C, 0x8E, 0x00, 0x02, 0x0D,
    0x00, 0x0E, 0xA8, 0x00, 0x00, 0x0F, 0x8E, 0x00, 0x02, 0x10, 0x00, 0x11, 0xBA, 0x00, 0x02, 0x12,
    0x00, 0x13, 0xBA, 0x00, 0x02, 0x14, 0x00, 0x15, 0xBA, 0x00, 0x04, 0x16, 0x00, 0x17, 0x00, 0x18,
    0xB8, 0x00, 0x04, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0xAA, 0x00, 0x12, 0x1C, 0x00, 0x1D, 0x00, 0x1E,
    0x00, 0x1F, 0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0xA8, 0x00,
    0x16, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0xA4, 0x00, 0x16, 0x32, 0x00, 0x33, 0x00, 0x34,
    0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C,
    0x00, 0x3D, 0xA6, 0x00, 0x14, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x38,
    0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0xAA, 0x00, 0x12, 0x48, 0x00, 0x49,
    0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51,
    0xAA, 0x00, 0x10, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58,
    0x00, 0x59, 0x00, 0x5A, 0xAC, 0x00, 0x10, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F,
    0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0xAC, 0x00, 0x12, 0x64, 0x00, 0x65, 0x00, 0x66,
    0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0xAA, 0x00,
    0x12, 0x6E, 0x00, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73, 0x00, 0x74, 0x00, 0x75,
    0x00, 0x76, 0x00, 0x77, 0xAA, 0x00, 0x10, 0x78, 0x00, 0x79, 0x00, 0x7A, 0x00, 0x7B, 0x00, 0x7C,
    0x00, 0x38, 0x00, 0x7D, 0x00, 0x7E, 0x00, 0x7F, 0xAC, 0x00, 0x10, 0x80, 0x00, 0x81, 0x00, 0x82,
    0x00, 0x83, 0x00, 0x84, 0x00, 0x38, 0x00, 0x85, 0x00, 0x86, 0x00, 0x87, 0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0x90, 0x00,
};

const body emi_sad_gym_close_body = {
    /* used_tiles      */ emi_sad_gym_close_body_used,
    /* used_count      */ 136,
    /* map_compressed  */ emi_sad_gym_close_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 23,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_sad_gym_close,
};

alignas(int) static const uint16_t emi_sad_close_body_used[138] = {
    0, 1311, 1442, 1443, 1444, 1445, 1316, 1446, 1157, 1318, 1447, 1448, 1449, 1322, 1450, 1324,
    1451, 1452, 1453, 1454, 1455, 1456, 1457, 1458, 1047, 1459, 1460, 1461, 1462, 1463, 1464, 1465,
    1466, 1467, 1468, 1469, 1470, 1471, 1472, 1473, 1474, 1475, 1476, 1477, 1478, 1479, 1480, 1481,
    1357, 1482, 1483, 1484, 1485, 1486, 1487, 1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, 1496,
    1497, 1498, 1499, 1500, 1501, 1502, 1503, 1504, 1505, 1506, 1507, 1508, 1509, 1510, 1511, 1512,
    1513, 1514, 1515, 1516, 1517, 1518, 1519, 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527, 1528,
    1529, 1530, 1531, 1532, 1533, 1534, 1535, 1536, 1537, 1538, 1539, 1540, 1541, 1542, 1543, 1544,
    1545, 1546, 1547, 1548, 1549, 1550, 1551, 1552, 1553, 1554, 1555, 1556, 1557, 1558, 1559, 1560,
    1561, 1562, 1563, 1564, 1565, 1566, 710, 1567, 1568, 1569,
};

alignas(int) static const unsigned char emi_sad_close_body_map_rle[340] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8F, 0x00, 0x0A, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0xC0, 0x00, 0x02, 0x07, 0x00, 0x08, 0xA8, 0x00,
    0x00, 0x09, 0x8E, 0x00, 0x02, 0x0A, 0x00, 0x0B, 0xA8, 0x00, 0x00, 0x0C, 0x8E, 0x00, 0x02, 0x0D,
    0x00, 0x0E, 0xA8, 0x00, 0x00, 0x0F, 0x8E, 0x00, 0x02, 0x10, 0x00, 0x11, 0xBA, 0x00, 0x02, 0x12,
    0x00, 0x13, 0xBA, 0x00, 0x02, 0x14, 0x00, 0x15, 0xBA, 0x00, 0x04, 0x16, 0x00, 0x17, 0x00, 0x18,
    0xB8, 0x00, 0x04, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0xAA, 0x00, 0x12, 0x1C, 0x00, 0x1D, 0x00, 0x1E,
    0x00, 0x1F, 0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0xA8, 0x00,
    0x10, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0x80, 0x00, 0x02, 0x2F, 0x00, 0x30, 0xA4, 0x00, 0x16, 0x31, 0x00, 0x32, 0x00, 0x33,
    0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B,
    0x00, 0x3C, 0xA6, 0x00, 0x14, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42,
    0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0xA8, 0x00, 0x14, 0x48, 0x00, 0x49,
    0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51,
    0x00, 0x52, 0xA8, 0x00, 0x12, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58,
    0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0xAC, 0x00, 0x10, 0x5D, 0x00, 0x5E, 0x00, 0x5F,
    0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0xAC, 0x00, 0x10, 0x66,
    0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E,
    0xAC, 0x00, 0x10, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73, 0x00, 0x74, 0x00, 0x75,
    0x00, 0x76, 0x00, 0x77, 0xAC, 0x00, 0x10, 0x78, 0x00, 0x79, 0x00, 0x7A, 0x00, 0x7B, 0x00, 0x7C,
    0x00, 0x7D, 0x00, 0x7E, 0x00, 0x7F, 0x00, 0x80, 0xAC, 0x00, 0x10, 0x81, 0x00, 0x82, 0x00, 0x83,
    0x00, 0x84, 0x00, 0x85, 0x00, 0x86, 0x00, 0x87, 0x00, 0x88, 0x00, 0x89, 0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0x90, 0x00,
};

const body emi_sad_close_body = {
    /* used_tiles      */ emi_sad_close_body_used,
    /* used_count      */ 138,
    /* map_compressed  */ emi_sad_close_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 23,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emi_thumb_sad_close,
};

alignas(int) static const uint16_t emicas_basic_body_used[95] = {
    0, 558, 1570, 1571, 1572, 1573, 1574, 1575, 1576, 1577, 1578, 1579, 1580, 1581, 1582, 1583,
    1584, 1585, 1586, 1587, 1588, 1589, 1590, 1591, 1592, 1593, 1594, 1595, 1596, 1597, 1598, 1599,
    1600, 1601, 1602, 1603, 1604, 1605, 1606, 1607, 1608, 1609, 1610, 1611, 1612, 1613, 1614, 1615,
    1616, 1617, 1618, 1619, 1620, 1621, 1622, 1623, 1624, 1625, 1626, 1627, 1628, 1629, 1630, 1631,
    1632, 1633, 1634, 1635, 1636, 1637, 1638, 1639, 1640, 1641, 1642, 1643, 1644, 1645, 1646, 1647,
    1648, 1649, 1650, 1651, 1652, 1653, 1654, 1655, 1656, 1657, 1658, 1659, 1660, 1661, 1662,
};

alignas(int) static const unsigned char emicas_basic_body_map_rle[248] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD1, 0x00, 0x06, 0x01,
    0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x0A, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08,
    0x00, 0x09, 0x00, 0x0A, 0xB0, 0x00, 0x04, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0xB8, 0x00, 0x04, 0x0E,
    0x00, 0x0F, 0x00, 0x10, 0xB8, 0x00, 0x04, 0x11, 0x00, 0x12, 0x00, 0x13, 0xB6, 0x00, 0x02, 0x14,
    0x00, 0x15, 0x80, 0x00, 0x00, 0x16, 0xB6, 0x00, 0x0E, 0x17, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A,
    0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0xB0, 0x00, 0x0C, 0x1F, 0x00, 0x20, 0x00, 0x21,
    0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0xB2, 0x00, 0x0A, 0x26, 0x00, 0x27, 0x00, 0x28,
    0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0xB0, 0x00, 0x0C, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F,
    0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0xB0, 0x00, 0x0C, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36,
    0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0xB0, 0x00, 0x0C, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0xB0, 0x00, 0x0C, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44,
    0x00, 0x3E, 0x00, 0x45, 0x00, 0x46, 0xB2, 0x00, 0x0A, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A,
    0x00, 0x4B, 0x00, 0x4C, 0xB2, 0x00, 0x0A, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51,
    0x00, 0x52, 0xB2, 0x00, 0x0A, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58,
    0xB2, 0x00, 0x0A, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00, 0x92, 0x00, 0x00, 0x00,
};

const body emicas_basic_body = {
    /* used_tiles      */ emicas_basic_body_used,
    /* used_count      */ 95,
    /* map_compressed  */ emicas_basic_body_map_rle,
    /* vis_x0          */ 11,
    /* vis_x1          */ 19,
    /* vis_y0          */ 9,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emicas_thumb_basic,
};

alignas(int) static const uint16_t emicas_up_body_used[106] = {
    0, 558, 1663, 1664, 1665, 1666, 1667, 1668, 1669, 1670, 1578, 1579, 1671, 1672, 1673, 1674,
    1675, 1676, 1677, 1587, 1588, 1678, 1679, 1591, 1680, 1681, 1682, 1683, 1684, 1685, 1686, 1687,
    1688, 1689, 1690, 1691, 1692, 1693, 1694, 1695, 1696, 1697, 1698, 1699, 1700, 1701, 1702, 1703,
    1704, 1705, 1706, 1707, 1708, 1709, 1710, 1711, 1712, 1713, 1714, 1715, 1716, 1624, 1717, 1718,
    1719, 1720, 1721, 1628, 1629, 1722, 1723, 1724, 1725, 1726, 1727, 1728, 1729, 1730, 1731, 1732,
    1733, 1734, 1735, 1736, 1737, 1738, 1739, 1740, 1741, 1742, 1743, 1744, 1745, 1746, 1747, 1748,
    1749, 1750, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758,
};

alignas(int) static const unsigned char emicas_up_body_map_rle[268] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD1, 0x00, 0x06, 0x01,
    0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x0A, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08,
    0x00, 0x09, 0x00, 0x0A, 0xB0, 0x00, 0x04, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0xB8, 0x00, 0x04, 0x0E,
    0x00, 0x0F, 0x00, 0x10, 0xB8, 0x00, 0x04, 0x11, 0x00, 0x12, 0x00, 0x13, 0xB6, 0x00, 0x02, 0x14,
    0x00, 0x15, 0x80, 0x00, 0x00, 0x16, 0xB6, 0x00, 0x0E, 0x17, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A,
    0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0xB0, 0x00, 0x0C, 0x1F, 0x00, 0x20, 0x00, 0x21,
    0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0xAE, 0x00, 0x0E, 0x26, 0x00, 0x27, 0x00, 0x28,
    0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0xAE, 0x00, 0x10, 0x2E, 0x00, 0x2F,
    0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0xAA, 0x00,
    0x04, 0x37, 0x00, 0x38, 0x00, 0x39, 0x80, 0x00, 0x0A, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0xAC, 0x00, 0x10, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44,
    0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0xAE, 0x00, 0x0E, 0x49, 0x00, 0x4A, 0x00, 0x4B,
    0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0xB0, 0x00, 0x0C, 0x51, 0x00, 0x52,
    0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0xB0, 0x00, 0x0A, 0x58, 0x00, 0x59,
    0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0xB2, 0x00, 0x0A, 0x5E, 0x00, 0x5F, 0x00, 0x60,
    0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0xB2, 0x00, 0x0A, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x67,
    0x00, 0x68, 0x00, 0x69, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x92, 0x00,
};

const body emicas_up_body = {
    /* used_tiles      */ emicas_up_body_used,
    /* used_count      */ 106,
    /* map_compressed  */ emicas_up_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 20,
    /* vis_y0          */ 9,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emicas_thumb_up,
};

alignas(int) static const uint16_t emicas_basic_close_body_used[123] = {
    0, 1759, 1760, 1761, 1762, 1763, 1764, 1765, 1766, 1767, 1768, 1769, 1770, 1771, 1772, 1773,
    1774, 1775, 1776, 1777, 1778, 1779, 1780, 1781, 1782, 1783, 1784, 1785, 1786, 1787, 1788, 1789,
    1790, 1791, 1792, 1793, 1794, 1795, 1796, 1797, 1798, 1799, 895, 710, 1800, 1801, 1802, 1803,
    1804, 1805, 1806, 1807, 1808, 1809, 1810, 1811, 1812, 1813, 1814, 1815, 1816, 1817, 1818, 1819,
    1820, 1821, 1822, 1823, 1824, 1825, 1630, 1826, 1827, 1828, 1829, 1830, 1831, 1832, 1833, 1834,
    1835, 1836, 1837, 1838, 1839, 1840, 1841, 1842, 1843, 1844, 1845, 1846, 1847, 1848, 1849, 1850,
    1851, 1852, 1853, 1854, 1855, 1856, 1857, 1858, 1859, 1860, 1861, 1862, 1863, 1864, 1865, 1866,
    1867, 1868, 1869, 1870, 1871, 1872, 1873, 1874, 1875, 1876, 1877,
};

alignas(int) static const unsigned char emicas_basic_close_body_map_rle[324] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8F, 0x00, 0x0E, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0xAE, 0x00, 0x00, 0x09,
    0xBA, 0x00, 0x02, 0x0A, 0x00, 0x0B, 0xBA, 0x00, 0x02, 0x0C, 0x00, 0x0D, 0xBA, 0x00, 0x02, 0x0E,
    0x00, 0x0F, 0xB8, 0x00, 0x04, 0x10, 0x00, 0x11, 0x00, 0x12, 0xB8, 0x00, 0x02, 0x13, 0x00, 0x14,
    0xBA, 0x00, 0x02, 0x15, 0x00, 0x16, 0xB8, 0x00, 0x02, 0x17, 0x00, 0x18, 0x80, 0x00, 0x00, 0x19,
    0xB8, 0x00, 0x00, 0x1A, 0x80, 0x00, 0x10, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F,
    0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0xA8, 0x00, 0x14, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E,
    0xAA, 0x00, 0x12, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35,
    0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0xAA, 0x00, 0x10, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C,
    0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0xAC, 0x00, 0x10, 0x42, 0x00, 0x43,
    0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0xAC, 0x00,
    0x10, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52,
    0x00, 0x53, 0xAC, 0x00, 0x10, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x46, 0x00, 0x58,
    0x00, 0x59, 0x00, 0x46, 0x00, 0x5A, 0xAC, 0x00, 0x10, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E,
    0x00, 0x5F, 0x00, 0x60, 0x00, 0x46, 0x00, 0x46, 0x00, 0x61, 0xAC, 0x00, 0x12, 0x62, 0x00, 0x63,
    0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x46, 0x00, 0x46, 0x00, 0x46, 0x00, 0x67, 0x00, 0x68,
    0xAA, 0x00, 0x12, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x46,
    0x00, 0x6F, 0x00, 0x70, 0x00, 0x71, 0xAA, 0x00, 0x12, 0x72, 0x00, 0x73, 0x00, 0x74, 0x00, 0x75,
    0x00, 0x76, 0x00, 0x77, 0x00, 0x46, 0x00, 0x78, 0x00, 0x79, 0x00, 0x7A, 0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0x8E, 0x00,
};

const body emicas_basic_close_body = {
    /* used_tiles      */ emicas_basic_close_body_used,
    /* used_count      */ 123,
    /* map_compressed  */ emicas_basic_close_body_map_rle,
    /* vis_x0          */ 9,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emicas_thumb_basic_close,
};

alignas(int) static const uint16_t emicas_up_close_body_used[150] = {
    0, 1759, 1760, 1878, 1879, 1880, 1881, 1882, 1766, 1883, 1768, 1884, 1885, 1886, 1887, 1888,
    1889, 1890, 1776, 1891, 1892, 1893, 1894, 1895, 1896, 1897, 1898, 1899, 1900, 1901, 1902, 1903,
    1904, 1905, 1906, 1907, 1908, 1909, 1910, 1911, 1912, 1913, 1914, 1915, 1916, 1917, 1918, 1919,
    1920, 1921, 1922, 1923, 1924, 1925, 1926, 1927, 1928, 1929, 1930, 1931, 1932, 1933, 1934, 1935,
    1936, 1937, 1938, 1939, 1940, 1941, 1942, 1047, 1943, 1944, 1945, 1946, 1947, 1948, 1630, 1949,
    1950, 1951, 1952, 1953, 1954, 1955, 1956, 1957, 1958, 1959, 1960, 1961, 1962, 1963, 1964, 1965,
    1966, 1967, 1968, 1969, 1970, 1971, 1842, 1972, 1844, 1973, 1974, 1975, 1976, 1977, 1978, 1979,
    1849, 1980, 1981, 1982, 1983, 1984, 1985, 1986, 1987, 1988, 1989, 1990, 1991, 1992, 1858, 1993,
    1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 1866, 2002, 2003, 2004, 2005, 2006, 2007, 2008,
    2009, 2010, 1875, 2011, 2012, 2013,
};

alignas(int) static const unsigned char emicas_up_close_body_map_rle[380] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8F, 0x00, 0x0E, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0xAE, 0x00, 0x00, 0x09,
    0xBA, 0x00, 0x02, 0x0A, 0x00, 0x0B, 0xBA, 0x00, 0x02, 0x0C, 0x00, 0x0D, 0xBA, 0x00, 0x02, 0x0E,
    0x00, 0x0F, 0xB8, 0x00, 0x04, 0x10, 0x00, 0x11, 0x00, 0x12, 0xB8, 0x00, 0x02, 0x13, 0x00, 0x14,
    0xBA, 0x00, 0x02, 0x15, 0x00, 0x16, 0xB8, 0x00, 0x02, 0x17, 0x00, 0x18, 0x80, 0x00, 0x00, 0x19,
    0xB8, 0x00, 0x14, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20,
    0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0xA8, 0x00, 0x14, 0x25, 0x00, 0x26, 0x00, 0x27,
    0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F,
    0xA8, 0x00, 0x14, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36,
    0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0xA6, 0x00, 0x18, 0x3B, 0x00, 0x3C, 0x00, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45,
    0x00, 0x46, 0x00, 0x47, 0xA4, 0x00, 0x18, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C,
    0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54,
    0xA2, 0x00, 0x06, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x80, 0x00, 0x10, 0x59, 0x00, 0x5A,
    0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0xA2, 0x00,
    0x04, 0x62, 0x00, 0x63, 0x00, 0x64, 0x82, 0x00, 0x10, 0x65, 0x00, 0x66, 0x00, 0x4E, 0x00, 0x67,
    0x00, 0x68, 0x00, 0x4E, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0xA2, 0x00, 0x06, 0x6C, 0x00, 0x6D,
    0x00, 0x6E, 0x00, 0x6F, 0x82, 0x00, 0x0E, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x4E, 0x00, 0x4E,
    0x00, 0x73, 0x00, 0x74, 0x00, 0x75, 0xA4, 0x00, 0x06, 0x76, 0x00, 0x77, 0x00, 0x78, 0x00, 0x79,
    0x80, 0x00, 0x0E, 0x7A, 0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x4E, 0x00, 0x7E, 0x00, 0x7F,
    0x00, 0x80, 0xA6, 0x00, 0x16, 0x81, 0x00, 0x82, 0x00, 0x83, 0x00, 0x84, 0x00, 0x85, 0x00, 0x86,
    0x00, 0x87, 0x00, 0x4E, 0x00, 0x88, 0x00, 0x89, 0x00, 0x8A, 0x00, 0x8B, 0xA8, 0x00, 0x14, 0x8C,
    0x00, 0x8D, 0x00, 0x8E, 0x00, 0x8F, 0x00, 0x90, 0x00, 0x91, 0x00, 0x4E, 0x00, 0x92, 0x00, 0x93,
    0x00, 0x94, 0x00, 0x95, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8C, 0x00,
};

const body emicas_up_close_body = {
    /* used_tiles      */ emicas_up_close_body_used,
    /* used_count      */ 150,
    /* map_compressed  */ emicas_up_close_body_map_rle,
    /* vis_x0          */ 8,
    /* vis_x1          */ 22,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emicas_thumb_up_close,
};

alignas(int) static const uint16_t eminude_basic_body_used[97] = {
    0, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024, 2025, 2026, 2027, 2028,
    2029, 2030, 2031, 2032, 2033, 2034, 2035, 2036, 2037, 2038, 2039, 2040, 2041, 2042, 2043, 2044,
    2045, 2046, 2047, 2048, 2049, 2050, 2051, 2052, 2053, 2054, 2055, 2056, 2057, 2058, 2059, 2060,
    2061, 2062, 2063, 2064, 2065, 2066, 2067, 2068, 2069, 2070, 2071, 2072, 2073, 2074, 2075, 2076,
    2077, 2078, 2079, 2080, 2081, 2082, 2083, 2084, 2085, 2086, 2087, 2088, 2089, 2090, 2091, 2092,
    2093, 2094, 2095, 2096, 2097, 2098, 2099, 2100, 2101, 2102, 2103, 2104, 2105, 2106, 2107, 2108,
    2109,
};

alignas(int) static const unsigned char eminude_basic_body_map_rle[248] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD1, 0x00, 0x06, 0x01,
    0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x0A, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08,
    0x00, 0x09, 0x00, 0x0A, 0xB0, 0x00, 0x04, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0xB8, 0x00, 0x04, 0x0E,
    0x00, 0x0F, 0x00, 0x10, 0xB8, 0x00, 0x04, 0x11, 0x00, 0x12, 0x00, 0x13, 0xB6, 0x00, 0x02, 0x14,
    0x00, 0x15, 0x80, 0x00, 0x00, 0x16, 0xB6, 0x00, 0x0E, 0x17, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A,
    0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0xB0, 0x00, 0x0C, 0x1F, 0x00, 0x20, 0x00, 0x21,
    0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0xB2, 0x00, 0x0A, 0x26, 0x00, 0x27, 0x00, 0x28,
    0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0xB0, 0x00, 0x0C, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F,
    0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0xB0, 0x00, 0x0C, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36,
    0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0xB0, 0x00, 0x0C, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0xB0, 0x00, 0x0C, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44,
    0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0xB2, 0x00, 0x0A, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B,
    0x00, 0x4C, 0x00, 0x4D, 0xB2, 0x00, 0x0A, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52,
    0x00, 0x53, 0xB2, 0x00, 0x0A, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59,
    0xB2, 0x00, 0x0C, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60,
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x90, 0x00,
};

const body eminude_basic_body = {
    /* used_tiles      */ eminude_basic_body_used,
    /* used_count      */ 97,
    /* map_compressed  */ eminude_basic_body_map_rle,
    /* vis_x0          */ 11,
    /* vis_x1          */ 20,
    /* vis_y0          */ 9,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::eminude_thumb_basic,
};

alignas(int) static const uint16_t eminude_basic_close_body_used[132] = {
    0, 2110, 2111, 2112, 2113, 2114, 2115, 2116, 2117, 2118, 2119, 2120, 2121, 2122, 2123, 2124,
    2125, 2126, 2127, 2128, 2129, 2130, 2131, 2132, 2133, 2134, 2135, 2136, 2137, 2138, 2139, 2140,
    2141, 2142, 2143, 2144, 2145, 2146, 2147, 2148, 2149, 2150, 2151, 2152, 2153, 2154, 2155, 2156,
    2157, 2158, 2159, 2160, 2161, 2162, 2163, 2164, 2165, 2166, 2167, 2168, 2169, 2170, 2171, 2172,
    2173, 2174, 2175, 2176, 2177, 2178, 2179, 2180, 2181, 2182, 2183, 2184, 2185, 2186, 2187, 2188,
    2189, 2190, 2191, 2192, 2193, 2194, 2195, 2196, 2197, 2198, 2199, 2200, 2201, 2202, 2203, 2204,
    2205, 2206, 2207, 2208, 2209, 2210, 2211, 2212, 2213, 2214, 2215, 2216, 2217, 2218, 2219, 2220,
    2221, 2222, 2223, 2224, 2225, 2226, 2227, 2228, 2229, 2230, 2231, 2232, 2233, 2234, 2235, 2236,
    2237, 2238, 2239, 2240,
};

alignas(int) static const unsigned char eminude_basic_close_body_map_rle[324] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8F, 0x00, 0x0E, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0xAE, 0x00, 0x00, 0x09,
    0xBA, 0x00, 0x02, 0x0A, 0x00, 0x0B, 0xBA, 0x00, 0x02, 0x0C, 0x00, 0x0D, 0xB8, 0x00, 0x04, 0x0E,
    0x00, 0x0F, 0x00, 0x10, 0xB8, 0x00, 0x04, 0x11, 0x00, 0x12, 0x00, 0x13, 0xB8, 0x00, 0x02, 0x14,
    0x00, 0x15, 0xBA, 0x00, 0x02, 0x16, 0x00, 0x17, 0xB8, 0x00, 0x02, 0x18, 0x00, 0x19, 0xBC, 0x00,
    0x00, 0x1A, 0x80, 0x00, 0x10, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20,
    0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0xA8, 0x00, 0x14, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27,
    0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0xAA, 0x00,
    0x12, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36,
    0x00, 0x37, 0x00, 0x38, 0xAA, 0x00, 0x12, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0xAA, 0x00, 0x10, 0x43, 0x00, 0x44,
    0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0xAC, 0x00,
    0x10, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53,
    0x00, 0x54, 0xAC, 0x00, 0x10, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A,
    0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0xAC, 0x00, 0x10, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61,
    0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0xAC, 0x00, 0x10, 0x67, 0x00, 0x68,
    0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0xAC, 0x00,
    0x12, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73, 0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0x00, 0x77,
    0x00, 0x78, 0x00, 0x79, 0xAA, 0x00, 0x12, 0x7A, 0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E,
    0x00, 0x7F, 0x00, 0x80, 0x00, 0x81, 0x00, 0x82, 0x00, 0x83, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
    0x8E, 0x00, 0x00, 0x00,
};

const body eminude_basic_close_body = {
    /* used_tiles      */ eminude_basic_close_body_used,
    /* used_count      */ 132,
    /* map_compressed  */ eminude_basic_close_body_map_rle,
    /* vis_x0          */ 9,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::eminude_thumb_basic_close,
};

alignas(int) static const uint16_t emiwheel_basic_body_used[91] = {
    0, 2241, 2242, 2243, 464, 2244, 2245, 2246, 2247, 2248, 2249, 2250, 2251, 2252, 2253, 2254,
    2255, 2256, 2036, 2257, 2258, 2259, 2260, 2261, 2262, 2263, 2264, 2265, 2266, 2267, 2268, 2269,
    2270, 2271, 2272, 2273, 2274, 2275, 2276, 2277, 2278, 2279, 2280, 2281, 2282, 2283, 2284, 2285,
    2286, 2287, 2288, 2289, 2290, 2291, 2292, 2293, 972, 2294, 2295, 2296, 2297, 2298, 2299, 2300,
    2301, 2302, 2303, 2304, 2305, 2306, 2307, 2308, 2309, 2310, 2311, 2312, 2313, 2314, 2315, 2316,
    2317, 2318, 2319, 2320, 2321, 2322, 2323, 2324, 2325, 2326, 2327,
};

alignas(int) static const unsigned char emiwheel_basic_body_map_rle[240] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
    0x8F, 0x00, 0x04, 0x01, 0x00, 0x02, 0x00, 0x03, 0xB4, 0x00, 0x0C, 0x04, 0x00, 0x05, 0x00, 0x06,
    0x00, 0x07, 0x00, 0x08, 0x00, 0x09, 0x00, 0x0A, 0xB0, 0x00, 0x02, 0x0B, 0x00, 0x0C, 0x86, 0x00,
    0x00, 0x0D, 0xB0, 0x00, 0x02, 0x0E, 0x00, 0x0F, 0x86, 0x00, 0x00, 0x10, 0xB0, 0x00, 0x02, 0x11,
    0x00, 0x12, 0x86, 0x00, 0x00, 0x13, 0xAE, 0x00, 0x02, 0x14, 0x00, 0x15, 0x88, 0x00, 0x00, 0x16,
    0xAE, 0x00, 0x0E, 0x17, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D,
    0x00, 0x1E, 0xAE, 0x00, 0x0E, 0x1F, 0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24,
    0x00, 0x25, 0x00, 0x26, 0xAA, 0x00, 0x12, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B,
    0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0xAE, 0x00, 0x0E, 0x31, 0x00, 0x32,
    0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0xAE, 0x00, 0x0E, 0x39,
    0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0xAE, 0x00,
    0x0E, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48,
    0xAE, 0x00, 0x10, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F,
    0x00, 0x50, 0x00, 0x51, 0xAC, 0x00, 0x10, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56,
    0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8E, 0x00,
};

const body emiwheel_basic_body = {
    /* used_tiles      */ emiwheel_basic_body_used,
    /* used_count      */ 91,
    /* map_compressed  */ emiwheel_basic_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 21,
    /* vis_y0          */ 12,
    /* vis_y1          */ 26,
    /* render_w_px     */ 88,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emiwheel_thumb_basic,
};

alignas(int) static const uint16_t emiwheel_basic_close_body_used[130] = {
    0, 2328, 2329, 2330, 2331, 2332, 2333, 2334, 2335, 2336, 251, 2337, 2338, 2339, 2340, 2341,
    2342, 2343, 2344, 2345, 2346, 2347, 2348, 2349, 2350, 2351, 2352, 2353, 2354, 2355, 2356, 2357,
    2358, 2359, 2360, 2361, 2362, 2363, 2364, 2365, 2366, 2367, 2368, 2369, 2370, 2371, 2372, 2373,
    2374, 2375, 2376, 2377, 2378, 2379, 2380, 2381, 2382, 2383, 2384, 2385, 2386, 2387, 2388, 2389,
    2390, 2391, 2392, 2393, 2394, 2395, 2396, 2397, 2398, 2399, 2400, 2401, 2402, 2403, 2404, 2405,
    2406, 2407, 2408, 2409, 2410, 2411, 2412, 2413, 2414, 2415, 2416, 2417, 2418, 2419, 2420, 2421,
    2422, 2423, 2424, 2425, 2426, 2427, 2428, 2429, 2430, 2431, 2432, 2433, 2434, 2435, 2436, 2437,
    2438, 2439, 2440, 2441, 2442, 2443, 2444, 2445, 2446, 2447, 2448, 2449, 2450, 2451, 2452, 2453,
    2454, 2455,
};

alignas(int) static const unsigned char emiwheel_basic_close_body_map_rle[320] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x93, 0x00, 0x08, 0x01,
    0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0xB0, 0x00, 0x00, 0x06, 0xBC, 0x00, 0x00, 0x07,
    0xBA, 0x00, 0x02, 0x08, 0x00, 0x09, 0x8E, 0x00, 0x00, 0x0A, 0xA8, 0x00, 0x02, 0x0B, 0x00, 0x0C,
    0x8E, 0x00, 0x00, 0x0D, 0xA8, 0x00, 0x02, 0x0E, 0x00, 0x0F, 0xBA, 0x00, 0x02, 0x10, 0x00, 0x11,
    0xB8, 0x00, 0x02, 0x12, 0x00, 0x13, 0xBA, 0x00, 0x02, 0x14, 0x00, 0x15, 0xBA, 0x00, 0x16, 0x16,
    0x00, 0x17, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E,
    0x00, 0x1F, 0x00, 0x20, 0x00, 0x21, 0xA6, 0x00, 0x16, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25,
    0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D,
    0xA2, 0x00, 0x18, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34,
    0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0xA2, 0x00, 0x1A, 0x3B,
    0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43,
    0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0xA6, 0x00, 0x16, 0x49, 0x00, 0x4A,
    0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52,
    0x00, 0x53, 0x00, 0x54, 0xA6, 0x00, 0x16, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59,
    0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0xA8, 0x00,
    0x14, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x67, 0x00, 0x68,
    0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0xA8, 0x00, 0x14, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F,
    0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73, 0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0xA8, 0x00,
    0x14, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00, 0x7A, 0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E,
    0x00, 0x7F, 0x00, 0x80, 0x00, 0x81, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8C, 0x00, 0x00, 0x00,
};

const body emiwheel_basic_close_body = {
    /* used_tiles      */ emiwheel_basic_close_body_used,
    /* used_count      */ 130,
    /* map_compressed  */ emiwheel_basic_close_body_map_rle,
    /* vis_x0          */ 8,
    /* vis_x1          */ 23,
    /* vis_y0          */ 8,
    /* vis_y1          */ 26,
    /* render_w_px     */ 127,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::emiwheel_thumb_basic_close,
};

const variant emi_basic_gym_shock = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_shock_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_gym_grin = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_grin_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_gym_closedhappy = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedhappy_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_gym_concentrate = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_concentrate_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_gym_closedgrin = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedgrin_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_gym_confused = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_confused_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_gym_happy = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_happy_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_gym_closedsweat = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedsweat_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_gym_annoyed = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_annoyed_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_gym_hes = {
    /* body                */ &emi_basic_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_hes_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6F2C,
};

const variant emi_basic_grin = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_grin,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_basic_closedsweat = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedsweat,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_basic_closedhappy = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedhappy,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_basic_hes = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_hes,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_basic_closedgrin = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedgrin,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_basic_annoyed = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_annoyed,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_basic_shock = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_shock,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_basic_happy = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_happy,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_basic_confused = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_confused,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_basic_concentrate = {
    /* body                */ &emi_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_concentrate,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x0C68,
};

const variant emi_excited_gym_smile = {
    /* body                */ &emi_excited_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_smile_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x8B49,
};

const variant emi_excited_gym_sad = {
    /* body                */ &emi_excited_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_sad_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x8B49,
};

const variant emi_excited_gym_circle = {
    /* body                */ &emi_excited_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_circle_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x8B49,
};

const variant emi_excited_gym_proud = {
    /* body                */ &emi_excited_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_proud_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x8B49,
};

const variant emi_excited_gym_hesitant = {
    /* body                */ &emi_excited_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_hesitant_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x8B49,
};

const variant emi_excited_gym_amused = {
    /* body                */ &emi_excited_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_amused_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x8B49,
};

const variant emi_excited_gym_happy = {
    /* body                */ &emi_excited_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_happy_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x8B49,
};

const variant emi_excited_gym_joy = {
    /* body                */ &emi_excited_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_joy_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x8B49,
};

const variant emi_excited_gym_laugh = {
    /* body                */ &emi_excited_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_laugh_gym,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x8B49,
};

const variant emi_excited_joy = {
    /* body                */ &emi_excited_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_joy,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x562B,
};

const variant emi_excited_sad = {
    /* body                */ &emi_excited_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_sad,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x562B,
};

const variant emi_excited_smile = {
    /* body                */ &emi_excited_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_smile,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x562B,
};

const variant emi_excited_circle = {
    /* body                */ &emi_excited_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_circle,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x562B,
};

const variant emi_excited_proud = {
    /* body                */ &emi_excited_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_proud,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x562B,
};

const variant emi_excited_laugh = {
    /* body                */ &emi_excited_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_laugh,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x562B,
};

const variant emi_excited_amused = {
    /* body                */ &emi_excited_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_amused,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x562B,
};

const variant emi_excited_happy = {
    /* body                */ &emi_excited_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_happy,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 12,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x562B,
};

const variant emi_sad_gym_shyblush = {
    /* body                */ &emi_sad_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_shyblush_gym,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xED43,
};

const variant emi_sad_gym_pout = {
    /* body                */ &emi_sad_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_pout_gym,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xED43,
};

const variant emi_sad_gym_angry = {
    /* body                */ &emi_sad_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_angry_gym,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xED43,
};

const variant emi_sad_gym_grin = {
    /* body                */ &emi_sad_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_grin_gym,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xED43,
};

const variant emi_sad_gym_grit = {
    /* body                */ &emi_sad_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_grit_gym,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xED43,
};

const variant emi_sad_gym_annoyed = {
    /* body                */ &emi_sad_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_annoyed_gym,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xED43,
};

const variant emi_sad_gym_shy = {
    /* body                */ &emi_sad_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_shy_gym,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xED43,
};

const variant emi_sad_gym_depressed = {
    /* body                */ &emi_sad_gym_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_depressed_gym,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xED43,
};

const variant emi_sad_grin = {
    /* body                */ &emi_sad_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_grin,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x3DD6,
};

const variant emi_sad_annoyed = {
    /* body                */ &emi_sad_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_annoyed,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x3DD6,
};

const variant emi_sad_grit = {
    /* body                */ &emi_sad_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_grit,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x3DD6,
};

const variant emi_sad_shy = {
    /* body                */ &emi_sad_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_shy,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x3DD6,
};

const variant emi_sad_pout = {
    /* body                */ &emi_sad_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_pout,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x3DD6,
};

const variant emi_sad_angry = {
    /* body                */ &emi_sad_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_angry,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x3DD6,
};

const variant emi_sad_shyblush = {
    /* body                */ &emi_sad_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_shyblush,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x3DD6,
};

const variant emi_sad_depressed = {
    /* body                */ &emi_sad_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_depressed,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x3DD6,
};

const variant emi_basic_gym_close_happy = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_happy_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_gym_close_hes = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_hes_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_gym_close_closedhappy = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedhappy_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_gym_close_closedgrin = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedgrin_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_gym_close_closedsweat = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedsweat_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_gym_close_annoyed = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_annoyed_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_gym_close_shock = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_shock_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_gym_close_happyblush = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_happyblush_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_gym_close_confused = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_confused_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_gym_close_grin = {
    /* body                */ &emi_basic_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_grin_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x1389,
};

const variant emi_basic_close_hes = {
    /* body                */ &emi_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_hes_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBBC1,
};

const variant emi_basic_close_shock = {
    /* body                */ &emi_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_shock_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBBC1,
};

const variant emi_basic_close_closedhappy = {
    /* body                */ &emi_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedhappy_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBBC1,
};

const variant emi_basic_close_confused = {
    /* body                */ &emi_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_confused_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBBC1,
};

const variant emi_basic_close_happy = {
    /* body                */ &emi_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_happy_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBBC1,
};

const variant emi_basic_close_annoyed = {
    /* body                */ &emi_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_annoyed_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBBC1,
};

const variant emi_basic_close_grin = {
    /* body                */ &emi_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_grin_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBBC1,
};

const variant emi_basic_close_closedgrin = {
    /* body                */ &emi_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_basic_closedgrin_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBBC1,
};

const variant emi_excited_gym_close_laugh = {
    /* body                */ &emi_excited_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_laugh_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x70CC,
};

const variant emi_excited_gym_close_sad = {
    /* body                */ &emi_excited_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_sad_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x70CC,
};

const variant emi_excited_gym_close_happy = {
    /* body                */ &emi_excited_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_happy_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x70CC,
};

const variant emi_excited_gym_close_amused = {
    /* body                */ &emi_excited_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_amused_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x70CC,
};

const variant emi_excited_gym_close_proud = {
    /* body                */ &emi_excited_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_proud_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x70CC,
};

const variant emi_excited_close_smile = {
    /* body                */ &emi_excited_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_smile_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xC4D2,
};

const variant emi_excited_close_proud = {
    /* body                */ &emi_excited_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_proud_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xC4D2,
};

const variant emi_excited_close_laugh = {
    /* body                */ &emi_excited_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_laugh_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xC4D2,
};

const variant emi_excited_close_happy = {
    /* body                */ &emi_excited_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_happy_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xC4D2,
};

const variant emi_excited_close_sad = {
    /* body                */ &emi_excited_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_sad_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xC4D2,
};

const variant emi_excited_close_amused = {
    /* body                */ &emi_excited_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_excited_amused_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xC4D2,
};

const variant emi_sad_gym_close_pout = {
    /* body                */ &emi_sad_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_pout_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x5F59,
};

const variant emi_sad_gym_close_angry = {
    /* body                */ &emi_sad_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_angry_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x5F59,
};

const variant emi_sad_gym_close_depressed = {
    /* body                */ &emi_sad_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_depressed_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x5F59,
};

const variant emi_sad_gym_close_shy = {
    /* body                */ &emi_sad_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_shy_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x5F59,
};

const variant emi_sad_gym_close_grin = {
    /* body                */ &emi_sad_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_grin_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x5F59,
};

const variant emi_sad_gym_close_annoyed = {
    /* body                */ &emi_sad_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_annoyed_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x5F59,
};

const variant emi_sad_gym_close_shyblush = {
    /* body                */ &emi_sad_gym_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_shyblush_gym_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x5F59,
};

const variant emi_sad_close_depressed = {
    /* body                */ &emi_sad_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_depressed_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x205C,
};

const variant emi_sad_close_annoyed = {
    /* body                */ &emi_sad_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_annoyed_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x205C,
};

const variant emi_sad_close_shy = {
    /* body                */ &emi_sad_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_shy_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x205C,
};

const variant emi_sad_close_shyblush = {
    /* body                */ &emi_sad_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_shyblush_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x205C,
};

const variant emi_sad_close_grin = {
    /* body                */ &emi_sad_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_grin_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x205C,
};

const variant emi_sad_close_angry = {
    /* body                */ &emi_sad_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_angry_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x205C,
};

const variant emi_sad_close_pout = {
    /* body                */ &emi_sad_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_pout_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x205C,
};

const variant emi_sad_close_grit = {
    /* body                */ &emi_sad_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emi_spr_sad_grit_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x205C,
};

const variant emicas_basic_grit = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_grit,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_frown = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_frown,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_awayfrown = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_awayfrown,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_weaksmile = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_weaksmile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_happy = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_happy,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_pout = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_pout,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_sad = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_sad,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_blush = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_blush,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_angry = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_angry,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_wink = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_wink,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_evil = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_evil,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_smile = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_smile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_neutral = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_neutral,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_grin = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_grin,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_basic_closedsmile = {
    /* body                */ &emicas_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_closedsmile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x896C,
};

const variant emicas_up_weaksmile = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_weaksmile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_sad = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_sad,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_neutral = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_neutral,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_smile = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_smile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_happy = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_happy,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_pout = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_pout,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_angry = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_angry,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_grin = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_grin,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_frown = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_frown,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_awayfrown = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_awayfrown,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_wink = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_wink,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_up_closedsmile = {
    /* body                */ &emicas_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_closedsmile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xD412,
};

const variant emicas_basic_close_frown = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_frown_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_awayfrown = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_awayfrown_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_smile = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_smile_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_sad = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_sad_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_blush = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_blush_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_closedsmile = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_closedsmile_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_neutral = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_neutral_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_weaksmile = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_weaksmile_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_angry = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_angry_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_happy = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_happy_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_basic_close_wink = {
    /* body                */ &emicas_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_basic_wink_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x489B,
};

const variant emicas_up_close_neutral = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_neutral_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_closedsmile = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_closedsmile_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_grin = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_grin_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_happy = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_happy_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_frown = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_frown_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_blush = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_blush_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_awayfrown = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_awayfrown_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_smile = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_smile_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_weaksmile = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_weaksmile_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_sad = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_sad_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_wink = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_wink_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant emicas_up_close_angry = {
    /* body                */ &emicas_up_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emicas_spr_up_angry_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD059,
};

const variant eminude_basic_blush = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_blush,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_grin = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_grin,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_evil = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_evil,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_wink = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_wink,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_happy = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_happy,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_closedsmile = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_closedsmile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_frown = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_frown,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_awayfrown = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_awayfrown,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_weaksmile = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_weaksmile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_neutral = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_neutral,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_pout = {
    /* body                */ &eminude_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_pout,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 11,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xF25A,
};

const variant eminude_basic_close_blush = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_blush_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_sad = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_sad_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_angry = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_angry_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_grin = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_grin_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_closedsmile = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_closedsmile_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_happy = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_happy_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_weaksmile = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_weaksmile_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_evil = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_evil_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_frown = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_frown_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_pout = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_pout_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_wink = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_wink_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_neutral = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_neutral_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant eminude_basic_close_smile = {
    /* body                */ &eminude_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::eminude_spr_basic_smile_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 7,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xE574,
};

const variant emiwheel_basic_awayfrown = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_awayfrown,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_blush = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_blush,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_weaksmile = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_weaksmile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_pout = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_pout,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_closedsmile = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_closedsmile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_happy = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_happy,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_frown = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_frown,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_smile = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_smile,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_sad = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_sad,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_wink = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_wink,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_evil = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_evil,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_angry = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_angry,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_grin = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_grin,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_neutral = {
    /* body                */ &emiwheel_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_neutral,
    /* face_offset_x_cells */ 15,
    /* face_offset_y_cells */ 14,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xBB83,
};

const variant emiwheel_basic_close_neutral = {
    /* body                */ &emiwheel_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_neutral_close,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 9,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCC2B,
};

const variant emiwheel_basic_close_closedsmile = {
    /* body                */ &emiwheel_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_closedsmile_close,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 9,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCC2B,
};

const variant emiwheel_basic_close_blush = {
    /* body                */ &emiwheel_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_blush_close,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 9,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCC2B,
};

const variant emiwheel_basic_close_wink = {
    /* body                */ &emiwheel_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_wink_close,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 9,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCC2B,
};

const variant emiwheel_basic_close_awayfrown = {
    /* body                */ &emiwheel_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_awayfrown_close,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 9,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCC2B,
};

const variant emiwheel_basic_close_grin = {
    /* body                */ &emiwheel_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::emiwheel_spr_basic_grin_close,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 9,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCC2B,
};

}  // namespace ks::smart_characters::emi
