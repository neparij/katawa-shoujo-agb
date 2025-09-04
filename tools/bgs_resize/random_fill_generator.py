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

SAKURA_LAYER_0 : List[TilePack] = [
    TilePack("tiles/sakura_0.bmp", 48),
    TilePack("tiles/sakura_1.bmp", 32),
]

SAKURA_LAYER_1 : List[TilePack] = [
    TilePack("tiles/sakura_0.bmp", 16),
    TilePack("tiles/sakura_1.bmp", 24),
]

def shared_palette(tile_packs: List[TilePack]) -> list[int] | None:
    shared_pal = None
    for tile_pack in tile_packs:
        if not os.path.exists(tile_pack.path):
            raise FileNotFoundError(f"Tile pack not found: {tile_pack.path}")
        tile_image = Image.open(tile_pack.path)
        # All tiles (Image from tile_packs[i].path) should contain the same palette:
        palette = tile_image.getpalette()
        if shared_pal is None:
            shared_pal = palette
        elif shared_pal != palette:
            raise ValueError(f"Tile pack {tile_pack.path} has a different palette")
    return shared_pal

def generate_with_array(tile_packs: List[TilePack], size: tuple[int, int], output_dir: str, output_file_name: str):
    palette = shared_palette(tile_packs)

    image = Image.new("P", size, palette[:3])
    image.putpalette(palette)

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

def generate_tiles(tile_packs: List[TilePack], output_dir: str, output_file_name_template: str):
    palette = shared_palette(tile_packs)

    # If len = 3, then generate:
    # 0, 1, 2
    # 1, 2, 0
    # 2, 0, 1
    for i in range(len(tile_packs)):
        output_file_name = output_file_name_template.format(i)
        print("Generating tileset:", output_file_name)

        image = Image.new("P", ((len(tile_packs) + 1) * 8, 8), palette[:3])
        image.putpalette(palette)
        for j in range(len(tile_packs)):
            tile_pack = tile_packs[(i + j) % len(tile_packs)]
            print("  Adding tile pack:", tile_pack)
            tile = Image.open(tile_pack.path)
            image.paste(tile, ((j + 1) * 8, 0))
        output_path = os.path.join(output_dir, output_file_name)
        image.save(output_path, format="BMP")
        print(f"Generated and saved: {output_path}")
        create_tiles_json_metadata(output_path)

def create_tiles_json_metadata(image_path):
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "regular_bg_tiles",
        "bpp_mode": "bpp_4",
        "compression": "auto_no_huffman",
    }

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")

if __name__ == "__main__":
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics/vfx"

    # generate_with_array(SNOW_FG, (512, 512), output_directory, "snow_layer_0.bmp")
    # generate_with_array(SNOW_BG, (256, 256), output_directory, "snow_layer_1.bmp")

    generate_tiles(SAKURA_LAYER_0, output_directory, "sakura_tiles_{:d}.bmp")
    generate_with_array(SAKURA_LAYER_0, (256, 256), output_directory, "sakura_layer_0.bmp")
    generate_with_array(SAKURA_LAYER_1, (256, 256), output_directory, "sakura_layer_1.bmp")
