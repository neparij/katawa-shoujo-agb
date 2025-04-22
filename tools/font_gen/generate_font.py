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

            # lerp_factor = i / (COLORS_COUNT - 1)
            lerp_factor = (i / (COLORS_COUNT - 1)) + alpha_threshold - (i / (COLORS_COUNT - 1)) * alpha_threshold
            print(f"Color {i} lerp factor: {lerp_factor}")

            r = int(self.background_color[0] + (self.text_color[0] - self.background_color[0]) * lerp_factor)
            g = int(self.background_color[1] + (self.text_color[1] - self.background_color[1]) * lerp_factor)
            b = int(self.background_color[2] + (self.text_color[2] - self.background_color[2]) * lerp_factor)
            colors.extend([r, g, b])
        return colors


# Configuration
FONT_PATH = "/Library/Fonts/playtime.ttf"
FONT_SIZE = 12
CHAR_WIDTH = 16
CHAR_HEIGHT = 16
CHAR_SPACE_WIDTH = 6

FONT_DEFAULT_PALETTE = "main"
COLUMNS = 1

# define hi  = Character(_("Hisao"),    who_color="#629276") -> TextPaletteData("hi", (98, 146, 118, 255), (16, 16, 16, 255)),
# define ha  = Character(_("Hanako"),   who_color="#897CBF") -> TextPaletteData("ha", (137, 124, 191, 255), (16, 16, 16, 255)),
# define emi = Character(_("Emi"),      who_color="#FF8D7C") -> TextPaletteData("emi", (255, 141, 124, 255), (16, 16, 16, 255)),
# define rin = Character(_("Rin"),      who_color="#b14343") -> TextPaletteData("rin", (177, 67, 67, 255), (16, 16, 16, 255)),
# define li  = Character(_("Lilly"),    who_color="#F9EAA0") -> TextPaletteData("li", (249, 234, 160, 255), (16, 16, 16, 255)),
# define shi = Character(_("Shizune"),  who_color="#72ADEE") -> TextPaletteData("shi", (114, 173, 238, 255), (16, 16, 16, 255)),
# define mi  = Character(_("Misha"),    who_color="#FF809F") -> TextPaletteData("mi", (255, 128, 159, 255), (16, 16, 16, 255)),
# define ke  = Character(_("Kenji"),    who_color="#CC7C2A") -> TextPaletteData("ke", (204, 124, 42, 255), (16, 16, 16, 255)),
# define mu  = Character(_("Mutou"),    who_color="#FFFFFF") -> TextPaletteData("mu", (255, 255, 255, 255), (16, 16, 16, 255)),
# define nk  = Character(_("Nurse"),    who_color="#FFFFFF") -> TextPaletteData("nk", (255, 255, 255, 255), (16, 16, 16, 255)),
# define no  = Character(_("Nomiya"),   who_color="#E0E0E0") -> TextPaletteData("no", (224, 224, 224, 255), (16, 16, 16, 255)),
# define yu  = Character(_("Yuuko"),    who_color="#2c9e31") -> TextPaletteData("yu", (44, 158, 49, 255), (16, 16, 16, 255)),
# define sa  = Character(_("Sae"),      who_color="#D4D4FF") -> TextPaletteData("sa", (212, 212, 255, 255), (16, 16, 16, 255)),
# define aki = Character(_("Akira"),    who_color="#eb243b") -> TextPaletteData("aki", (235, 36, 59, 255), (16, 16, 16, 255)),
# define hh  = Character(_("Hideaki"),  who_color="#6299FF") -> TextPaletteData("hh", (98, 153, 255, 255), (16, 16, 16, 255)),
# define hx  = Character(_("Jigoro"),   who_color="#99AACC") -> TextPaletteData("hx", (153, 170, 204, 255), (16, 16, 16, 255)),
# define emm = Character(_("Meiko"),    who_color="#995050") -> TextPaletteData("emm", (153, 80, 80, 255), (16, 16, 16, 255)),
# define sk  = Character(_("Shopkeep"), who_color="#7187A8") -> TextPaletteData("sk", (113, 135, 168, 255), (16, 16, 16, 255)),
# define mk  = Character(_("Miki"),     who_color="#AD735E") -> TextPaletteData("mk", (173, 115, 94, 255), (16, 16, 16, 255)),

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
CHAR_WIDTHS = [str(CHAR_SPACE_WIDTH) + ",     // Space"]

if ENABLE_ANTIALIASING:
    ImageDraw.fontmode = "L"
else:
    ImageDraw.fontmode = "1"


def get_font_name(palette_name: str) -> str:
    return f'variable_{CHAR_WIDTH}x{CHAR_HEIGHT}_font{f"_{palette_name}" if palette_name != FONT_DEFAULT_PALETTE else ""}'


def draw_text(draw, position, text, font, text_color):
    char_bbox = font.getbbox(text)
    char_width = char_bbox[2] - char_bbox[0]
    draw.fontmode = ImageDraw.fontmode
    draw.text(position, text, font=font, fill=text_color, anchor="lm")

    if text == "\\":
        text = "Backslash"
    CHAR_WIDTHS.append(str(min(CHAR_WIDTH, math.ceil(char_width) + 1)) + ",    // " + text)


def generate_sprite_sheet(paldata: TextPaletteData):
    # Calculate the size of the sprite sheet
    rows = (len(CHARACTERS) + COLUMNS - 1) // COLUMNS
    sheet_width = COLUMNS * CHAR_WIDTH
    sheet_height = rows * CHAR_HEIGHT

    # sprite_sheet = Image.new("RGBA", (sheet_width, sheet_height), paldata.background_color)
    sprite_sheet = Image.new("P", (sheet_width, sheet_height), paldata.background_color)
    sprite_sheet.putpalette(paldata.get_palette())

    draw = ImageDraw.Draw(sprite_sheet)
    draw.fontmode = ImageDraw.fontmode
    font = ImageFont.truetype(FONT_PATH, FONT_SIZE)

    for i, char in enumerate(CHARACTERS):
        x = (i % COLUMNS) * CHAR_WIDTH
        y = (i // COLUMNS) * CHAR_HEIGHT
        text_position = (x, y + CHAR_HEIGHT // 2)
        draw_text(draw, text_position, char, font, paldata.text_color)

    p = sprite_sheet.getpalette()
    palette_colors = [tuple(p[i:i + 3]) for i in range(0, len(p), 3)]
    first_color_index = palette_colors.index(paldata.background_color[0:3])
    if first_color_index != 0:
        raise f"Background color {paldata.background_color} is not in the original palette at index 0!"
    sprite_sheet.putpalette(PALETTE_BACKGROUND_COLOR + sprite_sheet.getpalette()[3:])

    filename = get_font_name(palette.name) + ".bmp"
    sprite_sheet.save(filename)
    generate_palettes_sample(paldata)
    print(f"Sprite sheet saved to {filename}")


# Creates 16x16 sprite with palette colors
def generate_palettes_sample(paldata: TextPaletteData):
    p = paldata.get_palette()
    palette_colors = [tuple(p[i:i + 3]) for i in range(0, len(p), 3)]
    first_color_index = palette_colors.index(paldata.background_color[0:3])
    if first_color_index != 0:
        raise f"Background color {paldata.background_color} is not in the original palette at index 0!"
    p[0:3] = PALETTE_BACKGROUND_COLOR

    img = Image.new("P", (CHAR_WIDTH, CHAR_HEIGHT), palette_colors[0])
    img.putpalette(p)

    # Fills pixels with all palette colors
    for i, color in enumerate(palette_colors):
        print(f"Color {i}: {color}")
        x = i % 16
        y = i // 16
        img.putpixel((x, y), i)

    img.save(get_font_name(paldata.name) + "_pal.bmp")
    print(f"Palette sample saved as {get_font_name(paldata.name) + '_pal.bmp'}")

def save_widths_info(paldata: TextPaletteData):
    filename = get_font_name(paldata.name) + ".widths.txt"
    with open(filename, "w") as file:
        file.write("\n".join(map(str, CHAR_WIDTHS)) + "\n")
        print(f"Character widths saved to {filename}")


if __name__ == "__main__":
    print("Char count: " + str(len(CHARACTERS)))
    for palette in FONT_PALETTES:
        generate_sprite_sheet(palette)
        save_widths_info(palette)
