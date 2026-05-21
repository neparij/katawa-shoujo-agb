"""Scene displayables (crowd, …) — not smart_characters."""

from __future__ import annotations

from src.utils import get_sprite_paletted_variant

DISPLAYABLE_NAMES = frozenset({"crowd"})


def is_displayable_sprite(sprite: str) -> bool:
    if sprite in DISPLAYABLE_NAMES:
        return True
    return any(sprite.startswith(f"{name}_") for name in DISPLAYABLE_NAMES)


def split_displayable_sprite(sprite: str) -> tuple[str, str | None]:
    for name in DISPLAYABLE_NAMES:
        if sprite == name:
            return name, None
        if sprite.startswith(f"{name}_"):
            return name, sprite[len(name) + 1 :]
    raise ValueError(f"not a displayable sprite: {sprite!r}")


def displayable_palette_variant(subvariant: str | None) -> str:
    if subvariant is None:
        return "PALETTE_VARIANT_DEFAULT"
    if subvariant == "ni_fb":
        return "PALETTE_VARIANT_PAST_NIGHT"
    _, palette = get_sprite_paletted_variant(subvariant)
    return palette


def crowd_frame_index(subvariant: str | None) -> int:
    if subvariant is None:
        return 0
    base, _ = get_sprite_paletted_variant(subvariant)
    if base and base.startswith("still"):
        suffix = base.removeprefix("still")
        if suffix.isdigit():
            return max(0, int(suffix) - 1)
    return 0


def crowd_animate(subvariant: str | None) -> bool:
    if subvariant is None:
        return True
    base, _ = get_sprite_paletted_variant(subvariant)
    return not (base and base.startswith("still"))
