#!/usr/bin/env python3
"""Build streaming displayable assets (ROM tileset + per-frame maps)."""

from __future__ import annotations

import json
import os

from src.character_sprite.smart_character_converter import (
    BG_SIZE,
    MAP_H,
    MAP_W,
    TILES_PER_SLAB,
    build_body_data,
    cut_into_tiles,
    dedupe_tiles,
    split_into_slabs,
    write_slab_bmp,
    write_tiles_json,
    _emit_rle_map_array,
    _emit_uint16_array,
)
from src.displayable_tile_reduction import count_unique_tiles_grit


def build_streaming_asset(
    symbol: str,
    processed_frames: list[bytes],
    palette_bmp: str,
    out_dir: str,
    project_root: str,
    render_w: int,
    render_h: int,
) -> tuple[int, int, int]:
    """Write tile slabs + generated C++ data. Returns (max_vram, grit_rom, tiles_exact)."""

    all_tile_bytes: list[bytes] = []
    for frame in processed_frames:
        all_tile_bytes.extend(cut_into_tiles(frame))

    unique, lookup = dedupe_tiles(all_tile_bytes)
    grit_rom = count_unique_tiles_grit(processed_frames)
    tiles_exact = len(unique)

    slabs = split_into_slabs(unique)
    slab_count = len(slabs)

    for stale in os.listdir(out_dir):
        if stale == f"{symbol}.bmp" or stale == f"{symbol}.json":
            os.remove(os.path.join(out_dir, stale))
        if stale.startswith(f"{symbol}_frame_"):
            os.remove(os.path.join(out_dir, stale))

    for slab_idx, slab in enumerate(slabs):
        slab_bmp = os.path.join(out_dir, f"{symbol}_tiles_{slab_idx}.bmp")
        write_slab_bmp(slab, palette_bmp, slab_bmp)
        write_tiles_json(slab_bmp.replace(".bmp", ".json"))

    frame_rows: list[dict] = []
    max_vram = 0
    for fi, frame in enumerate(processed_frames):
        tiles = cut_into_tiles(frame)
        used_global, map_cells, _bbox = build_body_data(tiles, lookup)
        used_count = len(used_global)
        max_vram = max(max_vram, used_count)
        frame_rows.append({
            "index": fi,
            "used_global": used_global,
            "map_cells": map_cells,
            "used_count": used_count,
        })

    src_dir = os.path.join(project_root, "src", "displayables")
    os.makedirs(src_dir, exist_ok=True)
    cpp_path = os.path.join(src_dir, f"{symbol}.cpp")
    _write_asset_cpp(cpp_path, symbol, slab_count, frame_rows, max_vram, render_w, render_h)
    return max_vram, grit_rom, tiles_exact


def _write_asset_cpp(
    cpp_path: str,
    symbol: str,
    slab_count: int,
    frame_rows: list[dict],
    max_vram: int,
    render_w: int,
    render_h: int,
) -> None:
    sym_u = symbol.upper()
    with open(cpp_path, "w", encoding="utf-8") as f:
        f.write('#include "displayable_asset.h"\n')
        f.write('#include "bn_regular_bg_tiles_item.h"\n')
        for slab_idx in range(slab_count):
            f.write(
                f'#include "bn_regular_bg_tiles_items_{symbol}_tiles_{slab_idx}.h"\n'
            )
        f.write("\n")
        f.write(f"namespace ks::displayables {{\n\n")

        f.write(
            f"static const bn::regular_bg_tiles_item* const {symbol}_slabs"
            f"[{slab_count}] = {{\n"
        )
        for slab_idx in range(slab_count):
            f.write(
                f"    &bn::regular_bg_tiles_items::{symbol}_tiles_{slab_idx},\n"
            )
        f.write("};\n\n")

        f.write(f"static const displayable_tileset {symbol}_tileset = {{\n")
        f.write(f"    /* slabs      */ {symbol}_slabs,\n")
        f.write(f"    /* slab_count */ {slab_count},\n")
        f.write("};\n\n")

        for row in frame_rows:
            fi = row["index"]
            prefix = f"{symbol}_f{fi}"
            _emit_uint16_array(f, f"{prefix}_used", row["used_global"])
            _emit_rle_map_array(f, f"{prefix}_map_rle", row["map_cells"])

        f.write(f"static const displayable_frame {symbol}_frames[{len(frame_rows)}] = {{\n")
        for row in frame_rows:
            fi = row["index"]
            f.write(
                f"    {{ {symbol}_f{fi}_used, {row['used_count']}, "
                f"{symbol}_f{fi}_map_rle }},\n"
            )
        f.write("};\n\n")

        f.write(f"extern const displayable_asset {symbol}_asset = {{\n")
        f.write(f"    /* tileset        */ &{symbol}_tileset,\n")
        f.write(f"    /* frames         */ {symbol}_frames,\n")
        f.write(f"    /* frame_count    */ {len(frame_rows)},\n")
        f.write(f"    /* max_vram_tiles */ {max_vram},\n")
        f.write(f"    /* render_w_px    */ {render_w},\n")
        f.write(f"    /* render_h_px    */ {render_h},\n")
        f.write("};\n\n")
        f.write("}  // namespace ks::displayables\n")


def patch_displayable_header(
    h_path: str,
    symbol: str,
    spec_fields: dict,
) -> None:
    """Rewrite displayable meta header to reference streaming asset."""
    ticks = spec_fields["ticks_per_frame"]
    seen = spec_fields.get("seen_bitmask", "DISPLAYABLE_BITMASK_NONE")
    with open(h_path, "w", encoding="utf-8") as f:
        f.write(f"#ifndef KS_DISPLAYABLES_{symbol.upper()}_H\n")
        f.write(f"#define KS_DISPLAYABLES_{symbol.upper()}_H\n\n")
        f.write('#include "displayable_meta.h"\n')
        f.write('#include "displayable_asset.h"\n\n')
        f.write("namespace ks::displayables {\n\n")
        f.write(f"extern const displayable_asset {symbol}_asset;\n\n")
        fc = spec_fields["frame_count"]
        rw = spec_fields["render_w_px"]
        rh = spec_fields["render_h_px"]
        f.write(f"constexpr inline displayable_meta {symbol} = {{\n")
        f.write("    /* item            */ nullptr,\n")
        f.write(f"    /* asset           */ &{symbol}_asset,\n")
        f.write(f"    /* frame_count     */ {fc},\n")
        f.write(f"    /* ticks_per_frame */ {ticks},\n")
        f.write(f"    /* render_w_px     */ {rw},\n")
        f.write(f"    /* render_h_px     */ {rh},\n")
        f.write(f"    /* seen_bitmask    */ {seen},\n")
        f.write("};\n\n")
        f.write("}  // namespace ks::displayables\n\n")
        f.write(f"#endif  // KS_DISPLAYABLES_{symbol.upper()}_H\n")
