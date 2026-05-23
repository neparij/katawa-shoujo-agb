#!/usr/bin/env python3
"""Build 4bpp regular BG map cells + tile lists from qualetize indexed images."""

from __future__ import annotations

GBA_TILE = 8


def map_cells_for_size(map_w: int, map_h: int) -> tuple[int, int]:
    if map_w % GBA_TILE or map_h % GBA_TILE:
        raise ValueError(f"Map size must be multiple of 8, got {map_w}×{map_h}")
    return map_w // GBA_TILE, map_h // GBA_TILE


def cut_into_tiles(pixels: bytes, map_w: int, map_h: int) -> list[bytes]:
    map_w_cells, map_h_cells = map_cells_for_size(map_w, map_h)
    tiles: list[bytes] = []
    for ty in range(map_h_cells):
        row_base = ty * GBA_TILE * map_w
        for tx in range(map_w_cells):
            tile = bytearray(64)
            x0 = tx * GBA_TILE
            for py in range(GBA_TILE):
                src = row_base + py * map_w + x0
                tile[py * GBA_TILE:(py + 1) * GBA_TILE] = pixels[src:src + GBA_TILE]
            tiles.append(bytes(tile))
    return tiles


def write_tiles_to_pixels(
    pixels: bytearray,
    tiles: list[bytes],
    map_w: int,
    map_h: int,
) -> None:
    """Overwrite ``pixels`` with the given 8×8 tile grid."""
    map_w_cells, map_h_cells = map_cells_for_size(map_w, map_h)
    if len(tiles) != map_w_cells * map_h_cells:
        raise ValueError(
            f"Expected {map_w_cells * map_h_cells} tiles, got {len(tiles)}"
        )
    for ty in range(map_h_cells):
        row_base = ty * GBA_TILE * map_w
        for tx in range(map_w_cells):
            tile = tiles[ty * map_w_cells + tx]
            x0 = tx * GBA_TILE
            for py in range(GBA_TILE):
                src = row_base + py * map_w + x0
                pixels[src:src + GBA_TILE] = tile[py * GBA_TILE:(py + 1) * GBA_TILE]


def dedupe_tiles(all_tiles: list[bytes]) -> tuple[list[bytes], dict[bytes, int]]:
    transparent = bytes(64)
    unique: list[bytes] = [transparent]
    lookup: dict[bytes, int] = {transparent: 0}
    for t in all_tiles:
        if t not in lookup:
            lookup[t] = len(unique)
            unique.append(t)
    return unique, lookup


def dominant_palette_bank(tile: bytes) -> int:
    counts = [0] * 16
    for idx in tile:
        if idx == 0:
            continue
        counts[idx // 16] += 1
    best = 0
    best_count = -1
    for bank, count in enumerate(counts):
        if count > best_count:
            best_count = count
            best = bank
    return best


def build_variant_map_data(
    pixels: bytes,
    map_w: int,
    map_h: int,
    global_lookup: dict[bytes, int],
) -> tuple[list[int], list[int]]:
    """Return (used_global_rom_indices, map_cells_u16 with palette banks)."""
    tiles = cut_into_tiles(pixels, map_w, map_h)
    used_global: list[int] = [0]
    used_set: dict[int, int] = {0: 0}
    map_cells: list[int] = []

    for tile in tiles:
        gidx = global_lookup[tile]
        local = used_set.get(gidx)
        if local is None:
            local = len(used_global)
            used_set[gidx] = local
            used_global.append(gidx)

        if local == 0 or all(b == 0 for b in tile):
            map_cells.append(0)
        else:
            bank = dominant_palette_bank(tile)
            map_cells.append(local | (bank << 12))

    return used_global, map_cells


def global_index_to_rom(global_idx: int, tiles_per_slab: int = 1024) -> int:
    slab = global_idx // tiles_per_slab
    local = global_idx % tiles_per_slab
    return (slab << 10) | local


def used_globals_to_rom(used_global: list[int]) -> list[int]:
    return [global_index_to_rom(g) for g in used_global]
