#ifndef KS_FONTS_LATIN_H
#define KS_FONTS_LATIN_H

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"

constexpr bn::utf8_character latin_utf8_characters[] = {
    "¡", "¿", "É", "Ú", "à", "á", "é", "ê", "í", "ñ", "ó", "ú", "ü", "ō", "—", "“", "”", "…"
};
constexpr bn::span<const bn::utf8_character> latin_utf8_characters_span(latin_utf8_characters);
constexpr auto latin_utf8_characters_map = bn::utf8_characters_map<latin_utf8_characters_span>();

extern const int8_t font_default_latin_character_widths[];
extern const bn::sprite_font font_default_latin_sprite_font;

extern const int8_t font_bold_latin_character_widths[];
extern const bn::sprite_font font_bold_latin_sprite_font;

extern const int8_t font_small_latin_character_widths[];
extern const bn::sprite_font font_small_latin_sprite_font;

#endif // KS_FONTS_LATIN_H
