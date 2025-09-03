import hashlib
import math
import os
import json
import random
import subprocess
from typing import List

from PIL import Image, ImageOps, ImageDraw, ImageFont
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode

PINK_COLOR = (255, 0, 255)  # Pink background color

class TilePack:
    def __init__(self, path, amount, width: int = 8, height: int = 8):
        self.width = width
        self.height = height
        self.path = path
        self.amount = amount

SNOW_FG : List[TilePack] = [
    TilePack("tiles/snow_bg_0.bmp", 64),
    TilePack("tiles/snow_bg_1.bmp", 64),
    TilePack("tiles/snow_fg_0.bmp", 64),
    TilePack("tiles/snow_fg_1.bmp", 16),
]

SNOW_BG : List[TilePack] = [
    TilePack("tiles/snow_bg_0.bmp", 64),
    TilePack("tiles/snow_bg_1.bmp", 64),
    TilePack("tiles/snow_bg_2.bmp", 64),
    TilePack("tiles/snow_bg_3.bmp", 8),
]

def generate_with_array(tile_packs: List[TilePack], size: tuple[int, int], output_dir: str, output_file_name: str):
    check_palette = None
    for tile_pack in tile_packs:
        if not os.path.exists(tile_pack.path):
            raise FileNotFoundError(f"Tile pack not found: {tile_pack.path}")
        tile_image = Image.open(tile_pack.path)
        # All tiles (Image from tile_packs[i].path) should contain the same palette:
        palette = tile_image.getpalette()
        if check_palette is None:
            check_palette = palette
        elif check_palette != palette:
            raise ValueError(f"Tile pack {tile_pack.path} has a different palette")

    image = Image.new("P", size, check_palette[:3])
    image.putpalette(check_palette)

    for tile_pack in tile_packs:
        tile = Image.open(tile_pack.path)

        for _ in range(tile_pack.amount):
            max_x = image.width - tile_pack.width
            max_y = image.height - tile_pack.height
            x = random.randint(0, max_x // tile_pack.width) * tile_pack.width
            y = random.randint(0, max_y // tile_pack.height) * tile_pack.height
            image.paste(tile, (x, y))

    output_path = os.path.join(output_dir, output_file_name)
    image.save(output_path, format="BMP")
    print(f"Generated and saved: {output_path}")

    create_json_metadata(output_path, size)

def create_json_metadata(image_path, size: tuple[int, int]):
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "regular_bg",
        "bpp_mode": "bpp_4_manual",
        "compression": "auto_no_huffman",
    }

    if size[0] > 256 or size[1] > 256:
        metadata["big"] = True
        metadata["map_compression"] = "none"

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")

if __name__ == "__main__":
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics/vfx"

    generate_with_array(SNOW_FG, (512, 512), output_directory, "snow_layer_0.bmp")
    generate_with_array(SNOW_BG, (256, 256), output_directory, "snow_layer_1.bmp")
    # output_meta_path = os.path.join(output_directory, "thumbs", f"thumb_event_drugs.bmp")
    # create_thumbnail("./event_drugs.bmp", output_meta_path)
    # create_thumbnail_json_metadata(output_meta_path)
