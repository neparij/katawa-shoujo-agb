import os
import json
import subprocess
import tempfile
from typing import List

from PIL import Image, ImageOps

IMAGEMAGICK = "magick"
IMGDITHER = "/Users/n.laptev/development/gba/imgdither/release/imgdither"
IMGDITHER_COLOURSPACE = "ycbcr-psy"
IMGDITHER_DITHER_METHOD = "floyd"
IMGDITHER_DITHER_LEVEL = 0.5
IMGDITHER_COLOR_0_IS_CLEAR = True

SCREEN_WIDTH = 240
SCREEN_HEIGHT = 160

class ImageTools:
    TRANSPARENT_COLOR = (255, 0, 253)

    @staticmethod
    def list_converted_images_in_directory(directory: str) -> List[str]:
        # return [f.removesuffix(".bmp") for f in os.listdir(directory) if f.endswith(".bmp")]
        images = []
        for f in os.listdir(directory):
            if f.endswith(".json") and os.path.exists(os.path.join(directory, f.removesuffix(".json") + ".bmp")):
                images.append(f.removesuffix(".json"))
        return images

    @staticmethod
    def resize(input_filename: str, output_filename: str, palettes: int, colors: int,
               y_crop: int = 0,
               y_offset: int = 0,
               dithering: float = 1.0,
               dither_method: str | None = None,
               dither_level: float | None = None,
               remove_size: tuple[int, int] | None = None,
               remove_offset: tuple[int, int] | None = None,
               sprite_offset: tuple[int, int] | None = None,
               sprite_size: tuple[int, int] | None = None,
               num_color_cluster_passes: int = 256,
               num_tile_cluster_passes: int = 256,
               use_sample_palette: str | None = None,
               crop_to_screen: bool = False,
               target_height: int = 160,
               target_size: tuple[int, int] = (256, 256),
               tint: tuple[int, int, int] | None = None):

        canvas = Image.new("RGB", target_size, ImageTools.TRANSPARENT_COLOR)

        print(f"Open: {input_filename}")
        source_image = Image.open(input_filename).convert("RGBA")

        print(f"Cropping: {input_filename}")
        cropped = source_image.crop((0, y_crop + y_offset, source_image.size[0], source_image.size[1] + y_offset))

        ratio = cropped.size[0] / cropped.size[1]
        target_width = int(target_height * ratio)

        print(f"Resize: {input_filename}")
        # source_resized = cropped.resize((target_width, target_height), Image.Resampling.LANCZOS)
        source_resized = cropped.resize((target_width, target_height), Image.Resampling.HAMMING)

        if crop_to_screen:
            print(f"Crop to screen: {input_filename}")
            # Crop to screen. Centered.
            source_resized = source_resized.crop((max(0, int((source_resized.size[0] - SCREEN_WIDTH) / 2)),
                                                 max(0, int((source_resized.size[1] - SCREEN_HEIGHT) / 2)),
                                                 min(source_resized.size[0], int((source_resized.size[0] + SCREEN_WIDTH) / 2)),
                                                 min(source_resized.size[1], int((source_resized.size[1] + SCREEN_HEIGHT) / 2))))

        source_tinted = source_resized
        if tint is not None:
            print(f"Tint: {input_filename} to {tint}")
            source_tinted = ImageOps.colorize(source_resized.convert("L"), [0,0,0], tint).convert("RGBA")

        print(f"Threshold alpha: {input_filename}")
        alpha = source_resized.split()[3]
        alpha = alpha.point(lambda p: 255 if p > 127 else 0)
        source_tinted.putalpha(alpha)

        print(f"Put on canvas: {input_filename}")
        canvas.paste(source_tinted,
                     (int((canvas.size[0] - source_tinted.size[0]) / 2),
                      int((canvas.size[1] - source_tinted.size[1]) / 2)),
                     mask=source_tinted.split()[3])

        if sprite_size and sprite_offset:
            print(f"Crop Sprite to {sprite_size}")
            canvas = canvas.crop(
                (sprite_offset[0], sprite_offset[1], sprite_offset[0] + sprite_size[0],
                 sprite_offset[1] + sprite_size[1]))

        if remove_size and remove_offset:
            remove = Image.new("RGBA", remove_size, ImageTools.TRANSPARENT_COLOR)
            canvas.paste(remove, remove_offset)

        if not use_sample_palette:
            from tilequant import Tilequant
            from tilequant.image_converter import DitheringMode
            print(f"Quantizing: {output_filename}")
            converter = Tilequant(canvas, ImageTools.TRANSPARENT_COLOR)
            quantized = converter.convert(num_palettes=palettes, colors_per_palette=colors,
                                          dithering_mode=DitheringMode.FLOYDSTEINBERG if dithering > 0 else DitheringMode.NONE,
                                          dithering_level=dithering,
                                          num_color_cluster_passes=num_color_cluster_passes, num_tile_cluster_passes=num_tile_cluster_passes)
            quantized.save(output_filename, format="BMP")
            print(f"Resized, Quantized and saved: {output_filename}")
        else:
            palette_file = os.path.abspath(use_sample_palette)
            print(f"Dithering using sample palette: {palette_file}")
            input_filename_path_png = tempfile.mktemp(suffix="-ksgba.png")
            input_filename_path_bmp = tempfile.mktemp(suffix="-ksgba.bmp")
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

            # Remap and dither the image
            command = [IMGDITHER, input_filename_path_bmp, palette_file, output_filename]
            command.append(f"-col0isclear:{"y" if IMGDITHER_COLOR_0_IS_CLEAR else "n"}")
            command.append(f"-colspace:{IMGDITHER_COLOURSPACE}")
            method = dither_method if dither_method is not None else IMGDITHER_DITHER_METHOD
            level = dither_level if dither_level is not None else IMGDITHER_DITHER_LEVEL
            if method == "none" or level <= 0:
                command.append("-dither:none,0")
            else:
                command.append(f"-dither:{method},{level}")
            print(f"Running command: {' '.join(command)}")

            try:
                subprocess.check_output(" ".join(command), shell=True, stderr=subprocess.STDOUT)
            except subprocess.CalledProcessError as e:
                print(f"Command failed with exit code {e.returncode}")
                print(f"Output: {e.output.decode()}")
                raise

            # Delete the BMP file after conversion
            os.remove(input_filename_path_bmp)
            dither_note = "none" if method == "none" or level <= 0 else f"{method},{level}"
            print(f"Resized, Converted with sample palette, dithered({dither_note}) and saved: {output_filename}")

    @staticmethod
    def create_8x8_tiles(input_filename: str, output_filename: str) -> List[str]:
        print(f"Open: {input_filename}")
        filenames = []
        output_filename = output_filename.removesuffix(".bmp")
        source_image = Image.open(input_filename).convert("RGBA")
        width, height = source_image.size
        if width % 8 != 0 or height % 8 != 0:
            raise Exception("Image dimensions must be a multiple of 8.")
        for y in range(0, height, 8):
            for x in range(0, width, 8):
                tile = source_image.crop((x, y, x + 8, y + 8))
                tile = tile.convert("P", palette=Image.Palette.ADAPTIVE, colors=16, dither=Image.Dither.NONE)
                tile_filename = f"{output_filename}_{x // 8:02X}_{y // 8:02X}.bmp"
                tile.save(tile_filename, format="BMP")
                filenames.append(tile_filename)
        print(f"Tiles saved: {output_filename}")
        return filenames

    @staticmethod
    def resize_background(input_filename: str, output_filename: str, quantize: bool = True):
        palettes = 4 if quantize else 1
        colors = 16 if quantize else 256
        ImageTools.resize(input_filename, output_filename, palettes, colors)

    @staticmethod
    def resize_character_background(input_filename: str, output_filename: str,
                                    y_offset: int = 0, y_crop: int = 120,
                                    face_cutout_offset: tuple[int, int] | None = None,
                                    face_cutout_size: tuple[int, int] | None = None,
                                    tint: list | None = None,
                                    dither_method: str | None = None,
                                    dither_level: float | None = None):
        """Generate the body-BG bitmap. If `face_cutout_*` are given (canvas-px,
        already 8-px aligned), the face region is filled with the magic
        transparent color so it's a clean rectangle of empty BG cells —
        runtime overlays the matching emotion sprite on top.
        """
        palettes = 2
        colors = 16
        ImageTools.resize(input_filename, output_filename, palettes, colors, y_crop=y_crop, y_offset=y_offset,
                          num_color_cluster_passes=256, num_tile_cluster_passes=256,
                          use_sample_palette="../../graphics/common_palettes/pal_char_bg.bmp",
                          crop_to_screen=True, tint=tint,
                          remove_offset=face_cutout_offset, remove_size=face_cutout_size,
                          dither_method=dither_method, dither_level=dither_level)

    @staticmethod
    def resize_character_thumbnail(input_filename: str, output_filename: str,
                                   y_offset=0, y_crop: int = 120,
                                   tint: tuple[int, int, int] | None = None):
        palettes = 2
        colors = 16
        ImageTools.resize(input_filename, output_filename, palettes, colors, y_crop=y_crop, y_offset=y_offset,
                          target_height=32, target_size=(32, 32),
                          num_color_cluster_passes=256, num_tile_cluster_passes=256,
                          use_sample_palette="../../graphics/common_palettes/pal_char_bg.bmp",
                          crop_to_screen=True, tint=tint)

    @staticmethod
    def resize_character_emotion_sprite(input_filename: str, output_filename: str, sprite_offset: tuple[int, int],
                                        sprite_size: tuple[int, int], y_offset = 0, y_crop: int = 120,
                                        use_sample_palette = None, tint: tuple[int, int, int] | None = None):
        palettes = 1
        colors = 16
        ImageTools.resize(input_filename, output_filename, palettes, colors, y_crop=y_crop, y_offset=y_offset,
                          dithering=0.0,
                          sprite_offset=sprite_offset, sprite_size=sprite_size,
                          num_color_cluster_passes=16, num_tile_cluster_passes=256,
                          use_sample_palette="../../graphics/common_palettes/pal_char_bg.bmp",
                          tint=tint)

