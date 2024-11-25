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
    "¡", "«", "»", "¿", "Á", "É", "Í", "Ñ", "Ó", "Ú", "Ü", "á", "é", "í", "ñ", "ó", "ú", "ü", "Ё", "А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я", "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я", "ё", "–", "—", "…"
};

constexpr int8_t variable_16x16_sprite_font_character_widths[] = {
    6,     // Space
    4,    // !
    5,    // "
    8,    // #
    8,    // $
    10,    // %
    10,    // &
    3,    // '
    5,    // (
    5,    // )
    5,    // *
    8,    // +
    4,    // ,
    6,    // -
    4,    // .
    7,    // /
    8,    // 0
    5,    // 1
    8,    // 2
    8,    // 3
    9,    // 4
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
    8,    // ?
    11,    // @
    9,    // A
    8,    // B
    9,    // C
    9,    // D
    7,    // E
    7,    // F
    9,    // G
    9,    // H
    4,    // I
    6,    // J
    8,    // K
    6,    // L
    11,    // M
    8,    // N
    9,    // O
    8,    // P
    10,    // Q
    8,    // R
    8,    // S
    8,    // T
    8,    // U
    8,    // V
    11,    // W
    10,    // X
    8,    // Y
    8,    // Z
    5,    // [
    7,    // Backslash
    5,    // ]
    8,    // ^
    7,    // _
    4,    // `
    6,    // a
    7,    // b
    6,    // c
    7,    // d
    7,    // e
    6,    // f
    7,    // g
    6,    // h
    3,    // i
    6,    // j
    7,    // k
    3,    // l
    9,    // m
    6,    // n
    7,    // o
    7,    // p
    7,    // q
    6,    // r
    6,    // s
    7,    // t
    6,    // u
    6,    // v
    8,    // w
    6,    // x
    7,    // y
    6,    // z
    5,    // {
    5,    // |
    5,    // }
    6,    // ~
    4,    // ¡
    6,    // «
    6,    // »
    7,    // ¿
    9,    // Á
    7,    // É
    4,    // Í
    9,    // Ñ
    9,    // Ó
    8,    // Ú
    8,    // Ü
    7,    // á
    7,    // é
    4,    // í
    6,    // ñ
    7,    // ó
    6,    // ú
    6,    // ü
    7,    // Ё
    9,    // А
    8,    // Б
    8,    // В
    7,    // Г
    9,    // Д
    7,    // Е
    13,    // Ж
    8,    // З
    8,    // И
    8,    // Й
    8,    // К
    8,    // Л
    11,    // М
    9,    // Н
    9,    // О
    8,    // П
    8,    // Р
    9,    // С
    8,    // Т
    8,    // У
    12,    // Ф
    10,    // Х
    9,    // Ц
    8,    // Ч
    12,    // Ш
    13,    // Щ
    10,    // Ъ
    10,    // Ы
    8,    // Ь
    8,    // Э
    12,    // Ю
    8,    // Я
    6,    // а
    6,    // б
    6,    // в
    6,    // г
    7,    // д
    7,    // е
    10,    // ж
    7,    // з
    6,    // и
    6,    // й
    7,    // к
    6,    // л
    8,    // м
    7,    // н
    7,    // о
    6,    // п
    7,    // р
    6,    // с
    9,    // т
    7,    // у
    10,    // ф
    6,    // х
    7,    // ц
    6,    // ч
    9,    // ш
    10,    // щ
    8,    // ъ
    8,    // ы
    7,    // ь
    6,    // э
    9,    // ю
    6,    // я
    7,    // ё
    9,    // –
    10,    // —
    9,    // …

};

constexpr bn::span<const bn::utf8_character> variable_16x16_sprite_font_utf8_characters_span(
        variable_16x16_sprite_font_utf8_characters);

constexpr auto variable_16x16_sprite_font_utf8_characters_map =
        bn::utf8_characters_map<variable_16x16_sprite_font_utf8_characters_span>();

constexpr bn::sprite_font variable_16x16_sprite_font(
        bn::sprite_items::variable_16x16_font, variable_16x16_sprite_font_utf8_characters_map.reference(),
        variable_16x16_sprite_font_character_widths);

#endif
