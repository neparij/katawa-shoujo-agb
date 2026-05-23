#!/usr/bin/env python3
"""Build composite background ROM assets (streaming tileset + variant maps)."""

from __future__ import annotations

import json
import os
import re

import numpy as np
from PIL import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode

from src.character_sprite.smart_character_converter import (
    MAP_W,
    split_into_slabs,
    write_slab_bmp,
    _emit_rle_map_array,
    _emit_uint16_array,
)
from src.composite_map import (
    build_variant_map_data,
    cut_into_tiles,
    dedupe_tiles,
    used_globals_to_rom,
)
from src.composite_preprocess import (
    DISPLAY_HEIGHT,
    DISPLAY_WIDTH,
    CompositeLayer,
    SOURCE_HEIGHT,
    composite_layers_fullres,
)
from src.composite_specs import (
    CompositeAssetSpec,
    CompositeVariantSpec,
    resolve_ksre_thumb_path,
    shared_thumb_stem,
)
from src.composite_quantize import write_bg_palette_json, write_tiles_slab_json


def _encode_map_rle_u16(map_cells: list[int]) -> bytes:
    from src.character_sprite.smart_character_converter import _gba_bios_rle_encode

    raw = bytearray()
    for cell in map_cells:
        raw.append(cell & 0xFF)
        raw.append((cell >> 8) & 0xFF)
    return _gba_bios_rle_encode(bytes(raw))


def build_composite_asset(
    symbol: str,
    variant_pixels: list[bytes],
    palette_ref_bmp: str,
    map_w: int,
    map_h: int,
    out_dir: str,
    project_root: str,
    variant_names: list[str],
    huge: bool = False,
) -> tuple[int, int]:
    """Write grit inputs + generated C++. Returns (max_vram_tiles, unique_tile_count)."""
    os.makedirs(out_dir, exist_ok=True)

    all_tile_bytes: list[bytes] = []
    for pixels in variant_pixels:
        all_tile_bytes.extend(cut_into_tiles(pixels, map_w, map_h))

    unique, lookup = dedupe_tiles(all_tile_bytes)
    slabs = split_into_slabs(unique)
    slab_count = len(slabs)

    grit_file_re = re.compile(
        rf"^{re.escape(symbol)}_(tiles_\d+|palette)\.(bmp|json)$"
    )
    for stale in os.listdir(out_dir):
        if grit_file_re.match(stale):
            os.remove(os.path.join(out_dir, stale))

    for slab_idx, slab in enumerate(slabs):
        slab_bmp = os.path.join(out_dir, f"{symbol}_tiles_{slab_idx}.bmp")
        write_slab_bmp(slab, palette_ref_bmp, slab_bmp)
        slab_compression = "none" if huge else "auto_no_huffman"
        write_tiles_slab_json(
            slab_bmp.replace(".bmp", ".json"),
            compression=slab_compression,
        )

    palette_out = os.path.join(out_dir, f"{symbol}_palette.bmp")
    Image.open(palette_ref_bmp).save(palette_out, format="BMP")
    write_bg_palette_json(palette_out.replace(".bmp", ".json"), 128)

    variant_rows: list[dict] = []
    max_vram = 0
    for vi, pixels in enumerate(variant_pixels):
        used_global, map_cells = build_variant_map_data(pixels, map_w, map_h, lookup)
        used_rom = used_globals_to_rom(used_global)
        used_count = len(used_rom)
        max_vram = max(max_vram, used_count)
        map_rle = _encode_map_rle_u16(map_cells)
        variant_rows.append({
            "index": vi,
            "name": variant_names[vi],
            "used_rom": used_rom,
            "used_count": used_count,
            "map_rle": map_rle,
        })

    src_dir = os.path.join(project_root, "src", "composite_backgrounds")
    os.makedirs(src_dir, exist_ok=True)
    cpp_path = os.path.join(src_dir, f"composite_{symbol}.cpp")
    _write_asset_cpp(
        cpp_path, symbol, slab_count, variant_rows, max_vram, map_w, map_h, huge,
    )
    return max_vram, len(unique)


def _write_asset_cpp(
    cpp_path: str,
    symbol: str,
    slab_count: int,
    variant_rows: list[dict],
    max_vram: int,
    map_w: int,
    map_h: int,
    huge: bool = False,
) -> None:
    with open(cpp_path, "w", encoding="utf-8") as f:
        f.write('#include "composite_bg_asset.h"\n')
        f.write('#include "bn_bg_palette_item.h"\n')
        f.write('#include "bn_regular_bg_tiles_item.h"\n')
        for slab_idx in range(slab_count):
            f.write(
                f'#include "bn_regular_bg_tiles_items_{symbol}_tiles_{slab_idx}.h"\n'
            )
        f.write(f'#include "bn_bg_palette_items_{symbol}_palette.h"\n\n')
        f.write("namespace ks::composites {\n\n")

        f.write(
            f"static const bn::regular_bg_tiles_item* const {symbol}_slabs"
            f"[{slab_count}] = {{\n"
        )
        for slab_idx in range(slab_count):
            f.write(
                f"    &bn::regular_bg_tiles_items::{symbol}_tiles_{slab_idx},\n"
            )
        f.write("};\n\n")

        f.write(f"static const composite_tileset {symbol}_tileset = {{\n")
        f.write(f"    /* slabs      */ {symbol}_slabs,\n")
        f.write(f"    /* slab_count */ {slab_count},\n")
        f.write("};\n\n")

        for row in variant_rows:
            vi = row["index"]
            prefix = f"{symbol}_v{vi}"
            _emit_uint16_array(f, f"{prefix}_used", row["used_rom"])
            f.write(
                f"alignas(int) static const unsigned char {prefix}_map_rle"
                f"[{len(row['map_rle'])}] = {{\n"
            )
            data = row["map_rle"]
            for start in range(0, len(data), 16):
                chunk = data[start:start + 16]
                f.write("    " + ", ".join(f"0x{b:02X}" for b in chunk) + ",\n")
            f.write("};\n\n")

        f.write(
            f"static const composite_variant {symbol}_variants"
            f"[{len(variant_rows)}] = {{\n"
        )
        for row in variant_rows:
            vi = row["index"]
            f.write(
                f"    {{ {symbol}_v{vi}_used, {row['used_count']}, "
                f"{symbol}_v{vi}_map_rle }},\n"
            )
        f.write("};\n\n")

        f.write(f"extern const composite_bg_asset {symbol}_asset = {{\n")
        f.write(f"    /* tileset        */ &{symbol}_tileset,\n")
        f.write(f"    /* palette        */ &bn::bg_palette_items::{symbol}_palette,\n")
        f.write(f"    /* variants       */ {symbol}_variants,\n")
        f.write(f"    /* variant_count  */ {len(variant_rows)},\n")
        f.write(f"    /* max_vram_tiles */ {max_vram},\n")
        f.write(f"    /* map_w_px       */ {map_w},\n")
        f.write(f"    /* map_h_px       */ {map_h},\n")
        f.write(f"    /* huge           */ {'true' if huge else 'false'},\n")
        f.write("};\n\n")
        f.write("}  // namespace ks::composites\n")


def _huge_merged_bounds(
    canvas_w: int,
    canvas_h: int,
    map_w: int,
    *,
    scale_by_height: bool = False,
    content_w: int = DISPLAY_WIDTH,
    content_h: int = DISPLAY_HEIGHT,
) -> tuple[int, int, int, int]:
    """Return ``merged_w, merged_h, paste_x, paste_y`` in map pixels."""
    if scale_by_height:
        scale = content_h / canvas_h
        merged_h = max(1, int(round(content_h)))
        merged_w = max(1, int(round(canvas_w * scale)))
    else:
        scale = content_w / canvas_w
        merged_w = max(1, int(round(content_w)))
        merged_h = max(1, int(round(canvas_h * scale)))
    paste_x = (map_w - merged_w) // 2
    paste_y = 0
    return merged_w, merged_h, paste_x, paste_y


def _huge_thumb_viewport(
    rgba: Image.Image,
    canvas_w: int,
    canvas_h: int,
    map_w: int,
    *,
    scale_by_height: bool = False,
    content_h: int = DISPLAY_HEIGHT,
) -> Image.Image:
    """Crop the on-screen 240×160 viewport from a huge map canvas for thumbnails."""
    merged_w, merged_h, paste_x, paste_y = _huge_merged_bounds(
        canvas_w,
        canvas_h,
        map_w,
        scale_by_height=scale_by_height,
        content_h=content_h,
    )
    crop_w = min(DISPLAY_WIDTH, merged_w)
    crop_h = min(DISPLAY_HEIGHT, merged_h)
    crop_x = paste_x + (merged_w - crop_w) // 2
    crop_y = paste_y
    return rgba.crop((crop_x, crop_y, crop_x + crop_w, crop_y + crop_h))


def _flatten_rgba_on_pink(rgba: Image.Image, pink: tuple[int, int, int] = (255, 0, 255)) -> Image.Image:
    background = Image.new("RGB", rgba.size, pink)
    background.paste(rgba, mask=rgba.split()[3])
    return background


def _opaque_content_bbox(rgba: Image.Image) -> tuple[int, int, int, int] | None:
    alpha = np.array(rgba)[:, :, 3]
    ys, xs = np.where(alpha > 127)
    if len(xs) == 0:
        return None
    return int(xs.min()), int(ys.min()), int(xs.max()) + 1, int(ys.max()) + 1


def build_composite_thumbnail_source(
    layers: list[CompositeLayer],
    map_rgba: Image.Image,
    spec: CompositeAssetSpec,
    variant: CompositeVariantSpec,
) -> Image.Image:
    """Build RGB input for save-slot thumbs (same crop/fit path as ``bgs_resize``)."""
    thumb_path = resolve_ksre_thumb_path(spec, variant)
    if thumb_path is not None:
        if not os.path.exists(thumb_path):
            raise FileNotFoundError(
                f"{spec.symbol}/{variant.name}: KSRE thumb not found: {thumb_path}"
            )
        return Image.open(thumb_path).convert("RGB")

    if spec.huge:
        content_h = (
            spec.huge_content_h if spec.huge_content_h is not None else DISPLAY_HEIGHT
        )
        rgba = _huge_thumb_viewport(
            map_rgba,
            spec.composite_canvas_w,
            spec.composite_canvas_h,
            spec.map_w_px,
            scale_by_height=spec.huge_scale_by_height,
            content_h=content_h,
        )
        return _flatten_rgba_on_pink(rgba)

    use_stacked = spec.composite_canvas_h > SOURCE_HEIGHT
    if use_stacked:
        bbox = _opaque_content_bbox(map_rgba)
        rgba = map_rgba.crop(bbox) if bbox else map_rgba
        return _flatten_rgba_on_pink(rgba)

    return _flatten_rgba_on_pink(composite_layers_fullres(layers))


def _quantize_thumb_bmp(source_rgb: Image.Image, bmp_path: str) -> None:
    pink = (255, 0, 255)
    thumb_json = {
        "type": "regular_bg",
        "bpp_mode": "bpp_4_manual",
        "colors_count": 64,
        "compression": "auto_no_huffman",
    }
    background = Image.new("RGB", (256, 256), pink)
    source_resized = ImageOps.fit(
        source_rgb,
        (48, 32),
        method=Image.Resampling.LANCZOS,
        centering=(0.5, 0.5),
    )
    background.paste(source_resized, (104, 112))
    converter = Tilequant(
        background,
        pink,
        tile_width=8,
        tile_height=8,
    )
    quantized = converter.convert(
        num_palettes=4,
        colors_per_palette=16,
        dithering_mode=DitheringMode.FLOYDSTEINBERG,
        dithering_level=0.5,
        num_color_cluster_passes=0,
        num_tile_cluster_passes=0,
    )
    quantized.save(bmp_path, format="BMP")
    with open(bmp_path.replace(".bmp", ".json"), "w", encoding="utf-8") as json_file:
        json.dump(thumb_json, json_file, indent=4)


def _remove_stale_thumb_files(thumbs_dir: str, meta_names: list[str], keep_stem: str) -> None:
    for meta_name in meta_names:
        if meta_name == keep_stem:
            continue
        for ext in (".bmp", ".json"):
            path = os.path.join(thumbs_dir, f"thumb_{meta_name}{ext}")
            if os.path.exists(path):
                os.remove(path)


def write_composite_thumbnails(
    spec: CompositeAssetSpec,
    thumb_sources: list[Image.Image],
    meta_names: list[str],
    thumbs_dir: str,
) -> list[str]:
    """Write save-slot thumbnails; return the thumb stem used for each variant."""
    os.makedirs(thumbs_dir, exist_ok=True)
    shared_stem = shared_thumb_stem(spec)
    if shared_stem:
        _quantize_thumb_bmp(
            thumb_sources[0],
            os.path.join(thumbs_dir, f"thumb_{shared_stem}.bmp"),
        )
        _remove_stale_thumb_files(thumbs_dir, meta_names, shared_stem)
        return [shared_stem] * len(meta_names)

    for source_rgb, meta_name in zip(thumb_sources, meta_names, strict=True):
        _quantize_thumb_bmp(
            source_rgb,
            os.path.join(thumbs_dir, f"thumb_{meta_name}.bmp"),
        )
    return list(meta_names)


def patch_composite_meta_header(
    h_path: str,
    symbol: str,
    variant_meta: list[tuple[str, int, str, int, str]],
    seen_bitmask: str = "DISPLAYABLE_BITMASK_NONE",
) -> None:
    """Write one composite_background_meta entry per script-visible variant."""
    sym_u = symbol.upper()
    with open(h_path, "w", encoding="utf-8") as f:
        f.write(f"#ifndef KS_COMPOSITES_{sym_u}_H\n")
        f.write(f"#define KS_COMPOSITES_{sym_u}_H\n\n")
        f.write('#include "background_meta.h"\n')
        f.write('#include "regular_composite_bg_item.h"\n')
        for thumb_stem in sorted({row[2] for row in variant_meta}):
            f.write(f'#include "bn_regular_bg_items_thumb_{thumb_stem}.h"\n')
        f.write("\n")
        f.write("namespace ks::composites {\n")
        f.write(f"extern const composite_bg_asset {symbol}_asset;\n")
        f.write("}\n\n")
        f.write("namespace ks::composite_background_metas {\n\n")
        for meta_name, variant_index, thumb_stem, hash_id, seen_bitmask in variant_meta:
            f.write(
                f"constexpr inline composite_background_meta {meta_name} = {{\n"
            )
            f.write(
                f"    ks::regular_composite_bg_item(ks::composites::{symbol}_asset, "
                f"{variant_index}),\n"
            )
            f.write(f"    bn::regular_bg_items::thumb_{thumb_stem},\n")
            f.write(f"    {seen_bitmask},\n")
            f.write(f"    {hash_id:#010x},\n")
            f.write("};\n\n")
        f.write("}  // namespace ks::composite_background_metas\n\n")
        f.write(f"#endif  // KS_COMPOSITES_{sym_u}_H\n")


def patch_composite_huge_meta_header(
    h_path: str,
    symbol: str,
    variant_meta: list[tuple[str, int, str, int, str]],
    seen_bitmask: str = "DISPLAYABLE_BITMASK_NONE",
) -> None:
    """Write one composite_huge_background_meta entry per script-visible variant."""
    sym_u = symbol.upper()
    with open(h_path, "w", encoding="utf-8") as f:
        f.write(f"#ifndef KS_COMPOSITE_HUGE_{sym_u}_H\n")
        f.write(f"#define KS_COMPOSITE_HUGE_{sym_u}_H\n\n")
        f.write('#include "background_meta.h"\n')
        f.write('#include "composite_huge_bg_item.h"\n')
        for thumb_stem in sorted({row[2] for row in variant_meta}):
            f.write(f'#include "bn_regular_bg_items_thumb_{thumb_stem}.h"\n')
        f.write("\n")
        f.write("namespace ks::composites {\n")
        f.write(f"extern const composite_bg_asset {symbol}_asset;\n")
        f.write("}\n\n")
        f.write("namespace ks::composite_huge_background_metas {\n\n")
        for meta_name, variant_index, thumb_stem, hash_id, variant_seen in variant_meta:
            f.write(
                f"constexpr inline composite_huge_background_meta {meta_name} = {{\n"
            )
            f.write(
                f"    ks::composite_huge_bg_item(ks::composites::{symbol}_asset, "
                f"{variant_index}),\n"
            )
            f.write(f"    bn::regular_bg_items::thumb_{thumb_stem},\n")
            f.write(f"    {variant_seen},\n")
            f.write(f"    {hash_id:#010x},\n")
            f.write("};\n\n")
        f.write("}  // namespace ks::composite_huge_background_metas\n\n")
        f.write(f"#endif  // KS_COMPOSITE_HUGE_{sym_u}_H\n")
