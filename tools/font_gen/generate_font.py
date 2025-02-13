from PIL import Image, ImageDraw, ImageFont
import math

# Configuration
# FONT_PATH = "/Library/Fonts/cjkFonts-allseto.ttf"
FONT_PATH = "/Library/Fonts/playtime.ttf"
FONT_SIZE = 9  # Font size for characters
CHAR_WIDTH = 8  # Width of each character
CHAR_HEIGHT = 16  # Height of each character
CHAR_SPACE_WIDTH = 8

FONT_NAME = "variable_" + str(CHAR_WIDTH) + "x" + str(CHAR_HEIGHT) + "_font"
COLUMNS = 1  # Number of characters per row
BACKGROUND_COLOR = (224, 232, 40, 255)
TEXT_COLOR = (32, 112, 48, 255)
OUTLINE_COLOR = (224, 232, 40, 255)

# Cyrillic characters (А-Я, а-я, Ё, ё)
BASIC_LATIN = ''.join(chr(i) for i in range(0x0021, 0x007F))  # ! to ~
# CYRILLIC = (
#     "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"
#     "Ёабвгдежзийклмнопрстуфхцчшщъыьэюяё"
# )
ADDITIONAL = [
    "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿",
    "…", "—", "–", "«", "»",
    "А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П",
    "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я",
    "Ё", "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о",
    "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю",
    "я", "ё"
]
ADDITIONAL = sorted(ADDITIONAL, key=lambda char: ord(char))
# Print the sorted list
print("Sorted ADDITIONAL array by UTF-8 character code:")
formatted_output = ', '.join(f'"{char}"' for char in ADDITIONAL)
print(f"constexpr bn::utf8_character variable_16x16_sprite_font_utf8_characters[] = {{\n    {formatted_output}\n}};")

CHARACTERS = BASIC_LATIN + ''.join(ADDITIONAL)
CHAR_WIDTHS = [str(CHAR_SPACE_WIDTH) + ",     // Space"]

ImageDraw.fontmode = "1"

def draw_text_with_shadow(draw, position, text, font, text_color, outline_color, outline_width=1):

    # Calculate width
    # char_width = font.getlength(text)
    char_bbox = font.getbbox(text)
    char_width = char_bbox[2] - char_bbox[0]

    x, y = position
    # # Draw shadow
    # draw.text((x + 1, y), text, font=font, fill=outline_color, anchor="lm")
    # draw.text((x + 1, y + 1), text, font=font, fill=outline_color, anchor="lm")

    # Draw the main text
    draw.fontmode = "1"
    draw.text((x, y), text, font=font, fill=text_color, anchor="lm")

    if text == "\\":
        text = "Backslash"
    CHAR_WIDTHS.append(str(min(CHAR_WIDTH, math.ceil(char_width) + 1)) + ",    // " + text)

def generate_sprite_sheet():
    # Calculate the size of the sprite sheet
    rows = (len(CHARACTERS) + COLUMNS - 1) // COLUMNS
    sheet_width = COLUMNS * CHAR_WIDTH
    sheet_height = rows * CHAR_HEIGHT

    # Create a blank image for the sprite sheet
    sprite_sheet = Image.new("RGBA", (sheet_width, sheet_height), BACKGROUND_COLOR)
    draw = ImageDraw.Draw(sprite_sheet)
    draw.fontmode = "1"

    # Load the font
    font = ImageFont.truetype(FONT_PATH, FONT_SIZE)

    # Draw each character onto the sprite sheet
    for i, char in enumerate(CHARACTERS):
        x = (i % COLUMNS) * CHAR_WIDTH
        y = (i // COLUMNS) * CHAR_HEIGHT
        # Center the text within the cell
        # text_position = (x + CHAR_WIDTH // 2, y + CHAR_HEIGHT // 2)
        text_position = (x, y + CHAR_HEIGHT // 2)
        draw_text_with_shadow(draw, text_position, char, font, TEXT_COLOR, OUTLINE_COLOR, outline_width=1)

    # Save the sprite sheet
    OUTPUT_PATH = FONT_NAME + ".32.bmp"
    sprite_sheet.save(OUTPUT_PATH)
    print(f"Sprite sheet saved to {OUTPUT_PATH}")

def convert_to_4_bpp():
    img = Image.open(FONT_NAME + ".32.bmp")

    OUTPUT_PATH = FONT_NAME + ".bmp"
    img_8bit = img.convert("P", palette=Image.ADAPTIVE, colors=16)

    palette = img_8bit.getpalette()
    palette_colors = [tuple(palette[i:i + 3]) for i in range(0, len(palette), 3)]

    if BACKGROUND_COLOR[0:3] not in palette_colors:
        print(f"Warning: The first color {BACKGROUND_COLOR} is not in the original palette!")
        return

    first_color_index = palette_colors.index(BACKGROUND_COLOR[0:3])
    remap = list(range(len(palette_colors)))
    if first_color_index != 0:
        remap[0], remap[first_color_index] = remap[first_color_index], remap[0]

    img_remapped = img_8bit.remap_palette(remap)
    img_remapped.save(OUTPUT_PATH)
    print(f"Converted image saved as {OUTPUT_PATH}")

def save_widths_info():
    OUTPUT_PATH = FONT_NAME + ".widths.txt"
    with open(OUTPUT_PATH, "w") as file:
        file.write("\n".join(map(str, CHAR_WIDTHS)) + "\n")
        print(f"Character widths saved to {OUTPUT_PATH}")

if __name__ == "__main__":
    print("Char count: " + str(len(CHARACTERS)))
    generate_sprite_sheet()
    convert_to_4_bpp()
    save_widths_info()

