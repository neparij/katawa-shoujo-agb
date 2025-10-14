#include "fonts/fonts_latin.h"
#include "bn_sprite_items_font_bold_latin.h"

constexpr int8_t font_bold_latin_character_widths[] = {
    4,    //  
    3,    // !
    4,    // "
    7,    // #
    8,    // $
    9,    // %
    9,    // &
    2,    // '
    4,    // (
    4,    // )
    4,    // *
    7,    // +
    3,    // ,
    5,    // -
    3,    // .
    6,    // /
    7,    // 0
    4,    // 1
    7,    // 2
    7,    // 3
    7,    // 4
    7,    // 5
    7,    // 6
    7,    // 7
    8,    // 8
    7,    // 9
    3,    // :
    3,    // ;
    7,    // <
    7,    // =
    7,    // >
    6,    // ?
    10,    // @
    8,    // A
    8,    // B
    8,    // C
    9,    // D
    7,    // E
    6,    // F
    9,    // G
    8,    // H
    3,    // I
    6,    // J
    8,    // K
    6,    // L
    10,    // M
    8,    // N
    9,    // O
    7,    // P
    9,    // Q
    8,    // R
    8,    // S
    6,    // T
    8,    // U
    7,    // V
    10,    // W
    8,    // X
    7,    // Y
    8,    // Z
    4,    // [
    6,    // Backslash
    4,    // ]
    7,    // ^
    5,    // _
    4,    // `
    6,    // a
    6,    // b
    6,    // c
    6,    // d
    6,    // e
    5,    // f
    6,    // g
    6,    // h
    3,    // i
    5,    // j
    6,    // k
    3,    // l
    8,    // m
    6,    // n
    6,    // o
    6,    // p
    6,    // q
    5,    // r
    6,    // s
    5,    // t
    6,    // u
    6,    // v
    8,    // w
    6,    // x
    6,    // y
    5,    // z
    4,    // {
    4,    // |
    4,    // }
    6,    // ~
    6,    // é
    6,    // ê
    10,    // —
    9,    // …
};

constexpr bn::sprite_font font_bold_latin_sprite_font(
    bn::sprite_items::font_bold_latin,
    latin_utf8_characters_map.reference(),
    font_bold_latin_character_widths);

