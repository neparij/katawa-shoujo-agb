#!/usr/bin/env python3
"""Analyze tile differences between similar composite background variants.

Example (emi_sleep unsure vs weep):
  python3 src/composite_diff_analyzer.py \\
    --project-root ../.. \\
    unsure.png weep.png \\
    --names unsure weep \\
    --out-dir build/composite_diff/emi_sleep

Use ``--mode indexed`` to inspect post-qualetize tile bytes (strict).
Default ``--mode rgba`` ignores minor drift before quantize.
"""

from __future__ import annotations

import argparse
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from src.composite_preprocess import CompositeLayer, composite_layers
from src.composite_quantize import quantize_variants_shared, read_indexed_pixels
from src.composite_specs import MAP_W_PX, MAP_H_PX, HUGE_MAP_H_PX, HUGE_MAP_W_PX
from src.composite_tile_diff import (
    TileDiffMode,
    TileDiffSettings,
    analyze_tile_diffs,
    export_diff_mask_png,
    export_diff_overlay_png,
    format_tile_diff_report,
)


def _parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Find 8×8 tiles that differ between similar BG variants",
    )
    parser.add_argument("--project-root", required=True)
    parser.add_argument(
        "images",
        nargs="+",
        help="Variant PNG/JPEG paths (first = base)",
    )
    parser.add_argument(
        "--names",
        nargs="+",
        default=None,
        help="Variant names (default: file stems)",
    )
    parser.add_argument("--out-dir", default=None, help="Write overlay/mask PNGs here")
    parser.add_argument(
        "--mode",
        choices=("rgba", "indexed"),
        default="rgba",
        help="rgba = pre-qualetize regions; indexed = post-qualetize tiles",
    )
    parser.add_argument(
        "--rgba-threshold",
        type=int,
        default=8,
        help="Max RGB channel delta in 8×8 block (rgba mode)",
    )
    parser.add_argument(
        "--indexed-max-mismatch",
        type=int,
        default=0,
        help="Allow up to N differing pixels per tile (indexed mode)",
    )
    parser.add_argument("--huge", action="store_true", help="Use 512×512 map")
    parser.add_argument(
        "--canvas-w", type=int, default=1920,
        help="Source composite width (stacked / huge)",
    )
    parser.add_argument(
        "--canvas-h", type=int, default=1080,
        help="Source composite height",
    )
    parser.add_argument(
        "--huge-scale-by-height",
        action="store_true",
        help="Huge map: scale merged slab by height",
    )
    return parser.parse_args()


def main() -> None:
    args = _parse_args()
    project_root = os.path.abspath(args.project_root)
    map_w = HUGE_MAP_W_PX if args.huge else MAP_W_PX
    map_h = HUGE_MAP_H_PX if args.huge else MAP_H_PX

    names = args.names
    if names is None:
        names = [os.path.splitext(os.path.basename(p))[0] for p in args.images]
    if len(names) != len(args.images):
        raise SystemExit("--names count must match image count")

    layers = [CompositeLayer(os.path.abspath(p)) for p in args.images]
    variant_rgba = [
        composite_layers(
            [layer],
            map_w,
            map_h,
            canvas_w=args.canvas_w,
            canvas_h=args.canvas_h,
            huge=args.huge,
            huge_scale_by_height=args.huge_scale_by_height,
        )
        for layer in layers
    ]

    work_dir = os.path.join(project_root, "build", "composite_diff", names[0])
    os.makedirs(work_dir, exist_ok=True)
    indexed, _ = quantize_variants_shared(
        variant_rgba, map_w, map_h, work_dir, "_".join(names[:2])
    )
    variant_pixels = [read_indexed_pixels(img, map_w, map_h) for img in indexed]

    settings = TileDiffSettings(
        mode=TileDiffMode(args.mode),
        rgba_channel_threshold=args.rgba_threshold,
        indexed_max_mismatch_pixels=args.indexed_max_mismatch,
    )
    report = analyze_tile_diffs(
        names,
        map_w,
        map_h,
        variant_rgba=variant_rgba,
        variant_pixels=variant_pixels,
        settings=settings,
    )
    print(format_tile_diff_report(report))

    out_dir = args.out_dir or os.path.join(work_dir, "overlays")
    os.makedirs(out_dir, exist_ok=True)

    export_diff_mask_png(
        report.changed_cells,
        map_w,
        map_h,
        os.path.join(out_dir, "_diff_mask.png"),
    )
    for vi, name in enumerate(names[1:], start=1):
        cells = report.per_variant_cells[vi - 1]
        export_diff_overlay_png(
            variant_rgba[0],
            variant_rgba[vi],
            cells,
            os.path.join(out_dir, f"overlay_{name}.png"),
        )
    print(f"wrote overlays under {out_dir}")


if __name__ == "__main__":
    main()
