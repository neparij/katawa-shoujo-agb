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
DISPLAY_WIDTH = 240
DISPLAY_HEIGHT = 160
DISPLAY_BOTTOM_MARGIN = 0

QUALETIZE_PASSES_COLOUR = (2 ** 10) * QUALETIZE_PALETTES_COUNT
QUALETIZE_PASSES_TILES = (2 ** 10) * QUALETIZE_PALETTES_COUNT

IGNORE_IMAGES = [
    "hisao_class",
    "emi_knockeddown_large",
    "emi_knockeddown",
    "lilly_shizu_showdown_full",
    "lilly_shizu_showdown_large"
]

# Used for CustomEvents based on original images.
IGNORE_METAS = [
    "op_snowywoods",
    "other_iwanako",
    "other_iwanako_nosnow",
]

BG_INCLUDE_VFX_IMAGES = [
    "mural_start",
    "mural",
    "mural_unfinished"
]

HEADERS_DIR = "/Users/n.laptev/development/gba/katawa/include"
BG_META_HEADERS_DIR = os.path.join(HEADERS_DIR, "background_metas")

BG_META_STORAGE = []

def resize_images(image_files, output_dir, quantize=True, quantize_palettes=8, unquant_colors : int = 256):
    if not image_files:
        print("No image files found in the specified directory.")
        return

    os.makedirs(output_dir, exist_ok=True)  # Create output directory if it doesn't exist
    os.makedirs(f"{output_dir}/thumbs", exist_ok=True)  # Create output directory if it doesn't exist

    for image_file in image_files:
        output_file_name = f"{os.path.splitext(os.path.basename(image_file))[0]}.bmp"  # Save as BMP
        output_path = os.path.join(output_dir, output_file_name)
        output_meta_path = os.path.join(output_dir, "thumbs", f"thumb_{output_file_name}")

        process_image_savefile_thumbnail(image_file, output_meta_path)
        create_thumbnail_json_metadata(os.path.join(output_dir, "thumbs", "thumb_" + output_file_name))

        if os.path.splitext(output_file_name)[0] in IGNORE_IMAGES:
            print(f"Skipping {image_file} as it is in the ignore list.")
            continue

        try:
            if quantize:
                process_image_quantized(image_file, output_path, quantize_palettes)
                create_json_metadata(output_path, quantize, unquant_colors)
            else:
                process_image(image_file, output_path, unquant_colors)
                create_json_metadata(output_path, quantize, unquant_colors)

            if os.path.splitext(output_file_name)[0] not in IGNORE_METAS:
                write_background_metadata(os.path.splitext(output_file_name)[0])
        except Exception as e:
            print(f"Error processing {image_file}: {e}")

def process_image_quantized(input_path, output_path, quantize_palettes: int):
    canvas = Image.new("RGBA", (256, 256), (0, 0, 0, 0))
    source_image = Image.open(input_path).convert("RGBA")
    width = int((source_image.width / source_image.height) * 1080)
    source_image = source_image.resize((width, 1080), resample=Image.Resampling.LANCZOS)

    crop_x, crop_y = 0, 0
    if DISPLAY_WIDTH == 240 and DISPLAY_HEIGHT == 160:
        gba_resize_factor = 160 / 1080
        extra_width = source_image.width - 1920
        extra_height = source_image.height - 1080
        extra_width_percentage = extra_width / 1920
        extra_height_percentage = extra_height / 1080

        gba_extra_width = int(240 * extra_width_percentage)
        gba_extra_height = int(160 * extra_height_percentage)

        if extra_width < 0:
            print(f"[38;5;197m Source size: {source_image.width}x{source_image.height}, GBA size: 240x160⠀[33;0m")
            print(f"[38;5;197m Extra width: {extra_width}, Extra height: {extra_height}⠀[33;0m")
            print(f"[38;5;197m Extra width percentage: {extra_width_percentage}, Extra height percentage: {extra_height_percentage}⠀[33;0m")
            print(f"[38;5;197m GBA extra width: {gba_extra_width}, GBA extra height: {gba_extra_height}⠀[33;0m")
            # raise Exception(f"Extra width is negative: {extra_width}")
            gba_extra_width = 0
            gba_extra_height = 0

        # color_filter = ImageEnhance.Color(source_image)
        # source_image = color_filter.enhance(1.5)

        source_height_resized = ImageOps.scale(source_image, gba_resize_factor, resample=Image.Resampling.LANCZOS)

        crop_x = source_height_resized.width - (240 + gba_extra_width)
        crop_y = source_height_resized.height - (160 + gba_extra_height)
    else:
        resize_factor = DISPLAY_HEIGHT / 1080
        # color_filter = ImageEnhance.Color(source_image)
        # source_image = color_filter.enhance(1.5)
        source_height_resized = ImageOps.scale(source_image, resize_factor, resample=Image.Resampling.LANCZOS)
        crop_x = source_height_resized.width - (DISPLAY_WIDTH)
        crop_y = source_height_resized.height - (DISPLAY_HEIGHT)

    source_cropped = ImageOps.crop(source_height_resized, (crop_x // 2, crop_y // 2, crop_x // 2, crop_y // 2))
    canvas.paste(source_cropped, ((256 - source_cropped.width) // 2, (256 - source_cropped.height - DISPLAY_BOTTOM_MARGIN) // 2), source_cropped)

    input_filename_path_png = output_path.replace(".bmp", "_input.png")
    input_filename_path_bmp = output_path.replace(".bmp", "_input.bmp")
    canvas.save(input_filename_path_png, format="PNG")

    # Convert PNG to BMP with alpha using ImageMagick
    command = [IMAGEMAGICK, input_filename_path_png, "-define", "bmp:format=bmp4", input_filename_path_bmp]
    try:
        subprocess.check_output(" ".join(command), shell=True, stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as e:
        print(f"Command failed with exit code {e.returncode}")
        print(f"Output: {e.output.decode()}")
        raise

    # Delete the PNG file after conversion
    os.remove(input_filename_path_png)

    # Qualetize the BMP image
    command = [QUALETIZE, input_filename_path_bmp, output_path]
    command.append(f"-npal:{quantize_palettes}")
    command.append(f"-cols:{QUALETIZE_PALETTE_COLORS}")
    command.append(f"-tilepasses:{QUALETIZE_PASSES_TILES}")
    command.append(f"-colourpasses:{QUALETIZE_PASSES_COLOUR}")
    command.append(f"-col0isclear:{"y" if QUALETIZE_COLOR_0_IS_CLEAR else "n"}")
    command.append(f"-rgba:{QUALETIZE_BITS_PER_COLOR}{QUALETIZE_BITS_PER_COLOR}{QUALETIZE_BITS_PER_COLOR}1")
    command.append(f"-colspace:{QUALETIZE_COLOURSPACE}")
    command.append(f"-dither:{QUALETIZE_DITHER_METHOD},{QUALETIZE_DITHER_LEVEL}")
    print(f"Running command: {' '.join(command)}")

    try:
        subprocess.check_output(" ".join(command), shell=True, stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as e:
        print(f"Command failed with exit code {e.returncode}")
        print(f"Output: {e.output.decode()}")
        raise

    # Delete the BMP file after conversion
    os.remove(input_filename_path_bmp)
    print(f"Resized, Quantized and saved: {output_path}")

def process_image(input_path, output_path, colors : int = 256):
    """Process an image: resize, add pink background, remap palette, and save as BMP."""
    # Create a 256x256 image filled with pink
    pink_background = Image.new("RGB", (256, 256), PINK_COLOR)

    # Open the source image
    source_image = Image.open(input_path).convert("RGB")

    # Resize the source image to fit within 240x160 while maintaining aspect ratio
    source_resized = ImageOps.fit(source_image, (256, 160), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
    # pink_background.paste(source_resized, (8, 48))  # Center 240x160 on 256x256
    pink_background.paste(source_resized, (0, 48))  # Center 256x160 on 256x256

    # Convert to 255-color palette
    palette_image = pink_background.convert("P", palette=Image.Palette.ADAPTIVE, colors=colors)

    # # Convert to 63-color palette
    # palette_image = pink_background.convert("P", palette=Image.ADAPTIVE, colors=63)

    # Get the current palette data
    palette = palette_image.getpalette()
    palette_colors = [tuple(palette[i:i + 3]) for i in range(0, len(palette), 3)]

    # Ensure pink is explicitly the first color in the palette
    if PINK_COLOR not in palette_colors:
        print(f"Warning: Pink color {PINK_COLOR} is not in the palette!")
        return

    first_color_index = palette_colors.index(PINK_COLOR)
    remap = list(range(len(palette_colors)))
    if first_color_index != 0:
        # Swap pink with the first palette color
        remap[0], remap[first_color_index] = remap[first_color_index], remap[0]

    # Remap the palette to make pink the first color
    img_remapped = palette_image.remap_palette(remap)
    # img_remapped = palette_image

    # Save the result as BMP
    img_remapped.save(output_path, format="BMP")
    print(f"Resized and saved: {output_path}")

def process_image_savefile_thumbnail(input_path, output_path):
    background = Image.new("RGB", (256, 256), PINK_COLOR)
    source_image = Image.open(input_path).convert("RGB")

    source_resized = ImageOps.fit(source_image, (48, 32), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
    background.paste(source_resized, (104, 112))

    converter = Tilequant(
        background, PINK_COLOR,
        tile_width=8,
        tile_height=8,
    )
    quantized = converter.convert(num_palettes=4, colors_per_palette=16,
                                  dithering_mode=DitheringMode.FLOYDSTEINBERG, dithering_level=0.5,
                                  num_color_cluster_passes=0, num_tile_cluster_passes=0)
    quantized.save(output_path, format="BMP")
    print(f"Resized, quantized and saved: {output_path}")

def create_json_metadata(image_path, quantize, unquant_colors: int):
    """Create a JSON metadata file for the image."""
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "regular_bg",
    }

    if quantize:
        metadata["bpp_mode"] = "bpp_4_manual"
        metadata["compression"] = "auto_no_huffman"
        metadata["tiles_compression"] = "none"
    else:
        metadata["colors"] = unquant_colors
        metadata["compression"] = "auto_no_huffman"
        metadata["tiles_compression"] = "none"

    #  * * `"compression"`: optional field which specifies the compression of the tiles, the colors and the map data:
    #  *   * `"none"`: uncompressed data (this is the default option).
    #  *   * `"lz77"`: LZ77 compressed data.
    #  *   * `"run_length"`: run-length compressed data.
    #  *   * `"huffman"`: Huffman compressed data.
    #  *   * `"auto"`: uses the option which gives the smallest data size.
    #  *   * `"auto_no_huffman"`: uses the option which gives the smallest data size, excluding "huffman".

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")

def create_thumbnail_json_metadata(image_path):
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "regular_bg",
        "bpp_mode": "bpp_4_manual",
        "colors_count": 64,
        "compression": "auto_no_huffman",
    }

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")

def write_background_metadata(background_name):
    meta_filename = os.path.join(BG_META_HEADERS_DIR, f"{background_name}.h")
    hashed_id = hashlib.md5(background_name.encode()).hexdigest()[:8].upper()
    BG_META_STORAGE.append((background_name, hashed_id))

    os.makedirs(BG_META_HEADERS_DIR, exist_ok=True)
    with open(meta_filename, "w", encoding="utf-8") as meta_file:
        meta_file.write(f"#ifndef KS_BGMETA_{background_name.upper()}\n")
        meta_file.write(f"#define KS_BGMETA_{background_name.upper()}\n\n")
        meta_file.write(f'#include "background_meta.h"\n')
        meta_file.write(f'#include "bn_regular_bg_items_{background_name}.h"\n')
        meta_file.write(f'#include "bn_regular_bg_items_thumb_{background_name}.h"\n')
        meta_file.write(f'namespace ks::background_metas {{\n')
        meta_file.write(
            f'    constexpr inline background_meta {background_name}(\n'
            f'                     bn::regular_bg_items::{background_name},\n'
            f'                     bn::regular_bg_items::thumb_{background_name},\n'
            f'                     0x{hashed_id});\n\n')
        meta_file.write(f'}}\n\n')
        meta_file.write(f'#endif  // KS_BGMETA_{background_name.upper()}\n')

def write_background_metadata_store():
    metas_filename = os.path.join(HEADERS_DIR, "background_metas.h")


    with open(metas_filename, "w", encoding="utf-8") as f:
        f.write(f"#ifndef KS_BGMETAS\n")
        f.write(f"#define KS_BGMETAS\n\n")

        f.write(f'#include "custom_background_metas.h"\n\n')
        for bg in BG_META_STORAGE:
            f.write(f'#include "background_metas/{bg[0]}.h"\n')

        f.write(f'namespace ks::background_metas {{\n')
        f.write(f'    inline const bn::regular_bg_item& get_thumbnail_by_hash(const unsigned int hash) {{\n')
        f.write(f'        switch (hash) {{\n')
        for bg in BG_META_STORAGE:
            f.write(f'            case 0x{bg[1]}: return {bg[0]}.thumbnail;\n')
        f.write(f'            default: return get_custom_thumbnail_by_hash(hash);\n')
        f.write(f'        }}\n')
        f.write(f'    }}\n\n')
        f.write(f'}};\n\n')
        f.write(f'#endif  // KS_BGMETAS\n')

def resize_events():
    ### HERE AND AFTER EVENTS
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics/event"
    input_directory = "/Users/n.laptev/development/ksre/game/event"

    image_files = [f"{input_directory}/{f}" for f in os.listdir(input_directory) if f.lower().endswith(('.png', '.jpg', '.jpeg'))]
    # resize_images_in_directory(input_directory, quantize_palettes=8)
    # # resize_images_in_directory(input_directory, quantize=True, quantize_palettes=14)
    # resize_images_in_directory(input_directory, quantize=False, unquant_colors = 16*14)
    # TODO: WAS: resize_images(image_files, output_directory, quantize=False, unquant_colors=16 * 8)
    resize_images(image_files, output_directory, quantize_palettes=8)

    ### HERE AND AFTER EVENTS (LILLY)
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics/event"
    input_directory = "/Users/n.laptev/development/ksre/game/event/Lilly_supercg"

    image_files = [f"{input_directory}/{f}" for f in os.listdir(input_directory) if f.lower().endswith(('.png', '.jpg', '.jpeg'))]
    resize_images(image_files, output_directory, quantize_palettes=8)
    # # resize_images_in_directory(input_directory, quantize=True, quantize_palettes=14)
    # resize_images_in_directory(input_directory, quantize=False, unquant_colors = 16*14)
    # resize_images_in_directory(input_directory, quantize=False, unquant_colors = 16*8)


def resize_backgrounds():
    ## HERE AND AFTER BACKGROUNDS
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics/bgs"
    bgs_directory = "/Users/n.laptev/development/ksre/game/bgs"
    vfx_directory = "/Users/n.laptev/development/ksre/game/vfx"

    image_files = []
    image_files += [f"{bgs_directory}/{f}" for f in os.listdir(bgs_directory) if f.lower().endswith(('.png', '.jpg', '.jpeg'))]
    image_files += [f"{vfx_directory}/{f}.jpg" for f in BG_INCLUDE_VFX_IMAGES]

    resize_images(image_files, output_directory, quantize_palettes=8)
    # resize_images_in_directory(input_directory, quantize=False, unquant_colors=16 * 8)
    # resize_images_in_directory(input_directory)

if __name__ == "__main__":
    resize_backgrounds()
    resize_events()
    write_background_metadata_store()
