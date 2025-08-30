import re
from typing import Dict, List

FILL_COLORS = [
    "black",
    "bloodred",
    "white",
    "pink",
    "darkgrey"
]

def sanitize_function_name(text):
    return re.sub(r"[^a-zA-Z0-9_]", "", text.replace(" ", "_").lower())

def sanitize_comment_text(text):
    return text.replace("\n", " ").replace("\r", " ").replace("\t", " ")

def get_x_position(value: float, anchor: float = 0.5) -> int:
    """
    Converts a relative X position (0.0 to 1.0) with anchor (0.0 to 1.0) to an absolute X position (-120 to 120).
    """
    sprite_width = 128
    anchor_offset = int((anchor - 0.5) * sprite_width)
    return int(-120 + value * 240) - anchor_offset
    # return int(-120 + value * 240)

def get_xalign_position(value: float) -> int:
    """
    Converts a relative X position to an absolute X position with sprite alignment.
    The sprite's anchor is centered.

    :param value: Relative X position (0.0 to 1.0).
    :return: Aligned absolute X position.
    """
    # sprite_width = 128
    # anchor_offset = -sprite_width // 2 + int(value * sprite_width)
    # return get_x_position(value) - anchor_offset
    return get_x_position(value, anchor=value)

def get_y_position(value: float) -> int:
    """
    Converts a relative Y position (0.0 to 1.0) to an absolute Y position (-80 to 80).
    """
    return int(-80 + value * 160)

def get_yalign_position(value: float) -> int:
    """
    Converts a relative Y position to an absolute Y position with sprite alignment.
    The sprite's anchor is centered.

    :param value: Relative X position (0.0 to 1.0).
    :return: Aligned absolute X position.
    """
    sprite_height = 160
    anchor_offset = -sprite_height // 2 + int(value * sprite_height)
    return get_y_position(value) - anchor_offset

def get_paletted_variant(variant: str) -> (str, str):
    if variant.endswith("_ss"):
        return variant.removesuffix("_ss"), "PALETTE_VARIANT_SPRITE_SUNSET"
    elif variant.endswith("_ni"):
        return variant.removesuffix("_ni"), "PALETTE_VARIANT_SPRITE_NIGHT"
    elif variant.endswith("_rn"):
        return variant.removesuffix("_rn"), "PALETTE_VARIANT_SPRITE_RAIN"
    else:
        return variant, "PALETTE_VARIANT_DEFAULT"

def is_color_filled_bg(background: str) -> bool:
    return background in FILL_COLORS

def starts_with_filled_bg(line: str) -> bool:
    for color in FILL_COLORS:
        if line.startswith(f"scene {color}"):
            return True
    return False

def add_translations(tl_dict: Dict[str, List[Dict[str,str]]], tl_group: str, values: Dict[str,str]) -> int:
    """
    Adds a translation values to the specified translation group in the dictionary.
    :param tl_dict: The dictionary containing translation groups.
    :param tl_group: The translation group to which the value should be added.
    :param values: The translation values to add.
    :return: The index of the added value in the group list.
    """
    print(f"Adding translation to group '{tl_group}' (): {values}")
    if tl_group not in tl_dict:
        tl_dict[tl_group] = []
    tl_dict[tl_group].append(values)
    return len(tl_dict[tl_group]) - 1

def add_translations_optional(tl_dict: Dict[str, List[Dict[str,str]]], tl_group: str, values: Dict[str,str]) -> int:
    """
    Adds a translation values to the specified translation group in the dictionary if it doesn't already exist.
    :param tl_dict: The dictionary containing translation groups.
    :param tl_group: The translation group to which the value should be added.
    :param values: The translation values to add.
    :return: The index of the value in the group list.
    """
    if tl_group not in tl_dict:
        tl_dict[tl_group] = []
    if values in tl_dict[tl_group]:
        return tl_dict[tl_group].index(values)
    return add_translations(tl_dict, tl_group, values)

def get_tl_group_hash(tl_group: str) -> str:
    hash_value = 1337
    for char in tl_group:
        hash_value = (hash_value * 31 + ord(char)) & 0xFFFFFFFF
    return f"{hash_value:08X}"

def get_tl_group_locales(tl_group: List[Dict[str,str]]) -> List[str]:
    locales = []
    for entry in tl_group:
        for locale in entry.keys():
            if locale not in locales:
                locales.append(locale)
    return locales