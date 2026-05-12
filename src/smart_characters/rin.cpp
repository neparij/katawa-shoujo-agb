#include "smart_characters/rin.h"

#include "bn_regular_bg_tiles_items_rin_tiles_0.h"
#include "bn_regular_bg_tiles_items_rin_tiles_1.h"
#include "bn_bg_palette_items_pal_char_bg.h"
#include "bn_sprite_tiles_items_rin_thumb_back.h"
#include "bn_sprite_tiles_items_rin_thumb_basic.h"
#include "bn_sprite_tiles_items_rin_thumb_basic_cas.h"
#include "bn_sprite_tiles_items_rin_thumb_basic_cas_close.h"
#include "bn_sprite_tiles_items_rin_thumb_basic_close.h"
#include "bn_sprite_tiles_items_rin_thumb_negative.h"
#include "bn_sprite_tiles_items_rin_thumb_negative_cas.h"
#include "bn_sprite_tiles_items_rin_thumb_negative_cas_close.h"
#include "bn_sprite_tiles_items_rin_thumb_negative_close.h"
#include "bn_sprite_tiles_items_rin_thumb_relaxed.h"
#include "bn_sprite_tiles_items_rin_thumb_relaxed_cas.h"
#include "bn_sprite_tiles_items_rin_thumb_relaxed_cas_close.h"
#include "bn_sprite_tiles_items_rin_thumb_relaxed_close.h"
#include "bn_sprite_tiles_items_rin_thumb_relaxed_silhouette.h"
#include "bn_sprite_tiles_items_rinpan_thumb_basic.h"
#include "bn_sprite_tiles_items_rinpan_thumb_basic_close.h"
#include "bn_sprite_tiles_items_rinpan_thumb_relaxed.h"
#include "bn_sprite_tiles_items_rinpan_thumb_relaxed_close.h"
#include "bn_sprite_tiles_items_rin_spr_back_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_absent.h"
#include "bn_sprite_tiles_items_rin_spr_basic_absent_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_absent_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_absent_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_amused.h"
#include "bn_sprite_tiles_items_rin_spr_basic_amused_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_awayabsent.h"
#include "bn_sprite_tiles_items_rin_spr_basic_awayabsent_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_awayabsent_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_awayabsent_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_blush_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_crying.h"
#include "bn_sprite_tiles_items_rin_spr_basic_crying_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpan.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpan_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpan_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpan_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpanamused.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpanamused_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpanamused_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpancontemplation.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpancontemplation_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpancontemplation_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpandelight.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpandelight_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpannormal.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpannormal_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpannormal_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpannormal_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpansurprised.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpansurprised_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpansurprised_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpanupset.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpanupset_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpanupset_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_deadpanupset_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_delight.h"
#include "bn_sprite_tiles_items_rin_spr_basic_delight_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_lucid.h"
#include "bn_sprite_tiles_items_rin_spr_basic_lucid_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_lucid_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_lucid_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_sad.h"
#include "bn_sprite_tiles_items_rin_spr_basic_sad_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_sad_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_sad_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_surprised.h"
#include "bn_sprite_tiles_items_rin_spr_basic_surprised_cas.h"
#include "bn_sprite_tiles_items_rin_spr_basic_surprised_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_surprised_close.h"
#include "bn_sprite_tiles_items_rin_spr_basic_upset.h"
#include "bn_sprite_tiles_items_rin_spr_basic_upset_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_angry.h"
#include "bn_sprite_tiles_items_rin_spr_negative_angry_cas.h"
#include "bn_sprite_tiles_items_rin_spr_negative_angry_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_angry_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_annoyed.h"
#include "bn_sprite_tiles_items_rin_spr_negative_annoyed_cas.h"
#include "bn_sprite_tiles_items_rin_spr_negative_annoyed_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_annoyed_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_confused.h"
#include "bn_sprite_tiles_items_rin_spr_negative_confused_cas.h"
#include "bn_sprite_tiles_items_rin_spr_negative_confused_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_confused_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_crying.h"
#include "bn_sprite_tiles_items_rin_spr_negative_sad.h"
#include "bn_sprite_tiles_items_rin_spr_negative_sad_cas.h"
#include "bn_sprite_tiles_items_rin_spr_negative_sad_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_sad_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_spaciness.h"
#include "bn_sprite_tiles_items_rin_spr_negative_spaciness_cas.h"
#include "bn_sprite_tiles_items_rin_spr_negative_spaciness_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_spaciness_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_worried.h"
#include "bn_sprite_tiles_items_rin_spr_negative_worried_cas.h"
#include "bn_sprite_tiles_items_rin_spr_negative_worried_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_negative_worried_close.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_boredom.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_boredom_close.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_disgust.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_doubt.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_doubt_cas.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_doubt_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_doubt_close.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_nonchalant.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_nonchalant_cas.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_nonchalant_cas_close.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_nonchalant_close.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_sleepy.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_sleepy_cas.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_sleepy_close.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_surprised.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_surprised_close.h"
#include "bn_sprite_tiles_items_rin_spr_relaxed_surprised_silhouette.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_absent.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_amused.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_awayabsent.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_awayabsent_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpan.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpan_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpanamused.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpanamused_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpancontemplation.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpancontemplation_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpandelight.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpandelight_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpannormal.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpansurprised.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpanupset.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_deadpanupset_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_lucid.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_lucid_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_surprised.h"
#include "bn_sprite_tiles_items_rinpan_spr_basic_upset.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_boredom.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_boredom_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_doubt.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_doubt_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_nonchalant.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_nonchalant_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_sleepy.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_sleepy_close.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_surprised.h"
#include "bn_sprite_tiles_items_rinpan_spr_relaxed_surprised_close.h"

namespace ks::smart_characters::rin {

static const bn::regular_bg_tiles_item* const slab_table[2] = {
    &bn::regular_bg_tiles_items::rin_tiles_0,
    &bn::regular_bg_tiles_items::rin_tiles_1,
};

const tileset_data tileset = {
    /* slabs       */ slab_table,
    /* slab_count  */ 2,
    /* palette     */ &bn::bg_palette_items::pal_char_bg,
};

alignas(int) static const uint16_t rin_basic_cas_body_used[99] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98,
};

alignas(int) static const unsigned char rin_basic_cas_body_map_rle[256] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD1, 0x00, 0x08, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0xB2, 0x00, 0x02, 0x06, 0x00, 0x07, 0xBA, 0x00, 0x02, 0x08,
    0x00, 0x09, 0x86, 0x00, 0x00, 0x0A, 0xB2, 0x00, 0x00, 0x0B, 0x86, 0x00, 0x00, 0x0C, 0xB2, 0x00,
    0x00, 0x0D, 0xBE, 0x00, 0x06, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0x00, 0x11, 0xB4, 0x00, 0x0A, 0x12,
    0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0xB2, 0x00, 0x0A, 0x18, 0x00, 0x19,
    0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0xB2, 0x00, 0x0A, 0x1E, 0x00, 0x1F, 0x00, 0x20,
    0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0xB2, 0x00, 0x0C, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27,
    0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0xB0, 0x00, 0x0A, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E,
    0x00, 0x2F, 0x00, 0x30, 0xB2, 0x00, 0x0A, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35,
    0x00, 0x36, 0xB2, 0x00, 0x0A, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C,
    0xB2, 0x00, 0x0A, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0xB0, 0x00,
    0x0C, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0xB0, 0x00,
    0x0C, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0xB2, 0x00,
    0x0A, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0xB2, 0x00, 0x0A, 0x57,
    0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0xB2, 0x00, 0x0A, 0x5D, 0x00, 0x5E,
    0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x92, 0x00,
};

const body rin_basic_cas_body = {
    /* used_tiles      */ rin_basic_cas_body_used,
    /* used_count      */ 99,
    /* map_compressed  */ rin_basic_cas_body_map_rle,
    /* vis_x0          */ 12,
    /* vis_x1          */ 20,
    /* vis_y0          */ 7,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_basic_cas,
};

alignas(int) static const uint16_t rin_negative_cas_body_used[79] = {
    0, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
    114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129,
    130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
    146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161,
    162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176,
};

alignas(int) static const unsigned char rin_negative_cas_body_map_rle[208] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
    0xCB, 0x00, 0x0A, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0xB2, 0x00,
    0x0A, 0x07, 0x00, 0x08, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0x00, 0x0C, 0xB2, 0x00, 0x0A, 0x0D,
    0x00, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0x00, 0x11, 0x00, 0x12, 0xB2, 0x00, 0x0A, 0x13, 0x00, 0x14,
    0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00, 0x18, 0xB2, 0x00, 0x0A, 0x19, 0x00, 0x1A, 0x00, 0x1B,
    0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0xB2, 0x00, 0x0A, 0x1F, 0x00, 0x20, 0x00, 0x21, 0x00, 0x22,
    0x00, 0x23, 0x00, 0x24, 0xB2, 0x00, 0x0A, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29,
    0x00, 0x2A, 0xB2, 0x00, 0x0A, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30,
    0xB2, 0x00, 0x0A, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0xB2, 0x00,
    0x0A, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0xB2, 0x00, 0x0A, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0xB2, 0x00, 0x0A, 0x43, 0x00, 0x44,
    0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0xB2, 0x00, 0x0A, 0x49, 0x00, 0x4A, 0x00, 0x4B,
    0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x92, 0x00, 0x00, 0x00,
};

const body rin_negative_cas_body = {
    /* used_tiles      */ rin_negative_cas_body_used,
    /* used_count      */ 79,
    /* map_compressed  */ rin_negative_cas_body_map_rle,
    /* vis_x0          */ 13,
    /* vis_x1          */ 19,
    /* vis_y0          */ 13,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_negative_cas,
};

alignas(int) static const uint16_t rin_relaxed_cas_body_used[99] = {
    0, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
    192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207,
    208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223,
    224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255,
    256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271,
    272, 273, 274,
};

alignas(int) static const unsigned char rin_relaxed_cas_body_map_rle[260] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD3, 0x00, 0x06, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x00, 0x05, 0x86, 0x00, 0x02, 0x06, 0x00, 0x07, 0xB0, 0x00,
    0x00, 0x08, 0x86, 0x00, 0x00, 0x09, 0xB2, 0x00, 0x00, 0x0A, 0x86, 0x00, 0x00, 0x0B, 0xBC, 0x00,
    0x00, 0x0C, 0xB4, 0x00, 0x06, 0x0D, 0x00, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0xB4, 0x00, 0x0A, 0x11,
    0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0xB2, 0x00, 0x0A, 0x17, 0x00, 0x18,
    0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0xB2, 0x00, 0x0A, 0x1D, 0x00, 0x1E, 0x00, 0x1F,
    0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0xB2, 0x00, 0x0A, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0xB2, 0x00, 0x0A, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0xB2, 0x00, 0x0A, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34,
    0xB2, 0x00, 0x0A, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0xB2, 0x00,
    0x0C, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0xB0, 0x00,
    0x0C, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0xB0, 0x00,
    0x0C, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0xB0, 0x00,
    0x0C, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0xB0, 0x00,
    0x0A, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0xB2, 0x00, 0x0A, 0x5D,
    0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
    0x92, 0x00, 0x00, 0x00,
};

const body rin_relaxed_cas_body = {
    /* used_tiles      */ rin_relaxed_cas_body_used,
    /* used_count      */ 99,
    /* map_compressed  */ rin_relaxed_cas_body_map_rle,
    /* vis_x0          */ 13,
    /* vis_x1          */ 20,
    /* vis_y0          */ 7,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_relaxed_cas,
};

alignas(int) static const uint16_t rin_basic_body_used[100] = {
    0, 1, 275, 276, 277, 278, 6, 279, 280, 281, 282, 283, 284, 285, 286, 287,
    288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303,
    304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319,
    320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335,
    336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351,
    352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367,
    368, 369, 370, 371,
};

alignas(int) static const unsigned char rin_basic_body_map_rle[260] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD1, 0x00, 0x08, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0xB2, 0x00, 0x02, 0x06, 0x00, 0x07, 0x86, 0x00, 0x00, 0x08,
    0xB0, 0x00, 0x02, 0x09, 0x00, 0x0A, 0x86, 0x00, 0x00, 0x0B, 0xB2, 0x00, 0x00, 0x0C, 0x86, 0x00,
    0x00, 0x0D, 0xB2, 0x00, 0x00, 0x0E, 0xBE, 0x00, 0x06, 0x0F, 0x00, 0x10, 0x00, 0x11, 0x00, 0x12,
    0xB4, 0x00, 0x0A, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00, 0x18, 0xB2, 0x00,
    0x0A, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0xB2, 0x00, 0x0C, 0x1F,
    0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0xB0, 0x00, 0x0C, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0xB0, 0x00, 0x0A, 0x2D,
    0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0xB2, 0x00, 0x0A, 0x33, 0x00, 0x34,
    0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0xB2, 0x00, 0x0A, 0x39, 0x00, 0x3A, 0x00, 0x3B,
    0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0xB2, 0x00, 0x0C, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42,
    0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0xB0, 0x00, 0x0A, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49,
    0x00, 0x4A, 0x00, 0x4B, 0xB2, 0x00, 0x0A, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50,
    0x00, 0x51, 0xB2, 0x00, 0x0A, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57,
    0xB2, 0x00, 0x0A, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0xB2, 0x00,
    0x0A, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0x92, 0x00,
};

const body rin_basic_body = {
    /* used_tiles      */ rin_basic_body_used,
    /* used_count      */ 100,
    /* map_compressed  */ rin_basic_body_map_rle,
    /* vis_x0          */ 12,
    /* vis_x1          */ 20,
    /* vis_y0          */ 7,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_basic,
};

alignas(int) static const uint16_t rin_negative_body_used[78] = {
    0, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386,
    387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402,
    403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 300, 416, 417,
    418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433,
    434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447,
};

alignas(int) static const unsigned char rin_negative_body_map_rle[208] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
    0xCB, 0x00, 0x0A, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0xB2, 0x00,
    0x0A, 0x07, 0x00, 0x08, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0x00, 0x0C, 0xB2, 0x00, 0x0A, 0x0D,
    0x00, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0x00, 0x11, 0x00, 0x12, 0xB2, 0x00, 0x0A, 0x13, 0x00, 0x14,
    0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00, 0x18, 0xB2, 0x00, 0x0A, 0x19, 0x00, 0x1A, 0x00, 0x1B,
    0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0xB2, 0x00, 0x0A, 0x1F, 0x00, 0x20, 0x00, 0x21, 0x00, 0x22,
    0x00, 0x23, 0x00, 0x24, 0xB2, 0x00, 0x0A, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29,
    0x00, 0x2A, 0xB2, 0x00, 0x0A, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30,
    0xB2, 0x00, 0x0A, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0xB2, 0x00,
    0x0A, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0xB2, 0x00, 0x0A, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x3C, 0xB2, 0x00, 0x0A, 0x42, 0x00, 0x43,
    0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0xB2, 0x00, 0x0A, 0x48, 0x00, 0x49, 0x00, 0x4A,
    0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x92, 0x00, 0x00, 0x00,
};

const body rin_negative_body = {
    /* used_tiles      */ rin_negative_body_used,
    /* used_count      */ 78,
    /* map_compressed  */ rin_negative_body_map_rle,
    /* vis_x0          */ 13,
    /* vis_x1          */ 19,
    /* vis_y0          */ 13,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_negative,
};

alignas(int) static const uint16_t rin_relaxed_body_used[100] = {
    0, 448, 449, 450, 451, 181, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461,
    462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477,
    478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493,
    223, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508,
    509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524,
    525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540,
    541, 542, 543, 544,
};

alignas(int) static const unsigned char rin_relaxed_body_map_rle[260] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD3, 0x00, 0x06, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x00, 0x05, 0x86, 0x00, 0x02, 0x06, 0x00, 0x07, 0xB0, 0x00,
    0x00, 0x08, 0x86, 0x00, 0x02, 0x09, 0x00, 0x0A, 0xB0, 0x00, 0x00, 0x0B, 0x86, 0x00, 0x00, 0x0C,
    0xBC, 0x00, 0x00, 0x0D, 0xB4, 0x00, 0x06, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0x00, 0x11, 0xB4, 0x00,
    0x0A, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0xB2, 0x00, 0x0A, 0x18,
    0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0xB2, 0x00, 0x0A, 0x1E, 0x00, 0x1F,
    0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0xB2, 0x00, 0x0A, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0xB2, 0x00, 0x0A, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0x00, 0x2F, 0xB2, 0x00, 0x0A, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34,
    0x00, 0x35, 0xB2, 0x00, 0x0A, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B,
    0xB2, 0x00, 0x0C, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42,
    0xB0, 0x00, 0x0C, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49,
    0xB0, 0x00, 0x0C, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50,
    0xB0, 0x00, 0x0C, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57,
    0xB0, 0x00, 0x0A, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0xB2, 0x00,
    0x0A, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0x92, 0x00,
};

const body rin_relaxed_body = {
    /* used_tiles      */ rin_relaxed_body_used,
    /* used_count      */ 100,
    /* map_compressed  */ rin_relaxed_body_map_rle,
    /* vis_x0          */ 13,
    /* vis_x1          */ 20,
    /* vis_y0          */ 7,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_relaxed,
};

alignas(int) static const uint16_t rin_back_body_used[101] = {
    0, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559,
    560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575,
    576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591,
    592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607,
    608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623,
    624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639,
    640, 641, 642, 643, 644,
};

alignas(int) static const unsigned char rin_back_body_map_rle[264] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD3, 0x00, 0x06, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x00, 0x05, 0xBA, 0x00, 0x02, 0x06, 0x00, 0x07, 0x86, 0x00,
    0x00, 0x08, 0xB2, 0x00, 0x00, 0x09, 0x86, 0x00, 0x00, 0x0A, 0xB2, 0x00, 0x00, 0x0B, 0x86, 0x00,
    0x00, 0x0C, 0xB4, 0x00, 0x06, 0x0D, 0x00, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0xB4, 0x00, 0x0A, 0x11,
    0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0xB0, 0x00, 0x0C, 0x17, 0x00, 0x18,
    0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0xB0, 0x00, 0x0C, 0x1E, 0x00, 0x1F,
    0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0xB0, 0x00, 0x0C, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0xB0, 0x00, 0x0C, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0xB2, 0x00, 0x0A, 0x33, 0x00, 0x34,
    0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0xB0, 0x00, 0x0C, 0x39, 0x00, 0x3A, 0x00, 0x3B,
    0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0xB0, 0x00, 0x0C, 0x40, 0x00, 0x41, 0x00, 0x42,
    0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0xB2, 0x00, 0x0A, 0x47, 0x00, 0x48, 0x00, 0x49,
    0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0xB2, 0x00, 0x0A, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50,
    0x00, 0x51, 0x00, 0x52, 0xB2, 0x00, 0x0A, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57,
    0x00, 0x58, 0xB2, 0x00, 0x0A, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E,
    0xB2, 0x00, 0x0A, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00, 0x92, 0x00, 0x00, 0x00,
};

const body rin_back_body = {
    /* used_tiles      */ rin_back_body_used,
    /* used_count      */ 101,
    /* map_compressed  */ rin_back_body_map_rle,
    /* vis_x0          */ 12,
    /* vis_x1          */ 19,
    /* vis_y0          */ 7,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_back,
};

alignas(int) static const uint16_t rin_basic_cas_close_body_used[136] = {
    0, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654, 655, 656, 657, 658, 659,
    660, 661, 662, 663, 664, 665, 666, 667, 668, 669, 670, 671, 672, 673, 674, 675,
    676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 686, 687, 688, 689, 690, 691,
    692, 693, 694, 695, 696, 697, 698, 699, 700, 701, 702, 703, 704, 705, 706, 707,
    708, 709, 710, 711, 712, 713, 714, 715, 716, 717, 718, 719, 720, 721, 722, 723,
    724, 725, 726, 727, 728, 729, 730, 731, 732, 733, 734, 735, 736, 737, 738, 739,
    740, 741, 742, 743, 744, 745, 746, 747, 748, 749, 750, 751, 752, 753, 754, 755,
    756, 757, 758, 759, 760, 761, 762, 763, 764, 765, 766, 767, 768, 769, 770, 771,
    772, 773, 774, 775, 776, 777, 778, 779,
};

alignas(int) static const unsigned char rin_basic_cas_close_body_map_rle[332] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x9B, 0x00, 0x00, 0x01, 0xAA, 0x00,
    0x00, 0x02, 0x8E, 0x00, 0x02, 0x03, 0x00, 0x04, 0xA8, 0x00, 0x00, 0x05, 0x8E, 0x00, 0x02, 0x06,
    0x00, 0x07, 0xBA, 0x00, 0x04, 0x08, 0x00, 0x09, 0x00, 0x0A, 0xB8, 0x00, 0x02, 0x0B, 0x00, 0x0C,
    0xBA, 0x00, 0x00, 0x0D, 0xFC, 0x00, 0x00, 0x0E, 0xAE, 0x00, 0x10, 0x0F, 0x00, 0x10, 0x00, 0x11,
    0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0xAC, 0x00, 0x12, 0x18,
    0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20,
    0x00, 0x21, 0xAA, 0x00, 0x12, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27,
    0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0xAA, 0x00, 0x12, 0x2C, 0x00, 0x2D, 0x00, 0x2E,
    0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0xAA, 0x00,
    0x12, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0xAA, 0x00, 0x12, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44,
    0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0xAA, 0x00, 0x12, 0x4A, 0x00, 0x4B,
    0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53,
    0xAA, 0x00, 0x12, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A,
    0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0xAA, 0x00, 0x12, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61,
    0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x67, 0xAA, 0x00, 0x12, 0x68,
    0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70,
    0x00, 0x71, 0xA8, 0x00, 0x14, 0x72, 0x00, 0x73, 0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0x00, 0x77,
    0x00, 0x78, 0x00, 0x79, 0x00, 0x7A, 0x00, 0x7B, 0x00, 0x7C, 0xA8, 0x00, 0x14, 0x7D, 0x00, 0x7E,
    0x00, 0x7F, 0x00, 0x80, 0x00, 0x81, 0x00, 0x82, 0x00, 0x83, 0x00, 0x84, 0x00, 0x85, 0x00, 0x86,
    0x00, 0x87, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8E, 0x00, 0x00, 0x00,
};

const body rin_basic_cas_close_body = {
    /* used_tiles      */ rin_basic_cas_close_body_used,
    /* used_count      */ 136,
    /* map_compressed  */ rin_basic_cas_close_body_map_rle,
    /* vis_x0          */ 9,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 138,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_basic_cas_close,
};

alignas(int) static const uint16_t rin_negative_cas_close_body_used[123] = {
    0, 780, 781, 782, 783, 784, 785, 786, 787, 788, 789, 790, 791, 792, 793, 794,
    795, 796, 797, 798, 799, 800, 801, 802, 803, 804, 805, 806, 807, 808, 809, 810,
    811, 812, 813, 814, 815, 300, 816, 817, 818, 819, 820, 821, 822, 823, 824, 825,
    826, 827, 828, 829, 830, 831, 832, 833, 834, 835, 836, 837, 838, 839, 840, 841,
    842, 843, 844, 845, 846, 847, 848, 849, 850, 851, 852, 853, 854, 855, 856, 857,
    858, 859, 860, 861, 862, 863, 864, 865, 866, 867, 868, 869, 870, 871, 872, 873,
    874, 875, 876, 877, 878, 879, 880, 881, 882, 883, 884, 885, 886, 887, 888, 889,
    890, 891, 892, 893, 894, 895, 896, 897, 898, 899, 900,
};

alignas(int) static const unsigned char rin_negative_cas_close_body_map_rle[312] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x89, 0x00, 0x00, 0x01, 0x8E, 0x00,
    0x00, 0x02, 0xAA, 0x00, 0x00, 0x03, 0x8E, 0x00, 0x02, 0x04, 0x00, 0x05, 0xA8, 0x00, 0x00, 0x06,
    0x8E, 0x00, 0x04, 0x07, 0x00, 0x08, 0x00, 0x09, 0xA6, 0x00, 0x00, 0x0A, 0x8E, 0x00, 0x04, 0x0B,
    0x00, 0x0C, 0x00, 0x0D, 0xB8, 0x00, 0x02, 0x0E, 0x00, 0x0F, 0xFF, 0x00, 0xEA, 0x00, 0x0E, 0x10,
    0x00, 0x11, 0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0xAE, 0x00,
    0x10, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F,
    0x00, 0x20, 0xAC, 0x00, 0x10, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0xAC, 0x00, 0x10, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0xAA, 0x00, 0x12, 0x33, 0x00, 0x34,
    0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C,
    0xAA, 0x00, 0x12, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43,
    0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0xAC, 0x00, 0x10, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x49,
    0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0xAC, 0x00, 0x10, 0x4F, 0x00, 0x50,
    0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0xAC, 0x00,
    0x10, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F,
    0x00, 0x60, 0xAC, 0x00, 0x10, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66,
    0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0xAC, 0x00, 0x10, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D,
    0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0xAC, 0x00, 0x10, 0x73, 0x00, 0x74,
    0x00, 0x75, 0x00, 0x76, 0x00, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00, 0x25, 0x00, 0x7A, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00, 0x90, 0x00, 0x00, 0x00,
};

const body rin_negative_cas_close_body = {
    /* used_tiles      */ rin_negative_cas_close_body_used,
    /* used_count      */ 123,
    /* map_compressed  */ rin_negative_cas_close_body_map_rle,
    /* vis_x0          */ 9,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 138,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_negative_cas_close,
};

alignas(int) static const uint16_t rin_relaxed_cas_close_body_used[121] = {
    0, 901, 902, 903, 904, 905, 906, 907, 908, 909, 910, 911, 912, 913, 914, 915,
    916, 917, 918, 919, 920, 921, 922, 923, 924, 925, 926, 927, 928, 929, 930, 931,
    932, 933, 934, 935, 300, 936, 937, 938, 939, 940, 941, 942, 943, 944, 945, 946,
    947, 948, 949, 950, 951, 952, 953, 954, 955, 956, 957, 958, 959, 960, 961, 962,
    963, 964, 965, 966, 967, 968, 969, 851, 970, 971, 972, 973, 974, 975, 976, 977,
    978, 979, 980, 981, 982, 983, 984, 985, 986, 987, 988, 989, 990, 991, 992, 993,
    994, 995, 996, 997, 998, 999, 1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009,
    1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018,
};

alignas(int) static const unsigned char rin_relaxed_cas_close_body_map_rle[308] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8D, 0x00, 0x00, 0x01, 0x8E, 0x00,
    0x00, 0x02, 0xAA, 0x00, 0x00, 0x03, 0x8E, 0x00, 0x00, 0x04, 0xA8, 0x00, 0x02, 0x05, 0x00, 0x06,
    0x8E, 0x00, 0x00, 0x07, 0xA8, 0x00, 0x02, 0x08, 0x00, 0x09, 0x8E, 0x00, 0x00, 0x0A, 0xA8, 0x00,
    0x02, 0x0B, 0x00, 0x0C, 0x8E, 0x00, 0x00, 0x0D, 0xFF, 0x00, 0xEA, 0x00, 0x0E, 0x0E, 0x00, 0x0F,
    0x00, 0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0xAC, 0x00, 0x10, 0x16,
    0x00, 0x17, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E,
    0xAC, 0x00, 0x10, 0x1F, 0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25,
    0x00, 0x26, 0x00, 0x27, 0xAC, 0x00, 0x10, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C,
    0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0xAC, 0x00, 0x10, 0x31, 0x00, 0x32, 0x00, 0x33,
    0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0xAC, 0x00, 0x10, 0x3A,
    0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42,
    0xAC, 0x00, 0x12, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x47, 0x00, 0x47,
    0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0xAA, 0x00, 0x12, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E,
    0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0xAA, 0x00, 0x10, 0x55,
    0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D,
    0xAE, 0x00, 0x0E, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64,
    0x00, 0x65, 0xAC, 0x00, 0x10, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B,
    0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0xAC, 0x00, 0x12, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72,
    0x00, 0x73, 0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0x00, 0x77, 0x00, 0x78, 0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0x8E, 0x00,
};

const body rin_relaxed_cas_close_body = {
    /* used_tiles      */ rin_relaxed_cas_close_body_used,
    /* used_count      */ 121,
    /* map_compressed  */ rin_relaxed_cas_close_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 138,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_relaxed_cas_close,
};

alignas(int) static const uint16_t rin_basic_close_body_used[131] = {
    0, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 657, 1031, 1032,
    1033, 1034, 1035, 1036, 1037, 1038, 1039, 1040, 1041, 300, 564, 1042, 1043, 1044, 1045, 1046,
    1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062,
    1063, 1064, 1065, 1066, 1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078,
    1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094,
    1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110,
    1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118, 1119, 1120, 1121, 1122, 1123, 1124, 1125, 1126,
    1127, 1128, 1129, 1130, 1131, 1132, 1133, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142,
    1143, 1144, 1145,
};

alignas(int) static const unsigned char rin_basic_close_body_map_rle[332] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x9B, 0x00, 0x00, 0x01, 0xAA, 0x00,
    0x00, 0x02, 0x8E, 0x00, 0x02, 0x03, 0x00, 0x04, 0xA8, 0x00, 0x00, 0x05, 0x8E, 0x00, 0x02, 0x06,
    0x00, 0x07, 0xBA, 0x00, 0x04, 0x08, 0x00, 0x09, 0x00, 0x0A, 0xB8, 0x00, 0x02, 0x0B, 0x00, 0x0C,
    0xBA, 0x00, 0x00, 0x0D, 0xFC, 0x00, 0x00, 0x0E, 0xAE, 0x00, 0x10, 0x0F, 0x00, 0x10, 0x00, 0x11,
    0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0xAC, 0x00, 0x12, 0x18,
    0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x19, 0x00, 0x19, 0x00, 0x1D, 0x00, 0x1E,
    0x00, 0x1F, 0xAA, 0x00, 0x12, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x19,
    0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0xAA, 0x00, 0x12, 0x29, 0x00, 0x19, 0x00, 0x2A,
    0x00, 0x2B, 0x00, 0x2C, 0x00, 0x19, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0xAA, 0x00,
    0x12, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38,
    0x00, 0x39, 0x00, 0x3A, 0xAA, 0x00, 0x12, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F,
    0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0xAA, 0x00, 0x12, 0x45, 0x00, 0x46,
    0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E,
    0xAA, 0x00, 0x12, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55,
    0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0xAA, 0x00, 0x12, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C,
    0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0xAA, 0x00, 0x12, 0x63,
    0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B,
    0x00, 0x6C, 0xA8, 0x00, 0x14, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72,
    0x00, 0x73, 0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0x00, 0x77, 0xA8, 0x00, 0x14, 0x78, 0x00, 0x79,
    0x00, 0x7A, 0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E, 0x00, 0x7F, 0x00, 0x80, 0x00, 0x81,
    0x00, 0x82, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8E, 0x00, 0x00, 0x00,
};

const body rin_basic_close_body = {
    /* used_tiles      */ rin_basic_close_body_used,
    /* used_count      */ 131,
    /* map_compressed  */ rin_basic_close_body_map_rle,
    /* vis_x0          */ 9,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 138,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_basic_close,
};

alignas(int) static const uint16_t rin_negative_close_body_used[116] = {
    0, 1146, 1147, 1148, 1149, 1150, 1151, 1152, 1153, 788, 1154, 1155, 792, 793, 1156, 1157,
    1158, 1159, 1160, 1161, 1162, 1163, 1164, 300, 1165, 1166, 1167, 1168, 1169, 1170, 1171, 1172,
    1173, 1174, 1175, 1176, 1177, 1178, 1179, 1180, 1181, 1182, 1183, 1184, 1185, 1186, 1187, 1188,
    1189, 1190, 1191, 1192, 1193, 1194, 1195, 1196, 1197, 1198, 1199, 1200, 1201, 1202, 1203, 1204,
    1205, 1206, 1207, 1208, 1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1218, 1219, 1220,
    1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1232, 1233, 1234, 1235, 1236,
    1237, 1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245, 1246, 1247, 1248, 1249, 1250, 1251, 1252,
    1253, 1254, 1255, 1256,
};

alignas(int) static const unsigned char rin_negative_close_body_map_rle[300] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x89, 0x00, 0x00, 0x01, 0x8E, 0x00,
    0x00, 0x02, 0xAA, 0x00, 0x00, 0x03, 0x8E, 0x00, 0x02, 0x04, 0x00, 0x05, 0xA8, 0x00, 0x00, 0x06,
    0x8E, 0x00, 0x04, 0x07, 0x00, 0x08, 0x00, 0x09, 0xB8, 0x00, 0x04, 0x0A, 0x00, 0x0B, 0x00, 0x0C,
    0xB8, 0x00, 0x00, 0x0D, 0xFF, 0x00, 0xEC, 0x00, 0x0E, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0x00, 0x11,
    0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0xAE, 0x00, 0x10, 0x16, 0x00, 0x17, 0x00, 0x18,
    0x00, 0x19, 0x00, 0x1A, 0x00, 0x17, 0x00, 0x17, 0x00, 0x1B, 0x00, 0x1C, 0xAC, 0x00, 0x10, 0x1D,
    0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20, 0x00, 0x17, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24,
    0xAC, 0x00, 0x10, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x17, 0x00, 0x29, 0x00, 0x2A,
    0x00, 0x2B, 0x00, 0x2C, 0xAC, 0x00, 0x10, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31,
    0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0xAC, 0x00, 0x10, 0x36, 0x00, 0x37, 0x00, 0x38,
    0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0xAC, 0x00, 0x10, 0x3F,
    0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47,
    0xAC, 0x00, 0x10, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E,
    0x00, 0x4F, 0x00, 0x50, 0xAC, 0x00, 0x10, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55,
    0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0xAC, 0x00, 0x10, 0x5A, 0x00, 0x5B, 0x00, 0x5C,
    0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0xAC, 0x00, 0x10, 0x63,
    0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B,
    0xAC, 0x00, 0x10, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72,
    0x00, 0x17, 0x00, 0x73, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x90, 0x00,
};

const body rin_negative_close_body = {
    /* used_tiles      */ rin_negative_close_body_used,
    /* used_count      */ 116,
    /* map_compressed  */ rin_negative_close_body_map_rle,
    /* vis_x0          */ 9,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 138,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_negative_close,
};

alignas(int) static const uint16_t rin_relaxed_close_body_used[112] = {
    0, 1257, 1258, 1259, 1260, 905, 1261, 1262, 1263, 1264, 910, 1265, 1266, 913, 795, 1267,
    1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 300, 1276, 1277, 1278, 1279, 1280, 1281, 1282,
    1283, 1284, 1285, 1286, 1287, 1136, 1288, 1289, 1290, 1291, 1292, 1293, 1294, 1295, 1296, 1297,
    1298, 1299, 1300, 1301, 1302, 1303, 1304, 1305, 1306, 1307, 1308, 1309, 1310, 1311, 1312, 1313,
    1314, 1315, 1316, 1317, 1318, 1319, 1320, 1321, 1322, 1323, 1324, 1325, 1326, 1327, 1328, 1329,
    1330, 1331, 1332, 1333, 1334, 1335, 1336, 1337, 1338, 1339, 1340, 1341, 1342, 1343, 1344, 1345,
    1346, 1347, 1348, 1349, 1350, 1351, 1352, 1353, 1354, 1355, 1356, 1357, 1358, 1359, 1360, 1361,
};

alignas(int) static const unsigned char rin_relaxed_close_body_map_rle[308] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8D, 0x00, 0x00, 0x01, 0x8E, 0x00,
    0x00, 0x02, 0xAA, 0x00, 0x00, 0x03, 0x8E, 0x00, 0x00, 0x04, 0xA8, 0x00, 0x02, 0x05, 0x00, 0x06,
    0x8E, 0x00, 0x00, 0x07, 0xA8, 0x00, 0x02, 0x08, 0x00, 0x09, 0x8E, 0x00, 0x00, 0x0A, 0xA8, 0x00,
    0x02, 0x0B, 0x00, 0x0C, 0x8E, 0x00, 0x00, 0x0D, 0xFF, 0x00, 0xE8, 0x00, 0x10, 0x0E, 0x00, 0x0F,
    0x00, 0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0xAC, 0x00,
    0x10, 0x17, 0x00, 0x18, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x18, 0x00, 0x18,
    0x00, 0x1C, 0xAC, 0x00, 0x10, 0x1D, 0x00, 0x1E, 0x00, 0x18, 0x00, 0x1F, 0x00, 0x20, 0x00, 0x21,
    0x00, 0x18, 0x00, 0x22, 0x00, 0x23, 0xAC, 0x00, 0x10, 0x24, 0x00, 0x25, 0x00, 0x18, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x18, 0x00, 0x29, 0x00, 0x2A, 0xAC, 0x00, 0x10, 0x2B, 0x00, 0x2C,
    0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0xAC, 0x00,
    0x10, 0x34, 0x00, 0x35, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x35, 0x00, 0x35,
    0x00, 0x39, 0xAC, 0x00, 0x12, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F,
    0x00, 0x35, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0xAA, 0x00, 0x12, 0x43, 0x00, 0x44, 0x00, 0x45,
    0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0xAC, 0x00,
    0x0E, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54,
    0xAE, 0x00, 0x0E, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B,
    0x00, 0x5C, 0xAC, 0x00, 0x10, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62,
    0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0xAC, 0x00, 0x12, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69,
    0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0x8E, 0x00,
};

const body rin_relaxed_close_body = {
    /* used_tiles      */ rin_relaxed_close_body_used,
    /* used_count      */ 112,
    /* map_compressed  */ rin_relaxed_close_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 138,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_relaxed_close,
};

alignas(int) static const uint16_t rin_relaxed_silhouette_body_used[51] = {
    0, 1362, 1363, 1364, 1365, 1366, 1367, 1368, 1369, 1370, 1371, 1372, 1373, 1374, 1375, 1376,
    1377, 1378, 1379, 1380, 1381, 1382, 1383, 1384, 1385, 1386, 1387, 1388, 1389, 1390, 1391, 1392,
    1393, 1394, 1395, 1396, 1397, 1398, 1399, 1400, 1401, 1402, 1403, 1404, 1405, 1406, 1407, 1408,
    1409, 1410, 1411,
};

alignas(int) static const unsigned char rin_relaxed_silhouette_body_map_rle[260] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD3, 0x00, 0x06, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x00, 0x05, 0x86, 0x00, 0x02, 0x06, 0x00, 0x07, 0xB0, 0x00,
    0x00, 0x08, 0x86, 0x00, 0x02, 0x09, 0x00, 0x0A, 0xB0, 0x00, 0x00, 0x0B, 0x86, 0x00, 0x00, 0x0C,
    0xBC, 0x00, 0x00, 0x0D, 0xB4, 0x00, 0x06, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0x00, 0x11, 0xB4, 0x00,
    0x0A, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0xB2, 0x00, 0x0A, 0x17,
    0x00, 0x14, 0x00, 0x14, 0x00, 0x14, 0x00, 0x14, 0x00, 0x18, 0xB2, 0x00, 0x0A, 0x19, 0x00, 0x14,
    0x00, 0x14, 0x00, 0x14, 0x00, 0x14, 0x00, 0x1A, 0xB2, 0x00, 0x0A, 0x1B, 0x00, 0x14, 0x00, 0x14,
    0x00, 0x14, 0x00, 0x14, 0x00, 0x1A, 0xB2, 0x00, 0x0A, 0x1C, 0x00, 0x1D, 0x00, 0x14, 0x00, 0x14,
    0x00, 0x14, 0x00, 0x1E, 0xB2, 0x00, 0x0A, 0x1F, 0x00, 0x20, 0x00, 0x14, 0x00, 0x14, 0x00, 0x14,
    0x00, 0x21, 0xB2, 0x00, 0x0A, 0x22, 0x00, 0x14, 0x00, 0x14, 0x00, 0x14, 0x00, 0x14, 0x00, 0x23,
    0xB2, 0x00, 0x0C, 0x24, 0x00, 0x14, 0x00, 0x14, 0x00, 0x14, 0x00, 0x14, 0x00, 0x14, 0x00, 0x25,
    0xB0, 0x00, 0x0C, 0x26, 0x00, 0x14, 0x00, 0x14, 0x00, 0x27, 0x00, 0x14, 0x00, 0x14, 0x00, 0x28,
    0xB0, 0x00, 0x0C, 0x29, 0x00, 0x14, 0x00, 0x14, 0x00, 0x2A, 0x00, 0x14, 0x00, 0x14, 0x00, 0x2B,
    0xB0, 0x00, 0x0C, 0x2C, 0x00, 0x14, 0x00, 0x14, 0x00, 0x2D, 0x00, 0x14, 0x00, 0x14, 0x00, 0x2E,
    0xB0, 0x00, 0x0A, 0x1B, 0x00, 0x14, 0x00, 0x14, 0x00, 0x2F, 0x00, 0x14, 0x00, 0x14, 0xB2, 0x00,
    0x0A, 0x1B, 0x00, 0x14, 0x00, 0x30, 0x00, 0x31, 0x00, 0x14, 0x00, 0x32, 0xFF, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0x92, 0x00,
};

const body rin_relaxed_silhouette_body = {
    /* used_tiles      */ rin_relaxed_silhouette_body_used,
    /* used_count      */ 51,
    /* map_compressed  */ rin_relaxed_silhouette_body_map_rle,
    /* vis_x0          */ 13,
    /* vis_x1          */ 20,
    /* vis_y0          */ 7,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rin_thumb_relaxed_silhouette,
};

alignas(int) static const uint16_t rinpan_basic_body_used[92] = {
    0, 1412, 1413, 1414, 1415, 6, 1416, 1417, 1418, 1419, 1420, 1421, 1422, 1423, 1424, 1425,
    1426, 1427, 1428, 1429, 1430, 1431, 1432, 1433, 1434, 1435, 1436, 1437, 1438, 1439, 1440, 1441,
    1442, 1443, 1444, 1445, 1446, 1447, 1448, 1449, 1450, 1451, 1452, 1453, 1454, 1455, 1456, 1457,
    1458, 1459, 1460, 1461, 1462, 1463, 1464, 1465, 1466, 1467, 1468, 1469, 1470, 1471, 1472, 1473,
    1474, 1475, 1476, 1477, 1478, 1479, 1480, 1481, 1482, 1483, 1484, 1485, 1486, 1487, 1488, 1489,
    1490, 1491, 1492, 1493, 1494, 1495, 1496, 1497, 1498, 1499, 1500, 1501,
};

alignas(int) static const unsigned char rinpan_basic_body_map_rle[252] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD3, 0x00, 0x06, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0xB2, 0x00, 0x02, 0x05, 0x00, 0x06, 0xBA, 0x00, 0x02, 0x07, 0x00, 0x08,
    0x86, 0x00, 0x00, 0x09, 0xB2, 0x00, 0x00, 0x0A, 0x86, 0x00, 0x00, 0x0B, 0xB2, 0x00, 0x00, 0x0C,
    0xBE, 0x00, 0x06, 0x0D, 0x00, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0xB4, 0x00, 0x0A, 0x11, 0x00, 0x12,
    0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0xB2, 0x00, 0x0A, 0x17, 0x00, 0x18, 0x00, 0x19,
    0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0xB2, 0x00, 0x0A, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20,
    0x00, 0x21, 0x00, 0x22, 0xB2, 0x00, 0x0C, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27,
    0x00, 0x28, 0x00, 0x29, 0xB0, 0x00, 0x0A, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E,
    0x00, 0x2F, 0xB2, 0x00, 0x0A, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35,
    0xB2, 0x00, 0x0A, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0xB2, 0x00,
    0x0A, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0xB2, 0x00, 0x0A, 0x42,
    0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0xB2, 0x00, 0x0A, 0x48, 0x00, 0x49,
    0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0xB2, 0x00, 0x0A, 0x4E, 0x00, 0x4F, 0x00, 0x50,
    0x00, 0x4F, 0x00, 0x4F, 0x00, 0x51, 0xB2, 0x00, 0x0A, 0x52, 0x00, 0x4F, 0x00, 0x53, 0x00, 0x54,
    0x00, 0x55, 0x00, 0x56, 0xB2, 0x00, 0x0A, 0x57, 0x00, 0x4F, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A,
    0x00, 0x5B, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x92, 0x00, 0x00, 0x00,
};

const body rinpan_basic_body = {
    /* used_tiles      */ rinpan_basic_body_used,
    /* used_count      */ 92,
    /* map_compressed  */ rinpan_basic_body_map_rle,
    /* vis_x0          */ 12,
    /* vis_x1          */ 20,
    /* vis_y0          */ 7,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rinpan_thumb_basic,
};

alignas(int) static const uint16_t rinpan_relaxed_body_used[91] = {
    0, 1502, 1503, 1504, 1505, 1506, 1507, 183, 1508, 1509, 1510, 1511, 188, 1512, 1513, 1514,
    1515, 1516, 1517, 1518, 1519, 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527, 1528, 1529, 1530,
    1531, 1532, 1533, 1534, 1535, 1536, 1537, 1538, 1539, 1540, 1541, 1542, 1543, 1544, 1545, 1546,
    1547, 1548, 1549, 1550, 1551, 1552, 1553, 1554, 1555, 1556, 1557, 1558, 1559, 1560, 1561, 1562,
    1563, 1564, 1565, 1566, 1567, 1568, 1569, 1570, 1571, 1572, 1573, 1574, 1575, 1489, 1576, 1577,
    1578, 1579, 1580, 1581, 1582, 1583, 1584, 1585, 1586, 1587, 1588,
};

alignas(int) static const unsigned char rinpan_relaxed_body_map_rle[260] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xD3, 0x00, 0x06, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x00, 0x05, 0x86, 0x00, 0x02, 0x06, 0x00, 0x07, 0xB0, 0x00,
    0x00, 0x08, 0x86, 0x00, 0x00, 0x09, 0xB2, 0x00, 0x00, 0x0A, 0x86, 0x00, 0x00, 0x0B, 0xBC, 0x00,
    0x00, 0x0C, 0xB4, 0x00, 0x06, 0x0D, 0x00, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0xB4, 0x00, 0x0A, 0x11,
    0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0xB2, 0x00, 0x0A, 0x17, 0x00, 0x18,
    0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0xB2, 0x00, 0x0A, 0x1D, 0x00, 0x1E, 0x00, 0x1F,
    0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0xB2, 0x00, 0x0A, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0xB2, 0x00, 0x0A, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D,
    0x00, 0x2E, 0xB2, 0x00, 0x0A, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34,
    0xB2, 0x00, 0x0A, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0xB2, 0x00,
    0x0C, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0xB0, 0x00,
    0x0C, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0xB0, 0x00,
    0x0C, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4D, 0x00, 0x4E, 0xB0, 0x00,
    0x0C, 0x4F, 0x00, 0x4D, 0x00, 0x50, 0x00, 0x51, 0x00, 0x4D, 0x00, 0x52, 0x00, 0x53, 0xB0, 0x00,
    0x0A, 0x54, 0x00, 0x4D, 0x00, 0x55, 0x00, 0x56, 0x00, 0x4D, 0x00, 0x57, 0xB2, 0x00, 0x0A, 0x54,
    0x00, 0x4D, 0x00, 0x58, 0x00, 0x59, 0x00, 0x4D, 0x00, 0x5A, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
    0x92, 0x00, 0x00, 0x00,
};

const body rinpan_relaxed_body = {
    /* used_tiles      */ rinpan_relaxed_body_used,
    /* used_count      */ 91,
    /* map_compressed  */ rinpan_relaxed_body_map_rle,
    /* vis_x0          */ 13,
    /* vis_x1          */ 20,
    /* vis_y0          */ 7,
    /* vis_y1          */ 26,
    /* render_w_px     */ 61,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rinpan_thumb_relaxed,
};

alignas(int) static const uint16_t rinpan_basic_close_body_used[138] = {
    0, 1589, 280, 1590, 1591, 1592, 1593, 1594, 1595, 1596, 1597, 1598, 1599, 1600, 1601, 1602,
    1603, 1604, 1605, 1606, 1607, 1608, 1609, 1610, 1611, 1612, 1613, 1614, 1615, 1616, 1617, 1618,
    1619, 1620, 1621, 1622, 1623, 1624, 1625, 1626, 1489, 1627, 1628, 1629, 1630, 1631, 1632, 1633,
    300, 1634, 1635, 1636, 1637, 1638, 1639, 1640, 1641, 1642, 1643, 1644, 1645, 1646, 1647, 1648,
    1649, 1650, 1651, 1652, 1653, 1654, 1655, 1656, 1657, 1658, 1659, 1660, 1661, 1662, 1303, 1663,
    1664, 1665, 1666, 1667, 1668, 1669, 1670, 1671, 1672, 1673, 1674, 1675, 1676, 1677, 1678, 1679,
    1680, 1681, 1682, 1683, 1684, 1685, 1686, 1687, 1688, 1689, 1690, 1691, 1692, 1693, 1694, 1695,
    1696, 1697, 1698, 1699, 1700, 1701, 1702, 1703, 1704, 1705, 1706, 1707, 1708, 1709, 1710, 1711,
    1712, 1713, 1714, 1715, 1716, 1717, 1718, 1719, 1720, 1721,
};

alignas(int) static const unsigned char rinpan_basic_close_body_map_rle[336] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x9B, 0x00, 0x02, 0x01, 0x00, 0x02,
    0xA8, 0x00, 0x00, 0x03, 0x8E, 0x00, 0x02, 0x04, 0x00, 0x05, 0xA8, 0x00, 0x00, 0x06, 0x8E, 0x00,
    0x04, 0x07, 0x00, 0x08, 0x00, 0x09, 0xB8, 0x00, 0x04, 0x0A, 0x00, 0x0B, 0x00, 0x0C, 0xB8, 0x00,
    0x04, 0x0D, 0x00, 0x0E, 0x00, 0x0F, 0xB8, 0x00, 0x00, 0x10, 0xFC, 0x00, 0x00, 0x11, 0xAE, 0x00,
    0x10, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00, 0x18, 0x00, 0x19,
    0x00, 0x1A, 0xAC, 0x00, 0x12, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20,
    0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0xAA, 0x00, 0x12, 0x25, 0x00, 0x26, 0x00, 0x27,
    0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0xAA, 0x00,
    0x12, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36,
    0x00, 0x37, 0x00, 0x38, 0xAA, 0x00, 0x12, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0xAA, 0x00, 0x12, 0x43, 0x00, 0x44,
    0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C,
    0xAA, 0x00, 0x14, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x4E, 0x00, 0x52,
    0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0xA8, 0x00, 0x12, 0x57, 0x00, 0x58, 0x00, 0x59,
    0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0xAA, 0x00,
    0x12, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x67, 0x00, 0x68,
    0x00, 0x69, 0x00, 0x6A, 0xAA, 0x00, 0x12, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F,
    0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73, 0x00, 0x74, 0xAA, 0x00, 0x12, 0x75, 0x00, 0x76,
    0x00, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00, 0x7A, 0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E,
    0xA8, 0x00, 0x14, 0x7F, 0x00, 0x80, 0x00, 0x81, 0x00, 0x82, 0x00, 0x83, 0x00, 0x84, 0x00, 0x85,
    0x00, 0x86, 0x00, 0x87, 0x00, 0x88, 0x00, 0x89, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8E, 0x00,
};

const body rinpan_basic_close_body = {
    /* used_tiles      */ rinpan_basic_close_body_used,
    /* used_count      */ 138,
    /* map_compressed  */ rinpan_basic_close_body_map_rle,
    /* vis_x0          */ 9,
    /* vis_x1          */ 22,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 138,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rinpan_thumb_basic_close,
};

alignas(int) static const uint16_t rinpan_relaxed_close_body_used[117] = {
    0, 1722, 1723, 1724, 1725, 1726, 1727, 1728, 1729, 1730, 1731, 911, 1732, 1733, 1734, 1735,
    1736, 1737, 1738, 1739, 1740, 1741, 1742, 1743, 1744, 1745, 1746, 1747, 1748, 1749, 1750, 1751,
    1752, 1753, 1754, 1755, 1756, 1489, 1757, 1758, 1759, 1760, 1761, 1136, 1762, 1763, 1764, 1765,
    1766, 1767, 1768, 1769, 1770, 1771, 1772, 1773, 1774, 1775, 1776, 1777, 1778, 1303, 1779, 1780,
    1781, 1782, 1783, 1784, 1785, 1786, 1787, 1788, 1789, 1790, 1791, 1792, 1793, 1794, 1795, 1796,
    1797, 1798, 1799, 1800, 1801, 1802, 1803, 1804, 1805, 1806, 1807, 1808, 1809, 1810, 1811, 1812,
    1813, 1814, 1815, 1816, 1817, 1818, 1819, 1820, 1821, 1822, 1823, 1824, 1825, 1826, 1827, 1828,
    1829, 1830, 1831, 1832, 1833,
};

alignas(int) static const unsigned char rinpan_relaxed_close_body_map_rle[304] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8D, 0x00, 0x02, 0x01, 0x00, 0x02,
    0xBA, 0x00, 0x02, 0x03, 0x00, 0x04, 0xB8, 0x00, 0x04, 0x05, 0x00, 0x06, 0x00, 0x07, 0xB8, 0x00,
    0x04, 0x08, 0x00, 0x09, 0x00, 0x0A, 0xB8, 0x00, 0x04, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0xBC, 0x00,
    0x00, 0x0E, 0xFF, 0x00, 0xB8, 0x00, 0x10, 0x0F, 0x00, 0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x13,
    0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0xAC, 0x00, 0x10, 0x18, 0x00, 0x19, 0x00, 0x1A,
    0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20, 0xAC, 0x00, 0x10, 0x21,
    0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29,
    0xAC, 0x00, 0x10, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30,
    0x00, 0x31, 0x00, 0x32, 0xAC, 0x00, 0x10, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37,
    0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0xAC, 0x00, 0x10, 0x3C, 0x00, 0x3D, 0x00, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0x00, 0x3D, 0x00, 0x3D, 0x00, 0x3D, 0x00, 0x40, 0xAC, 0x00, 0x12, 0x41,
    0x00, 0x42, 0x00, 0x3D, 0x00, 0x3D, 0x00, 0x43, 0x00, 0x44, 0x00, 0x3D, 0x00, 0x45, 0x00, 0x46,
    0x00, 0x47, 0xAA, 0x00, 0x12, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x3D, 0x00, 0x4B, 0x00, 0x4C,
    0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0xAA, 0x00, 0x10, 0x51, 0x00, 0x52, 0x00, 0x53,
    0x00, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0xAE, 0x00, 0x0E, 0x5A,
    0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0xAC, 0x00,
    0x10, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x67, 0x00, 0x68, 0x00, 0x69,
    0x00, 0x6A, 0xAC, 0x00, 0x12, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70,
    0x00, 0x71, 0x00, 0x72, 0x00, 0x73, 0x00, 0x74, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8E, 0x00,
};

const body rinpan_relaxed_close_body = {
    /* used_tiles      */ rinpan_relaxed_close_body_used,
    /* used_count      */ 117,
    /* map_compressed  */ rinpan_relaxed_close_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 138,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::rinpan_thumb_relaxed_close,
};

const variant rin_basic_cas_deadpanupset = {
    /* body                */ &rin_basic_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpanupset_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x4EBA,
};

const variant rin_basic_cas_deadpancontemplation = {
    /* body                */ &rin_basic_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpancontemplation_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x4EBA,
};

const variant rin_basic_cas_deadpan = {
    /* body                */ &rin_basic_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpan_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x4EBA,
};

const variant rin_basic_cas_surprised = {
    /* body                */ &rin_basic_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_surprised_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x4EBA,
};

const variant rin_basic_cas_deadpannormal = {
    /* body                */ &rin_basic_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpannormal_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x4EBA,
};

const variant rin_basic_cas_awayabsent = {
    /* body                */ &rin_basic_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_awayabsent_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x4EBA,
};

const variant rin_basic_cas_sad = {
    /* body                */ &rin_basic_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_sad_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x4EBA,
};

const variant rin_basic_cas_absent = {
    /* body                */ &rin_basic_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_absent_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x4EBA,
};

const variant rin_basic_cas_lucid = {
    /* body                */ &rin_basic_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_lucid_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x4EBA,
};

const variant rin_negative_cas_spaciness = {
    /* body                */ &rin_negative_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_spaciness_cas,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xFEFC,
};

const variant rin_negative_cas_annoyed = {
    /* body                */ &rin_negative_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_annoyed_cas,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xFEFC,
};

const variant rin_negative_cas_sad = {
    /* body                */ &rin_negative_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_sad_cas,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xFEFC,
};

const variant rin_negative_cas_worried = {
    /* body                */ &rin_negative_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_worried_cas,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xFEFC,
};

const variant rin_negative_cas_confused = {
    /* body                */ &rin_negative_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_confused_cas,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xFEFC,
};

const variant rin_negative_cas_angry = {
    /* body                */ &rin_negative_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_angry_cas,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xFEFC,
};

const variant rin_relaxed_cas_sleepy = {
    /* body                */ &rin_relaxed_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_sleepy_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x7969,
};

const variant rin_relaxed_cas_doubt = {
    /* body                */ &rin_relaxed_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_doubt_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x7969,
};

const variant rin_relaxed_cas_nonchalant = {
    /* body                */ &rin_relaxed_cas_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_nonchalant_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x7969,
};

const variant rin_basic_delight = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_delight,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_sad = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_sad,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_deadpannormal = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpannormal,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_surprised = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_surprised,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_deadpandelight = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpandelight,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_upset = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_upset,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_deadpanamused = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpanamused,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_absent = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_absent,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_amused = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_amused,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_deadpanupset = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpanupset,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_deadpancontemplation = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpancontemplation,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_lucid = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_lucid,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_crying = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_crying,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_awayabsent = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_awayabsent,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_deadpansurprised = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpansurprised,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_basic_deadpan = {
    /* body                */ &rin_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpan,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6765,
};

const variant rin_negative_angry = {
    /* body                */ &rin_negative_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_angry,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x75C0,
};

const variant rin_negative_crying = {
    /* body                */ &rin_negative_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_crying,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x75C0,
};

const variant rin_negative_confused = {
    /* body                */ &rin_negative_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_confused,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x75C0,
};

const variant rin_negative_sad = {
    /* body                */ &rin_negative_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_sad,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x75C0,
};

const variant rin_negative_annoyed = {
    /* body                */ &rin_negative_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_annoyed,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x75C0,
};

const variant rin_negative_worried = {
    /* body                */ &rin_negative_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_worried,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x75C0,
};

const variant rin_negative_spaciness = {
    /* body                */ &rin_negative_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_spaciness,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 5,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x75C0,
};

const variant rin_relaxed_doubt = {
    /* body                */ &rin_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_doubt,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xA9BE,
};

const variant rin_relaxed_surprised = {
    /* body                */ &rin_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_surprised,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xA9BE,
};

const variant rin_relaxed_boredom = {
    /* body                */ &rin_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_boredom,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xA9BE,
};

const variant rin_relaxed_nonchalant = {
    /* body                */ &rin_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_nonchalant,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xA9BE,
};

const variant rin_relaxed_disgust = {
    /* body                */ &rin_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_disgust,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xA9BE,
};

const variant rin_relaxed_sleepy = {
    /* body                */ &rin_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_sleepy,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xA9BE,
};

const variant rin_back_cas = {
    /* body                */ &rin_back_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_back_cas,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE17D,
};

const variant rin_basic_cas_close_awayabsent = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_awayabsent_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_basic_cas_close_sad = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_sad_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_basic_cas_close_lucid = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_lucid_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_basic_cas_close_deadpansurprised = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpansurprised_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_basic_cas_close_deadpanupset = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpanupset_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_basic_cas_close_deadpanamused = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpanamused_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_basic_cas_close_deadpan = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpan_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_basic_cas_close_deadpannormal = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpannormal_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_basic_cas_close_surprised = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_surprised_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_basic_cas_close_absent = {
    /* body                */ &rin_basic_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_absent_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x131F,
};

const variant rin_negative_cas_close_sad = {
    /* body                */ &rin_negative_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_sad_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD7E9,
};

const variant rin_negative_cas_close_confused = {
    /* body                */ &rin_negative_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_confused_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD7E9,
};

const variant rin_negative_cas_close_worried = {
    /* body                */ &rin_negative_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_worried_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD7E9,
};

const variant rin_negative_cas_close_spaciness = {
    /* body                */ &rin_negative_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_spaciness_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD7E9,
};

const variant rin_negative_cas_close_annoyed = {
    /* body                */ &rin_negative_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_annoyed_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD7E9,
};

const variant rin_negative_cas_close_angry = {
    /* body                */ &rin_negative_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_angry_cas_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD7E9,
};

const variant rin_relaxed_cas_close_nonchalant = {
    /* body                */ &rin_relaxed_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_nonchalant_cas_close,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBFF7,
};

const variant rin_relaxed_cas_close_doubt = {
    /* body                */ &rin_relaxed_cas_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_doubt_cas_close,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xBFF7,
};

const variant rin_basic_close_crying = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_crying_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_awayabsent = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_awayabsent_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_lucid = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_lucid_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_delight = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_delight_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_deadpandelight = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpandelight_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_upset = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_upset_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_amused = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_amused_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_deadpanupset = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpanupset_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_blush = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_blush_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_deadpancontemplation = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpancontemplation_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_deadpansurprised = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpansurprised_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_deadpan = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpan_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_sad = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_sad_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_surprised = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_surprised_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_deadpannormal = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpannormal_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_deadpanamused = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_deadpanamused_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_basic_close_absent = {
    /* body                */ &rin_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_basic_absent_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEA6A,
};

const variant rin_negative_close_worried = {
    /* body                */ &rin_negative_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_worried_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD1BB,
};

const variant rin_negative_close_sad = {
    /* body                */ &rin_negative_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_sad_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD1BB,
};

const variant rin_negative_close_confused = {
    /* body                */ &rin_negative_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_confused_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD1BB,
};

const variant rin_negative_close_annoyed = {
    /* body                */ &rin_negative_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_annoyed_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD1BB,
};

const variant rin_negative_close_spaciness = {
    /* body                */ &rin_negative_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_spaciness_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD1BB,
};

const variant rin_negative_close_angry = {
    /* body                */ &rin_negative_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_negative_angry_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xD1BB,
};

const variant rin_relaxed_close_sleepy = {
    /* body                */ &rin_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_sleepy_close,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x8AD3,
};

const variant rin_relaxed_close_surprised = {
    /* body                */ &rin_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_surprised_close,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x8AD3,
};

const variant rin_relaxed_close_nonchalant = {
    /* body                */ &rin_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_nonchalant_close,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x8AD3,
};

const variant rin_relaxed_close_boredom = {
    /* body                */ &rin_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_boredom_close,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x8AD3,
};

const variant rin_relaxed_close_doubt = {
    /* body                */ &rin_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_doubt_close,
    /* face_offset_x_cells */ 12,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0x8AD3,
};

const variant rin_relaxed_silhouette_surprised = {
    /* body                */ &rin_relaxed_silhouette_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rin_spr_relaxed_surprised_silhouette,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x1766,
};

const variant rinpan_basic_deadpan = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpan,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_upset = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_upset,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_surprised = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_surprised,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_awayabsent = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_awayabsent,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_deadpandelight = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpandelight,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_deadpanupset = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpanupset,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_deadpanamused = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpanamused,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_amused = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_amused,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_absent = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_absent,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_lucid = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_lucid,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_deadpancontemplation = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpancontemplation,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_deadpannormal = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpannormal,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_basic_deadpansurprised = {
    /* body                */ &rinpan_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpansurprised,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0xE908,
};

const variant rinpan_relaxed_sleepy = {
    /* body                */ &rinpan_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_sleepy,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x2D7F,
};

const variant rinpan_relaxed_boredom = {
    /* body                */ &rinpan_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_boredom,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x2D7F,
};

const variant rinpan_relaxed_surprised = {
    /* body                */ &rinpan_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_surprised,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x2D7F,
};

const variant rinpan_relaxed_nonchalant = {
    /* body                */ &rinpan_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_nonchalant,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x2D7F,
};

const variant rinpan_relaxed_doubt = {
    /* body                */ &rinpan_relaxed_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_doubt,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x2D7F,
};

const variant rinpan_basic_close_deadpanamused = {
    /* body                */ &rinpan_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpanamused_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCE97,
};

const variant rinpan_basic_close_awayabsent = {
    /* body                */ &rinpan_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_awayabsent_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCE97,
};

const variant rinpan_basic_close_deadpancontemplation = {
    /* body                */ &rinpan_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpancontemplation_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCE97,
};

const variant rinpan_basic_close_deadpan = {
    /* body                */ &rinpan_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpan_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCE97,
};

const variant rinpan_basic_close_lucid = {
    /* body                */ &rinpan_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_lucid_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCE97,
};

const variant rinpan_basic_close_deadpandelight = {
    /* body                */ &rinpan_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpandelight_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCE97,
};

const variant rinpan_basic_close_deadpanupset = {
    /* body                */ &rinpan_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_basic_deadpanupset_close,
    /* face_offset_x_cells */ 10,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xCE97,
};

const variant rinpan_relaxed_close_boredom = {
    /* body                */ &rinpan_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_boredom_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEAA1,
};

const variant rinpan_relaxed_close_doubt = {
    /* body                */ &rinpan_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_doubt_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEAA1,
};

const variant rinpan_relaxed_close_sleepy = {
    /* body                */ &rinpan_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_sleepy_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEAA1,
};

const variant rinpan_relaxed_close_nonchalant = {
    /* body                */ &rinpan_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_nonchalant_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEAA1,
};

const variant rinpan_relaxed_close_surprised = {
    /* body                */ &rinpan_relaxed_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::rinpan_spr_relaxed_surprised_close,
    /* face_offset_x_cells */ 13,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xEAA1,
};

}  // namespace ks::smart_characters::rin
