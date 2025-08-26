import os
import json
from typing import List

from PIL import Image, ImageOps
# import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode


class ImageTools:
    TRANSPARENT_COLOR = (255, 0, 253)

    @staticmethod
    def resize(input_filename: str, output_filename: str, palettes: int, colors: int,
               y_crop: int = 0,
               y_offset: int = 0,
               dithering: float = 1.0,
               remove_size: tuple[int, int] | None = None,
               remove_offset: tuple[int, int] | None = None,
               sprite_offset: tuple[int, int] | None = None,
               sprite_size: tuple[int, int] | None = None,
               num_color_cluster_passes: int = 256,
               num_tile_cluster_passes: int = 256,
               use_sample_palette: str | None = None,
               add_boundary_pixels: bool = False,
               target_height: int = 160,
               target_size: tuple[int, int] = (256, 256),
               tint: tuple[int, int, int] | None = None):

        if use_sample_palette:
            sample_palette_image = Image.open(use_sample_palette)
            # ImageTools.TRANSPARENT_COLOR = tuple(sample_palette_image.getpalette()[:3])

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

        # if add_boundary_pixels:
        #     if not use_sample_palette:
        #         raise Exception("Boundary pixels can only be added when using a sample palette.")
        #     index = 2
        #     sample_palette_data = sample_palette_image.palette.palette  # Raw palette data as bytes
        #     non_transparent_color = tuple(sample_palette_data[index * 3:index * 3 + 3])  # Get RGB values
        #     canvas.putpixel((0, 0), non_transparent_color)
        #     canvas.putpixel((511, 0), non_transparent_color)
        #     canvas.putpixel((0, 255), non_transparent_color)
        #     canvas.putpixel((511, 255), non_transparent_color)

        if not use_sample_palette:
            print(f"Quantizing: {output_filename}")
            converter = Tilequant(canvas, ImageTools.TRANSPARENT_COLOR)
            quantized = converter.convert(num_palettes=palettes, colors_per_palette=colors,
                                          dithering_mode=DitheringMode.FLOYDSTEINBERG if dithering > 0 else DitheringMode.NONE,
                                          dithering_level=dithering,
                                          num_color_cluster_passes=num_color_cluster_passes, num_tile_cluster_passes=num_tile_cluster_passes)
            quantized.save(output_filename, format="BMP")
            print(f"Resized, Quantized and saved: {output_filename}")
        else:
            print(f"Open sample pallette image: {use_sample_palette}")
            paletted_image = Image.new('RGB', canvas.size)
            paletted_image.paste(canvas)
            # paletted_image.putpalette(sample_palette_image.getpalette())
            paletted_image = paletted_image.quantize(palette=sample_palette_image, method=Image.Quantize.LIBIMAGEQUANT, dither=Image.Dither.NONE)
            # paletted_image = paletted_image.quantize(palette=sample_palette_image, method=Image.Quantize.LIBIMAGEQUANT, dither=Image.Dither.FLOYDSTEINBERG)
            paletted_image.save(output_filename, format="BMP")
            print(f"Resized, Converted with sample palette and saved: {output_filename}")
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
        palettes = 4 if quantize else 1
        colors = 16 if quantize else 256
        ImageTools.resize(input_filename, output_filename, palettes, colors)

    @staticmethod
    def resize_character_background(input_filename: str, output_filename: str, remove_size: tuple[int, int], remove_offset: tuple[int, int], y_offset = 0, tint: tuple[int, int, int] | None = None):
        palettes = 2
        colors = 16
        ImageTools.resize(input_filename, output_filename, palettes, colors, y_crop=120, y_offset=y_offset,
                          remove_size=remove_size, remove_offset=remove_offset,
                          num_color_cluster_passes=256, num_tile_cluster_passes=256,
                          use_sample_palette="/Users/n.laptev/development/gba/katawa/tools/converter/assets/sample_character_bg_palette.bmp",
                          add_boundary_pixels=True, tint=tint)

    @staticmethod
    def resize_character_thumbnail(input_filename: str, output_filename: str, y_offset=0, tint: tuple[int, int, int] | None = None):
        palettes = 2
        colors = 16
        ImageTools.resize(input_filename, output_filename, palettes, colors, y_crop=120, y_offset=y_offset,
                          target_height=32, target_size=(32, 32),
                          num_color_cluster_passes=256, num_tile_cluster_passes=256,
                          use_sample_palette="/Users/n.laptev/development/gba/katawa/tools/converter/assets/sample_character_bg_palette.bmp",
                          add_boundary_pixels=True, tint=tint)

    @staticmethod
    def resize_character_emotion_sprite(input_filename: str, output_filename: str, sprite_offset: tuple[int, int],
                                        sprite_size: tuple[int, int], y_offset = 0, use_sample_palette = None, tint: tuple[int, int, int] | None = None):
        palettes = 1
        colors = 16
        ImageTools.resize(input_filename, output_filename, palettes, colors, y_crop=120, y_offset=y_offset,
                          dithering=0.0,
                          sprite_offset=sprite_offset, sprite_size=sprite_size,
                          num_color_cluster_passes=16, num_tile_cluster_passes=256,
                          use_sample_palette="/Users/n.laptev/development/gba/katawa/tools/converter/assets/sample_character_spr_palette.bmp",
                          tint=tint)
