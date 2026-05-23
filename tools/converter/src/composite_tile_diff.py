#!/usr/bin/env python3
"""Detect differing 8×8 tiles between similar composite background variants.

Two comparison modes:

* **rgba** — on pre-qualetize canvases; tolerates small colour drift and
  ignores fully transparent 8×8 blocks. Use this to find *regions* that
  actually changed (faces, expressions, …).
* **indexed** — on post-qualetize tile bytes; exact or fuzzy pixel count.
  Use this to see what the GBA build will store after shared qualetize.

For backgrounds that differ only in small areas (e.g. emi_sleep unsure/weep)
register each full image as a single-layer ``CompositeVariantSpec``; shared
qualetize plus ``static_tile_identity_threshold`` canonicalization (default 8)
reuse base indexed tiles in unchanged 8×8 cells so Floyd dither does not inflate
ROM. This module helps inspect savings and optionally export diff overlays for
manual layer authoring.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum

import numpy as np
from PIL import Image

from src.composite_map import (
    GBA_TILE,
    cut_into_tiles,
    dedupe_tiles,
    map_cells_for_size,
    write_tiles_to_pixels,
)

# Max per-channel RGBA delta (0–255) in an 8×8 block to treat a cell as
# unchanged vs the base variant. Matches TileDiffSettings.rgba_channel_threshold.
DEFAULT_STATIC_TILE_IDENTITY_THRESHOLD = 8


class TileDiffMode(str, Enum):
    RGBA = "rgba"
    INDEXED = "indexed"


@dataclass(frozen=True)
class TileDiffSettings:
    mode: TileDiffMode = TileDiffMode.RGBA
    # rgba: max per-channel delta (0–255) in an 8×8 block to count as changed.
    rgba_channel_threshold: int = DEFAULT_STATIC_TILE_IDENTITY_THRESHOLD
    # indexed: max differing pixels inside 64-byte tile (0 = exact match).
    indexed_max_mismatch_pixels: int = 0
    # Skip blocks where every pixel is transparent in all variants.
    ignore_fully_transparent: bool = True
    transparent_alpha: int = 10


@dataclass
class TileDiffReport:
    map_w: int
    map_h: int
    variant_names: list[str]
    base_name: str
    settings: TileDiffSettings
    # Per map-cell (tx, ty): True if any variant differs from base.
    changed_cells: list[list[bool]] = field(default_factory=list)
    # Per variant index (skip base): set of (tx, ty) changed vs base.
    per_variant_cells: list[set[tuple[int, int]]] = field(default_factory=list)
    # Post-quantize stats when indexed pixels supplied.
    indexed_exact_diff_vs_base: list[int] = field(default_factory=list)
    indexed_unique_tiles: int = 0
    indexed_dedupe_savings: int = 0

    @property
    def cells_w(self) -> int:
        return len(self.changed_cells[0]) if self.changed_cells else 0

    @property
    def cells_h(self) -> int:
        return len(self.changed_cells)

    @property
    def changed_tile_count(self) -> int:
        return sum(1 for row in self.changed_cells for cell in row if cell)

    @property
    def static_tile_count(self) -> int:
        return self.cells_w * self.cells_h - self.changed_tile_count


def _block_fully_transparent(block: np.ndarray, alpha_limit: int) -> bool:
    return bool(np.all(block[:, :, 3] <= alpha_limit))


def _rgba_blocks_differ(
    base: np.ndarray,
    other: np.ndarray,
    settings: TileDiffSettings,
) -> bool:
    if settings.ignore_fully_transparent:
        if _block_fully_transparent(base, settings.transparent_alpha):
            if _block_fully_transparent(other, settings.transparent_alpha):
                return False
    diff = np.abs(base.astype(np.int16) - other.astype(np.int16))
    return int(diff[:, :, :3].max()) > settings.rgba_channel_threshold


def _indexed_tiles_differ(tile_a: bytes, tile_b: bytes, max_mismatch: int) -> bool:
    if max_mismatch <= 0:
        return tile_a != tile_b
    mismatches = sum(1 for a, b in zip(tile_a, tile_b) if a != b)
    return mismatches > max_mismatch


def _compare_rgba_variants(
    variant_rgba: list[Image.Image],
    settings: TileDiffSettings,
) -> tuple[list[list[bool]], list[set[tuple[int, int]]]]:
    arrays = [np.array(img.convert("RGBA")) for img in variant_rgba]
    map_h, map_w = arrays[0].shape[:2]
    cells_w, cells_h = map_cells_for_size(map_w, map_h)
    changed = [[False] * cells_w for _ in range(cells_h)]
    per_variant: list[set[tuple[int, int]]] = []

    for vi in range(1, len(arrays)):
        cells: set[tuple[int, int]] = set()
        for ty in range(cells_h):
            y0 = ty * GBA_TILE
            for tx in range(cells_w):
                x0 = tx * GBA_TILE
                base_block = arrays[0][y0:y0 + GBA_TILE, x0:x0 + GBA_TILE]
                other_block = arrays[vi][y0:y0 + GBA_TILE, x0:x0 + GBA_TILE]
                if _rgba_blocks_differ(base_block, other_block, settings):
                    changed[ty][tx] = True
                    cells.add((tx, ty))
        per_variant.append(cells)
    return changed, per_variant


def _compare_indexed_variants(
    variant_pixels: list[bytes],
    map_w: int,
    map_h: int,
    settings: TileDiffSettings,
) -> tuple[list[list[bool]], list[set[tuple[int, int]]], list[int]]:
    all_tiles = [cut_into_tiles(px, map_w, map_h) for px in variant_pixels]
    cells_w, cells_h = map_cells_for_size(map_w, map_h)
    changed = [[False] * cells_w for _ in range(cells_h)]
    per_variant: list[set[tuple[int, int]]] = []
    exact_counts: list[int] = []

    base_tiles = all_tiles[0]
    for vi in range(1, len(all_tiles)):
        cells: set[tuple[int, int]] = set()
        diff_count = 0
        for idx, (base_tile, other_tile) in enumerate(zip(base_tiles, all_tiles[vi])):
            if _indexed_tiles_differ(
                base_tile, other_tile, settings.indexed_max_mismatch_pixels
            ):
                diff_count += 1
                tx = idx % cells_w
                ty = idx // cells_w
                changed[ty][tx] = True
                cells.add((tx, ty))
        per_variant.append(cells)
        exact_counts.append(diff_count)
    return changed, per_variant, exact_counts


def analyze_tile_diffs(
    variant_names: list[str],
    map_w: int,
    map_h: int,
    *,
    variant_rgba: list[Image.Image] | None = None,
    variant_pixels: list[bytes] | None = None,
    settings: TileDiffSettings | None = None,
) -> TileDiffReport:
    """Compare variants against the first (base) entry."""
    if len(variant_names) < 2:
        raise ValueError("Need at least two variants (base + one other)")
    if settings is None:
        settings = TileDiffSettings()

    report = TileDiffReport(
        map_w=map_w,
        map_h=map_h,
        variant_names=list(variant_names),
        base_name=variant_names[0],
        settings=settings,
    )

    if settings.mode == TileDiffMode.RGBA:
        if variant_rgba is None:
            raise ValueError("rgba mode requires variant_rgba")
        if len(variant_rgba) != len(variant_names):
            raise ValueError("variant_rgba length mismatch")
        changed, per_variant = _compare_rgba_variants(variant_rgba, settings)
        report.changed_cells = changed
        report.per_variant_cells = per_variant
    else:
        if variant_pixels is None:
            raise ValueError("indexed mode requires variant_pixels")
        if len(variant_pixels) != len(variant_names):
            raise ValueError("variant_pixels length mismatch")
        changed, per_variant, exact_counts = _compare_indexed_variants(
            variant_pixels, map_w, map_h, settings
        )
        report.changed_cells = changed
        report.per_variant_cells = per_variant
        report.indexed_exact_diff_vs_base = exact_counts

    if variant_pixels is not None:
        all_tile_bytes: list[bytes] = []
        for px in variant_pixels:
            all_tile_bytes.extend(cut_into_tiles(px, map_w, map_h))
        unique, _ = dedupe_tiles(all_tile_bytes)
        report.indexed_unique_tiles = len(unique)
        report.indexed_dedupe_savings = len(all_tile_bytes) - len(unique)

    return report


def export_diff_overlay_png(
    base_rgba: Image.Image,
    variant_rgba: Image.Image,
    changed_cells: set[tuple[int, int]],
    output_path: str,
) -> None:
    """Write variant pixels only in changed 8×8 cells; rest transparent."""
    base = base_rgba.convert("RGBA")
    variant = variant_rgba.convert("RGBA")
    if base.size != variant.size:
        raise ValueError(f"Size mismatch: {base.size} vs {variant.size}")

    out = Image.new("RGBA", base.size, (0, 0, 0, 0))
    for tx, ty in changed_cells:
        x0 = tx * GBA_TILE
        y0 = ty * GBA_TILE
        block = variant.crop((x0, y0, x0 + GBA_TILE, y0 + GBA_TILE))
        out.paste(block, (x0, y0))
    out.save(output_path, format="PNG")


def export_diff_mask_png(
    changed_cells: list[list[bool]],
    map_w: int,
    map_h: int,
    output_path: str,
    *,
    scale: int = 2,
) -> None:
    """Debug visualisation: highlight changed 8×8 cells."""
    cells_w, cells_h = map_cells_for_size(map_w, map_h)
    img = Image.new("RGBA", (cells_w * scale, cells_h * scale), (0, 0, 0, 0))
    pixels = img.load()
    for ty, row in enumerate(changed_cells):
        for tx, changed in enumerate(row):
            if not changed:
                continue
            for py in range(scale):
                for px in range(scale):
                    pixels[tx * scale + px, ty * scale + py] = (255, 64, 64, 200)
    img = img.resize((map_w, map_h), resample=Image.Resampling.NEAREST)
    img.save(output_path, format="PNG")


def canonicalize_static_variant_tiles(
    variant_rgba: list[Image.Image],
    variant_pixels: list[bytearray],
    map_w: int,
    map_h: int,
    *,
    rgba_channel_threshold: int = DEFAULT_STATIC_TILE_IDENTITY_THRESHOLD,
) -> int:
    """Reuse base indexed tiles in cells that are unchanged on RGBA canvases.

    Qualetize dither can make byte-identical tiles diverge across near-duplicate
    variants; this runs after shared qualetize and before global dedupe.

    Returns the number of 8×8 cells rewritten across all non-base variants.
    """
    if len(variant_rgba) < 2:
        return 0
    if len(variant_rgba) != len(variant_pixels):
        raise ValueError("variant_rgba and variant_pixels length mismatch")

    settings = TileDiffSettings(rgba_channel_threshold=rgba_channel_threshold)
    _, per_variant = _compare_rgba_variants(variant_rgba, settings)

    base_tiles = cut_into_tiles(bytes(variant_pixels[0]), map_w, map_h)
    cells_w, cells_h = map_cells_for_size(map_w, map_h)
    rewritten = 0

    for vi in range(1, len(variant_pixels)):
        changed = per_variant[vi - 1]
        tiles = cut_into_tiles(bytes(variant_pixels[vi]), map_w, map_h)
        for ty in range(cells_h):
            for tx in range(cells_w):
                if (tx, ty) in changed:
                    continue
                idx = ty * cells_w + tx
                if tiles[idx] != base_tiles[idx]:
                    tiles[idx] = base_tiles[idx]
                    rewritten += 1
        write_tiles_to_pixels(variant_pixels[vi], tiles, map_w, map_h)

    return rewritten


def format_tile_diff_report(report: TileDiffReport) -> str:
    lines = [
        f"base: {report.base_name}",
        f"variants: {', '.join(report.variant_names)}",
        f"mode: {report.settings.mode.value}",
        f"map: {report.map_w}×{report.map_h} ({report.cells_w}×{report.cells_h} cells)",
        f"changed cells (union vs base): {report.changed_tile_count} / "
        f"{report.cells_w * report.cells_h}",
        f"static cells: {report.static_tile_count}",
    ]
    for i, name in enumerate(report.variant_names[1:], start=1):
        count = len(report.per_variant_cells[i - 1])
        lines.append(f"  vs {name}: {count} changed cells")
    if report.indexed_exact_diff_vs_base:
        for i, name in enumerate(report.variant_names[1:], start=1):
            lines.append(
                f"  indexed tile diff vs base ({name}): "
                f"{report.indexed_exact_diff_vs_base[i - 1]}"
            )
    if report.indexed_unique_tiles:
        total = report.cells_w * report.cells_h * len(report.variant_names)
        lines.append(
            f"indexed ROM: {report.indexed_unique_tiles} unique tiles "
            f"(dedupe saves {report.indexed_dedupe_savings} of {total})"
        )
    return "\n".join(lines)
