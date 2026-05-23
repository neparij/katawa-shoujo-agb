#!/usr/bin/env python3
"""Shared qualetize pass for composite background variants.

All variants are stacked into one tall RGBA canvas, qualetize runs once so
every variant shares the same 4bpp_manual palette, then strips are split
back into per-variant indexed BMPs.
"""

from __future__ import annotations

import os
import subprocess
from dataclasses import dataclass

import numpy as np
from PIL import Image

IMAGEMAGICK = os.environ.get(
    "KSGBA_IMAGEMAGICK",
    os.environ.get("IMAGEMAGICK", "magick"),
)
QUALETIZE = os.environ.get(
    "KSGBA_QUALETIZE",
    "/Users/n.laptev/development/gba/qualetize/release/qualetize",
)

# Match tools/bgs_resize/src/resize.py defaults for event backgrounds.
QUALETIZE_COLOURSPACE = "ycbcr-psy"
QUALETIZE_DITHER_METHOD = "floyd"
QUALETIZE_DITHER_LEVEL = 1.0
QUALETIZE_PALETTES_COUNT = 8
QUALETIZE_PALETTE_COLORS = 16
QUALETIZE_BITS_PER_COLOR = 5
QUALETIZE_COLOR_0_IS_CLEAR = True
QUALETIZE_PASSES_COLOUR = (2 ** 12) * QUALETIZE_PALETTES_COUNT
QUALETIZE_PASSES_TILES = (2 ** 12) * QUALETIZE_PALETTES_COUNT


@dataclass(frozen=True)
class QualetizeSettings:
    palettes_count: int = QUALETIZE_PALETTES_COUNT
    colors_per_palette: int = QUALETIZE_PALETTE_COLORS
    dither_method: str = QUALETIZE_DITHER_METHOD
    dither_level: float = QUALETIZE_DITHER_LEVEL


def _rgba_to_bmp4(rgba: Image.Image, bmp_path: str) -> None:
    png_path = bmp_path.replace(".bmp", "_rgba.png")
    rgba.save(png_path, format="PNG")
    command = [
        IMAGEMAGICK,
        png_path,
        "-define",
        "bmp:format=bmp4",
        bmp_path,
    ]
    subprocess.check_call(command)
    os.remove(png_path)


def _run_qualetize(input_bmp: str, output_bmp: str, settings: QualetizeSettings) -> None:
    command = [
        QUALETIZE,
        input_bmp,
        output_bmp,
        f"-npal:{settings.palettes_count}",
        f"-cols:{settings.colors_per_palette}",
        f"-tilepasses:{QUALETIZE_PASSES_TILES}",
        f"-colourpasses:{QUALETIZE_PASSES_COLOUR}",
        f"-col0isclear:{'y' if QUALETIZE_COLOR_0_IS_CLEAR else 'n'}",
        f"-rgba:{QUALETIZE_BITS_PER_COLOR}{QUALETIZE_BITS_PER_COLOR}"
        f"{QUALETIZE_BITS_PER_COLOR}1",
        f"-colspace:{QUALETIZE_COLOURSPACE}",
        f"-dither:{settings.dither_method},{settings.dither_level}",
    ]
    print("Running:", " ".join(command))
    subprocess.check_call(command)


def quantize_variants_shared(
    variant_rgba: list[Image.Image],
    map_w: int,
    map_h: int,
    work_dir: str,
    symbol: str,
    settings: QualetizeSettings | None = None,
) -> tuple[list[Image.Image], Image.Image]:
    """Return per-variant indexed BMPs (P mode) and the master palette source.

    ``variant_rgba`` must already be ``map_w × map_h`` RGBA canvases.
    They are stacked vertically (map_w × map_h × N) for a single qualetize
    call, then split back.
    """
    if settings is None:
        settings = QualetizeSettings()

    for i, img in enumerate(variant_rgba):
        if img.size != (map_w, map_h):
            raise ValueError(
                f"variant {i}: expected {map_w}×{map_h}, got {img.size}"
            )
        if img.mode != "RGBA":
            raise ValueError(f"variant {i}: expected RGBA, got {img.mode}")

    os.makedirs(work_dir, exist_ok=True)
    stack_h = map_h * len(variant_rgba)
    stack = Image.new("RGBA", (map_w, stack_h), (0, 0, 0, 0))
    for i, img in enumerate(variant_rgba):
        stack.paste(img, (0, i * map_h))

    stack_bmp = os.path.join(work_dir, f"{symbol}_quantize_stack.bmp")
    stack_out_bmp = os.path.join(work_dir, f"{symbol}_quantize_stack_out.bmp")
    _rgba_to_bmp4(stack, stack_bmp)
    _run_qualetize(stack_bmp, stack_out_bmp, settings)

    master = Image.open(stack_out_bmp)
    if master.mode != "P":
        master = master.convert("P")
    palette = master.getpalette()
    if palette is None:
        raise RuntimeError(f"No palette in qualetize output: {stack_out_bmp}")

    indexed_variants: list[Image.Image] = []
    for i in range(len(variant_rgba)):
        y0 = i * map_h
        strip = master.crop((0, y0, map_w, y0 + map_h))
        out_path = os.path.join(work_dir, f"{symbol}_variant_{i}.bmp")
        strip.save(out_path, format="BMP")
        indexed_variants.append(Image.open(out_path).convert("P"))

    palette_ref = Image.new("P", (map_w, map_h))
    palette_ref.putpalette(palette)
    palette_ref_path = os.path.join(work_dir, f"{symbol}_palette_ref.bmp")
    # Copy pixels from first variant so grit sees the shared palette in use.
    palette_ref.paste(indexed_variants[0])
    palette_ref.save(palette_ref_path, format="BMP")

    os.remove(stack_bmp)
    return indexed_variants, Image.open(palette_ref_path)


def read_indexed_pixels(img: Image.Image, map_w: int, map_h: int) -> bytes:
    if img.mode != "P":
        img = img.convert("P")
    if img.size != (map_w, map_h):
        raise ValueError(f"Expected {map_w}×{map_h}, got {img.size}")
    return img.tobytes()


def write_bg_palette_json(json_path: str, colors_count: int) -> None:
    import json

    with open(json_path, "w", encoding="utf-8") as f:
        json.dump({
            "type": "bg_palette",
            "bpp_mode": "bpp_4",
            "colors_count": colors_count,
            "compression": "none",
        }, f, indent=4)
        f.write("\n")


def write_tiles_slab_json(json_path: str, *, compression: str = "auto_no_huffman") -> None:
    import json

    with open(json_path, "w", encoding="utf-8") as f:
        json.dump({
            "type": "regular_bg_tiles",
            "bpp_mode": "bpp_4",
            "compression": compression,
        }, f, indent=4)
        f.write("\n")
