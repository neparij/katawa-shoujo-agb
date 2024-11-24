/*
 * Copyright (c) 2020-2024 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef VARIABLE_16x16_SPRITE_FONT_H
#define VARIABLE_16x16_SPRITE_FONT_H

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"
#include "bn_sprite_items_variable_16x16_font.h"

constexpr bn::utf8_character variable_16x16_sprite_font_utf8_characters[] = {
    "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿",
    "…", "—",
    "А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П",
    "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я",
    "Ё", "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о",
    "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю",
    "я", "ё"
};

constexpr int8_t variable_16x16_sprite_font_character_widths[] = {
    6,     // Space
    4,    // !
    6,    // "
    8,    // #
    9,    // $
    10,    // %
    10,    // &
    4,    // '
    5,    // (
    5,    // )
    6,    // *
    8,    // +
    4,    // ,
    6,    // -
    4,    // .
    7,    // /
    8,    // 0
    5,    // 1
    8,    // 2
    8,    // 3
    8,    // 4
    8,    // 5
    8,    // 6
    8,    // 7
    8,    // 8
    8,    // 9
    4,    // :
    4,    // ;
    8,    // <
    8,    // =
    8,    // >
    7,    // ?
    10,    // @
    9,    // A
    9,    // B
    9,    // C
    10,    // D
    8,    // E
    7,    // F
    10,    // G
    9,    // H
    5,    // I
    7,    // J
    9,    // K
    7,    // L
    11,    // M
    9,    // N
    10,    // O
    8,    // P
    10,    // Q
    9,    // R
    9,    // S
    7,    // T
    9,    // U
    8,    // V
    11,    // W
    8,    // X
    8,    // Y
    9,    // Z
    5,    // [
    7,    // Backslash
    5,    // ]
    8,    // ^
    6,    // _
    5,    // `
    7,    // a
    7,    // b
    7,    // c
    7,    // d
    7,    // e
    5,    // f
    7,    // g
    7,    // h
    4,    // i
    5,    // j
    7,    // k
    4,    // l
    9,    // m
    7,    // n
    7,    // o
    7,    // p
    7,    // q
    6,    // r
    7,    // s
    6,    // t
    7,    // u
    7,    // v
    8,    // w
    7,    // x
    7,    // y
    6,    // z
    5,    // {
    5,    // |
    5,    // }
    7,    // ~
    9,    // Á
    8,    // É
    5,    // Í
    10,    // Ó
    9,    // Ú
    9,    // Ü
    9,    // Ñ
    7,    // á
    7,    // é
    4,    // í
    7,    // ó
    7,    // ú
    7,    // ü
    7,    // ñ
    4,    // ¡
    7,    // ¿
    10,    // …
    11,    // —
    9,    // А
    9,    // Б
    9,    // В
    7,    // Г
    10,    // Д
    8,    // Е
    13,    // Ж
    8,    // З
    9,    // И
    9,    // Й
    9,    // К
    8,    // Л
    11,    // М
    9,    // Н
    10,    // О
    9,    // П
    8,    // Р
    9,    // С
    7,    // Т
    8,    // У
    12,    // Ф
    8,    // Х
    9,    // Ц
    8,    // Ч
    13,    // Ш
    14,    // Щ
    9,    // Ъ
    10,    // Ы
    8,    // Ь
    8,    // Э
    12,    // Ю
    8,    // Я
    8,    // Ё
    7,    // а
    7,    // б
    7,    // в
    7,    // г
    7,    // д
    7,    // е
    11,    // ж
    7,    // з
    7,    // и
    7,    // й
    7,    // к
    7,    // л
    8,    // м
    8,    // н
    7,    // о
    7,    // п
    7,    // р
    7,    // с
    9,    // т
    7,    // у
    10,    // ф
    7,    // х
    7,    // ц
    7,    // ч
    10,    // ш
    10,    // щ
    8,    // ъ
    9,    // ы
    7,    // ь
    6,    // э
    9,    // ю
    6,    // я
    7,    // ё

};

constexpr bn::span<const bn::utf8_character> variable_16x16_sprite_font_utf8_characters_span(
        variable_16x16_sprite_font_utf8_characters);

constexpr auto variable_16x16_sprite_font_utf8_characters_map =
        bn::utf8_characters_map<variable_16x16_sprite_font_utf8_characters_span>();

constexpr bn::sprite_font variable_16x16_sprite_font(
        bn::sprite_items::variable_16x16_font, variable_16x16_sprite_font_utf8_characters_map.reference(),
        variable_16x16_sprite_font_character_widths);

#endif