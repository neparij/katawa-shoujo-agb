"""Per-displayable asset specs (frames, dithering, tile reduction, timing).

Each entry in ``DISPLAYABLE_SPECS`` has its own ``dither`` and ``tile_options``.
Tune ``tile_options.reduce_threshold`` when ``grit_rom`` or ``max_vram`` exceeds 1024.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Literal

from src.displayable_tile_reduction import DisplayableTileOptions

# Where ``frame_sources`` paths are resolved:
#   ``sprites`` — ``{KSRE}/game/`` (ksre_converter ``--source``)
#   ``project`` — katawa repo root (``--outdir``)
SourcesRoot = Literal["sprites", "project"]

# Grit regular_bg hard limit (one BG tileset in VRAM).
GRIT_MAX_TILES = 1024

# imgdither ``-dither:<method>,<level>`` (see imgdither-cli.c).
DITHER_METHODS = frozenset({
    "none", "floyd", "atkinson", "checker",
    "ord2", "ord4", "ord8", "ord16", "ord32", "ord64",
})


@dataclass(frozen=True)
class DisplayableDitherOptions:
    """Per-asset palette remap / dithering (imgdither, ``pal_char_bg``)."""

    method: str = "floyd"
    level: float = 0.5

    def __post_init__(self) -> None:
        if self.method not in DITHER_METHODS:
            raise ValueError(
                f"Unknown dither method {self.method!r}; "
                f"expected one of: {', '.join(sorted(DITHER_METHODS))}"
            )
        if self.method != "none" and not (0.0 <= self.level <= 4.0):
            raise ValueError(f"dither level must be in [0, 4], got {self.level}")

    @property
    def enabled(self) -> bool:
        return self.method != "none" and self.level > 0.0

    def imgdither_arg(self) -> str:
        """Argument for imgdither ``-dither:…``."""
        if not self.enabled:
            return "none,0"
        return f"{self.method},{self.level}"


@dataclass(frozen=True)
class DisplayableAssetSpec:
    """One scene displayable: stacked maps → single ``regular_bg_item``."""

    symbol: str
    frame_sources: tuple[str, ...]
    sources_root: SourcesRoot = "sprites"
    ticks_per_frame: int = 18
    y_crop: int = 0
    dither: DisplayableDitherOptions = DisplayableDitherOptions()
    tile_options: DisplayableTileOptions = DisplayableTileOptions()


# Animated crowd — GBA-prepared frames under ``intermediate/images/``.
# (Original KSRE: ``vfx/crowd1.png`` … with ``sources_root="sprites"``.)
CROWD = DisplayableAssetSpec(
    symbol="crowd",
    sources_root="project",
    frame_sources=(
        "intermediate/images/crowd_1.png",
        "intermediate/images/crowd_2.png",
        "intermediate/images/crowd_3.png",
    ),
    ticks_per_frame=18,
    dither=DisplayableDitherOptions(method="floyd", level=1.0),
    tile_options=DisplayableTileOptions(
        reduce_threshold=48.0,
        reduce_flip_x=True,
        reduce_flip_y=True,
        reduce_use_blur=True,
    ),
)

DISPLAYABLE_SPECS: dict[str, DisplayableAssetSpec] = {
    "crowd": CROWD,
}
