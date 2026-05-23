#!/usr/bin/env python3
"""Build composite background assets (shared qualetize + streaming tileset).

Requires:
  - qualetize (KSGBA_QUALETIZE)
  - ImageMagick (KSGBA_IMAGEMAGICK)
  - PNG sources under KSRE game root (KSRE_GAME_ROOT)

Example:
  KSRE_GAME_ROOT=/path/to/ksre-2/game \\
  python3 src/composite_converter.py --project-root ../.. --name rin_goodend
"""

from __future__ import annotations

import argparse
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from src.composite_asset_builder import (
    build_composite_asset,
    build_composite_thumbnail_source,
    patch_composite_meta_header,
    patch_composite_huge_meta_header,
    write_composite_thumbnails,
)
from src.composite_preprocess import composite_layers
from src.composite_quantize import quantize_variants_shared, read_indexed_pixels
from src.composite_specs import COMPOSITE_SPECS, CompositeAssetSpec
from src.composite_map import cut_into_tiles, dedupe_tiles
from src.composite_tile_diff import (
    TileDiffMode,
    TileDiffSettings,
    analyze_tile_diffs,
    canonicalize_static_variant_tiles,
    format_tile_diff_report,
)


def convert_composite(spec: CompositeAssetSpec, project_root: str, *, report_diff: bool = False) -> None:
    out_dir = os.path.join(project_root, "graphics", "composites")
    work_dir = os.path.join(project_root, "build", "composite_work", spec.symbol)
    os.makedirs(work_dir, exist_ok=True)

    variant_rgba = []
    variant_thumb_sources = []
    variant_names: list[str] = []
    for variant in spec.variants:
        print(f"  compositing variant {variant.name} ({len(variant.layers)} layers)")
        layer_list = list(variant.layers)
        rgba = composite_layers(
            layer_list,
            spec.map_w_px,
            spec.map_h_px,
            canvas_w=spec.composite_canvas_w,
            canvas_h=spec.composite_canvas_h,
            huge=spec.huge,
            huge_scale_by_height=spec.huge_scale_by_height,
            huge_content_h=spec.huge_content_h,
        )
        preview = os.path.join(work_dir, f"pre_quant_{variant.name}.png")
        rgba.save(preview)
        variant_rgba.append(rgba)
        variant_thumb_sources.append(
            build_composite_thumbnail_source(layer_list, rgba, spec, variant)
        )
        variant_names.append(variant.name)

    print(f"  shared qualetize ({len(variant_rgba)} variants, "
          f"{spec.map_w_px}×{spec.map_h_px} each)")
    indexed_variants, palette_ref = quantize_variants_shared(
        variant_rgba,
        spec.map_w_px,
        spec.map_h_px,
        work_dir,
        spec.symbol,
    )

    variant_pixels = [
        bytearray(read_indexed_pixels(img, spec.map_w_px, spec.map_h_px))
        for img in indexed_variants
    ]

    if report_diff and len(variant_names) > 1:
        diff_report = analyze_tile_diffs(
            variant_names,
            spec.map_w_px,
            spec.map_h_px,
            variant_rgba=variant_rgba,
            variant_pixels=[bytes(px) for px in variant_pixels],
            settings=TileDiffSettings(mode=TileDiffMode.RGBA),
        )
        print("  tile diff before canonicalize (rgba, union vs base):")
        for line in format_tile_diff_report(diff_report).splitlines():
            print(f"    {line}")

    if (
        spec.static_tile_identity_threshold is not None
        and len(variant_pixels) > 1
    ):
        rewritten = canonicalize_static_variant_tiles(
            variant_rgba,
            variant_pixels,
            spec.map_w_px,
            spec.map_h_px,
            rgba_channel_threshold=spec.static_tile_identity_threshold,
        )
        print(
            f"  canonicalize static tiles "
            f"(identity threshold={spec.static_tile_identity_threshold}): "
            f"{rewritten} cells rewritten"
        )
        if report_diff:
            diff_report = analyze_tile_diffs(
                variant_names,
                spec.map_w_px,
                spec.map_h_px,
                variant_rgba=variant_rgba,
                variant_pixels=[bytes(px) for px in variant_pixels],
                settings=TileDiffSettings(mode=TileDiffMode.RGBA),
            )
            print("  tile diff after canonicalize:")
            for line in format_tile_diff_report(diff_report).splitlines():
                print(f"    {line}")

    max_vram, unique_tiles = build_composite_asset(
        spec.symbol,
        [bytes(px) for px in variant_pixels],
        palette_ref.filename or os.path.join(work_dir, f"{spec.symbol}_palette_ref.bmp"),
        spec.map_w_px,
        spec.map_h_px,
        out_dir,
        project_root,
        variant_names,
        huge=spec.huge,
    )

    if spec.huge:
        include_dir = os.path.join(project_root, "include", "composite_huge_background_metas")
    else:
        include_dir = os.path.join(project_root, "include", "composite_background_metas")
    os.makedirs(include_dir, exist_ok=True)
    meta_names = [f"{spec.meta_prefix}_{name}" for name in variant_names]
    thumbs_dir = os.path.join(project_root, "graphics", "event", "thumbs")
    thumb_stems = write_composite_thumbnails(
        spec, variant_thumb_sources, meta_names, thumbs_dir
    )
    variant_meta = [
        (
            meta_names[idx],
            idx,
            thumb_stems[idx],
            spec.variants[idx].hash,
            spec.variants[idx].seen_bitmask or spec.seen_bitmask,
        )
        for idx in range(len(variant_names))
    ]
    h_path = os.path.join(include_dir, f"{spec.symbol}.h")
    if spec.huge:
        patch_composite_huge_meta_header(h_path, spec.symbol, variant_meta, spec.seen_bitmask)
        stale_regular = os.path.join(
            project_root, "include", "composite_background_metas", f"{spec.symbol}.h"
        )
        if os.path.exists(stale_regular):
            os.remove(stale_regular)
    else:
        patch_composite_meta_header(h_path, spec.symbol, variant_meta, spec.seen_bitmask)

    print(
        f"wrote {spec.symbol}: variants={len(variant_names)} "
        f"unique_tiles={unique_tiles} max_vram={max_vram} "
        f"map={spec.map_w_px}×{spec.map_h_px}"
    )
    print(f"wrote {h_path}")
    print(f"wrote {os.path.join(project_root, 'src', 'composite_backgrounds', f'composite_{spec.symbol}.cpp')}")
    print(f"grit inputs under {out_dir} ({spec.symbol}_*)")


def main() -> None:
    parser = argparse.ArgumentParser(description="Composite background converter")
    parser.add_argument("--project-root", required=True)
    parser.add_argument(
        "--name",
        default=None,
        help=f"Asset key (default: all). Known: {', '.join(COMPOSITE_SPECS)}",
    )
    parser.add_argument(
        "--report-diff",
        action="store_true",
        help="Print pre-qualetize tile diff stats (union vs first variant)",
    )
    args = parser.parse_args()
    project_root = os.path.abspath(args.project_root)

    if args.name is None:
        for key in COMPOSITE_SPECS:
            print(f"Converting composite: {key}")
            convert_composite(COMPOSITE_SPECS[key], project_root, report_diff=args.report_diff)
    else:
        spec = COMPOSITE_SPECS.get(args.name)
        if spec is None:
            raise SystemExit(
                f"Unknown composite {args.name!r}. "
                f"Known: {', '.join(COMPOSITE_SPECS)}"
            )
        convert_composite(spec, project_root, report_diff=args.report_diff)


if __name__ == "__main__":
    main()
