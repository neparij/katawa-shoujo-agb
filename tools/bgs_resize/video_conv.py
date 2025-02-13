import os
import shlex
import shutil
import subprocess
from typing import List

import diffimg

import json
from PIL import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode

PINK_COLOR = (255, 0, 255)  # Pink background color
QUANTIZE = True
DIFF_RESOLUTION_DIVIDER = 8
DIFF_THRESHOLD = 0.1
SOURCE_FPS = 15
MIN_FPS = 5
MAX_FPS = 15

MAX_FRAME_SKIP = SOURCE_FPS / MIN_FPS
MIN_FRAME_SKIP = SOURCE_FPS / MAX_FPS

USE_DIFF = True

def unpack_video(video_path, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    # proc = subprocess.run(shlex.split(f'ffmpeg -y -i {video_path} -r {SOURCE_FPS} {output_dir}/frame_%08d.png'))
    proc = subprocess.run(shlex.split(f'ffmpeg -y -i {video_path} -r {SOURCE_FPS} {output_dir}/frame_%d.png'))
    if proc.returncode == 0:
        print(f"Video unpacked to {output_dir}")
    else:
        raise Exception(f"Error unpacking video: {proc.returncode}\n{proc.stderr}")

def resize_images_in_directory(input_dir):
    """Resize all images in the input directory and save them in the output directory."""
    image_files = [f for f in os.listdir(input_dir) if f.lower().endswith(('.png'))]

    if not image_files:
        print("No image files found in the specified directory.")
        return

    os.makedirs(OUTPUT_DIR, exist_ok=True)  # Create output directory if it doesn't exist

    sorted_filenames: List[str] = []
    for image_file in image_files:
        if not image_file.startswith("frame_") or not image_file.endswith(".png"):
            continue

        sorted_filenames.append(image_file.replace("frame_", "").replace(".png", ""))
    sorted_filenames.sort(key=int)


    if USE_DIFF:
        for f in sorted_filenames:
            canvas = Image.new("RGB", (256 // DIFF_RESOLUTION_DIVIDER, 256 // DIFF_RESOLUTION_DIVIDER), PINK_COLOR)
            source_image = Image.open(f'{input_dir}/frame_{f}.png').convert("RGB")
            source_resized = ImageOps.fit(source_image, (256 // DIFF_RESOLUTION_DIVIDER, 256 // DIFF_RESOLUTION_DIVIDER), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
            canvas.paste(source_resized, (0,0))
            saturated = canvas.convert("P", palette=Image.Palette.WEB, colors=16, dither=Image.Dither.NONE)
            saturated.save(f'{input_dir}/saturated/frame_{f}.bmp', format="BMP")


    positive_frames : List[str] = []
    previous_frame = None
    count = 0
    skipped_frames = 0
    for f in sorted_filenames:
        if previous_frame is not None:
            if USE_DIFF:
                diff = diffimg.diff(f'{input_dir}/saturated/frame_{previous_frame}.bmp', f'{input_dir}/saturated/frame_{f}.bmp')
                ration: float = diff
                # print("ration: ", ration)
                if ration > DIFF_THRESHOLD or skipped_frames > MAX_FRAME_SKIP and not skipped_frames < MIN_FRAME_SKIP:
                    if skipped_frames > MAX_FRAME_SKIP:
                        print(f"!!! Skipped frames is to ^HIGH^ !!!")
                    count += 1
                    print(f"Frame {f} is different from {previous_frame} with ration {ration}")
                    positive_frames.append(f)
                    previous_frame = f
                    skipped_frames = 0
                else:
                    if ration > DIFF_THRESHOLD and not skipped_frames < MIN_FRAME_SKIP:
                        print(f"!!! Skipped frames is too _low_ !!!")
                    skipped_frames += 1
            else:
                positive_frames.append(f)
                previous_frame = f
        else:
            positive_frames.append(f)
            previous_frame = f

    print(f"Total frames: {len(sorted_filenames)}\n"
          f"Diff frames: {count}\n"
          f"Ratio threshold: {DIFF_THRESHOLD}\n"
          f"Efficiency: {int(count/len(sorted_filenames)*100)}%")

    # Copy original frames for positive frames
    for f in positive_frames:
        shutil.copy(f'{input_dir}/frame_{f}.png', f'{input_dir}/positive/frame_{f}.png')

    with open(f'{input_dir}/emi_video.h', "w", encoding="utf-8") as header:
        for line in [
            "#ifndef EMI_VIDEO_H",
            "#define EMI_VIDEO_H",
            "",
            "#include \"bn_regular_bg_item.h\"",
            "",
            "namespace EmiVideo {",
            "",
            "bn::regular_bg_item getFrame(unsigned frame);",
            "unsigned int getSyncTime(unsigned frame);"
            "",
            "}  // namespace EmiVideo",
            "",
            "#endif  // EMI_VIDEO_H",
        ]:
            header.write(line + "\n")

    with open(f'{input_dir}/emi_video.cpp', "w", encoding="utf-8") as cpp:
        cpp.write("#include \"emi_video.h\"\n\n")
        cpp.write('#include "bn_array.h"\n')
        for f in positive_frames:
            cpp.write(f'#include "bn_regular_bg_items_frame_{f}.h"\n')
        cpp.write("\n")
        cpp.write(f'const bn::array<unsigned int, {len(positive_frames)}> sync_time = {{\n')
        for f in positive_frames:
            cpp.write(f'    {int(f)},\n')
        cpp.write("};\n\n")
        cpp.write(f'const bn::array<bn::regular_bg_item, {len(positive_frames)}> frames = {{\n')
        for f in positive_frames:
            cpp.write(f'    bn::regular_bg_items::frame_{f},\n')
        cpp.write("};\n\n")
        cpp.write("bn::regular_bg_item EmiVideo::getFrame(unsigned frame) {\n")
        cpp.write("    return frames[frame];\n")
        cpp.write("};\n")
        cpp.write("unsigned int EmiVideo::getSyncTime(unsigned frame) {\n")
        cpp.write("    return sync_time[frame];\n")
        cpp.write("};\n")


if __name__ == "__main__":
    # OUTPUT_DIR = "./evout"
    OUTPUT_DIR = "/Users/n.laptev/development/libagmv/examples/simple_gba_video_encode/tc_act2_emi"
    video_path = "/Users/n.laptev/development/ksre/game/video/tc_act2_emi.mkv"
    unpack_video(video_path, OUTPUT_DIR)
    resize_images_in_directory(OUTPUT_DIR)
