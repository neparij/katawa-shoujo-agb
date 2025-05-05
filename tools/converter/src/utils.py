import re


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
