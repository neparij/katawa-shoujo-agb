#!/usr/bin/env python3
"""
Smart character converter — hybrid BG + OBJ.

Reads `character_sprites.yaml` (cell-aligned face cut-out coords) and emits,
per `tileset` key:

    1) The unique-tile ROM tileset for **bodies only** (one body per group),
       split into slabs of up to 1024 tiles each. Each slab is a Butano
       `regular_bg_tiles` BMP+JSON (uncompressed, 8bpp, indexed against
       `pal_char_bg`).

    2) Per-group `body` data (one per pose × outfit × close):
         - used_tiles[K] — *global* ROM tile indices (0..N-1).
         - map[1024]     — bg map cells with already-remapped 0..K-1 indices.
         - vis bbox      — half-open cell bbox of non-transparent body cells.
       The body is rendered from the group's `base_emotion` PNG with the
       face cells stamped transparent — every emotion in the group reuses
       this single body, so we don't pay for per-emotion BG duplication
       any more.

    3) Per-(group × emotion) `variant` data: a (body, face_sprite_item,
       face_cell_offset, face_cell_size, group_hash) tuple. Face OBJ
       assets are also generated here from YAML/source PNGs via
       `ImageTools.resize_character_emotion_sprite` (same path used by the
       sprite viewer), so body and face generation live in one converter.
       The group hash matches the legacy MD5-derived `character_sprite_meta`
       hash so existing save thumbnails keep working.

    4) A scene-wide `include/smart_characters_index.h` that maps a group
       hash back to its base-emotion face sprite (for save thumbnails) —
       generated at the end of `convert_all`.

Generated layout (relative to --project-root):
    graphics/characters/<tileset>/<tileset>_tiles_<i>.bmp  (body tile slab)
    graphics/characters/<tileset>/<tileset>_tiles_<i>.json
    graphics/characters/<char>/<char>_spr_*.bmp            (face OBJ assets)
    graphics/characters/<char>/<char>_spr_*.json
    include/smart_characters/<tileset>.h
    src/smart_characters/<tileset>.cpp
    include/smart_characters_index.h                       (hash -> thumbnail)

Usage (run from tools/converter/):
    python -m src.character_sprite.smart_character_converter \
        --yaml src/character_sprite/character_sprites.yaml \
        --sprites /path/to/ksre/sprites \
        --project-root ../.. \
        [--tileset akira]
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import sys
from typing import Iterable

import yaml
from PIL import Image

from src.image_tools.image_tools import ImageTools


GBA_TILE = 8
BG_SIZE  = 256
MAP_W = MAP_H = BG_SIZE // GBA_TILE  # 32
MAP_CELLS = MAP_W * MAP_H            # 1024

# Body rendering pipeline geometry — keep in sync with
# `ImageTools.resize_character_background` (which delegates to
# `ImageTools.resize` with these constants):
#
#   * Source PNG is cropped from y=y_crop+y_offset..H+y_offset (height stays
#     `source_h - y_crop` regardless of y_offset, since the crop window slides).
#   * The cropped image keeps its aspect ratio and is scaled to height
#     `BODY_TARGET_H_PX`. The resulting width is `int(BODY_TARGET_H_PX *
#     source_w / cropped_h)`.
#   * The 160-px-tall scaled body is pasted **canvas-centred** onto the
#     256×256 BG canvas, so the body's displayable centre ≡ canvas centre.
#
# Both `BODY_Y_CROP_PX` and `BODY_TARGET_H_PX` are also encoded in
# `image_tools.resize`'s defaults — adjust both if you ever change the
# converter's render target.
BODY_Y_CROP_PX   = 120
BODY_TARGET_H_PX = 160


def _compute_render_size_px(source_png: str, y_offset: int) -> tuple[int, int]:
    """Pose-stable rendered displayable size in canvas pixels.

    Mirrors `ImageTools.resize` exactly: crop the source by `y_crop` (with
    a sliding `y_offset` that doesn't change cropped height), then scale
    to height `BODY_TARGET_H_PX`. Width is whatever the aspect ratio
    produces. Returns `(render_w_px, render_h_px)`.

    The result is the exact width of the body's **rendered displayable**
    on the BG canvas — what Ren'Py would call the displayable's width.
    Used by the runtime to resolve Ren'Py-style `xpos`/`xanchor` against
    a stable per-group anchor, instead of the visible-cell bbox which
    flickers from pose to pose.
    """
    with Image.open(source_png) as img:
        source_w, source_h = img.size
    cropped_h = source_h - BODY_Y_CROP_PX
    if cropped_h <= 0:
        # Defensive: y_crop ≥ source height means the resize step also
        # bails; report a sensible fallback so body emission keeps going.
        return (BODY_TARGET_H_PX, BODY_TARGET_H_PX)
    # Match `int(target_height * ratio)` from `ImageTools.resize` — same
    # truncation rule, identical width.
    render_w_px = int(BODY_TARGET_H_PX * source_w / cropped_h)
    return (render_w_px, BODY_TARGET_H_PX)

# Hardware limits:
#   * A regular BG can address at most 1024 distinct tiles (10-bit tile_id).
#   * Butano's regular_bg_tiles_item also caps at 1024 visual tiles in BPP_8.
#   * Therefore each body's `used_count` (the working set in VRAM) must be
#     ≤ 1024, but the *ROM* tileset shared across every body in a tileset
#     may be larger and is split into slabs of up to 1024 tiles each.
TILES_PER_SLAB = 1024


# ---------------------------------------------------------------------------
# Per-group body BG rendering
# ---------------------------------------------------------------------------

def render_body_bmp(source_png: str, output_bmp: str, *,
                    y_offset: int, tint: list | None,
                    cutout_offset_px: tuple[int, int],
                    cutout_size_px: tuple[int, int]) -> None:
    """Render the shared body BG for a group into a 256×256 8bpp BMP using
    `pal_char_bg`, with the face cells stamped transparent so the emotion
    sprite can be alpha-composited on top at runtime.

    Skips the (slow) tilequant / imgdither pass if `output_bmp` is newer
    than the source PNG.
    """
    if (os.path.exists(output_bmp)
            and os.path.getmtime(output_bmp) >= os.path.getmtime(source_png)):
        return
    print(f"  render body: {os.path.basename(source_png)}  "
          f"cutout=({cutout_offset_px[0]},{cutout_offset_px[1]}) "
          f"size=({cutout_size_px[0]}x{cutout_size_px[1]})")
    ImageTools.resize_character_background(
        source_png, output_bmp,
        y_offset=y_offset,
        face_cutout_offset=cutout_offset_px,
        face_cutout_size=cutout_size_px,
        tint=tint,
    )


def render_thumbnail_bmp(source_png: str, output_bmp: str, *,
                         y_offset: int, tint: list | None) -> None:
    """Render a 32×32 8bpp mini-portrait of the whole character body+face.

    Quantised against `pal_char_bg` so the resulting indexed bitmap can
    later be paired at runtime with the shared `pal_char_obj` (a
    sprite-typed clone of `pal_char_bg`) — the artist colours match
    exactly. The thumbnail is one-per-group (no emotion variant), which
    is the same trade-off the legacy `CharacterSprite.to_thumb_name`
    pipeline used and which keeps the existing save-game hashes valid.
    """
    if (os.path.exists(output_bmp)
            and os.path.getmtime(output_bmp) >= os.path.getmtime(source_png)):
        return
    print(f"  render thumb: {os.path.basename(source_png)}")
    ImageTools.resize_character_thumbnail(
        source_png, output_bmp,
        y_offset=y_offset,
        tint=tint,
    )


def write_thumbnail_json(json_path: str) -> None:
    """Metadata for a character thumbnail tile asset.

    Mirrors the face JSON: `sprite_tiles` only, no embedded palette —
    save UI composes a `bn::sprite_item` at runtime from
    (32×32 shape, thumbnail_tiles, pal_char_obj).
    """
    with open(json_path, "w", encoding="utf-8") as f:
        json.dump({
            "type": "sprite_tiles",
            "bpp_mode": "bpp_8",
            "compression": "auto_no_huffman",
        }, f, indent=4)
        f.write("\n")


def render_face_bmp(source_png: str, output_bmp: str, *,
                    y_offset: int, tint: list | None,
                    sprite_offset_px: tuple[int, int],
                    sprite_size_px: tuple[int, int]) -> None:
    """Render one emotion face OBJ BMP from the source PNG.

    Uses exactly the same rendering path as the sprite viewer:
    `ImageTools.resize_character_emotion_sprite` with YAML-derived
    (cell-aligned) offset/size, y offset and tint.
    """
    if (os.path.exists(output_bmp)
            and os.path.getmtime(output_bmp) >= os.path.getmtime(source_png)):
        return
    print(f"  render face: {os.path.basename(source_png)}  "
          f"offset=({sprite_offset_px[0]},{sprite_offset_px[1]}) "
          f"size=({sprite_size_px[0]}x{sprite_size_px[1]})")
    ImageTools.resize_character_emotion_sprite(
        source_png, output_bmp,
        sprite_offset=sprite_offset_px,
        sprite_size=sprite_size_px,
        y_offset=y_offset,
        tint=tint,
    )


def write_face_sprite_json(json_path: str) -> None:
    """Metadata for generated face OBJ tile assets (`bn_sprite_tiles_items_*`).

    We deliberately emit `sprite_tiles` (not `sprite`) so grit produces
    *only* tile data — no per-face palette (~256 B/face × ~400 faces was
    ~100 KB of duplicated palettes) and no `bn::sprite_items::*` struct.
    All faces share the same `pal_char_obj` (a sprite-typed clone of
    `pal_char_bg`, which the tiles were already quantised against). The
    runtime composes a `bn::sprite_item` on the fly from
    (face_tiles, shared_palette, shape_size) when creating the face.
    """
    with open(json_path, "w", encoding="utf-8") as f:
        json.dump({
            "type": "sprite_tiles",
            "bpp_mode": "bpp_8",
            "compression": "auto_no_huffman",
        }, f, indent=4)
        f.write("\n")


# ---------------------------------------------------------------------------
# Tile extraction & deduplication
# ---------------------------------------------------------------------------

def read_indexed_pixels(bmp_path: str) -> bytes:
    """Open an 8bpp indexed BMP and return raw 256×256 pixel indices."""
    img = Image.open(bmp_path)
    if img.mode != "P":
        img = img.convert("P")
    if img.size != (BG_SIZE, BG_SIZE):
        raise ValueError(f"Expected {BG_SIZE}×{BG_SIZE}, got {img.size} for {bmp_path}")
    return img.tobytes()


def cut_into_tiles(pixels: bytes) -> list[bytes]:
    """Slice a 256×256 indexed image into 1024 tiles of 64 raw bytes each."""
    tiles: list[bytes] = []
    for ty in range(MAP_H):
        row_base = ty * GBA_TILE * BG_SIZE
        for tx in range(MAP_W):
            tile = bytearray(64)
            x0 = tx * GBA_TILE
            for py in range(GBA_TILE):
                src = row_base + py * BG_SIZE + x0
                tile[py * GBA_TILE:(py + 1) * GBA_TILE] = pixels[src:src + GBA_TILE]
            tiles.append(bytes(tile))
    return tiles


def dedupe_tiles(all_tiles: Iterable[bytes]) -> tuple[list[bytes], dict[bytes, int]]:
    """Build a global unique-tile list. Tile 0 is reserved as the
    all-zeros transparent tile, ensuring empty cells always reference it.
    """
    transparent = bytes(64)
    unique: list[bytes] = [transparent]
    lookup: dict[bytes, int] = {transparent: 0}
    for t in all_tiles:
        if t not in lookup:
            lookup[t] = len(unique)
            unique.append(t)
    return unique, lookup


def build_body_data(tiles_1024: list[bytes],
                    global_lookup: dict[bytes, int]
                    ) -> tuple[list[int], list[int], tuple[int, int, int, int]]:
    """Returns (used_tiles, map_cells, bbox) for one body BG.

    - used_tiles[i] is the global ROM tile index. Always starts with 0
      (transparent) so that empty map cells remap to 0 trivially.
    - map_cells[c] is a 0..K-1 index into used_tiles, ready for the runtime.
    - bbox = (vis_x0, vis_x1, vis_y0, vis_y1) — the half-open cell range
      that contains every *non-transparent* body cell (face cut-out cells
      contribute as transparent and are therefore *not* part of the bbox).
      Used by the multi-character manager to pack multiple bodies into one
      regular BG without overlapping visible tiles. If the body is fully
      empty, bbox is (0, 0, 0, 0).
    """
    used_global: list[int] = [0]                  # reserve transparent at slot 0
    used_set: dict[int, int] = {0: 0}
    map_cells: list[int] = []
    vis_x0, vis_y0 = MAP_W, MAP_H
    vis_x1, vis_y1 = 0, 0
    has_visible = False
    for idx, t in enumerate(tiles_1024):
        gidx = global_lookup[t]
        local = used_set.get(gidx)
        if local is None:
            local = len(used_global)
            used_set[gidx] = local
            used_global.append(gidx)
        map_cells.append(local)
        if local != 0:  # non-transparent — contributes to visible bbox
            cx = idx % MAP_W
            cy = idx // MAP_W
            if cx < vis_x0: vis_x0 = cx
            if cx + 1 > vis_x1: vis_x1 = cx + 1
            if cy < vis_y0: vis_y0 = cy
            if cy + 1 > vis_y1: vis_y1 = cy + 1
            has_visible = True
    if not has_visible:
        bbox = (0, 0, 0, 0)
    else:
        bbox = (vis_x0, vis_x1, vis_y0, vis_y1)
    return used_global, map_cells, bbox


# ---------------------------------------------------------------------------
# Tileset slab writers
# ---------------------------------------------------------------------------

def split_into_slabs(unique_tiles: list[bytes]) -> list[list[bytes]]:
    """Split the global unique-tile list into slabs of TILES_PER_SLAB each."""
    return [unique_tiles[i:i + TILES_PER_SLAB]
            for i in range(0, max(len(unique_tiles), 1), TILES_PER_SLAB)]


def write_slab_bmp(slab_tiles: list[bytes], palette_bmp: str,
                   output_bmp: str) -> tuple[int, int]:
    """Pack a single slab (≤1024 tiles) into a 256-wide indexed 8bpp BMP.

    Layout: 32 tiles per row, ceil(N / 32) rows. Padding tiles are zero-filled.
    """
    n = len(slab_tiles)
    rows = max(1, (n + MAP_W - 1) // MAP_W)
    pad = rows * MAP_W - n
    padded = slab_tiles + [bytes(64)] * pad

    width = BG_SIZE
    height = rows * GBA_TILE
    pixels = bytearray(width * height)
    for i, tile in enumerate(padded):
        ty = i // MAP_W
        tx = i % MAP_W
        for py in range(GBA_TILE):
            dst = (ty * GBA_TILE + py) * width + tx * GBA_TILE
            pixels[dst:dst + GBA_TILE] = tile[py * GBA_TILE:(py + 1) * GBA_TILE]

    palette = Image.open(palette_bmp).getpalette()
    img = Image.new("P", (width, height))
    img.putpalette(palette)
    img.frombytes(bytes(pixels))
    img.save(output_bmp, format="BMP")
    return width, height


def write_tiles_json(json_path: str) -> None:
    with open(json_path, "w", encoding="utf-8") as f:
        json.dump({
            "type": "regular_bg_tiles",
            "bpp_mode": "bpp_8",
            "compression": "none",
        }, f, indent=4)
        f.write("\n")


# ---------------------------------------------------------------------------
# C++ output helpers
# ---------------------------------------------------------------------------

def _emit_uint16_array(f, name: str, values: list[int]) -> None:
    f.write(f"alignas(int) static const uint16_t {name}[{len(values)}] = {{\n")
    for start in range(0, len(values), 16):
        chunk = values[start:start + 16]
        f.write("    " + ", ".join(str(x) for x in chunk) + ",\n")
    f.write("};\n\n")


def _gba_bios_rle_encode(data: bytes) -> bytes:
    """Encode `data` in the GBA BIOS RLE format (SWI 0x14 / 0x15).

    Stream layout:

        [u32 le]  header  = 0x30 | (uncompressed_size_in_bytes << 8)
        [chunks]
            flag byte:
              bit 7 = 1 (compressed run): length = (flag & 0x7F) + 3,
                  followed by 1 byte that is repeated.
              bit 7 = 0 (literal run):    length = (flag & 0x7F) + 1,
                  followed by N raw bytes.

    The packer is a simple one-pass greedy: consume the longest valid
    repeat-run when its length is ≥3 (the break-even point — a 2-byte
    repeat costs 2 bytes raw vs 2 bytes flag+value), otherwise glue
    bytes into a literal run, breaking the literal as soon as a ≥3-byte
    repeat could start at the next position.

    Output is padded to a 4-byte multiple as required by the BIOS.
    """
    n = len(data)
    out = bytearray()
    out.append(0x30)
    out.append(n & 0xFF)
    out.append((n >> 8) & 0xFF)
    out.append((n >> 16) & 0xFF)

    i = 0
    while i < n:
        # Compressed-run scan starting at i.
        j = i + 1
        while j < n and (j - i) < 130 and data[j] == data[i]:
            j += 1
        run_len = j - i
        if run_len >= 3:
            out.append(0x80 | (run_len - 3))
            out.append(data[i])
            i = j
            continue
        # Literal run — keep extending until either the 128-byte cap
        # or the start of a worthwhile (≥3) compressed run.
        lit_start = i
        while i < n and (i - lit_start) < 128:
            k = i + 1
            while k < n and (k - i) < 130 and data[k] == data[i]:
                k += 1
            if (k - i) >= 3:
                break
            i += 1
        lit_len = i - lit_start
        out.append((lit_len - 1) & 0x7F)
        out.extend(data[lit_start:i])

    while len(out) & 3:
        out.append(0)
    return bytes(out)


def _emit_rle_map_array(f, name: str, cells: list[int]) -> int:
    """Emit `cells` (16-bit map values) as a BIOS-RLE-compressed byte
    stream. Returns the compressed byte count for stats / sizing.

    The 16-bit map cells are serialized little-endian (matching VRAM
    layout) so that on decompress the BIOS writes a contiguous
    `regular_bg_map_cell[]` straight into EWRAM.
    """
    raw = bytearray()
    for v in cells:
        raw.append(v & 0xFF)
        raw.append((v >> 8) & 0xFF)
    encoded = _gba_bios_rle_encode(bytes(raw))
    f.write(
        f"alignas(int) static const unsigned char {name}[{len(encoded)}] = {{\n"
    )
    for start in range(0, len(encoded), 16):
        chunk = encoded[start:start + 16]
        f.write("    " + ", ".join(f"0x{b:02X}" for b in chunk) + ",\n")
    f.write("};\n\n")
    return len(encoded)


# ---------------------------------------------------------------------------
# Group context
# ---------------------------------------------------------------------------

class GroupContext:
    """A (character × pose × outfit × close) group, as seen by the converter.

    Holds the metadata needed to render the body BG and to construct
    per-emotion `variant` references. All face coordinates are kept in
    8-px **cell** units (matching the YAML format); pixel coords are
    derived on demand for image-processing calls.
    """

    def __init__(self, char_name: str, group_key: str, group_data: dict):
        self.char_name = char_name
        self.group_key = group_key
        self.pose      = group_data.get("pose")
        self.outfit    = group_data.get("outfit")
        self.close     = bool(group_data.get("close", False))
        self.base_emotion = group_data.get("base_emotion")

        off = group_data.get("base_emotion_offset") or [0, 0]
        size = group_data.get("base_emotion_size") or [4, 4]
        self.face_offset_cells: tuple[int, int] = (int(off[0]), int(off[1]))
        self.face_size_cells:   tuple[int, int] = (int(size[0]), int(size[1]))

        self.y_offset      = int(group_data.get("base_origin_offset") or 0)
        self.silhouette_tint = group_data.get("silhouette_tint")
        self.sprites: dict = group_data.get("sprites", {}) or {}

    @property
    def face_offset_px(self) -> tuple[int, int]:
        return (self.face_offset_cells[0] * 8, self.face_offset_cells[1] * 8)

    @property
    def face_size_px(self) -> tuple[int, int]:
        return (self.face_size_cells[0] * 8, self.face_size_cells[1] * 8)

    @property
    def tint_arg(self) -> list | None:
        t = self.silhouette_tint
        return [t, t, t] if t is not None else None

    @property
    def body_symbol(self) -> str:
        return f"{self.char_name}_{self.group_key}_body"

    def variant_symbol(self, emotion: str) -> str:
        return f"{self.char_name}_{self.group_key}_{emotion}"

    @property
    def thumb_symbol(self) -> str:
        """Legacy thumbnail asset name (`CharacterSprite.to_thumb_name`).

        One thumbnail per (pose × outfit × close) — emotion is *not*
        encoded; the 32×32 mini-portrait can't usefully discriminate
        emotions and saving one per group instead of one per variant
        kept ROM small in the old pipeline. We keep the same naming so
        the hash (`thumb_hash_str`, MD5(thumb_symbol)[:4]) used by
        already-written save files matches.
        """
        s = f"{self.char_name}_thumb"
        if self.pose:
            s += f"_{self.pose}"
        if self.outfit:
            s += f"_{self.outfit}"
        if self.close:
            s += "_close"
        return s

    @property
    def thumb_hash_str(self) -> str:
        """4 uppercase hex chars derived from the group's legacy thumb name.

        Matches the old `character_sprite.CharacterSprite.to_thumb_hash` so
        that save-game thumbnails written by the previous pipeline keep
        resolving after the migration.
        """
        thumb = f"{self.char_name}_thumb"
        if self.pose:
            thumb += f"_{self.pose}"
        if self.outfit:
            thumb += f"_{self.outfit}"
        if self.close:
            thumb += "_close"
        return hashlib.md5(thumb.encode()).hexdigest()[:4].upper()

    def sprite_item_name(self, emotion: str) -> str:
        """The Butano sprite_item name produced by the artist pipeline
        (`CharacterSprite.to_sprite_name`) for this emotion. Mirrors that
        function exactly so the smart converter and the artist pipeline
        always agree on which BMP / sprite_item to reference.
        """
        s = f"{self.char_name}_spr"
        if self.pose:
            s += f"_{self.pose}"
        s += f"_{emotion}"
        if self.outfit:
            s += f"_{self.outfit}"
        if self.close:
            s += "_close"
        return s

    def base_sprite_filename(self) -> str | None:
        """The PNG to use as the *body* source: the group's base_emotion
        sprite (face cut-out is stamped on top during rendering). If the
        named base_emotion is missing, fall back to the first sprite —
        defensive only; clean YAML always names a real emotion.
        """
        if self.base_emotion and self.base_emotion in self.sprites:
            sprite = self.sprites[self.base_emotion]
        elif self.sprites:
            sprite = next(iter(self.sprites.values()))
        else:
            return None
        return (sprite or {}).get("filename")


# ---------------------------------------------------------------------------
# Source emission
# ---------------------------------------------------------------------------

def _sprite_include(name: str) -> str:
    """Face tiles only — palette comes from the shared `pal_char_obj`,
    and `bn::sprite_item` is composed at runtime by the manager."""
    return f'#include "bn_sprite_tiles_items_{name}.h"\n'


def write_tileset_sources(header_path: str, source_path: str,
                          tileset_key: str,
                          bodies: list[dict],
                          variants: list[dict],
                          slab_count: int) -> None:
    """Generate the .h / .cpp pair for one tileset.

    `bodies` is a list of {ctx, used_tiles, map, bbox} dicts (one per group).
    `variants` is a list of {ctx, emotion, body_symbol, sprite_item} dicts
    (one per (group × emotion)).
    """
    h_guard = f"KS_SMART_CHAR_{tileset_key.upper()}_H"

    with open(header_path, "w", encoding="utf-8") as f:
        f.write(f"#ifndef {h_guard}\n#define {h_guard}\n\n")
        f.write('#include "smart_character_bg.h"\n\n')
        f.write(f"namespace ks::smart_characters::{tileset_key} {{\n\n")
        f.write("extern const tileset_data tileset;\n\n")
        if bodies:
            f.write("// Per-group bodies (one per pose × outfit × close).\n")
            for b in bodies:
                f.write(f"extern const body {b['ctx'].body_symbol};\n")
            f.write("\n")
        if variants:
            f.write("// Per-(group × emotion) variants.\n")
            for v in variants:
                f.write(f"extern const variant {v['symbol']};\n")
            f.write("\n")
        f.write("}  // namespace ks::smart_characters::" + tileset_key + "\n\n")
        f.write(f"#endif  // {h_guard}\n")

    sprite_includes = sorted({v["sprite_item_name"] for v in variants})
    # Thumbnails live alongside face sprites under each character's
    # `graphics/characters/<char>/` folder and produce
    # `bn::sprite_tiles_items::<char>_thumb_*` symbols too.
    thumb_includes  = sorted({b["ctx"].thumb_symbol for b in bodies})

    with open(source_path, "w", encoding="utf-8") as f:
        f.write(f'#include "smart_characters/{tileset_key}.h"\n\n')
        for slab_idx in range(slab_count):
            f.write(
                f'#include "bn_regular_bg_tiles_items_'
                f'{tileset_key}_tiles_{slab_idx}.h"\n'
            )
        f.write(f'#include "bn_bg_palette_items_pal_char_bg.h"\n')
        for name in thumb_includes:
            f.write(f'#include "bn_sprite_tiles_items_{name}.h"\n')
        for name in sprite_includes:
            f.write(_sprite_include(name))
        f.write("\n")
        f.write(f"namespace ks::smart_characters::{tileset_key} {{\n\n")

        f.write(
            f"static const bn::regular_bg_tiles_item* const slab_table"
            f"[{slab_count}] = {{\n"
        )
        for slab_idx in range(slab_count):
            f.write(
                f"    &bn::regular_bg_tiles_items::"
                f"{tileset_key}_tiles_{slab_idx},\n"
            )
        f.write("};\n\n")

        f.write(
            f"const tileset_data tileset = {{\n"
            f"    /* slabs       */ slab_table,\n"
            f"    /* slab_count  */ {slab_count},\n"
            f"    /* palette     */ &bn::bg_palette_items::pal_char_bg,\n"
            f"}};\n\n"
        )

        rle_total_raw = 0
        rle_total_enc = 0
        for b in bodies:
            ctx = b["ctx"]
            sym = ctx.body_symbol
            _emit_uint16_array(f, f"{sym}_used", b["used_tiles"])
            enc_size = _emit_rle_map_array(f, f"{sym}_map_rle", b["map"])
            rle_total_raw += len(b["map"]) * 2
            rle_total_enc += enc_size

            vx0, vx1, vy0, vy1 = b["bbox"]
            f.write(
                f"const body {sym} = {{\n"
                f"    /* used_tiles      */ {sym}_used,\n"
                f"    /* used_count      */ {len(b['used_tiles'])},\n"
                f"    /* map_compressed  */ {sym}_map_rle,\n"
                f"    /* vis_x0          */ {vx0},\n"
                f"    /* vis_x1          */ {vx1},\n"
                f"    /* vis_y0          */ {vy0},\n"
                f"    /* vis_y1          */ {vy1},\n"
                f"    /* render_w_px     */ {b['render_w_px']},\n"
                f"    /* render_h_px     */ {b['render_h_px']},\n"
                f"    /* tileset         */ &tileset,\n"
                f"    /* thumbnail_tiles */ "
                f"&bn::sprite_tiles_items::{ctx.thumb_symbol},\n"
                f"}};\n\n"
            )

        if rle_total_raw:
            ratio = (rle_total_enc * 100.0) / rle_total_raw
            print(
                f"[smart-chars] {tileset_key}: maps RLE "
                f"{rle_total_raw} -> {rle_total_enc} bytes "
                f"({ratio:.1f}%)"
            )

        for v in variants:
            ctx = v["ctx"]
            sym = v["symbol"]
            fox, foy = ctx.face_offset_cells
            fsx, fsy = ctx.face_size_cells
            f.write(
                f"const variant {sym} = {{\n"
                f"    /* body                */ &{ctx.body_symbol},\n"
                f"    /* face_tiles          */ &bn::sprite_tiles_items::{v['sprite_item_name']},\n"
                f"    /* face_offset_x_cells */ {fox},\n"
                f"    /* face_offset_y_cells */ {foy},\n"
                f"    /* face_size_x_cells   */ {fsx},\n"
                f"    /* face_size_y_cells   */ {fsy},\n"
                f"    /* hash                */ 0x{ctx.thumb_hash_str},\n"
                f"}};\n\n"
            )

        f.write("}  // namespace ks::smart_characters::" + tileset_key + "\n")


# ---------------------------------------------------------------------------
# Main pipeline
# ---------------------------------------------------------------------------

class SmartCharacterConverter:
    def __init__(self, yaml_path: str, sprites_dir: str, project_root: str,
                 palette_bmp: str):
        self.yaml_path    = yaml_path
        self.sprites_dir  = sprites_dir
        self.project_root = project_root
        self.palette_bmp  = palette_bmp
        with open(yaml_path, "r", encoding="utf-8") as f:
            self.data = yaml.safe_load(f)
        # Collected (hash -> base-emotion sprite_item name) entries, gathered
        # across every tileset processed by `convert_all`. Used to emit the
        # scene-wide `smart_characters_index.h` that powers save thumbnails.
        # Maps `thumb_hash_str` → (tileset_key, variant_symbol) for the
        # group's `base_emotion` variant. Resolved at save-load time
        # (see `smart_characters_index.h::get_thumbnail_by_hash`).
        self._thumbnail_index: dict[str, tuple[str, str]] = {}

    # ------------------------------------------------------------------

    def convert_all(self) -> None:
        tilesets: dict[str, list] = {}
        for char_name, char_data in self.data["sprites"].items():
            ts = char_data.get("tileset", char_name)
            tilesets.setdefault(ts, []).append((char_name, char_data))

        for ts_key, chars in tilesets.items():
            print(f"\n=== Tileset: {ts_key} ===")
            self.convert_tileset(ts_key, chars)

        # Emit the scene-wide hash -> thumbnail index for save metadata.
        self.write_smart_characters_index()

    # ------------------------------------------------------------------

    def convert_tileset(self, tileset_key: str, characters: list) -> None:
        cache_dir = os.path.join(self.project_root, "intermediate",
                                 "smart_characters", tileset_key)
        os.makedirs(cache_dir, exist_ok=True)
        # Smart-character assets reuse the project's per-character
        # `graphics/characters/<char>/` tree (already enumerated in
        # `Makefile`'s GRAPHICS list), so Butano's grit pass picks them
        # up unchanged. Body tile slabs are shared across every variant
        # with the same `tileset` key, so they live under that tileset
        # owner's folder; face OBJ sprites are per-character and live
        # under the owning character's own folder.
        characters_root = os.path.join(self.project_root, "graphics", "characters")

        # 1) Render one body BG + one save thumbnail per group (both
        #    sourced from base_emotion). Slice the body into 1024 tiles.
        group_records: list[dict] = []   # parallel arrays preserved by index
        for char_name, char_data in characters:
            for group_key, group_data in (char_data.get("groups") or {}).items():
                ctx = GroupContext(char_name, group_key, group_data)
                base_filename = ctx.base_sprite_filename()
                if not base_filename:
                    print(f"  ! group {char_name}/{group_key} has no sprites; skipping")
                    continue
                base_png = os.path.join(self.sprites_dir, base_filename)
                if not os.path.exists(base_png):
                    print(f"  ! missing source {base_png}; skipping group {char_name}/{group_key}")
                    continue

                body_bmp = os.path.join(
                    cache_dir, f"{char_name}_{group_key}_body.bmp"
                )
                render_body_bmp(
                    base_png, body_bmp,
                    y_offset=ctx.y_offset,
                    tint=ctx.tint_arg,
                    cutout_offset_px=ctx.face_offset_px,
                    cutout_size_px=ctx.face_size_px,
                )

                # Save-game thumbnail: 32×32 mini body+face. Lives next
                # to the character's face sprites so the Makefile's
                # `graphics/characters/<char>` glob picks it up.
                thumb_dir = os.path.join(characters_root, char_name)
                os.makedirs(thumb_dir, exist_ok=True)
                thumb_bmp  = os.path.join(thumb_dir, f"{ctx.thumb_symbol}.bmp")
                thumb_json = os.path.join(thumb_dir, f"{ctx.thumb_symbol}.json")
                render_thumbnail_bmp(
                    base_png, thumb_bmp,
                    y_offset=ctx.y_offset,
                    tint=ctx.tint_arg,
                )
                if (not os.path.exists(thumb_json)
                        or os.path.getmtime(thumb_json) < os.path.getmtime(thumb_bmp)):
                    write_thumbnail_json(thumb_json)

                pixels = read_indexed_pixels(body_bmp)
                tiles  = cut_into_tiles(pixels)
                # Compute the rendered displayable size from the source
                # PNG (not from the rendered BMP), exactly mirroring the
                # geometry inside `ImageTools.resize`. We do this here
                # rather than reading from `body_bmp` because the BMP is
                # always 256×256 — the actual displayable was pasted
                # canvas-centred and shrunk to fit, and only the source
                # PNG geometry recovers that *displayable* width.
                render_w_px, render_h_px = _compute_render_size_px(
                    base_png, ctx.y_offset)
                group_records.append({
                    "ctx": ctx,
                    "tiles": tiles,
                    "render_w_px": render_w_px,
                    "render_h_px": render_h_px,
                })

        if not group_records:
            print(f"  (no groups rendered)")
            return

        # 2) Dedup body tiles globally across every group in this tileset.
        flat = (t for rec in group_records for t in rec["tiles"])
        unique, lookup = dedupe_tiles(flat)
        slabs = split_into_slabs(unique)
        print(f"  unique body tiles: {len(unique)}  ({len(slabs)} slab(s))")

        # 3) Build per-group body data and per-(group × emotion) variant
        #    references.
        bodies: list[dict] = []
        variants: list[dict] = []
        max_used = 0
        for rec in group_records:
            ctx: GroupContext = rec["ctx"]
            used, map_cells, bbox = build_body_data(rec["tiles"], lookup)
            if len(used) > 1024:
                raise ValueError(
                    f"Body {ctx.body_symbol} uses {len(used)} unique tiles > 1024 "
                    f"(VRAM hardware limit for one regular BG)."
                )
            max_used = max(max_used, len(used))
            bodies.append({
                "ctx": ctx,
                "used_tiles": used,
                "map": map_cells,
                "bbox": bbox,
                "render_w_px": rec["render_w_px"],
                "render_h_px": rec["render_h_px"],
            })
            for emotion in ctx.sprites:
                sprite_rec = (ctx.sprites.get(emotion) or {})
                sprite_filename = sprite_rec.get("filename")
                if not sprite_filename:
                    raise ValueError(
                        f"Missing filename for {ctx.char_name}/{ctx.group_key}/{emotion}"
                    )
                sprite_src = os.path.join(self.sprites_dir, sprite_filename)
                if not os.path.exists(sprite_src):
                    raise FileNotFoundError(
                        f"Missing source sprite {sprite_src} "
                        f"for {ctx.char_name}/{ctx.group_key}/{emotion}"
                    )

                sprite_item_name = ctx.sprite_item_name(emotion)
                # Each face sprite lives in its own character's folder,
                # not the tileset owner's, so e.g. `emicas_spr_*.bmp` and
                # `emiwheel_spr_*.bmp` (both on tileset `emi`) end up in
                # `graphics/characters/emicas/` and `.../emiwheel/`.
                face_dir = os.path.join(characters_root, ctx.char_name)
                os.makedirs(face_dir, exist_ok=True)
                face_bmp  = os.path.join(face_dir, f"{sprite_item_name}.bmp")
                face_json = os.path.join(face_dir, f"{sprite_item_name}.json")
                render_face_bmp(
                    sprite_src, face_bmp,
                    y_offset=ctx.y_offset,
                    tint=ctx.tint_arg,
                    sprite_offset_px=ctx.face_offset_px,
                    sprite_size_px=ctx.face_size_px,
                )
                if (not os.path.exists(face_json)
                        or os.path.getmtime(face_json) < os.path.getmtime(face_bmp)):
                    write_face_sprite_json(face_json)

                variants.append({
                    "ctx": ctx,
                    "emotion": emotion,
                    "symbol": ctx.variant_symbol(emotion),
                    "sprite_item_name": sprite_item_name,
                })

                # Save thumbnails resolve through the group hash. Map each
                # group's hash to its `base_emotion` face sprite — that is
                # the canonical "neutral" face for the pose/outfit, and
                # matches what the legacy thumbnail pipeline produced.
                if emotion == ctx.base_emotion:
                    self._thumbnail_index[ctx.thumb_hash_str] = (
                        tileset_key, ctx.variant_symbol(emotion))
        print(f"  bodies: {len(bodies)}   variants: {len(variants)}")
        print(f"  largest body working set: {max_used} tiles "
              f"(VRAM cap is 1024)")

        # 4) Emit outputs.
        # Body tile slabs live under the tileset owner's character folder
        # (e.g. `emi`) so every character sharing this tileset reads from
        # the same set of slab BMPs.
        graphics_dir = os.path.join(self.project_root, "graphics",
                                    "characters", tileset_key)
        include_dir  = os.path.join(self.project_root, "include",  "smart_characters")
        src_dir      = os.path.join(self.project_root, "src",      "smart_characters")
        for d in (graphics_dir, include_dir, src_dir):
            os.makedirs(d, exist_ok=True)

        # Clean up legacy single-strip artefacts from earlier iterations.
        for stale in (f"{tileset_key}_tiles.bmp", f"{tileset_key}_tiles.json"):
            stale_path = os.path.join(graphics_dir, stale)
            if os.path.exists(stale_path):
                os.remove(stale_path)
        # Also clean up slab files for slab indices that are no longer needed
        # (e.g. tileset shrunk between runs).
        for fname in os.listdir(graphics_dir):
            prefix = f"{tileset_key}_tiles_"
            if not fname.startswith(prefix):
                continue
            base = fname[len(prefix):]
            for ext in (".bmp", ".json"):
                if base.endswith(ext):
                    try:
                        idx = int(base[:-len(ext)])
                    except ValueError:
                        break
                    if idx >= len(slabs):
                        os.remove(os.path.join(graphics_dir, fname))
                    break

        for slab_idx, slab_tiles in enumerate(slabs):
            bmp_path  = os.path.join(graphics_dir,
                                     f"{tileset_key}_tiles_{slab_idx}.bmp")
            json_path = os.path.join(graphics_dir,
                                     f"{tileset_key}_tiles_{slab_idx}.json")
            w, h = write_slab_bmp(slab_tiles, self.palette_bmp, bmp_path)
            write_tiles_json(json_path)
            print(f"  wrote {bmp_path}  ({w}×{h}, "
                  f"{len(slab_tiles)} tiles)")

        h_path   = os.path.join(include_dir, f"{tileset_key}.h")
        cpp_path = os.path.join(src_dir,     f"{tileset_key}.cpp")
        write_tileset_sources(h_path, cpp_path, tileset_key,
                              bodies, variants, slab_count=len(slabs))
        print(f"  wrote {h_path}")
        print(f"  wrote {cpp_path}")

    # ------------------------------------------------------------------

    def write_smart_characters_index(self) -> None:
        """Emit `include/smart_characters_index.h`, exposing
        `get_thumbnail_by_hash(hash)` so save-game metadata can resolve a
        stored group hash back to the matching base-emotion face sprite.
        """
        if not self._thumbnail_index:
            print("\n(no smart-character thumbnails registered; "
                  "skipping smart_characters_index.h)")
            return

        index_path = os.path.join(self.project_root, "include",
                                  "smart_characters_index.h")
        os.makedirs(os.path.dirname(index_path), exist_ok=True)
        sorted_entries = sorted(self._thumbnail_index.items())
        # De-duplicate per-tileset includes; one tileset header pulls in
        # every variant declared inside it.
        used_tilesets = sorted({ts for _h, (ts, _v) in sorted_entries})
        with open(index_path, "w", encoding="utf-8") as f:
            f.write("#ifndef KS_SMART_CHARACTERS_INDEX_H\n")
            f.write("#define KS_SMART_CHARACTERS_INDEX_H\n\n")
            f.write('#include "smart_character_bg.h"\n')
            for ts in used_tilesets:
                f.write(f'#include "smart_characters/{ts}.h"\n')
            f.write("\nnamespace ks::smart_characters {\n\n")
            f.write("/// Resolve a group hash (as stored in save thumbnails)\n")
            f.write("/// back to the `variant` of that group's base-emotion\n")
            f.write("/// face. Returns `nullptr` on miss. Caller composes the\n")
            f.write("/// sprite from `face_tiles` + face shape + the shared\n")
            f.write("/// `bn::sprite_palette_items::pal_char_obj`.\n")
            f.write("inline const variant* get_thumbnail_by_hash"
                    "(const unsigned int hash) {\n")
            f.write("    switch (hash) {\n")
            for hash_str, (tileset_key, variant_symbol) in sorted_entries:
                f.write(f"        case 0x{hash_str}: "
                        f"return &{tileset_key}::{variant_symbol};\n")
            f.write("        default: return nullptr;\n")
            f.write("    }\n")
            f.write("}\n\n")
            f.write("}  // namespace ks::smart_characters\n\n")
            f.write("#endif  // KS_SMART_CHARACTERS_INDEX_H\n")
        print(f"\nwrote {index_path}  "
              f"({len(sorted_entries)} thumbnail entries)")


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main() -> None:
    parser = argparse.ArgumentParser(description="Smart character tilesets converter")
    parser.add_argument("--yaml", required=True,
                        help="Path to character_sprites.yaml (cell-aligned format)")
    parser.add_argument("--sprites", required=True,
                        help="Root directory containing the source PNG sprites")
    parser.add_argument("--project-root", required=True,
                        help="Project root (parent of include/, src/, graphics/)")
    parser.add_argument("--palette-bmp",
                        default="../../graphics/common_palettes/pal_char_bg.bmp",
                        help="Reference palette BMP (defaults to project's pal_char_bg.bmp)")
    parser.add_argument("--tileset", default=None,
                        help="If set, only convert the given tileset key")
    args = parser.parse_args()

    conv = SmartCharacterConverter(
        os.path.abspath(args.yaml),
        os.path.abspath(args.sprites),
        os.path.abspath(args.project_root),
        os.path.abspath(args.palette_bmp),
    )

    if args.tileset:
        chars = [(name, data) for name, data in conv.data["sprites"].items()
                 if data.get("tileset", name) == args.tileset]
        if not chars:
            print(f"No characters found for tileset '{args.tileset}'", file=sys.stderr)
            sys.exit(1)
        conv.convert_tileset(args.tileset, chars)
    else:
        conv.convert_all()


if __name__ == "__main__":
    main()
