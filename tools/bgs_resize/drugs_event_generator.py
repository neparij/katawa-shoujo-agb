import hashlib
import math
import os
import json
import random
import subprocess

from PIL import Image, ImageOps, ImageDraw, ImageFont

PINK_COLOR = (255, 0, 255)  # Pink background color
STEPS = 63
COLORS = 64

FONT_PATH = "/Users/n.laptev/development/ksre/game/font/gentium.ttf"

DRUGS_EN = [
    "Disopyramide",
    "Warfarin",
    "Diltiazem",
    "Felodipine",
    "Propanolol",
    "Penbutolol",
    "Carteolol",
    "Procainamide",
    "Heparin",
    "Phenytoin",
    "Verapamil",
    "Quinidine",
    "Flecainide",
    "5mg/day",
    "400mg/day",
    "15ml/day",
    "100mg/day",
    "10ml/48hrs",
    "10ml/day",
    "200mg/12hrs",
    "50mg/12hrs",
    "500mg/48hrs",
    "125mg/12hrs",
    "25ml/day",
    "nightmares",
    "decreased concentration",
    "bradycardia",
    "clinical depression",
    "insomnia",
    "erectile dysfunction",
    "abnormal vision",
    "heart failure",
    "nausea",
    "dizziness",
    "hallucinations",
    "bronchospasm",
    "dyspnea",
    "fatigue",
    "hypotension",
    "heart block",
    "cold extremities",
    "diarrhea",
    "cardiac arrest",
    "ventricular fibrillation",
    "ataxia",
    "asthma"
]

def generate_with_array(drugs: list[str], output_dir: str, output_file_name: str):
    output_path = os.path.join(output_dir, output_file_name)
    image = Image.new("RGB", (512, 512), PINK_COLOR)
    canvas = Image.new("RGB", (480, 160), PINK_COLOR)

    draw = ImageDraw.Draw(canvas)
    draw.fontmode = ImageDraw.fontmode

    wordlist = drugs * 4
    random.shuffle(wordlist)

    for i in range(len(wordlist)):
        step = math.floor(i / len(wordlist) * STEPS)
        brightness = 255 - (255 * step // (STEPS - 1))
        from_x = math.floor(brightness / 255 * 240)
        size = random.randint(11, 25)
        print(f"Drawing {i+1}/{len(wordlist)}: '{wordlist[i]}' with color step {step} of {STEPS}")
        print(f"Brightness: {brightness}")

        font = ImageFont.truetype(FONT_PATH, size)

        draw.text(
            (random.randint(from_x, 480), random.randint(0, 160)),
            wordlist[i],
            font=font,
            fill=(brightness, brightness, brightness),
            anchor="mm"
        )

    # paste to center:
    image.paste(canvas, ((512 - 480) // 2, (512 - 160) // 2))

    palette_image = image.convert("P", palette=Image.Palette.ADAPTIVE, colors=COLORS)
    palette = palette_image.getpalette()

    orig_colors = [tuple(palette[i:i + 3]) for i in range(0, COLORS * 3, 3)]
    new_colors = sorted(orig_colors, key=lambda c: -1 if c == PINK_COLOR else c[0])

    mapping = []
    for c in new_colors:
        mapping.append(orig_colors.index(c))

    img_remapped = palette_image.remap_palette(mapping)

    img_remapped.save(output_path, format="BMP")
    print(f"Resized and saved: {output_path}")
    create_json_metadata(output_path)

def create_json_metadata(image_path):
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "huge_bg",
        "bpp_mode": "bpp_8",
        "colors": COLORS,
        "compression": "auto_no_huffman",
    }

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")

if __name__ == "__main__":
    ImageDraw.fontmode = "1" # Don't use antialiasing for better look (yes, as it would be re-paletted by GBA runtime)
    assert STEPS < COLORS
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics/huge"

    generate_with_array(DRUGS_EN, output_directory, "event_drugs_en.bmp")
