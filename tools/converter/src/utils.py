import re
from typing import Dict, List

FILL_COLORS = [
    "black",
    "bloodred",
    "white",
    "pink",
    "darkgrey"
]

#     /// SOH - sets cursor to render text by chars
#     static constexpr char CTL_FAST = 0x01;
#     /// STX - starts bold text (switch spritefont)
#     static constexpr char CTL_BOLD_START = 0x02;
#     /// ETX - ends bold text (restore spritefont)
#     static constexpr char CTL_BOLD_END = 0x03;
#     /// EOT - starts strikethrough text (switch spritefont?)
#     static constexpr char CTL_STRIKE_START = 0x04;
#     /// ENQ - ends strikethrough text (restore spritefont?)
#     static constexpr char CTL_STRIKE_END = 0x05;
#     /// ACK - wait command (next byte is count of 1/10 seconds to wait or 0xFF to wait for user input)
#     static constexpr char CTL_WAIT = 0x06;
#     /// BEL - do not wait for user input to continue dialogue
#     static constexpr char CTL_NOWAIT = 0x07;
#     /// BS - sets the color (switch spritepalette, next byte is palette index starting from 0x01)
#     static constexpr char CTL_COLOR_START = 0x08;
#     /// HT - restore color (switch spritepalette)
#     static constexpr char CTL_COLOR_END = 0x09;

CTL_FAST = b'\x01'
CTL_BOLD_START = b'\x02'
CTL_BOLD_END = b'\x03'
CTL_STRIKE_START = b'\x04'
CTL_STRIKE_END = b'\x05'
CTL_WAIT = b'\x06'
CTL_NOWAIT = b'\x07'
CTL_COLOR_START = b'\x08'
CTL_COLOR_END = b'\x09'

def sanitize_function_name(text):
    return re.sub(r"[^a-zA-Z0-9_]", "", text.replace(" ", "_").lower())

def sanitize_comment_text(text):
    return text.replace("\n", " ").replace("\r", " ").replace("\t", " ")

def sanitize_ingame_text(text: str):
    text = text.replace("’", "'")
    # text = text.replace("　", " ") # Ideographic space (CJK)
    return text

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

def bytecode_format(text: str) -> bytes:
    """
    :param text: The input text.
    :return: The text formatted with control characters as bytes.
    """
    data = text.encode("utf-8")
    data = data.replace(b"{fast}", CTL_FAST)
    data = data.replace(b"{b}", CTL_BOLD_START)
    data = data.replace(b"{/b}", CTL_BOLD_END)
    data = data.replace(b"{s}", CTL_STRIKE_START)
    data = data.replace(b"{/s}", CTL_STRIKE_END)
    data = data.replace(b"{w}", CTL_WAIT + b"\xFF")
    data = re.sub(
        br"\{w=(\d*\.*\d+)\}",
        lambda m: CTL_WAIT + bytes([min(255, max(1, int(float(m.group(1)) * 10)))]),
        data
    )
    data = data.replace(b"{nw}", CTL_NOWAIT)
    # TODO: Support colors

    return data + b"\x00"

def split_by_commands(text: str) -> List[str]:
    """
    :param text: The input text with commands (e.g. {b}, {w=1.5}, etc.)
    :return: The array of text without commands (split by commands)
    """
    command_re = re.compile(r"(\{[^\}]+\})")
    parts = command_re.split(text)
    return [part for part in parts if part and not command_re.match(part)]

def remove_bytecode_functions(data: bytes) -> bytes:
    """
    :param data: The input bytecode data.
    :return: The text with control characters removed.
    """
    data = re.sub(br"\x06[\x00-\xFF]", b"", data)  # Remove wait commands
    data = re.sub(br"\x08[\x00-\xFF]", b"", data)  # Remove color start commands

    data = data.replace(CTL_FAST, b"")
    data = data.replace(CTL_BOLD_START, b"")
    data = data.replace(CTL_BOLD_END, b"")
    data = data.replace(CTL_STRIKE_START, b"")
    data = data.replace(CTL_STRIKE_END, b"")
    data = data.replace(CTL_NOWAIT, b"")
    data = data.replace(CTL_COLOR_END, b"")
    return data.rstrip(b"\x00")  # Remove trailing null bytes
