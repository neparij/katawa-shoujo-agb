"""
Remnants of the legacy Python implementation of tilequant.
These few remaining bits and pieces are simply for the "simple" conversion.
"""
from __future__ import annotations

from PIL import Image

from tilequant.legacy.image_converter import ImageConverter  # type: ignore
from tilequant.util import Color


def do_simple_convert(
    image: Image.Image,
    num_palettes: int,
    colors_per_palette: int,
    tile_width: int,
    tile_height: int,
    transparent_color: Color | None,
) -> Image.Image:
    legacy_convert = ImageConverter(
        image,
        tile_width=tile_width,
        tile_height=tile_height,
        transparent_color=transparent_color,
    )
    return legacy_convert.convert(
        num_palettes,
        colors_per_palette,
        color_steps=-1,
        max_colors=256,
        low_to_high=False,
        mosaic_limiting=False,
    )
