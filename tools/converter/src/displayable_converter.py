#!/usr/bin/env python3
"""Build scene displayable BG assets (crowd, …).

Animated displayables use per-frame VRAM tile streaming (like smart_characters):
ROM holds all unique tiles; only the current frame's tiles are uploaded, with
VRAM reserved for ``max_vram_tiles`` across frames.

Run with the converter venv (``run.sh`` uses python3.13):
    source .venv/bin/activate && python3.13 src/displayable_converter.py ...
"""

from __future__ import annotations

import argparse
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from src.image_tools.image_tools import ImageTools, SCREEN_HEIGHT, SCREEN_WIDTH
from src.character_sprite.smart_character_converter import (
    BODY_TARGET_H_PX,
    _compute_render_size_px,
)
from src.displayable_specs import DISPLAYABLE_SPECS, DisplayableAssetSpec, GRIT_MAX_TILES
from src.displayable_tile_reduction import (
    count_unique_tiles,
    count_unique_tiles_grit,
    process_displayable_frames,
    read_indexed_pixels,
)
from src.displayable_asset_builder import (
    build_streaming_asset,
    patch_displayable_header,
)


def _default_palette_bmp(project_root: str) -> str:
    return os.path.join(project_root, "graphics", "common_palettes", "pal_char_bg.bmp")


def _resolve_frame_source(spec: DisplayableAssetSpec, rel_path: str,
                          sprites_dir: str, project_root: str) -> str:
    root = project_root if spec.sources_root == "project" else sprites_dir
    return os.path.join(root, rel_path)


def convert_displayable(spec: DisplayableAssetSpec,
                        sprites_dir: str,
                        project_root: str) -> None:
    palette_bmp = _default_palette_bmp(project_root)
    if not os.path.exists(palette_bmp):
        raise FileNotFoundError(palette_bmp)

    out_dir = os.path.join(project_root, "graphics", "displayables", spec.symbol)
    os.makedirs(out_dir, exist_ok=True)

    render_w, render_h = 0, BODY_TARGET_H_PX
    frame_pixels: list[bytes] = []

    for rel_path in spec.frame_sources:
        src = _resolve_frame_source(spec, rel_path, sprites_dir, project_root)
        if not os.path.exists(src):
            raise FileNotFoundError(
                f"{src}  (sources_root={spec.sources_root!r}, rel={rel_path!r})"
            )
        tmp_bmp = os.path.join(out_dir, "_tmp_frame.bmp")
        ImageTools.resize_character_background(
            src, tmp_bmp,
            y_offset=0,
            y_crop=spec.y_crop,
            face_cutout_offset=None,
            face_cutout_size=None,
            dither_method=spec.dither.method,
            dither_level=spec.dither.level,
        )
        frame_pixels.append(read_indexed_pixels(tmp_bmp))
        # Match ``resize_character_background`` (incl. ``crop_to_screen``).
        w, _ = _compute_render_size_px(src, 0, spec.y_crop)
        render_w = max(render_w, min(w, SCREEN_WIDTH))
        render_h = SCREEN_HEIGHT

    tmp = os.path.join(out_dir, "_tmp_frame.bmp")
    if os.path.exists(tmp):
        os.remove(tmp)

    processed, merged = process_displayable_frames(
        frame_pixels, palette_bmp, spec.tile_options)
    tiles_exact = count_unique_tiles(processed)
    tiles_grit = count_unique_tiles_grit(processed)
    if tiles_grit > GRIT_MAX_TILES:
        raise ValueError(
            f"{spec.symbol}: {tiles_grit} grit ROM tiles "
            f"(limit {GRIT_MAX_TILES}; exact={tiles_exact}). "
            f"Raise tile_options.reduce_threshold in displayable_specs.py "
            f"(current {spec.tile_options.reduce_threshold})."
        )

    max_vram, grit_rom, _ = build_streaming_asset(
        spec.symbol, processed, palette_bmp, out_dir, project_root,
        render_w, render_h,
    )
    if max_vram > GRIT_MAX_TILES:
        raise ValueError(
            f"{spec.symbol}: max_vram_tiles={max_vram} exceeds {GRIT_MAX_TILES}"
        )

    include_dir = os.path.join(project_root, "include", "displayables")
    os.makedirs(include_dir, exist_ok=True)
    h_path = os.path.join(include_dir, f"{spec.symbol}.h")
    patch_displayable_header(h_path, spec.symbol, {
        "ticks_per_frame": spec.ticks_per_frame,
        "frame_count": len(processed),
        "render_w_px": render_w,
        "render_h_px": render_h,
        "seen_bitmask": "DISPLAYABLE_BITMASK_NONE",
    })

    opts = spec.tile_options
    tile_note = (
        f"  max_vram={max_vram}/{GRIT_MAX_TILES}  "
        f"grit_rom={grit_rom}  tiles_exact={tiles_exact}"
    )
    if opts.reduce_threshold > 0:
        tile_note += f"  merged={merged}  threshold={opts.reduce_threshold}"
    print(
        f"wrote {spec.symbol}  maps={len(processed)}  "
        f"render={render_w}x{render_h}{tile_note}"
    )
    print(f"wrote {h_path}")
    print(f"wrote {os.path.join(project_root, 'src', 'displayables', spec.symbol + '.cpp')}")


def convert_all_displayables(sprites_dir: str, project_root: str,
                             names: list[str] | None = None) -> None:
    keys = names if names is not None else list(DISPLAYABLE_SPECS.keys())
    for key in keys:
        spec = DISPLAYABLE_SPECS.get(key)
        if spec is None:
            known = ", ".join(DISPLAYABLE_SPECS)
            raise ValueError(f"Unknown displayable: {key!r}. Known: {known}")
        print(f"Converting displayable: {key}")
        convert_displayable(spec, sprites_dir, project_root)


def main() -> None:
    parser = argparse.ArgumentParser(description="Scene displayables converter")
    parser.add_argument("--sprites", required=True,
                        help="Ren'Py game root (contains vfx/, sprites/, …)")
    parser.add_argument("--project-root", required=True)
    parser.add_argument("--name", default=None,
                        help=f"Single displayable key; default: all ({', '.join(DISPLAYABLE_SPECS)})")
    args = parser.parse_args()

    if args.name is None:
        convert_all_displayables(args.sprites, args.project_root)
    else:
        spec = DISPLAYABLE_SPECS.get(args.name)
        if spec is None:
            raise SystemExit(
                f"Unknown displayable: {args.name!r}. "
                f"Known: {', '.join(DISPLAYABLE_SPECS)}"
            )
        convert_displayable(spec, args.sprites, args.project_root)


if __name__ == "__main__":
    main()
