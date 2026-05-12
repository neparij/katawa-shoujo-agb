#!/usr/bin/env python3
"""
One-time script: generates character_sprites.yaml from CharacterSpritesReader.

Usage (run from tools/converter/):
    python -m src.character_sprite.generate_sprites_yaml \
        --source /path/to/ksre/sprites \
        --output src/character_sprite/character_sprites.yaml
"""

import argparse
import os
import sys

import yaml

from src.character_sprite.character_sprite import (
    CharacterRegex,
    CharacterSpritesGroup,
    CharacterSpritesReader,
)

# Displayable regex (without \.png$) used per character name.
# Characters not listed here use CharacterRegex.default().
CHARACTER_DISPLAYABLE_REGEX: dict[str, str] = {
    "nurse": CharacterRegex.nurse(),
    "yuuko": CharacterRegex.yuuko(),
    "yuukoshang": CharacterRegex.yuukoshang(),
}


def subgroup_key(group: CharacterSpritesGroup) -> str:
    """Returns the YAML group key: pose[_outfit][_close], without the character name."""
    parts = []
    if group.pose:
        parts.append(group.pose)
    if group.outfit:
        parts.append(group.outfit)
    if group.close:
        parts.append("close")
    return "_".join(parts) if parts else "default"


def relative_filename(original_path: str, input_dir: str) -> str:
    """Returns the filename relative to input_dir (e.g. 'lilly/lilly_basic_smile.png')."""
    return os.path.relpath(original_path, input_dir)


def build_yaml_structure(groups: list[CharacterSpritesGroup], input_dir: str) -> dict:
    characters: dict = {}

    for group in groups:
        char = group.character_name

        if char not in characters:
            characters[char] = {
                "displayable_regex": CHARACTER_DISPLAYABLE_REGEX.get(char, CharacterRegex.default()),
                "tileset": char,
                "groups": {},
            }

        key = subgroup_key(group)

        sprites_dict = {}
        for sprite in group.sprites:
            sprites_dict[sprite.emotion] = {
                "filename": relative_filename(sprite.original_path, input_dir),
                "naked": sprite.nude,
            }

        # Emit the face cut-out as 8-px **cell** indices (e.g. [14, 8] →
        # cuts the BG starting at canvas pixel (112, 64)). All downstream
        # GBA tooling treats these as cell coords directly, so they
        # multiply by 8 when they need pixel space.
        characters[char]["groups"][key] = {
            "pose": group.pose,
            "outfit": group.outfit,
            "close": group.close,
            "base_emotion": group.base_emotion,
            "base_emotion_offset": list(group.base_emotion_offset_cells),
            "base_emotion_size": list(group.base_emotion_size_cells),
            "base_origin_offset": group.base_origin_offset,
            "silhouette_tint": group.silhouette_tint,
            "sprites": sprites_dict,
        }

    return {"sprites": characters}


def main():
    parser = argparse.ArgumentParser(description="Generate character_sprites.yaml")
    parser.add_argument(
        "--source",
        required=True,
        help="Path to the KS:RE sprites root directory (contains akira/, emi/, etc.)",
    )
    parser.add_argument(
        "--output",
        default=os.path.join(os.path.dirname(__file__), "character_sprites.yaml"),
        help="Output YAML file path",
    )
    args = parser.parse_args()

    input_dir = os.path.abspath(args.source)
    print(f"Reading sprites from: {input_dir}")

    reader = CharacterSpritesReader(input_dir)
    groups = reader.process_all()
    print(f"Processed {len(groups)} sprite groups")

    data = build_yaml_structure(groups, input_dir)

    with open(args.output, "w", encoding="utf-8") as f:
        yaml.dump(data, f, allow_unicode=True, sort_keys=False, default_flow_style=False)

    print(f"Written to: {args.output}")


if __name__ == "__main__":
    main()
