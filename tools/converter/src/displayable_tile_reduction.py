#!/usr/bin/env python3
"""Tile deduplication and optional MSE-based reduction for scene displayables."""

from __future__ import annotations

from dataclasses import dataclass
from typing import Iterable

import numpy as np
from numba import njit
from PIL import Image

BG_SIZE = 256
GBA_TILE = 8
TILE_PIXELS = GBA_TILE * GBA_TILE
TILE_RGBA = TILE_PIXELS * 4
MAP_W = MAP_H = BG_SIZE // GBA_TILE


# ---------------------------------------------------------------------------
# Numba kernels (palette + RGBA MSE with early threshold exit)
# ---------------------------------------------------------------------------

@njit(cache=False)  # cache=True breaks when module is imported as src.* vs bare name
def _rgba_mse_flat(a: np.ndarray, b: np.ndarray, thresh: float) -> float:
    err = 0.0
    limit = thresh * TILE_RGBA
    for i in range(TILE_RGBA):
        d = int(a[i]) - int(b[i])
        err += d * d
        if err > limit:
            return 1e18
    return err / TILE_RGBA


@njit(cache=False)  # cache=True breaks when module is imported as src.* vs bare name
def _indices_mse_flat(tile: np.ndarray, rep: np.ndarray, pal: np.ndarray,
                      thresh: float) -> float:
    err = 0.0
    limit = thresh * TILE_RGBA
    for i in range(TILE_PIXELS):
        ti = int(tile[i])
        ri = int(rep[i])
        for c in range(4):
            d = int(pal[ti, c]) - int(pal[ri, c])
            err += d * d
            if err > limit:
                return 1e18
    return err / TILE_RGBA


@njit(cache=False)  # cache=True breaks when module is imported as src.* vs bare name
def _tile_defect(indices: np.ndarray) -> int:
    counts = np.zeros(256, np.int32)
    for i in range(TILE_PIXELS):
        counts[indices[i]] += 1
    mode = 0
    best = 0
    for i in range(256):
        if counts[i] > best:
            best = counts[i]
            mode = i
    defect = 0
    for i in range(TILE_PIXELS):
        if indices[i] != mode:
            defect += 1
    return defect


@njit(cache=False)  # cache=True breaks when module is imported as src.* vs bare name
def _orient_indices(tile: np.ndarray, omap: np.ndarray) -> np.ndarray:
    out = np.empty(TILE_PIXELS, np.uint8)
    for i in range(TILE_PIXELS):
        out[i] = tile[omap[i]]
    return out


@njit(cache=False)  # cache=True breaks when module is imported as src.* vs bare name
def _orient_rgba_flat(colors: np.ndarray, omap: np.ndarray) -> np.ndarray:
    out = np.empty(TILE_RGBA, np.uint8)
    for i in range(TILE_PIXELS):
        sb = omap[i] * 4
        db = i * 4
        out[db] = colors[sb]
        out[db + 1] = colors[sb + 1]
        out[db + 2] = colors[sb + 2]
        out[db + 3] = colors[sb + 3]
    return out


@njit(cache=False)  # cache=True breaks when module is imported as src.* vs bare name
def _blur_tile_rgba(colors: np.ndarray) -> np.ndarray:
    """3×3 box blur on an 8×8×4 tile."""
    out = np.empty(TILE_RGBA, np.uint8)
    for y in range(GBA_TILE):
        for x in range(GBA_TILE):
            acc0 = acc1 = acc2 = acc3 = 0
            count = 0
            for dy in range(-1, 2):
                ny = y + dy
                if ny < 0 or ny >= GBA_TILE:
                    continue
                for dx in range(-1, 2):
                    nx = x + dx
                    if nx < 0 or nx >= GBA_TILE:
                        continue
                    base = (ny * GBA_TILE + nx) * 4
                    acc0 += colors[base]
                    acc1 += colors[base + 1]
                    acc2 += colors[base + 2]
                    acc3 += colors[base + 3]
                    count += 1
            dst = (y * GBA_TILE + x) * 4
            out[dst] = acc0 // count
            out[dst + 1] = acc1 // count
            out[dst + 2] = acc2 // count
            out[dst + 3] = acc3 // count
    return out


@njit(cache=False)  # cache=True breaks when module is imported as src.* vs bare name
def _expand_tile_rgba(tile: np.ndarray, pal: np.ndarray) -> np.ndarray:
    out = np.empty(TILE_RGBA, np.uint8)
    for i in range(TILE_PIXELS):
        idx = tile[i]
        base = i * 4
        out[base] = pal[idx, 0]
        out[base + 1] = pal[idx, 1]
        out[base + 2] = pal[idx, 2]
        out[base + 3] = pal[idx, 3]
    return out


@njit(cache=False)  # cache=True breaks when module is imported as src.* vs bare name
def _write_rep(indexed: np.ndarray, ty: int, tx: int, stride: int,
               rep: np.ndarray, omap: np.ndarray) -> None:
    y0 = ty * GBA_TILE
    x0 = tx * GBA_TILE
    for y in range(GBA_TILE):
        row = (y0 + y) * stride + x0
        for x in range(GBA_TILE):
            indexed[row + x] = rep[omap[y * GBA_TILE + x]]


@njit(cache=False)  # cache=True breaks when module is imported as src.* vs bare name
def _medoid_pick(members: np.ndarray, n: int, pal: np.ndarray) -> int:
    best_i = 0
    best_sum = 1e18
    for i in range(n):
        total = 0.0
        for j in range(n):
            if i != j:
                total += _indices_mse_flat(members[i], members[j], pal, 1e9)
        if total < best_sum:
            best_sum = total
            best_i = i
    return best_i


def _find_best_rep(tile: np.ndarray, pal: np.ndarray,
                   rep_indices_list: list[np.ndarray],
                   rep_blur_list: list[np.ndarray],
                   oriented_blurs: np.ndarray,
                   orient_maps: np.ndarray,
                   thresh: float) -> tuple[int, float, int, int, int] | None:
    """(exact_mse, rep_defect, rep_idx, orient_idx) or None."""
    best: tuple[int, float, int, float, int, int] | None = None
    n_orient = orient_maps.shape[0]

    for rep_idx, rep in enumerate(rep_indices_list):
        rep_blur = rep_blur_list[rep_idx]
        rep_defect = _tile_defect(rep)
        for oi in range(n_orient):
            blur_mse = _rgba_mse_flat(rep_blur, oriented_blurs[oi], thresh)
            if blur_mse > thresh:
                continue
            oriented = _orient_indices(tile, orient_maps[oi])
            exact_mse = _indices_mse_flat(oriented, rep, pal, thresh)
            exact_i = 0 if exact_mse == 0.0 else 1
            key = (exact_i, exact_mse, rep_defect, blur_mse)
            if best is None or key < (best[0], best[1], best[2], best[3]):
                best = (exact_i, exact_mse, rep_defect, blur_mse, rep_idx, oi)
    if best is None:
        return None
    return best[1], best[2], best[4], best[5]


# ---------------------------------------------------------------------------
# NumPy helpers
# ---------------------------------------------------------------------------

def read_indexed_pixels(bmp_path: str) -> bytes:
    img = Image.open(bmp_path)
    if img.mode != "P":
        img = img.convert("P")
    if img.size != (BG_SIZE, BG_SIZE):
        raise ValueError(f"Expected {BG_SIZE}×{BG_SIZE}, got {img.size} for {bmp_path}")
    return img.tobytes()


def _load_palette_rgba(palette_bmp: str) -> np.ndarray:
    raw = Image.open(palette_bmp).getpalette() or []
    pal = np.zeros((256, 4), np.uint8)
    n = min(256, len(raw) // 3)
    for i in range(n):
        pal[i, 0] = raw[i * 3]
        pal[i, 1] = raw[i * 3 + 1]
        pal[i, 2] = raw[i * 3 + 2]
        pal[i, 3] = 255
    return pal


def _cut_tiles(indexed: np.ndarray, width: int, height: int) -> np.ndarray:
    """(num_tiles, 64) uint8 tile indices."""
    img = indexed.reshape(height, width)
    ty = height // GBA_TILE
    tx = width // GBA_TILE
    blocks = img.reshape(ty, GBA_TILE, tx, GBA_TILE).transpose(0, 2, 1, 3)
    return blocks.reshape(ty * tx, TILE_PIXELS).copy()


def _paste_tiles(indexed: np.ndarray, width: int, height: int,
                 tiles: np.ndarray) -> None:
    ty = height // GBA_TILE
    tx = width // GBA_TILE
    blocks = tiles.reshape(ty, tx, GBA_TILE, GBA_TILE).transpose(0, 2, 1, 3)
    indexed.reshape(height, width)[:] = blocks.reshape(ty * GBA_TILE, tx * GBA_TILE)


def _orientation_maps(allow_flip_x: bool, allow_flip_y: bool) -> np.ndarray:
    specs = [(False, False)]
    if allow_flip_x:
        specs.append((True, False))
    if allow_flip_y:
        specs.append((False, True))
    if allow_flip_x and allow_flip_y:
        specs.append((True, True))
    maps = np.empty((len(specs), TILE_PIXELS), np.int32)
    for oi, (flip_x, flip_y) in enumerate(specs):
        m = maps[oi]
        for y in range(GBA_TILE):
            for x in range(GBA_TILE):
                sx = GBA_TILE - 1 - x if flip_x else x
                sy = GBA_TILE - 1 - y if flip_y else y
                m[y * GBA_TILE + x] = sy * GBA_TILE + sx
    return maps


def _tile_order(tiles_x: int, tiles_y: int) -> np.ndarray:
    cx = (tiles_x - 1) / 2.0
    cy = (tiles_y - 1) / 2.0
    n = tiles_y * tiles_x
    coords = np.empty((n, 3), np.float64)
    k = 0
    for ty in range(tiles_y):
        for tx in range(tiles_x):
            coords[k, 0] = tx
            coords[k, 1] = ty
            coords[k, 2] = (tx - cx) ** 2 + (ty - cy) ** 2
            k += 1
    order = np.argsort(coords[:, 2])
    return coords[order].astype(np.int32)


@dataclass(frozen=True)
class DisplayableTileOptions:
    """Controls post-process tile optimization before grit import."""

    reduce_threshold: float = 0.0
    reduce_flip_x: bool = True
    reduce_flip_y: bool = True
    reduce_use_blur: bool = True


def exact_dedupe_frames(frames_pixels: Iterable[bytes]) -> list[bytes]:
    """Exact tile dedupe across all animation frames."""
    frames = list(frames_pixels)
    if not frames:
        return []
    stacked = np.concatenate([
        np.frombuffer(f, dtype=np.uint8) for f in frames
    ])
    n_frames = len(frames)
    tiles = _cut_tiles(stacked, BG_SIZE, BG_SIZE * n_frames)
    unique, inverse = np.unique(tiles, axis=0, return_inverse=True)
    rebuilt_tiles = unique[inverse]
    out_frames: list[bytes] = []
    per_frame = MAP_W * MAP_H
    for fi in range(n_frames):
        frame_tiles = rebuilt_tiles[fi * per_frame:(fi + 1) * per_frame]
        buf = np.frombuffer(bytearray(BG_SIZE * BG_SIZE), dtype=np.uint8)
        _paste_tiles(buf, BG_SIZE, BG_SIZE, frame_tiles)
        out_frames.append(buf.tobytes())
    return out_frames


def reduce_tiles_indexed(pixels: bytearray | bytes,
                         palette_bmp: str,
                         width: int,
                         height: int,
                         opts: DisplayableTileOptions) -> int:
    """Merge similar 8×8 tiles in-place. Returns number of merged tiles."""
    if opts.reduce_threshold <= 0:
        return 0

    pal = _load_palette_rgba(palette_bmp)
    indexed = np.frombuffer(
        pixels if isinstance(pixels, bytearray) else bytearray(pixels),
        dtype=np.uint8,
    )
    if not indexed.flags.writeable:
        indexed = indexed.copy()

    tiles_x = width // GBA_TILE
    tiles_y = height // GBA_TILE
    orient_maps = _orientation_maps(opts.reduce_flip_x, opts.reduce_flip_y)
    order = _tile_order(tiles_x, tiles_y)

    all_tiles = _cut_tiles(indexed, width, height)
    n_orient = orient_maps.shape[0]
    oriented_blur_buf = np.empty((n_orient, TILE_RGBA), np.uint8)

    rep_indices_list: list[np.ndarray] = []
    rep_blur_list: list[np.ndarray] = []
    members_list: list[list[np.ndarray]] = []
    medoid_interval = 8
    max_members = 64
    merged = 0
    thresh = opts.reduce_threshold

    for k in range(order.shape[0]):
        tx = int(order[k, 0])
        ty = int(order[k, 1])
        tile = all_tiles[ty * tiles_x + tx]

        colors = _expand_tile_rgba(tile, pal)
        if opts.reduce_use_blur:
            tile_blur = _blur_tile_rgba(colors)
        else:
            tile_blur = colors

        for oi in range(n_orient):
            oriented_blur_buf[oi] = _orient_rgba_flat(tile_blur, orient_maps[oi])

        match = _find_best_rep(
            tile, pal, rep_indices_list, rep_blur_list,
            oriented_blur_buf, orient_maps, thresh,
        )

        if match is None:
            rep_indices_list.append(tile.copy())
            rep_blur_list.append(tile_blur.copy())
            members_list.append([tile.copy()])
            continue

        exact_mse, rep_defect, rep_idx, orient_idx = match
        rep = rep_indices_list[rep_idx]
        tile_defect = _tile_defect(tile)

        if tile_defect < rep_defect and exact_mse > 0.0:
            rep_indices_list.append(tile)
            rep_blur_list.append(tile_blur.copy())
            members_list.append([tile.copy()])
            continue

        omap = orient_maps[orient_idx]
        _write_rep(indexed, ty, tx, width, rep, omap)
        members = members_list[rep_idx]
        if len(members) < max_members:
            members.append(tile.copy())
        else:
            members[len(members) % max_members] = tile.copy()
        if len(members) % medoid_interval == 0:
            stack = np.stack(members[:len(members)])
            pick = _medoid_pick(stack, len(members), pal)
            rep_indices_list[rep_idx] = members[pick].copy()
            rep_blur_list[rep_idx] = _expand_tile_rgba(rep_indices_list[rep_idx], pal)
            if opts.reduce_use_blur:
                rep_blur_list[rep_idx] = _blur_tile_rgba(rep_blur_list[rep_idx])
        merged += 1

    if isinstance(pixels, bytearray):
        pixels[:] = indexed.tobytes()
    return merged


def count_unique_tiles(frames_pixels: Iterable[bytes]) -> int:
    """Exact 8×8 dedupe (grit ``-mRt``, no flip equivalence)."""
    frames = list(frames_pixels)
    if not frames:
        return 0
    stacked = np.concatenate([
        np.frombuffer(f, dtype=np.uint8) for f in frames
    ])
    tiles = _cut_tiles(stacked, BG_SIZE, BG_SIZE * len(frames))
    return int(np.unique(tiles, axis=0).shape[0])


# All four dihedral orientations; matches grit ``-mRtf`` flip reduction.
_GRIT_FLIP_MAPS = _orientation_maps(True, True)


def _canonical_tile_bytes(tile: np.ndarray) -> bytes:
    """Lexicographically smallest of the four H/V flip orientations."""
    best: bytes | None = None
    for oi in range(_GRIT_FLIP_MAPS.shape[0]):
        oriented = _orient_indices(tile, _GRIT_FLIP_MAPS[oi])
        candidate = oriented.tobytes()
        if best is None or candidate < best:
            best = candidate
    assert best is not None
    return best


def count_unique_tiles_grit(frames_pixels: Iterable[bytes]) -> int:
    """Unique ROM tiles after Butano/grit ``-mRtf`` (exact + flip dedupe)."""
    frames = list(frames_pixels)
    if not frames:
        return 0
    stacked = np.concatenate([
        np.frombuffer(f, dtype=np.uint8) for f in frames
    ])
    tiles = _cut_tiles(stacked, BG_SIZE, BG_SIZE * len(frames))
    canon: set[bytes] = set()
    for tile in tiles:
        canon.add(_canonical_tile_bytes(tile))
    return len(canon)


def process_displayable_frames(frames_pixels: list[bytes],
                               palette_bmp: str,
                               opts: DisplayableTileOptions) -> tuple[list[bytes], int]:
    rebuilt = exact_dedupe_frames(frames_pixels)
    merged = 0
    if opts.reduce_threshold > 0 and rebuilt:
        stacked = bytearray()
        for frame in rebuilt:
            stacked.extend(frame)
        merged = reduce_tiles_indexed(
            stacked, palette_bmp, BG_SIZE, BG_SIZE * len(rebuilt), opts)
        rebuilt = [
            bytes(stacked[i * BG_SIZE * BG_SIZE:(i + 1) * BG_SIZE * BG_SIZE])
            for i in range(len(rebuilt))
        ]
    return rebuilt, merged


def stack_frames_bmp(frames_pixels: list[bytes], palette_bmp: str,
                     output_bmp: str) -> None:
    palette = Image.open(palette_bmp).getpalette()
    height = BG_SIZE * len(frames_pixels)
    stacked = bytearray()
    for frame in frames_pixels:
        if len(frame) != BG_SIZE * BG_SIZE:
            raise ValueError(f"Expected {BG_SIZE}×{BG_SIZE} frame, got {len(frame)} bytes")
        stacked.extend(frame)
    img = Image.new("P", (BG_SIZE, height))
    img.putpalette(palette)
    img.frombytes(bytes(stacked))
    img.save(output_bmp, format="BMP")
