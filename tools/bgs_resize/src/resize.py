import argparse
import hashlib
import os
import json
import subprocess
from typing import List

import numpy as np
from PIL import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode

from src.definition_reader import DefinitionsReader, GalleryImageDefinition

ONLY_METADATA = False
ONLY_MISSING = False
GALLERY_IMAGES : List[GalleryImageDefinition] = []

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

QUALETIZE_PASSES_COLOUR = (2 ** 12) * QUALETIZE_PALETTES_COUNT
QUALETIZE_PASSES_TILES = (2 ** 12) * QUALETIZE_PALETTES_COUNT

IGNORE_IMAGES = [
    "hisao_class",
    "emi_knockeddown_large",
    "emi_knockeddown",
    "lilly_shizu_showdown_full",
    "lilly_shizu_showdown_large",
    "hanako_fw",
    "hanako_fw_flash",
    "rin_wet_pan_down",
    "rin_wet_arms",
    "rin_h_closed",
    "rin_h_left",
    "rin_h_normal",
    "rin_h_right",
    "rin_h_strain",
    "rin_h_closed_close",
    "rin_h_left_close",
    "rin_h_normal_close",
    "rin_h_right_close",
    "rin_h_strain_close",
    "rin_h2_l_pan",
    "rin_h2_l_nopan",
    "rin_h2_l_hisao",
    "rin_h2_u_surprise",
    "rin_h2_u_away",
    "rin_h2_u_closed",
    "rin_goodend_base",
    "rin_goodend_1",
    "rin_goodend_1b",
    "rin_goodend_2",
    "rin_goodend_fg",
    "rin_goodend_2_hires",
    "rin_pair_base",
    "rin_pair_hisao_clothes",
    "rin_pair_hisao_smile",
    "rin_pair_hisao_frown",
    "rin_pair_rin_talk",
    "rin_pair_rin_smile",
    "rin_pair_rin_frown",
    "rin_pair_rin_closed",
    "emi_sleep_normal",
    "emi_sleep_unsure",
    "emi_sleep_weep",
    "emi_sleep_cry",
    "picnic_normal",
    "picnic_rain",
    "hana_library",
    "hana_library_read",
    "hana_library_gasp",
    "hana_library_smile",
    "shizu_shanghai",
    "shizu_shanghai_boredlaugh",
    "shizu_shanghai_borednormal",
    "shizu_shanghai_normallaugh",
    "shizu_shanghai_smirklaugh",
    "shizu_shanghai_smirknormal",
    "shizu_undressing_clothed_stare",
    "shizu_undressing_clothed_kiss",
    "shizu_undressing_clothed_blush",
    "shizu_undressing_unclothed_closed",
    "shizu_undressing_unclothed_blush",
    "shizu_undressing_unclothed_kiss",
    "shizu_undressing_unclothed_talk",
    "shizu_straddle_open",
    "shizu_straddle_tease",
    "shizu_straddle_closed",
    "shizu_straddle_smile",
    "shizu_straddle_come",
    "shizu_table_smile",
    "shizu_table_normal",
    "shizu_table_comeopen",
    "shizu_table_comeclosed",
    "shizune_hcg_tied_smile",
    "shizune_hcg_tied_blush",
    "shizune_hcg_tied_stare",
    "shizune_hcg_tied_close",
    "shizune_hcg_tied_kinky3",
    "shizune_hcg_tied_kinky2",
    "shizune_hcg_tied_kinky1",
    "shizune_hcg_tied_hisao2",
]

CUSTOM_PALETTE_IMAGES = {
    "misc_sky_ni": 6,
}

# Used for CustomEvents based on original images.
IGNORE_METAS = [
    "op_snowywoods",
    "other_iwanako",
    "other_iwanako_nosnow",
    "hosp_room"
]

BG_INCLUDE_VFX_IMAGES = [
    "mural_start.jpg",
    "mural.jpg",
    "mural_unfinished.jpg",
    "icecream.jpg",
    "braille.jpg",
    "hanako_eye.jpg",
    "worrytree.jpg",
    "dandelion.jpg",
    "gallery_atelier_close.jpg",
    "rin_doodle.png"
]

DISPLAYABLE_BITMASK_MAP = {
    # VFX items
    "musicbox closed": "musicbox_closed",
    "musicbox open": "musicbox_open",
    "insert startpistol": "startpistol",
    # EVENTS
    "lilly_handjob_chest_frown_small": "lilly_hcg_handjob_chest_frown",
    "lilly_handjob_chest_normal_small": "lilly_hcg_handjob_chest_normal",
    "lilly_handjob_stroke_flustopen_small": "lilly_hcg_handjob_stroke_flustopen_small",
    "lilly_handjob_stroke_normopen_small": "lilly_hcg_handjob_stroke_normopen_small",
    "lilly_handjob_stroke_normshut_small": "lilly_hcg_handjob_stroke_normshut_small",
    "lilly_cowgirl_cry_small": "lilly_hcg_cowgirl_cry_small",
    "lilly_cowgirl_frown_small": "lilly_hcg_cowgirl_frown_small",
    "lilly_cowgirl_smile_small": "lilly_hcg_cowgirl_smile_small",
    "lilly_cowgirl_strain_small": "lilly_hcg_cowgirl_strain_small",
    "lilly_cowgirl_weaksmile_small": "lilly_hcg_cowgirl_weaksmile_small",
    "lilly_bath_emb_small": "lilly_hcg_bath_emb_small",
    "lilly_bath_grab_small": "lilly_hcg_bath_grab_small",
    "lilly_bath_moan_small": "lilly_hcg_bath_moan_small",
    "lilly_bath_open_small": "lilly_hcg_bath_open_small",
    "lilly_bath_smile_small": "lilly_hcg_bath_smile_small",
    "lilly_afterbath_open_small": "lilly_hcg_afterbath_open_small",
    "lilly_afterbath_shut_small": "lilly_hcg_afterbath_shut_small",
    "showdown": "lilly_shizu_showdown",
}

HEADERS_DIR = "/Users/n.laptev/development/gba/katawa/include"
BG_META_HEADERS_DIR = os.path.join(HEADERS_DIR, "background_metas")
VFX_META_HEADERS_DIR = os.path.join(HEADERS_DIR, "vfx_metas")

BG_META_STORAGE = []

def displayable_in_gallery_def(bg_name : str):
    for img in GALLERY_IMAGES:
        if bg_name in img.images:
            return True
    return False

def displayable_bitmask_name(bg_name : str):
    displayable = bg_name
    for displayable_name in DISPLAYABLE_BITMASK_MAP:
        if bg_name in DISPLAYABLE_BITMASK_MAP[displayable_name]:
            displayable = displayable_name
    if displayable_in_gallery_def(displayable):
        return f"DISPLAYABLE_BITMASK_{displayable.upper().replace(" " , "_")}"
    return "DISPLAYABLE_BITMASK_NONE"

def resize_images(image_files, output_dir, quantize=True, quantize_palettes=8, unquant_colors : int = 256,
                  only_metadata=False, only_missing=False, metadata_type=None):
    if not metadata_type in [None, "bg", "vfx"]:
        raise Exception(f"Unknown storage type: {metadata_type}")

    if not image_files:
        print("No image files found in the specified directory.")
        return

    os.makedirs(output_dir, exist_ok=True)  # Create output directory if it doesn't exist
    os.makedirs(f"{output_dir}/thumbs", exist_ok=True)  # Create output directory if it doesn't exist

    for image_file in image_files:
        output_file_name = f"{os.path.splitext(os.path.basename(image_file))[0]}.bmp"  # Save as BMP
        output_basename = os.path.splitext(output_file_name)[0]
        output_path = os.path.join(output_dir, output_file_name)
        output_meta_path = os.path.join(output_dir, "thumbs", f"thumb_{output_file_name}")

        if output_basename in IGNORE_IMAGES:
            print(f"Skipping {image_file} as it is in the ignore list.")
            continue

        if metadata_type in ["bg"]:
            thumb_exists = os.path.exists(output_meta_path)
            thumb_json_exists = os.path.exists(os.path.join(output_dir, "thumbs", f"thumb_{output_basename}.json"))
            create_thumbnail = True
            if thumb_exists and thumb_json_exists:
                create_thumbnail = not only_missing
            if create_thumbnail:
                if not only_metadata:
                    process_image_savefile_thumbnail(image_file, output_meta_path)
                create_thumbnail_json_metadata(os.path.join(output_dir, "thumbs", "thumb_" + output_file_name))

        if output_basename in CUSTOM_PALETTE_IMAGES.keys():
            quantize_palettes = CUSTOM_PALETTE_IMAGES[output_basename]
            print(f"Using custom palette count {quantize_palettes} for {image_file}")

        try:
            image_exists = os.path.exists(output_path)
            image_json_exists = os.path.exists(os.path.join(output_dir, f"{output_basename}.json"))
            create_image = True
            if image_exists and image_json_exists:
                create_image = not only_missing
            if create_image:
                if quantize:
                    if not only_metadata:
                        process_image_quantized(image_file, output_path, quantize_palettes)
                    create_json_metadata(output_path, quantize, unquant_colors)
                else:
                    if not only_metadata:
                        process_image(image_file, output_path, unquant_colors)
                    create_json_metadata(output_path, quantize, unquant_colors)

            if output_basename not in IGNORE_METAS and metadata_type is not None:
                if metadata_type == "bg":
                    write_background_metadata(output_basename)
                elif metadata_type == "vfx":
                    write_vfx_metadata(output_basename)
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
            print(f"[38;5;197m Source size: {source_image.width}x{source_image.height}, GBA size: 240x160?[33;0m")
            print(f"[38;5;197m Extra width: {extra_width}, Extra height: {extra_height}?[33;0m")
            print(f"[38;5;197m Extra width percentage: {extra_width_percentage}, Extra height percentage: {extra_height_percentage}?[33;0m")
            print(f"[38;5;197m GBA extra width: {gba_extra_width}, GBA extra height: {gba_extra_height}?[33;0m")
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
    # Remove Semi-transparent pixels:
    arr = np.array(canvas)  # shape (h, w, 4)
    mask = arr[:, :, 3] > 127  # visible mask
    # Visible ? force alpha=255
    arr[mask, 3] = 255
    # Invisible ? set to (0,0,0,0)
    arr[~mask] = (0, 0, 0, 0)
    result = Image.fromarray(arr, "RGBA")

    input_filename_path_png = output_path.replace(".bmp", "_input.png")
    input_filename_path_bmp = output_path.replace(".bmp", "_input.bmp")
    result.save(input_filename_path_png, format="PNG")

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
    raise Exception("process_image - Not used anymore, use quantized version!")
    # # Create a 256x256 image filled with pink
    # pink_background = Image.new("RGB", (256, 256), PINK_COLOR)
    #
    # # Open the source image
    # source_image = Image.open(input_path).convert("RGB")
    #
    # # Resize the source image to fit within 240x160 while maintaining aspect ratio
    # source_resized = ImageOps.fit(source_image, (256, 160), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
    # # pink_background.paste(source_resized, (8, 48))  # Center 240x160 on 256x256
    # pink_background.paste(source_resized, (0, 48))  # Center 256x160 on 256x256
    #
    # # Convert to 255-color palette
    # palette_image = pink_background.convert("P", palette=Image.Palette.ADAPTIVE, colors=colors)
    #
    # # # Convert to 63-color palette
    # # palette_image = pink_background.convert("P", palette=Image.ADAPTIVE, colors=63)
    #
    # # Get the current palette data
    # palette = palette_image.getpalette()
    # palette_colors = [tuple(palette[i:i + 3]) for i in range(0, len(palette), 3)]
    #
    # # Ensure pink is explicitly the first color in the palette
    # if PINK_COLOR not in palette_colors:
    #     print(f"Warning: Pink color {PINK_COLOR} is not in the palette!")
    #     return
    #
    # first_color_index = palette_colors.index(PINK_COLOR)
    # remap = list(range(len(palette_colors)))
    # if first_color_index != 0:
    #     # Swap pink with the first palette color
    #     remap[0], remap[first_color_index] = remap[first_color_index], remap[0]
    #
    # # Remap the palette to make pink the first color
    # img_remapped = palette_image.remap_palette(remap)
    # # img_remapped = palette_image
    #
    # # Save the result as BMP
    # img_remapped.save(output_path, format="BMP")
    # print(f"Resized and saved: {output_path}")

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
        metadata["tiles_compression"] = "auto_no_huffman"
    else:
        metadata["colors"] = unquant_colors
        metadata["compression"] = "auto_no_huffman"
        metadata["tiles_compression"] = "auto_no_huffman"

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
        meta_file.write(f'#include "definitions/seen_bitmask.h"\n')
        meta_file.write(f'#include "bn_regular_bg_items_{background_name}.h"\n')
        meta_file.write(f'#include "bn_regular_bg_items_thumb_{background_name}.h"\n')
        meta_file.write(f'namespace ks::background_metas {{\n')
        meta_file.write(
            f'    constexpr inline background_meta {background_name}(\n'
            f'                     bn::regular_bg_items::{background_name},\n'
            f'                     bn::regular_bg_items::thumb_{background_name},\n'
            f'                     {displayable_bitmask_name(background_name)},\n'
            f'                     0x{hashed_id});\n\n')
        meta_file.write(f'}}\n\n')
        meta_file.write(f'#endif  // KS_BGMETA_{background_name.upper()}\n')

def write_vfx_metadata(vfx_name):
    meta_filename = os.path.join(VFX_META_HEADERS_DIR, f"{vfx_name}.h")

    os.makedirs(BG_META_HEADERS_DIR, exist_ok=True)
    with open(meta_filename, "w", encoding="utf-8") as meta_file:
        meta_file.write(f"#ifndef KS_VFXMETA_{vfx_name.upper()}\n")
        meta_file.write(f"#define KS_VFXMETA_{vfx_name.upper()}\n\n")
        meta_file.write(f'#include "vfx_meta.h"\n')
        meta_file.write(f'#include "definitions/seen_bitmask.h"\n')
        meta_file.write(f'#include "bn_regular_bg_items_{vfx_name}.h"\n')
        meta_file.write(f'namespace ks::vfx_metas {{\n')
        meta_file.write(
            f'    constexpr inline vfx_meta {vfx_name}(\n'
            f'                     bn::regular_bg_items::{vfx_name},\n'
            f'                     {displayable_bitmask_name(vfx_name)});\n\n')
        meta_file.write(f'}}\n\n')
        meta_file.write(f'#endif  // KS_VFXMETA_{vfx_name.upper()}\n')

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
    input_directories = [
        "/Users/n.laptev/development/ksre-2/game/event",
        "/Users/n.laptev/development/ksre-2/game/event/emi_grinding",
        "/Users/n.laptev/development/ksre-2/game/event/emi_shed",
        "/Users/n.laptev/development/ksre-2/game/event/hanako_breakdown",
        "/Users/n.laptev/development/ksre-2/game/event/hisaobird",
        "/Users/n.laptev/development/ksre-2/game/event/kenji_glasses",
        "/Users/n.laptev/development/ksre-2/game/event/lilly_afterbath",
        "/Users/n.laptev/development/ksre-2/game/event/lilly_bath",
        "/Users/n.laptev/development/ksre-2/game/event/lilly_cowgirl",
        "/Users/n.laptev/development/ksre-2/game/event/lilly_handjob",
        "/Users/n.laptev/development/ksre-2/game/event/Lilly_supercg",
        "/Users/n.laptev/development/ksre-2/game/event/lilly_train",
        "/Users/n.laptev/development/ksre-2/game/event/rin_goodend",
        "/Users/n.laptev/development/ksre-2/game/event/rin_h",
        "/Users/n.laptev/development/ksre-2/game/event/rin_h2",
        "/Users/n.laptev/development/ksre-2/game/event/rin_pair",
        "/Users/n.laptev/development/ksre-2/game/event/rin_roof",
        "/Users/n.laptev/development/ksre-2/game/event/rin_trueend",
        "/Users/n.laptev/development/ksre-2/game/event/rin_wet",
        "/Users/n.laptev/development/ksre-2/game/event/shizu_roof",
        "/Users/n.laptev/development/ksre-2/game/event/shizu_supercg",
        "/Users/n.laptev/development/ksre-2/game/event/shizu_undressing",
        "/Users/n.laptev/development/ksre-2/game/event/shizu_yukata",
        "/Users/n.laptev/development/ksre-2/game/event/shizune_hcg_tied",
    ]

    image_files = []
    for input_directory in input_directories:
        image_files += [f"{input_directory}/{f}" for f in os.listdir(input_directory) if f.lower().endswith('.png')]

    resize_images(image_files, output_directory, quantize_palettes=8, only_metadata=ONLY_METADATA, only_missing=ONLY_MISSING, metadata_type="bg")

def resize_items():
    ### HERE AND AFTER EVENTS
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics/vfx"
    input_directory = "/Users/n.laptev/development/ksre-2/game/vfx"
    items = [
        "pills",
        "stuffedcat",
        "teaset",
        "shangpai",
        "wine",
        "musicbox_closed",
        "musicbox_open",
        "hanaphone",
        "phonestrap",
        "hanaphonestrap",
        "startpistol",
        "invite",
        "sc_comp",
        "brailler",
        "chessboard",
        "kenjibox",
        "jigorocard",
        "letter_insert",
        "letter_open_insert",
        "letter_open_insert_2",
        "stallphoto_insert"
    ]

    image_files = []
    for item in items:
        image_files.append(f"{input_directory}/{item}.png")

    resize_images(image_files, output_directory, quantize_palettes=8, only_metadata=ONLY_METADATA, only_missing=ONLY_MISSING, metadata_type="vfx")

def resize_backgrounds():
    ## HERE AND AFTER BACKGROUNDS
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics/bgs"
    bgs_directory = "/Users/n.laptev/development/ksre-2/game/bgs"
    vfx_directory = "/Users/n.laptev/development/ksre-2/game/vfx"

    image_files = []
    image_files += [f"{bgs_directory}/{f}" for f in os.listdir(bgs_directory) if f.lower().endswith(('.png', '.jpg', '.jpeg'))]
    image_files += [f"{vfx_directory}/{f}" for f in BG_INCLUDE_VFX_IMAGES]

    resize_images(image_files, output_directory, quantize_palettes=8, only_metadata=ONLY_METADATA, only_missing=ONLY_MISSING, metadata_type="bg")
    # resize_images_in_directory(input_directory, quantize=False, unquant_colors=16 * 8)
    # resize_images_in_directory(input_directory)

def main():
    parser = argparse.ArgumentParser(description="Katawa Shoujo GBA: BGS Resizer (Deprecated)")
    parser.add_argument(
        "--only-metadata",
        required=False,
        default=False,
        action="store_true"
    )
    parser.add_argument(
        "--only-missing",
        required=False,
        default=False,
        action="store_true"
    )

    args = parser.parse_args()
    global ONLY_METADATA
    global ONLY_MISSING
    global GALLERY_IMAGES
    ONLY_METADATA = args.only_metadata
    ONLY_MISSING = args.only_missing


    definitions_reader = DefinitionsReader(os.path.join("/Users/n.laptev/development/ksre-2", "game", "definitions.rpy"))
    gallery_images_ast = definitions_reader.extract_gallery_images_block()
    gallery_images = definitions_reader.parse_gallery_images_structure(gallery_images_ast)
    GALLERY_IMAGES = gallery_images

    resize_backgrounds()
    resize_events()
    resize_items()
    write_background_metadata_store()

if __name__ == "__main__":
    main()
