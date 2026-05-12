#include "smart_characters/hideaki.h"

#include "bn_regular_bg_tiles_items_hideaki_tiles_0.h"
#include "bn_bg_palette_items_pal_char_bg.h"
#include "bn_sprite_tiles_items_hideaki_thumb_basic.h"
#include "bn_sprite_tiles_items_hideaki_thumb_up.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_angry.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_bored.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_confused.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_darkside.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_disapproves.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_evil.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_happy.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_normal.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_ohshit.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_sad.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_serious.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_surprise.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_thinking.h"
#include "bn_sprite_tiles_items_hideaki_spr_basic_triangle.h"
#include "bn_sprite_tiles_items_hideaki_spr_up_angry.h"
#include "bn_sprite_tiles_items_hideaki_spr_up_bored.h"
#include "bn_sprite_tiles_items_hideaki_spr_up_closed.h"
#include "bn_sprite_tiles_items_hideaki_spr_up_happy.h"
#include "bn_sprite_tiles_items_hideaki_spr_up_normal.h"
#include "bn_sprite_tiles_items_hideaki_spr_up_serious.h"
#include "bn_sprite_tiles_items_hideaki_spr_up_surprise.h"

namespace ks::smart_characters::hideaki {

static const bn::regular_bg_tiles_item* const slab_table[1] = {
    &bn::regular_bg_tiles_items::hideaki_tiles_0,
};

const tileset_data tileset = {
    /* slabs       */ slab_table,
    /* slab_count  */ 1,
    /* palette     */ &bn::bg_palette_items::pal_char_bg,
};

alignas(int) static const uint16_t hideaki_basic_body_used[112] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
};

alignas(int) static const unsigned char hideaki_basic_body_map_rle[284] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8F, 0x00, 0x08, 0x01,
    0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0xB4, 0x00, 0x0A, 0x06, 0x00, 0x07, 0x00, 0x08,
    0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0xB2, 0x00, 0x00, 0x0C, 0x86, 0x00, 0x00, 0x0D, 0xB0, 0x00,
    0x02, 0x0E, 0x00, 0x0F, 0x86, 0x00, 0x00, 0x10, 0xB0, 0x00, 0x02, 0x11, 0x00, 0x12, 0xBC, 0x00,
    0x00, 0x13, 0xBC, 0x00, 0x08, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00, 0x18, 0xB2, 0x00,
    0x0C, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0xB0, 0x00,
    0x0E, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27,
    0xAE, 0x00, 0x0C, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E,
    0xB0, 0x00, 0x0C, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35,
    0xB0, 0x00, 0x0E, 0x36, 0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C,
    0x00, 0x3D, 0xAE, 0x00, 0x0E, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43,
    0x00, 0x44, 0x00, 0x45, 0xAE, 0x00, 0x0E, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A,
    0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0xAE, 0x00, 0x0E, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51,
    0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0xAE, 0x00, 0x0E, 0x56, 0x00, 0x57, 0x00, 0x58,
    0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5D, 0xAE, 0x00, 0x10, 0x5E, 0x00, 0x5F,
    0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0xAC, 0x00,
    0x10, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E,
    0x00, 0x6F, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8E, 0x00, 0x00, 0x00,
};

const body hideaki_basic_body = {
    /* used_tiles      */ hideaki_basic_body_used,
    /* used_count      */ 112,
    /* map_compressed  */ hideaki_basic_body_map_rle,
    /* vis_x0          */ 12,
    /* vis_x1          */ 21,
    /* vis_y0          */ 8,
    /* vis_y1          */ 26,
    /* render_w_px     */ 81,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::hideaki_thumb_basic,
};

alignas(int) static const uint16_t hideaki_up_body_used[107] = {
    0, 1, 2, 3, 112, 5, 6, 7, 113, 114, 10, 11, 115, 13, 14, 116,
    16, 17, 117, 118, 119, 21, 120, 121, 24, 25, 122, 123, 124, 125, 126, 127,
    32, 128, 129, 130, 131, 132, 133, 39, 134, 135, 136, 137, 138, 139, 140, 141,
    142, 143, 144, 50, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156,
    157, 158, 159, 160, 161, 67, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171,
    172, 80, 173, 82, 174, 175, 176, 177, 178, 179, 91, 180, 181, 182, 183, 184,
    185, 186, 187, 188, 189, 190, 191, 107, 192, 193, 194,
};

alignas(int) static const unsigned char hideaki_up_body_map_rle[272] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8F, 0x00, 0x08, 0x01,
    0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0xB4, 0x00, 0x0A, 0x06, 0x00, 0x07, 0x00, 0x08,
    0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0xB2, 0x00, 0x00, 0x0C, 0x86, 0x00, 0x00, 0x0D, 0xB0, 0x00,
    0x02, 0x0E, 0x00, 0x0F, 0x86, 0x00, 0x00, 0x10, 0xB0, 0x00, 0x02, 0x11, 0x00, 0x12, 0xBC, 0x00,
    0x00, 0x13, 0xBC, 0x00, 0x08, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00, 0x18, 0xB2, 0x00,
    0x0C, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0xB0, 0x00,
    0x0E, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27,
    0xAE, 0x00, 0x0E, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E,
    0x00, 0x2F, 0xAE, 0x00, 0x0E, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35,
    0x00, 0x36, 0x00, 0x37, 0xAE, 0x00, 0x0E, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C,
    0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F, 0xAE, 0x00, 0x0E, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43,
    0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0xAE, 0x00, 0x0E, 0x48, 0x00, 0x49, 0x00, 0x4A,
    0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0xB0, 0x00, 0x0A, 0x50, 0x00, 0x51,
    0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55, 0xB2, 0x00, 0x0C, 0x56, 0x00, 0x57, 0x00, 0x58,
    0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0xB0, 0x00, 0x0C, 0x5D, 0x00, 0x5E, 0x00, 0x5F,
    0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0xB0, 0x00, 0x0C, 0x64, 0x00, 0x65, 0x00, 0x66,
    0x00, 0x67, 0x00, 0x68, 0x00, 0x69, 0x00, 0x6A, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x90, 0x00,
};

const body hideaki_up_body = {
    /* used_tiles      */ hideaki_up_body_used,
    /* used_count      */ 107,
    /* map_compressed  */ hideaki_up_body_map_rle,
    /* vis_x0          */ 12,
    /* vis_x1          */ 20,
    /* vis_y0          */ 8,
    /* vis_y1          */ 26,
    /* render_w_px     */ 81,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::hideaki_thumb_up,
};

const variant hideaki_basic_happy = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_happy,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_evil = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_evil,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_disapproves = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_disapproves,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_normal = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_normal,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_ohshit = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_ohshit,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_thinking = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_thinking,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_darkside = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_darkside,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_surprise = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_surprise,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_triangle = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_triangle,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_bored = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_bored,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_angry = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_angry,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_confused = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_confused,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_sad = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_sad,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_basic_serious = {
    /* body                */ &hideaki_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_basic_serious,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x6FE6,
};

const variant hideaki_up_surprise = {
    /* body                */ &hideaki_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_up_surprise,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x164D,
};

const variant hideaki_up_angry = {
    /* body                */ &hideaki_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_up_angry,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x164D,
};

const variant hideaki_up_serious = {
    /* body                */ &hideaki_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_up_serious,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x164D,
};

const variant hideaki_up_bored = {
    /* body                */ &hideaki_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_up_bored,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x164D,
};

const variant hideaki_up_happy = {
    /* body                */ &hideaki_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_up_happy,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x164D,
};

const variant hideaki_up_closed = {
    /* body                */ &hideaki_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_up_closed,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x164D,
};

const variant hideaki_up_normal = {
    /* body                */ &hideaki_up_body,
    /* face_tiles          */ &bn::sprite_tiles_items::hideaki_spr_up_normal,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 10,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x164D,
};

}  // namespace ks::smart_characters::hideaki
