import json

from PIL import Image, ImageDraw, ImageFont
import math

from PIL.ImageFile import ImageFile


class TextPaletteData:
    def __init__(self, name: str, text_color: tuple, background_color: tuple):
        self.name = name
        self.text_color = text_color
        self.background_color = background_color

    # Generates palette data (each color is 3 elements), first (1) is background color, last (16) is text color. It should be lerp'ed values
    def get_palette(self) -> [int]:
        colors = []
        alpha_threshold = 0.1

        for i in range(COLORS_COUNT):
            if i == 0:
                r = int(self.background_color[0])
                g = int(self.background_color[1])
                b = int(self.background_color[2])
                colors.extend([r, g, b])
                continue

            lerp_factor = (i / (COLORS_COUNT - 1)) + alpha_threshold - (i / (COLORS_COUNT - 1)) * alpha_threshold

            r = int(self.background_color[0] + (self.text_color[0] - self.background_color[0]) * lerp_factor)
            g = int(self.background_color[1] + (self.text_color[1] - self.background_color[1]) * lerp_factor)
            b = int(self.background_color[2] + (self.text_color[2] - self.background_color[2]) * lerp_factor)
            colors.extend([r, g, b])
        return colors

class FontData:
    def __init__(self, name: str, font_path: str, char_size: tuple[int, int], font_size: int, stroke_width: float = 0):
        self.name = name
        self.font_path = font_path
        self.char_size = char_size
        self.font_size = font_size
        self.stroke_width = stroke_width

    def get_font(self):
        return ImageFont.truetype(self.font_path, self.font_size)

# Configuration
FONT_PATH = "/Users/n.laptev/development/ksre/game/font/playtime.ttf"

FONT_DEFAULT_PALETTE = "main"
COLUMNS = 1

FONT_PALETTES = [
    TextPaletteData(FONT_DEFAULT_PALETTE, (255, 255, 255, 255), (16, 16, 16, 255)),
    TextPaletteData("beige", (148, 132, 123, 255), (255, 254, 206, 255)),
    TextPaletteData("beige_selected", (0, 0, 0, 255), (255, 254, 206, 255)),

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
]

FONTS = [
    FontData("playtime", FONT_PATH, (16, 16), 12),
    FontData("playtime_bold", FONT_PATH, (16, 16), 12, 0.2),
    # FontData("playtime_small_bold", FONT_PATH, (8, 16), 8, 0.15),
]

PALETTE_BACKGROUND_COLOR = [0, 255, 0]
ENABLE_ANTIALIASING = True
COLORS_COUNT = 16

BASIC_LATIN = ''.join(chr(i) for i in range(0x0021, 0x007F))  # ! to ~
ADDITIONAL = [
    "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿",
    "…", "—", "–", "«", "»",
    "А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П",
    "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я",
    "Ё", "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о",
    "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю",
    "я", "ё"
    # "Ⓐ", "Ⓑ", "Ⓛ", "Ⓡ"
]
ADDITIONAL = sorted(ADDITIONAL, key=lambda char: ord(char))
# Print the sorted list
print("Sorted ADDITIONAL array by UTF-8 character code:")
formatted_output = ', '.join(f'"{char}"' for char in ADDITIONAL)
print(f"constexpr bn::utf8_character variable_16x16_sprite_font_utf8_characters[] = {{\n    {formatted_output}\n}};")

CHARACTERS = BASIC_LATIN + ''.join(ADDITIONAL)

if ENABLE_ANTIALIASING:
    ImageDraw.fontmode = "L"
else:
    ImageDraw.fontmode = "1"


def get_font_name(paldata: TextPaletteData, font_data: FontData) -> str:
    return f'font_{font_data.name}{f"_{paldata.name}" if paldata.name != FONT_DEFAULT_PALETTE else ""}'

def get_palette_name(paldata: TextPaletteData) -> str:
    return f'fontpalette_{paldata.name}'

def draw_text(draw, position, text, font, paldata: TextPaletteData, font_data: FontData):
    char_bbox = font.getbbox(text)
    # char_width = char_bbox[2] - char_bbox[0] + font_data.stroke_width
    char_width = char_bbox[2] - char_bbox[0]
    draw.fontmode = ImageDraw.fontmode
    draw.text(position, text, font=font, fill=paldata.text_color, anchor="lm", stroke_width=font_data.stroke_width, stroke_fill=paldata.text_color)

    if text == "\\":
        text = "Backslash"
    CHAR_WIDTHS.append(str(min(font_data.char_size[0], math.ceil(char_width) + 1)) + ",    // " + text)


def generate_sprite_sheet(paldata: TextPaletteData, font_data: FontData):
    # Calculate the size of the sprite sheet
    rows = (len(CHARACTERS) + COLUMNS - 1) // COLUMNS
    sheet_width = COLUMNS * font_data.char_size[0]
    sheet_height = rows * font_data.char_size[1]

    # sprite_sheet = Image.new("RGBA", (sheet_width, sheet_height), paldata.background_color)
    sprite_sheet = Image.new("P", (sheet_width, sheet_height), paldata.background_color)
    sprite_sheet.putpalette(paldata.get_palette())

    draw = ImageDraw.Draw(sprite_sheet)
    draw.fontmode = ImageDraw.fontmode
    font = font_data.get_font()

    for i, char in enumerate(CHARACTERS):
        x = (i % COLUMNS) * font_data.char_size[0]
        y = (i // COLUMNS) * font_data.char_size[1]
        text_position = (x, y + font_data.char_size[1] // 2)
        draw_text(draw, text_position, char, font, paldata, font_data)

    p = sprite_sheet.getpalette()
    palette_colors = [tuple(p[i:i + 3]) for i in range(0, len(p), 3)]
    first_color_index = palette_colors.index(paldata.background_color[0:3])
    if first_color_index != 0:
        raise f"Background color {paldata.background_color} is not in the original palette at index 0!"
    sprite_sheet.putpalette(PALETTE_BACKGROUND_COLOR + sprite_sheet.getpalette()[3:])

    filename = get_font_name(paldata, font_data) + ".bmp"
    sprite_sheet.save(filename)
    print(f"Sprite sheet saved to {filename}")
    generate_json_metadata(filename, font_data.char_size[1])


# Creates 16x16 sprite with palette colors
def generate_palettes_sample(paldata: TextPaletteData):
    p = paldata.get_palette()
    palette_colors = [tuple(p[i:i + 3]) for i in range(0, len(p), 3)]
    first_color_index = palette_colors.index(paldata.background_color[0:3])
    if first_color_index != 0:
        raise f"Background color {paldata.background_color} is not in the original palette at index 0!"
    p[0:3] = PALETTE_BACKGROUND_COLOR

    img = Image.new("P", (16, 16), palette_colors[0])
    img.putpalette(p)

    # Fills pixels with all palette colors
    for i, color in enumerate(palette_colors):
        x = i % 16
        y = i // 16
        img.putpixel((x, y), i)

    palette_filename = f'{get_palette_name(paldata)}.bmp'
    img.save(palette_filename)
    print(f"Palette sample saved as {palette_filename}")
    generate_json_metadata(palette_filename, 16)

def generate_json_metadata(filename, char_height: int):
    with open(f'{filename.removesuffix(".bmp")}.json', "w") as file:
        metadata = {
            "type": "sprite",
            "height": char_height,
            "bpp_mode": "bpp_4",
            "colors_count": 16,
            "compression": "none",
        }
        file.write(json.dumps(metadata, indent=4))

def save_widths_info(paldata: TextPaletteData, font_data: FontData):
    filename = get_font_name(paldata, font_data) + ".widths.txt"
    with open(filename, "w") as file:
        file.write("\n".join(map(str, CHAR_WIDTHS)) + "\n")
        print(f"Character widths saved to {filename}")


if __name__ == "__main__":
    print("Char count: " + str(len(CHARACTERS)))
    for font in FONTS:
        CHAR_WIDTHS = [str(font.font_size // 2) + ",     // Space"]
        generate_sprite_sheet(FONT_PALETTES[0], font)
        save_widths_info(FONT_PALETTES[0], font)
    for palette in FONT_PALETTES:
        generate_palettes_sample(palette)