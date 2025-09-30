import hashlib
import os
import json
import subprocess

from PIL import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode

PINK_COLOR = (255, 0, 255)  # Pink background color

QUALETIZE = "/Users/n.laptev/development/gba/qualetize/release/qualetize"
IMAGEMAGICK = "magick"

# Game Boy Advance (GBA) settings - default
QUALETIZE_COLOURSPACE = "ycbcr-psy"
QUALETIZE_DITHER_METHOD = "floyd"
QUALETIZE_DITHER_LEVEL = 1.0
QUALETIZE_PALETTES_COUNT = 8
QUALETIZE_PALETTE_COLORS = 16
QUALETIZE_BITS_PER_COLOR = 5
QUALETIZE_COLOR_0_IS_CLEAR = True

QUALETIZE_PASSES_COLOUR = (2 ** 10) * QUALETIZE_PALETTES_COUNT
QUALETIZE_PASSES_TILES = (2 ** 10) * QUALETIZE_PALETTES_COUNT

PAGES = [
    [
        "event/other_iwanako",
        "event/hisao_class",
        "event/kenji_rooftop",
        "event/hisao_teacup",
        "event/hisao_letter_closed",
        "event/akira_park",
        "event/emi_knockeddown",
        "event/emi_run_face",
        "event/emitrack_blocks",
        "event/emitrack_running",
        "event/emitrack_finishtop",
        "event/emitrack_finish",
    ],
    [
        "event/picnic_normal",
        "event/emi_sleep_unsure",
        "event/emi_sleepy",
        "event/emi_firstkiss",
        "event/emi_bed_normal",
        "event/emi_forehead",
        # "event/emi_grinding",
        # "event/emi_shed",
        "event/emi_grave",
        "event/emi_cry_down",
        "event/emi_miss_closed",
        "event/emi_ending_smile",
    ],
    [
        "event/hana_library",
        "event/hanako_fw",
        "event/hanako_presents1",
        "event/hanako_crayon1",
        # "event/hanako_breakdown_down",
        "event/hanako_cry_closed",
        "event/hanako_billiards_break",
        "event/hanako_emptyclassroom_bg",
        "event/hanako_rage",
        "event/hisao_scar",
        "event/hanako_scars",
        "event/hanako_bed_boobs_blush",
    ]
]

def create_json_metadata(image_path):
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "regular_bg",
        "bpp_mode": "bpp_4_manual",
        "colors_count": 32,
        "compression": "auto_no_huffman",
    }

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")

def create_pages():
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics"
    input_directory = "/Users/n.laptev/development/ksre-2/game"

    page_num = 0
    for page in PAGES:
        image_files = []
        image_files += [f"{input_directory}/{f}.png" for f in page]
        output_path = f"{output_directory}/ui_bg_menu_extras_gallery_page_{page_num}.bmp"
        xx = 0
        yy = 0

        print(f"Processing page {page_num + 1} with {len(image_files)} images.")
        canvas = Image.new("RGBA", (256, 256), PINK_COLOR)
        for image_file in image_files:
            source_image = Image.open(image_file).convert("RGBA")
            grayscale_image = ImageOps.grayscale(source_image).convert("RGBA")
            grayscale_resized = ImageOps.fit(grayscale_image, (48, 32), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
            canvas.paste(grayscale_resized, (20 + 56 * xx, 73 + 38 * yy))

            xx += 1
            if xx == 4:
                xx = 0
                yy += 1

        converter = Tilequant(
            canvas, PINK_COLOR,
            tile_width=8,
            tile_height=8,
        )
        quantized = converter.convert(num_palettes=2, colors_per_palette=16,
                                      dithering_mode=DitheringMode.FLOYDSTEINBERG, dithering_level=0.5,
                                      num_color_cluster_passes=0, num_tile_cluster_passes=0)
        quantized.save(output_path, format="BMP")
        create_json_metadata(output_path)
        print(f"Resized, quantized and saved: {output_path}")
        page_num += 1


def main():
    create_pages()

if __name__ == "__main__":
    main()
