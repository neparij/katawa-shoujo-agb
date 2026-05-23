#!/usr/bin/env python3
"""Composite background group specifications."""

from __future__ import annotations

import hashlib
import os
from dataclasses import dataclass, field

from src.composite_preprocess import CompositeLayer
from src.composite_tile_diff import DEFAULT_STATIC_TILE_IDENTITY_THRESHOLD

DEFAULT_KSRE_GAME = os.environ.get(
    "KSRE_GAME_ROOT",
    "/Users/n.laptev/development/ksre-2/game",
)

# Butano regular_bg maps require ≥32 cells per axis, in multiples of 32
# (256×256 px). Viewport content is centered inside this canvas.
MAP_W_PX = 256
MAP_H_PX = 256

# Scrollable composite huge maps (512×512 px, 64×64 cells — same as event_drugs).
HUGE_MAP_W_PX = 512
HUGE_MAP_H_PX = 512
HUGE_CONTENT_W_PX = 240


@dataclass(frozen=True)
class CompositeVariantSpec:
    name: str
    layers: tuple[CompositeLayer, ...]
    hash: int = 0
    seen_bitmask: str = ""
    # Optional override; defaults to ``CompositeAssetSpec.thumb_rel_path``.
    thumb_rel_path: str = ""


@dataclass(frozen=True)
class CompositeAssetSpec:
    symbol: str
    variants: tuple[CompositeVariantSpec, ...]
    map_w_px: int = MAP_W_PX
    map_h_px: int = MAP_H_PX
    composite_canvas_w: int = 1920
    composite_canvas_h: int = 1080
    ksre_game_root: str = DEFAULT_KSRE_GAME
    meta_prefix: str = ""
    seen_bitmask: str = "DISPLAYABLE_BITMASK_NONE"
    huge: bool = False
    # When huge=True: scale merged slab to content width (default). If True,
    # scale to display height instead — needed for wide pans (rin_wet_arms).
    huge_scale_by_height: bool = False
    # When huge=True: target merged content height before pasting into the map.
    # Defaults to 160 (viewport). Use 512 for tall scrollable assets.
    huge_content_h: int | None = None
    # Max per-channel RGBA delta (0–255) for an 8×8 cell to count as unchanged
    # vs the base variant. After qualetize, static cells reuse base indexed
    # tiles so dither noise does not bloat ROM. None disables canonicalization.
    static_tile_identity_threshold: int | None = DEFAULT_STATIC_TILE_IDENTITY_THRESHOLD
    # Save-slot / gallery thumb source under KSRE ``event/`` (``definitions.rpy``
    # style: ``thumb/foo.jpg``). When set, composite_converter skips map-derived
    # thumbs and resizes this file to 48×32 like ``bgs_resize``.
    thumb_rel_path: str = ""

    def __post_init__(self) -> None:
        if not self.variants:
            raise ValueError(f"{self.symbol}: no variants")
        if self.map_w_px % 8 or self.map_h_px % 8:
            raise ValueError(f"{self.symbol}: map size must be multiple of 8")
        map_w_cells = self.map_w_px // 8
        map_h_cells = self.map_h_px // 8
        if map_w_cells < 32 or map_w_cells % 32 != 0:
            raise ValueError(
                f"{self.symbol}: map width must be ≥256 px and a multiple of 256"
            )
        if map_h_cells < 32 or map_h_cells % 32 != 0:
            raise ValueError(
                f"{self.symbol}: map height must be ≥256 px and a multiple of 256"
            )
        max_px = HUGE_MAP_W_PX if self.huge else MAP_W_PX
        if self.map_w_px > max_px or self.map_h_px > max_px:
            raise ValueError(
                f"{self.symbol}: map exceeds {max_px}×{max_px} limit (huge={self.huge})"
            )


def _layer(rel_path: str, x: int = 0, y: int = 0) -> CompositeLayer:
    root = DEFAULT_KSRE_GAME
    return CompositeLayer(os.path.join(root, rel_path), x, y)


def _thumb(rel_path: str) -> str:
    """KSRE gallery thumb path as in ``definitions.rpy`` (``thumb/*.jpg``)."""
    return rel_path


def resolve_ksre_thumb_path(
    spec: CompositeAssetSpec,
    variant: CompositeVariantSpec,
) -> str | None:
    rel = variant.thumb_rel_path or spec.thumb_rel_path
    if not rel:
        return None
    if rel.startswith("event/"):
        event_rel = rel
    elif rel.startswith("thumb/"):
        event_rel = os.path.join("event", rel)
    else:
        event_rel = os.path.join("event", "thumb", rel)
    return os.path.join(spec.ksre_game_root, event_rel)


def shared_thumb_stem(spec: CompositeAssetSpec) -> str | None:
    """Basename of the KSRE gallery thumb (``thumb/foo.jpg`` → ``foo``).

    When set, all variants share one ``thumb_foo`` GBA asset.
    """
    paths: set[str] = set()
    for variant in spec.variants:
        rel = variant.thumb_rel_path or spec.thumb_rel_path
        if rel:
            paths.add(rel)
    if not paths:
        return None
    if len(paths) != 1:
        raise ValueError(
            f"{spec.symbol}: mixed thumb_rel_path across variants: {sorted(paths)}"
        )
    rel = next(iter(paths))
    return os.path.splitext(os.path.basename(rel.replace("\\", "/")))[0]


def flat_variants(
    symbol: str,
    variant_sources: tuple[tuple[str, str], ...],
    *,
    meta_prefix: str = "",
    seen_bitmask: str = "DISPLAYABLE_BITMASK_NONE",
    **spec_kwargs,
) -> CompositeAssetSpec:
    """Build a composite spec from full-frame variants (one layer each).

    Use when backgrounds are nearly identical and differ only in small regions
    (expressions, eyes, …). Shared qualetize plus static-tile canonicalization
    (``static_tile_identity_threshold``, default 8) dedupes ROM tiles; run
    ``composite_converter --report-diff`` first to inspect changed cells.

    ``variant_sources`` is ``(variant_name, ksre_rel_path)`` pairs; the first
    entry is the diff base for analysis tools.
    """
    if not variant_sources:
        raise ValueError(f"{symbol}: no variant_sources")
    prefix = meta_prefix or symbol
    return CompositeAssetSpec(
        symbol=symbol,
        meta_prefix=prefix,
        seen_bitmask=seen_bitmask,
        variants=tuple(
            CompositeVariantSpec(name, (_layer(rel_path),))
            for name, rel_path in variant_sources
        ),
        **spec_kwargs,
    )


RIN_GOODEND = CompositeAssetSpec(
    symbol="rin_goodend",
    meta_prefix="rin_goodend",
    thumb_rel_path=_thumb("thumb/rin_goodend.jpg"),
    variants=(
        CompositeVariantSpec(
            "1",
            (
                _layer("event/rin_goodend/rin_goodend_base.png"),
                _layer("event/rin_goodend/rin_goodend_1.png"),
            ),
            hash=0x8AB58058,
        ),
        CompositeVariantSpec(
            "1b",
            (
                _layer("event/rin_goodend/rin_goodend_base.png"),
                _layer("event/rin_goodend/rin_goodend_1b.png"),
            ),
            hash=0x6DFB6768,
        ),
        CompositeVariantSpec(
            "2",
            (
                _layer("event/rin_goodend/rin_goodend_base.png"),
                _layer("event/rin_goodend/rin_goodend_2.png"),
            ),
            hash=0x222FA88A,
        ),
    ),
)

def _rin_h2_u(name: str) -> CompositeLayer:
    return _layer(f"event/rin_h2/rin_h2_u_{name}.png", 0, 0)


def _rin_h2_l(name: str) -> CompositeLayer:
    return _layer(f"event/rin_h2/rin_h2_l_{name}.png", 0, 720)


RIN_H2 = CompositeAssetSpec(
    symbol="rin_h2",
    meta_prefix="rin_h2",
    thumb_rel_path=_thumb("thumb/rin_h2.jpg"),
    huge=True,
    map_w_px=HUGE_MAP_W_PX,
    map_h_px=HUGE_MAP_H_PX,
    composite_canvas_w=1920,
    composite_canvas_h=2160,
    variants=(
        CompositeVariantSpec(
            "pan_surprise",
            (_rin_h2_u("surprise"), _rin_h2_l("pan")),
            hash=0x6C60BF4A,
        ),
        CompositeVariantSpec(
            "pan_away",
            (_rin_h2_u("away"), _rin_h2_l("pan")),
            hash=0xCD24BD8F,
        ),
        CompositeVariantSpec(
            "pan_closed",
            (_rin_h2_u("closed"), _rin_h2_l("pan")),
            hash=0xD9351E8A,
        ),
        CompositeVariantSpec(
            "nopan_closed",
            (_rin_h2_u("closed"), _rin_h2_l("nopan")),
            hash=0xF16A04EE,
        ),
        CompositeVariantSpec(
            "hisao_surprise",
            (_rin_h2_u("surprise"), _rin_h2_l("hisao")),
            hash=0x0575DE92,
        ),
        CompositeVariantSpec(
            "hisao_away",
            (_rin_h2_u("away"), _rin_h2_l("hisao")),
            hash=0xA0104552,
        ),
        CompositeVariantSpec(
            "hisao_closed",
            (_rin_h2_u("closed"), _rin_h2_l("hisao")),
            hash=0x65D832D6,
        ),
    ),
)

def _rin_pair_layers(clothes: bool, hisao: str, rin: str) -> tuple[CompositeLayer, ...]:
    layers = [_layer("event/rin_pair/rin_pair_base.png")]
    if clothes:
        layers.append(_layer("event/rin_pair/rin_pair_hisao_clothes.png"))
    if hisao != "normal":
        layers.append(_layer(f"event/rin_pair/rin_pair_hisao_{hisao}.png"))
    if rin != "normal":
        layers.append(_layer(f"event/rin_pair/rin_pair_rin_{rin}.png"))
    return tuple(layers)


def _rin_pair_variant_name(clothes: bool, hisao: str, rin: str) -> str:
    c = "c" if clothes else "n"
    h = {"normal": "hn", "frown": "hf", "smile": "hs"}[hisao]
    r = {"normal": "rn", "talk": "rt", "smile": "rs", "frown": "rf", "closed": "rc"}[rin]
    return f"{c}_{h}_{r}"


# Unique combinations that appear in script-a4-rin.rpy (not full 2×3×5 Cartesian product).
_RIN_PAIR_SCRIPT_VARIANTS = (
    (True, "normal", "normal"),   # scene ev rin_pair_base_clothes
    (True, "frown", "normal"),
    (True, "frown", "talk"),
    (True, "smile", "talk"),
    (True, "smile", "smile"),
    (True, "smile", "frown"),
    (True, "normal", "frown"),
    (False, "normal", "normal"),  # show ev rin_pair_base
    (False, "normal", "closed"),
    (False, "frown", "closed"),
    (False, "frown", "talk"),
    (False, "normal", "talk"),
    (False, "normal", "smile"),
    (False, "frown", "smile"),
)

def _md5_meta_hash(meta_name: str) -> int:
    return int(hashlib.md5(meta_name.encode()).hexdigest()[:8], 16)


_RIN_PAIR_VARIANT_HASHES = {
    _rin_pair_variant_name(clothes, hisao, rin): _md5_meta_hash(
        f"rin_pair_{_rin_pair_variant_name(clothes, hisao, rin)}"
    )
    for clothes, hisao, rin in _RIN_PAIR_SCRIPT_VARIANTS
}

RIN_PAIR = CompositeAssetSpec(
    symbol="rin_pair",
    meta_prefix="rin_pair",
    thumb_rel_path=_thumb("thumb/rin_pair.jpg"),
    variants=tuple(
        CompositeVariantSpec(
            _rin_pair_variant_name(clothes, hisao, rin),
            _rin_pair_layers(clothes, hisao, rin),
            hash=_RIN_PAIR_VARIANT_HASHES[_rin_pair_variant_name(clothes, hisao, rin)],
        )
        for clothes, hisao, rin in _RIN_PAIR_SCRIPT_VARIANTS
    ),
)


def _rin_h_layers(variant_name: str) -> tuple[CompositeLayer, ...]:
    """Match ``rin_h_comp()`` in images.rpy."""
    if variant_name == "closed":
        return (_layer("event/rin_h/rin_h_closed.png"),)
    if variant_name == "closed_close":
        return (_layer("event/rin_h/rin_h_closed_close.png"),)
    if variant_name.endswith("_close"):
        pose = variant_name.removesuffix("_close")
        return (
            _layer("event/rin_h/rin_h_closed_close.png"),
            _layer(f"event/rin_h/rin_h_{pose}_close.png"),
        )
    return (
        _layer("event/rin_h/rin_h_closed.png"),
        _layer(f"event/rin_h/rin_h_{variant_name}.png"),
    )


# Script-closure variants from script-a4-rin.rpy evh rin_h_* sequence.
_RIN_H_SCRIPT_VARIANTS = (
    "closed",
    "left",
    "normal",
    "right",
    "closed_close",
    "strain_close",
    "strain",
    "normal_close",
    "right_close",
    "left_close",
)

_RIN_H_VARIANT_HASHES = {
    "closed": 0xD0FE448D,
    "left": 0xB2A237FA,
    "normal": 0xB783FCC3,
    "right": 0x823E033F,
    "strain": 0x9DFC70B0,
    "closed_close": 0x6D8C5931,
    "left_close": 0xBE664BFD,
    "normal_close": 0x6BF21BE8,
    "right_close": 0x2713A330,
    "strain_close": 0x21AACB6F,
}

RIN_H = CompositeAssetSpec(
    symbol="rin_h",
    meta_prefix="rin_h",
    thumb_rel_path=_thumb("thumb/rin_h.jpg"),
    variants=tuple(
        CompositeVariantSpec(
            name,
            _rin_h_layers(name),
            hash=_RIN_H_VARIANT_HASHES[name],
        )
        for name in _RIN_H_SCRIPT_VARIANTS
    ),
)

RIN_WET_PAN = CompositeAssetSpec(
    symbol="rin_wet_pan",
    meta_prefix="rin_wet",
    thumb_rel_path=_thumb("thumb/rin_wet.jpg"),
    huge=True,
    map_w_px=HUGE_MAP_W_PX,
    map_h_px=HUGE_MAP_H_PX,
    composite_canvas_w=1920,
    composite_canvas_h=1920,
    variants=(
        CompositeVariantSpec(
            "pan_down",
            (_layer("event/rin_wet/rin_wet_pan_down.png"),),
            hash=0x101E4A44,
        ),
    ),
)

RIN_WET_ARMS = CompositeAssetSpec(
    symbol="rin_wet_arms",
    meta_prefix="rin_wet",
    thumb_rel_path=_thumb("thumb/rin_wet.jpg"),
    huge=True,
    huge_scale_by_height=True,
    map_w_px=HUGE_MAP_W_PX,
    map_h_px=HUGE_MAP_H_PX,
    composite_canvas_w=2640,
    composite_canvas_h=1080,
    variants=(
        CompositeVariantSpec(
            "arms",
            (_layer("event/rin_wet/rin_wet_arms.png"),),
            hash=0x7FBD8C8C,
        ),
    ),
)

# script-a2-emi.rpy: scene ev picnic_* + show picnic_rain charachangeev.
PICNIC = CompositeAssetSpec(
    symbol="picnic",
    meta_prefix="picnic",
    thumb_rel_path=_thumb("thumb/picnic.jpg"),
    variants=(
        CompositeVariantSpec(
            "normal",
            (_layer("event/picnic_normal.png"),),
            hash=0xA4EF2B3D,
            seen_bitmask="DISPLAYABLE_BITMASK_PICNIC_NORMAL",
        ),
        CompositeVariantSpec(
            "rain",
            (_layer("event/picnic_rain.png"),),
            hash=0x49D3D12B,
            seen_bitmask="DISPLAYABLE_BITMASK_PICNIC_RAIN",
        ),
    ),
)

# script-a1-tuesday.rpy / script-a2-hanako.rpy: ev hana_library_* charachangeev.
HANA_LIBRARY = CompositeAssetSpec(
    symbol="hana_library",
    meta_prefix="hana_library",
    thumb_rel_path=_thumb("thumb/hana_library.jpg"),
    variants=(
        CompositeVariantSpec(
            "default",
            (_layer("event/hana_library.png"),),
            hash=0x092915A0,
            seen_bitmask="DISPLAYABLE_BITMASK_HANA_LIBRARY",
        ),
        CompositeVariantSpec(
            "read",
            (_layer("event/hana_library_read.png"),),
            hash=0x3BADDF80,
            seen_bitmask="DISPLAYABLE_BITMASK_HANA_LIBRARY_READ",
        ),
        CompositeVariantSpec(
            "gasp",
            (_layer("event/hana_library_gasp.png"),),
            hash=0xCF7F47FE,
            seen_bitmask="DISPLAYABLE_BITMASK_HANA_LIBRARY_GASP",
        ),
        CompositeVariantSpec(
            "smile",
            (_layer("event/hana_library_smile.png"),),
            hash=0x28FC69DE,
            seen_bitmask="DISPLAYABLE_BITMASK_NONE",
        ),
    ),
)

# script-a1-wednesday.rpy / script-a1-saturday.rpy: ev shizu_shanghai_* charachangeev.
SHIZU_SHANGHAI = CompositeAssetSpec(
    symbol="shizu_shanghai",
    meta_prefix="shizu_shanghai",
    thumb_rel_path=_thumb("thumb/shizu_shanghai.jpg"),
    variants=(
        CompositeVariantSpec(
            "default",
            (_layer("event/shizu_shanghai.png"),),
            hash=0x9425AC62,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_SHANGHAI",
        ),
        CompositeVariantSpec(
            "boredlaugh",
            (_layer("event/shizu_shanghai_boredlaugh.png"),),
            hash=0x8E491684,
            seen_bitmask="DISPLAYABLE_BITMASK_NONE",
        ),
        CompositeVariantSpec(
            "borednormal",
            (_layer("event/shizu_shanghai_borednormal.png"),),
            hash=0xA2ABB1B8,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_SHANGHAI_BOREDNORMAL",
        ),
        CompositeVariantSpec(
            "normallaugh",
            (_layer("event/shizu_shanghai_normallaugh.png"),),
            hash=0xE24226CA,
            seen_bitmask="DISPLAYABLE_BITMASK_NONE",
        ),
        CompositeVariantSpec(
            "smirklaugh",
            (_layer("event/shizu_shanghai_smirklaugh.png"),),
            hash=0xE49E0B6C,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_SHANGHAI_SMIRKLAUGH",
        ),
        CompositeVariantSpec(
            "smirknormal",
            (_layer("event/shizu_shanghai_smirknormal.png"),),
            hash=0x0CFEBE5E,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_SHANGHAI_SMIRKNORMAL",
        ),
    ),
)

# script-a4-shizune.rpy: evh shizu_undressing_* charachangeev.
SHIZU_UNDRESSING = CompositeAssetSpec(
    symbol="shizu_undressing",
    meta_prefix="shizu_undressing",
    thumb_rel_path=_thumb("thumb/shizu_undressing.jpg"),
    variants=(
        CompositeVariantSpec(
            "clothed_stare",
            (_layer("event/shizu_undressing/shizu_undressing_clothed_stare.png"),),
            hash=0xC44FE6B4,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_STARE",
        ),
        CompositeVariantSpec(
            "clothed_kiss",
            (_layer("event/shizu_undressing/shizu_undressing_clothed_kiss.png"),),
            hash=0xC4C2CC63,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_KISS",
        ),
        CompositeVariantSpec(
            "clothed_blush",
            (_layer("event/shizu_undressing/shizu_undressing_clothed_blush.png"),),
            hash=0x3A073DCC,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_CLOTHED_BLUSH",
        ),
        CompositeVariantSpec(
            "unclothed_closed",
            (_layer("event/shizu_undressing/shizu_undressing_unclothed_closed.png"),),
            hash=0x072E261D,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_CLOSED",
        ),
        CompositeVariantSpec(
            "unclothed_blush",
            (_layer("event/shizu_undressing/shizu_undressing_unclothed_blush.png"),),
            hash=0x6EBB3CBA,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_BLUSH",
        ),
        CompositeVariantSpec(
            "unclothed_kiss",
            (_layer("event/shizu_undressing/shizu_undressing_unclothed_kiss.png"),),
            hash=0x1F3F9121,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_KISS",
        ),
        CompositeVariantSpec(
            "unclothed_talk",
            (_layer("event/shizu_undressing/shizu_undressing_unclothed_talk.png"),),
            hash=0x497161B3,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_UNDRESSING_UNCLOTHED_TALK",
        ),
    ),
)

# script-a4-shizune.rpy: evh shizu_straddle_open pan (CustomEvent), then tease/… charachangeev.
SHIZU_STRADDLE_OPEN = CompositeAssetSpec(
    symbol="shizu_straddle_open",
    meta_prefix="shizu_straddle",
    thumb_rel_path=_thumb("thumb/shizu_straddle.jpg"),
    huge=True,
    map_w_px=HUGE_MAP_W_PX,
    map_h_px=HUGE_MAP_H_PX,
    composite_canvas_w=3321,
    composite_canvas_h=3568,
    huge_scale_by_height=True,
    huge_content_h=HUGE_MAP_H_PX,
    variants=(
        CompositeVariantSpec(
            "open",
            (_layer("event/shizu_straddle_open.png"),),
            hash=0x609E25BC,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_STRADDLE_OPEN",
        ),
    ),
)

SHIZU_STRADDLE = CompositeAssetSpec(
    symbol="shizu_straddle",
    meta_prefix="shizu_straddle",
    thumb_rel_path=_thumb("thumb/shizu_straddle.jpg"),
    variants=(
        CompositeVariantSpec(
            "tease",
            (_layer("event/shizu_straddle_tease.png"),),
            hash=0x9666EA8A,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_STRADDLE_TEASE",
        ),
        CompositeVariantSpec(
            "closed",
            (_layer("event/shizu_straddle_closed.png"),),
            hash=0x50DFADCB,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_STRADDLE_CLOSED",
        ),
        CompositeVariantSpec(
            "smile",
            (_layer("event/shizu_straddle_smile.png"),),
            hash=0xB6BB09FC,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_STRADDLE_SMILE",
        ),
        CompositeVariantSpec(
            "come",
            (_layer("event/shizu_straddle_come.png"),),
            hash=0xEC59D299,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_STRADDLE_COME",
        ),
    ),
)

SHIZU_TABLE = CompositeAssetSpec(
    symbol="shizu_table",
    meta_prefix="shizu_table",
    thumb_rel_path=_thumb("thumb/shizu_table.jpg"),
    variants=(
        CompositeVariantSpec(
            "smile",
            (_layer("event/shizu_table_smile.png"),),
            hash=0x93E8189C,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_TABLE_SMILE",
        ),
        CompositeVariantSpec(
            "normal",
            (_layer("event/shizu_table_normal.png"),),
            hash=0x7A90048B,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_TABLE_NORMAL",
        ),
        CompositeVariantSpec(
            "comeopen",
            (_layer("event/shizu_table_comeopen.png"),),
            hash=0x0EECAABD,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_TABLE_COMEOPEN",
        ),
        CompositeVariantSpec(
            "comeclosed",
            (_layer("event/shizu_table_comeclosed.png"),),
            hash=0x61A6CAD8,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZU_TABLE_COMECLOSED",
        ),
    ),
)

# script-a3-shizune.rpy: evh shizune_hcg_tied_* — multi-layer when evh_hi hisao overlay shown.
# GBA uses KSRE *_small.png sources only (same viewport after crop, faster to convert).
# hisao2_small is a full 1920×1080 sheet with sparse pixels; on _small viewport paste at
# (0, 0), not Ren'Py Composite (1296, 224) which targets the pre-zoom full canvas.
_TIED = "event/shizune_hcg_tied/"
_TIED_HISAO2 = _layer(f"{_TIED}shizune_hcg_tied_hisao2_small.png")

SHIZUNE_HCG_TIED = CompositeAssetSpec(
    symbol="shizune_hcg_tied",
    meta_prefix="shizune_hcg_tied",
    thumb_rel_path=_thumb("thumb/shizune_tied.jpg"),
    variants=(
        CompositeVariantSpec(
            "smile",
            (_layer(f"{_TIED}shizune_hcg_tied_smile_small.png"),),
            hash=0xEA7DA516,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_SMILE",
        ),
        CompositeVariantSpec(
            "blush",
            (_layer(f"{_TIED}shizune_hcg_tied_blush_small.png"),),
            hash=0xB5D68A89,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_BLUSH",
        ),
        CompositeVariantSpec(
            "blush_hisao2",
            (
                _layer(f"{_TIED}shizune_hcg_tied_blush_small.png"),
                _TIED_HISAO2,
            ),
            hash=0x79997E98,
            seen_bitmask="DISPLAYABLE_BITMASK_NONE",
        ),
        CompositeVariantSpec(
            "stare",
            (_layer(f"{_TIED}shizune_hcg_tied_stare_small.png"),),
            hash=0x9D02A3DE,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_STARE",
        ),
        CompositeVariantSpec(
            "close_hisao2",
            (
                _layer(f"{_TIED}shizune_hcg_tied_close_small.png"),
                _TIED_HISAO2,
            ),
            hash=0x2EE9AAC0,
            seen_bitmask="DISPLAYABLE_BITMASK_NONE",
        ),
        CompositeVariantSpec(
            "kinky3",
            (_layer(f"{_TIED}shizune_hcg_tied_kinky3_small.png"),),
            hash=0xCAAA6F67,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_KINKY3",
        ),
        CompositeVariantSpec(
            "kinky2",
            (_layer(f"{_TIED}shizune_hcg_tied_kinky2_small.png"),),
            hash=0x0E394C83,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_KINKY2",
        ),
        CompositeVariantSpec(
            "close",
            (_layer(f"{_TIED}shizune_hcg_tied_close_small.png"),),
            hash=0xB0780A17,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_CLOSE",
        ),
        CompositeVariantSpec(
            "kinky1_hisao2",
            (
                _layer(f"{_TIED}shizune_hcg_tied_kinky1_small.png"),
                _TIED_HISAO2,
            ),
            hash=0xEC815210,
            seen_bitmask="DISPLAYABLE_BITMASK_SHIZUNE_HCG_TIED_KINKY1",
        ),
    ),
)

# script-a2-emi.rpy: scene ev emi_sleep_* with charachangeev variant switches.
EMI_SLEEP = CompositeAssetSpec(
    symbol="emi_sleep",
    meta_prefix="emi_sleep",
    thumb_rel_path=_thumb("thumb/emi_sleep.jpg"),
    variants=(
        CompositeVariantSpec(
            "normal",
            (_layer("event/emi_sleep_normal.png"),),
            hash=0x4D12722B,
            seen_bitmask="DISPLAYABLE_BITMASK_EMI_SLEEP_NORMAL",
        ),
        CompositeVariantSpec(
            "unsure",
            (_layer("event/emi_sleep_unsure.png"),),
            hash=0x09B2DDB8,
            seen_bitmask="DISPLAYABLE_BITMASK_EMI_SLEEP_UNSURE",
        ),
        CompositeVariantSpec(
            "weep",
            (_layer("event/emi_sleep_weep.png"),),
            hash=0xD9BD6EF2,
            seen_bitmask="DISPLAYABLE_BITMASK_EMI_SLEEP_WEEP",
        ),
        CompositeVariantSpec(
            "cry",
            (_layer("event/emi_sleep_cry.png"),),
            hash=0x515384F8,
            seen_bitmask="DISPLAYABLE_BITMASK_EMI_SLEEP_CRY",
        ),
    ),
)

COMPOSITE_SPECS: dict[str, CompositeAssetSpec] = {
    "rin_goodend": RIN_GOODEND,
    "rin_h": RIN_H,
    "rin_h2": RIN_H2,
    "rin_pair": RIN_PAIR,
    "rin_wet_pan": RIN_WET_PAN,
    "rin_wet_arms": RIN_WET_ARMS,
    "emi_sleep": EMI_SLEEP,
    "picnic": PICNIC,
    "hana_library": HANA_LIBRARY,
    "shizu_shanghai": SHIZU_SHANGHAI,
    "shizu_undressing": SHIZU_UNDRESSING,
    "shizu_straddle_open": SHIZU_STRADDLE_OPEN,
    "shizu_straddle": SHIZU_STRADDLE,
    "shizu_table": SHIZU_TABLE,
    "shizune_hcg_tied": SHIZUNE_HCG_TIED,
}


def composite_meta_name(spec: CompositeAssetSpec, variant: CompositeVariantSpec) -> str:
    prefix = spec.meta_prefix or spec.symbol
    return f"{prefix}_{variant.name}"


def composite_meta_symbol_for(name: str) -> str | None:
    """Return composite asset symbol if `name` is a regular composite script meta."""
    for spec in COMPOSITE_SPECS.values():
        if spec.huge:
            continue
        for variant in spec.variants:
            if composite_meta_name(spec, variant) == name:
                return spec.symbol
    return None


def composite_huge_meta_symbol_for(name: str) -> str | None:
    """Return composite asset symbol if `name` is a composite-huge script meta."""
    for spec in COMPOSITE_SPECS.values():
        if not spec.huge:
            continue
        for variant in spec.variants:
            if composite_meta_name(spec, variant) == name:
                return spec.symbol
    return None
