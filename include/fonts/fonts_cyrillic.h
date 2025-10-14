#ifndef KS_FONTS_CYRILLIC_H
#define KS_FONTS_CYRILLIC_H

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"

constexpr bn::utf8_character cyrillic_utf8_characters[] = {
    "«", "»", "А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Ы", "Э", "Ю", "Я", "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я", "ё", "–", "—", "…"
};
constexpr bn::span<const bn::utf8_character> cyrillic_utf8_characters_span(cyrillic_utf8_characters);
constexpr auto cyrillic_utf8_characters_map = bn::utf8_characters_map<cyrillic_utf8_characters_span>();

extern const int8_t font_default_cyrillic_character_widths[];
extern const bn::sprite_font font_default_cyrillic_sprite_font;

extern const int8_t font_bold_cyrillic_character_widths[];
extern const bn::sprite_font font_bold_cyrillic_sprite_font;

extern const int8_t font_small_cyrillic_character_widths[];
extern const bn::sprite_font font_small_cyrillic_sprite_font;

#endif // KS_FONTS_CYRILLIC_H
