import json
import os.path
from typing import List

from PIL import Image, ImageDraw, ImageFont
from PIL.Image import Resampling

from src.font.font_data import FontData, create_font_group
from src.font.text_palette_data import TextPaletteData

PALETTE_BACKGROUND_COLOR = [0, 255, 0]
ENABLE_ANTIALIASING = True
FONT_DEFAULT_PALETTE = "main"
FONT_PALETTES = [
    TextPaletteData(FONT_DEFAULT_PALETTE, (255, 255, 255, 255), (16, 16, 16, 255)),
    TextPaletteData("beige", (148, 132, 123, 255), (255, 254, 206, 255)),
    TextPaletteData("beige_selected", (0, 0, 0, 255), (255, 254, 206, 255)),
    TextPaletteData("beige_disabled", (211, 197, 170, 255), (255, 254, 206, 255)),

    TextPaletteData("alive", (102, 102, 102, 255), (16, 16, 16, 255)),
    TextPaletteData("red", (255, 0, 0, 255), (16, 16, 16, 255)),
    # TextPaletteData("FF2AAA", (255, 42, 170, 255), (16, 16, 16, 255)),

    TextPaletteData("hi", (98, 146, 118, 255), (16, 16, 16, 255)),
    TextPaletteData("ha", (137, 124, 191, 255), (16, 16, 16, 255)),
    TextPaletteData("emi", (255, 141, 124, 255), (16, 16, 16, 255)),
    TextPaletteData("rin", (177, 67, 67, 255), (16, 16, 16, 255)),
    TextPaletteData("li", (249, 234, 160, 255), (16, 16, 16, 255)),
    TextPaletteData("shi", (114, 173, 238, 255), (16, 16, 16, 255)),
    TextPaletteData("mi", (255, 128, 159, 255), (16, 16, 16, 255)),
    TextPaletteData("ke", (204, 124, 42, 255), (16, 16, 16, 255)),
    TextPaletteData("mu", (255, 255, 255, 255), (16, 16, 16, 255)),
    TextPaletteData("nk", (255, 255, 255, 255), (16, 16, 16, 255)),
    TextPaletteData("no", (224, 224, 224, 255), (16, 16, 16, 255)),
    TextPaletteData("yu", (44, 158, 49, 255), (16, 16, 16, 255)),
    TextPaletteData("sa", (212, 212, 255, 255), (16, 16, 16, 255)),
    TextPaletteData("aki", (235, 36, 59, 255), (16, 16, 16, 255)),
    TextPaletteData("hh", (98, 153, 255, 255), (16, 16, 16, 255)),
    TextPaletteData("hx", (153, 170, 204, 255), (16, 16, 16, 255)),
    TextPaletteData("emm", (153, 80, 80, 255), (16, 16, 16, 255)),
    TextPaletteData("sk", (113, 135, 168, 255), (16, 16, 16, 255)),
    TextPaletteData("mk", (173, 115, 94, 255), (16, 16, 16, 255)),

    TextPaletteData("opening_0", (255, 255, 255, 255), (8, 23, 8, 255)),
    TextPaletteData("opening_1", (255, 255, 255, 255), (82, 90, 90, 255)),
]

class FontsWriter:
    def __init__(self, source: str, outdir: str, group: str, common_characters: List[str],
                 additional_characters: List[str]):
        self.source = source
        self.outdir = outdir
        self.group = group
        self.common_characters = common_characters
        self.additional_characters = additional_characters

    def generate_json_metadata(self, filename, char_height: int):
        with open(f'{filename.removesuffix(".bmp")}.json', "w") as file:
            metadata = {
                "type": "sprite",
                "height": char_height,
                "bpp_mode": "bpp_4",
                "colors_count": 16,
                "compression": "none",
            }
            file.write(json.dumps(metadata, indent=4))

    def generate_palettes(self):
        for bold in [False, True]:
            for palette_data in FONT_PALETTES:
                p = palette_data.get_palette(bold=bold)
                palette_colors = [tuple(p[i:i + 3]) for i in range(0, len(p), 3)]
                first_color_index = palette_colors.index(palette_data.background_color[0:3])
                if first_color_index != 0:
                    raise f"Background color {palette_data.background_color} is not in the original palette at index 0!"
                p[0:3] = PALETTE_BACKGROUND_COLOR

                img = Image.new("P", (16, 16), palette_colors[0])
                img.putpalette(p)

                # Fills pixels with all palette colors
                for i, color in enumerate(palette_colors):
                    x = i % 16
                    y = i // 16
                    img.putpixel((x, y), i)

                palette_filename = os.path.join(self.outdir, "graphics", "fonts",
                                                f"{palette_data.get_name()}{"_bold" if bold else ""}.bmp")
                img.save(palette_filename)
                print(f"Palette sample saved as {palette_filename}")
                self.generate_json_metadata(palette_filename, 16)

    def generate_fonts(self):
        char_size = (16, 16)

        font_path = os.path.join(self.source, "game", "font", "playtime.ttf")
        cjk_font_path = os.path.join(self.source, "game", "font", "VL-PGothic-Regular.ttf")
        fonts = create_font_group(
            default_font_path=font_path,
            cjk_font_path=cjk_font_path,
            char_size=char_size,
            main_size=13,
            small_size=11
        )

        for font in fonts:
            self._generate_spritesheet(font)
            self._generate_font_impl(font)
        self._generate_fonts_info(fonts)

    def _generate_spritesheet(self, font_data):
        sheet_width = font_data.char_size[0]
        paldata = FONT_PALETTES[0]
        sheet_height = (len(self.common_characters) + len(self.additional_characters)) * font_data.char_size[1]
        sprite_sheet_multiplied = Image.new("RGB", (sheet_width * 10, sheet_height * 10), paldata.background_color)

        draw = ImageDraw.Draw(sprite_sheet_multiplied)
        draw.fontmode = "L" if ENABLE_ANTIALIASING else "1"
        font = font_data.get_font()
        cjk_font = font_data.get_cjk_font()

        for i, char in enumerate(self.common_characters[1:] + self.additional_characters):
            x = 0
            y = i * font_data.char_size[1] * 10
            text_position = (x, y + (font_data.char_size[1] // 2) * 10)
            if ord(char) >= 0x2E80:
                draw.text(text_position, char, font=cjk_font, fill=paldata.text_color, anchor="lm", stroke_width=int(font_data.stroke_width * 10), stroke_fill=paldata.text_color)
            else:
                draw.text(text_position, char, font=font, fill=paldata.text_color, anchor="lm", stroke_width=int(font_data.stroke_width * 10), stroke_fill=paldata.text_color)

        font_filename = os.path.join(self.outdir, "graphics", "fonts", f"{font_data.get_name()}_{self.group}.bmp")

        sprite_sheet_divided = sprite_sheet_multiplied.resize((sheet_width, sheet_height), resample=Resampling.LANCZOS)

        sample_palette = Image.new("P", (1, 1), paldata.background_color)
        sample_palette.putpalette(paldata.get_palette())
        sprite_sheet_paletted = sprite_sheet_divided.quantize(colors=16, method=Image.Quantize.MEDIANCUT,
                                                              dither=Image.Dither.RASTERIZE, palette=sample_palette)

        p = sprite_sheet_paletted.getpalette()
        palette_colors = [tuple(p[i:i + 3]) for i in range(0, len(p), 3)]
        first_color_index = palette_colors.index(paldata.background_color[0:3])
        if first_color_index != 0:
            raise f"Background color {paldata.background_color} is not in the original palette at index 0!"
        sprite_sheet_paletted.putpalette(PALETTE_BACKGROUND_COLOR + sprite_sheet_paletted.getpalette()[3:])

        sprite_sheet_paletted.save(font_filename)
        print(f"Sprite sheet saved to {font_filename}")
        self.generate_json_metadata(font_filename, font_data.char_size[1])
        pass


    def _generate_fonts_info(self, fonts: List[FontData]):
        header_filename = os.path.join(self.outdir, "include", "fonts", f"fonts_{self.group}.h")
        with open(header_filename, "w") as header_file:
            header_file.write(f"#ifndef KS_FONTS_{self.group.upper()}_H\n")
            header_file.write(f"#define KS_FONTS_{self.group.upper()}_H\n\n")

            header_file.write(f'#include "bn_sprite_font.h"\n')
            header_file.write(f'#include "bn_utf8_characters_map.h"\n\n')

            header_file.write(f'constexpr bn::utf8_character {self.group}_utf8_characters[] = {{\n')
            header_file.write(f'    {", ".join([f"\"{c}\"" for c in self.additional_characters])}\n')
            header_file.write(f'}};\n')
            header_file.write(f'constexpr bn::span<const bn::utf8_character> {self.group}_utf8_characters_span({self.group}_utf8_characters);\n')
            header_file.write(f'constexpr auto {self.group}_utf8_characters_map = bn::utf8_characters_map<{self.group}_utf8_characters_span>();\n\n')

            for font_data in fonts:
                font_name = f"{font_data.get_name()}_{self.group}"
                header_file.write(f"extern const int8_t {font_name}_character_widths[];\n")
                header_file.write(f"extern const bn::sprite_font {font_name}_sprite_font;\n\n")

            header_file.write(f"#endif // KS_FONTS_{self.group.upper()}_H\n")

    def _generate_font_impl(self, font_data):
        font = font_data.get_font()
        cjk_font = font_data.get_cjk_font()
        font_name = f"{font_data.get_name()}_{self.group}"
        impl_filename = os.path.join(self.outdir, "src", "fonts", f"{font_name}.cpp")
        with open(impl_filename, "w") as impl_file:
            impl_file.write(f'#include "fonts/fonts_{self.group}.h"\n')
            impl_file.write(f'#include "bn_sprite_items_{font_name}.h"\n\n')

            impl_file.write(f'constexpr int8_t {font_name}_character_widths[] = {{\n')
            for i, char in enumerate(self.common_characters + self.additional_characters):
                if ord(char) >= 0x2E80:
                    char_bbox = cjk_font.getbbox(char)
                else:
                    char_bbox = font.getbbox(char)
                char_width = char_bbox[2] - char_bbox[0]
                if char == "\\":
                    char = "Backslash"
                impl_file.write(f"    {min(font_data.char_size[0], round(char_width / 10) + 0)},    // {char} ({ord(char[0])})\n")
            impl_file.write(f'}};\n\n')

            impl_file.write(f'constexpr bn::sprite_font {font_name}_sprite_font(\n')
            impl_file.write(f'    bn::sprite_items::{font_name},\n')
            impl_file.write(f'    {self.group}_utf8_characters_map.reference(),\n')
            impl_file.write(f'    {font_name}_character_widths);\n\n')
