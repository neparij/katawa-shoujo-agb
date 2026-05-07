#include "smart_characters/akira.h"

#include "bn_regular_bg_tiles_items_akira_tiles_0.h"
#include "bn_bg_palette_items_pal_char_bg.h"
#include "bn_sprite_tiles_items_akira_thumb_basic.h"
#include "bn_sprite_tiles_items_akira_thumb_basic_close.h"
#include "bn_sprite_tiles_items_akira_spr_basic_annoyed.h"
#include "bn_sprite_tiles_items_akira_spr_basic_annoyed_close.h"
#include "bn_sprite_tiles_items_akira_spr_basic_boo.h"
#include "bn_sprite_tiles_items_akira_spr_basic_boo_close.h"
#include "bn_sprite_tiles_items_akira_spr_basic_distant_close.h"
#include "bn_sprite_tiles_items_akira_spr_basic_ending.h"
#include "bn_sprite_tiles_items_akira_spr_basic_ending_close.h"
#include "bn_sprite_tiles_items_akira_spr_basic_evil.h"
#include "bn_sprite_tiles_items_akira_spr_basic_kill.h"
#include "bn_sprite_tiles_items_akira_spr_basic_laugh.h"
#include "bn_sprite_tiles_items_akira_spr_basic_laugh_close.h"
#include "bn_sprite_tiles_items_akira_spr_basic_lost.h"
#include "bn_sprite_tiles_items_akira_spr_basic_lost_close.h"
#include "bn_sprite_tiles_items_akira_spr_basic_resigned.h"
#include "bn_sprite_tiles_items_akira_spr_basic_resigned_close.h"
#include "bn_sprite_tiles_items_akira_spr_basic_smile.h"
#include "bn_sprite_tiles_items_akira_spr_basic_smile_close.h"

namespace ks::smart_characters::akira {

static const bn::regular_bg_tiles_item* const slab_table[1] = {
    &bn::regular_bg_tiles_items::akira_tiles_0,
};

const tileset_data tileset = {
    /* slabs       */ slab_table,
    /* slab_count  */ 1,
    /* palette     */ &bn::bg_palette_items::pal_char_bg,
};

alignas(int) static const uint16_t akira_basic_body_used[126] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125,
};

alignas(int) static const unsigned char akira_basic_body_map_rle[312] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x93, 0x00, 0x06, 0x01, 0x00, 0x02,
    0x00, 0x03, 0x00, 0x04, 0xB4, 0x00, 0x0A, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00, 0x09,
    0x00, 0x0A, 0xB2, 0x00, 0x00, 0x0B, 0x86, 0x00, 0x00, 0x0C, 0xB2, 0x00, 0x00, 0x0D, 0x86, 0x00,
    0x00, 0x0E, 0xFF, 0x00, 0xB0, 0x00, 0x0A, 0x0F, 0x00, 0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x13,
    0x00, 0x14, 0xB2, 0x00, 0x0C, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A,
    0x00, 0x1B, 0xB0, 0x00, 0x0C, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20, 0x00, 0x21,
    0x00, 0x22, 0xB0, 0x00, 0x0C, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28,
    0x00, 0x29, 0xAE, 0x00, 0x0E, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F,
    0x00, 0x30, 0x00, 0x31, 0xAE, 0x00, 0x0E, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36,
    0x00, 0x37, 0x00, 0x38, 0x00, 0x39, 0xAE, 0x00, 0x0E, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D,
    0x00, 0x3E, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x41, 0xAE, 0x00, 0x10, 0x42, 0x00, 0x43, 0x00, 0x44,
    0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0xAC, 0x00, 0x10, 0x4B,
    0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53,
    0xAC, 0x00, 0x10, 0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A,
    0x00, 0x5B, 0x00, 0x5C, 0xAC, 0x00, 0x10, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61,
    0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0xAC, 0x00, 0x0E, 0x66, 0x00, 0x67, 0x00, 0x68,
    0x00, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0xAE, 0x00, 0x0E, 0x6E, 0x00, 0x6F,
    0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73, 0x00, 0x74, 0x00, 0x75, 0xAE, 0x00, 0x0E, 0x76,
    0x00, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00, 0x7A, 0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00, 0x90, 0x00, 0x00, 0x00,
};

const body akira_basic_body = {
    /* used_tiles      */ akira_basic_body_used,
    /* used_count      */ 126,
    /* map_compressed  */ akira_basic_body_map_rle,
    /* vis_x0          */ 12,
    /* vis_x1          */ 21,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 67,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::akira_thumb_basic,
};

alignas(int) static const uint16_t akira_basic_close_body_used[141] = {
    0, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
    141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156,
    157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172,
    173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188,
    189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204,
    205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220,
    221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236,
    237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252,
    253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265,
};

alignas(int) static const unsigned char akira_basic_close_body_map_rle[336] = {
    0x30, 0x00, 0x08, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x9D, 0x00, 0x00, 0x01, 0xBC, 0x00,
    0x00, 0x02, 0xBC, 0x00, 0x00, 0x03, 0xBC, 0x00, 0x00, 0x04, 0xBC, 0x00, 0x00, 0x05, 0xFF, 0x00,
    0xEC, 0x00, 0x0E, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0x00, 0x0C,
    0x00, 0x0D, 0xAC, 0x00, 0x12, 0x0E, 0x00, 0x0F, 0x00, 0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x13,
    0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0xA8, 0x00, 0x14, 0x18, 0x00, 0x19, 0x00, 0x1A,
    0x00, 0x1B, 0x00, 0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20, 0x00, 0x21, 0x00, 0x22,
    0xA8, 0x00, 0x14, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29,
    0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0xA8, 0x00, 0x14, 0x2E, 0x00, 0x2F, 0x00, 0x30,
    0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00, 0x38,
    0xA8, 0x00, 0x16, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00, 0x3F,
    0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0xA6, 0x00, 0x16, 0x45, 0x00, 0x46,
    0x00, 0x47, 0x00, 0x48, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E,
    0x00, 0x4F, 0x00, 0x50, 0xA6, 0x00, 0x16, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00, 0x54, 0x00, 0x55,
    0x00, 0x56, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0xA6, 0x00,
    0x16, 0x5D, 0x00, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64,
    0x00, 0x65, 0x00, 0x66, 0x00, 0x67, 0x00, 0x68, 0xA6, 0x00, 0x16, 0x69, 0x00, 0x6A, 0x00, 0x6B,
    0x00, 0x6C, 0x00, 0x6D, 0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00, 0x73,
    0x00, 0x74, 0xA6, 0x00, 0x16, 0x75, 0x00, 0x76, 0x00, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00, 0x7A,
    0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E, 0x00, 0x7F, 0x00, 0x80, 0xA6, 0x00, 0x16, 0x81,
    0x00, 0x82, 0x00, 0x83, 0x00, 0x84, 0x00, 0x85, 0x00, 0x86, 0x00, 0x87, 0x00, 0x88, 0x00, 0x89,
    0x00, 0x8A, 0x00, 0x8B, 0x00, 0x8C, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x8C, 0x00, 0x00, 0x00,
};

const body akira_basic_close_body = {
    /* used_tiles      */ akira_basic_close_body_used,
    /* used_count      */ 141,
    /* map_compressed  */ akira_basic_close_body_map_rle,
    /* vis_x0          */ 10,
    /* vis_x1          */ 22,
    /* vis_y0          */ 6,
    /* vis_y1          */ 26,
    /* render_w_px     */ 113,
    /* render_h_px     */ 160,
    /* tileset         */ &tileset,
    /* thumbnail_tiles */ &bn::sprite_tiles_items::akira_thumb_basic_close,
};

const variant akira_basic_evil = {
    /* body                */ &akira_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_evil,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x02D6,
};

const variant akira_basic_laugh = {
    /* body                */ &akira_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_laugh,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x02D6,
};

const variant akira_basic_ending = {
    /* body                */ &akira_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_ending,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x02D6,
};

const variant akira_basic_annoyed = {
    /* body                */ &akira_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_annoyed,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x02D6,
};

const variant akira_basic_resigned = {
    /* body                */ &akira_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_resigned,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x02D6,
};

const variant akira_basic_smile = {
    /* body                */ &akira_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_smile,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x02D6,
};

const variant akira_basic_kill = {
    /* body                */ &akira_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_kill,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x02D6,
};

const variant akira_basic_boo = {
    /* body                */ &akira_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_boo,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x02D6,
};

const variant akira_basic_lost = {
    /* body                */ &akira_basic_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_lost,
    /* face_offset_x_cells */ 14,
    /* face_offset_y_cells */ 8,
    /* face_size_x_cells   */ 4,
    /* face_size_y_cells   */ 4,
    /* hash                */ 0x02D6,
};

const variant akira_basic_close_laugh = {
    /* body                */ &akira_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_laugh_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xA6F5,
};

const variant akira_basic_close_ending = {
    /* body                */ &akira_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_ending_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xA6F5,
};

const variant akira_basic_close_boo = {
    /* body                */ &akira_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_boo_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xA6F5,
};

const variant akira_basic_close_smile = {
    /* body                */ &akira_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_smile_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xA6F5,
};

const variant akira_basic_close_annoyed = {
    /* body                */ &akira_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_annoyed_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xA6F5,
};

const variant akira_basic_close_lost = {
    /* body                */ &akira_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_lost_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xA6F5,
};

const variant akira_basic_close_resigned = {
    /* body                */ &akira_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_resigned_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xA6F5,
};

const variant akira_basic_close_distant = {
    /* body                */ &akira_basic_close_body,
    /* face_tiles          */ &bn::sprite_tiles_items::akira_spr_basic_distant_close,
    /* face_offset_x_cells */ 11,
    /* face_offset_y_cells */ 6,
    /* face_size_x_cells   */ 8,
    /* face_size_y_cells   */ 8,
    /* hash                */ 0xA6F5,
};

}  // namespace ks::smart_characters::akira
