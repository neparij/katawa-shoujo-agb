import os
import shlex
import shutil
import subprocess
from typing import List

# import diffimg

import json
from PIL import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode

TRANSPARENT_COLOR = (255, 0, 255)
TARGET_FPS = 10
DIFF_THRESHOLD = 0.1


indexed_frame: List[int] = []

def unpack_video(_video_path, _output_dir):
    os.makedirs(_output_dir, exist_ok=True)
    # proc = subprocess.run(shlex.split(f'ffmpeg -y -i {video_path} -r {TARGET_FPS} -vf scale=426:240 {output_dir}/frame_%08d.png'))
    # proc = subprocess.run(shlex.split(f'ffmpeg -y -i {_video_path} -r {TARGET_FPS} -vf scale=-1:180,crop=240:160 {_output_dir}/frame_%d.bmp'))
    # proc = subprocess.run(shlex.split(f'ffmpeg -y -i {_video_path} -r {TARGET_FPS} -vf scale=-1:240,crop=320:214 {_output_dir}/frame_%d.bmp'))

    proc = subprocess.run(shlex.split(
        f'ffmpeg -y -i {_video_path} -r {TARGET_FPS} -vf scale=-1:90,crop=120:80 {_output_dir}/frame_%d.png'))
    # ffmpeg -i input.mkv -vn -ar 18157 -ac 1 -c:a pcm_u8 output.wav
    if proc.returncode == 0:
        print(f"Video unpacked to {_output_dir}")
    else:
        raise Exception(f"Error unpacking video: {proc.returncode}\n{proc.stderr}")

def convert_files(_input_dir, _output_dir, _source_dir):
    os.makedirs(_output_dir, exist_ok=True)

    print("Processing images")

    image_files = [f for f in os.listdir(_input_dir) if f.lower().endswith('.png')]
    print(f"Found {len(image_files)} images")
    sorted_filenames: List[str] = []
    for image_file in image_files:
        print(f"Processing: {image_file}")
        if not image_file.startswith("frame_") or not image_file.endswith(".png"):
            continue
        sorted_filenames.append(image_file.replace("frame_", "").replace(".png", ""))
    sorted_filenames.sort(key=int)

    for f in sorted_filenames:
        indexed_frame.append(int(f))

    for _input_file in sorted_filenames:
        print(f"Processing: {_input_file}")
        output_file = f'{_output_dir}/frame_{_input_file}.bmp'
        # canvas = Image.new("RGB", (256, 256), TRANSPARENT_COLOR)
        # source_image = Image.open(f'{_input_dir}/frame_{_input_file}.png').convert("RGB")
        # source_resized = ImageOps.fit(source_image, (240, 160), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
        # canvas.paste(source_resized, (8, 48))  # Center 240x160 on 256x256
        canvas = Image.new("RGB", (128, 128), TRANSPARENT_COLOR)
        source_image = Image.open(f'{_input_dir}/frame_{_input_file}.png').convert("RGB")
        source_resized = ImageOps.fit(source_image, (120, 80), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
        canvas.paste(source_resized, (4, 24))  # Center 120x80 on 128x128
        converter = Tilequant(
            canvas, TRANSPARENT_COLOR
        )

        #############################
        #     10 FPS, COMPR: none   #
        #############################

        # 4 PAL 16 colors
        # FLOYDSTEINBERG - 4.1 MB
        # NONE - [!] ERROR: ROM/GBFS file too big.
        # ORDERED -

        # 8 PAL 16 colors
        # FLOYDSTEINBERG - 5.4MB
        # NONE - 5MB
        # ORDERED - 4.1MB


        #############################
        #     10 FPS, COMPR: auto   #
        #############################

        # 16 PAL 4 colors
        # FLOYDSTEINBERG -5.7MB
        # NONE -
        # ORDERED -

        #############################
        #     5 FPS, COMPR: auto    #
        #############################

        # 2 PAL 16 colors
        # FLOYDSTEINBERG - 4.1 MB
        # NONE - 3.2MB
        # ORDERED -

        # 8 PAL 16 colors
        # FLOYDSTEINBERG - 5.4MB
        # NONE - 5MB
        # ORDERED - 4.1MB


        quantized = converter.convert(num_palettes=16, colors_per_palette=4, dithering_mode=DitheringMode.NONE)
        quantized.save(output_file, format="BMP")
        print(f"Resized, Quantized and saved: {output_file}")
        create_json_metadata(output_file)

    with open(f'{source_dir}/emi_video.h', "w", encoding="utf-8") as header:
        for line in [
            "#ifndef EMI_VIDEO_H",
            "#define EMI_VIDEO_H",
            "",
            "#include \"bn_regular_bg_item.h\"",
            "",
            "namespace EmiVideo {",
            "",
            "bn::regular_bg_item getFrame(unsigned frame);",
            # "unsigned int getSyncTime(unsigned frame);"
            "",
            "}  // namespace EmiVideo",
            "",
            "#endif  // EMI_VIDEO_H",
        ]:
            header.write(line + "\n")

    with open(f'{source_dir}/emi_video.cpp', "w", encoding="utf-8") as cpp:
        cpp.write("#include \"emi_video.h\"\n\n")
        cpp.write('#include "bn_array.h"\n')
        for f in sorted_filenames:
            cpp.write(f'#include "bn_regular_bg_items_frame_{f}.h"\n')
        cpp.write("\n")
        # cpp.write(f'const bn::array<unsigned int, {len(sorted_filenames)}> sync_time = {{\n')
        # for f in sorted_filenames:
        #     cpp.write(f'    {int(f)},\n')
        # cpp.write("};\n\n")
        cpp.write(f'const bn::array<bn::regular_bg_item, {len(sorted_filenames)}> frames = {{\n')
        for f in sorted_filenames:
            cpp.write(f'    bn::regular_bg_items::frame_{f},\n')
        cpp.write("};\n\n")
        cpp.write("bn::regular_bg_item EmiVideo::getFrame(unsigned frame) {\n")
        cpp.write("    return frames[frame];\n")
        cpp.write("};\n")
        cpp.write("unsigned int EmiVideo::getSyncTime(unsigned frame) {\n")
        cpp.write("    return sync_time[frame];\n")
        cpp.write("};\n")

def create_json_metadata(image_path):
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "regular_bg",
        "bpp_mode": "bpp_4_manual",
        "compression": "none",
    }

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


if __name__ == "__main__":
    # OUTPUT_DIR = "./evout"
    input_file = "/Users/n.laptev/development/ksre/game/video/tc_act2_emi.mkv"
    unpack_dir = "/Users/n.laptev/development/libagmv/examples/simple_gba_video_encode/tc_act2_emi"
    output_dir = "/Users/n.laptev/development/gba/katawa/graphics/video/temp_emi_imgs/converted"
    source_dir = "/Users/n.laptev/development/gba/katawa/src"
    unpack_video(input_file, unpack_dir)
    convert_files(unpack_dir, output_dir, source_dir)
