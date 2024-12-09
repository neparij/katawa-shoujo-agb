import os
import json
from typing import List

from PIL import Image
# import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode


class ImageTools:
    TRANSPARENT_COLOR = (255, 0, 255)

    @staticmethod
    def resize(input_filename: str, output_filename: str, palettes: int, colors: int,
               y_crop: int = 0,
               y_offset: int = 0,
               dithering: float = 1.0,
               remove_size: tuple[int, int] | None = None,
               remove_offset: tuple[int, int] | None = None,
               sprite_offset: tuple[int, int] | None = None,
               sprite_size: tuple[int, int] | None = None):
        canvas = Image.new("RGBA", (256, 256), ImageTools.TRANSPARENT_COLOR)

        print(f"Open: {input_filename}")
        source_image = Image.open(input_filename).convert("RGBA")

        print(f"Cropping: {input_filename}")
        cropped = source_image.crop((0, y_crop + y_offset, source_image.size[0], source_image.size[1] + y_offset))

        ratio = cropped.size[0] / cropped.size[1]
        target_height = 160
        target_width = int(target_height * ratio)

        print(f"Resize: {input_filename}")
        source_resized = cropped.resize((target_width, target_height), Image.Resampling.LANCZOS)

        print(f"Threshold alpha: {input_filename}")
        alpha = source_resized.split()[3]
        alpha = alpha.point(lambda p: 255 if p > 127 else 0)
        source_resized.putalpha(alpha)

        print(f"Put on canvas: {input_filename}")
        canvas.paste(source_resized,
                     (int((canvas.size[0] - source_resized.size[0]) / 2),
                      int((canvas.size[1] - source_resized.size[1]) / 2)),
                     mask=source_resized.split()[3])

        if sprite_size and sprite_offset:
            print(f"Crop Sprite to {sprite_size}")
            canvas = canvas.crop(
                (sprite_offset[0], sprite_offset[1], sprite_offset[0] + sprite_size[0],
                 sprite_offset[1] + sprite_size[1]))

        if remove_size and remove_offset:
            remove = Image.new("RGBA", remove_size, ImageTools.TRANSPARENT_COLOR)
            canvas.paste(remove, remove_offset)

        # if palettes > 1:
        print(f"Quantizing: {output_filename}")
        converter = Tilequant(canvas, ImageTools.TRANSPARENT_COLOR)
        quantized = converter.convert(num_palettes=palettes, colors_per_palette=colors,
                                      dithering_mode=DitheringMode.FLOYDSTEINBERG if dithering > 0 else DitheringMode.NONE,
                                      dithering_level=dithering,
                                      num_color_cluster_passes=256, num_tile_cluster_passes=256)
        # canvas.save(output_filename, format="BMP")
        quantized.save(output_filename, format="BMP")
        print(f"Resized, Quantized and saved: {output_filename}")
        # else:
        #     print(f"Convert to {colors} colors palette.")
        #     palette_image = canvas.convert("P", palette=Image.Palette.ADAPTIVE, colors=colors, dither=Image.Dither.FLOYDSTEINBERG if dithering > 0 else Image.Dither.NONE)
        #     palette = palette_image.getpalette()
        #     num_colors = len(palette) // 3
        #     palette[(num_colors - 1) * 3:(num_colors - 1) * 3 + 3] = ImageTools.TRANSPARENT_COLOR
        #     palette_colors = [tuple(palette[i:i + 3]) for i in range(0, len(palette), 3)]
        #     palette_image.putpalette(palette)
        #
        #     remap = list(range(len(palette_colors)))
        #     remap[0], remap[num_colors - 1] = remap[num_colors - 1], remap[0]
        #
        #     # Remap the palette to make pink the first color
        #     img_remapped = palette_image.remap_palette(remap)
        #     img_remapped.save(output_filename, format="BMP")
        #     print(f"Resized, Converted and saved: {output_filename}")

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
        palettes = 8 if quantize else 1
        colors = 16 if quantize else 256
        ImageTools.resize(input_filename, output_filename, palettes, colors)

    @staticmethod
    def resize_character_background(input_filename: str, output_filename: str, remove_size: tuple[int, int], remove_offset: tuple[int, int], y_offset = 0):
        palettes = 2
        colors = 16
        ImageTools.resize(input_filename, output_filename, palettes, colors, y_crop=120, y_offset=y_offset, remove_size=remove_size, remove_offset=remove_offset)

    @staticmethod
    def resize_character_emotion_sprite(input_filename: str, output_filename: str, sprite_offset: tuple[int, int],
                                        sprite_size: tuple[int, int], y_offset = 0):
        palettes = 1
        colors = 16
        ImageTools.resize(input_filename, output_filename, palettes, colors, y_crop=120, y_offset=y_offset, dithering=0.0,
                          sprite_offset=sprite_offset, sprite_size=sprite_size)
